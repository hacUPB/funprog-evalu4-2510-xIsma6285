#include <stdio.h>
int main(int argc, char const *argv[])
{
    int Datos[5] = {0};
   
   for (int cont = 0; cont < 15; cont++){
    Datos[0]++;
    Datos[1]+= 2;
    Datos[2]+= 3;
    Datos[3]+= 4;
    Datos[4]+= 5;
   
    for (int i = 0; i < 5; i++)
        {
            printf("%d  ", Datos[i]);
           }
    printf("\n");
}
       return 0;
}