#include <stdio.h>
#include <GENFUN.h>

void main (void)
{
	uint8 au8TestArray[11] = "hello world";
	printf("Array before CapsOn: %s\n", au8TestArray);
	GENFUN_vCpasOn (&au8TestArray[0], 11);
	printf("Array after CapsOn: %s\n", au8TestArray);
}

void GENFUN_vCpasOn (uint8 *pu8Src, uint8 u8SizeOfList)
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