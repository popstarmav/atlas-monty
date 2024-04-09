#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[]) {
    FILE *file;
    char line[100];
    char *opcode;
    char *arg;
    char *endptr;
    long int value;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        line_number++;

        opcode = strtok(line, " \n");
        if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
            continue;

        arg = strtok(NULL, " \n");

        if (strcmp(opcode, "push") == 0) {
            if (arg == NULL) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                exit(EXIT_FAILURE);
            }

            value = strtol(arg, &endptr, 10);

            if (*endptr != '\0') {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                exit(EXIT_FAILURE);
            }

            push(&stack, (int)value);
        }
        else if (strcmp(opcode, "pall") == 0) {
            pall(stack);
        }
        else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        }
    }

    fclose(file);
    return 0;
}

