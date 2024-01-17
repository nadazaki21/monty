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

	for (i = 0; i < 3; i++)
	{
		argtokens[i] = NULL;
	}
}

/**
 * execute_op - executes the OP code provided in the argtokens array.
 * @argtokens: pointer to the string array of tokens.
 * @linenumber: the corresponding line number of the OP code.
 *
 * Return: void.
 */
void execute_op(char **argtokens, int linenumber)
{

}
