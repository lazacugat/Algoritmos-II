#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    unsigned int counter = 0;
    while (s[counter] != ('\0'))
    {
        counter = counter + 1;
    }
    return counter;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool value = true;
    for (unsigned int counter = 0 ; counter < fstring_length(s1); counter++){
        if (s1[counter] != s2[counter]){
                value = false;
                break;
            }
            
    }
    return value;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int counter = 0;
    bool value = true;
        while (s1[counter] == s2[counter]){
            counter ++;
        }
    if (s1[counter] > s2[counter])
    {
        value = false;
    }
    return value;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux,s1);
    fstring_set(s1,s2);
    fstring_set(s2,aux);
}


