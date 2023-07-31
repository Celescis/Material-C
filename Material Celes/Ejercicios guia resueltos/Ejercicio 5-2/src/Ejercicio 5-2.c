/******************************************************************************

Ejercicio 5-2:
Pedir el ingreso de 10 n�meros enteros entre -1000 y 1000. Determinar:
Cantidad de positivos y negativos.
Sumatoria de los pares.
El mayor de los impares.
Listado de los n�meros ingresados.
Listado de los n�meros pares.
Listado de los n�meros de las posiciones impares.
Se deber�n utilizar funciones y vectores.
CELESTE CISTERNAS 1RO B

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 3

int PedirNum(char texto[],char error[],int min, int max);
void CargarNum(int numero[],int tam, int min, int max);

int main()
{
	setbuf(stdout, NULL);
	int num[MAX];
	int i;

	CargarNum(num,MAX,-1000,1000);

	for(i=0;i<MAX;i++)
	{
		printf("%d\n",num[i]);
	}
    return 0;
}
int PedirNum(char texto[],char error[],int min, int max)
{
	int numero;
	printf("%s",texto);
	scanf("%d",&numero);
	while(numero>max || numero<min)
	{
		printf("%s",error);
		scanf("%d", &numero);
	}

	return numero;
}
void CargarNum(int numero[],int tam, int min, int max)
{
	int i;

	for(i=0;i<tam;i++)
	{
		numero[i]= PedirNum("Ingrese un n�mero: ","Error, fuera de rango \n",-1000,1000);
	}
}


