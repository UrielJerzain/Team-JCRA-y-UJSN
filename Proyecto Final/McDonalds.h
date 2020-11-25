typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct 
{
	uint8 u8MaxOrder;
	uint32 u32EarnMoney;
}tstMaxInfo;
		
typedef enum 
{	
	enMaxBurgers,
	enMaxDrinks,
	enMaxDesserts,
	enMaxFries,
	enMaxCount
}tenMaxCount;

#define FACTOR 	   1
#define RESTAURANT 1
#define DRIVE_THRU 2
#define MAX_LETTUCE 50
#define MAX_TOMATO  40
#define MAX_MEAT    100
#define MAX_BREAD   70
#define MAX_CHEESE  60
#define LIMIT1 		1
#define LIMIT2 		4
#define OPTION1     1
#define OPTION2     2
#define OPTION3     3
#define OPTION4     4
#define INGREDIENT1 1
#define INGREDIENT2 2
#define INGREDIENT3 3
#define LETTUCE     0
#define TOMATO      1
#define MEAT        2
#define BREAD       3
#define CHEESE      4
#define Big_Mac		70
#define	Cheeseburger 65
#define Quarter_Pounder 80
#define Deluxe		100
#define Drink		30
#define Cheesecake1 50
#define Lemon_Pie1	55
#define	Ice_Cream1	40
#define	Nutella_Cake1 70
#define Small		25
#define	Medium		35
#define	Large		40
#define Extra_Large 50

#define INNIT_Count			\
{							\
	{0,0},					\
	{0,0},					\
	{0,0},					\
	{0,0}					\
}		 


void Restaurant();
void Drive_Thru();
void Menu();
void Burgers();
void Drinks();
void Desserts();
void Fries();
uint8 Extra();
void AmountBurgers(uint8 u8Type);
void delay(uint8 number_of_seconds);
uint8 printRandoms(uint8 lower, uint8 upper,  uint8 count);
void AmountDrinks();
void AmountDesserts(uint8 u8Dessert);
void AmountFries(uint8 u8Size);
void MaxOrderBurger(uint8 u8Amount, uint8 u8Type);
void MaxOrderDrinks (uint8 u8AmountDrinks);
void MaxOrderDesserts (uint8 u8AmountDesserts , uint8 u8Dessert);
void MaxOrderFries (uint8 u8AmountFries, uint8 u8Size);
void Interfaz();