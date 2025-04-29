#include <stdio.h>
#include <stidlob.h>
 
void func(void);
 
int main(void){
    func();
    func();
    func();
    func();
}
 
void func(void){
    static int cont = 0; //la variable static hace que la guarde en datos estaticos
    cont ++;
    printf("cont = %d\n", cont)
 
 
}