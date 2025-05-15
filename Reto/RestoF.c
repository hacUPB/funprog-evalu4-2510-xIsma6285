#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_FILENAME 256
typedef struct {
   int caracteres;
   int palabras;
   int espacios;
   int lineas;
   int vocales[5]; // a, e, i, o, u
} Estadisticas;
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
   Estadisticas est = {0};
   int enPalabra = 0;
   for (int i = 0; texto[i] != '\0'; i++) {
       char c = texto[i];
       if (c != '\n') est.caracteres++;
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
       // Contar vocales (minúsculas o mayúsculas)
       c = tolower(c);
       if (c == 'a') est.vocales[0]++;
       else if (c == 'e') est.vocales[1]++;
       else if (c == 'i') est.vocales[2]++;
       else if (c == 'o') est.vocales[3]++;
       else if (c == 'u') est.vocales[4]++;
   }
   if (texto[strlen(texto) - 1] != '\n')
       est.lineas++;
   return est;
}
char* reemplazarPalabra(const char* texto, const char* buscar, const char* reemplazo) {
   int largoBuscar = strlen(buscar);
   int largoReemplazo = strlen(reemplazo);
   int nuevoTam = 0;
   // Calcular tamaño necesario
   const char* temp = texto;
   while ((temp = strstr(temp, buscar))) {
       nuevoTam += largoReemplazo;
       temp += largoBuscar;
   }
   nuevoTam += strlen(texto);
   char* resultado = (char*)malloc(nuevoTam + 1);
   if (!resultado) {
       printf("No se pudo asignar memoria para reemplazo.\n");
       return NULL;
   }
   char* ptr = resultado;
   while (*texto) {
       if (strstr(texto, buscar) == texto) {
           strcpy(ptr, reemplazo);
           ptr += largoReemplazo;
           texto += largoBuscar;
       } else {
           *ptr++ = *texto++;
       }
   }
   *ptr = '\0';
   return resultado;
}
void guardarResultados(const char* nombreArchivo, Estadisticas est, const char* textoModificado) {
   FILE* f = fopen(nombreArchivo, "w");
   if (!f) {
       printf("No se pudo crear el archivo.\n");
       return;
   }
   fprintf(f, "Estadísticas:\n");
   fprintf(f, "Caracteres: %d\n", est.caracteres);
   fprintf(f, "Palabras: %d\n", est.palabras);
   fprintf(f, "Espacios: %d\n", est.espacios);
   fprintf(f, "Líneas: %d\n", est.lineas);
   fprintf(f, "\nFrecuencia de vocales:\n");
   fprintf(f, "a: %d\n", est.vocales[0]);
   fprintf(f, "e: %d\n", est.vocales[1]);
   fprintf(f, "i: %d\n", est.vocales[2]);
   fprintf(f, "o: %d\n", est.vocales[3]);
   fprintf(f, "u: %d\n", est.vocales[4]);
   fprintf(f, "\nTexto Modificado:\n%s\n", textoModificado);
   fclose(f);
   printf("Resultados guardados en '%s'\n", nombreArchivo);
}
int main() {
   char nombreEntrada[MAX_FILENAME];
   char nombreSalida[MAX_FILENAME];
   char buscar[100], reemplazo[100];
   char* contenido = NULL;
   char* textoFinal = NULL;
   Estadisticas est;
   printf("Ingrese el nombre del archivo de entrada (.txt): ");
   fgets(nombreEntrada, MAX_FILENAME, stdin);
   nombreEntrada[strcspn(nombreEntrada, "\n")] = '\0'; // quitar \n
   contenido = leerArchivo(nombreEntrada);
   if (!contenido) return 1;
   est = calcularEstadisticas(contenido);
   printf("\nFrecuencia de vocales:\n");
   printf("a: %d\n", est.vocales[0]);
   printf("e: %d\n", est.vocales[1]);
   printf("i: %d\n", est.vocales[2]);
   printf("o: %d\n", est.vocales[3]);
   printf("u: %d\n", est.vocales[4]);
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
   guardarResultados(nombreSalida, est, textoFinal);
   free(contenido);
   free(textoFinal);
   return 0;
}