#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
//__________________________________________________________________________________________________________
/**
Crear una función que reciba como parámetros una cadena y dos caracteres.
La función permitirá reemplazar en la cadena el primer carácter por el segundo.
Retornará la cantidad de reemplazos que realizó. Utilizar la función en el main.
///////////////////////////////////////////////////////////////////////////////
	setbuf(stdout,NULL);
	char palabra[tam];
	char unaLetra;
	char otraLetra;
	int cantidadReemplazos;

    printf("\nIngrese una palabra: ");
    gets(palabra);

    printf("Ingrese una letra\n");
    scanf("%c",&unaLetra);

    printf("Ingrese otra letra\n");
    fflush(stdin);
    scanf("%c",&otraLetra);

    cantidadReemplazos=CantidadReemplazos(palabra,unaLetra,otraLetra);

    printf("La cantidad de reemplazos es %d\n",cantidadReemplazos);
*/
int CantidadReemplazos(char palabra[], char unaLetra, char otraLetra)
{
    int i;
    int len;
    int contador=0;

    if(palabra!=NULL)
    {
    	len = strlen(palabra);

		for(i = 0; i < len; i++)
		{
			if(tolower(palabra[i]) == tolower(unaLetra))
			{
				palabra[i] = otraLetra;
				contador++;
			}
		}
		strlwr(palabra);
		palabra[0] = toupper(palabra[0]);

		if(contador > 0)
		{
			printf("%s\n", palabra);
		}
    }

    return contador;
}

//__________________________________________________________________________________________________________
/**
Realizar una función que reciba y retorne un entero.
La función deberá hallar cuántos divisores hay del numero recibido como parámetro entre la unidad y el mismo.
Retornará la cantidad encontrada.
 	setbuf(stdout,NULL);
	int num;
	int cantidadDivisores;
	printf("\nIngrese numero: ");
	scanf("%d",&num);

	cantidadDivisores=CantidadDivisores(num);

	printf("La cantidad de divisores de %d es %d",num,cantidadDivisores);
 */
int CantidadDivisores(int numero)
{
    int i;
    int contador=0;

    printf("\nLos divisores son: ");
    for(i=1;i<=numero;i++)
    {
        if(numero%i==0)
        {
            contador++;
            printf("%d, ",i);
        }
    }

    return contador;
}

//__________________________________________________________________________________________________________
/**
 * 	INVERTIR PALABRA
	setbuf(stdout,NULL);
	char palabra[100];

	printf("\nIngrese una palabra: ");
	gets(palabra);

	if(!InvertirCadena(palabra))
	{
		printf("\nLa palabra invertida es: %s",palabra);
	}
 */
int InvertirCadena(char cadena[])
{
    int isOk = -1;
    int i;
    int len = strlen(cadena);
    int tam;
    char aux;

    tam = strlen(cadena) / 2;

    if(cadena != NULL)
    {
        for (i = 0; i < tam; i++)
        {
            aux = cadena[i];
            cadena[i] = cadena[len - i - 1];
            cadena[len - i - 1] = aux;
        }
        isOk = 0;
    }
    return isOk;
}

//__________________________________________________________________________________________________________
/**
 * 	BUSCAR CARACTER
	setbuf(stdout,NULL);
	char palabra[100];
	char caracter;
	int index;

	printf("\nIngrese una palabra: ");
	gets(palabra);

	printf("\nIngrese una letra a buscar: ");
	scanf("%c",&caracter);

	printf("\nLa letra %c de la palabra %s se encuentra en la posicion: ",caracter,palabra);
	index = BuscarCaracter(palabra,caracter);
	if(index<0)
	{
		printf("No se encuentra ese caracter");
	}
*/
int BuscarCaracter(char array[], char caracter)
{
    int i;
    int indice = -1;
    int len = strlen(array);

    if(array!=NULL)
    {
        for(i = 0; i < len; i ++)
		{

        	if(caracter == array[i])
        	{
        		indice = i;
        		printf("%d, ",i+1);
        	}
		}
    }

    return indice;
}
/**
 * Ejercicio 6-3:
	Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido).
	Ninguna de las dos variables se puede modificar.
	Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
	Por ejemplo:
	Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
	Gomez, Juan Ignacio

	setbuf(stdout,NULL);
	char nombre[TAM];
	char apellido[TAM];

    printf("\nIngrese su nombre: ");
    gets(nombre);

    printf("\nIngrese su apellido: ");
    gets(apellido);

    ReacomodarPalabras(nombre,apellido);
 *
 */
int ReacomodarPalabras(char nombre[], char apellido[])
{
	int isOk = -1;
	char aux[100];
	int lenAux;
	int lenNombre;

	if(nombre!=NULL && apellido!=NULL)
	{
		strcpy(aux,apellido);
		strcat(aux,", ");
		strcat(aux,nombre);

		strlwr(aux);//cadena minuscula
		aux[0] = toupper(aux[0]);//hago mayuscula la primer letra
		lenAux = strlen(aux);
		lenNombre = strlen(nombre);
		aux[lenAux-lenNombre] = toupper(aux[lenAux-lenNombre]);

		printf("%s",aux);
	}
	return isOk;
}
