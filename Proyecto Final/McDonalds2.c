#include <stdio.h>
#include "stdlib.h"
#include "McDonalds.h"
#include <time.h>
#include <math.h>

tstMaxInfo stBurgers[enMaxBurgers] = INNIT;
static tstMaxInfo stTotalBurgers[enMaxBurgers];
tstMaxInfo stDrinks[enMaxDrinks] = INNIT;
static tstMaxInfo stTotalDrinks[enMaxDrinks];
tstMaxInfo stDesserts[enMaxDesserts] = INNIT;
static tstMaxInfo stTotalDesserts[enMaxDesserts];
tstMaxInfo stFries[enMaxFries] = INNIT;
static tstMaxInfo stTotalFries[enMaxFries];

static uint8 u8Ingredients[]={MAX_LETTUCE,MAX_TOMATO,MAX_MEAT,MAX_BREAD,MAX_CHEESE};

void Start()
{
	uint8 u8LogIn=RESTRICTION;
	printf("\n\n\n\n\nWelcome to McDonalds.\nSelect 1 if you work here, if not please select 2.\n");
	scanf("%d",&u8LogIn);
	while(u8LogIn<EMPLOYEE || u8LogIn>COSTUMER)
	{
		fflush(stdin);
		printf("Please select a correct option.\n1)Employee\n2)Costumer\n");
		scanf("%d",&u8LogIn);
	}
	if (u8LogIn == EMPLOYEE)
	{
		Employee();
	}
	else
	{
		Costumer();
	}
}

void Employee()
{	
	uint8 u8Account = RESTRICTION;
	printf("What do you want to know?\n1)Burgers\n2)Drinks\n3)Desserts\n4)Fries\n");
	scanf("%d",&u8Account);
	while(u8Account<LIMIT1 || u8Account>LIMIT2) 
	{ 
		fflush(stdin); 
		printf("Please select a correct option:\n1)Burgers\n2)Drinks\n3)Desserts\n4)Fries\n"); 
		scanf("%d", &u8Account); 
	}
	if(u8Account == OPTION1)
	{
		printf("\n\nAt the moment the Costumer had ordered:\nBurgers:\nBig Mac %d  $%d\nCheeseburger %d  $%d\nQuarter Pounder %d  $%d\nDeluxe %d  $%d\nTotal Burgers %d  $%d\n",stTotalBurgers[enBigMac].u8Amount , stTotalBurgers[enBigMac].u32EarnMoney, stTotalBurgers[enCheeseBurger].u8Amount , stTotalBurgers[enCheeseBurger].u32EarnMoney, stTotalBurgers[enQuarterPounder].u8Amount , stTotalBurgers[enQuarterPounder].u32EarnMoney, stTotalBurgers[enDeluxe].u8Amount , stTotalBurgers[enDeluxe].u32EarnMoney, stTotalBurgers[enTotalBurgers].u8Amount , stTotalBurgers[enTotalBurgers].u32EarnMoney);
	}
	else if(u8Account == OPTION2)
	{
		printf("\n\nAt the moments the Costumer had ordered:\nDrinks:\nSprite %d  $%d\nCoke %d  $%d\nFanta %d  $%d\nSquirt %d  $%d\nTotal Drinks %d  $%d\n",stTotalDrinks[enSprite].u8Amount , stTotalDrinks[enSprite].u32EarnMoney, stTotalDrinks[enCoke].u8Amount , stTotalDrinks[enCoke].u32EarnMoney, stTotalDrinks[enFanta].u8Amount , stTotalDrinks[enFanta].u32EarnMoney, stTotalDrinks[enSquirt].u8Amount , stTotalDrinks[enSquirt].u32EarnMoney, stTotalDrinks[enTotalDrinks].u8Amount , stDrinks[enTotalDrinks].u32EarnMoney);
	}
	else if(u8Account == OPTION3)
	{
		printf("\n\nAt the moments the Costumer had ordered:\nDesserts:\nCheese Cake %d  $%d\nLemon Pie %d  $%d\nIce Cream %d  $%d\nNutella Cake %d  $%d\nTotal Desserts %d  $%d\n",stTotalDesserts[enCheeseCake].u8Amount , stTotalDesserts[enCheeseCake].u32EarnMoney, stTotalDesserts[enLemonPie].u8Amount , stTotalDesserts[enLemonPie].u32EarnMoney, stTotalDesserts[enIceCream].u8Amount , stTotalDesserts[enIceCream].u32EarnMoney, stTotalDesserts[enNutellaCake].u8Amount , stTotalDesserts[enNutellaCake].u32EarnMoney, stTotalDesserts[enTotalDesserts].u8Amount , stTotalDesserts[enTotalDesserts].u32EarnMoney);
	}
	else
	{
		printf("\n\nAt the moments the Costumer had ordered:\nFries:\nSmall %d  $%d\nMedium %d  $%d\nLarge %d  $%d\nExtra Large %d  $%d\nTotal Fries %d  $%d\n\n\n",stTotalFries[enSmall].u8Amount , stTotalFries[enSmall].u32EarnMoney, stTotalFries[enMedium].u8Amount , stTotalFries[enMedium].u32EarnMoney, stTotalFries[enLarge].u8Amount , stTotalFries[enLarge].u32EarnMoney, stTotalFries[enExtraLarge].u8Amount , stTotalFries[enExtraLarge].u32EarnMoney, stTotalFries[enTotalFries].u8Amount , stTotalFries[enTotalFries].u32EarnMoney);
	}

}

