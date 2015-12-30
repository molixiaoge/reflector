# reflector
> A clang based tool for generating RTTI data from C/C++ code

This is the accompanying prototype code for my blog post (coming soon ...).

## Getting Setup

NB: There are pre-built versions of reflector in the bin folder for osx and windows.

### Reflector (Clang)

Reflector is a clang based tool, it requires the LLVM and Clang source tree. You can get more information on the [official site](http://clang.llvm.org/get_started.html).

Requires [git](https://git-scm.com/), [cmake](https://cmake.org/) and [python](https://www.python.org/) (required by cmake)


**Get LLVM**

```
git clone https://github.com/llvm-mirror/llvm.git
```

**Get Clang**

```bash
cd llvm/tools
git clone https://github.com/llvm-mirror/clang.git
cd ../..
```

**Get Reflector**
```
git clone https://github.com/gwaredd/reflector.git
```
Copy the reflector code into the clang tools source tree (`llvm/tools/clang/tools/reflector`).

On unix/osx
```
cp -r reflector/src/reflector/ llvm/tools/clang/tools/
```

On windows

```
robocopy reflector\src\reflector llvm\tools\clang\tools\reflector
```

Add the project to the cmake file, in `llvm/tools/clang/tools/CMakeLists.txt` add ...
```
add_clang_subdirectory(reflector)
```

To the end of the file, it will now be built as part of the llvm project.

**Make the things!**

Unix/osx/makefiles ...
```bash
mkdir build
cd build
cmake -G "Unix Makefiles" ../llvm
make
```

Or windows (VS 2015) ...
```bash
mkdir build
cd build
cmake -G "Visual Studio 14" ..\llvm
LLVM.sln
```

***(building may take some time)***

If this all worked then the reflector binary should be here ... `build/bin/reflector` (or `build\debug\bin` on windows)

To test reflector on some code. Edit the file `reflector/tests/compile_commands.json` and replace the directory field with the absolute path to that directory. Then run ...

```bash
    ./bin/reflector --show-errors ../reflector/tests/test.cpp
```

This should output JSON data to the stdout.

### Envision

Envision is a coffeescript script that takes the JSON output of reflector and turns it into C++ source for the prototype gwRTTI library (`src/gwRTTI/`).

This requires [node.js](https://nodejs.org/) and [coffeescript](http://coffeescript.org/).

**Install node.js**
* Download and install from http://nodejs.org

This installs the `npm` package manager required for the next two steps.

**Install coffeescript**

```bash
npm -g install coffee-script
```

**Install envision**

To install the modules required by envision ...
```bash
cd src/envision
npm install
```
To run envision on some test data
```bash
coffee envision.coffee ../../tests/test.json test_rtti.cpp
```

***Warnings are expected with this test file.***

This should create a `test_rtti.cpp` in the envision folder.

Have fun, big love

Gw
