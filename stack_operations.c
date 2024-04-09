#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void push(stack_t **stack, int value) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;

    if (*stack == NULL) {
        new_node->next = NULL;
    } else {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}

void pall(stack_t *stack) {
    while (stack != NULL) {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}

