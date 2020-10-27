#include "stdio.h"
#include "Structs.h"

/* Descripcion 

->Crear un programa que simule un estacionamiento con 5 diferentes secciones 0, 1, 2, 3 o 4. Cada seccion tendra un cupo maximo de carros que sera definido por Defines diferentes. 
->Se tiene que usar un arreglo de estructuras para manejar los estacionamientos, la estructura es la de abajo.
->El programa correra en un ciclo infinito y habra funciones aleatorias que metan y saquen carros de las diferentes secciones.
->El programa debe tener una logica que atienda las peticiones siguientes con funciones:
	*Obtener el numero de espacios disponibles de una seccion (F1)
	*Obtener el numero de espacios no disponibles de una seccion (F2)
	*Obtener ganancias de sección(F3)
	*Registrar vehiculo ingresado(F4)
	*Remover vehiculo(F5)
	*Registrar pago de vehiculo ingresado(F6)
*/

/* Fucniones */
/*
->(F1) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de espacios disponibles de esa seccion
->(F2) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de espacios no disponibles de esa seccion
->(F3) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de dinero acumulada en esa sección
->(F4) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y permita ingresar un vehiculo a esa seccion
->(F5) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y permita retirar un vehiculo de la cuenta de la seccion
->(F6) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y registre el pago por haber ingresado el vehiculo
*/

tstParkingInfo astMyParks[enMaxSectors] = INIT_PARKING_SLOTS;						/*Struct to Use*/

void main ( void )
{
	uint8 u8InputAction = 0;
	tenParkingSectors enSector; 
	uint8 u8ConfirmationFromAction = 0;
	while(1)
	{
		fflush(stdin);
		printf("Press 1 to -> Read Available Slots\n");
		printf("Press 2 to -> Read Unavailable Slots\n");
		printf("Press 3 to -> Read Earned Money\n");
		printf("Press 4 to -> Enter a Car to a Section\n");
		printf("Press 5 to -> Remove a Car from a Section\n");
		printf("Enter selection: ");
		scanf("%d", &u8InputAction);
		printf("Action Selected %d\n", u8InputAction );
		printf("Enter Sector from 0 to 4: ");
		scanf("%d", &enSector);
		printf("Sector Selected %d\n", enSector );

		if( enSector < enMaxSectors )
		{
			if( u8InputAction == 1 )
			{
				switch(enSector)
				{
					case 0: ShowAvailableSlots( enSector0 );
					break;
					case 1: ShowAvailableSlots( enSector1 );
					break;
					case 2: ShowAvailableSlots( enSector2 );
					break;
					case 3: ShowAvailableSlots( enSector3 );
					break;
					case 4: ShowAvailableSlots( enSector4 );
					break;
				}
			}
			else if( u8InputAction == 2 )
			{
				switch(enSector)
				{
					case 0: ShowNotAvailableSlots( enSector0 );
					break;
					case 1: ShowNotAvailableSlots( enSector1 );
					break;
					case 2: ShowNotAvailableSlots( enSector2 );
					break;
					case 3: ShowNotAvailableSlots( enSector3 );
					break;
					case 4: ShowNotAvailableSlots( enSector4 );
					break;
				}
			}
			else if( u8InputAction == 3 )
			{
				switch(enSector)
				{
					case 0: ShowEarnedMoney( enSector0 );
					break;
					case 1: ShowEarnedMoney( enSector1 );
					break;
					case 2: ShowEarnedMoney( enSector2 );
					break;
					case 3: ShowEarnedMoney( enSector3 );
					break;
					case 4: ShowEarnedMoney( enSector4 );
					break;
				}
			}
			else if( u8InputAction == 4 )
			{
				switch(enSector)
				{
					case 0: u8ConfirmationFromAction =u8AddCarToSector( enSector0 );
							if(u8ConfirmationFromAction == 1)
							{
								printf("Successfully added to Sector 0\n");
								u8ImportPaymentOfSlot (enSector0);
							}
							else
							{
								printf("Sector 0 is full\n");
							}
					break;
					case 1: u8ConfirmationFromAction =u8AddCarToSector( enSector1 );
						    if(u8ConfirmationFromAction == 1)
							{
								printf("Successfully added to Sector 1\n");
								u8ImportPaymentOfSlot (enSector1);
							}
							else
							{
								printf("Sector 1 is full\n");
							}
					break;
					case 2: u8ConfirmationFromAction =u8AddCarToSector( enSector2 );
							if(u8ConfirmationFromAction == 1)
							{
								printf("Successfully added to Sector 2\n");
								u8ImportPaymentOfSlot (enSector2);
							}
							else
							{
								printf("Sector 2 is full\n");
							}
					break;
					case 3: u8ConfirmationFromAction =u8AddCarToSector( enSector3 );
							if(u8ConfirmationFromAction == 1)
							{
								printf("Successfully added to Sector 3\n");
								u8ImportPaymentOfSlot (enSector3);
							}
							else
							{
								printf("Sector 3 is full\n");
							}
					break;
					case 4: u8ConfirmationFromAction =u8AddCarToSector( enSector4 );
							if(u8ConfirmationFromAction == 1)
							{
								printf("Successfully added to Sector 4\n");
								u8ImportPaymentOfSlot (enSector4);
							}
							else
							{
								printf("Sector 4 is full\n");
							}
					break;
				}
			}
			else if ( u8InputAction == 5 )
			{
				switch(enSector)
				{
					case 0: u8ConfirmationFromAction =u8RemoveCarFromSector( enSector0 );
							if(u8ConfirmationFromAction == 1)
							{
								printf("Successfully removed from Sector 0\n");
							}
							else
							{
								printf("Sector 0 is empty\n");
							}
					break;
					case 1: u8ConfirmationFromAction =u8RemoveCarFromSector( enSector1 );
						    if(u8ConfirmationFromAction == 1)
							{
								printf("Successfully removed from Sector 1\n");
							}
							else
							{
								printf("Sector 1 is empty\n");
							}
					break;
					case 2: u8ConfirmationFromAction =u8RemoveCarFromSector( enSector2 );
							if(u8ConfirmationFromAction == 1)
							{
								printf("Successfully removed from Sector 2\n");
							}
							else
							{
								printf("Sector 2 is empty\n");
							}
					break;
					case 3: u8ConfirmationFromAction =u8RemoveCarFromSector( enSector3 );
							if(u8ConfirmationFromAction == 1)
							{
								printf("Successfully removed from Sector 3\n");
							}
							else
							{
								printf("Sector 3 is empty\n");
							}
					break;
					case 4: u8ConfirmationFromAction =u8RemoveCarFromSector( enSector4 );
							if(u8ConfirmationFromAction == 1)
							{
								printf("Successfully removed from Sector 4\n");
							}
							else
							{
								printf("Sector 4 is empty\n");
							}
					break;
				}
			}
			else
			{
				/*Nothing to do*/
			}
			printf("\n\n");
		}
		else
		{
			/*Not a valid sector*/
		}

	}
}

