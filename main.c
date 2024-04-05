#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char line[100];
	char *opcode = strtok(line, " \n");
	char *arg = strtok(NULL, " \n");
	char *endptr;
	long int value = strtol(arg, &endptr, 10);
	unsigned int line_number = 0;
	stack_t **stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(;ine), file))
	{
		line_number++;

		if (opcode == NULL || strncmp(opcode, "#", 1) 1== 0)
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			if (arg == NULL)
			{
				frprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(file);
				exit(EXIT_FAILURE);
			}

			if (*endptr != '\0)
			{
				fprintf(stderr, "L%d: usage: push interger\n", line_number);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			push(stack, (int)value, line_number);

		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %\n", line_number, opcide);
		}
	}

	flcose(file);
	return(0);
}

