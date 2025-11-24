#include<stdio.h>

/* en el enum cada dato se guarda como const int Uno = 1; asi que no puedes declarar variables con el mismo nombre */

typedef enum Numeros {cero,uno,dos,tres,cuatro,cinco};
typedef Numeros Uno[3];

int main(){
Uno Dos = {tres,cuatro,cinco};
printf("{Cero,Uno,Dos,Tres,Cuatro,Cinco}\n");
for(int i=0;i<3;i++){
printf("el valor es = %i\n",Dos[i]);
}
}
