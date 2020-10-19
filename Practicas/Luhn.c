#include "Luhn.h"
#include "stdio.h"

void main (void)
{
	uint8 au8CardNumber [16] = {5,3,2,8,6,5,4,2,7,9,4,6,2,4,6,7};
	uint8 u8Check = 0;	
	u8Check = u8LuhnCheck(&au8CardNumber[0], 16);
	if( u8Check == 0)
	{
		printf("Your credit card number works");
	}
	else
	{
		printf("Your credit card number does not works.\nPlease try with another one");	
	}
}

uint8 u8LuhnCheck (uint8 *pu8Data, uint8 u8SizeOfList)
{
	uint8 u8Summary = 0;
	uint8 u8Check = 0;
	while (u8SizeOfList != 0)
	{
		if(u8SizeOfList %2==0)
		{
			*pu8Data *=2;
			if(*pu8Data>9)
			{
				u8Summary =(u8Summary + *pu8Data%10 + 1);
			}
			else
			{
				u8Summary =(u8Summary + *pu8Data);
			}
		}
		else
		{
			u8Summary =(u8Summary + *pu8Data);
		}
		pu8Data++;
		u8SizeOfList--;
	}
	u8Check = u8Summary%10;
	return u8Check;
}