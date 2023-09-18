#include "shell.h"


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
    static char buffer[BUFFER_SIZE];
    static int buffer_index = 0;
    static int buffer_size = 0;
    char c;

    if (line == NULL || line_length == NULL || input_stream == NULL)
        return -1;

    if (buffer_index >= buffer_size)
    {
        buffer_size = fread(buffer, sizeof(char), BUFFER_SIZE, input_stream);
        buffer_index = 0;
        if (buffer_size <= 0)
            return -1;
    }

    c = buffer[buffer_index++];

    if (c == '\n')
    {
        *line = _realloc(*line, *line_length * sizeof(char), (*line_length + 1) * sizeof(char));
        (*line)[*line_length] = '\0';
        return *line_length;
    }
    else
    {
        *line = _realloc(*line, *line_length * sizeof(char), (*line_length + 1) * sizeof(char));
        (*line)[(*line_length)++] = c;
        return _getline(line, line_length, input_stream);
    }
}
