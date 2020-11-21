#include <time.h>
#include "stdio.h"
#include "stdlib.h"
#include "Drinks.h"

tstOptions stBartender[MaxMenu][MaxOptions] = MENU_INNIT;

void Menu()
{
	uint8 u8Menu=0;
	uint8 u8x=FACTOR;
	printf("Welcome to the Ultimate Drinks Machine.\nSelect the ingredients that you want to add to the beverage.\n");
	while(u8x==FACTOR)
	{
		printf("1)Licors\n2)Sodas\n3)Juices\n");
		scanf("%d", &u8Menu);
		while(u8Menu<LIMIT1 || u8Menu>LIMIT2)
		{
			fflush(stdin);
			printf("Please select a correct option:\n1)Licors\n2)Sodas\n3)Juices\n");
			scanf("%d", &u8Menu);
		}
		if(u8Menu==OPTION1)
		{
			Licors();
			u8x=Extra();
		}
		else if(u8Menu==OPTION2)
		{
			Sodas();
			u8x=Extra();
		}
		else
		{
			Juices();
			u8x=Extra();
		}
	}
	Start();
}

void Start()
{
	uint8 u8i;
	uint8 u8j;
	uint32 u32Movement=DELAY*MOVEMENT;
	uint32 u32Serving=DELAY*SERVING;

	for(u8i=0;u8i<LIMIT2;u8i++)
	{
		for(u8j=0;u8j<OPTION5;u8j++)
		{
			u32Movement=DELAY*MOVEMENT;
			u32Serving=DELAY*SERVING;
			printf("Moving\n");
			while(u32Movement--);
			if(stBartender[u8i][u8j]==FACTOR)
			{
				printf("Serving \n");
				while(u32Serving--);
			}
		}
	}
	u32Movement=DELAY*MOVEMENT;
	printf("Moving\n");
	while(u32Movement--);
	printf("Enjoy your beverage.\n");
}

void Licors()
{
	uint8 u8Licor;
	printf("Select a Licor of your choice\n1)Tequila\n2)Rum\n3)Whisky\n4)Gin\n5)Vodka\n");
	scanf("%d", &u8Licor);
	while(u8Licor<OPTION1 || u8Licor>OPTION5)
	{
		fflush(stdin);
		printf("Please select a correct option:\n1)Tequila\n2)Rum\n3)Whisky\n4)Gin\n5)Vodka\n");
		scanf("%d", &u8Licor);
	}
	u8Licor -= FACTOR;
	stBartender[enLicors][u8Licor]=FACTOR;
}

void Sodas()
{
	uint8 u8Soda;
	printf("Select a Soda of your choice\n1)Coke\n2)Sprite\n3)Mineral Water\n4)Ginger Ale\n5)Dr Pepper\n");
	scanf("%d", &u8Soda);
	while(u8Soda<OPTION1 || u8Soda>OPTION5)
	{
		fflush(stdin);
		printf("Please select a correct option:\n1)Coke\n2)Sprite\n3)Mineral Water\n4)Ginger Ale\n5)Dr Pepper\n");
		scanf("%d", &u8Soda);
	}
	u8Soda -= FACTOR;
	stBartender[enSodas][u8Soda]=FACTOR;
}

void Juices()
{
	uint8 u8Juice;
	printf("Select a Licor of your choice\n1)Peach\n2)Cranberry\n3)Lemon\n4)Orange\n5)Strawberry\n");
	scanf("%d", &u8Juice);
	while(u8Juice<OPTION1 || u8Juice>OPTION5)
	{
		fflush(stdin);
		printf("Please select a correct option:\n1)Peach\n2)Cranberry\n3)Lemon\n4)Orange\n5)Strawberry\n");
		scanf("%d", &u8Juice);
	}
	u8Juice -= FACTOR;
	stBartender[enJuices][u8Juice]=FACTOR;
}

uint8 Extra()
{
	uint8 u8Confirm;
	printf("Do you want to add another ingredient to your beverage?\n1)Yes\n2)No\n");
	scanf("%d",&u8Confirm);
	while(u8Confirm<OPTION1 || u8Confirm>OPTION2)
	{
		fflush(stdin);
		printf("Please select a correct option:\n1)Yes\n2)No\n");
		scanf("%d", &u8Confirm);
	}
	return u8Confirm;
}