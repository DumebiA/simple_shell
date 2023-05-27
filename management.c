#include "main.h"

<<<<<<< HEAD
/**
 **_realloc - memory reallocation via malloc and free
 *@ptr: Pointer
 *@old_size: last size of pointer
 *@new_size: latest size pointer
 *Return: pointer to reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
=======
void *re_alloc(void *pointr, unsigned int os, unsigned int ns)
>>>>>>> 6e71b2a5f3eff3c32419dc876ae517412fc179f8
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
<<<<<<< HEAD
		fill_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		mem_cpy(result, ptr, old_size);
		free(ptr);
=======
		fill_array(res, '\0', ns);
		free(pointr);
	}
	else
	{
		mem_cpy(res, pointr, os);
		free(pointr);
>>>>>>> 6e71b2a5f3eff3c32419dc876ae517412fc179f8
	}
	return (res);

}
<<<<<<< HEAD

/**
 * mem_cpy - byte copy form source to dest
 * @dest: dest pointer
 * @src: sou pointer
 * @n: size
 *Return: void Pointer
 */
char *mem_cpy(char *dest, char *src, unsigned int n)
=======

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
>>>>>>> 6e71b2a5f3eff3c32419dc876ae517412fc179f8
{
	unsigned int n;

	for (n = 0;n < o; n++)
	{
<<<<<<< HEAD
		est[i] = src[i];
=======
		dest[n] = src[n];
>>>>>>> 6e71b2a5f3eff3c32419dc876ae517412fc179f8
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
<<<<<<< HEAD
void *fill_array(void *a, int el, unsigned int len)
=======
void *fill_array(void *x, int l, unsigned int length)
>>>>>>> 6e71b2a5f3eff3c32419dc876ae517412fc179f8
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
