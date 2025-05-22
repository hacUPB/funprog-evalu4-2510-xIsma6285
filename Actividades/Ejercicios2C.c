#include <stdio.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    printf("El contenido del arreglo y sus direcciones de memoria es: \n");
    for (int i = 0; i < 5; i++) {
        printf("numeros[%d] = %d\t Direccion: %p\n", i, numeros[i], (void*)&numeros[i]);
    }
    return 0;
}

/* Preguntas */
// 1. El valor de datos[5] en int datos[6] = {5, 82, 41}; es 0.
// 2. Para determinar el numero de elementos en un arreglo: sizeof(arreglo) / sizeof(arreglo[0])

/* Ejercicio 1 */
#include <stdio.h>
int main() {
    int numeros[10];
    for (int i = 0; i < 10; i++) {
        numeros[i] = 11 + i;
    }
    printf("Numeros en orden descendente:\n");
    for (int i = 9; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    printf("\n\n");
    return 0;
}

/* Ejercicio 2 */
#include <stdio.h>
int main() {
    int pares[5] = {2, 4, 6, 8, 10};
    printf("Numeros pares en orden ascendente:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", pares[i]);
    }
    printf("\n\n");
    return 0;
}

/* Ejercicio 3 */
#include <stdio.h>
int main() {
    int numeros[10];
    int suma = 0, resta = 0, multiplicacion = 1;
    printf("Ingrese 10 numeros enteros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
        suma += numeros[i];
        if (i == 0) {
            resta = numeros[i];
        } else {
            resta -= numeros[i];
        }
        multiplicacion *= numeros[i];
    }
    printf("\nSuma: %d\nResta acumulada: %d\nMultiplicacion acumulada: %d\n\n", suma, resta, multiplicacion);
    return 0;
}

/* Ejercicio 4 */
#include <stdio.h>
int main() {
    int array1[5], array2[5], combinado[10];
    printf("Ingrese 10 numeros (5 para cada arreglo):\n");
    for (int i = 0; i < 5; i++) {
        printf("Grupo 1 - Numero %d: ", i + 1);
        scanf("%d", &array1[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("Grupo 2 - Numero %d: ", i + 6);
        scanf("%d", &array2[i]);
    }
    for (int i = 0; i < 5; i++) {
        combinado[i] = array1[i];
        combinado[i + 5] = array2[i];
    }
    printf("\nArreglo combinado:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", combinado[i]);
    }
    printf("\n");
    return 0;
}

/* Ejercicio 5 */
#include <stdio.h>
void analizarNotas(float notas[], int tam) {
    float suma = 0;
    int aprobados = 0, reprobados = 0, sobresalientes = 0;
    for (int i = 0; i < tam; i++) {
        suma += notas[i];
        if (notas[i] >= 3.0) aprobados++;
        else reprobados++;
        if (notas[i] >= 4.0) sobresalientes++;
    }
    float promedio = suma / tam;
    printf("\n--- Estadisticas del curso ---\n");
    printf("Promedio general: %.2f\n", promedio);
    printf("Aprobados: %d\nReprobados: %d\nSobresalientes: %d\n", aprobados, reprobados, sobresalientes);
}

int main() {
    float notas[24];
    printf("Ingrese las notas de 24 estudiantes:\n");
    for (int i = 0; i < 24; i++) {
        printf("Estudiante %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
    analizarNotas(notas, 24);
    return 0;
}

/* Ejercicio 6 */
#include <stdio.h>
#define ESTUDIANTES 3
#define ACTIVIDADES 3

int main() {
    float notas[ESTUDIANTES + 1][ACTIVIDADES + 1];
    printf("Ingrese los porcentajes de las %d actividades:\n", ACTIVIDADES);
    for (int j = 0; j < ACTIVIDADES; j++) {
        printf("Porcentaje actividad %d: ", j + 1);
        scanf("%f", &notas[0][j]);
    }
    for (int i = 1; i <= ESTUDIANTES; i++) {
        printf("\nNotas del estudiante %d:\n", i);
        for (int j = 0; j < ACTIVIDADES; j++) {
            printf("Nota actividad %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
    for (int i = 1; i <= ESTUDIANTES; i++) {
        float definitiva = 0;
        for (int j = 0; j < ACTIVIDADES; j++) {
            definitiva += notas[i][j] * notas[0][j];
        }
        notas[i][ACTIVIDADES] = definitiva;
    }
    printf("\n--- Nota definitiva de los estudiantes ---\n");
    for (int i = 1; i <= ESTUDIANTES; i++) {
        printf("Estudiante %d - Nota definitiva: %.2f\n", i, notas[i][ACTIVIDADES]);
    }
    return 0;
}
