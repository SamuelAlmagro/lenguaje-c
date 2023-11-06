#include <stdio.h>
#include <stdlib.h>

int main(){
int edad,repetir,correcto;
float precio,descuento;
repetir=0;

while(repetir<3){
  printf("dime tu edad\n");
  scanf("%3d",&edad);
  printf("dime el precio\n");
  scanf("%5f",&precio);
    if(edad<18){
      descuento=precio*0.1;
    }
    else{
      descuento=precio*0.5;
    }
        printf("tienes que pagar: %f\n",descuento);
        repetir=repetir+1;
        printf("-----------------------------------------\n");

    }
return 0;
}
