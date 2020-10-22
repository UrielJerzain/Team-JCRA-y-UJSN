#include "stdio.h"
#include "LuhnUriel.h"
#include <time.h>
#include <stdlib.h>

void main (void)
{
	uint8 au8CardNumber[16] = {4,4,6,3,5,8,5,2,3,6,3,7,8,1,6,3};
	uint8 u8Check = 0;
	uint8 Sol;

	u8Check = u8LuhnCheck(&au8CardNumber[0],16);
	printf("El resultado es : %d\n",u8Check);
	if ( u8Check == 0)
	{
	printf("Su tarjeta ha sido aceptada");
	}
	else
	{
	printf("Su tarjeta ha sido rechazada");
	}

}

uint8 u8LuhnCheck (uint8 *pu8Data, uint8 u8Sol)
{
	uint8 u8Check=0;
	while (u8Sol != 0)
	{
		if( u8Sol %2 == 1 )
		{
		*pu8Data= *pu8Data * 2;
			if (*pu8Data >= 10)
			{
			u8Check = u8Check + *pu8Data%10 + 1;
			}
			else if (*pu8Data <=9)
			{
			u8Check = u8Check + *pu8Data;
			}	
			else 
			{
			/*Nothing to do*/
			}
	
		
		}
		else
		{
		u8Check = u8Check + *pu8Data;
		}
		pu8Data++;
		u8Sol--;
		}
		u8Check = u8Check%10;
		return u8Check;

}