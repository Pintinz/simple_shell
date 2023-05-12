#include "shell.h"

/**
 * str_cspn - A function that rejects characters
 * @str: string characters
 * @reject: the character it detects to start rejecting from
 * Return: it returns length
 */

int str_cspn(const char *str, const char *reject)
{
        int length, j;

        for (length = 0; str[length]; length++)
        {
                for (j = 0; reject[j]; j++)
                {
                        if (str[length] == reject[j])
                        {
                                return (length);
                        }
                }
        }
        return (length);
}
