#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H

/// @brief Reads from a file the size of an array and its elements
/// @param array Populates the array from the filepath. 
/// @param max_size Max length of the array
/// @param filepath Where the data will be read
/// @return Size of the array
unsigned int array_from_file(int array[], unsigned int max_size,const char *filepath);

/// @brief Prints elements from an array
/// @param a Input an array
/// @param length Length of the array
void array_dump(int a[], unsigned int length);

#endif