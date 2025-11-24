/**************************************
* NOMBRE: #Samuel#
* PRIMER APELLIDO: #Almagro#
* SEGUNDO APELLIDO: #Meno#
* DNI: #51249764#
* EMAIL: #samuelalmagro2@gmail.com#
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//NUMERO FINCAS
const int Fields=20;
//NUMERO MAX MAQUINAS
const int Machines=10;
//TAMAÑO MAX NOMBRES
const int MaxName=20;
//NUMERO MAX DE ESPACIOS EN HECTARIAS
const int MaxH=3;
//UN GRADO DE LATITUD EQUIVALE 110KM
const float FACTLAT=110.0;
//UN GRADO DE LONGITUD EQUIVALE 110KM
const float FACTLON=110.0;
//VOLVER AL MENU
int M=0;
//NUMERO DE NODOS BORRADOS MAQUINAS
int Mdell=0;
//NUMERO DE NODOS BORRADOS FINCAS
int Fdell=0;
//NUMERO DE DIAS SIN COSECHA Y VIAJE
int Nday=0;
//NUMERO DE DIAS COSECHADOS
int Cday=0;

//STRUCT DE DATOS DE MAQUINAS
typedef struct tNodeMachine{
  //DATOS MAQUINA
  int IDM;
  char Name[MaxName];
  char Crop;
  int Cap;
  float Lat;
  float Lon;
  //DATOS ALQUILER NUEVOS
  int NRday;
  int NRmonth;
  int NRyear;
  int NFIDM;
  int NRtime;
  //DATOS ALQUILER VIEJOS
  int Rday;
  int Rmonth;
  int Ryear;
  int FIDM;
  int Rtime;

  tNodeMachine *Next;
};

//PUNTEROS USADOS EN MAQUINAS
typedef tNodeMachine *tPointMachine;
tPointMachine EditM , auxM, StartM;

//STRUCT DE DATOS DE FINCAS
typedef struct tNodeField{
  int IDM;
  char Name[MaxName];
  char Crop;
  int Size;
  float Lat;
  float Lon;
  tNodeField *Next;
};

//PUNTEROS USADOS EN FINCAS
typedef tNodeField *tPointField;
tPointField EditF, auxF,  StartF;

//ARRAY USADO PARA LISTAR MAQUINAS
typedef int MNodes[Machines];
MNodes a;

//ESTA FUNCION ES PARA CALCULAR DISTANCIAS
float Distance(float lat1, float lon1, float lat2, float lon2) {
    float DistLat=0;
    float Distlon=0;
    float Dist=0;

    lat1 = (lat1 * 3.14) / 180.0;
    lon1 = (lon1 * 3.14) / 180.0;
    lat2 = (lat2 * 3.14) / 180.0;
    lon2 = (lon2 * 3.14) / 180.0;

    DistLat = lat2 - lat1;
    Distlon = lon2 - lon1;

    Dist = sqrt(DistLat * DistLat + Distlon * Distlon);;

    return Dist;
}

//ESTA FUNCION CUENTA EL NUMERO DE CARACTERES EN UN STRING
 int Charcount(char Longitud[]){
      return strlen(Longitud);
      }

//ESTA FUNCION LA USO PARA DIFERENCIAR LAS UNIDADES,DECENAS Y CENTENAS EN HECTARIAS
int CountDigit(int numb) {
    int digitCount = 0;
    if (numb == 0) {
        return 1;
    }
    while (numb != 0) {
        numb = numb / 10;
        digitCount++;
    }
    return digitCount;
}


//ARRAY PARA EL CALENDARIO
typedef int diasMes[13];
diasMes Pvector = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//FUNCION AÑO BISIESTO
int bisiesto(int year){
    return (year % 4 ==0 && year % 100 != 0)||(year % 400==0);

  }


//ESTE PARAMETRO ES EL MENU DE EDITAR FINCAS
void EditField(){
  int Comparation;
  int Idem=0;
  char sn;
  char NCrop;

  printf("====================================================\n");
  printf("\n");
  printf("Editar Finca:\n");
  printf("    Identificador (n%cmero entre 1 y 20)?:",163);
  scanf("%i",&Idem);

  while(Idem!=Comparation){
  EditF=EditF->Next;
  Comparation=EditF->IDM;
    }

  Comparation=0;
  printf("    Nombre (entre 1 y 20 caracteres)?:");
  scanf(" %s",&EditF->Name);

  printf("    Tipo (G-Grano, U-Uva, A-Aceituna, B-Borrar)?");
  scanf(" %c",&EditF->Crop);
  NCrop=EditF->Crop;

  printf("    Tama%co (hect%creas)?:", 164,160);
  scanf(" %i",&EditF->Size);

  printf("    Ubicaci%cn (Latitud)?:",162);
  scanf(" %f",&EditF->Lat);

  printf("    Ubicaci%cn (Longitud)?:",162);
  scanf(" %f",&EditF->Lon);
  printf("\n");
  printf("IMPORTANTE: Esta opci%cn borra los datos anteriores.\n",162);
  printf("Son correctos los nuevos datos (S/N)?:");

  while(sn!='N'&& sn!='S'){
  scanf(" %c",&sn);
  }

    if(sn=='N'){
      strcpy(EditF->Name, "");
      EditF->Crop='\0';
      EditF->Size=0;
      EditF->Lon=0;
      EditF->Lat=0;
  }
  sn='\0';

  if(NCrop=='B'){
    Fdell=Fdell+1;
    auxF=EditF;
    EditF=EditF->Next;
    auxF->Next=NULL;
    auxF=EditF;
    StartF=EditF;
    StartF=StartF->Next;

      while(Idem!=Comparation){

        EditF=EditF->Next;
        StartF=StartF->Next;
        Comparation=StartF->IDM;
  }
  EditF->Next=auxF;
  StartF->Next=NULL;
  }
printf("\n");
printf("====================================================\n");
printf("\n");
printf("Volver al Menu Principal?(S/N)\n");
  while(sn!='N'&& sn!='S'){
  scanf(" %c",&sn);
  }
    if(sn=='N'){
      system("cls");
      EditField();
      }
    else if(sn=='S'){
      system("cls");
      M=1;
      }
sn='\0';
}

//ESTE PARAMETRO ES EL MENU DE EDITAR MAQUINAS
void EditMachine(){
  int Comparation;
  int Idem=0;
  char sn;
  char NCrop;

  printf("====================================================\n");
  printf("\n");
  printf("Editar M%cquina:\n",160);
  printf("    Identificador (n%cmero entre 1 y 10)?:",163);
  scanf("%i",&Idem);

  while(Idem!=Comparation){
  EditM=EditM->Next;
  Comparation=EditM->IDM;
    }

  Comparation=0;
  printf("    Nombre (entre 1 y 20 caracteres)?:");
  scanf(" %s",&EditM->Name);

  printf("    Tipo (G-Grano, U-Uva, A-Aceituna, B-Borrar)?");
  scanf(" %c",&EditM->Crop);
  NCrop=EditM->Crop;

  printf("    Capacidad (hect%creas/d%ca)?:",160,161);
  scanf(" %i",&EditM->Cap);

  printf("    Ubicaci%cn inicial (Latitud)?:",162);
  scanf(" %f",&EditM->Lat);

  printf("    Ubicaci%cn inicial (Longitud)?:",162);
  scanf(" %f",&EditM->Lon);
  printf("\n");
  printf("IMPORTANTE: Esta opci%cn borra los datos anteriores.\n",162);
  printf("Son correctos los nuevos datos (S/N)?:");

  while(sn!='N'&& sn!='S'){
  scanf(" %c",&sn);
  }

    if(sn=='N'){
      strcpy(EditM->Name, "");
      EditM->Crop='\0';
      EditM->Cap=0;
      EditM->Lon=0;
      EditM->Lat=0;
  }
  sn='\0';

  if(NCrop=='B'){
    Mdell=Mdell+1;
    auxM=EditM;
    EditM=EditM->Next;
    auxM->Next=NULL;
    auxM=EditM;
    StartM=EditM;
    StartM=StartM->Next;

      while(Idem!=Comparation){

        EditM=EditM->Next;
        StartM=StartM->Next;
        Comparation=StartM->IDM;
  }
  EditM->Next=auxM;
  StartM->Next=NULL;
  }
printf("\n");
printf("====================================================\n");
printf("\n");
printf("Volver al Menu Principal?(S/N)\n");
  while(sn!='N'&& sn!='S'){
  scanf(" %c",&sn);
  }
    if(sn=='N'){
      system("cls");
      EditMachine();
      }
    else if(sn=='S'){
      system("cls");
      M=1;
      }
sn='\0';
}

//ESTE PARAMETRO ES EL MENU DE LISTAR MAQUINAS
void ListMachine(){
  char LCrop;
  int count=0;
  int Comp=0;
  int NameL=0;
  int MORE=0;
  int BigNum=0;
  int longitud=0;
  int Hl=0;
  char sn='\0';

longitud=(Machines-Mdell);
  printf("================================================================\n");
  printf("\n");
  printf("Tipo de m%cquinas a listar (G-Grano, U-Uva, A-Aceituna, T-Todas)?\n",160);
  scanf(" %c",&LCrop);
      printf("Id       Nombre              Tipo      Capacidad\n");


//PONER EL ARRAY A 0
for (int i = 0; i < Machines; i++) {
    a[i] = 0;
    EditM = EditM->Next;
}
//ESTO ES PARA SABER EL IDM MAS GRANDE EN MIS NODOS Y ASI ORDENAR DE MAYOR A MENOR
for (int i = 0; i < Machines; i++) {
    a[i] = EditM->IDM;
    EditM = EditM->Next;
}


while (MORE < Machines) {
    if (a[MORE] > BigNum) {
        BigNum = a[MORE];
    }
    MORE = MORE + 1;
}

//ESTO ES PARA PONER EL PUNTERO EN EL NUMERO QUE SIGE DESPUES DEL MAS GRANDE ESTO SI 10 ES EL MAS GRANDE NOS PONE EN EL 1 SI NO SE HA BORRADO 1
while(EditM->IDM != BigNum){
  EditM = EditM->Next;
  }

//IMPRIME LOS DATOS
    switch(LCrop){
      case 'G':

while(longitud!=count){

  if(EditM->Crop=='G'){
    count=count+1;
    printf("%i       ", EditM->IDM);
      if(EditM->IDM<10){
        printf(" ");
        }
    printf("%s",EditM->Name);
    NameL = Charcount(EditM->Name);
    for (int i = 0; i < (MaxName-NameL); i++) {
    printf(" ");
        }
    printf("Grano    ");
    printf(" %i", EditM->Cap);
    for(int i=0;i<=MaxH-CountDigit(EditM->Cap);i++){
      printf(" ");
      }
    printf("hect%crias/d%ca\n",160,161);

    EditM = EditM->Next;
    }
  else if (EditM->Crop!='G'){
    count=count+1;
    EditM = EditM->Next;

    }
  }
break;

      case 'U':

while(longitud!=count){

  if(EditM->Crop=='U'){
    count=count+1;
    printf("%i       ", EditM->IDM);
      if(EditM->IDM<10){
        printf(" ");
        }
    printf("%s",EditM->Name);
    NameL = Charcount(EditM->Name);
    for (int i = 0; i < (MaxName-NameL); i++) {
    printf(" ");
        }
    printf("Uva      ");
    printf(" %i", EditM->Cap);
    for(int i=0;i<=MaxH-CountDigit(EditM->Cap);i++){
      printf(" ");
      }
    printf("hect%crias/d%ca\n",160,161);
    EditM = EditM->Next;
    }
  else if (EditM->Crop!='U'){
    count=count+1;
    EditM = EditM->Next;

    }
  }
break;

      case 'A':

while(longitud!=count){

  if(EditM->Crop=='A'){
    count=count+1;
    printf("%i       ", EditM->IDM);
      if(EditM->IDM<10){
        printf(" ");
        }
    printf("%s",EditM->Name);
    NameL = Charcount(EditM->Name);
    for (int i = 0; i < (MaxName-NameL); i++) {
    printf(" ");
        }
    printf("Aceituna ");
    printf(" %i", EditM->Cap);
    for(int i=0;i<=MaxH-CountDigit(EditM->Cap);i++){
      printf(" ");
      }
    printf("hect%crias/d%ca\n",160,161);
    EditM = EditM->Next;
    }
  else if (EditM->Crop!='A'){
    count=count+1;
    EditM = EditM->Next;

    }
  }
break;
      case 'T':

while(longitud!=count){

  if(EditM->Crop!='\0'){
    count=count+1;
    printf("%i       ", EditM->IDM);
      if(EditM->IDM<10){
        printf(" ");
        }
    printf("%s",EditM->Name);
    NameL = Charcount(EditM->Name);
    for (int i = 0; i < (MaxName-NameL); i++) {
    printf(" ");
        }

    if(EditM->Crop=='A'){
    printf("Aceituna ");
    }
    else if(EditM->Crop=='U'){
    printf("Uva      ");
    }
    else if(EditM->Crop=='G'){
    printf("Grano    ");
    }


    Hl=CountDigit(EditM->Cap);
    for(int i=0;i<=MaxH-Hl;i++){
      printf(" ");
      }
    printf("%i", EditM->Cap);
    printf(" hect%crias/d%ca\n",160,161);
    EditM = EditM->Next;
    }
  else if (EditM->Crop=='\0'){
    count=count+1;
    EditM = EditM->Next;

    }
  }
break;
  }
printf("================================================================\n");
printf("\n");
printf("Volver al Menu Principal?(S/N)\n");
  while(sn!='N'&& sn!='S'){
  scanf(" %c",&sn);
  }
    if(sn=='N'){
      system("cls");
      ListMachine();
      }
    else if(sn=='S'){
      system("cls");
      M=1;
      }
sn='\0';
}

//ESTE PARAMETRO ES EL MENU DE LISTAR FINCAS
void ListFields(){
  char LCrop;
  int count=0;
  int Comp=0;
  int NameL=0;
  int MORE=0;
  int BigNum=0;
  int longitud=0;
  int Hl=0;
  char sn='\0';

longitud=(Fields-Fdell);
  printf("====================================================================================\n");
  printf("\n");
  printf("Tipo de Fincas a listar (G-Grano, U-Uva, A-Aceituna, T-Todas)?\n");
  scanf(" %c",&LCrop);
      printf("Id       Nombre              Tipo        Tama%co            Latitud   Longitud\n",164);


//PONER EL ARRAY A 0
for (int i = 0; i < Fields; i++) {
    a[i] = 0;
    EditF = EditF->Next;
}
//ESTO ES PARA SABER EL IDM MAS GRANDE EN MIS NODOS Y ASI ORDENAR DE MAYOR A MENOR
for (int i = 0; i < Fields; i++) {
    a[i] = EditF->IDM;
    EditF = EditF->Next;
}


while (MORE < Fields) {
    if (a[MORE] > BigNum) {
        BigNum = a[MORE];
    }
    MORE = MORE + 1;
}

//ESTO ES PARA PONER EL PUNTERO EN EL NUMERO QUE SIGE DESPUES DEL MAS GRANDE ESTO SI 10 ES EL MAS GRANDE NOS PONE EN EL 1 SI NO SE HA BORRADO 1
while(EditF->IDM != BigNum){
  EditF = EditF->Next;
  }

//IMPRIME LOS DATOS
    switch(LCrop){
      case 'G':

while(longitud!=count){

  if(EditF->Crop=='G'){
    count=count+1;
    printf("%i       ", EditF->IDM);
      if(EditF->IDM<10){
        printf(" ");
        }
    printf("%s",EditF->Name);
    NameL = Charcount(EditF->Name);
    for (int i = 0; i < (MaxName-NameL); i++) {
    printf(" ");
        }
    printf("Grano    ");
    printf(" %i", EditF->Size);
    for(int i=0;i<=MaxH-CountDigit(EditF->Size);i++){
      printf(" ");
      }
    printf("hect%crias       ",160);

    printf("%.3f       ", EditF->Lat);
    printf("%.3f\n", EditF->Lon);

    EditF = EditF->Next;
    }
  else if (EditF->Crop!='G'){
    count=count+1;
    EditF = EditF->Next;

    }
  }
break;

      case 'U':

while(longitud!=count){

  if(EditF->Crop=='U'){
    count=count+1;
    printf("%i       ", EditF->IDM);
      if(EditF->IDM<10){
        printf(" ");
        }
    printf("%s",EditF->Name);
    NameL = Charcount(EditF->Name);
    for (int i = 0; i < (MaxName-NameL); i++) {
    printf(" ");
        }
    printf("Uva      ");
    printf(" %i", EditF->Size);
    for(int i=0;i<=MaxH-CountDigit(EditF->Size);i++){
      printf(" ");
      }
    printf("hect%crias       ",160);

    printf("%.3f       ", EditF->Lat);
    printf("%.3f\n", EditF->Lon);

    EditF = EditF->Next;
    }
  else if (EditF->Crop!='U'){
    count=count+1;
    EditF = EditF->Next;

    }
  }
break;

      case 'A':

while(longitud!=count){

  if(EditF->Crop=='A'){
    count=count+1;
    printf("%i       ", EditF->IDM);
      if(EditF->IDM<10){
        printf(" ");
        }
    printf("%s",EditF->Name);
    NameL = Charcount(EditF->Name);
    for (int i = 0; i < (MaxName-NameL); i++) {
    printf(" ");
        }
    printf("Aceitunas ");
    printf(" %i", EditF->Size);
    for(int i=0;i<=MaxH-CountDigit(EditF->Size);i++){
      printf(" ");
      }
    printf("hect%crias       ",160);

    printf("%.3f       ", EditF->Lat);
    printf("%.3f\n", EditF->Lon);

    EditF = EditF->Next;
    }
  else if (EditF->Crop!='A'){
    count=count+1;
    EditF = EditF->Next;

    }
  }
break;
      case 'T':

while(longitud!=count){

  if(EditF->Crop!='\0'){
    count=count+1;
    printf("%i       ", EditF->IDM);
      if(EditF->IDM<10){
        printf(" ");
        }
    printf("%s",EditF->Name);
    NameL = Charcount(EditF->Name);
    for (int i = 0; i < (MaxName-NameL); i++) {
    printf(" ");
        }

    if(EditM->Crop=='A'){
    printf("Aceituna ");
    }
    else if(EditF->Crop=='U'){
    printf("Uva      ");
    }
    else if(EditF->Crop=='G'){
    printf("Grano    ");
    }


    Hl=CountDigit(EditF->Size);
    for(int i=0;i<=MaxH-Hl;i++){
      printf(" ");
      }
    printf("%i", EditF->Size);
    printf(" hect%Crias       ",160);
    printf("%.3f       ", EditF->Lat);
    printf("%.3f\n", EditF->Lon);
    EditF = EditF->Next;
    }
  else if (EditF->Crop=='\0'){
    count=count+1;
    EditF = EditF->Next;

    }
  }
break;
  }
printf("\n");
printf("====================================================================================\n");
printf("\n");
printf("Volver al Menu Principal?(S/N)\n");
  while(sn!='N'&& sn!='S'){
  scanf(" %c",&sn);
  }
    if(sn=='N'){
      system("cls");
      ListMachine();
      }
    else if(sn=='S'){
      system("cls");
      M=1;
      }
sn='\0';
}

//MENU DE ALQUILER
void RentMachine(){
  //DATOS NUEVOS
  int ADay=0;
  int AMonth=0;
  int AYear=0;
  int AFID=0;
  int ASize=0;
  int ALat=0;
  int ALon=0;
  int CATime=0;
  //DATOS VIEJOS

  int BDay=0;
  int BMonth=0;
  int BYear=0;
  int BFID=0;
  int BSize=0;
  int CBTime=0;
  //
  int Time=0;
  int MID=0;
  int TravelTime=1;
  int FTime=0;
  char sn;
  int AMonth2;
  int AYear2;
  int ADay2;

  printf("====================================================================================\n");
  printf("\n");

  printf("Fecha comienzo cosecha: D%ca?",161);
  scanf("%i",&ADay);
  printf("Fecha comienzo cosecha: Mes?");
  scanf("%i",&AMonth);
  printf("Fecha comienzo cosecha: A%co?",164);
  scanf("%i",&AYear);
  printf("Identificador de finca (n%cmero entre 1 y 20)?",163);
  scanf("%i",&AFID);
  printf("Identificador de M%cquina (n%cmero entre 1 y 10)?",160,163);
  scanf("%i",&MID);
  //BUSCA LA MAQUINA
    while(EditM->IDM!=MID){
        EditM = EditM->Next;
    }


  printf("\n");
  printf("         Resumen alquiler:\n");
  printf("\n");

  printf("M%cquina alquilada:%s (ID=%i)\n",160,EditM->Name,EditM->IDM);
    //BUSCAMOS LA FINCA NUEVA
        while(EditF->IDM!=AFID){
        EditF = EditF->Next;
    }
    //GUARDA LOS DATOS DE LA FINCA NUEVA
      ASize=EditF->Size;
      ALat=EditF->Lat;
      ALon=EditF->Lon;


  printf("Finca a cosechar:%s (ID=%i)\n",EditF->Name,EditF->IDM);
    //BUSCA FINCA VIEJA
    if(EditM->NFIDM!=0){
        while(EditF->IDM!=EditM->NFIDM){
        EditF = EditF->Next;
    }
    //GUARDA LOS DATOS DE LA FINCA VIEJA
      BSize=EditF->Size;
      BDay=EditM->NRday;
      BMonth=EditM->NRmonth;
      BYear=EditM->NRyear;
      BFID=EditM->NFIDM;
      printf("Traslado desde: finca%s (ID=%i)\n",EditF->Name,EditF->IDM);
    }
    else{
      printf("Traslado desde: finca NoAsignada (ID=N/A)\n");
      }

  printf("Distancia entre fincas: %iKM en linea recta\n",Distance(EditM->Lat,EditM->Lon,ALat,ALon));

  //CALCULO TIEMPOS
  CBTime=(BSize/EditM->Cap);
  CATime=(ASize/EditM->Cap);
  FTime=CBTime+TravelTime;

  //ESTO HAY QUE CAMBIARLO MIRANDO EL CALENDARIO

  if((ADay-TravelTime)==0){

        if(AMonth==1&&ADay==1){
      AYear2=AYear-1;
      AMonth2=12;
      ADay2=Pvector[AMonth2]-1;
      }
      else{
        AMonth2=AMonth-1;
        ADay2=Pvector[AMonth2]-1;
        }

  if(bisiesto(AYear2) && AMonth2==2){
  Pvector[2]=29;
  }
    ADay2=Pvector[AMonth2]-1;
    }
  else{
    AMonth2=AMonth;
    AYear2=AYear;
    ADay2=ADay;
    }

  printf("Tiempo de traslado:%i/%i/%i(%i dia)\n",ADay2,AMonth2,AYear2,TravelTime);
  printf("Fecha comienzo:%i/%i/%i\n",ADay,AMonth,AYear);
  printf("Duraci%cn cosecha: %i\n",162, CATime);

    if(Pvector[AMonth]<(CATime+ADay)){
      ADay2=abs((Pvector[AMonth]-ADay)-CATime);
      AMonth2=AMonth+1;
      if(AMonth2==13){
        AMonth2=1;
        AYear2=AYear+1;
        }
    }
    else{
      ADay2=(CATime+ADay);
      AMonth2=AMonth;
      AYear2=AYear;
      }

  printf("Fecha finalizaci%cn:%i/%i/%i\n",162,ADay2,AMonth2,AYear2);

printf("Es correcta la operaci%cn (S/N)?",162);
    while(sn!='N'&& sn!='S'){
  scanf(" %c",&sn);
  }
    if(sn=='N'){
      system("cls");
      RentMachine();
      }
    else{
      //INDRODUCIMOS LOS DATOS NUEVOS INCLUIDO LA NUEVA POSICION DE LA MAQUINA
      EditM->NRday=ADay;
      EditM->NRmonth=AMonth;
      EditM->NRyear=AYear;
      EditM->NFIDM=AFID;
      EditM->NRtime=CATime;
      EditM->Lat=ALat;
      EditM->Lon=ALon;
      //MOVEMOS LOS DATOS VIEJOS A VIEJOS EN LA MEMORIA
      EditM->Rday=BDay;
      EditM->Rmonth=BMonth;
      EditM->Ryear=BYear;
      EditM->FIDM=BFID;
      EditM->Rtime=CBTime;
      //ESTO BORRA SIEMPRE LOS DATOS VIEJOS ANTERIORES ES DECIR EN LA PROXIMA ITERACION LOS DATOS QUE HEMOS
      //INTRODUCIDO LA PRIMERA VEZ PASARAN A VIEJOS Y YA LA PROXIMA SE BORRAN
      }
sn='\0';
printf("\n");
printf("====================================================================================\n");
printf("\n");
printf("Volver al Menu Principal?(S/N)\n");
  while(sn!='N'&& sn!='S'){
  scanf(" %c",&sn);
  }
    if(sn=='N'){
      system("cls");
      RentMachine();
      }
    else if(sn=='S'){
      system("cls");
      M=1;
      }
sn='\0';


  }

//CALENDARIO
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

void calendario (int year, int mes, int idm,int NRtime,int Rtime,int Rday,int NRday,int RNmonth,int Rmonth){

  int diaInicioMes = diaInicio(year, mes);
  int contador;
  int colocar;


//ESTA PARTE DEL CODIGO DEBERIA DE TENER EN CUENTA LOS DIAS DE COSECHA QUE NO ESTAN EN EL MES QUE ESTAMOS MIRANDO
//TAL COMO ESTA AHORA EL PROGRAMA TIENE PROBLEMAS SI PONES A COSECHAR EN UN MES DISTINTO DEL QUE TERMINAN LAS MAQUINAS
/*if(mes>Rmonth){
  for(int i=Rmonth;i==mes;i++){
  Rtime=(Pvector[Rmonth]-Rday)-Rtime
  }
  Rday=1
  }
if(mes>NRmonth){
  for(int i=NRmonth;i==mes;i++){
  Rtime=(Pvector[NRmonth]-NRday)-NRtime
  }
  NRday=1
  }
*/


