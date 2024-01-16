#include "monty.h"
/**
 * 
*/
void initialize_args()
{
    args = malloc(sizeof(args_t));
    if (args == NULL)
        dprintf(2, "Error: malloc failed");
    
    args->stream = NULL;
    args->line = NULL;

    args->line_number = 0;
}