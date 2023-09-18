#include "shell.h"
#include <stdio.h>

/**
 * _getline - Read a line from the input stream
 * @line: Pointer to the line buffer
 * @line_length: Pointer to the length of the line
 * @input_stream: The input stream to read from
 *
 * Return: Number of characters read, or -1 on failure
 */
int _getline(char **line, size_t *line_length, FILE *input_stream)
{
    char *buffer = NULL;
    ssize_t read;

    if (line == NULL || line_length == NULL || input_stream == NULL)
        return -1;

    read = getline(&buffer, line_length, input_stream);
    if (read == -1)
    {
        free(buffer);
        return -1;
    }

    *line = buffer;
    return read;
}
