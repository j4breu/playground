#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"

char *str = NULL;

char *get_string(char *message)
{
    char *aux = NULL;
    int c = 0;
    size_t len = 0;

    printf("%s", message);

    str = malloc(1);
    if (!str)
    {
        return NULL;
    }

    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        if (len + 1 > SIZE_MAX)
        {
            return NULL;
        }

        str[len] = (char)c;
        len++;

        aux = realloc(str, len);
        if (!aux)
        {
            return NULL;
        }
        str = aux;
    }

    str[len] = '\0';

    return str;
}

#if defined (__GNUC__)
    void __attribute__((destructor)) cleanup();
#else
    #error Default compiler / version is not recognized.
#endif

void cleanup(void)
{
    free(str);
}
