typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct 
{
	uint8 u8Amount;
	uint32 u32EarnMoney;
}tstMaxInfo;
		
typedef enum 
{	
	enBigMac,
	enCheeseBurger,
	enQuarterPounder,
	enDeluxe,
	enTotalBurgers,
	enMaxBurgers
}tenBurger;

typedef enum 
{	
	enCoke,
	enSprite,
	enFanta,
	enSquirt,
	enTotalDrinks,
	enMaxDrinks
}tenDrinks;

typedef enum 
{	
	enCheeseCake,
	enLemonPie,
	enIceCream,
	enNutellaCake,
	enTotalDesserts,
	enMaxDesserts
}tenDesserts;

typedef enum 
{	
	enSmall,
	enMedium,
	enLarge,
	enExtraLarge,
	enTotalFries,
	enMaxFries
}tenFries;

#define FACTOR 	   1
#define FALSO	   0
#define RESTAURANT 1
#define DRIVE_THRU 2
#define MAX_LETTUCE 100
#define MAX_TOMATO  100
#define MAX_MEAT    200
#define MAX_BREAD   100
#define MAX_CHEESE  100
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
#define BIG_MAC		70
#define	CHEESEBURGER 65
#define QUARTER_POUNDER 80
#define DELUXE		100
#define SPRITE      20
#define COKE		30
#define FANTA       25
#define SQUIRT      15
#define CHEESECAKE  35
#define LEMON_PIE	25
#define	ICE_CREAM	10
#define	NUTELLA_CAKE 40
#define SMALL		25
#define	MEDIUM		35
#define	LARGE		40
#define EXTRA_LARGE 50
#define LIMIT_BURGERS 15
#define LIMIT_ORDERS  25
#define RESTRICTION 50
#define EMPLOYEE 1
#define COSTUMER 2
#define DELAY_INGREDIENTS 15
#define DELAY_BURGERS 10
#define DELAY_DESSERTS 20
#define DELAY_DRINKS 15
#define DELAY_FRIES 30

#define INNIT    			\
{							\
	{0,0},					\
	{0,0},					\
	{0,0},					\
	{0,0},					\
	{0,0}					\
}		 

void Start();
void Order();
void Burgers();
void Drinks();
void Desserts();
void Fries();
uint8 Extra();
void AmountBurgers(uint8 u8Type);
void AmountDrinks(uint8 u8Drinks);
void AmountDesserts(uint8 u8Dessert);
void AmountFries(uint8 u8Size);
void MaxOrderBurger(uint8 u8Amount, uint8 u8Type);
void MaxOrderDrinks (uint8 u8Amount, uint8 u8Drinks);
void MaxOrderDesserts (uint8 u8Amount , uint8 u8Dessert);
void MaxOrderFries (uint8 u8Amount, uint8 u8Size);
void Costumer();
void Employee();
void Pay();
void Exit();
void Backup();
void Recharge(uint8 u8AmountLettuce, uint8 u8AmountMeat, uint8 u8AmountCheese, uint8 u8AmountBread, uint8 u8AmountTomato);
void delay(uint32 number_of_seconds);