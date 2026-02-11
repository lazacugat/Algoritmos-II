#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

unsigned int array_from_stdin(int array[], unsigned int max_size) {
    unsigned int length;
    fprintf(stdout, "Ingrese el tamaño del arreglo \n");
    fscanf(stdin,"%u", &length);
    if(max_size < length)
    {
        fprintf(stderr,"tamaño del arreglo mayor que lo permitido");
        exit(EXIT_FAILURE); 
    }

    unsigned int lec;
    
    for(unsigned int i = 0; i < length; i++)
    {
        fprintf(stdout, "Ingrese el elemente %u del arreglo\n", lec);
        fscanf(stdin ,"%u",&lec);
        array[i] = lec;
    }

    return length;
}

void array_dump(int a[], unsigned int length) {
    
    printf("[");
    if (length > 0)
    {
        for (unsigned int i = 0; i < length - 1; i++)
        {
            printf(" %d,", a[i]);
        }
    
        printf(" %d", a[length - 1]);
    }

    printf("]\n");
}


int main() {
   
   int array[MAX_SIZE];
   
   unsigned int length = array_from_stdin(array, MAX_SIZE);
   
    array_dump(array, length);
   
    return EXIT_SUCCESS;
}
