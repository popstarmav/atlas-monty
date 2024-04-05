#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char line[100];
    int line_number = 0;
    while (fgets(line, sizeof(line), file)) {
        line_number++;

        char *opcode = strtok(line, " \n");
        if (opcode == NULL || strncmp(opcode, "#", 1) == 0) {
            continue;
        }

        if (strcmp(opcode, "push") == 0) {
            char *arg = strtok(NULL, " \n");
            if (arg == NULL) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file); // Close the file before exiting
                exit(EXIT_FAILURE);
            }

            char *endptr;
            long int value = strtol(arg, &endptr, 10);
            if (*endptr != '\0') {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file); // Close the file before exiting
                exit(EXIT_FAILURE);
            }
            push((int)value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        }
    }

    fclose(file);
    return 0;
}
