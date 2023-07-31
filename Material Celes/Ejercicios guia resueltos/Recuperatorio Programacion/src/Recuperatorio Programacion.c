/******************************************************************************

                RECUPERATORIO PRIMER PARCIAL PROGRAMACION 2021
Nombre: Celeste Cisternas
Curso: 1ro B
1. Crear una función que reciba como parámetros una cadena. Dicha función deberá convertir a mayúsculas las vocales
y a minúsculas las consonantes.
2. Realizar una función que reciba y retorne un entero. La función deberá determinar si el número es primo o no.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ConversorMayus(char cadena[]);
int EsPrimo(int numero);

int main(void)
{
	setbuf(stdout,NULL);
	char palabra[100];
	int num;
	int retorno;

	printf("\nIngrese una palabra: ");
	gets(palabra);

	retorno = ConversorMayus(palabra);

	if(!retorno)
	{
		printf("\nPalabra transformada: %s\n",palabra);
	}
	else
	{
		printf("Error");
	}

	printf("\nIngrese un numero: ");
	fflush(stdin);
	scanf("%d",&num);

	if(EsPrimo(num))
	{
		printf("\nEl numero %d es primo\n",num);
	}
	else
	{
		printf("\nEl numero %d, no es primo\n",num);
	}

	return EXIT_SUCCESS;
}

int ConversorMayus(char cadena[])
{
	int isOk = 1;
	int len;
	int i;

	len = strlen(cadena);

	if(cadena != NULL)
	{
		isOk = 0;
		for(i = 0; i < len; i++)
		{
			if(cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' || cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
			{
				cadena[i] = toupper(cadena[i]);
			}
			else
			{
				cadena[i] = tolower(cadena[i]);
			}
		}
	}

	return isOk;
}

int EsPrimo(int numero)
{
    int isOk = 1;
    int i;

	for(i = 2; i < numero; i++)
	{
		if((numero % i) == 0)
		{
			isOk = 0;
		}
	}

	return isOk;
}
