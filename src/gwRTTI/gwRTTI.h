////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <map>

////////////////////////////////////////////////////////////////////////////////

#if defined( _MSC_VER )

    #include <stdint.h> // for uint8_t etc

    #define gwDLL_EXPORT __declspec( dllexport )
    #define gwDLL_IMPORT __declspec( dllimport )

#elif defined( __GNUC__ )

    #include <inttypes.h>
    #include <stdlib.h>

    #define gwDLL_EXPORT __attribute__ ((visibility ("default")))
    #define gwDLL_IMPORT __attribute__ ((visibility ("default")))

#else

    #error unknown compiler

#endif

#ifdef _USRDLL
    #ifdef GWRTTI_EXPORTS
        #define GWRTTI_API gwDLL_EXPORT
    #else
        #define GWRTTI_API gwDLL_IMPORT
    #endif
#else
    #define GWRTTI_API
#endif



////////////////////////////////////////////////////////////////////////////////

namespace gw
{
    namespace RTTI
    {
        struct TypeInfo;
        
        extern const char* __ValueTypeToString( const TypeInfo* type, void* obj, char* buffer, int size );
        
        ////////////////////////////////////////////////////////////////////////////////
        
        struct Attr
        {
            const char* Key;
            const char* Value;
        };
        
        struct Constant
        {
            const char* Name;
            int         Value;
        };
        
        
        ////////////////////////////////////////////////////////////////////////////////

        struct GWRTTI_API Field
        {
            void* (*Get)( void* );
            
            const char*     Name;
            const TypeInfo* Info;
            
            Attr*           Attrs;
            int             NumAttrs;
            
            bool IsPointer:1;
            bool IsArray:1;
            
            std::function< std::pair<void*,const TypeInfo*>() > (*Iterator)( void* );
                        
            Field()
                : Get( nullptr )
                , Name( nullptr )
                , Info( nullptr )
                , Attrs( nullptr )
                , NumAttrs( 0 )
                , IsPointer( false )
                , IsArray( false )
                , Iterator( nullptr )
            {
            }
        };


        ////////////////////////////////////////////////////////////////////////////////

        struct GWRTTI_API TypeInfo
        {
            bool    IsA( const TypeInfo* ) const;
            void*   GetField( void*, const char* ) const;

            unsigned int    UID;                    // internal unique identifier
            std::string     Name;                   // name
            uint64_t        Hash;                   // djb2_64 hash of name
            
            void* (*Instantiate)();                 // instantiate function
            const char* (*ToString)( void*, char*, int );
            
            // potentially useful(!?) things we can infer from the type

            bool            IsFundamental:1;
            bool            IsEnum:1;
            bool            IsPOD:1;

            const TypeInfo** Inherits;  // base classes
            
            Field*          Fields;     // classes have fields
            Constant*       Constants;  // enums have constants ... don't get them confused :)
            
            int             NumMembers; // num fields or num constants
            
            Attr*           Attrs;      // key/value attribute pairs
            int             NumAttrs;
            
            TypeInfo()
                : UID( 0 )
                , Hash( ~0 )
                , Instantiate( nullptr )
                , ToString( nullptr )

                , IsFundamental( false )
                , IsEnum( false )
                , IsPOD( false )

                , Inherits( nullptr )
                , Fields( nullptr )
                , Constants( nullptr )
                , NumMembers( 0 )
                , Attrs( nullptr )
                , NumAttrs( 0 )
            {
            }
        };



        ////////////////////////////////////////////////////////////////////////////////

        class GWRTTI_API Registry
        {
            public:

                static Registry& Instance() { static Registry sRegistry; return sRegistry; }

                const TypeInfo* Find( const char* );
                void*           Instantiate( const char* );

                TypeInfo*       FindOrCreate( const char* );

            protected:

                Registry()
                    : mID( 0 )
                {
                }

                unsigned int mID;
                std::map< std::string, TypeInfo > mTypes;
        };



        ////////////////////////////////////////////////////////////////////////////////
        // templated implementation of specific type info
        // we use template specialisation to provide the

        template< typename T >
        struct TypeInfoImpl : public TypeInfo
        {
            // specialise Create() to provide custom type implementation

            void Create() {}

            static const TypeInfo* Class()
            {
                static const TypeInfo* info = CreateTypeInfo();
                return info;
            }


            protected:
            
                // called first time we access the class - which be from gwRTTI_REGISTER!

                static const TypeInfo* CreateTypeInfo()
                {
                    // first call we fetch from registry - this is because of memory is local to "shared boundaries"
                    // (i.e. Windows DLL's). This isn't a problem if the library is statically linked
                    
                    #ifdef _MSC_VER
                        TypeInfo* info = gw::RTTI::Registry::Instance().FindOrCreate( __FUNCSIG__ );
                    #else
                        TypeInfo* info = gw::RTTI::Registry::Instance().FindOrCreate( __PRETTY_FUNCTION__ );
                    #endif
                    
                    auto p = reinterpret_cast< TypeInfoImpl<T>* >( const_cast<TypeInfo*>( info ) );

                    p->Instantiate      = std::is_constructible<T>::value ? []() -> void* { return new T(); } : nullptr;
                    p->IsFundamental    = std::is_fundamental<T>::value;
                    p->IsEnum           = std::is_enum<T>::value;
                    p->IsPOD            = std::is_pod<T>::value;
                    
                    if( std::is_enum<T>::value || std::is_fundamental<T>::value )
                    {
                        p->ToString = []( void* obj, char* buf, int size ){ return __ValueTypeToString( TypeInfoImpl<T>::Class(), obj, buf, size ); };
                    }

                    p->Create();

                    return p;
                }
        };


        ////////////////////////////////////////////////////////////////////////////////
        // register type to do custom initialisation during global init

        template<typename T>
        struct Register
        {
            Register()
            {
                TypeInfoImpl<T>::Class();
            }
        };

        // use __COUNTER__ as some names have spaces in them (e.g. "unsigned int")

        #define __gwRTTI_REGISTER_CONCAT(a,b) a##b
        #define __gwRTTI_REGISTER_CREATENAME(c) __gwRTTI_REGISTER_CONCAT( __gw_rtti_, c )
        #define gwRTTI_REGISTER(t) static gw::RTTI::Register<t> __gwRTTI_REGISTER_CREATENAME( __COUNTER__ );


        ////////////////////////////////////////////////////////////////////////////////
        // a convenient shorthand - e.g. RTTI::Type<float>(), or RTTI::Type( p )

        template< typename T >
        inline const TypeInfo* Type()
        {
            return TypeInfoImpl<T>::Class();
        }

        template< typename T >
        inline const TypeInfo* Type( const T* )
        {
            return TypeInfoImpl<T>::Class();
        }


        ////////////////////////////////////////////////////////////////////////////////
        // RTTI for classes

        #define gwRTTI(T) \
            public: \
                virtual const gw::RTTI::TypeInfo* GetType() const { return gw::RTTI::Type( this ); } \
                friend void gw::RTTI::TypeInfoImpl<T>::Create();


        template< typename T, typename O >
        T* Cast( O* object )
        {
            // NB: static_cast required to rebase pointer
            return object && object->Type()->IsA( RTTI::Type<T>() ) ? static_cast<T*>( object ) : nullptr;
        }
    }
}

