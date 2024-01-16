#include "monty.h"
/**
 * stream_failes - produces an error and closes program when failing to
 * open the file
 * @filename: file to be opened
*/
void stream_failed(char *filename)
{
    dprintf(2, "Error: Can't open file %s\n", filename);
    exit(EXIT_FAILURE);
}
/**
 * open_stream - opens the file to be read
 * @filename: file to be read
*/
void open_stream(char *filename)
{
    int fd;

    fd = open(filename, 0); /* 0 means reading only */
    if (fd == -1)
        stream_failed(filename);
    
    args->stream = fdopen(fd, "r");
    if (args->stream == NULL)
    {
        close(fd);
        stream_failed(filename);
    }
}