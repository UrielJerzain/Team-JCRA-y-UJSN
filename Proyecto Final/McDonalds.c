#include <stdio.h>
#include "stdlib.h"
#include "McDonalds.h"
#include <time.h>

void main (void)
{
	uint8 u8Options;
	uint8 u8x=FACTOR;
	printf("Welcome to McDonalds.\nWhere do you prefer to order?\n1) Inside the restaurant.\n2) Drive thru.\n");
	scanf("%d", &u8Options);
	while(u8x==FACTOR)
	{
		if(u8Options==RESTAURANT)
		{
			Restaurant();
			u8x=0;
		}
		else if(u8Options==DRIVE_THRU)
		{
			Drive_Thru();
			u8x=0;
		}
		else
		{
			fflush(stdin);
			scanf("%d", &u8Options);
		}
	}
}

void Restaurant()
{

}

void Drive_Thru()
{

}

void delay(uint8 number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    uint8 milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

uint8 printRandoms(uint8 lower, uint8 upper,  uint8 count) 
{ 
    uint8 i; 
    uint8 num;
    num = (rand() % (upper - lower + FACTOR)) + lower; 
    //printf("%d \n", num); 
    return num;
} 