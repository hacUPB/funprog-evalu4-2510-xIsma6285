#include <stdio.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int Datos[5] = {45, 32, 89, 11, 9};
    printf("%d\n", Datos[2]); //El indice 2 corresponde a la posicion en el banco de datos que empiezan a ser posicionados desde 0 es decir el dato 2 es el numero 89

    //Imprime los datos de ese arreglo
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n - %p\n", Datos[i], &Datos[i]);
    }
    return 0;

}