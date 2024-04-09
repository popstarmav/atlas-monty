#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void process_opcode(stack_t **stack, char *opcode, char *arg, unsigned int line_number) {
    if (strcmp(opcode, "push") == 0) {
        if (!arg || !isdigit(*arg)) {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        int value = atoi(arg);
        stack_t *new_node = malloc(sizeof(stack_t));
        if (!new_node) {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        new_node->n = value;
        new_node->next = *stack;
        *stack = new_node;
    } else if (strcmp(opcode, "pall") == 0) {
        stack_t *current = *stack;
        while (current != NULL) {
            printf("%d\n", current->n);
            current = current->next;
        }
    } else {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
