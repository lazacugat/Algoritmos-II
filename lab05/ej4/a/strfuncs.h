#ifndef _STRFUNCS_H_
#define _STRFUNCS_H_

#include <stddef.h>


/// @brief  Calculates the lenght of a string
/// @param str Pointer to a string
/// @return The length of the string pointed by str
size_t string_length(const char *str);

/// @brief Eliminates the Chars c in the string str
/// @param str Pointer to a string
/// @param c Char
/// @return  A new string obtained by taking the characters from str that are different from the character c
char *string_filter(const char *str, char c);

#endif