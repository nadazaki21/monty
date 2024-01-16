#include "monty.h"
/**
 * is_number: ensure that the second argument of the line
 * is a number
 * @arg2: the second argument of the monty command
 * Return: 1  if it is a number 0 if not
 * 
*/
int is_number(char *arg2)
{
    char *tmp = arg2;
    while (tmp != NULL)
    {
        if (isdigit(*tmp))
            tmp++;
        else
        {
            dprintf(2, "L%d: unknown instruction %d", args->line_number, args->instruction->opcode );
            exit(EXIT_FAILURE);
        }
    }
    return (1);
}
/**
 * tokenize - tokenize the string into number of words(strings)
 * and assigns these string to the array of stingg of the global var
 * args
 * @str: the string to tokenize
*/
void tokenize(char *line)
{

    char delimiter = " ";
    /* array of strings*/
    char *tokens[2]; /* monty command is 2 arguments maximum*/
    int tokenCount = 0;

    /* Get the first token */
    char *token = strtok(line, delimiter);
    /* you pass the sting to be tokenized the first time only*/

    /* continue to get tokens */
    while (token != NULL && tokenCount < 2)
    /* limiting token count to  is important as rest of the line is not imp*/
    {
        tokens[tokenCount] = token;
        tokenCount++;
        token = strtok(NULL, delimiter);
    }

    /* Now, tokens[] array contains all the tokens */
    args->tokens = tokens;

}