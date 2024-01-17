#include "monty.h"

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
	char *buffer = NULL, *token, *argtokens[3], *string;
	size_t size;
	int i, linenumber = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fstream = start_stream(argv[1]);
	while (getline(&buffer, &size, fstream) != -1)
	{
		init_argtokens(argtokens);
		linenumber++;
		for (i = 0, string = buffer; i < 2; string = NULL, i++)
		{
			token = strtok(string, " \n");
			if (token == NULL)
				break;
			argtokens[i] = token;
		}
		argtokens[i] = NULL;
		execute_op(argtokens, linenumber);
	}
	fclose(fstream);
	free(buffer);
	return (0);
}
