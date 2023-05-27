#include "main.h"

/**
 **_realloc - memory reallocation via malloc and free
 *@ptr: Pointer
 *@old_size: last size of pointer
 *@new_size: latest size pointer
 *Return: pointer to reallocated memory
 */
void *re_alloc(void *pointr, unsigned int os, unsigned int ns)
{
	void *res;

	if (ns == os)
		return (pointr);
	if (ns == 0 && pointr)
	{
		free(pointr);
		return (NULL);
	}
	res = malloc(ns);
	if (res == NULL)
		return (NULL);
	if (pointr == NULL)
	{

		fill_array(result, '\0', ns);
		free(pointr);
	}
	else
	{
		mem_cpy(result, pointr, os);
		free(pointr);
		fill_array(res, '\0', ns);
		free(pointr);
	}
	else
	{
		mem_cpy(res, pointr, os);
		free(pointr);

	}
	return (res);

}


/**
 * mem_cpy - byte copy form source to dest
 * @dest: dest pointer
 * @src: sou pointer
 * @n: size
 *Return: void Pointer
 */
void freeAll(char **cmd, char *line)
{
	free(cmd);
	free(line);

	cmd = NULL;
	line = NULL;
}

/**
 * mem_cpy - Copy Byte From Source To Destination
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @o: Size
 * Return: Void Pointer
 */
char *mem_cpy(char *dest, char *src, unsigned int o)
{
	unsigned int n;

	for (n = 0;n < o; n++)
	{

		dest[n] = src[n];
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
void *fill_array(void *x, int l, unsigned int length)
{
	char *o = x;
	unsigned int n = 0;

	while (n < length)
	{
		*o = l;
		o++;
		n++;
	}
	return (x);
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
