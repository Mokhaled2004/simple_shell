#include "shell.h"
#include <unistd.h>

void *_realloc(void* ptr, size_t old_size, size_t new_size) {
    void *new_ptr = malloc(new_size);
    	if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    if (new_ptr == NULL) {
        return NULL;
    }

    if (ptr != NULL) {
        size_t copy_size = old_size;
        if (copy_size > new_size) {
            copy_size = new_size;
        }
        memcpy(new_ptr, ptr, copy_size);

        free(ptr);
    }

    return new_ptr;
}
int _getline(char **line, int *len)
{
	char buffer[1024];
	int buffer_index = 0;
	int buffer_size = 0;
	char c;

	if (line == NULL)
		return (-1);

	while (1)
	{
		/* If the buffer is empty, read more input */
		if (buffer_index >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, 1024);
			buffer_index = 0;
			if (buffer_size <= 0)
			{
				break;
			}
		}

		/* Read a character from the buffer */
		c = buffer[buffer_index++];

		if (c == '\n')
		{
			/* End of line, terminate the string */
			(*line)[*len] = '\0';
			break;
		}
		else
		{
			*line = _realloc(*line, (*len) * sizeof(char), (*len + 1) * sizeof(char));
			(*line)[(*len)++] = c;
		}
	}

	return (*len);
}
