#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256

typedef struct {
    int caracteres;
    int palabras;
    int espacios;
    int lineas;
} Estadisticas;

char* leerArchivo(const char* RETOPROG) {
    FILE* archivo = fopen(RETOPROG, "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

    fseek(archivo, 0, SEEK_END);
    long tam = ftell(archivo);
    rewind(archivo);

    char* buffer = (char*)malloc((tam + 1) * sizeof(char));
    if (!buffer) {
        printf("No se pudo asignar memoria.\n");
        fclose(archivo);
        return NULL;
    }

    fread(buffer, 1, tam, archivo);
    buffer[tam] = '\0';
    fclose(archivo);
    return buffer;
}

Estadisticas calcularEstadisticas(const char* texto) {
    Estadisticas est = {0, 0, 0, 0};
    int enPalabra = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];

        if (c != '\n')
            est.caracteres++;

        if (c == ' ') {
            est.espacios++;
            enPalabra = 0;
        } else if (c == '\n') {
            est.lineas++;
            enPalabra = 0;
        } else {
            if (!enPalabra) {
                est.palabras++;
                enPalabra = 1;
            }
        }
    }

    if (texto[0] != '\0' && texto[0] != '\n' &&
        texto[strlen(texto) - 1] != '\n') {
        est.lineas++;
    }

    return est;
}

void guardarEnArchivo(const char* RETOPROG, Estadisticas est) {
    FILE* f = fopen(RETOPROG, "w");
    if (!f) {
        printf("No se pudo crear el archivo.\n");
        return;
    }

    fprintf(f, "Estadísticas:\n");
    fprintf(f, "Caracteres: %d\n", est.caracteres);
    fprintf(f, "Palabras: %d\n", est.palabras);
    fprintf(f, "Espacios: %d\n", est.espacios);
    fprintf(f, "Líneas: %d\n", est.lineas);
    fclose(f);
    printf("Estadísticas guardadas en '%s'\n", RETOPROG);
}

int main() {
    int opcion;
    char RETOPROG[MAX_FILENAME];
    char* contenido = NULL;
    Estadisticas est = {0};

    do {
        printf("\n--- MENÚ ---\n");
        printf("1. Ingresar nombre de archivo\n");
        printf("2. Calcular estadísticas\n");
        printf("3. Guardar estadísticas (usando el mismo nombre RETOPROG)\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // limpiar salto de línea

        if (opcion == 1) {
            printf("Nombre del archivo (.txt): ");
            fgets(RETOPROG, MAX_FILENAME, stdin);
            for (int i = 0; RETOPROG[i] != '\0'; i++) {
                if (RETOPROG[i] == '\n') {
                    RETOPROG[i] = '\0';
                    break;
                }
            }

            if (contenido) {
                free(contenido);
                contenido = NULL;
            }

            contenido = leerArchivo(RETOPROG);
            if (contenido)
                printf("Archivo cargado correctamente.\n");

        } else if (opcion == 2) {
            if (!contenido) {
                printf("Primero debe cargar un archivo.\n");
            } else {
                est = calcularEstadisticas(contenido);
                printf("\nEstadísticas:\n");
                printf("Caracteres: %d\n", est.caracteres);
                printf("Palabras: %d\n", est.palabras);
                printf("Espacios: %d\n", est.espacios);
                printf("Líneas: %d\n", est.lineas);
            }

        } else if (opcion == 3) {
            if (!contenido) {
                printf("Primero debe cargar y analizar un archivo.\n");
            } else {
                guardarEnArchivo(RETOPROG, est);
            }

        } else if (opcion != 4) {
            printf("Opción no válida.\n");
        }

    } while (opcion != 4);

    if (contenido)
        free(contenido);

    printf("Programa finalizado.\n");
    return 0;
}
