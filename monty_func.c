#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    stack_t *stack = NULL;
    char line[MAX_LINE_LENGTH];
    unsigned int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;

        char *opcode = strtok(line, " \n");
        if (opcode == NULL || opcode[0] == '#') {
            continue;
        }

        char *arg = strtok(NULL, " \n");

        if (strcmp(opcode, "push") == 0) {
            if (arg == NULL) {
                fprintf(stderr, "Error: Missing argument for push at line %u\n", line_number);
                fclose(file);
                free_stack(stack);
                return EXIT_FAILURE;
            }
            int value = atoi(arg);
            push(&stack, value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(stack);
        } else {
            fprintf(stderr, "Error: Unknown opcode %s at line %u\n", opcode, line_number);
            fclose(file);
            free_stack(stack);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    free_stack(stack);
    return EXIT_SUCCESS;
}

#include "monty.h"

void free_stack(stack_t *stack) {
    while (stack != NULL) {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

