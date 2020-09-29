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
	uint8 u8Condicion=1;
	
	printf("De cuantos bits seria tu variable?");
	scanf("%d",&u32SOV);
	if(u32SOV == 8 || u32SOV == 16 || u32SOV == 32)
	{
		while (u8Condicion == 1)
		{
			printf("1:Operacion AND\n");
			printf("2:Operacion OR\n");
			printf("3:Operacion XOR\n");	
			scanf("%d",&u32Opciones);
			if(u32Opciones>=1 && u32Opciones<=3)
			{
				printf("Corrimiento para la operaciones");
				scanf("%d",&u32Correr);
				if (u32Correr> u32SOV)
				{
					if(u32Opciones==1)
					{
						(u32Variable &= !(1<<u32Correr));
					}
					else if(u32Opciones==2)
					{
						(u32Variable |= (1<<u32Correr));
					}
					else
					{
						(u32Variable ^= (1<<u32Correr));
					}
					printf("El resultado de la operación es: %d",u32Variable);
					(u8Condicion == 1);	
				}
				else
					(u8Condicion == 1);	
			}
			else
				(u8Condicion == 1);
			printf("Favor de seleccionar un número dentro de las opciones");
		}
	}
	
}