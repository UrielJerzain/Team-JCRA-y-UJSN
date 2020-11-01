typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef struct
{
uint8 enColumn0;
uint8 enColumn1;
uint8 enColumn2;
uint8 enColumn3;
uint8 enColumn4;
uint8 enColumn5;
uint8 enColumn6;
uint8 enColumn7;
uint8 enColumn8;
uint8 enColumn9;
uint8 enColumn10;
uint8 enColumn11;
uint8 enColumn12;
uint8 enColumn13;
uint8 enColumn14;
}tstMines;

typedef enum
{
	enRow0,
	enRow1,
	enRow2,
	enRow3,
	enRow4,
	enRow5,
	enRow6,
	enRow7,
	enRow8,
	enRow9,
	enRow10,
	enRow11,
	enRow12,
	enRow13,
	enRow14,
	enMaxRows
}tenRows;


#define AT_SIGN_CODE        64
#define EASY		        10
#define MEDIUM      		20
#define HARD         		30

#define INIT_MAP		\
{								\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
	{35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},					\
}

void PrintGameBoard ();
void BombsPlacement (uint8 u8Difficulty);
void Mines();
void Numbers(uint8 u8Row, uint8 u8Column);
