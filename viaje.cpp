#include <stdio.h>
int main(){
  int nota;
  const int Nveces=200;
  for(int intento=1;intento<=Nveces;intento++){
  printf("Valore Su estadia del 1 al 10\n");
  scanf("%2d",&nota);

  switch(nota){
    case 1:
    printf("insuficiente\n");
    break;
    case 2:
    printf("insuficiente\n");
    break;
    case 3:
    printf("insuficiente\n");
    break;
    case 4:
    printf("insuficiente\n");
    break;
    case 5:
    printf("Suficiente\n");
    break;
    case 6:
    printf("Bien\n");
    break;
    case 7:
    printf("Notable\n");
    break;
    case 8:
    printf("Notable\n");
    break;
    case 9:
    printf("Sobresaliente\n");
    break;
    case 10:
    printf("Sobresaliente\n");
    break;
    default:
      printf("Opcion no valida\n");
  }
  }
  }
