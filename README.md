LATTE
-----

Important:
All source files are compiled against LLVM in /home/students/inf/PUBLIC/MRJP/llvm39
and as such, compiled files should be run using
/home/students/inf/PUBLIC/MRJP/llvm39/bin/lli


1. Installation and usage

Use `make` to build compilers. It wraps cmake (as it is the build system used).

After compilation, latc_llvm executable should be available
under root directory. Its usage is as defined in assignment specification.

Implemented features:
- core Latte LLVM compiler (front-end + back-end) [+ bugfix from 1st submit]
- optimizations: dead code elimination (code after returns is not generated)
- extensions: arrays, objects with virtual functions and inheritance
- basic garbage collection: strings are initialized with refcount equal to 1,
    during assignments, reference counts are checked, and strings are freed if they are 0,
    also during scope leaving [e.g. block leave, function leave], reference counts are decremented too

2. Directory structure

bash/ - bash scripts wrapping final binaries
src/ - source code
grammar/ - ANTLR4 grammar definition
include/ - includes (e.g. antlr4-runtime)
lib/ - libraries
tests/ - test files

3. Libraries

Used libraries:
- llvm - LLVM IR code generation
- lib/libantlr4-runtime.a - antlr4 C++ runtime for parsing
- lib/runtime.ll, lib/runtime.bc - runtime bytecode
- C system libraries for runtime


