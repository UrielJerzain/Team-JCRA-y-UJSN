#include "Config.h"

void Configuracion()
{
 	uint8 u8Modificar=0;
 	uint8 u8Bombas=0;
 	uint16 u16Tiempo1=0;
 	uint16 u16Tiempo2=0;
 	uint16 u16Tiempo3=0;

  	u16Tiempo1=Bomba1();
  	u16Tiempo2=Bomba2();
  	u16Tiempo3=Bomba3();

 	u8Modificar=Modificar();
	while(u8Modificar==OPTION1)
	{
		printf("Cual bomba deseas modificar?\n1)Bomba1\n2)Bomba2\n3)Bomba3\n");
		scanf("%d",&u8Bombas);
	    while(u8Bombas<OPTION1 || u8Bombas>OPTION3)
	    {
	    	fflush(stdin);
	    	printf("Seleccione una opcion valida\n1)Bomba1\n2)Bomba2\n3)Bomba3\n");
	    	scanf("%d",&u8Bombas);
	    }
	    if(u8Bombas==OPTION1)
	    {
	    	u16Tiempo1=Bomba1();
	    	u8Modificar=Modificar();
	    }
	    else if(u8Bombas==OPTION2)
	    {
	    	u16Tiempo2=Bomba2();
	    	u8Modificar=Modificar();
	    }
	    else
	    {
	    	u16Tiempo3=Bomba3();
	    	u8Modificar=Modificar();
	    }
	}
	Start(u16Tiempo1, u16Tiempo2, u16Tiempo3);
}

uint16 Bomba1()
{
 	uint16 u16Bomba1=RESTRICCION;
 	printf("Favor de seleccionar el tiempo de la bomba 1 (Max 300 seg)\n");
 	scanf("%d",&u16Bomba1);
 	while(u16Bomba1<0||u16Bomba1>TIME_LIMIT)
 	{
 		fflush(stdin);
 		printf("Selecciona un tiempo permitido de 0 a 300 seg\n");
 		scanf("%d",&u16Bomba1);
 	}
 	return u16Bomba1;
}

uint16 Bomba2()
{
 	uint16 u16Bomba2=RESTRICCION;
 	printf("Favor de seleccionar el tiempo de la bomba 2 (Max 300 seg)\n");
 	scanf("%d",&u16Bomba2);
 	while(u16Bomba2<0||u16Bomba2>TIME_LIMIT)
 	{
 		fflush(stdin);
 		printf("Selecciona un tiempo permitido de 0 a 300 seg\n");
 		scanf("%d",&u16Bomba2);
 	}
 	return u16Bomba2;
}

uint16 Bomba3()
{
 	uint16 u16Bomba3=RESTRICCION;
 	printf("Favor de seleccionar el tiempo de la bomba 3 (Max 300 seg)\n");
 	scanf("%d",&u16Bomba3);
 	while(u16Bomba3<0||u16Bomba3>TIME_LIMIT)
 	{
 		fflush(stdin);
 		printf("Selecciona un tiempo permitido de 0 a 300 seg\n");
 		scanf("%d",&u16Bomba3);
 	}
 	return u16Bomba3;
}

uint8 Modificar()
{
 	uint8 u8Modificar=0;
 	printf("Desea modificar algun tiempo?\n1)Si\n2)No\n");
	scanf("%d",&u8Modificar);
	while(u8Modificar<OPTION1 || u8Modificar>OPTION2)
	{
		fflush(stdin);
		printf("Seleccione una opcion valida\n1)Si\n2)No\n");
		scanf("%d",&u8Modificar);
	}
	return u8Modificar;
}