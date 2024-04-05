#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

#define STACK_SIZE 100

long long int stack[STACK_SIZE];
int top = -1;

void push(long long int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    top++;
    stack[top] = value;
}

void pall() {
    if (top == -1) {
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%lld\n", stack[i]);
    }
}
