#include "main.h"

/**
 **re_alloc -  Reallocates A Memory Block
 *@ptr: Pointer
 *@old_size: Old Size
 *@new_size: New Size
 *Return: Void
 */
void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size)
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
 * free_array - Free Array Of Char Pointer And Char Pointer
 * @cmd:Array Pointer
 * @line:Char Pointer
 * Return: Void
 */
void free_array(char **cmd, char *line)
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
 * @n: Size (How Much You Will Copy)
 *Return: Void Pointer
 */
char *mem_cpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * fill_array - Fill An Array By Constant Byte
 * @a:Void Pointer
 * @el: Int
 * @len:Length Int
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
 * ca_alloc -  Allocates Memory For An Array, Using Malloc.
 * @size: Size
 * Return: Void Pointer
 */
void *ca_alloc(unsigned int size)
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