void Costumer()
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
	else 
	{
		Drive_Thru();
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

void Menu()
{
	uint8 u8Menu;
	static uint8 u8Condition=0;
	printf("What do you want to do?\n1)Order\n2)Consult your bill\n3)Pay\n4)Exit\n");
	scanf("%d",&u8Menu); 
	while(u8Menu<LIMIT1 || u8Menu>LIMIT2) 
	{ 
		fflush(stdin); 
		printf("Please select a correct option:\n1)Order\n2)Consult your bill\n3)Pay\n4)Exit\n"); 
		scanf("%d", &u8Menu); 
	} 
	if(u8Menu == OPTION1)
	{
		Order();
	}
	else if(u8Menu == OPTION2)
	{
		Check();
	}
	else if(u8Menu == OPTION3)
	{
		u8Condition=Pay();
		Menu();
	}
	else
	{
		if(u8Condition==0)
		{
			printf("You cannot leave without paying your bill\n");
			Menu();
		}
		else
		{
			u8Condition=0;
			Exit();
		}
	}
}

void Order()
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
    		case OPTION2: Drinks();
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
	Menu();
}

void Burgers()
{
	uint8 u8Burger;
	printf("Select a burger\n1)Big Mac $70\n2)Cheeseburger $65\n3)Quarter Pounder $80\n4)Deluxe $100\n");
	scanf("%d",&u8Burger); 
	while(u8Burger<LIMIT1 || u8Burger>LIMIT2) 
	{ 
		fflush(stdin); 
		printf("Please select a correct option:\n1)Big Mac $70\n2)Cheeseburger $65\n3)Quarter Pounder $80\n4)Deluxe $100\n"); 
		scanf("%d", &u8Burger); 
	} 
	AmountBurgers(u8Burger);
}

void Drinks()
{	
	uint8 u8Drinks;
	printf("Select a drink:\n1)Sprite $20\n2)Coke $30\n3)Fanta $25\n4)Squirt $15\n");
	scanf("%d",&u8Drinks);
	while(u8Drinks<LIMIT1 || u8Drinks>LIMIT2) 
	{ 
		fflush(stdin); 
		printf("Please select a correct option:\n1)Sprite $20\n2)Coke $30\n3)Fanta $25\n4)Squirt $15\n"); 
		scanf("%d", &u8Drinks); 
	} 
	AmountDrinks(u8Drinks);
}

void Desserts()
{
	uint8 u8Dessert;
	printf("Select a dessert:\n1)Cheesecake $35\n2)Lemon Pie $25\n3)Ice Cream $10\n4)Nutella Cake $40\n");
	scanf("%d",&u8Dessert);
	while(u8Dessert<LIMIT1 || u8Dessert>LIMIT2) 
	{ 
		fflush(stdin); 
		printf("Please select a correct option:\n1)Cheesecake $35\n2)Lemon Pie $25\n3)Ice Cream $10\n4)Nutella Cake $40\n"); 
		scanf("%d", &u8Dessert); 
	} 
	AmountDesserts(u8Dessert);
}

