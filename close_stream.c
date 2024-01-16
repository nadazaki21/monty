#include "monty.h"
/**
 * close_stream - closes the file stream
*/
void close_stream()
{
    fclose(args->stream);
}