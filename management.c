#include "main.h"

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

void freeAll(char **cmd, char *line)
{
	free(cmd);
	free(line);

	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - Copy Byte From Source To Destination
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @o: Size (How Much You Will Copy)
 *Return: Void Pointer
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
 * fill_an_array - Fill An Array By Constant Byte
 * @a:Void Pointer
 * @el: Int
 * @len:Length Int
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
 * _calloc -  Allocates Memory For An Array, Using Malloc.
 * @size: Size
 * Return: Void Pointer
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
