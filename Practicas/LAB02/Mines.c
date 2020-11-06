#include <stdio.h>
#include "Mines.h"
#include "stdlib.h"
#include <time.h> 

tstMines stMineSweeper[enMaxRows][enMaxColumns] = INIT_MAP;
tstMines stMineSweeper2[enMaxRows][enMaxColumns] = INIT_BOMB;

void main(void)
{
	uint8 u8Difficulty;
	uint8 i;
	uint8 j;
	srand(time(0));
	printf("Welcome to the Minesweeper please select your difficulty:\n 1) Easy\n 2) Medium\n 3) Hard\n 4) God\n");
	scanf("%d", &u8Difficulty);
	if(u8Difficulty==LEVEL_EASY)
	{
	printf("Ready for an Easy level.\nThere will be 10 hidden mines.\nCheck out the board and do not find the mines\n");
	BombsPlacement (u8Difficulty);
	PrintGameBoard ();
	Game(u8Difficulty);
	}
	else if(u8Difficulty==LEVEL_MEDIUM)
	{
	printf("Ready for a Medium level.\nThere will be 20 hidden mines.\nCheck out the board and do not find the mines\n");
	BombsPlacement (u8Difficulty);
	PrintGameBoard ();
	Game(u8Difficulty);
	}
	else if(u8Difficulty==LEVEL_HARD)
	{
	printf("Ready for a Hard level.\nThere will be 30 hidden mines.\nCheck out the board and do not find the mines\n");
	BombsPlacement (u8Difficulty);
	PrintGameBoard ();
	Game(u8Difficulty);
	}
	else if(u8Difficulty==LEVEL_GOD)
	{
	printf("Ready for God level.\nThere will be 60 hidden mines.\nCheck out the board and do not find the mines\n");
	BombsPlacement (u8Difficulty);  
	PrintGameBoard ();
	Game(u8Difficulty);
	}
	else
	{
		/*Nothing to do*/
	}	
}

void PrintGameBoard ()
{
	uint8 i;
	uint8 j;
	for(i=ROW_BORDER1;i<=ROW_BORDER2;i++)
	{
		for(j=COLUMN_BORDER1;j<=COLUMN_BORDER2;j++)
		{
			printf("%c ", stMineSweeper[i][j]);
		}
	printf("\n");
	}
}

void BombsPlacement (uint8 u8Difficulty)
{
	uint8 i;

	if(u8Difficulty==LEVEL_EASY)
	{ 
		for (i=0;i<EASY;i++)
		{
			Repetition();
		}	
	}	
	else if(u8Difficulty==LEVEL_MEDIUM)
	{
		for (i=0;i<MEDIUM;i++)
		{
			Repetition();
		}
	}
	else if(u8Difficulty==LEVEL_HARD)
	{
		for (i=0;i<HARD;i++)
		{
			Repetition();
		}			
	}
	else 
	{
		for (i=0;i<GOD;i++)
		{
			Repetition();
		}			
	}
}

void Repetition()
{
	uint8 u8Row=0;
	uint8 u8Column=0;
	uint8 x;
	u8Row=rand()%SIZE2;
	u8Column=rand()%SIZE2;
	x=FACTOR;
	while(x==FACTOR)
	{
		if(stMineSweeper2[u8Row][u8Column] != AT_ASCII)
		{
			stMineSweeper2[u8Row][u8Column] = AT_ASCII;
			Numbers(u8Row, u8Column);
			x=0;
		}
		else
		{
			u8Row=rand()%SIZE2;
			u8Column=rand()%SIZE2;
		}
	}
}

