#include "string.h"
#include <stdio.h>

int main(void){
    string word1 = string_create("Hello");
    string word2 = string_create("World!");
    printf("Words : Hello and World! are equals ? : %d\n",string_eq(word1, word2));
    printf("Word : Hello is less lexicographically than World! ? : %d\n",string_less(word1,word2));
    printf("Word : World! is less lexicographically than Hello ? : %d\n",string_less(word2,word1));
    word1 = string_destroy(word1);
    word2 = string_destroy(word2);
    return 0;
}