void Fries()
{
	uint8 u8Size;
	printf("What Size do you prefer?\n1)Small $25\n2)Medium $35\n3)Large $40\n4)Extra-Large $50\n");
	scanf("%d",&u8Size);
	while(u8Size<LIMIT1 || u8Size>LIMIT2) 
	{ 
		fflush(stdin); 
		printf("Please select a correct option:\n1)Small $25\n2)Medium $35\n3)Large $40\n4)Extra-Large $50\\n"); 
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
	uint8 u8Amount=RESTRICTION;
	uint8 u8AmountLettuce;
	uint8 u8AmountBread;
	uint8 u8AmountMeat;
	uint8 u8AmountTomato;
	uint8 u8AmountCheese;
	printf("How many Burgers do you want? (MAX 15)\n");
	scanf("%d", &u8Amount);
	while(u8Amount<0 || u8Amount>LIMIT_BURGERS)
	{
		fflush(stdin);
		printf("Type in a correct number from 0 to 15\n");
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
			printf("We will bring more\n");
			Recharge(u8AmountLettuce,u8AmountMeat,u8AmountCheese,u8AmountBread,u8AmountTomato);
		}
		else
		{
			printf("Please wait until your burgers are ready\n");
			u8Ingredients[LETTUCE] -= u8AmountLettuce;
			u8Ingredients[TOMATO] -= u8AmountTomato;
			u8Ingredients[MEAT] -= u8AmountMeat;
			u8Ingredients[BREAD] -= u8AmountBread;
			u8Ingredients[CHEESE] -= u8AmountCheese;
			MaxOrderBurger(u8Amount,u8Type);
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
			printf("We will bring more\n");
			Recharge(u8AmountLettuce,u8AmountMeat,u8AmountCheese,u8AmountBread,u8AmountTomato);
		}
		else
		{
			printf("Please wait until your burgers are ready\n");
			u8Ingredients[LETTUCE] -= u8AmountLettuce;
			u8Ingredients[TOMATO] -= u8AmountTomato;
			u8Ingredients[MEAT] -= u8AmountMeat;
			u8Ingredients[BREAD] -= u8AmountBread;
			u8Ingredients[CHEESE] -= u8AmountCheese;
			MaxOrderBurger(u8Amount,u8Type);
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
			printf("We will bring more\n");
			Recharge(u8AmountLettuce,u8AmountMeat,u8AmountCheese,u8AmountBread,u8AmountTomato);
		}
		else
		{
			printf("Please wait until your burgers are ready\n");
			u8Ingredients[LETTUCE] -= u8AmountLettuce;
			u8Ingredients[TOMATO] -= u8AmountTomato;
			u8Ingredients[MEAT] -= u8AmountMeat;
			u8Ingredients[BREAD] -= u8AmountBread;
			u8Ingredients[CHEESE] -= u8AmountCheese;
			MaxOrderBurger(u8Amount,u8Type);
		}
	}
	else if(u8Type == OPTION4)
	{
		u8AmountLettuce= u8Amount*INGREDIENT3;
		u8AmountMeat= u8Amount*INGREDIENT3;
		u8AmountCheese= u8Amount*INGREDIENT3;
		u8AmountBread= u8Amount*INGREDIENT1;
		u8AmountTomato= u8Amount*INGREDIENT3;
		if(u8AmountLettuce > u8Ingredients[LETTUCE] || u8AmountTomato > u8Ingredients[TOMATO] || u8AmountMeat > u8Ingredients[MEAT] || u8AmountBread > u8Ingredients[BREAD] || u8AmountCheese > u8Ingredients[CHEESE])
		{
			printf("Sorry we don't have enough ingredients\n");
			printf("We will bring more\n");
			Recharge(u8AmountLettuce,u8AmountMeat,u8AmountCheese,u8AmountBread,u8AmountTomato);
		}
		else
		{
			printf("Please wait until your burgers are ready\n");
			u8Ingredients[LETTUCE] -= u8AmountLettuce;
			u8Ingredients[TOMATO] -= u8AmountTomato;
			u8Ingredients[MEAT] -= u8AmountMeat;
			u8Ingredients[BREAD] -= u8AmountBread;
			u8Ingredients[CHEESE] -= u8AmountCheese;
			MaxOrderBurger(u8Amount,u8Type);
		}
	}
	else
	{
		/*Nothing to do*/
	}
}

