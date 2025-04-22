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
- `bytecodes/` - Directory containing example Monty bytecode files
- `maker` - Build script

## Installation

```bash
git clone https://github.com/popstarmav/atlas-monty.git
cd atlas-monty
