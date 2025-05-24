#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
int main(void)
{
    srand(time(NULL)); // Generamos una semilla
    int temp[24];      /* Con esto ya tenemos declaradas las 24 variables */
    float media = 0;
    int hora, mayor = 0;
    int menor;
 for (int hora = 0; hora < 24; hora++)
 {
    temp[hora] = (rand() % ((35 - 14) + 1)) + 14;
    media += temp[hora];
    printf("%d\n", temp[hora]);
 }
 media = media / 24;
 
 for (int i = 0; i < 24; i++)
{
    if(temp[i] > mayor)
    {
        mayor = temp[i];
    }
}
menor = temp[0];
for (int i = 0; i < 24; i++)
{
    if(temp[i] < menor)
    {
        menor = temp[i];
    }
}
 
 printf("\nLa temperatura media es %f\n", media);
 printf("\nLa temperatura maxima fue: %d", mayor);
 printf("\nLa temperatura minima fue: %d\n", menor);
    return 0;
}