void Numbers(uint8 u8Row, uint8 u8Column)
{
	if(u8Row==ROW_BORDER1 && u8Column==COLUMN_BORDER1)
	{
		if(stMineSweeper2[u8Row][u8Column+YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row][u8Column+YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row+XFACTOR][u8Column+YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row+XFACTOR][u8Column+YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row+XFACTOR][u8Column] !=AT_ASCII)
		{
			stMineSweeper2[u8Row+XFACTOR][u8Column] += FACTOR;
		}
	}
	else if(u8Row==ROW_BORDER1 && u8Column==COLUMN_BORDER2)
	{
		if(stMineSweeper2[u8Row][u8Column-YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row][u8Column-YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row+XFACTOR][u8Column-YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row+XFACTOR][u8Column-YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row+XFACTOR][u8Column] !=AT_ASCII)
		{
			stMineSweeper2[u8Row+XFACTOR][u8Column] += FACTOR;
		}
	}
	else if(u8Row==ROW_BORDER2 && u8Column==COLUMN_BORDER1)
	{
		if(stMineSweeper2[u8Row][u8Column+YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row][u8Column+YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row-XFACTOR][u8Column+YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row-XFACTOR][u8Column+YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row-XFACTOR][u8Column] !=AT_ASCII)
		{
			stMineSweeper2[u8Row-XFACTOR][u8Column] += FACTOR;
		}
	}
	else if(u8Row==ROW_BORDER2 && u8Column==COLUMN_BORDER2)
	{
		if(stMineSweeper2[u8Row][u8Column-YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row][u8Column-YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row-XFACTOR][u8Column-YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row-XFACTOR][u8Column-YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row-XFACTOR][u8Column] !=AT_ASCII)
		{
			stMineSweeper2[u8Row-XFACTOR][u8Column] += FACTOR;
		}
	}
	else if(u8Row==ROW_BORDER1)
	{
		if(u8Column!=COLUMN_BORDER1 && u8Column!=COLUMN_BORDER2)
		{
			if(stMineSweeper2[u8Row][u8Column-YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row][u8Column-YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row+XFACTOR][u8Column-YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row+XFACTOR][u8Column-YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row+XFACTOR][u8Column] !=AT_ASCII)
			{
			stMineSweeper2[u8Row+XFACTOR][u8Column] += FACTOR;
			}
			if(stMineSweeper2[u8Row+XFACTOR][u8Column+YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row+XFACTOR][u8Column+YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row][u8Column+YFACTOR] !=AT_ASCII)
			{
			stMineSweeper2[u8Row][u8Column+YFACTOR] += FACTOR;
			}
		}
		else
		{
			/*Nothing to do*/
		}	
	}
	else if(u8Row==ROW_BORDER2)
	{
		if(u8Column!=COLUMN_BORDER1 && u8Column!=COLUMN_BORDER2)
		{
			if(stMineSweeper2[u8Row][u8Column-YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row][u8Column-YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row-XFACTOR][u8Column-YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row-XFACTOR][u8Column-YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row-XFACTOR][u8Column] !=AT_ASCII)
			{
			stMineSweeper2[u8Row-XFACTOR][u8Column] += FACTOR;
			}
			if(stMineSweeper2[u8Row-XFACTOR][u8Column+YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row-XFACTOR][u8Column+YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row][u8Column+YFACTOR] !=AT_ASCII)
			{
			stMineSweeper2[u8Row][u8Column+YFACTOR] += FACTOR;
			}
		}
		else
		{
			/*Nothing to do*/
		}	
	}
	else if(u8Column==COLUMN_BORDER1)
	{
		if(u8Row!=ROW_BORDER1 && u8Row!=ROW_BORDER2)
		{
			if(stMineSweeper2[u8Row][u8Column+YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row][u8Column+YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row-XFACTOR][u8Column+YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row-XFACTOR][u8Column+YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row-XFACTOR][u8Column] !=AT_ASCII)
			{
			stMineSweeper2[u8Row-XFACTOR][u8Column] += FACTOR;
			}
			if(stMineSweeper2[u8Row+XFACTOR][u8Column+YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row+XFACTOR][u8Column+YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row+XFACTOR][u8Column] !=AT_ASCII)
			{
			stMineSweeper2[u8Row+XFACTOR][u8Column] += FACTOR;
			}
		}
		else
		{
			/*Nothing to do*/
		}	
	}
	else if(u8Column==COLUMN_BORDER2)
	{
		if(u8Row!=ROW_BORDER1 && u8Row!=ROW_BORDER2)
		{
			if(stMineSweeper2[u8Row][u8Column-YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row][u8Column-YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row-XFACTOR][u8Column-YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row-XFACTOR][u8Column-YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row-XFACTOR][u8Column] !=AT_ASCII)
			{
			stMineSweeper2[u8Row-XFACTOR][u8Column] += FACTOR;
			}
			if(stMineSweeper2[u8Row+XFACTOR][u8Column-YFACTOR] != AT_ASCII)
			{
				stMineSweeper2[u8Row+XFACTOR][u8Column-YFACTOR] += FACTOR;
			}
			if(stMineSweeper2[u8Row+XFACTOR][u8Column] !=AT_ASCII)
			{
			stMineSweeper2[u8Row+XFACTOR][u8Column] += FACTOR;
			}
		}
		else
		{
			/*Nothing to do*/
		}	
	}
	else
	{
		if(stMineSweeper2[u8Row][u8Column-YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row][u8Column-YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row-XFACTOR][u8Column-YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row-XFACTOR][u8Column-YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row-XFACTOR][u8Column] !=AT_ASCII)
		{
			stMineSweeper2[u8Row-XFACTOR][u8Column] += FACTOR;
		}
		if(stMineSweeper2[u8Row+XFACTOR][u8Column-YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row+XFACTOR][u8Column-YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row+XFACTOR][u8Column] !=AT_ASCII)
		{
			stMineSweeper2[u8Row+XFACTOR][u8Column] += FACTOR;
		}
		if(stMineSweeper2[u8Row][u8Column+YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row][u8Column+YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row-XFACTOR][u8Column+YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row-XFACTOR][u8Column+YFACTOR] += FACTOR;
		}
		if(stMineSweeper2[u8Row+XFACTOR][u8Column+YFACTOR] != AT_ASCII)
		{
			stMineSweeper2[u8Row+XFACTOR][u8Column+YFACTOR] += FACTOR;		
		}
	}
}