void AmountDrinks(uint8 u8Drinks)
{	
	uint8 u8AmountDrinks=RESTRICTION;
	printf("How many Drinks do you want? (MAX 25)\n");
	scanf("%d", &u8AmountDrinks);
	while(u8AmountDrinks<0  || u8AmountDrinks>LIMIT_ORDERS)
	{
		fflush(stdin);
		printf("Type in a correct number from 0 to 25\n");
		scanf("%d", &u8AmountDrinks);
	}
	MaxOrderDrinks(u8AmountDrinks, u8Drinks);
}

void AmountDesserts(uint8 u8Dessert)
{
	uint8 u8AmountDesserts=RESTRICTION;
	printf("How many Desserts do you want? (MAX 25)\n");
	scanf("%d", &u8AmountDesserts);
	while(u8AmountDesserts<0 || u8AmountDesserts>LIMIT_ORDERS)
	{
		fflush(stdin);
		printf("Type in a correct number from 0 to 25\n");
		scanf("%d", &u8AmountDesserts);
	}
	MaxOrderDesserts(u8AmountDesserts , u8Dessert);
}

void AmountFries(uint8 u8Size)
{
	uint8 u8AmountFries=RESTRICTION;
	printf("How many Friess do you want? (MAX 25)\n");
	scanf("%d", &u8AmountFries);
	while(u8AmountFries<0 || u8AmountFries>LIMIT_ORDERS)
	{
		fflush(stdin);
		printf("Type in a correct number from 0 to 25\n");
		scanf("%d", &u8AmountFries);
	}
	MaxOrderFries (u8AmountFries, u8Size);
}

void MaxOrderBurger(uint8 u8Amount, uint8 u8Type)
{
	uint32 u32BMoney = 0;
	stBurgers[enTotalBurgers].u8Amount += u8Amount;
	if(u8Type == OPTION1)
	{
		stBurgers[enBigMac].u8Amount += u8Amount;
		u32BMoney = BIG_MAC;
		u32BMoney *= u8Amount;
		stBurgers[enBigMac].u32EarnMoney += u32BMoney;
	}
	else if (u8Type	== OPTION2)
	{
		stBurgers[enCheeseBurger].u8Amount += u8Amount;
		u32BMoney = CHEESEBURGER;
		u32BMoney *= u8Amount;
		stBurgers[enCheeseBurger].u32EarnMoney += u32BMoney;
	}
	else if (u8Type	== OPTION3)
	{
		stBurgers[enQuarterPounder].u8Amount += u8Amount;
		u32BMoney = QUARTER_POUNDER;
		u32BMoney *= u8Amount;
		stBurgers[enQuarterPounder].u32EarnMoney += u32BMoney;
	}
	else
	{
		stBurgers[enDeluxe].u8Amount += u8Amount;
		u32BMoney = DELUXE;
		u32BMoney *= u8Amount;
		stBurgers[enDeluxe].u32EarnMoney += u32BMoney;
	}
	stBurgers[enTotalBurgers].u32EarnMoney += u32BMoney;
}

void MaxOrderDrinks (uint8 u8Amount, uint8 u8Drinks)
{
	uint32 u32BMoney = 0;
	stDrinks[enTotalDrinks].u8Amount += u8Amount;
	if(u8Drinks == OPTION1)
	{
		stDrinks[enSprite].u8Amount += u8Amount;
		u32BMoney = SPRITE;
		u32BMoney *= u8Amount;
		stDrinks[enSprite].u32EarnMoney += u32BMoney;
	}
	else if (u8Drinks	== OPTION2)
	{
		stDrinks[enCoke].u8Amount += u8Amount;
		u32BMoney = COKE;
		u32BMoney *= u8Amount;
		stDrinks[enCoke].u32EarnMoney += u32BMoney;
	}
	else if (u8Drinks	== OPTION3)
	{
		stDrinks[enFanta].u8Amount += u8Amount;
		u32BMoney = FANTA;
		u32BMoney *= u8Amount;
		stDrinks[enFanta].u32EarnMoney += u32BMoney;
	}
	else 
	{
		stDrinks[enSquirt].u8Amount += u8Amount;
		u32BMoney = SQUIRT;
		u32BMoney *= u8Amount;
		stDrinks[enSquirt].u32EarnMoney += u32BMoney;
	}
	stDrinks[enTotalDrinks].u32EarnMoney += u32BMoney;
}

