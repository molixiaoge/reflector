////////////////////////////////////////////////////////////////////////////////
// Automatically generated RTTI information
// source  : ../../tests/test.json
// date    : Thu Dec 17 2015 21:51:46 GMT+0000 (GMT)


#include "gw/gw.h"
#include "gw/gwRTTI.h"

using namespace gw::RTTI;


////////////////////////////////////////////////////////////////////////////////
// common types

gwRTTI_REGISTER( bool );
gwRTTI_REGISTER( char );
gwRTTI_REGISTER( unsigned char );
gwRTTI_REGISTER( short );
gwRTTI_REGISTER( int );
gwRTTI_REGISTER( unsigned int );
gwRTTI_REGISTER( float );
gwRTTI_REGISTER( double );


////////////////////////////////////////////////////////////////////////////////
// AClass

template<> void TypeInfoImpl< AClass >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, nullptr };
    Inherits = bases;

    
    //
    // class fields
    //

    static Property p[ 8 ];

    // 0. a

    p[ 0 ].Name     = "a";
    p[ 0 ].Info     = Type< float >();
    p[ 0 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<AClass*>(o)->a; };
    

    // 1. b

    p[ 1 ].Name     = "b";
    p[ 1 ].Info     = Type< const float * >();
    p[ 1 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<AClass*>(o)->b; };
    

    // 2. buffer

    p[ 2 ].Name     = "buffer";
    p[ 2 ].Info     = Type< char [32] >();
    p[ 2 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<AClass*>(o)->buffer; };
    

    // 3. v3

    p[ 3 ].Name     = "v3";
    p[ 3 ].Info     = Type< Vector3 >();
    p[ 3 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<AClass*>(o)->v3; };
    

    // 4. pv3

    p[ 4 ].Name     = "pv3";
    p[ 4 ].Info     = Type< Vector3 * >();
    p[ 4 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<AClass*>(o)->pv3; };
    

    // 5. rv3

    p[ 5 ].Name     = "rv3";
    p[ 5 ].Info     = Type< Vector3 & >();
    p[ 5 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<AClass*>(o)->rv3; };
    

    // 6. c

    p[ 6 ].Name     = "c";
    p[ 6 ].Info     = Type< float >();
    p[ 6 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<AClass*>(o)->c; };
    

    // 7. d

    p[ 7 ].Name     = "d";
    p[ 7 ].Info     = Type< float >();
    p[ 7 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<AClass*>(o)->d; };
    

    // set fields

    Properties      = p;
    NumProperties   = 8;
}

gwRTTI_REGISTER( AClass );


////////////////////////////////////////////////////////////////////////////////
// MyEnum

template<> void TypeInfoImpl< MyEnum >::Create()
{
    //
    // constants
    //
    
    static Constant e[ 3 ];

    e[ 0 ].Name     = "One";
    e[ 0 ].Value    = 0;
    

    e[ 1 ].Name     = "Two";
    e[ 1 ].Value    = 1;
    

    e[ 2 ].Name     = "Three";
    e[ 2 ].Value    = 2;
    

    // set constants

    Constants       = e;
    NumConstants    = 3;
}

gwRTTI_REGISTER( MyEnum );


////////////////////////////////////////////////////////////////////////////////
// ClassWithEnum

template<> void TypeInfoImpl< ClassWithEnum >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, nullptr };
    Inherits = bases;

    
    //
    // class fields
    //

    static Property p[ 1 ];

    // 0. x

    p[ 0 ].Name     = "x";
    p[ 0 ].Info     = Type< ClassWithEnum::ClassEnum >();
    p[ 0 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<ClassWithEnum*>(o)->x; };
    

    // set fields

    Properties      = p;
    NumProperties   = 1;
}

gwRTTI_REGISTER( ClassWithEnum );


////////////////////////////////////////////////////////////////////////////////
// ClassWithEnum::ClassEnum

template<> void TypeInfoImpl< ClassWithEnum::ClassEnum >::Create()
{
    //
    // constants
    //
    
    static Constant e[ 3 ];

    e[ 0 ].Name     = "One";
    e[ 0 ].Value    = 0;
    

    e[ 1 ].Name     = "Two";
    e[ 1 ].Value    = 5;
    

    e[ 2 ].Name     = "Three";
    e[ 2 ].Value    = 6;
    

    // set constants

    Constants       = e;
    NumConstants    = 3;
}

gwRTTI_REGISTER( ClassWithEnum::ClassEnum );


////////////////////////////////////////////////////////////////////////////////
// NSRef

template<> void TypeInfoImpl< NSRef >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, nullptr };
    Inherits = bases;

    
    //
    // class fields
    //

    static Property p[ 1 ];

    // 0. nsc

    p[ 0 ].Name     = "nsc";
    p[ 0 ].Info     = Type< NS::NSClass >();
    p[ 0 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<NSRef*>(o)->nsc; };
    

    // set fields

    Properties      = p;
    NumProperties   = 1;
}

gwRTTI_REGISTER( NSRef );


////////////////////////////////////////////////////////////////////////////////
// MyStruct

