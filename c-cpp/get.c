#include <stdio.h>
#include <stdlib.h>

char *get_string(char *);

int main(void)
{
    char *input = get_string("Input: ");
    printf("%s", input);
    free(input);

    return 0;
}

char *get_string(char *message)
{
    int c = 0, len = 0;
    char *aux, *str = NULL;

    printf("%s", message);

    str = malloc(len + 1);
    while ((c = getchar()) != '\n')
    {
        str[len] = (char)c;
        len++;
        aux = realloc(str, len + 1);
        str = aux;
    }
    str[len] = '\0';

    return str;
}