
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

char Type1[] = "Tequila";
char Type2[] = "Whisky";
char Type3[] = "Vodka";
char Move[]="---->";



typedef enum 
{
	Sunrise = 0,
	Margarita,
	Manhattan,
	Mojito,
	enMaxCocktail
}tenstates;

typedef struct
{
	uint8 u8Tequila;
	uint8 u8Whisky;
	uint8 u8Vodka;
}tststates;

#define STATES_INNIT				\
{								\
	{0,0,0},					\
	{0,0,0},					\
	{0,0,0},					\
	{0,0,0}						\
}

#define Tiempo_Mover		1000000000
#define Tiempo_Llenar		3000000000
#define MaxLicor     		4
#define Nothing				5
#define SIZE				1
#define Size2 				3
#define Extra_Limite		2
#define Extra_Limite1		1
#define True				1
#define False				0
#define	FillDrink			1
#define EnableFillTequila	2
#define EnableFillDrink		3
#define ReturnBase			4
#define Teq 				1				
#define Whysk 				2
#define Vodk 				3
#define Sunrise				1
#define Margarita			2
#define Manhattan			3
#define Mojito				4
#define Hielo				1
#define Clamato				2
#define Tajin				3
void Drinks (uint8 u8Alcohol , uint8 u8Drink);
void Extra(uint8 u8Ingrediente);
void Function();