/*F1*/
void ShowAvailableSlots ( tenParkingSectors enCurrentSector )
{
	switch(enCurrentSector)
	{
		case 0: printf("The available slots in this sector %d of %d", astMyParks[enSector0].u8AvailableSlots, astMyParks[enSector0].u8MaxSlots);
		break;
		case 1: printf("The available slots in this sector %d of %d", astMyParks[enSector1].u8AvailableSlots, astMyParks[enSector1].u8MaxSlots);
		break;
		case 2: printf("The available slots in this sector %d of %d", astMyParks[enSector2].u8AvailableSlots, astMyParks[enSector2].u8MaxSlots);
		break;
		case 3: printf("The available slots in this sector %d of %d", astMyParks[enSector3].u8AvailableSlots, astMyParks[enSector3].u8MaxSlots);
		break;
		case 4: printf("The available slots in this sector %d of %d", astMyParks[enSector4].u8AvailableSlots, astMyParks[enSector4].u8MaxSlots);
		break;
	}
}

/*F2*/
void ShowNotAvailableSlots ( tenParkingSectors enCurrentSector )
{
	switch(enCurrentSector)
	{
		case 0: printf("The non available slots in this sector %d of %d", astMyParks[enSector0].u8NotAvailableSlots, astMyParks[enSector0].u8MaxSlots);
		break;
		case 1: printf("The non available slots in this sector %d of %d", astMyParks[enSector1].u8NotAvailableSlots, astMyParks[enSector1].u8MaxSlots);
		break;
		case 2: printf("The non available slots in this sector %d of %d", astMyParks[enSector2].u8NotAvailableSlots, astMyParks[enSector2].u8MaxSlots);
		break;
		case 3: printf("The non available slots in this sector %d of %d", astMyParks[enSector3].u8NotAvailableSlots, astMyParks[enSector3].u8MaxSlots);
		break;
		case 4: printf("The non available slots in this sector %d of %d", astMyParks[enSector4].u8NotAvailableSlots, astMyParks[enSector4].u8MaxSlots);
		break;
	}
}

