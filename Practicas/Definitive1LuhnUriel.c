#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef unsigned char uint8;
typedef unsigned short uint16;

uint8 u8LuhnCheck ( uint8 *pu8Data, uint8 u8Sol);
void main (void)
{
	uint8 au8CardNumber[16] = {4,1,6,8,8,1,8,8,4,4,4,4,7,1,1,0};
	uint8 u8Check = 0;
	uint8 Sol;
    uint8 i;
	u8Check = u8LuhnCheck(&au8CardNumber[0],16);
    for ( i = 0 ; i < 16 ; i++) 
    {
        printf(" %d ", au8CardNumber[i]);
    }
	printf("\nEl residuo es : %d\n",u8Check);
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
    uint8 u8DigitoValidacion;
	while (u8Sol != 0)
	{
		if( u8Sol %2 == 0 )
		{
		    *pu8Data = *pu8Data * 2;
			if ( *pu8Data >= 10 )
			{
			    u8Check = u8Check + *pu8Data%10 + 1;
                *pu8Data = *pu8Data%10 + 1;
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
		*pu8Data++;
		u8Sol--;
	}
    *pu8Data--;
    *pu8Data = u8Check%10;
	u8DigitoValidacion = u8Check%10;
	return (u8Check+u8DigitoValidacion)%10;

}