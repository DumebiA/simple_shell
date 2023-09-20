#include "main.h"

/**
 **re_alloc -  Reallocates A Memory Block
 *@p: Pointer
 *@os: Old Size
 *@ns: New Size
 *Return: Void
 */
void *re_alloc(void *p, unsigned int os, unsigned int ns)
{
	void *i;

	if (ns == os)
		return (p);
	if (ns == 0 && p)
	{
		free(p);
		return (NULL);
	}
	i = malloc(ns);
	if (i == NULL)
		return (NULL);
	if (p == NULL)
	{
		fill_array(i, '\0', ns);
		free(p);
	}
	else
	{
		mem_cpy(i, p, os);
		free(p);
	}
	return (i);

}
/**
 * free_array - Free Array Of Char Pointer And Char Pointer
 * @command:Array Pointer
 * @c:Char Pointer
 * Return: Void
 */
void free_array(char **command, char *c)
{
	free(command);
	free(c);
	command = NULL;
	c = NULL;
}

/**
 * mem_cpy - Copy Byte From Source To Destination
 * @d: Destination Pointer
 * @r: Source Pointer
 * @n: Size (How Much You Will Copy)
 *Return: Void Pointer
 */
char *mem_cpy(char *d, char *r, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		d[i] = r[i];
	}
	return (d);
}
/**
 * fill_array - Fill An Array By Constant Byte
 * @a:Void Pointer
 * @w: Int
 * @l:Length Int
 *Return: Void Pointer
 */
void *fill_array(void *a, int w, unsigned int l)
{
	char *c = a;
	unsigned int i = 0;

	while (i < l)
	{
		*c = w;
		c++;
		i++;
	}
	return (a);
}
/**
 * ca_alloc -  Allocates Memory For An Array, Using Malloc.
 * @s: Size
 * Return: Void Pointer
 */
void *ca_alloc(unsigned int s)
{
	char *c;
	unsigned int i;

	if (s == 0)
	return (NULL);
	c = malloc(s);
	if (c == NULL)
	return (NULL);
	for (i = 0; i < s; i++)
	{
		c[i] = '\0';
	}
	return (c);
}
