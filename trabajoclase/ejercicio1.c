#include <stdio.h>
 
int main( int argc, char const *argv[])
{
    int array_10[10];
 
    for (int i = 0; i < 10; i++)
    {
        array_10[i] = i + 11;
        printf("%d ", array_10[i]);
    }
    return 0;
}