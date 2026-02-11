#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x < 0)
    {
        y = -x;
    }
    else
        y = x;
}

int main(void) {
    int a=0, res=0;
    a =-10;
    absolute(a,res);
    printf("%d \n",res);
    return EXIT_SUCCESS;
}
/*¿Qué valor se mostraría al ejecutar 
la función main() del programa anterior
"Y"= 10
¿Qué valor se muestra por pantalla? 
0
¿Coincide con el programa en el lenguaje del teórico? 
No, no coincide con el valor de pantalla
*/

