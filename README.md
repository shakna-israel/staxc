StaX.c
======

This is a C implementation of [StaX](https://github.com/shakna-israel/stax), a bytecode interpreter that resembles a Turing Tarpit.

Some extensions may be in use, check the [Language](#Language) section.

---

## Requirements

GCC (GNU C Compiler) is required, as we use some GNU extensions to the C language, that clang or msvc may not be able to cope with.

GNU Make is used to build the project.

Git is used to fetch dependencies.

---

## Compiling & Installing

To download and compile [Cello](http://libcello.org), and then compile StaX.c, run:

```
make all
```

*Note:* This does not install any libraries, or even StaX.c, so we won't ruin your system.

---

## Usage

To open, parse and execute a file:

```
./StaX.c filename.stax
```

Or, to evaluate some code from stdin:

```
./StaX.c -eval push:10 push:12 out
```

---

## Language

StaX is a stack-based language.

The user has access to 10 LIFO (Last-In-First-Out) stacks, and can cycle between them using the ```inc``` and ```dec``` commands.

```push``` can be used to push an item onto the stack.

It takes a single character, that can be a number, or normal character, which will get cast to an integer.

If the user supplies more than a single character, StaX will crash, with an error message.

To call push, write ```push``` followed by a colon, ```:```, followed by the character to push to the stack.

```drop``` can be used to remove an item from the top of the stack.

```dup``` can be used to copy the top item of the stack, and push the copy.

e.g. If the stack is [0, 1, 2] and we called ```dup```, the stack would become [0, 0, 1, 2]

```swap``` changes the positions of the top two items on the stack.

e.g. If the stack is [0, 1, 2] amd we ca;;ed ```swap```, the stack would become [1, 0, 2]

```rev``` reverses the entire stack.

```out``` casts each integer on the stack to a character, and then writes it to stdout.

```new``` reads a single keystroke from stdin, and treats it as if we tried to ```push``` the character.

```add``` drops the first two items from the stack, and pushes their sum to the top of the stack.

```sub``` drops the first two items from the stack, and pushes their difference to the top of the stack.

```mul``` drops the first two items from the stack, and pushes their product to the top of the stack.

```div``` drops the first two items from the stack, and pushes their quotient to the top of the stack.

```goto``` takes a label parameter, and jumps to that label in the execution loop.

A label is any sequence of characters beginning with a colon, ```:```, for example: ```:main```.

The goto to use to jump to the label, ```:main```, would be ```goto:main```.

**Note:** StaX needs a conditional construct. At this point in time, it doesn't exist, as the least surprising behaviours seem difficult to reason about.

StaX.c implements its own conditional construct, though this may be replaced by one from the official language spec in the future.

```?``` takes a single character, that is cast to an integer. If the top value of the stack is equal to this value, the next expression is evaluated, and the one after it is ignored.

Otherwise, the next expression is ignored, and the one after it is evaluated.

For example:

```
push:10
push:10
?:10
add
sub
```

Would leave the top of the stack as 20, as ```add``` was evaluated, as the top of the stack at ```?```'s call was 10.

---

## License

Unless otherwise mentioned within a file, all contents are licensed according to the contents of [LICENSE.md](LICENSE.md)

StaX.c makes use of [Cello](http://libcello.org), which is currently covered under a BSD license, to Daniel Holden.

Check the [LICENSE.md](Cello/LICENSE.md) file when compiling for up-to-date information. (Run ```make deps``` to download and compile Cello, without building StaX.c).
