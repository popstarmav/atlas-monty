#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    top++;
    stack[top] = value;
}

void pall() {
    int i;
    if (top == -1) {
        return;
    }
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
