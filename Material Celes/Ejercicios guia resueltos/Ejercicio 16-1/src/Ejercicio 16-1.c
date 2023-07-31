/*
 ============================================================================
Ejercicio 16-1:
Realizar una función que reciba un puntero a char y dos char.
La función deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido, por el segundo.
Retornando la cantidad de reemplazos o -1 en caso de error.

CELESTE CISTERNAS 1RO B
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Reemplazar(char*, char, char);

int main(void)
{
	char texto[25];
	char unaLetra;
	char otraLetra;
	int cantidad;

	setbuf(stdout,NULL);

	printf("Ingrese una cadena de texto\n");
	fgets(texto,25,stdin);

	printf("Ingrese una letra\n");
	scanf("%c",&unaLetra);

	printf("Ingrese otra letra\n");
	fflush(stdin);
	scanf("%c",&otraLetra);

	cantidad=Reemplazar(texto,unaLetra,otraLetra);

	if(cantidad==0)
	{
		printf("No hubo reemplazos en la palabra");
	}
	else
	{
		printf("La palabra modificada es: %s y tuvo %d cambios de letra\n", texto, cantidad);
	}

	return 0;
}

int Reemplazar(char* cadena, char caracter, char caracterDos)
{
	int isOk=-1;
	int tam;
	int i;
	int cantidad=0;
	tam = strlen(cadena);

	if(cadena!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			*(cadena+i)=tolower(*(cadena+i));
			if(*(cadena+i)==tolower(caracter))
			{
				*(cadena+i)=tolower(caracterDos);
				cantidad++;
				isOk=cantidad;
			}
		}
	}

	return isOk;
}
