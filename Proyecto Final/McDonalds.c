#include <stdio.h>
#include "stdlib.h"
#include "McDonalds.h"
#include <time.h>
#include <math.h>
tstMaxInfo MaxInfo[enMaxCount] = INNIT_Count;

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
	Interfaz();

}

void Drive_Thru()
{
	Menu();
	Interfaz();
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
	AmountDesserts(u8Dessert);
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
	AmountFries(u8Size);	
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
			MaxInfo	[enMaxBurgers].u32EarnMoney += Big_Mac;
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
			MaxInfo[enMaxBurgers].u32EarnMoney += Quarter_Pounder;
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
			MaxInfo[enMaxBurgers].u32EarnMoney += Deluxe;
		}
	}
	MaxOrderBurger(u8Amount,u8Type);
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
	MaxOrderDrinks(u8AmountDrinks);
}

void AmountDesserts(uint8 u8Dessert)
{
	uint8 u8AmountDesserts;
	printf("How many Desserts do you want?\n");
	scanf("%d", &u8AmountDesserts);
	while(u8AmountDesserts<0)
	{
		fflush(stdin);
		printf("Type in a correct number\n");
		scanf("%d", &u8AmountDesserts);
	}
	MaxOrderDesserts(u8AmountDesserts , u8Dessert);
}

void AmountFries(uint8 u8Size)
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
	MaxOrderFries (u8AmountFries, u8Size);
}

/*Idea- Poner una interfaz al principio para poner que si quisiera saber el monto y la cantidad de cada pedido (hamburguesa, bebida, postre, papas) y ponerlas con un switch y al escoger una, imprimimos el resultado con la estructura y en la funcion quitamos los print*/
void MaxOrderBurger(uint8 u8Amount, uint8 u8Type)
{
	uint8 u8Confirm = 0;
	uint32 u32BMoney = 0;
	printf("Do you want to see the burgers count?\n1)Yes\n2)No\n");
	scanf("%d",&u8Confirm);
	MaxInfo[enMaxBurgers].u8MaxOrder += u8Amount;
	if(u8Type == 1)
	{
		u32BMoney = Big_Mac;
	}
	else if (u8Type	== 2)
	{
		u32BMoney = Cheeseburger;
	}
	else if (u8Type	== 3)
	{
		u32BMoney = Quarter_Pounder;
	}
	else if (u8Type	== 4)
	{
		u32BMoney = Deluxe;
	}
	u32BMoney *= u8Amount;
	MaxInfo[enMaxBurgers].u32EarnMoney += u32BMoney;
	if (u8Confirm == 1)
	{
		printf("Until now we have %d Burgers counted\n",MaxInfo[enMaxBurgers].u8MaxOrder);
		printf("Earn Money by Burgers %d \n",MaxInfo[enMaxBurgers].u32EarnMoney);
	}
	else
	{
		/*Nothing to do*/
	}	
}

void MaxOrderDrinks (uint8 u8AmountDrinks)
{
	uint8 u8Confirm = 0;
	uint32 u32DMoney = 0;
	printf("Do you want to see the drinks count?\n1)Yes\n2)No\n");
	scanf("%d",&u8Confirm);
	MaxInfo[enMaxDrinks].u8MaxOrder += u8AmountDrinks;
	u32DMoney = Drink;
	u32DMoney *= u8AmountDrinks;
	MaxInfo[enMaxDrinks].u32EarnMoney += u32DMoney;
	if (u8Confirm == 1)
	{
		printf("Until now we have %d Drinks counted\n", MaxInfo[enMaxDrinks].u8MaxOrder);
		printf("Earn Money by Drinks %d \n",MaxInfo[enMaxDrinks].u32EarnMoney);
	}
	else
	{
		/*Nothing to do*/
	}
}

void MaxOrderDesserts (uint8 u8AmountDesserts , uint8 u8Dessert)
{
	uint8 u8Confirm = 0;
	uint32 u32Money = 0;
	printf("Do you want to see the Desserts count?\n1)Yes\n2)No\n");
	scanf("%d",&u8Confirm);
	MaxInfo[enMaxDesserts].u8MaxOrder += u8AmountDesserts;
	if (u8Dessert == 1)
	{
		u32Money = Cheesecake1;
	}
	else if (u8Dessert	== 2)
	{
		u32Money = Lemon_Pie1;
	}
	else if (u8Dessert	== 3)
	{
		u32Money = Ice_Cream1;
	}
	else
	{
		u32Money = Nutella_Cake1;
	}
	u32Money *= u8AmountDesserts;
	MaxInfo[enMaxDesserts].u32EarnMoney += u32Money;

	if (u8Confirm == 1)
	{
		printf("Until now we have %d Desserts counted in your order\n",MaxInfo[enMaxDesserts].u8MaxOrder);
		printf("Earn Money by Desserts %d \n",MaxInfo[enMaxDesserts].u32EarnMoney);
	}
	else 
	{
		/*Nothing to do*/
	}
}

void MaxOrderFries (uint8 u8AmountFries, uint8 u8Size)
{
	uint8 u8Confirm = 0;
	uint32 u32Money = 0;
	printf("Do you want to see the Fries count?\n1)Yes\n2)No\n");
	scanf("%d",&u8Confirm);
	MaxInfo[enMaxFries].u8MaxOrder += u8AmountFries;
	if (u8Size == 1)
	{
		u32Money = Small;
	}
	else if (u8Size	== 2)
	{
		u32Money = Medium;
	}
	else if (u8Size	== 3)
	{
		u32Money = Large;
	}
	else
	{
		u32Money = Extra_Large;
	}
	u32Money *= u8AmountFries;
	MaxInfo[enMaxFries].u32EarnMoney += u32Money;
	if (u8Confirm == 1)
	{
		printf("Until now we have %d Fries counted in your order\n",MaxInfo[enMaxFries].u8MaxOrder);
		printf("Earn Money by Fries %d \n",MaxInfo[enMaxFries].u32EarnMoney);
	}
	else 
	{
		/*Nothing to do*/
	}	
}
void Interfaz()
{
	uint8 u8Count;
	uint8 u8Orders;
	printf("Would you like to know the order count?\n1)Yes\n2)No\n");
	scanf("%d",&u8Count);
	if(u8Count == 1)
	{
		printf("What order would you like to know?\n1)Burgers\n2)Drinks\n3)Desserts\n4)Fries\n");
		scanf("%d",&u8Orders);
		switch(u8Orders)
		{
			case 1:
			MaxOrderBurger(u8Amount,u8Type);
			break;

			case 2:
			MaxOrderDrinks(u8AmountDrinks);
			break;

			case 3:
			MaxOrderDesserts(u8AmountDesserts , u8Dessert);
			break;

			case 4:
			MaxOrderFries (u8AmountFries, u8Size);
			break;
		}
	}
}