#include "monty.h"
void freeall()
{
    /* free args memebers first if they were assigned any value*/
    if (args != NULL)
        free(args);

}