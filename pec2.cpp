/**************************************
* NOMBRE: #Juan Antonio#
* PRIMER APELLIDO: #Fernandez#
* SEGUNDO APELLIDO: #Gonzalez#
* DNI: #99999999#
* EMAIL: #jantonio.gonzalez@mimail.com#
***************************************/

#include <stdio.h>
int main (){
  int n;
  int posicionz,posiciond,posicionzb,posiciondb;
  //n=lados
  //h=espacios
  //x=numro simbolos iziquierda
  printf("%cLado del Rombo%c\n",168,63);
  scanf("%d",&n);
  if(n>=21){
    return 0;
    }
  //parte arriba
    for(int k=1;k<=n;k++){
        //espacios
      for(int h=1;h<=n-k;h++){
        printf(" ");
        }
        posicionz=0;
        //lado izquierdo
    for(int x=1;x<=((2*k)-1)-(k-1);x++){

      switch(posicionz%4){
        case 0:
        printf("%c",64);
        posicionz=posicionz+1;
        break;
        case 1:
        printf("%c",46);
        posicionz=posicionz+1;
        break;
        case 2:
        printf("%c",111);
        posicionz=posicionz+1;
        break;
        case 3:
        printf("%c",46);
        posicionz=posicionz+1;
        break;

      }
    }
    //lado derecho
    posiciond=posicionz-2;
      for(int x=1;x<=k-1;x++){

        switch(posiciond%4){
        case 0:
        printf("%c",64);
        posiciond=posiciond-1;
        break;
        case 1:
        printf("%c",46);
        posiciond=posiciond-1;
        break;
        case 2:
        printf("%c",111);
        posiciond=posiciond-1;
        break;
        case 3:
        printf("%c",46);
        posiciond=posiciond-1;
        break;
          }

    }
      printf("\n");
      }
  //parte abajo
  for(int y=1;y<=n-1;y++){
    //espacios
    for(int h=1;h<=y;h++){
        printf(" ");
        }
    //simbolos izquierda
    posicionzb=0;
        for(int z=1;z<=n-y;z++){

      switch(posicionzb%4){
        case 0:
        printf("%c",64);
        posicionzb=posicionzb+1;
        break;
        case 1:
        printf("%c",46);
        posicionzb=posicionzb+1;
        break;
        case 2:
        printf("%c",111);
        posicionzb=posicionzb+1;
        break;
        case 3:
        printf("%c",46);
        posicionzb=posicionzb+1;
        break;


      }
    }
    //simbolos derecha
        posiciondb=posicionzb-2;
      for(int m=1;m<=n-y;m++){

        switch(posiciondb%4){
        case 0:
        printf("%c",64);
        posiciondb=posiciondb-1;
        break;
        case 1:
        printf("%c",46);
        posiciondb=posiciondb-1;
        break;
        case 2:
        printf("%c",111);
        posiciondb=posiciondb-1;
        break;
        case 3:
        printf("%c",46);
        posiciondb=posiciondb-1;
        break;
          }

    }
printf("\n");
    }

  }
