#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
int main(void)
{
    srand(time(NULL)); // Generamos una semilla
    int temp[24];      /* Con esto ya tenemos declaradas las 24 variables */
    float media = 0;
    int hora;
 
    hora = rand();
    printf("%d\n", hora);
    /* Ahora tenemos que dar el valor de cada una */
    // for (hora = 0; hora < 24; hora++)
    // {
    //     rand();
    //     media += temp[hora];
    // }
    // media = media / 24;
    // printf("\nLa temperatura media es %f\n", media);
    return 0;
}