if(1601<=year && year<=3000){
  if(bisiesto(year) && mes==2){
  Pvector[2]=29;
  }
}
  else{
    printf("El año esta fuera del rango permitido (1601-3000)");
    return;
    }

  switch(mes){
    case 0:
      printf("Mes incorrecto\n");
      break;
    case 1:
      printf("          ENERO                  %i\n",year);
      break;
    case 2:
      printf("          FEBRERO                %i\n",year);
      break;
    case 3:
      printf("          MARZO                  %i\n",year);
      break;
    case 4:
      printf("          ABRIL                  %i\n",year);
      break;
    case 5:
      printf("          MAYO                   %i\n",year);
      break;
    case 6:
      printf("          JUNIO                  %i\n",year);
      break;
    case 7:
      printf("          JULIO                  %i\n",year);
      break;
    case 8:
      printf("          AGOSTO                 %i\n",year);
      break;
    case 9:
      printf("          SEPTIEMBRE             %i\n",year);
      break;
    case 10:
      printf("          OCTUBRE                %i\n",year);
      break;
    case 11:
      printf("          NOVIEMBRE              %i\n",year);
      break;
    case 12:
      printf("          DICIEMBRE              %i\n",year);
      break;
    }

printf("          ===========================\n");

printf("          LU  MA  MI  JU  VI | SA  DO\n");

