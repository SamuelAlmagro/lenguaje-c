#include <stdio.h>
int main(){
  //declaracion variables
  int Dia,Mes,Ano;
  int Dia2,Mes2,Ano2;
  int Edad;
  //pedir cumpleaños
  printf("Dime la fecha de tu cumpleanos\n");
  printf("introduce el Dia\n");
  scanf("%2d",&Dia);
  printf("introduce el Mes\n");
  scanf("%2d",&Mes);
  printf("introduce el Ano\n");
  scanf("%4d",&Ano);
  //fecha hoy
  printf("introduce la fecha de hoy\n");
  printf("introduce el dia\n");
  scanf("%2d",&Dia2);
  printf("introduce el Mes\n");
  scanf("%2d",&Mes2);
  printf("introduce el Ano\n");
  scanf("%4d",&Ano2);
  //decir fecha
  printf("La fecha de tu cumpleanos es:\nDia %2d Mes %2d Ano %4d\n",Dia,Mes,Ano);
  printf("La fecha de hoy es:\nDia %2d Mes %2d Ano %4d\n",Dia2,Mes2,Ano2);
  //calcular edad
  Edad=Ano2-Ano;
  printf("tu Edad es: %d Anos",Edad);
}
