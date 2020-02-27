# lattec

lattec is a LLVM based compiler for small object oriented language, Latte. This project was developed as part of Compilers class at my university. It demonstrates how to use antlr4 parser and LLVM libraries to develop a compiler that translates programs written in custom, imperative programming language supporting basic features like: multiple types, functions, objects, inheritance, standard input/output.

## Prerequisites

Before you compile lattec, make sure you have the following software installed:
- cmake >= 3.8
- llvm toolchain
- clang compiler

## Build
To build lattec, it should be enough to execute the following comands from root repository directory:

```
mkdir build
cmake ..
make -j12
```
Be aware that if your llvm toolchain is installed in non-standard directory, it may be necessary to launch `cmake` command with `CMAKE_PREFFIX_PATH` variable set to root of your llvm installation. Example invocation:
```
CMAKE_PREFIX_PATH=/path/to/llvm cmake ..
```

During building process, the following things will be done:
- antlr4 C++ runtime will be downloaded and compiled, if needed
- clang will be used to generate platform-specfic code needed to run some of Latte functionality. It will be located at `${ROOT_REPO_DIR}/lib/runtime.ll`
- compiler's entrypoint bash script will created at `${ROOT_REPO_DIR}/latc_llvm`. **Do not move this file**, or the compiler won't work. Also, before you use this script, make sure binaries of your installation of llvm toolchain (in particular: `llvm-as`, `llvm-link`) are available in your `PATH` environment variable.

## Usage
Example Latte programs and compiler invocations are available in `${ROOT_REPO_DIR}/tests` directory, in the following bash scripts:
- run_good.sh
- run_bad.sh
- run_arrays1.sh
- run_struct.sh
- run_objects1.sh
- run_obects2.sh

These scripts run unit tests for corresponding functionality of Latte programming language. They compile Latte programs located in `${ROOT_REPO_DIR}/tests/good`, `${ROOT_REPO_DIR}/tests/bad`, `${ROOT_REPO_DIR}/tests/extensions` directories into LLVM bytecode, then use `lli` LLVM interpreter to run the programs and compare outputs with expected ones.

## Latte programming language overview

Latte is a simple object oriented programming language that implements a subset of Java functionality using C inspired syntax. The syntax is defined in a format understood by antlr4 parser generator, which is used to generate parser's C++ code. The grammar is located in `${ROOT_REPO_DIR}/grammar/Latte.g4`.

The following code snippet implements [FizzBuzz](https://en.wikipedia.org/wiki/Fizz_buzz) in Latte while demonstrating key features of the language. Latte uses function `int main()` as its entry point:

```
// Custom object deifinition
class PrintableValue {
  int val;

  // All object methods are virtual and
  // can be overriden by child objects
  void setValue(int newValue) {
    val = newValue;
  }

  void printValue() {
    // printInt(int) is one of the functions
    // defined in src/runtime/runtime.c available
    // in every Latte program
    printInt(val);
  }
}

// Example of inheritance with
// overriden virtual function
class Fizz extends PrintableValue {
  void printValue() {
    printString("Fizz");
  }
}

class Buzz extends PrintableValue {
  void printValue() {
    printString("Buzz");
  }
}

// Example of inheritance with overloaded virtual function
class FizzBuzz extends PrintableValue {
  void printValue() {
    printString("FizzBuzz");
  }
}

class PrintableValueFactory {
  PrintableValue constructValue(int val) {
    PrintableValue ret = new PrintableValue;

    // If / else
    if (val % (3*5) == 0) {
      ret = new FizzBuzz;
    } else if (val % 3 == 0) {
      ret = new Fizz;
    } else if (val % 5 == 0) {
      ret = new Buzz;
    }

    ret.setValue(val);
    return ret;
  }
}

int main() {
  // Declaration & deifinition
  int i = 0;

  // Latte is strongly typed and supports custom objects
  PrintableValueFactory factory = new PrintableValueFactory;

  // While loop
  while (i < 30) {
    PrintableValue val = factory.constructValue(i+1);
    val.printValue();
    i = i+1;
  }

  return 0;
}

```

Every Latte program ships with additional runtime functions defined in C in `${ROOT_REPO_DIR}/src/runtime/runtime.c`.

Additional examples of Latte programs are available in `tests` directory.