#include <stdio.h>
#include "Minitas.h"
#include "stdlib.h"
#include <time.h> 

tstMines stMineSweeper[enMaxRows][enMaxColumns] = INIT_MAP;
tstMines stMineSweeper2[enMaxRows][enMaxColumns] = INIT_BOMB;

void main(void)
{
	uint8 u8Difficulty;
	uint8 u8x=1;
	uint8 i;
	uint8 j;
	srand(time(0));
	printf("Welcome to the Minesweeper please select your difficulty:\n 1) Easy\n 2) Medium\n 3) Hard\n 4) God\n");
	scanf("%d", &u8Difficulty);
	if(u8Difficulty==1)
	{
	printf("Ready for an Easy level.\nThere will be 10 hidden mines.\nCheck out the board and do not find the mines\n");
	BombsPlacement (u8Difficulty);
	PrintGameBoard ();
	Game(u8Difficulty);
	}
	else if(u8Difficulty==2)
	{
	printf("Ready for a Medium level.\nThere will be 20 hidden mines.\nCheck out the board and do not find the mines\n");
	BombsPlacement (u8Difficulty);
	PrintGameBoard ();
	Game(u8Difficulty);
	}
	else if(u8Difficulty==3)
	{
	printf("Ready for a Hard level.\nThere will be 30 hidden mines.\nCheck out the board and do not find the mines\n");
	BombsPlacement (u8Difficulty);
	PrintGameBoard ();
	Game(u8Difficulty);
	}
	else if(u8Difficulty==4)
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
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			printf("%c ", stMineSweeper[i][j]);
		}
	printf("\n");
	}
}

void BombsPlacement (uint8 u8Difficulty)
{
	uint8 i;

	if(u8Difficulty==1)
	{ 
		for (i=0;i<EASY;i++)
		{
			Repetition();
		}	
	}	
	else if(u8Difficulty==2)
	{
		for (i=0;i<MEDIUM;i++)
		{
			Repetition();
		}
	}
	else if(u8Difficulty==3)
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
	u8Row=rand()%15;
	u8Column=rand()%15;
	x=1;
	while(x==1)
	{
		if(stMineSweeper2[u8Row][u8Column] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row][u8Column] = AT_SIGN_CODE;
			Numbers(u8Row, u8Column);
			x=0;
		}
		else
		{
			u8Row=rand()%15;
			u8Column=rand()%15;
		}
	}
}

