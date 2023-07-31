/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : Celeste Cisternas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void modificarArray(int* array, int tam, int num, int index);

int main(void)
{
    setbuf(stdout, NULL);
    int* pEnteros;
    pEnteros = (int*) malloc(sizeof(int)*TAM);
    int i;

	if(pEnteros!=NULL)
	{
			*(pEnteros+0)=5;
			*(pEnteros+1)=4;
			*(pEnteros+2)=2;
			*(pEnteros+3)=1;
			*(pEnteros+4)=3;

		for(i=0; i<TAM; i++)
		{
			printf("%d, en la posicion %i\n", *(pEnteros+i), i);
		}
		printf("Llamo al algoritmo de modificacion y vuelvo a imprimir:\n");
		modificarArray(pEnteros, TAM, 15, 2);
		for(i=0; i<TAM+1; i++)
		{
			printf("%d, en la posicion %i\n", *(pEnteros+i), i);
		}
	}

    free(pEnteros);

    return 0;
}

void modificarArray(int* array, int tam, int num, int index)
{
    int i;
    int* pAux;
    pAux = (int*) realloc(array,sizeof(int)*tam+1);
    if(pAux!=NULL)
    {
        for(i=tam+1; i>index-1; i--)
        {
        	*(pAux+i+1) = *(pAux+i);
        }
        	*(pAux+index)=num;
    }
    array = pAux;
}
