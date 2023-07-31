/*
 ============================================================================
Ejercicio 16-2:
Realizar una función que reciba como parámetros un array de enteros y un entero por referencia.
La función calculará el valor máximo de ese array y utilizará el valor por referencia para retornar ese valor.

 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int ValorMax(int* pArray, int* entero);

int main()
{
	setbuf(stdout,NULL);
    int array[5]={1,12,3,6,10};
    int unEntero;

    if(!ValorMax(array,&unEntero))
    {
        printf("El valor mayor es: %d",unEntero);
    }
    else
    {
        printf("Algo salio mal");
    }

    return 0;
}

int ValorMax(int* pArray, int* entero)
{
    int i;
    int max=0;
    int isOk=-1;

    if(pArray!=NULL && entero!=NULL)
    {
        for(i=0; i<5 ;i++)
        {
            if(i==0 || max<(*(pArray+i)))
            {
                max=(*(pArray+i));
                *entero=max;
            }
        }
        isOk=0;
    }

    return isOk;
}
