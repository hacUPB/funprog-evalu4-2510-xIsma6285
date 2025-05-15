#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *pfile;
    int letra = '1';
    pfile = fopen("Texto2.txt", "a");
    if (pfile)
    {
        while(letra != '?')
        {
            caracter = fgetc(stdio);
            letra = fputc(caracter, pfile);

        }

    }
    fclose(pfile);M
    return 0;
}