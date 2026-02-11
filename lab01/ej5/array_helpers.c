#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "mybool.h"
#include "array_helpers.h"



unsigned int array_from_file(int array[], unsigned int max_size,const char *filepath) {
    
    FILE* file = fopen(filepath,"r");
    
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    
    unsigned int length;
    
    fscanf(file,"%u", &length);
    
    if(max_size < length)
    {
        fprintf(stderr,"tamaño del arreglo mayor que lo permitido");
        exit(EXIT_FAILURE); 
    }
    
    unsigned int lec;
    
    for(unsigned int i = 0; i < length; i++)
    {
        fscanf(file, "%u",&lec);
        array[i] = lec;
    }
    
    fclose(file);
    
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

mybool array_is_sorted(int a[], unsigned int length){
   
    mybool order = true;
    if (length > 0)
    {
        for (unsigned int i = 0; i < (length-1); i++)
        {
            if (a[i] > a[i+1])
            {
                order = false;
            }
        }
    }
    return order;
}