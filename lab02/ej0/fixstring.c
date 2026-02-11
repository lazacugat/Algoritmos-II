#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int counter = 0u;
    while (s[counter] != ('\0'))
    {
        counter ++;
    }
    return counter;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool value = true;
    for (unsigned int counter = 0u ; counter < fstring_length(s1); counter++){
        if (s1[counter] != s2[counter]){
                value = false;
                break;
            }
            
    }
    return value;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int counter = 0u;
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
