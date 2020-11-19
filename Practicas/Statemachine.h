typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

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

//typedef struct
//{
//	uint8 u8Licor;
//}tenstates

//typedef enum
//{
//	enTequila = 1,
//	enWhisky,
//	enVodka,
//	MaxLicor
//}Licores;


// typedef struct
// {	

// 	tenMix u8Drink[enMaxDrinks];

// }tenstates;

// typedef struct
// {
// 	enTequila = 0,
// 	enWhisky,
// 	enVodka,
// 	enMaxDrinks
// }tenMix;

#define Tiempo_Mover		10
#define Tiempo_Llenar		20
#define MaxLicor     		4
void Tequila ( uint8 u8Alcohol, uint8 u8Drink);
