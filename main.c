#include "monty.h"

stack_pointers main_stack;

/**
 * main - entry point for the monty program.
 * @argc: number of arguments.
 * @argv: array of argument strings.
 *
 * Return: 0 if successful, otherwise if error encountered.
 */
int main(int argc, char **argv)
{
	FILE *fstream;
	char *buffer = NULL, *argtokens[2];
	size_t size;
	int linenumber = 0;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fstream = start_stream(argv[1]);
	init_main_stack(fstream);
	while (getline(&buffer, &size, fstream) != -1)
	{
		main_stack.buffer = buffer;
		init_argtokens(argtokens);
		linenumber++;
		tokenize_line(buffer, argtokens);
		main_stack.argtokens = argtokens;
		if (argtokens[0])
			execute_op(linenumber);
	}
	free(buffer);
	fclose(fstream);
	freedlist(main_stack.top);
	return (0);
}
