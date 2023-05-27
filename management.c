#include "main.h"

/**
 **_realloc - memory reallocation via malloc and free
 *@ptr: Pointer
 *@old_size: last size of pointer
 *@new_size: latest size pointer
 *Return: pointer to reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		mem_cpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);

}

/**
 * mem_cpy - byte copy form source to dest
 * @dest: dest pointer
 * @src: sou pointer
 * @n: size
 *Return: void Pointer
 */
char *mem_cpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		est[i] = src[i];
	}
	return (dest);
}
/**
 * free_all - release array of *char and *char
 * @cmd: *array
 * @line: *char
 * Return: void
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	cmd = (NULL);
	free(line);
	line = NULL;
}

/**
 * fill_array - array fillied with constant
 * @a: pointer
 * @el: Int
 * @len:Int len
 *Return: Void Pointer
 */
void *fill_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * _calloc - memory allocation via malloc
 * @size: size
 * Return: void Pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
