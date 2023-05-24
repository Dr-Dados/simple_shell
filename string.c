#include "shell.h"
/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
int i = 0;
int val;

while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
{
i++;
}
val = s1[i] - s2[i];
return (val);
}
/**
 * _strncmp - Compare two strings up to a given number of characters.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of characters to compare.
 * Return: An integer less than, equal to, or greater
 *  than zero if the substring
 * of s1 is found, respectively, to be less than, to match, or be greater than
 * the substring of s2 up to n characters.
 */
size_t _strncmp(char *s1, char *s2, size_t n)
{
size_t i, j;

for (j = 0; s1[j] != '\0' && j < n; j++)
{
i = s1[j] - s2[j];

if (i != 0)
{
return (i);
}
}

return (0);
}
/**
 * _strlen - Calculate the length of a string.
 * @s: The input string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
int i;

for (i = 0; s[i] != 0; i++)
{
;
}

return (i);
}
/**
 * _strcpy - Copy a string from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 * Return: The pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

for (i = 0; src[i] != '\0'; i++)
dest[i] = src[i];

dest[i + 1] = 0;
return (dest);
}
/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string.
 * Return: The pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
int i, j = 0;

for (i = 0; dest[i] != '\0'; i++)
{
}

for (j = 0; src[j] != '\0'; j++)
{
dest[i] = src[j];
i++;
}

dest[i] = '\0';
return (dest);
}

