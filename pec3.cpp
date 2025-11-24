/**************************************
* NOMBRE: #Juan Antonio#
* PRIMER APELLIDO: #Fernandez#
* SEGUNDO APELLIDO: #Gonzalez#
* DNI: #99999999#
* EMAIL: #jantonio.gonzalez@mimail.com#
***************************************/
#include <stdio.h>
//array de los dias que tienen los meses años normales={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
//años bisiestos={0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} OJO el cambio de 28 por 29 se hace en
//void calendario
typedef int diasMes[13];
int bisiesto(int year){
  //funcion para identificar si es un año bisiesto
    return (year % 4 ==0 && year % 100 != 0)||(year % 400==0);

  }
//congruencia de zeller con ligera modificacion esta cuenta como:
//L=1 M=2 X=3 J=4 V=5 S=6 D=0
//para cambiar el D=0 se ha usado el if(h==0)
int diaInicio(int year, int mes) {
    int a = (14-mes)/12;
    int y = year-a;
    int m= mes + 12*a-2;
    int h;
    h=((1+y+y/4-y/100+y/400+(31*m)/12)%7);

    if(h==0){
      h=7;
      }
  return h;
}

void calendario (int year, int mes){
  //dos variables contador para contar los espacios en blanco del final
  //              colocar para los espacios en blanco del inicio
  //diaInicioMes simplemente es el int diaInicio que nos dice en que dia empieza el mes L=1,M=2...D=7
  int diaInicioMes = diaInicio(year, mes);
  int contador;
  int colocar;
//Cuantos dias tiene el mes en un array
diasMes Pvector = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
if(1601<=year && year<=3000){
  if(bisiesto(year) && mes==2){
  //pedimos el dia de inicio de mes 0=L 1=M ...
  Pvector[2]=29;
  //si es bisiesto enero tiene 29 dias
  }
}
  else{
    printf("El año esta fuera del rango permitido (1601-3000)");
    return;
    }
//imprimimos la hoja del calendario
  //primera fila
  switch(mes){
    case 0:
      printf("Mes incorrecto\n");
      break;
    case 1:
      printf("ENERO                  %i\n",year);
      break;
    case 2:
      printf("FEBRERO                %i\n",year);
      break;
    case 3:
      printf("MARZO                  %i\n",year);
      break;
    case 4:
      printf("ABRIL                  %i\n",year);
      break;
    case 5:
      printf("MAYO                   %i\n",year);
      break;
    case 6:
      printf("JUNIO                  %i\n",year);
      break;
    case 7:
      printf("JULIO                  %i\n",year);
      break;
    case 8:
      printf("AGOSTO                 %i\n",year);
      break;
    case 9:
      printf("SEPTIEMBRE             %i\n",year);
      break;
    case 10:
      printf("OCTUBRE                %i\n",year);
      break;
    case 11:
      printf("NOVIEMBRE              %i\n",year);
      break;
    case 12:
      printf("DICIEMBRE              %i\n",year);
      break;
    }
//segunda linea
printf("===========================\n");
//tercera linea
printf("LU  MA  MI  JU  VI | SA  DO\n");
//cuarta linea
printf("===========================\n");
//resto de filas
  //rellena los espacios de delante
  for (int i = 0; i < diaInicioMes-1; i++) {
    if(i%7==4){
      printf(" . ");
    }
    else if(i%7==5){
      printf("|");
      printf("  .  ");
      }

    else{
    printf(" .  ");
    }

  }

//rellenamos dias mes
  for (int a = 1; a <= Pvector[mes]; a++) {
    colocar = ((diaInicioMes-1)+a) % 7;
    if(colocar==5){
      printf("%2i ", a);
      }
    else if(colocar==6){
    printf("|");
    printf(" %2i  ", a);
    }
    else if(colocar==0){
      printf("%2i  ", a);
      printf("\n");
            }
    else{
      printf("%2i  ", a);
      }
  }

//rellenamos espacios de detras hay varios tipos de calendarios unos tiene 42 huecos y otros 32

  //si cae en Domingo el dia 1 entonces nos vemos obligados a añadir otra fila al calendario
  if(diaInicioMes-1==6){
  for(int b=1;b<=42 - (Pvector[mes] + diaInicioMes-1);b++){
    contador = ((Pvector[mes] + diaInicioMes-1)+b) % 7;
      if(contador==6){
        printf("| ");
        printf(" .  ");
        }
      else if(contador==5){
        printf(" . ");
        }
      else if(contador==0){
        printf(" . ");
        printf("\n");
        }
      else{
        printf(" .  ");
        }
  }
  }
  //basicamente todo mes que entre dentro de 35 huecos si le sumas los espacios en blanco de delante
  else if(35<(Pvector[mes] + diaInicioMes-1)){
    for(int b=1;b<=42 - (Pvector[mes] + diaInicioMes-1);b++){
    contador = ((Pvector[mes] + diaInicioMes-1)+b) % 7;
      if(contador==6){
        printf("| ");
        printf(" .  ");
        }
      else if(contador==5){
        printf(" . ");
        }
      else if(contador==0){
        printf(" . ");
        printf("\n");
        }
      else{
        printf(" .  ");
        }
  }
}
  //obligatoriamente si el dia 1 es domingo y el mes tiene 28 dias necesitamos otra fila
  else if (Pvector[mes]==28 && diaInicioMes==7){
    for(int b=1;b<=42 - (Pvector[mes] + diaInicioMes-1);b++){
    contador = ((Pvector[mes] + diaInicioMes-1)+b) % 7;
      if(contador==6){
        printf("| ");
        printf(" .  ");
        }
      else if(contador==5){
        printf(" . ");
        }
      else if(contador==0){
        printf(" . ");
        printf("\n");
        }
      else{
        printf(" .  ");
        }
  }

  }
  //cualquier mes que entre dentro de 35 huecos luego de sumarle los espacios en blanco de delante
  else{
    for(int b=1;b<=35 - (Pvector[mes] + diaInicioMes-1);b++){
    contador = ((Pvector[mes] + diaInicioMes-1)+b) % 7;
      if(contador==6){
        printf("| ");
        printf(" .  ");
        }
      else if(contador==5){
        printf(" . ");
        }
      else if(contador==0){
        printf(" . ");
        printf("\n");
        }
      else{
        printf(" .  ");
        }
  }
  }

  printf("\n");
}

//programa principal
//aqui pedimos el mes, el año y ejecutamos el subprograma calendario
int main(){
  int year,mes;
  //pedir mes
  printf("¿Mes (1-12)?");
  scanf("%i",&mes);
  if(mes<1 || mes>12){
    printf("Error: introduce un mes valido.(1-12)\n");
    return 0;
    }
  //pedir año
  printf("¿A%co (1601-3000)?",164);
  scanf("%i",&year);
  if(!(1601 <= year && year <= 3000)){
    printf("Error: introduce un A%co valido.\n",164);
    return 0;
    }
  //ejecutar void
calendario(year,mes);
return 0;

  }
