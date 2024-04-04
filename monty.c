#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

void push_opcode(stack_t **stack, char *arg) {
    int value;

    if (!isdigit(*arg) && *arg != '-' && *arg != '+') {
        fprintf(stderr, "usage: push integer\n");
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    push(stack, value);
}

void push(stack_t **stack, int value) {
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack == NULL) {
        new_node->next = NULL;
        *stack = new_node;
    } else {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}

void pall(stack_t **stack) {
    stack_t *current = *stack;

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int main(void) {
    stack_t *stack = NULL;

    push_opcode(&stack, "1");
    push_opcode(&stack, "2");
    push_opcode(&stack, "3");
    pall(&stack);

    return 0;
}

