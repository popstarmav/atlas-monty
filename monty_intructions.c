#include "monty.h"
#include <ctype.h>
#include "helper.h"

/* Print the value at the top of the stack, followed by a newline */
void pint(stack_t *stack, unsigned int line_number) {
    if (!stack) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack->n);
}

/* Print all values on the stack, starting from the top */
void pall(stack_t *stack) {
    stack_t *current = stack;
    while (current) {
        printf("%d\n", current->n);
        current = current->next;
    }
}