void MaxOrderDesserts (uint8 u8Amount , uint8 u8Dessert)
{
	uint32 u32BMoney = 0;
	stDesserts[enTotalDesserts].u8Amount += u8Amount;
	if(u8Dessert == OPTION1)
	{
		stDesserts[enCheeseCake].u8Amount += u8Amount;
		u32BMoney = CHEESECAKE;
		u32BMoney *= u8Amount;
		stDesserts[enCheeseCake].u32EarnMoney += u32BMoney;
	}
	else if (u8Dessert	== OPTION2)
	{
		stDesserts[enLemonPie].u8Amount += u8Amount;
		u32BMoney = LEMON_PIE;
		u32BMoney *= u8Amount;
		stDesserts[enLemonPie].u32EarnMoney += u32BMoney;
	}
	else if (u8Dessert == OPTION3)
	{
		stDesserts[enIceCream].u8Amount += u8Amount;
		u32BMoney = ICE_CREAM;
		u32BMoney *= u8Amount;
		stDesserts[enIceCream].u32EarnMoney += u32BMoney;
	}
	else 
	{
		stDesserts[enNutellaCake].u8Amount += u8Amount;
		u32BMoney = NUTELLA_CAKE;
		u32BMoney *= u8Amount;
		stDesserts[enNutellaCake].u32EarnMoney += u32BMoney;
	}
	stDesserts[enTotalDesserts].u32EarnMoney += u32BMoney;
}

void MaxOrderFries (uint8 u8Amount, uint8 u8Size)
{
	uint32 u32BMoney = 0;
	stFries[enTotalFries].u8Amount += u8Amount;
	if(u8Size == OPTION1)
	{
		stFries[enSmall].u8Amount += u8Amount;
		u32BMoney = SMALL;
		u32BMoney *= u8Amount;
		stFries[enSmall].u32EarnMoney += u32BMoney;
	}
	else if (u8Size	== OPTION2)
	{
		stFries[enMedium].u8Amount += u8Amount;
		u32BMoney = MEDIUM;
		u32BMoney *= u8Amount;
		stFries[enMedium].u32EarnMoney += u32BMoney;
	}
	else if (u8Size == OPTION3)
	{
		stFries[enLarge].u8Amount += u8Amount;
		u32BMoney = ICE_CREAM;
		u32BMoney *= u8Amount;
		stFries[enLarge].u32EarnMoney += u32BMoney;
	}
	else 
	{
		stFries[enExtraLarge].u8Amount += u8Amount;
		u32BMoney = EXTRA_LARGE;
		u32BMoney *= u8Amount;
		stFries[enExtraLarge].u32EarnMoney += u32BMoney;
	}
	stFries[enTotalFries].u32EarnMoney += u32BMoney;
}

void Check()
{
	printf("\n\nAt the moment you have ordered:\nBurgers:\nBig Mac %d  $%d\nCheeseburger %d  $%d\nQuarter Pounder %d  $%d\nDeluxe %d  $%d\nTotal Burgers %d  $%d\n",stBurgers[enBigMac].u8Amount , stBurgers[enBigMac].u32EarnMoney, stBurgers[enCheeseBurger].u8Amount , stBurgers[enCheeseBurger].u32EarnMoney, stBurgers[enQuarterPounder].u8Amount , stBurgers[enQuarterPounder].u32EarnMoney, stBurgers[enDeluxe].u8Amount , stBurgers[enDeluxe].u32EarnMoney, stBurgers[enTotalBurgers].u8Amount , stBurgers[enTotalBurgers].u32EarnMoney);
	printf("\nDrinks:\nSprite %d  $%d\nCoke %d  $%d\nFanta %d  $%d\nSquirt %d  $%d\nTotal Drinks %d  $%d\n",stDrinks[enSprite].u8Amount , stDrinks[enSprite].u32EarnMoney, stDrinks[enCoke].u8Amount , stDrinks[enCoke].u32EarnMoney, stDrinks[enFanta].u8Amount , stDrinks[enFanta].u32EarnMoney, stDrinks[enSquirt].u8Amount , stDrinks[enSquirt].u32EarnMoney, stDrinks[enTotalDrinks].u8Amount , stDrinks[enTotalDrinks].u32EarnMoney);
	printf("\nDesserts:\nCheese Cake %d  $%d\nLemon Pie %d  $%d\nIce Cream %d  $%d\nNutella Cake %d  $%d\nTotal Desserts %d  $%d\n",stDesserts[enCheeseCake].u8Amount , stDesserts[enCheeseCake].u32EarnMoney, stDesserts[enLemonPie].u8Amount , stDesserts[enLemonPie].u32EarnMoney, stDesserts[enIceCream].u8Amount , stDesserts[enIceCream].u32EarnMoney, stDesserts[enNutellaCake].u8Amount , stDesserts[enNutellaCake].u32EarnMoney, stDesserts[enTotalDesserts].u8Amount , stDesserts[enTotalDesserts].u32EarnMoney);
	printf("\nFries:\nSmall %d  $%d\nMedium %d  $%d\nLarge %d  $%d\nExtra Large %d  $%d\nTotal Fries %d  $%d\n\n\n",stFries[enSmall].u8Amount , stFries[enSmall].u32EarnMoney, stFries[enMedium].u8Amount , stFries[enMedium].u32EarnMoney, stFries[enLarge].u8Amount , stFries[enLarge].u32EarnMoney, stFries[enExtraLarge].u8Amount , stFries[enExtraLarge].u32EarnMoney, stFries[enTotalFries].u8Amount , stFries[enTotalFries].u32EarnMoney);
    Menu();
}

