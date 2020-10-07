#include "stdio.h"
#include "GENFUN.h"

void main (void)
{
	uint8 au8TestArray[12] = "hello world";
	uint8 au8Test2Array[10] = {8,9,26,13,2,3,4,2,3,10};
	uint8 u8Target;
	uint8 u8Repetition;
	uint8 u8Average;
	printf("First function CapsOn \n");
	printf("Array before CapsOn: %s\n", au8TestArray);
	GENFUN_vCapsOn (&au8TestArray[0], 12);
	printf("Array after CapsOn: %s\n", au8TestArray);
	printf("Second function CapsOff \n");
	printf("Array before CapsOff: %s\n", au8TestArray);
	GENFUN_vCapsOff (&au8TestArray[0], 12);
	printf("Array after CapsOff: %s\n", au8TestArray);
	printf("Third function GetOccurence \n");
	printf("Type in the letter you are looking for\n");
	scanf("%c", &u8Target);
	u8Repetition = GENFUN_u8GetOccurence (&au8TestArray[0], u8Target,12);
	printf("The amount of times that the letter %c was found in the array: %d\n", u8Target, u8Repetition);
	printf("Fourth function GetAverage \n");
	u8Average = GENFUN_u8GetAverage (&au8Test2Array[0], 10);
	printf("The average of the array is: %d\n", u8Average);
}

void GENFUN_vCapsOn (uint8 *pu8Src, uint8 u8SizeOfList)
{
	while ( u8SizeOfList != 0 )
	 {
	 	if (*pu8Src > ACII_LOW_THRESHOLD_OFF_ON && *pu8Src < ACII_HIGH_THRESHOLD_OFF_ON)
	    {
	     	*pu8Src -= ACII_CONVERTION_FACTOR;
	    }
	    else
	    {
	    	/*Nothing to do */
	    }
	    pu8Src++;
	    u8SizeOfList--;
	 }
}

void GENFUN_vCapsOff (uint8 *pu8Src, uint8 u8SizeOfList)
{
	while ( u8SizeOfList != 0 )
	 {
	 	if (*pu8Src > ACII_LOW_THRESHOLD_ON_OFF && *pu8Src < ACII_HIGH_THRESHOLD_ON_OFF)
	    {
	     	*pu8Src += ACII_CONVERTION_FACTOR;
	    }
	    else
	    {
	    	/*Nothing to do */
	    }
	    pu8Src++;
	    u8SizeOfList--;
	 }
}

uint8 GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList)
{
	uint8 u8Occurence = 0;
	while ( u8SizeOfList != 0 )
	{
		if (*pu8Src == u8Target)
		{
			u8Occurence++;
		}
		else
	    {
	    	/*Nothing to do */
	    }
	    pu8Src++;
	    u8SizeOfList--;
	}
	return u8Occurence;
}

uint8 GENFUN_u8GetAverage (uint8 *pu8Src, uint8 u8SizeOfList)
{
	uint8 u8Average = 0;
	uint8 u8ListSize = 0;
	uint8 u8Summatory = 0;
	u8ListSize = u8SizeOfList;
	while ( u8SizeOfList != 0 )
	{
		u8Summatory += *pu8Src;
	    pu8Src++;
	    u8SizeOfList--;
	}
	u8Average= u8Summatory/ u8ListSize;
	return u8Average;
}