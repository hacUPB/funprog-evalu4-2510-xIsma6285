/*
Esta versión se realiza con arreglos de datos usando
Memoria Dinámica
*/
 
#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    // 0. Declaración de variables
    int cant_registros;
    float *peso, *estatura, *imc; // Punteros para memoria dinámica
    // 1. Declarar el puntero
    FILE *p_datos;
 
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
 
    // Reservamos la memoria de forma dinámica
    peso = (float *)malloc(cant_registros * sizeof(float));
    estatura = (float *)malloc(cant_registros * sizeof(float));
    imc = (float *)malloc(cant_registros * sizeof(float));
 
    if (!peso || !estatura || !imc) // Si cualquiera de los punteros es Nulo, se cierra la app
    {
        perror("No se pudo reservar la memoria\n");
        fclose(p_datos);
        return 1;
    }
 
    for (int i = 0; i < cant_registros; i++)
    {
        fscanf(p_datos, "%f", &peso[i]);
        printf("Peso = %f\n", peso[i]);
        fscanf(p_datos, "%f", &estatura[i]);
        printf("Estatura = %f\n", estatura[i]);
        imc[i] = peso[i] / (estatura[i] * estatura[i]);
        printf("IMC = %f\n", imc[i]);
    }
 
    // Liberar la memoria dinámica
    free(peso);
    free(estatura);
    free(imc);
    return 0;
}