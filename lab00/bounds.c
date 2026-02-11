#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int a[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = -1;
    for (unsigned int i = 0u ; length > i ; ++ i ){
        if (value < a[i]){
            res.is_upperbound = false;  
        }
        if (value > a[i]){
            res.is_lowerbound = false;  
        }
        if (value == a[i]){
            res.exists = true; 
            res.where = i;
        }
    }
    return res;
}

int main(void) {
    int length;
    int a[length];
    int value;
    printf("Ingrese la longitud del arreglo deseado \n");    
    scanf("%d", &length);
    assert (length > 0);
    for (int i = 0; i < length; i++)
    {
        printf("Ingrese el elemento en la posicion %d del arreglo \n", i);
        scanf("%d", &a[i]);
    }
    printf("Ingrese un valor a identificar \n");
    scanf("%d", &value);

    struct bound_data res = check_bound(value, a, length);
    printf("El valor ingresado es el mayor : %d\n", res.is_upperbound);
    printf("El valor ingresado es el menor : %d\n", res.is_lowerbound);
    printf("El valor existe : %u\n", res.exists);
    printf("Si el valor existe, la posicion del mismo es : %u\n", res.where);

    return EXIT_SUCCESS;
}

