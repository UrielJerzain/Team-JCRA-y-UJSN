#include "stdio.h"
#include "stdlib.h"
#include "Statemachine.h"
tststates stCocktail[enMaxCocktail] = STATES_INNIT;

void main ( void ) 
{
	uint16 u16Delay = 0;
	uint8 u8Drink;
	uint8 u8Alcohol;
	printf("Seleccione el licor que desee:\n1) Tequila \n2)Whisky \n3)Vodka");
	scanf("%d",&u8Alcohol);
	printf("Seleccione la bebida que desee:\n1) Sunrise \n2)Margarita \n3)Manhattan \n4)Mojito");
	scanf("%d",&u8Drink);
	if ( u8Alcohol < MaxLicor )
	{
		switch (u8Alcohol)
		{
			case 1 : Tequila ( u8Alcohol, u8Drink);
			break;
			//case 2 : Whisky ();
			//break;
			//case 3 : Vodka ();
			//break;
		}
	}
	
}

void Tequila ( uint8 u8Alcohol, uint8 u8Drink) 
{	
	uint16 u16Delay;
	uint16 u16Llenar;
	uint8 x = 1;
	switch (u8Drink)
	{
		case 1 : 
		{
			while (1)
			{
				printf("Iniciando\n");
				if ( stCocktail[Sunrise].u8Tequila == 0 )
				{
					printf("----> Tequila\n");
					u16Delay = Tiempo_Mover;
					while(u16Delay--);
					if(u16Delay == 0)
					{
						printf("LLena (tequila)");
						u16Llenar = Tiempo_Llenar;
						while(u16Llenar--);
						stCocktail[Sunrise].u8Tequila = Sunrise;
					}

				//		stCocktail.u8Tequila = enTequila;
				}
				//else if ( stCocktail.u8Tequila == enTequila )
				//{
				//	printf("LLena (tequila)");
				//	u8Llenar = Tiempo_Llenar
				//	while(u8Llenar--);
				//	stCocktails.u8Tequila = Sunrise;
				//}

				else if (stCocktail[Sunrise].u8Tequila == Sunrise)
				{
					printf("----> bebida");
					u16Delay = Tiempo_Mover;
					while(u16Delay--);
					if(u16Delay == 0)
					{
						printf("Llena (bebida)");
						u16Llenar = Tiempo_Llenar;
						while(u16Llenar--);
						stCocktail[Sunrise].u8Tequila = 0;
					}
				//	stCocktails.u8Tequila = Sunrise;
				}
				//else if (stCocktails.u8Tequila == Sunrise)
				//{
				//	printf("Llena (bebida)");
				//	u8Llenar = Tiempo_Llenar
				//	while(u8Llenar--);
				//	stCocktails.u8Tequila = 0;
				//}
				else if (stCocktail[Sunrise].u8Tequila == 0)
				{
					printf("Bebida Lista");
				}

			}
		}
		break;
		
	}
	
	
}