uint8 Pay()
{
	uint32 u32Total;
	uint32 u32Pay=0;
	uint32 u32Change;
	uint8 u8Payed = FACTOR;
	uint8 u8i;
	u32Total=(stBurgers[enTotalBurgers].u32EarnMoney + stDrinks[enTotalDrinks].u32EarnMoney + stDesserts[enTotalDesserts].u32EarnMoney + stFries[enTotalFries].u32EarnMoney);
	printf("Your total is $%d.\nPlease type in the total or more.\n", u32Total);
	scanf("%d", &u32Pay);
	while(u32Pay < u32Total)
	{
		fflush(stdin);
		printf("Not enough money\n");
		scanf("%d", &u32Pay);
	}
	if(u32Pay> u32Total)
	{
		u32Change= u32Pay - u32Total;
		printf("Your change is $%d\n",u32Change);
	}
	else
	{
		/*Nothing to do*/
	}
	Backup();
	for(u8i=0;u8i<=OPTION4; u8i++)
	{
		stBurgers[u8i].u8Amount =0;	
		stDrinks[u8i].u8Amount=0;
		stDesserts[u8i].u8Amount=0;
		stFries[u8i].u8Amount=0;
		stBurgers[u8i].u32EarnMoney =0;	
		stDrinks[u8i].u32EarnMoney=0;
		stDesserts[u8i].u32EarnMoney=0;
		stFries[u8i].u32EarnMoney=0;
	}
	
	return u8Payed;
}

void Exit()
{
	printf("Come back soon\n");
}

