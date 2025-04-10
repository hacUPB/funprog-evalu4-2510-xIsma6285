#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
int main(void)
{
    srand(time(NULL)); // Generamos una semilla
    int temp[24];      /* Con esto ya tenemos declaradas las 24 variables */
    float media = 0;
    int hora, mayor = 0;
    /* Ahora tenemos que dar el valor de cada una */
    for (hora = 0; hora < 24; hora++)
    {
        temp[hora] = (rand() % ((35 - 14) + 1)) + 14;
        media += temp[hora];
        printf("%d  ", temp[hora]);
    }
    printf("\n");
    media = media / 24;
    mayor = temp[0];
    for (int i = 0; i < 24; i++)
    {
        if (temp[i] > mayor)
        {
            mayor = temp[i];
        }
    }
 
    printf("\nLa temperatura media es %f\n", media);
    printf("Mayor = %d\n", mayor);
    return 0;
}