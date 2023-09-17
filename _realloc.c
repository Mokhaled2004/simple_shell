#include "shell.h"
/**
 * _realloc - lol
 * @ptr: lol
 * @old_size: loll
 * @new_size: loolo
 * Return: lol
*/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
void *new_ptr = malloc(new_size);
if (new_size == 0)
{
free(ptr);
return (NULL);
}
if (new_ptr == NULL)
{
return (NULL);
}
if (ptr != NULL)
{
size_t copy_size = old_size;
if (copy_size > new_size)
{
copy_size = new_size;
}
memcpy(new_ptr, ptr, copy_size);
free(ptr);
}
return (new_ptr);
}
