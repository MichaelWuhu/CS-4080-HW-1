# CS-4080 Homework 1

Coursework for CS-4080 based on [Crafting Interpreters](https://craftinginterpreters.com/).
The assignment was to complete the challenges at the end of Chapters 1, 2, and
3. Some of those challenges were written responses, while others required
working code.

## Repository Contents

### Chapter 1

The introductory programming exercises include:

- `Hello.java` - a basic Java program.
- `dlist.c` - a doubly linked list implementation in C with assertions covering
  insertion, lookup, deletion, and cleanup.
- `Makefile` - build, test, debug, and clean targets for the Chapter 1 code.

### Chapter 3

The `craftinginterpreters` directory contains the Crafting Interpreters project
source, including the Java tree-walk interpreter (`jlox`), the C bytecode
interpreter (`clox`), chapter notes, tests, and generated book pages.

`EdgeCases.lox` contains additional Lox programs used to exercise behavior such
as arithmetic precedence, equality across types, truthiness, and
short-circuiting.

## Requirements

- A POSIX shell and `make`
- A C compiler supporting C11
- A Java Development Kit with `javac` and `java`
- Dart, only if using the full Crafting Interpreters build and test tools

## Running Chapter 1

From the repository root:

```sh
cd "Chapter 1"
make
```

Run the C tests directly with:

```sh
make c
```

Run the Java exercise with:

```sh
make java
```

Remove Chapter 1 build output with `make clean`.

## Running Chapter 3

From the interpreter directory, install the Dart tool dependencies before using
the full build or test targets:

```sh
cd "Chapter 3/craftinginterpreters"
make get
```

Build the interpreters with:

```sh
make jlox
make clox
```

Run the Java interpreter interactively or against the included edge-case file:

```sh
java -cp build/java com.craftinginterpreters.lox.Lox
java -cp build/java com.craftinginterpreters.lox.Lox ../EdgeCases.lox
```

The repository also provides the upstream interpreter test targets:

```sh
make test_jlox
make test_clox
make test
```

## Topics Practiced

- Java and C compilation
- Dynamic memory management and doubly linked data structures
- Lexing, parsing, and evaluating a programming language
- Expressions, statements, variables, control flow, functions, classes, and
  inheritance in Lox
- Testing language behavior with focused edge cases

## Reference

The interpreter and book materials come from
[Crafting Interpreters](https://craftinginterpreters.com/) by Robert Nystrom.