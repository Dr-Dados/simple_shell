#include "shell.h"

/**
 * _putchar - Write a character to the standard output.
 * @c: The character to write.
 * Return: On success, returns the number of characters written.
 * On error, returns -1 and sets errno appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