/*F3*/
void ShowEarnedMoney ( tenParkingSectors enCurrentSector )
{
	switch(enCurrentSector)
	{
		case 0: printf("The amount of money earned in this sector %d", astMyParks[enSector0].u32MoneyEarn);
		break;
		case 1: printf("The amount of money earned in this sector %d", astMyParks[enSector1].u32MoneyEarn);
		break;
		case 2: printf("The amount of money earned in this sector %d", astMyParks[enSector2].u32MoneyEarn);
		break;
		case 3: printf("The amount of money earned in this sector %d", astMyParks[enSector3].u32MoneyEarn);
		break;
		case 4: printf("The amount of money earned in this sector %d", astMyParks[enSector4].u32MoneyEarn);
		break;
	}
}
/*F4*/
uint8 u8AddCarToSector( tenParkingSectors enCurrentSector )
{
	uint8 u8CarIn = 0;
	switch(enCurrentSector)
	{
		case 0: if(astMyParks[enSector0].u8NotAvailableSlots < SECTOR0_SLOTS)
				{
					astMyParks[enSector0].u8AvailableSlots--;
					astMyParks[enSector0].u8NotAvailableSlots++;
					u8CarIn = 1;
				}
				else
				{
					/*Nothing to do*/
				}
				return u8CarIn;
		break;
		case 1: if(astMyParks[enSector1].u8NotAvailableSlots < SECTOR1_SLOTS)
				{
					astMyParks[enSector1].u8AvailableSlots--;
					astMyParks[enSector1].u8NotAvailableSlots++;
					u8CarIn = 1;
				}
				else
				{
					/*Nothing to do*/
				}
				return u8CarIn;
		break;
		case 2: if(astMyParks[enSector2].u8NotAvailableSlots < SECTOR2_SLOTS)
				{
					astMyParks[enSector2].u8AvailableSlots--;
					astMyParks[enSector2].u8NotAvailableSlots++;
					u8CarIn = 1;
				}
				else
				{
					/*Nothing to do*/
				}
				return u8CarIn;
		break;
		case 3: if(astMyParks[enSector3].u8NotAvailableSlots < SECTOR3_SLOTS)
				{
					astMyParks[enSector3].u8AvailableSlots--;
					astMyParks[enSector3].u8NotAvailableSlots++;
					u8CarIn = 1;
				}
				else
				{
					/*Nothing to do*/
				}
				return u8CarIn;
		break;
		case 4: if(astMyParks[enSector4].u8NotAvailableSlots < SECTOR4_SLOTS)
				{
					astMyParks[enSector4].u8AvailableSlots--;
					astMyParks[enSector4].u8NotAvailableSlots++;
					u8CarIn = 1;
				}
				else
				{
					/*Nothing to do*/
				}
				return u8CarIn;
		break;
	}
}
/*F5*/
uint8 u8RemoveCarFromSector( tenParkingSectors enCurrentSector )
{
	uint8 u8CarOut = 0;
	switch(enCurrentSector)
	{
		case 0: if(astMyParks[enSector0].u8NotAvailableSlots > 0)
				{
					astMyParks[enSector0].u8AvailableSlots++;
					astMyParks[enSector0].u8NotAvailableSlots--;
					u8CarOut=1;
				}
				else
				{
					/*Nothing to do*/
				}
				return u8CarOut;
		break;
		case 1: if(astMyParks[enSector1].u8NotAvailableSlots > 0)
				{
					astMyParks[enSector1].u8AvailableSlots++;
					astMyParks[enSector1].u8NotAvailableSlots--;
					u8CarOut=1;
				}
				else
				{
					/*Nothing to do*/
				}
				return u8CarOut;
		break;
		case 2: if(astMyParks[enSector2].u8NotAvailableSlots > 0)
				{
					astMyParks[enSector2].u8AvailableSlots++;
					astMyParks[enSector2].u8NotAvailableSlots--;
					u8CarOut=1;
				}
				else
				{
					/*Nothing to do*/
				}
				return u8CarOut;
		break;
		case 3: if(astMyParks[enSector3].u8NotAvailableSlots > 0)
				{
					astMyParks[enSector3].u8AvailableSlots++;
					astMyParks[enSector3].u8NotAvailableSlots--;
					u8CarOut=1;
				}
				else
				{
					/*Nothing to do*/
				}
				return u8CarOut;
		break;
		case 4: if(astMyParks[enSector4].u8NotAvailableSlots > 0)
				{
					astMyParks[enSector4].u8AvailableSlots++;
					astMyParks[enSector4].u8NotAvailableSlots--;
					u8CarOut=1;
				}
				else
				{
					/*Nothing to do*/
				}
				return u8CarOut;
		break;
	}
}
/*F6*/
void u8ImportPaymentOfSlot( tenParkingSectors enCurrentSector )
{
	switch(enCurrentSector)
	{
		case 0: astMyParks[enSector0].u32MoneyEarn += MONEY_EARNED;
		break;
		case 1: astMyParks[enSector1].u32MoneyEarn += MONEY_EARNED;
		break;
		case 2: astMyParks[enSector2].u32MoneyEarn += MONEY_EARNED;
		break;
		case 3: astMyParks[enSector3].u32MoneyEarn += MONEY_EARNED;
		break;
		case 4: astMyParks[enSector4].u32MoneyEarn += MONEY_EARNED;
		break;
	}
}