printf("          ===========================\n");

    printf("          ");
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
        while(EditM->IDM!=idm){
        EditM = EditM->Next;
    }


//rellenamos dias mes
  for (int a = 1; a <= Pvector[mes]; a++) {
    colocar = ((diaInicioMes-1)+a) % 7;
  if(a==NRday && NRtime!=0){
    if(colocar==5){
      printf("C1 ");
      Cday=Cday+1;
      }
    else if(colocar==6){
    printf("|");
    printf(" C1  ");
    Cday=Cday+1;
    }
    else if(colocar==0){
      printf("C1  ", a);
      printf("\n");
      printf("          ");
      Cday=Cday+1;
            }
    else{
      printf("C1  ", a);
      Cday=Cday+1;
      }
    NRtime=NRtime-1;
    NRday=NRday+1;
  }

  else if(a==Rday && Rtime!=0){
    if(colocar==5){
      printf("C2 ");
      Cday=Cday+1;
      }
    else if(colocar==6){
    printf("|");
    printf(" C2  ");
    Cday=Cday+1;
    }
    else if(colocar==0){
      printf("C2  ", a);
      Cday=Cday+1;
      printf("\n");
      printf("          ");
            }
    else{
      printf("C2  ", a);
      Cday=Cday+1;
      }
    Rtime=Rtime-1;
    Rday=Rday+1;
  }
  else if(a==Rday-1){
        if(colocar==5){
      printf("TR ");
      }
    else if(colocar==6){
    printf("|");
    printf(" TR  ");
    }
    else if(colocar==0){
      printf("TR  ", a);
      printf("\n");
      printf("          ");
            }
    else{
      printf("TR  ", a);
      }

  }
   else if(a==NRday-1){
        if(colocar==5){
      printf("TR ");
      }
    else if(colocar==6){
    printf("|");
    printf(" TR  ");
    }
    else if(colocar==0){
      printf("TR  ", a);
      printf("\n");
      printf("          ");
            }
    else{
      printf("TR  ", a);
      }
  }

  else{
    if(colocar==5){
      printf("%2i ", a);
      Nday=Nday+1;
      }
    else if(colocar==6){
    printf("|");
    printf(" %2i  ", a);
    Nday=Nday+1;
    }
    else if(colocar==0){
      printf("%2i  ", a);
      printf("\n");
      printf("          ");
      Nday=Nday+1;
            }
    else{
      printf("%2i  ", a);
      Nday=Nday+1;
      }
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
        printf("          ");
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
        printf("          ");
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
        printf("          ");
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
        printf("          ");
        }
      else{
        printf(" .  ");
        }
  }
  }

  printf("\n");
}


