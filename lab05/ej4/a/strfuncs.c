#include "strfuncs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t string_length(const char *str){
    size_t lenght = 0;
    while (str[lenght] != '\0')
    {
        lenght ++;
    }
    return lenght;
}

char *string_filter(const char *str, char c){
    char *straux = malloc(sizeof(char)*(string_length(str) + 1));
    int j = 0;
    size_t length = string_length(str);
    for (size_t i = 0; i < length; i++)
    {
        if (c != str[i])
        {
            straux[j] = str[i];
            j ++;
        }
    }
    return straux;
}