#include <stdio.h>
#define SIZE 100

struct informacion_celda
{
	char nombre[SIZE];
	unsigned int identificador;
	float calidad_senal;
	struct informacion_operador *ptr_operador;
};

struct informacion_operador
{
	char nombre[SIZE];
	unsigned int prioridad;
	unsigned int ultima_comprob;
};

void main (void)
{
	struct informacion_celda c;
	prioridad = 16;
	ultima_comprob = 10;
	nombre = 'Miguel';
	printf(&c.ptr_operador);
}
