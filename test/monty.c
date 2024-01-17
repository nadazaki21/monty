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
	fstream = fopen(argv[1], "r");
	if (fstream == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fstream) != -1)
	{
		i = 0;
		string = buffer;
		linenumber++;
		while (1)
		{
			token = strtok(string, " \n");
			if (token == NULL)
				break;
			argtokens[i] = token;
			printf("%p\n", argtokens[i]);
			string = NULL;
			i++;
		}
		argtokens[i] = NULL;
	}
	fclose(fstream);
	free(buffer);
	return (0);
}
