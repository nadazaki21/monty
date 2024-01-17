#include "monty.h"

/**
 * start_stream - opens a monty .m file into a FILE stream.
 * @filename: character pointer to the file name.
 *
 * Return: returns a FILE stream pointer, NULL if error encountered.
 */
FILE *start_stream(char *filename)
{
	FILE *filestream;

	filestream = fopen(filename, "r");
	if (filestream == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (filestream);
}

/**
 * init_argtokens - initializes all values of string tokens array to NULL.
 * @argtokens: pointer to the string array of token.
 *
 * Return: void.
 */
void init_argtokens(char **argtokens)
{
	int i;

	for (i = 0; i < 2; i++)
		argtokens[i] = NULL;
}


/**
 * tokenize_line - tokenizes a single line read from the FILE stream.
 * @buffer: pointer to the string of the line read from FILE stream.
 * @argtokens: pointer to the array of token strings produced.
 *
 * Return: void.
 */
void tokenize_line(char *buffer, char **argtokens)
{
	int i;
	char *string, *token;

	for (i = 0, string = buffer; i < 2; string = NULL, i++)
	{
		token = strtok(string, " \t\n");
		if (token == NULL || token[0] == '#')
			return;
		argtokens[i] = token;
	}
	main_stack.argtokens = argtokens;
}

/**
 * execute_op - executes the OP code provided in the argtokens array.
 * @linenumber: the corresponding line number of the OP code.
 *
 * Return: void.
 */
void execute_op(int linenumber)
{
	char *opcmd = main_stack.argtokens[0];
	void (*op_fun)(stack_t **stack, unsigned int line_number);

	op_fun = get_op_fun(main_stack.argtokens);
	if (op_fun == NULL)
	{
		dprintf(2, "L%d: unknown instruction %s\n", linenumber, opcmd);
		freedlist(main_stack.top);
		free(main_stack.buffer);
		fclose(main_stack.fstream);
		exit(EXIT_FAILURE);
	}
	op_fun(&main_stack.top, linenumber);
}

/**
 * get_op_fun - gets the corresponding function to the OPCODE.
 * @argtokens: pointer to the string array of tokens.
 *
 * Return: function pointer to a function that resembles the OPCODE.
 * (takes a stack_t double pointer and the linenumber).
 */
void (*get_op_fun(char **argtokens))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(argtokens[0], instructions[i].opcode) == 0)
			return (instructions[i].f);
	}
	return (NULL);
}
