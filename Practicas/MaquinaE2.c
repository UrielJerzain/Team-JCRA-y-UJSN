#include <stdio.h>
#include <stdlib.h>
#include "MaquinaE.h"
#include <string.h>
tststates stCocktail[enMaxCocktail] = STATES_INNIT;
void Function()
{
	uint8 u8Drink;
	uint8 u8Alcohol;
	uint8 u8Extra;
	uint8 u8Ingrediente;
	uint8 u8x = False;
	printf("Seleccione el licor que desee:\n1)Tequila \n2)Whisky \n3)Vodka\n");
	scanf("%d",&u8Alcohol);
	while (u8Alcohol < SIZE  || u8Alcohol>Size2)
	{
		fflush(stdin);
		printf("\nEscriba de 1 a 3\n");
		scanf("%d",&u8Alcohol);
	}
	printf("Seleccione la bebida que desee:\n1)Sunrise \n2)Margarita \n3)Manhattan \n4)Mojito\n");
	scanf("%d",&u8Drink);
	while (u8Drink < SIZE  || u8Drink>MaxLicor)
	{
		fflush(stdin);
		printf("Escriba de 1 a 4\n");
		scanf("%d",&u8Drink);
	}
	if ( u8Alcohol < MaxLicor )
	{
		Drinks (u8Alcohol , u8Drink);
			while(u8x == False)
			{
				printf("\nDesea añadir un ingrediente extra?\n1)Si\n2)No\n");
				scanf("%d",&u8Extra);
				while (u8Extra < Extra_Limite1 || u8Extra > Extra_Limite)
				{
					fflush(stdin);
					printf("Escriba las opciones correctas\n");
					scanf("%d",&u8Extra);
				}
				if(u8Extra == True)
				{
					printf("Cual ingrediente desea?\n1)Hielo\n2)Clamato\n3)Tajin\n");
					scanf("%d",&u8Ingrediente);
					while (u8Ingrediente < SIZE || u8Ingrediente > Size2)
					{
						fflush(stdin);
						printf("Escriba las opciones correctas\n");
						scanf("%d",&u8Ingrediente);
					}
					Extra (u8Ingrediente);
				}
				else
				{
					u8x=True;
				}	
			}
	printf("Bebida lista");
	}
	else 
	{
		/*nothing to do*/
	}	
}

void Drinks (uint8 u8Alcohol , uint8 u8Drink) 
{	
	uint32 u32Delay;
	uint32 u32Llenar;
	uint8 x=True;
	uint8 u8VarAlcohol=False;
	char Drink1[]="Sunrise";
	char Drink2[]="Margarita";
	char Drink3[]="Manhattan";
	char Drink4[]="Mojito";
	char Fill[]="Llenando ";
	printf("Iniciando..\n");
		if ( u8Alcohol == Teq)
		{
			printf(strcat( Move , Type1));
			u8VarAlcohol = stCocktail[Sunrise].u8Tequila;
			u8VarAlcohol = stCocktail[Margarita].u8Tequila;
			u8VarAlcohol = stCocktail[Manhattan].u8Tequila;
			u8VarAlcohol = stCocktail[Mojito].u8Tequila;
		}
		else if( u8Alcohol == Whysk )
		{
			printf(strcat(Move , Type2));
			u8VarAlcohol = stCocktail[Sunrise].u8Whisky;
			u8VarAlcohol = stCocktail[Margarita].u8Whisky;
			u8VarAlcohol = stCocktail[Manhattan].u8Whisky;
			u8VarAlcohol = stCocktail[Mojito].u8Whisky;
		}
		else if (u8Alcohol == Vodk )
		{
			printf(strcat(Move , Type3));
			u8VarAlcohol = stCocktail[Sunrise].u8Vodka;
			u8VarAlcohol = stCocktail[Margarita].u8Vodka;
			u8VarAlcohol = stCocktail[Manhattan].u8Vodka;
			u8VarAlcohol = stCocktail[Mojito].u8Vodka;	
		}
		else 
		{
			/*Nothing to do*/
		} 
		while (x==True)
		{
				
			if ( u8VarAlcohol == False )
			{
				u32Delay = Tiempo_Mover;
				while(u32Delay--);
				u8VarAlcohol = EnableFillTequila;
			}
			else if ( u8VarAlcohol == EnableFillTequila )
			{
				printf("\nLlenando Licor");
				u32Llenar = Tiempo_Llenar;
				while(u32Llenar--);
				u8VarAlcohol = FillDrink;
			}
			else if (u8VarAlcohol == FillDrink)
			{
				printf("\n----> Bebida");
				u32Delay = Tiempo_Mover;
				while(u32Delay--);
				u8VarAlcohol = EnableFillDrink;
			}
			else if (u8VarAlcohol == EnableFillDrink)
			{	
				printf("\n");
				if( u8Drink	== Sunrise)
				{
					printf(strcat(Fill , Drink1));
				}
				else if (u8Drink == Margarita)
				{
					printf(strcat(Fill, Drink2));
				}
				else if (u8Drink == Manhattan)
				{
					printf(strcat(Fill , Drink3));
				}
				else if (u8Drink == Mojito)
				{
					printf(strcat(Fill , Drink4));
				}
				else 
				{
					/**/
				}
				u32Llenar = Tiempo_Llenar;
				while(u32Llenar--);
				u8VarAlcohol = ReturnBase;
				}

			else if (u8VarAlcohol == ReturnBase)
			{
				printf("\nMezclando bebida");
				u32Delay = Tiempo_Mover;
				while(u32Llenar--);
				printf("\n*Bebida Mezclada*");
				u8VarAlcohol = Nothing; 
			}
			else 
			{
				x=False;
			}
		}	
}
void Extra(uint8 u8Ingrediente)
{
	uint32 u32Delay;
	uint32 u32Llenar;
	uint8 y=True;

		if(u8Ingrediente==Hielo)
	    {
			printf("Añadiendo Hielo...\n");
			u32Llenar = Tiempo_Llenar;
			while (u32Llenar--);
			printf("*Hielo Añadido*");
		}
		else if(u8Ingrediente==Clamato)
		{
			printf("Añadiendo Clamato...\n");
			u32Llenar = Tiempo_Llenar;
			while (u32Llenar--);
			printf("*Clamato añadido*");
		}
		else if(u8Ingrediente==Tajin)
		{
			printf("Añadiendo Tajin...\n");
			u32Llenar = Tiempo_Llenar;
			while (u32Llenar--);
			printf("*Tajin Añadido*");
		}
		else
		{
			/*Nothing to do*/
		}	
}
