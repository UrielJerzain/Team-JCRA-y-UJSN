#include "Config.h"

void Configuracion()
{
	static uint8 u8Candado=FACTOR;
 	static uint8 u8Modificar=0;
 	static uint8 u8Bombas=0;
 	static uint16 u16Tiempo1=0;
 	static uint16 u16Tiempo2=0;
 	static uint16 u16Tiempo3=0;

 	if(u8Candado==FACTOR)
 	{
 		u8Candado=0;
 		u16Tiempo1=Bomba(OPTION1);
  		u16Tiempo2=Bomba(OPTION2);
  		u16Tiempo3=Bomba(OPTION3);

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
	    		u16Tiempo1=Bomba(OPTION1);
	    		u8Modificar=Modificar();
	    	}
	    	else if(u8Bombas==OPTION2)
	    	{
	    		u16Tiempo2=Bomba(OPTION2);
	    		u8Modificar=Modificar();
	    	}
	    	else
	    	{
	    		u16Tiempo3=Bomba(OPTION3);
	    		u8Modificar=Modificar();
	    	}
		}
 	}
	u8Candado=Start(u16Tiempo1, u16Tiempo2, u16Tiempo3);
}

uint16 Bomba(uint8 u8Number)
{
 	uint16 u16Bomba=RESTRICCION;
 	printf("Favor de seleccionar el tiempo de la bomba %d (Max 300 seg)\n", u8Number);
 	scanf("%d",&u16Bomba);
 	while(u16Bomba<0||u16Bomba>TIME_LIMIT)
 	{
 		fflush(stdin);
 		printf("Selecciona un tiempo permitido de 0 a 300 seg\n");
 		scanf("%d",&u16Bomba);
 	}
 	return u16Bomba;
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

uint8 Start(uint16 u16Tiempo1, uint16 u16Tiempo2, uint16 u16Tiempo3)
{

	static uint16 u16TiempoBomba1 = 0;
	static uint16 u16TiempoBomba2 = 0;
	static uint16 u16TiempoBomba3 = 0;
	static uint8 u8Candado=FACTOR;

	if(u8Candado==FACTOR)
	{
		u8Candado=0;
		u16TiempoBomba1 = u16Tiempo1;
		u16TiempoBomba2 = u16Tiempo2;
		u16TiempoBomba3 = u16Tiempo3;
	}
 	else
	{
		/*Nothing to do*/
	}

	if( u16TiempoBomba1 != 0 )
	{
		printf("Bomba 1 activa\nTiempo restante %d segundos\n", u16TiempoBomba1);
		u16TiempoBomba1--;	
	}
	else
	{
		/*Nothing to do*/
	}
	
	if( u16TiempoBomba2 != 0 )
	{
		printf("Bomba 2 activa\nTiempo restante %d segundos\n", u16TiempoBomba2);
		u16TiempoBomba2--;	
	}
	else
	{
		/*Nothing to do*/
	}
	
	if( u16TiempoBomba3 != 0 )
	{
		printf("Bomba 3 activa\nTiempo restante %d segundos\n", u16TiempoBomba3);
		u16TiempoBomba3--;			
	}
	else
	{
		/*Nothing to do*/
	}

	if(u16TiempoBomba1 == 0 && u16TiempoBomba2 == 0 && u16TiempoBomba3 == 0)
	{
		delay(FACTOR);
		printf("Bombas finalizadas\n\n\n\n");
		u8Candado=FACTOR;
	}
	else
	{
		/*Nothing to do*/
	}
	return u8Candado;
}

void delay(uint32 number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    uint32 milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 