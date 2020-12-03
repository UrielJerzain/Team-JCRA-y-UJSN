#include "Start1.h"

void Start(uint16 u16Tiempo1, uint16 u16Tiempo2, uint16 u16Tiempo3)
{
 	uint16 u16TiempoBomba1 = u16Tiempo1;
	uint16 u16TiempoBomba2 = u16Tiempo2;
	uint16 u16TiempoBomba3 = u16Tiempo3;

	while(u16TiempoBomba1!=0 || u16TiempoBomba2!=0 || u16TiempoBomba3!=0)
	{
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
		delay(FACTOR);
	}
	printf("Bombas finalizadas\n\n\n\n");
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