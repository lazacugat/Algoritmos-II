#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if (x < 0)
    {
        *y = -x;
    }
    else
        *y = x;
}

int main(void) {
    int a=0, res=0;
    int *y = NULL;
    y = &res;
    a =-10;
    absolute(a,y);
    printf("%d \n",res);
    return EXIT_SUCCESS;
}
// ¿Se muestra el valor correcto? (en caso contrario revisar hasta lograr que sí lo haga)
// Si, a diferencia del ejercicio anterior se muestra el valor correcto abs(a) = 10
// El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out
// Es de tipo out, solo me importa su contenido a la salida del programa
// ¿Qué tipo de parámetros tiene disponibles C para sus funciones?
// los 3:
// Parámetros in: pasamos un valor a la funcion 
// Parámetros out: devolvemos un valor de la funcion
// Parámetros in/out:tomamos un valor in y devolvemos el mismo valor modificado o no.