void Backup()
{
	stTotalBurgers[enBigMac].u8Amount += stBurgers[enBigMac].u8Amount;
	stTotalBurgers[enBigMac].u32EarnMoney += stBurgers[enBigMac].u32EarnMoney;
	stTotalBurgers[enCheeseBurger].u8Amount += stBurgers[enCheeseBurger].u8Amount;
	stTotalBurgers[enCheeseBurger].u32EarnMoney += stBurgers[enCheeseBurger].u32EarnMoney;
	stTotalBurgers[enQuarterPounder].u8Amount += stBurgers[enQuarterPounder].u8Amount;
	stTotalBurgers[enQuarterPounder].u32EarnMoney += stBurgers[enQuarterPounder].u32EarnMoney;
	stTotalBurgers[enDeluxe].u8Amount += stBurgers[enDeluxe].u8Amount;
	stTotalBurgers[enDeluxe].u32EarnMoney += stBurgers[enDeluxe].u32EarnMoney;
	stTotalBurgers[enTotalBurgers].u8Amount += stBurgers[enTotalBurgers].u8Amount;
	stTotalBurgers[enTotalBurgers].u32EarnMoney += stBurgers[enTotalBurgers].u32EarnMoney;

	stTotalDrinks[enSprite].u8Amount += stDrinks[enSprite].u8Amount;
	stTotalDrinks[enSprite].u32EarnMoney += stDrinks[enSprite].u32EarnMoney;
	stTotalDrinks[enCoke].u8Amount += stDrinks[enCoke].u8Amount;
	stTotalDrinks[enCoke].u32EarnMoney += stDrinks[enCoke].u32EarnMoney;
	stTotalDrinks[enFanta].u8Amount += stDrinks[enFanta].u8Amount;
	stTotalDrinks[enFanta].u32EarnMoney += stDrinks[enFanta].u32EarnMoney;
	stTotalDrinks[enSquirt].u8Amount += stDrinks[enSquirt].u8Amount;
	stTotalDrinks[enSquirt].u32EarnMoney += stDrinks[enSquirt].u32EarnMoney;
	stTotalDrinks[enTotalDrinks].u8Amount += stDrinks[enTotalDrinks].u8Amount;
	stTotalDrinks[enTotalDrinks].u32EarnMoney += stDrinks[enTotalDrinks].u32EarnMoney;

	stTotalDesserts[enCheeseCake].u8Amount += stDesserts[enCheeseCake].u8Amount;
	stTotalDesserts[enCheeseCake].u32EarnMoney += stDesserts[enCheeseCake].u32EarnMoney;
	stTotalDesserts[enLemonPie].u8Amount += stDesserts[enLemonPie].u8Amount;
	stTotalDesserts[enLemonPie].u32EarnMoney += stDesserts[enLemonPie].u32EarnMoney;
	stTotalDesserts[enIceCream].u8Amount += stDesserts[enIceCream].u8Amount;
	stTotalDesserts[enIceCream].u32EarnMoney += stDesserts[enIceCream].u32EarnMoney;
	stTotalDesserts[enNutellaCake].u8Amount += stDesserts[enNutellaCake].u8Amount;
	stTotalDesserts[enNutellaCake].u32EarnMoney += stDesserts[enNutellaCake].u32EarnMoney;
	stTotalDesserts[enTotalDesserts].u8Amount += stDesserts[enTotalDesserts].u8Amount;
	stTotalDesserts[enTotalDesserts].u32EarnMoney += stDesserts[enTotalDesserts].u32EarnMoney;

	stTotalFries[enSmall].u8Amount += stFries[enSmall].u8Amount;
	stTotalFries[enSmall].u32EarnMoney += stFries[enSmall].u32EarnMoney;
	stTotalFries[enMedium].u8Amount += stFries[enMedium].u8Amount;
	stTotalFries[enMedium].u32EarnMoney += stFries[enMedium].u32EarnMoney;
	stTotalFries[enLarge].u8Amount += stFries[enLarge].u8Amount;
	stTotalFries[enLarge].u32EarnMoney += stFries[enLarge].u32EarnMoney;
	stTotalFries[enExtraLarge].u8Amount += stFries[enExtraLarge].u8Amount;
	stTotalFries[enExtraLarge].u32EarnMoney += stFries[enExtraLarge].u32EarnMoney;
	stTotalFries[enTotalFries].u8Amount += stFries[enTotalFries].u8Amount;
	stTotalFries[enTotalFries].u32EarnMoney += stFries[enTotalFries].u32EarnMoney;
}

void Recharge(uint8 u8AmountLettuce, uint8 u8AmountMeat, uint8 u8AmountCheese, uint8 u8AmountBread, uint8 u8AmountTomato)
{
	uint32 u32Delay;
	uint8 x = FACTOR; 
	while(x == FACTOR)
	{


		if ( u8AmountLettuce > u8Ingredients[LETTUCE]) 
		{ 
			printf("Llenando Lechuga");
			u32Delay = DELAY; 
			while(u32Delay--); 
			u8Ingredients[LETTUCE] += MAX_LETTUCE;

		} 
		else if ( u8AmountTomato > u8Ingredients[TOMATO] ) 
		{ 
			printf("\nLlenando Tomate"); 
			u32Delay = DELAY; 
			while(u32Delay--); 
			u8Ingredients[TOMATO] += MAX_TOMATO; 
		} 
		else if (u8AmountMeat > u8Ingredients[MEAT]) 
		{ 
			printf("\nLlenando Carne"); 
			u32Delay = DELAY; 
			while(u32Delay--); 
			u8Ingredients[MEAT] += MAX_MEAT; 
		} 
		else if ( u8AmountBread > u8Ingredients[BREAD] ) 
		{ 
			printf("\nLlenando Pan"); 
			u32Delay = DELAY; 
			while(u32Delay--); 
			u8Ingredients[BREAD] += MAX_BREAD;
		} 
		else if (u8AmountCheese > u8Ingredients[CHEESE]) 
		{ 
			printf("\nLlenando Queso\n"); 
			u32Delay = DELAY; 
			while(u32Delay--); 
			u8Ingredients[CHEESE] += MAX_CHEESE;
		} 
		else
		{
			x = FALSO;
		}
		
	}
	Menu();
}