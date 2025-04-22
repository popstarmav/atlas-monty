# Monty - A Stacks and Queues Interpreter

## Overview

Monty is a simple interpreter for Monty ByteCode files. The language relies on a unique stack with specific instructions to manipulate it. This project implements a LIFO (Last In, First Out) stack and a FIFO (First In, First Out) queue data structure in C.

## Features

- Stack operations (push, pop, swap, etc.)
- Queue operations
- Mathematical operations on stack elements
- Stack printing and manipulation
- Error handling for various edge cases

## Files Structure

- `monty.h` - Main header file with function prototypes and structure definitions
- `monty_main.c` - Entry point of the program
- `monty.c` - Core interpreter functionality
- `helper.c` & `helper.h` - Helper functions for the interpreter
- `error.c` - Error handling functions
- `monty_intructions.c` - Implementation of Monty bytecode instructions
- `monty_opcode.c` - Opcode handling functionality
- `stack.c` - Stack operations implementation
- `bytecodes/` - Directory containing example Monty bytecode files
- `maker` - Build script

## Installation

```bash
git clone https://github.com/popstarmav/atlas-monty.git
cd atlas-monty

Execute

Compilation
gcc -Wall -Werror -Wextra -pedantic *.c -o monty

Execute

Or simply use the provided maker script:

./maker

Execute

Usage
./monty file.m

Execute

Where file.m is the path to the file containing Monty byte code.

Monty Bytecode Instructions
Opcode	Description
push <int>	Pushes an element onto the stack
pall	Prints all values on the stack
pint	Prints the value at the top of the stack
pop	Removes the top element of the stack
swap	Swaps the top two elements of the stack
add	Adds the top two elements of the stack
nop	Does nothing
sub	Subtracts the top element from the second top element
div	Divides the second top element by the top element
mul	Multiplies the second top element with the top element
mod	Computes the modulus of the second top element by the top element
pchar	Prints the char at the top of the stack
pstr	Prints the string starting at the top of the stack
rotl	Rotates the stack to the top
rotr	Rotates the stack to the bottom
stack	Sets the format to stack (LIFO)
queue	Sets the format to queue (FIFO)
Examples
$ cat bytecodes/00.m
push 1
push 2
push 3
pall
$ ./monty bytecodes/00.m
3
2
1

