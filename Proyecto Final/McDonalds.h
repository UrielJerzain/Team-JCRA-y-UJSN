typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

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
void AmountDesserts();
void AmountFries();