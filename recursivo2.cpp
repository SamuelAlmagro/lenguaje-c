#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int funcion(int dato){
dato=dato*dato;
return dato;
}

int main(){
int i,j;
i=2;
j=funcion(i);
printf("%i y %i",j+2,i-1);

}
