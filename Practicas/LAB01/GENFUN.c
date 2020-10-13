#include "stdio.h"
#include "GENFUN.h"
#include <time.h>
#include <stdlib.h>


/*Nota 85*/
void main (void)
{
	uint8 au8TestArray[12] = "hello world";
	uint8 au8Test2Array[10] = {8,9,26,13,2,3,4,2,3,10};
	uint8 au8Test3Array[10] = {0,0,0,0,0,0,0,0,0,0};
	uint8 au8Test4Array[10] = {0,0,0,0,0,0,0,0,0,0};
	uint8 au8Test5Array[255];
	uint8 au8Test6Array[255];
	uint8 u8Target;
	uint8 u8Repetition;
	uint8 u8Average;
	uint8 u8Char2Set;
	uint8 u8MinVal;
	uint8 u8MaxVal;
	uint8 u8i;
	srand(time(0));

	/*CapsOn*/
	printf("First function CapsOn \n");
	printf("Array before CapsOn: %s\n", au8TestArray);
	GENFUN_vCapsOn (&au8TestArray[0], 12);
	printf("Array after CapsOn: %s\n", au8TestArray);

	/*CapsOff*/
	printf("\n\n\nSecond function CapsOff \n");
	printf("Array before CapsOff: %s\n", au8TestArray);
	GENFUN_vCapsOff (&au8TestArray[0], 12);
	printf("Array after CapsOff: %s\n", au8TestArray);

	/*GetOccurence*/
	printf("\n\n\nThird function GetOccurence \n");
	printf("Type in the letter you are looking for\n");
	gets(&u8Target);
	u8Repetition = GENFUN_u8GetOccurence (&au8TestArray[0], u8Target,12);
	printf("The amount of times that the letter %c was found in the array: %d\n", u8Target, u8Repetition);

	/*GetAverage*/
	printf("\n\n\nFourth function GetAverage \nThe array is:\n");
	for(u8i=0;u8i<10;u8i++)
	{
		printf("%d ", au8Test2Array[u8i]);
	}
	u8Average = GENFUN_u8GetAverage (&au8Test2Array[0], 10);
	printf("\nThe average of the array is: %d\n", u8Average);

	/*MemSet*/
	printf("\n\n\nFifth function MemSet \n");
	printf("Original array: %s\n", au8TestArray);
	printf("Type in a letter that you want to fill the array with \n");
	scanf("%c", &u8Char2Set);
	GENFUN_u8MemSet (&au8TestArray[0], u8Char2Set, 11);
	printf("Array after MemSet: %s\n", au8TestArray);
			

	/*MemCopy*/
	printf("\n\n\nSixth function MemCopy \n");
	printf("Backup array before MemCopy\n");
	for(u8i=0;u8i<10;u8i++)
	{
		printf("%d ", au8Test3Array[u8i]);
	}
	GENFUN_u8MemCopy(&au8Test2Array[0], &au8Test3Array[0], 10);
	printf("\nBackup array after MemCopy\n");
	for(u8i=0;u8i<10;u8i++)
	{
		printf("%d ", au8Test3Array[u8i]);
	}

	/*SortList*/
	printf("\n\n\n\nSeventh function SortList \n");
	printf("Array before SortList\n");
	for(u8i=0;u8i<10;u8i++)
	{
		printf("%d ", au8Test2Array[u8i]);
	}
	GENFUN_vSortList (&au8Test2Array[0], &au8Test4Array[0], 10);
	printf("\nArray after SortList\n");
	for(u8i=0;u8i<10;u8i++)
	{
		printf("%d ", au8Test4Array[u8i]);
	}

	/*SoftSignal*/
	printf("\n\n\n\nEighth function SoftSignal \n");
	printf("Original array \n");
	srand(time(0));
	for(u8i=0;u8i<255;u8i++)
	{
		au8Test5Array[u8i]=(rand()%5*2);
		printf("%d ", au8Test5Array[u8i]);
	}
	GENFUN_vSoftSignal(&au8Test5Array[0], &au8Test6Array[0]);
	printf("\nArray after SoftSignal\n");
	for(u8i=0;u8i<255;u8i++)
	{
		printf("%d ", au8Test6Array[u8i]);
	}

	/*FilterSignal*/
	printf("\n\n\n\nNinth function FilterSignal \n");
	printf("Original array \n");
	for(u8i=0;u8i<255;u8i++)
	{
		au8Test5Array[u8i]=(rand()%101);
		printf("%d ", au8Test5Array[u8i]);
	}
	printf("\nThe Upper limit is: 70\n");
	u8MaxVal=70;
	printf("The Lower limit is: 30\n");
	u8MinVal=30;
	GENFUN_vFilterSignal(&au8Test5Array[0], &au8Test6Array[0], u8MaxVal, u8MinVal);
	printf("Array after SoftFilter\n");
	for(u8i=0;u8i<255;u8i++)
	{
		printf("%d ", au8Test6Array[u8i]);
	}
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
		u8Summatory += *pu8Src;		/*Overflow*/
	    pu8Src++;
	    u8SizeOfList--;
	}
	u8Average= u8Summatory/ u8ListSize;
	return u8Average;
}

void GENFUN_u8MemSet (uint8 *pu8Src, uint8 u8Char2Set, uint8 u8SizeOfList)
{
	while ( u8SizeOfList != 0 )
	{
		*pu8Src = u8Char2Set;
	    pu8Src++;
	    u8SizeOfList--;
	}
}

void GENFUN_u8MemCopy (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList) 
{
	while (u8SizeOfList != 0)
	{
		*pu8Dest = *pu8Src;
		pu8Src++;
		pu8Dest++;
		u8SizeOfList--;
	}
}

void GENFUN_vSortList (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList) 
{
	uint8 i;
	uint8 j;
	uint8 u8aux;						/*Manejaste apuntadores como arreglos*/
	for (i=0;i< u8SizeOfList -1;i++)
	{
		for(j=i+1;j< u8SizeOfList;j++)
		{
			if(pu8Src[i] > pu8Src[j])
			{
				u8aux = pu8Src[i];
				pu8Src[i] = pu8Src[j];
				pu8Src[j] = u8aux;
			}
			else
			{
				/*Nothing to do*/
			}
		}
	}
	while (u8SizeOfList != 0)
	{
		*pu8Dest = *pu8Src;
		pu8Src++;
		pu8Dest++;
		u8SizeOfList--;
	}
}

void GENFUN_vSoftSignal (uint8 *pu8Src, uint8 *pu8Dest)
{
	uint8 u8Summatory = 0;
	uint8 u8Average = 0;				/*Manejaste apuntadores como arreglos*/
	uint8 i;
	uint8 j;
	for (i=0;i< 255;i++)
	{
		for(j=i+1;j< 255;j++)
		{
			u8Summatory = pu8Src[i] + pu8Src[j];
			u8Average = u8Summatory/2;
			pu8Dest[i] = u8Average;
			i++;
		}
	}
}

void GENFUN_vFilterSignal (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8MaxVal, uint8 u8MinVal)
{
	uint8 i;
	for (i=0;i< 255;i++)		/*Manejaste apuntadores como arreglos*/
	{
		if(pu8Src[i] < u8MinVal)
		{
			pu8Src[i] = u8MinVal;
		}
		else
		{
			/*Nothing to do*/
		}
		if(pu8Src[i] > u8MaxVal)
		{
			pu8Src[i] = u8MaxVal;
		}
		else
		{
			/*Nothing to do*/
		}
		pu8Dest[i] = pu8Src[i];
	}
}