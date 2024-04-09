#include "monty.h"

/* Push an element onto the stack */
void push(stack_t **stack, int value) {
    
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (!*stack) {
        new_node->next = NULL;
    } else {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

/* Pop the top element from the stack */
int pop(stack_t **stack, unsigned int line_number) {
    if (!*stack) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = (*stack)->n;
    stack_t *temp = *stack;
    *stack = (*stack)->next;
    free(temp);

    if (*stack)
        (*stack)->prev = NULL;

    return value;
}

/* Swap the top two elements of the stack */
void swap(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    int temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

/* Add the top two elements of the stack */
void add(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}

