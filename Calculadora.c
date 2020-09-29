#include "stdio.h"

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

void main ( void )
{
	uint32 u32Variable=0;
	uint32 u32SOV=0;
	uint32 u32Opciones=0;
	uint32 u32Correr=0;
	
	printf("De cuantos bits seria tu variable?");
	scanf("%d",&u32SOV);
	if(u32SOV == 8 || u32SOV == 16 || u32SOV == 32);
	{
		while ( 1 )
		{
		printf("1:Operacion AND\n");
		printf("2:Operacion OR\n");
		printf("3:Operacion XOR\n");	
		scanf("%d",&Opciones);
		}
	}
	
}