#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tamano;
    char *puntero;

    printf("Ingrese la cantidad de letras de su nombre y apellido (sin espacios): ");
    scanf("%d", &tamano);

    getchar();

    puntero = (char *) malloc((tamano + 1) * sizeof(char));
    if (puntero == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Ingrese su nombre y apellido (sin espacios): ");
    fgets(puntero, tamano + 1, stdin);

    printf("¡Hola %s!\n", puntero);

    free(puntero);

    return 0;
}
