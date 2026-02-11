#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static char *parse_args(int argc, char **argv) {
    if (argc != 2 )
    {
        fprintf(stderr, "Invalid arg count \n");
        exit(EXIT_FAILURE);
    }
    char *filepath = argv[1];
    if (filepath == NULL)
    {
        fprintf(stderr,"The filepath is invalid \n");
        exit(EXIT_FAILURE);
    }
    return filepath;
}

unsigned int data_from_file(const char *path,unsigned int indexes[], char letters[], unsigned int max_size){
    FILE *file = fopen(path,"r");
    if (file == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    int read;
    
    unsigned int counter = 0u, read_index = 0u;
    while (counter < max_size &&
        (read = fscanf(file,"%u ->",&read_index)) != EOF &&
        (read += fscanf(file," *%c*\n",&letters[counter])) == 2)
    {        
        if (read_index > max_size)
        {
            fprintf(stderr, "invalid data size \n");
            exit(EXIT_FAILURE);
        }
        indexes[counter] = read_index;
        counter ++;
    }
    if (read < 2 && read != EOF )
    {
        fprintf(stderr,"invalid data format \n");
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return counter;
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

int main(int argc,char *argv[]) {
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    char *filepath = NULL;
    filepath = parse_args(argc,argv);
    length = data_from_file(filepath,indexes,letters,MAX_SIZE);
    for (unsigned int counter = 0; counter < length; counter++)
    {
        sorted[indexes[counter]] = letters[counter];  
    }
    
    dump(sorted, length);

    return EXIT_SUCCESS;
}

