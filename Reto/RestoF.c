#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME 256

// Contadores simples (sin estructuras ni ctype)
int esVocal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

char* leerArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }
    fseek(archivo, 0, SEEK_END);
    long tam = ftell(archivo);
    rewind(archivo);
    char* buffer = (char*)malloc((tam + 1) * sizeof(char));
    if (!buffer) {
        fclose(archivo);
        return NULL;
    }
    fread(buffer, 1, tam, archivo);
    buffer[tam] = '\0';
    fclose(archivo);
    return buffer;
}

void calcularEstadisticas(const char* texto, int* caracteres, int* palabras, int* espacios, int* lineas, int* vocales) {
    *caracteres = *palabras = *espacios = *lineas = 0;
    for (int i = 0; i < 5; i++) vocales[i] = 0;

    int enPalabra = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if (c != '\n') (*caracteres)++;

        if (c == ' ') {
            (*espacios)++;
            enPalabra = 0;
        } else if (c == '\n') {
            (*lineas)++;
            enPalabra = 0;
        } else {
            if (!enPalabra) {
                (*palabras)++;
                enPalabra = 1;
            }
            if (c == 'a' || c == 'A') vocales[0]++;
            else if (c == 'e' || c == 'E') vocales[1]++;
            else if (c == 'i' || c == 'I') vocales[2]++;
            else if (c == 'o' || c == 'O') vocales[3]++;
            else if (c == 'u' || c == 'U') vocales[4]++;
        }
    }
    if (texto[strlen(texto) - 1] != '\n') (*lineas)++;
}

char* reemplazarPalabra(const char* texto, const char* buscar, const char* reemplazo) {
    int lenBuscar = strlen(buscar);
    int lenReemplazo = strlen(reemplazo);
    int nuevoTam = strlen(texto);

    const char* temp = texto;
    while ((temp = strstr(temp, buscar))) {
        nuevoTam += lenReemplazo - lenBuscar;
        temp += lenBuscar;
    }

    char* resultado = (char*)malloc(nuevoTam + 1);
    if (!resultado) return NULL;

    char* ptr = resultado;
    while (*texto) {
        if (strstr(texto, buscar) == texto) {
            strcpy(ptr, reemplazo);
            ptr += lenReemplazo;
            texto += lenBuscar;
        } else {
            *ptr++ = *texto++;
        }
    }
    *ptr = '\0';
    return resultado;
}

void guardarResultados(const char* nombreArchivo, int caracteres, int palabras, int espacios, int lineas, int* vocales, const char* texto) {
    FILE* f = fopen(nombreArchivo, "w");
    if (!f) return;

    fprintf(f, "Estadisticas:\n");
    fprintf(f, "Caracteres: %d\n", caracteres);
    fprintf(f, "Palabras: %d\n", palabras);
    fprintf(f, "Espacios: %d\n", espacios);
    fprintf(f, "Lineas: %d\n", lineas);
    fprintf(f, "\nFrecuencia de vocales:\n");
    fprintf(f, "a: %d\n", vocales[0]);
    fprintf(f, "e: %d\n", vocales[1]);
    fprintf(f, "i: %d\n", vocales[2]);
    fprintf(f, "o: %d\n", vocales[3]);
    fprintf(f, "u: %d\n", vocales[4]);
    fprintf(f, "\nTexto Modificado:\n%s\n", texto);

    fclose(f);
}

int main() {
    char nombreEntrada[MAX_FILENAME];
    char nombreSalida[MAX_FILENAME];
    char buscar[100], reemplazo[100];

    char* contenido = NULL;
    char* textoFinal = NULL;
    int caracteres, palabras, espacios, lineas, vocales[5];

    printf("Ingrese el nombre del archivo de entrada: ");
    fgets(nombreEntrada, MAX_FILENAME, stdin);
    nombreEntrada[strcspn(nombreEntrada, "\n")] = '\0';

    contenido = leerArchivo(nombreEntrada);
    if (!contenido) return 1;

    calcularEstadisticas(contenido, &caracteres, &palabras, &espacios, &lineas, vocales);

    printf("\nFrecuencia de vocales:\n");
    printf("a: %d\n", vocales[0]);
    printf("e: %d\n", vocales[1]);
    printf("i: %d\n", vocales[2]);
    printf("o: %d\n", vocales[3]);
    printf("u: %d\n", vocales[4]);

    printf("\nIngrese palabra a buscar: ");
    fgets(buscar, 100, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    printf("Ingrese palabra para reemplazar: ");
    fgets(reemplazo, 100, stdin);
    reemplazo[strcspn(reemplazo, "\n")] = '\0';

    textoFinal = reemplazarPalabra(contenido, buscar, reemplazo);
    if (!textoFinal) {
        free(contenido);
        return 1;
    }

    printf("Ingrese nombre del archivo de salida: ");
    fgets(nombreSalida, MAX_FILENAME, stdin);
    nombreSalida[strcspn(nombreSalida, "\n")] = '\0';

    guardarResultados(nombreSalida, caracteres, palabras, espacios, lineas, vocales, textoFinal);

    free(contenido);
    free(textoFinal);
    return 0;
}
