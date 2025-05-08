#include <stdio.h>
 
int main(void)
{
    // 0. Declaración de variables
    int cant_registros;
    float peso, estatura, imc;
    // 1. Declarar el puntero
    FILE *p_datos, *p_imc;
 
    // 2. Abrir el archivo
    p_datos = fopen("datos.txt", "r");
 
    // 3. Verficar que se pudo abrir el archivo
    if (!p_datos)
    {
        perror("No se pudo abrir.\n");
        return 1;
    }
 
    // 4. Operaciones de lectura
    fscanf(p_datos, "%d", &cant_registros);
    printf("Cantidad registros = %d\n", cant_registros);
    fscanf(p_datos, "%f", &peso);
    printf("Peso = %f\n", peso);
    fscanf(p_datos, "%f", &estatura);
    printf("Estatura = %f\n", estatura);
 
    imc = peso / (estatura * estatura);
    printf("IMC = %f\n", imc);
 
    return 0;
}