int MainCalendario(){
  int year=0;
  int mes=0;
  int IDm=0;
  int TRday=0;
  int sn=0;

  printf("Plan mensual M%cquina:\n",160);
  printf("Identificador M%cquina?",160);
  scanf("%i",&IDm);

  printf("Selecci%cn Mes?",162);
  scanf("%i",&mes);
  if(mes<1 || mes>12){
    printf("Error: introduce un mes valido.(1-12)\n");
    return 0;
    }

  printf("Selecci%cn A%co?",162,164);
  scanf("%i",&year);
  if(!(1601 <= year && year <= 3000)){
    printf("Error: introduce un A%co valido.\n",164);
    return 0;
    }
        while(EditM->IDM!=IDm){
        EditM = EditM->Next;
    }
    printf("\n");
  printf("          Plan M%cquina: %s\n", 160,EditM->Name);
    printf("\n");



calendario(year,mes,IDm,EditM->NRtime,EditM->Rtime,EditM->Rday,EditM->NRday,EditM->Rmonth,EditM->NRmonth);




for(int i=0;i<2;i++){
  if(EditM->NFIDM!=0){
    TRday=TRday+1;
    }
  else if(EditM->FIDM!=0){
    TRday=TRday+1;
    }
  }

printf("Tiempo de traslados (Tr):%i d%cas\n",TRday,161);
printf("Tiempo de esperas:%i d%cas\n",Nday,161);
Nday=0;

    if(EditM->NFIDM!=0){
        while(EditF->IDM!=EditM->NFIDM){
        EditF = EditF->Next;
    }
    printf("Cosecha C1: finca %s\n",EditF->Name);
    }
    else{
      printf("Cosecha C1: finca No Asignada\n");
      }


    if(EditM->FIDM!=0){
        while(EditF->IDM!=EditM->NFIDM){
        EditF = EditF->Next;

    }
            printf("Cosecha C2: finca %s\n",EditF->Name);
    }
    else{
      printf("Cosecha C2: finca No Asignada\n");
      }
printf("Tiempo total de cosechas (C#): %i d%cas\n",Cday,161);
Cday=0;

sn='\0';
printf("Mostrar otro mes (S/N)?");
    while(sn!='N'&& sn!='S'){
  scanf(" %c",&sn);
  }
    if(sn=='N'){
      M=1;
      system("cls");
      }
    else{
      MainCalendario();
      system("cls");
      }

return 0;

  }