template<> void TypeInfoImpl< MyStruct >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, nullptr };
    Inherits = bases;

    
    //
    // class fields
    //

    static Property p[ 2 ];

    // 0. f

    p[ 0 ].Name     = "f";
    p[ 0 ].Info     = Type< float >();
    p[ 0 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<MyStruct*>(o)->f; };
    

    // 1. sc

    p[ 1 ].Name     = "sc";
    p[ 1 ].Info     = Type< MyStruct::SubClass >();
    p[ 1 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<MyStruct*>(o)->sc; };
    

    // set fields

    Properties      = p;
    NumProperties   = 2;
}

gwRTTI_REGISTER( MyStruct );


////////////////////////////////////////////////////////////////////////////////
// MyStruct::SubClass

template<> void TypeInfoImpl< MyStruct::SubClass >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, nullptr };
    Inherits = bases;

    
    //
    // class fields
    //

    static Property p[ 1 ];

    // 0. a

    p[ 0 ].Name     = "a";
    p[ 0 ].Info     = Type< int >();
    p[ 0 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<MyStruct::SubClass*>(o)->a; };
    

    // set fields

    Properties      = p;
    NumProperties   = 1;
}

gwRTTI_REGISTER( MyStruct::SubClass );


////////////////////////////////////////////////////////////////////////////////
// Attrs

template<> void TypeInfoImpl< Attrs >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, nullptr };
    Inherits = bases;

    //
    // class attributes
    //
    
    static Attr attrs[ 7 ];

    attrs[ 0 ].Key     = "type";
    attrs[ 0 ].Value   = "class";

    attrs[ 1 ].Key     = "attr1";
    attrs[ 1 ].Value   = "a";

    attrs[ 2 ].Key     = "attr2";
    attrs[ 2 ].Value   = "b";

    attrs[ 3 ].Key     = "attr3";
    attrs[ 3 ].Value   = "c";

    attrs[ 4 ].Key     = "attr4";
    attrs[ 4 ].Value   = "d";

    attrs[ 5 ].Key     = "attr5";
    attrs[ 5 ].Value   = "x=y etc";

    attrs[ 6 ].Key     = "attr 6 with space";
    attrs[ 6 ].Value   = " hello world ";

    Attrs       = attrs;
    NumAttrs    = 7;

    
    //
    // class fields
    //

    static Property p[ 4 ];

    // 0. a

    p[ 0 ].Name     = "a";
    p[ 0 ].Info     = Type< float >();
    p[ 0 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<Attrs*>(o)->a; };
    
    static Attr p0_attrs[ 7 ];

    p0_attrs[ 0 ].Key     = "type";
    p0_attrs[ 0 ].Value   = "field";

    p0_attrs[ 1 ].Key     = "attr1";
    p0_attrs[ 1 ].Value   = "a";

    p0_attrs[ 2 ].Key     = "attr2";
    p0_attrs[ 2 ].Value   = "b";

    p0_attrs[ 3 ].Key     = "attr3";
    p0_attrs[ 3 ].Value   = "c";

    p0_attrs[ 4 ].Key     = "attr4-fish ! $ ";
    p0_attrs[ 4 ].Value   = "d";

    p0_attrs[ 5 ].Key     = "attr5";
    p0_attrs[ 5 ].Value   = "x=y etc";

    p0_attrs[ 6 ].Key     = "attr 6 with space";
    p0_attrs[ 6 ].Value   = " hello world ";

    p[0].Attrs       = p0_attrs;
    p[0].NumAttrs    = 7;


    // 1. b

    p[ 1 ].Name     = "b";
    p[ 1 ].Info     = Type< float >();
    p[ 1 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<Attrs*>(o)->b; };
    

    // 2. butd

    p[ 2 ].Name     = "butd";
    p[ 2 ].Info     = Type< float >();
    p[ 2 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<Attrs*>(o)->butd; };
    

    // 3. e

    p[ 3 ].Name     = "e";
    p[ 3 ].Info     = Type< float >();
    p[ 3 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<Attrs*>(o)->e; };
    
    static Attr p3_attrs[ 1 ];

    p3_attrs[ 0 ].Key     = "name";
    p3_attrs[ 0 ].Value   = "value";

    p[3].Attrs       = p3_attrs;
    p[3].NumAttrs    = 1;


    // set fields

    Properties      = p;
    NumProperties   = 4;
}

gwRTTI_REGISTER( Attrs );


////////////////////////////////////////////////////////////////////////////////
// MultilineAttr

template<> void TypeInfoImpl< MultilineAttr >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, nullptr };
    Inherits = bases;

    //
    // class attributes
    //
    
    static Attr attrs[ 4 ];

    attrs[ 0 ].Key     = "type";
    attrs[ 0 ].Value   = "class";

    attrs[ 1 ].Key     = "attr1";
    attrs[ 1 ].Value   = "a";

    attrs[ 2 ].Key     = "attr2";
    attrs[ 2 ].Value   = "b";

    attrs[ 3 ].Key     = "attr3";
    attrs[ 3 ].Value   = "c";

    Attrs       = attrs;
    NumAttrs    = 4;

}

gwRTTI_REGISTER( MultilineAttr );


