#include<stdio.h>
//subprograma void no se ejecuta tal cual tenemos que invocarlo en int main
void imprimedescuento(){
  int descuento,importe;
  printf("Escribe el importe\n");
  scanf("%d",&importe);
  printf("Escribe el descuento en porcentaje\n");
  scanf("%d",&descuento);
  printf("El descuento de %d es: %f\n",importe,float(importe*(descuento/100.0)));
  }
//el intmain lo tienes que declarar como siempre sera el programa principal y es lo primero que se ejecuta
int main(){
  int descuento,importe,repetir;
  repetir=1;
  while(repetir>=1){
    //llamamos al subprograma void
    imprimedescuento();
    printf("Se Ha vuelto a ejecutar el programa\n");
    repetir=repetir+1;
    importe=0;
    descuento=0;

  }
    }
