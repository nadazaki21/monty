#include "monty.h"
args_t *args = NULL;
/**
 * main - program main entry
 * @argc: number of args
 * @argv: the args themselves
 * Return: 0 0on succes and otherwise on failure
*/

int main(int argc, char **argv)
{
    (void) argv;
    size_t n = 0;

    if (argc != 2) /* validate the number of arguments*/
    {
        printf("USAGE: monty file");
        exit(EXIT_FAILURE);
    }
    initialize_args();
    open_stream(argv[2]);

    /*start to read from the file */
    while (getline(&(args->line) ,&n, args->stream))
    {
        args->line_number++;
        tokenize(args->line);
    }
    
    close_stream();
    freeall();

    return (0);
}