////////////////////////////////////////////////////////////////////////////////
// EnumAttr

template<> void TypeInfoImpl< EnumAttr >::Create()
{
    //
    // attrs
    //
    
    static Attr attrs[ 1 ];

    attrs[ 0 ].Key     = "x";
    attrs[ 0 ].Value   = "y";

    Attrs       = attrs;
    NumAttrs    = 1;

    //
    // constants
    //
    
    static Constant e[ 4 ];

    e[ 0 ].Name     = "EA_One";
    e[ 0 ].Value    = 0;
    

    e[ 1 ].Name     = "EA_Two";
    e[ 1 ].Value    = 1;
    

    e[ 2 ].Name     = "EA_Four";
    e[ 2 ].Value    = 3;
    

    e[ 3 ].Name     = "EA_Five";
    e[ 3 ].Value    = 4;
    
    static Attr e3_attrs[ 2 ];

    e3_attrs[ 0 ].Key     = "a";
    e3_attrs[ 0 ].Value   = "b";

    e3_attrs[ 1 ].Key     = "c";
    e3_attrs[ 1 ].Value   = "d";

    e[3].Attrs       = e3_attrs;
    e[3].NumAttrs    = 2;


    // set constants

    Constants       = e;
    NumConstants    = 4;
}

gwRTTI_REGISTER( EnumAttr );


////////////////////////////////////////////////////////////////////////////////
// A

template<> void TypeInfoImpl< A >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, nullptr };
    Inherits = bases;

    //
    // class attributes
    //
    
    static Attr attrs[ 1 ];

    attrs[ 0 ].Key     = "a";
    attrs[ 0 ].Value   = "b";

    Attrs       = attrs;
    NumAttrs    = 1;

    
    //
    // class fields
    //

    static Property p[ 1 ];

    // 0. mA

    p[ 0 ].Name     = "mA";
    p[ 0 ].Info     = Type< float >();
    p[ 0 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<A*>(o)->mA; };
    

    // set fields

    Properties      = p;
    NumProperties   = 1;
}

gwRTTI_REGISTER( A );


////////////////////////////////////////////////////////////////////////////////
// B

template<> void TypeInfoImpl< B >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, A, nullptr };
    Inherits = bases;

    //
    // class attributes
    //
    
    static Attr attrs[ 1 ];

    attrs[ 0 ].Key     = "a";
    attrs[ 0 ].Value   = "b";

    Attrs       = attrs;
    NumAttrs    = 1;

    
    //
    // class fields
    //

    static Property p[ 1 ];

    // 0. mB

    p[ 0 ].Name     = "mB";
    p[ 0 ].Info     = Type< float >();
    p[ 0 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<B*>(o)->mB; };
    

    // set fields

    Properties      = p;
    NumProperties   = 1;
}

gwRTTI_REGISTER( B );


////////////////////////////////////////////////////////////////////////////////
// C

template<> void TypeInfoImpl< C >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, B, nullptr };
    Inherits = bases;

    
    //
    // class fields
    //

    static Property p[ 1 ];

    // 0. mC

    p[ 0 ].Name     = "mC";
    p[ 0 ].Info     = Type< float >();
    p[ 0 ].Get      = []( void* o ) -> void* { return &reinterpret_cast<C*>(o)->mC; };
    

    // set fields

    Properties      = p;
    NumProperties   = 1;
}

gwRTTI_REGISTER( C );


////////////////////////////////////////////////////////////////////////////////
// Base

template<> void TypeInfoImpl< Base >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, nullptr };
    Inherits = bases;

}

gwRTTI_REGISTER( Base );


////////////////////////////////////////////////////////////////////////////////
// C1

template<> void TypeInfoImpl< C1 >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, Base, nullptr };
    Inherits = bases;

}

gwRTTI_REGISTER( C1 );


////////////////////////////////////////////////////////////////////////////////
// C2

template<> void TypeInfoImpl< C2 >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, Base, nullptr };
    Inherits = bases;

}

gwRTTI_REGISTER( C2 );


////////////////////////////////////////////////////////////////////////////////
// D

template<> void TypeInfoImpl< D >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, C1, C2, nullptr };
    Inherits = bases;

}

gwRTTI_REGISTER( D );


////////////////////////////////////////////////////////////////////////////////
// E

template<> void TypeInfoImpl< E >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, D, nullptr };
    Inherits = bases;

}

gwRTTI_REGISTER( E );


////////////////////////////////////////////////////////////////////////////////
// V1

template<> void TypeInfoImpl< V1 >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, Base, nullptr };
    Inherits = bases;

}

gwRTTI_REGISTER( V1 );


////////////////////////////////////////////////////////////////////////////////
// V2

template<> void TypeInfoImpl< V2 >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, Base, nullptr };
    Inherits = bases;

}

gwRTTI_REGISTER( V2 );


////////////////////////////////////////////////////////////////////////////////
// D2

template<> void TypeInfoImpl< D2 >::Create()
{
    //
    // base classes
    //
    
    static const TypeInfo* bases[] = { this, V1, V2, nullptr };
    Inherits = bases;

}

gwRTTI_REGISTER( D2 );


