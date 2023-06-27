#include "holberton.h"
/**
 * _getenv - gets PATH member from environ
 * @name: pointer to PATH string
 *
 * Return: pointer to PATH member string or NULL if not found
 */
char *_getenv(const char *name)
{
	int i, result;

	for (i = 0; environ[i]; i++)
	{
		result = _PATHstrcmp(name, environ[i]);
		if (result == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}

