#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    FILE *p_archivo;
    p_archivo = fopen("C:\\Users\\B09S113est\\Documents\\kkk\\Texto1.txt", "w");
    fprintf(stdout, "Ingrese su nombre: \n")
    fgets(Nombre,sizeof(Nombre), stdin);
    Nombre[strlen(Nombre) - 1] = '\0';
    fprintf(stdout, "Cuantos años tienes?\n");
    scanf("%d", &edad);
    if (p_archivo != NULL)
    {
        printf("Se crea el archivo. \n");
        //Escribir columna de caracteres
        fprintf(p_archivo, "Este archivo es de preuba para Texto1.txt");
        fprintf(p_archivo, "Hola %s bienvenido \n", Nombre)
    }
 fclose(p_archivo);
 return 0;
    
}