//MENU PRINCIPAL
void MainMenu(){
  char Letra;
  //menu principal
  printf("====================================================\n");
  printf("\n");
  printf("GesAMA: Gesti%cn de Alquiler de M%cquinas Agr%ccolas\n",162,160,161);
  printf("    Editar M%cquina              (Pulsar M)\n",160);
  printf("    Editar Finca                (Pulsar F)\n");
  printf("    Listar M%cquinas             (Pulsar L)\n",160);
  printf("    Estado Fincas               (Pulsar E)\n");
  printf("    Alquiler M%cquina            (Pulsar A)\n",160);
  printf("    Plan Mensual M%cquina        (Pulsar P)\n",160);
  printf("    Salir                       (Pulsar S)\n");
  printf("\n");
  printf("Teclear una opci%cn v%clida (M|F|L|E|A|P|S)?\n",162,160);
  printf("\n");
  printf("====================================================\n");
  //escanear letra
  scanf(" %c",&Letra);
  while(Letra==!'M'||Letra==!'F'||Letra==!'L'||Letra==!'E'||Letra==!'A'||Letra==!'P'||Letra==!'S'){
    printf("Opci%cn no valida (M|F|L|E|A|P|S)\n",162);
    scanf(" %c",&Letra);
    }
  switch(Letra){
    case 'M':
      //Editar M%cquina
      system("cls");
      EditMachine();
    break;
    case 'F':
      //Editar Finca
      system("cls");
      EditField();
    break;
    case 'L':
      //Listar M%cquinas
      system("cls");
      ListMachine();
    break;
    case 'E':
      //Estado Fincas
      system("cls");
      ListFields();
    break;
    case 'A':
      //Alquiler M%cquina
      system("cls");
      RentMachine();
    break;
    case 'P':
      //Plan Mensual M%cquina
      system("cls");
      MainCalendario();
    break;
    case 'S':
      //Salir
      system("cls");
    break;
    }
  }

int main(){
  //NODOS MAQUINAS
  EditM = new tNodeMachine;
  StartM = EditM;
  EditM->IDM=1;
  EditM->NFIDM=0;
  EditM->Next=NULL;

  for(int i=2;i<(Machines+1);i++){

  auxM= new tNodeMachine;
  auxM->IDM=i;
  EditM->NFIDM=0;
  auxM->Next=EditM;
  EditM=auxM;
  }
  StartM->Next=auxM;

  //NODOS FINCAS
  EditF = new tNodeField;
  StartF = EditF;
  EditF->IDM=1;
  EditF->Next=NULL;

  for(int i=2;i<(Fields+1);i++){

  auxF= new tNodeField;
  auxF->IDM=i;
  auxF->Next=EditF;
  EditF=auxF;
  }
  StartF->Next=auxF;
//INVOCAMOS EL MENU PRINCIPAL "M" LO USO PARA VOLVER A EL CUANDO TERMINO CON UNO DE LOS SUBMENUS DE HAY EL BUCLE
  MainMenu();

  while(M==1){
    M=0;
    MainMenu();
    }
}