void Game(uint8 u8Difficulty)
{
	uint8 u8Row;
	uint8 u8Column;
	uint8 u8Counter=0;
	uint8 x=FACTOR;
	uint8 i;
	uint8 j;
	while(x==FACTOR)
	{
		u8Row=Row()-XFACTOR;
		u8Column=Column()-YFACTOR;
		if(stMineSweeper2[u8Row][u8Column]!=AT_ASCII)
		{
			stMineSweeper[u8Row][u8Column]=stMineSweeper2[u8Row][u8Column];
			Reveal(u8Row, u8Column);
			PrintGameBoard();
			for(i=ROW_BORDER1;i<=ROW_BORDER2;i++)
			{
				for(j=COLUMN_BORDER1;j<=COLUMN_BORDER2;j++)
				{
					if(stMineSweeper[i][j]==HASHTAG_ASCII)
					{
						u8Counter += FACTOR;
					}	
					else
					{
						/*Nothing to do*/
					}
				}
			}
			if (u8Difficulty==LEVEL_EASY)
			{
				if (u8Counter==EASY)
				{
					printf("You have completed the easy mode.\n Try another one if you feel ready.\n");
					x=0;
				}
				else
				{
					u8Counter=0;
				}
			}
			else if (u8Difficulty==LEVEL_MEDIUM)
			{
				if (u8Counter==MEDIUM)
				{
					printf("You have completed the medium mode.\n Try another one if you feel ready.\n");
					x=0;
				}
				else
				{
					u8Counter=0;
				}
			}
			else if (u8Difficulty==LEVEL_HARD)
			{
				if (u8Counter==HARD)
				{
					printf("You have completed the hard mode.\n Try another one if you feel ready.\n");
					x=0;
				}
				else
				{
					u8Counter=0;
				}
			}
			else if (u8Difficulty==LEVEL_GOD)
			{
				if (u8Counter==GOD)
				{
					printf("You have completed the god mode.\n Congratulations.\n");
					x=0;
				}
				else
				{
					u8Counter=0;
				}
			}
			else
			{
				/*Nothing to do*/
			}
		}
		else
		{
			printf("You lost.\n Here are the rest of the mines.\n");
			for(i=ROW_BORDER1;i<=ROW_BORDER2;i++)
			{
				for(j=COLUMN_BORDER1;j<=COLUMN_BORDER2;j++)
				{
					printf("%c ", stMineSweeper2[i][j]);
				}
				printf("\n");
			}
			x=0;
		}
	}
}

uint8 Row()
{
	uint8 x=0;
	printf("Type in a row from 1 to 15\n");
	scanf("%d",&x);
	while (x<SIZE1 && x>SIZE2)
	{
		fflush(stdin);
		printf("Type in a row from 1 to 15\n");
		scanf("%d",&x);
	}
	return x;
}

uint8 Column()
{
	uint8 y=0;
	printf("Type in a column from 1 to 15\n");
	scanf("%d",&y);
	while (y<SIZE1 && y>SIZE2)
	{
		fflush(stdin);
		printf("Type in a column from 1 to 15\n");
		scanf("%d",&y);
	}
	return y;
}

void Reveal(uint8 u8Row, uint8 u8Column)
{
	uint8 Var= FACTOR;
	uint8 LeftBorder= u8Column - FACTOR;
	uint8 RightBorder= u8Column + FACTOR;
	uint8 TopBorder= u8Row - FACTOR;
	uint8 LowBorder= u8Row + FACTOR;
	while(LeftBorder>COLUMN_BORDER1 && RightBorder<COLUMN_BORDER2 && TopBorder<ROW_BORDER1 && LowBorder>ROW_BORDER2)
	{
		if(stMineSweeper2[u8Row][u8Column]==ZERO_ASCII)
		{
			stMineSweeper[u8Row][LeftBorder] = stMineSweeper2[u8Row][LeftBorder];
			while(stMineSweeper2[u8Row][LeftBorder]==ZERO_ASCII)
			{
				LeftBorder -= FACTOR;
				stMineSweeper[TopBorder][LeftBorder] = stMineSweeper2[TopBorder][LeftBorder];
				stMineSweeper[LowBorder][LeftBorder] = stMineSweeper2[LowBorder][LeftBorder];
				stMineSweeper[u8Row][LeftBorder] = stMineSweeper2[u8Row][LeftBorder];
			}
			LeftBorder= u8Column - FACTOR;
			stMineSweeper[TopBorder][LeftBorder] = stMineSweeper2[TopBorder][LeftBorder];
			stMineSweeper[TopBorder][u8Column] = stMineSweeper2[TopBorder][u8Column];
			stMineSweeper[LowBorder][LeftBorder] = stMineSweeper2[LowBorder][LeftBorder];
			stMineSweeper[LowBorder][u8Column] = stMineSweeper2[LowBorder][u8Column];
			stMineSweeper[u8Row][RightBorder] = stMineSweeper2[u8Row][RightBorder];
			stMineSweeper[TopBorder][RightBorder] = stMineSweeper2[TopBorder][RightBorder];
			stMineSweeper[LowBorder][RightBorder] = stMineSweeper2[LowBorder][RightBorder];	
		}
	}
}