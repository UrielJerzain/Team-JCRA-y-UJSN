#include <stdio.h>
#include "Mines.h"
#include "stdlib.h"
#include <time.h> 

tstMines stMineSweeper[enMaxRows] = INIT_MAP;
tstMines stMineSweeper2[enMaxRows] = INIT_MAP;

void main(void)
{
	uint8 u8Difficulty;
	uint8 u8x=1;
	srand(time(0));
	printf("Welcome to the Minesweeper please select your difficulty:\n E) Easy\n M) Medium\n H) Hard\n");
	scanf("%c", &u8Difficulty);
	if(u8Difficulty=='E')
	{
	printf("Hola\n");
	BombsPlacement (1);
	PrintGameBoard ();
	}
	else if(u8Difficulty=='M')
	{
	printf("Gay\n");
	BombsPlacement (2);
	PrintGameBoard ();
	}
	else if(u8Difficulty=='H')
	{
	printf("Versa\n");
	BombsPlacement (3);
	PrintGameBoard ();
	}
	else
	{

	}	
}

void PrintGameBoard ()
{
	uint8 i;
	for(i=0;i<15;i++)
	{
	printf("%c ",stMineSweeper[i].enColumn0);
	printf("%c ",stMineSweeper[i].enColumn1);
	printf("%c ",stMineSweeper[i].enColumn2);
	printf("%c ",stMineSweeper[i].enColumn3);
	printf("%c ",stMineSweeper[i].enColumn4);
	printf("%c ",stMineSweeper[i].enColumn5);
	printf("%c ",stMineSweeper[i].enColumn6);
	printf("%c ",stMineSweeper[i].enColumn7);
	printf("%c ",stMineSweeper[i].enColumn8);
	printf("%c ",stMineSweeper[i].enColumn9);
	printf("%c ",stMineSweeper[i].enColumn10);
	printf("%c ",stMineSweeper[i].enColumn11);
	printf("%c ",stMineSweeper[i].enColumn12);
	printf("%c ",stMineSweeper[i].enColumn13);
	printf("%c ",stMineSweeper[i].enColumn14);
	printf("\n");
	}
}

void BombsPlacement (uint8 u8Difficulty)
{
	uint8 i;
	if(u8Difficulty==1)
	{ 
		for (i=0;i<10;i++)
		{
			Mines();
		}	
	}	
	else if(u8Difficulty==2)
	{
		for (i=0;i<20;i++)
		{
			Mines();
		}
	}
	else
	{
		for (i=0;i<30;i++)
		{
			Mines();
		}
	}
}

void Mines()
{
	uint8 u8Row=0;
	uint8 u8Column=0;

	u8Row=rand()%15;
	u8Column=rand()%15;
	if(u8Column==0)
	{
		stMineSweeper2[u8Row].enColumn0 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==1)
	{
		stMineSweeper2[u8Row].enColumn1 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==2)
	{
		stMineSweeper2[u8Row].enColumn2 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==3)
	{
		stMineSweeper2[u8Row].enColumn3 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==4)
	{
		stMineSweeper2[u8Row].enColumn4 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==5)
	{
		stMineSweeper2[u8Row].enColumn5 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==6)
	{
		stMineSweeper2[u8Row].enColumn6 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==7)
	{
		stMineSweeper2[u8Row].enColumn7 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==8)
	{
		stMineSweeper2[u8Row].enColumn8 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==9)
	{
		stMineSweeper2[u8Row].enColumn9 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==10)
	{
		stMineSweeper2[u8Row].enColumn10 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==11)
	{
		stMineSweeper2[u8Row].enColumn11 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==12)
	{
		stMineSweeper2[u8Row].enColumn12 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else if(u8Column==13)
	{
		stMineSweeper2[u8Row].enColumn13 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
	else 
	{
		stMineSweeper2[u8Row].enColumn14 = AT_SIGN_CODE;
		Numbers(u8Row, u8Column);
	}
}

void Numbers(uint8 u8Row, uint8 u8Column)
{
	if(u8Row==0)
	{
		if(u8Column==0)
		{
			stMineSweeper2[u8Row].enColumn1 += 1;
			stMineSweeper2[u8Row+1].enColumn1 += 1;
			stMineSweeper2[u8Row+1].enColumn0 += 1;
		}
		else if(u8Column==1)
		{
			
		}
	}
	
}