void Numbers(uint8 u8Row, uint8 u8Column)
{
	if(u8Row==0 && u8Column==0)
	{
		if(stMineSweeper2[u8Row][u8Column+1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row][u8Column+1] += 1;
		}
		if(stMineSweeper2[u8Row+1][u8Column+1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row+1][u8Column+1] += 1;
		}
		if(stMineSweeper2[u8Row+1][u8Column] !=AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row+1][u8Column] += 1;
		}
	}
	else if(u8Row==0 && u8Column==14)
	{
		if(stMineSweeper2[u8Row][u8Column-1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row][u8Column-1] += 1;
		}
		if(stMineSweeper2[u8Row+1][u8Column-1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row+1][u8Column-1] += 1;
		}
		if(stMineSweeper2[u8Row+1][u8Column] !=AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row+1][u8Column] += 1;
		}
	}
	else if(u8Row==14 && u8Column==0)
	{
		if(stMineSweeper2[u8Row][u8Column+1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row][u8Column+1] += 1;
		}
		if(stMineSweeper2[u8Row-1][u8Column+1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row-1][u8Column+1] += 1;
		}
		if(stMineSweeper2[u8Row-1][u8Column] !=AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row-1][u8Column] += 1;
		}
	}
	else if(u8Row==14 && u8Column==14)
	{
		if(stMineSweeper2[u8Row][u8Column-1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row][u8Column-1] += 1;
		}
		if(stMineSweeper2[u8Row-1][u8Column-1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row-1][u8Column-1] += 1;
		}
		if(stMineSweeper2[u8Row-1][u8Column] !=AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row-1][u8Column] += 1;
		}
	}
	else if(u8Row==0)
	{
		if(u8Column!=0 && u8Column!=14)
		{
			if(stMineSweeper2[u8Row][u8Column-1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row][u8Column-1] += 1;
			}
			if(stMineSweeper2[u8Row+1][u8Column-1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row+1][u8Column-1] += 1;
			}
			if(stMineSweeper2[u8Row+1][u8Column] !=AT_SIGN_CODE)
			{
			stMineSweeper2[u8Row+1][u8Column] += 1;
			}
			if(stMineSweeper2[u8Row+1][u8Column+1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row+1][u8Column+1] += 1;
			}
			if(stMineSweeper2[u8Row][u8Column+1] !=AT_SIGN_CODE)
			{
			stMineSweeper2[u8Row][u8Column+1] += 1;
			}
		}
		else
		{
			/*Nothing to do*/
		}	
	}
	else if(u8Row==14)
	{
		if(u8Column!=0 && u8Column!=14)
		{
			if(stMineSweeper2[u8Row][u8Column-1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row][u8Column-1] += 1;
			}
			if(stMineSweeper2[u8Row-1][u8Column-1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row-1][u8Column-1] += 1;
			}
			if(stMineSweeper2[u8Row-1][u8Column] !=AT_SIGN_CODE)
			{
			stMineSweeper2[u8Row-1][u8Column] += 1;
			}
			if(stMineSweeper2[u8Row-1][u8Column+1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row-1][u8Column+1] += 1;
			}
			if(stMineSweeper2[u8Row][u8Column+1] !=AT_SIGN_CODE)
			{
			stMineSweeper2[u8Row][u8Column+1] += 1;
			}
		}
		else
		{
			/*Nothing to do*/
		}	
	}
	else if(u8Column==0)
	{
		if(u8Row!=0 && u8Row!=14)
		{
			if(stMineSweeper2[u8Row][u8Column+1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row][u8Column+1] += 1;
			}
			if(stMineSweeper2[u8Row-1][u8Column+1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row-1][u8Column+1] += 1;
			}
			if(stMineSweeper2[u8Row-1][u8Column] !=AT_SIGN_CODE)
			{
			stMineSweeper2[u8Row-1][u8Column] += 1;
			}
			if(stMineSweeper2[u8Row+1][u8Column+1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row+1][u8Column+1] += 1;
			}
			if(stMineSweeper2[u8Row+1][u8Column] !=AT_SIGN_CODE)
			{
			stMineSweeper2[u8Row+1][u8Column] += 1;
			}
		}
		else
		{
			/*Nothing to do*/
		}	
	}
	else if(u8Column==14)
	{
		if(u8Row!=0 && u8Row!=14)
		{
			if(stMineSweeper2[u8Row][u8Column-1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row][u8Column-1] += 1;
			}
			if(stMineSweeper2[u8Row-1][u8Column-1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row-1][u8Column-1] += 1;
			}
			if(stMineSweeper2[u8Row-1][u8Column] !=AT_SIGN_CODE)
			{
			stMineSweeper2[u8Row-1][u8Column] += 1;
			}
			if(stMineSweeper2[u8Row+1][u8Column-1] != AT_SIGN_CODE)
			{
				stMineSweeper2[u8Row+1][u8Column-1] += 1;
			}
			if(stMineSweeper2[u8Row+1][u8Column] !=AT_SIGN_CODE)
			{
			stMineSweeper2[u8Row+1][u8Column] += 1;
			}
		}
		else
		{
			/*Nothing to do*/
		}	
	}
	else
	{
		if(stMineSweeper2[u8Row][u8Column-1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row][u8Column-1] += 1;
		}
		if(stMineSweeper2[u8Row-1][u8Column-1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row-1][u8Column-1] += 1;
		}
		if(stMineSweeper2[u8Row-1][u8Column] !=AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row-1][u8Column] += 1;
		}
		if(stMineSweeper2[u8Row+1][u8Column-1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row+1][u8Column-1] += 1;
		}
		if(stMineSweeper2[u8Row+1][u8Column] !=AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row+1][u8Column] += 1;
		}
		if(stMineSweeper2[u8Row][u8Column+1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row][u8Column+1] += 1;
		}
		if(stMineSweeper2[u8Row-1][u8Column+1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row-1][u8Column+1] += 1;
		}
		if(stMineSweeper2[u8Row+1][u8Column+1] != AT_SIGN_CODE)
		{
			stMineSweeper2[u8Row+1][u8Column+1] += 1;		
		}
	}
}

void Game(uint8 u8Difficulty)
{
	uint8 u8Row;
	uint8 u8Column;
	uint8 u8Counter=0;
	uint8 x=1;
	uint8 i;
	uint8 j;
	while(x==1)
	{
		u8Row=Row()-1;
		u8Column=Column()-1;
		if(stMineSweeper2[u8Row][u8Column]!=AT_SIGN_CODE)
		{
			stMineSweeper[u8Row][u8Column]=stMineSweeper2[u8Row][u8Column];
			PrintGameBoard();
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
				{
					if(stMineSweeper[i][j]==HASHTAG_SIGN_CODE)
					{
						u8Counter += 1;
					}	
					else
					{
						/*Nothing to do*/
					}
				}
			}
			if (u8Difficulty==1)
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
			else if (u8Difficulty==2)
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
			else if (u8Difficulty==3)
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
			else if (u8Difficulty==4)
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
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
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
	while (x>=16 || x<=0)
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
	while (y>=16 || y<=0)
	{
		fflush(stdin);
		printf("Type in a column from 1 to 15\n");
		scanf("%d",&y);
	}
	return y;
}