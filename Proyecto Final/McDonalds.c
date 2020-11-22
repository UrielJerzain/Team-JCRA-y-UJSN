#include <stdio.h>
#include "stdlib.h"
#include "McDonalds.h"
#include <time.h>
#include <math.h>

uint8 u8Ingredients[]={MAX_LETTUCE,MAX_TOMATO,MAX_MEAT,MAX_BREAD,MAX_CHEESE};

void main (void)
{
	uint8 u8Options;
	printf("Welcome to McDonalds.\nWhere do you prefer to order?\n1) Inside the restaurant.\n2) Drive thru.\n");
	scanf("%d", &u8Options);
	while(u8Options<RESTAURANT || u8Options>DRIVE_THRU)
	{
		fflush(stdin);
		printf("Please select a correct option:\n1) Inside the restaurant.\n2) Drive thru.\n"); 
		scanf("%d", &u8Options);
	}
	if(u8Options==RESTAURANT)
	{
		Restaurant();
	}
	else if(u8Options==DRIVE_THRU)
	{
		Drive_Thru();
	}
	else
	{
		/*Nothing to do*/
	}
}

void Restaurant()
{
	Menu();
}

void Drive_Thru()
{
	Menu();
}

void delay(uint8 number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    uint8 milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

uint8 printRandoms(uint8 lower, uint8 upper,  uint8 count) 
{ 
    uint8 i; 
    uint8 num;
    num = (rand() % (upper - lower + FACTOR)) + lower; 
    //printf("%d \n", num); 
    return num;
} 
void Menu()
{
	uint8 u8Order;
	uint8 u8x=FACTOR;
	while(u8x==FACTOR)
	{
		printf("What would you like to order?\n1)Burgers\n2)Drinks\n3)Desserts\n4)Fries\n");
		scanf("%d",&u8Order); 
		while(u8Order<LIMIT1 || u8Order>LIMIT2) 
		{ 
			fflush(stdin); 
			printf("Please select a correct option:\n1)Burgers\n2)Drinks\n3)Desserts\n4)Fries\n"); 
			scanf("%d", &u8Order); 
		} 
    	switch(u8Order)
    	{
    		case OPTION1: Burgers();
    		u8x=Extra();
    		break;
    		case OPTION2: /**/Drinks();
    		u8x=Extra();
    		break;
    		case OPTION3: Desserts();
    		u8x=Extra();
    		break;
    		case OPTION4: Fries();
    		u8x=Extra();
    		break;
    	}
	}	
}

void Burgers()
{
	uint8 u8Burger;
	printf("Select a burger\n1)Big Mac\n2)Cheeseburger\n3)Quarter Pounder\n4)Deluxe\n");
	scanf("%d",&u8Burger); 
	while(u8Burger<LIMIT1 || u8Burger>LIMIT2) 
	{ 
		fflush(stdin); 
		printf("Please select a correct option:\n1)Big Mac\n2)Cheeseburger\n3)Quarter Pounder\n4)Deluxe\n"); 
		scanf("%d", &u8Burger); 
	} 
	AmountBurgers(u8Burger);
}


void Drinks()
{	
	uint8 u8Drinks;
	printf("Select a drink:\n1)Sprite\n2)Coke\n3)Fanta\n4)Squirt\n");
	scanf("%d",&u8Drinks);
	while(u8Drinks<LIMIT1 || u8Drinks>LIMIT2) 
	{ 
		fflush(stdin); 
		printf("Please select a correct option:\n1)Sprite\n2)Coke\n3)Fanta\n4)Squirt\n"); 
		scanf("%d", &u8Drinks); 
	} 
	AmountDrinks();
}

void Desserts()
{
	uint8 u8Dessert;
	printf("Select a dessert:\n1)Cheesecake\n2)Lemon Pie\n3)Ice Cream\n4)Nutella Cake\n");
	scanf("%d",&u8Dessert);
	while(u8Dessert<LIMIT1 || u8Dessert>LIMIT2) 
	{ 
		fflush(stdin); 
		printf("Please select a correct option:\n1)Cheesecake\n2)Lemon Pie\n3)Ice Cream\n4)Nutella Cake\n"); 
		scanf("%d", &u8Dessert); 
	} 
	AmountDesserts();
}

void Fries()
{
	uint8 u8Size;
	printf("What Size do you prefer?\n1)Small\n2)Medium\n3)Large\n4)Extra-Large\n");
	scanf("%d",&u8Size);
	while(u8Size<LIMIT1 || u8Size>LIMIT2) 
	{ 
		fflush(stdin); 
		printf("Please select a correct option:\n1)Small\n2)Medium\n3)Large\n4)Extra-Large\n"); 
		scanf("%d", &u8Size); 
	} 
	AmountFries();	
}

uint8 Extra()
{
	uint8 u8Confirm; 
	printf("Do you want to order anything else?\n1)Yes\n2)No\n"); 
	scanf("%d",&u8Confirm); 
	while(u8Confirm<OPTION1 || u8Confirm>OPTION2) 
	{ 
		fflush(stdin); 
		printf("Please select a correct option:\n1)Yes\n2)No\n"); 
		scanf("%d", &u8Confirm); 
	} 
	return u8Confirm; 
}

void AmountBurgers(uint8 u8Type)
{
	uint8 u8Amount;
	uint8 u8AmountLettuce;
	uint8 u8AmountBread;
	uint8 u8AmountMeat;
	uint8 u8AmountTomato;
	uint8 u8AmountCheese;
	printf("How many Burgers do you want?\n");
	scanf("%d", &u8Amount);
	while(u8Amount<0)
	{
		fflush(stdin);
		printf("Type in a correct number\n");
		scanf("%d", &u8Amount);
	}
	if(u8Type==OPTION1)
	{
		u8AmountLettuce= u8Amount*INGREDIENT1;
		u8AmountMeat= u8Amount*INGREDIENT2;
		u8AmountCheese= u8Amount*INGREDIENT2;
		u8AmountBread= u8Amount*INGREDIENT1;
		u8AmountTomato= u8Amount*INGREDIENT1;
		if(u8AmountLettuce > u8Ingredients[LETTUCE] || u8AmountTomato > u8Ingredients[TOMATO] || u8AmountMeat > u8Ingredients[MEAT] || u8AmountBread > u8Ingredients[BREAD] || u8AmountCheese > u8Ingredients[CHEESE])
		{
			printf("Sorry we don't have enough ingredients\n");
		}
		else
		{
			printf("Please wait until your burgers are ready\n");
			u8Ingredients[LETTUCE] -= u8AmountLettuce;
			u8Ingredients[TOMATO] -= u8AmountTomato;
			u8Ingredients[MEAT] -= u8AmountMeat;
			u8Ingredients[BREAD] -= u8AmountBread;
			u8Ingredients[CHEESE] -= u8AmountCheese;
		}
	}
	else if(u8Type==OPTION2)
	{
		u8AmountLettuce= u8Amount*INGREDIENT1;
		u8AmountMeat= u8Amount*INGREDIENT1;
		u8AmountCheese= u8Amount*INGREDIENT3;
		u8AmountBread= u8Amount*INGREDIENT1;
		u8AmountTomato= u8Amount*INGREDIENT1;
		if(u8AmountLettuce > u8Ingredients[LETTUCE] || u8AmountTomato > u8Ingredients[TOMATO] || u8AmountMeat > u8Ingredients[MEAT] || u8AmountBread > u8Ingredients[BREAD] || u8AmountCheese > u8Ingredients[CHEESE])
		{
			printf("Sorry we don't have enough ingredients\n");
		}
		else
		{
			printf("Please wait until your burgers are ready\n");
			u8Ingredients[LETTUCE] -= u8AmountLettuce;
			u8Ingredients[TOMATO] -= u8AmountTomato;
			u8Ingredients[MEAT] -= u8AmountMeat;
			u8Ingredients[BREAD] -= u8AmountBread;
			u8Ingredients[CHEESE] -= u8AmountCheese;
		}
	}
	else if(u8Type==OPTION3)
	{
		u8AmountLettuce= u8Amount*INGREDIENT2;
		u8AmountMeat= u8Amount*INGREDIENT3;
		u8AmountCheese= u8Amount*INGREDIENT2;
		u8AmountBread= u8Amount*INGREDIENT1;
		u8AmountTomato= u8Amount*INGREDIENT2;
		if(u8AmountLettuce > u8Ingredients[LETTUCE] || u8AmountTomato > u8Ingredients[TOMATO] || u8AmountMeat > u8Ingredients[MEAT] || u8AmountBread > u8Ingredients[BREAD] || u8AmountCheese > u8Ingredients[CHEESE])
		{
			printf("Sorry we don't have enough ingredients\n");
		}
		else
		{
			printf("Please wait until your burgers are ready\n");
			u8Ingredients[LETTUCE] -= u8AmountLettuce;
			u8Ingredients[TOMATO] -= u8AmountTomato;
			u8Ingredients[MEAT] -= u8AmountMeat;
			u8Ingredients[BREAD] -= u8AmountBread;
			u8Ingredients[CHEESE] -= u8AmountCheese;
		}
	}
	else 
	{
		u8AmountLettuce= u8Amount*INGREDIENT3;
		u8AmountMeat= u8Amount*INGREDIENT3;
		u8AmountCheese= u8Amount*INGREDIENT3;
		u8AmountBread= u8Amount*INGREDIENT1;
		u8AmountTomato= u8Amount*INGREDIENT3;
		if(u8AmountLettuce > u8Ingredients[LETTUCE] || u8AmountTomato > u8Ingredients[TOMATO] || u8AmountMeat > u8Ingredients[MEAT] || u8AmountBread > u8Ingredients[BREAD] || u8AmountCheese > u8Ingredients[CHEESE])
		{
			printf("Sorry we don't have enough ingredients\n");
		}
		else
		{
			printf("Please wait until your burgers are ready\n");
			u8Ingredients[LETTUCE] -= u8AmountLettuce;
			u8Ingredients[TOMATO] -= u8AmountTomato;
			u8Ingredients[MEAT] -= u8AmountMeat;
			u8Ingredients[BREAD] -= u8AmountBread;
			u8Ingredients[CHEESE] -= u8AmountCheese;
		}
	}
}

void AmountDrinks()
{	
	uint8 u8AmountDrinks;
	printf("How many Drinks do you want?\n");
	scanf("%d", &u8AmountDrinks);
	while(u8AmountDrinks<0)
	{
		fflush(stdin);
		printf("Type in a correct number\n");
		scanf("%d", &u8AmountDrinks);
	}
}

void AmountDesserts()
{
	uint8 u8AmountDesserts;
	printf("How many Drinks do you want?\n");
	scanf("%d", &u8AmountDesserts);
	while(u8AmountDesserts<0)
	{
		fflush(stdin);
		printf("Type in a correct number\n");
		scanf("%d", &u8AmountDesserts);
	}
}

void AmountFries()
{
	uint8 u8AmountFries;
	printf("How many Friess do you want?\n");
	scanf("%d", &u8AmountFries);
	while(u8AmountFries<0)
	{
		fflush(stdin);
		printf("Type in a correct number\n");
		scanf("%d", &u8AmountFries);
	}
}