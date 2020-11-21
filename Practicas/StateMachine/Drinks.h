typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define OPTION1 	1
#define OPTION2     2
#define OPTION3     3
#define OPTION4     4
#define OPTION5     5
#define FACTOR 		1
#define LIMIT1 		1
#define LIMIT2		3
#define DELAY       90000000
#define MOVEMENT    15
#define SERVING     10

typedef enum 
{
	u8Option1,
	u8Option2,
	u8Option3,
	u8Option4,
	u8Option5,
	MaxOptions
}tstOptions;

typedef enum
{
	enLicors,
	enSodas,
	enJuices,
	MaxMenu
}tenMenu;

#define MENU_INNIT				\
{								\
	{0,0,0,0,0},				\
	{0,0,0,0,0},				\
	{0,0,0,0,0}					\
}

void Menu();
void Start();
void Licors();
void Sodas();
void Juices();
uint8 Extra();