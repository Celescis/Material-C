/******************************************************************************

Ejercicio 17-2:
Realizar una función que reciba como parámetro un array de enteros, su tamaño y un entero.
La función se encargará de buscar el valor entero y borrará la primera ocurrencia del mismo.
El array deberá reestructurarse dinámicamente.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Search(int* array, int tam, int numero);

int main()
{
    int* vec;
    int num;
    int tam = 5;

    vec = (int*)malloc(sizeof(int)*tam);

    for(int i=0; i<tam ;i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d",(vec+i));
    }

    printf("Ingrese un numero a buscar: ");
    scanf("%d",&num);
    Search(vec,tam,num);

    for(int i=0; i<tam-1 ;i++)
    {
        printf("%d\n",*(vec+i));
    }
    return 0;
}

void Search(int* array, int tam, int numero)
{
    int flag = 0;
    int* arrayAux = NULL;

    if(array!=NULL && tam>0)
    {
        if(*(array+tam)!=numero)//si el ultimo num del array es distinto al numero pedido
        {
            for(int i=0; i<tam ;i++)
            {
                if((*(array+i)==numero)||flag==1)
                {
                   for(int j=i; j<tam-1 ;j++)
                    {
                        *(array+j)=*(array+(j+1));
                    }
                   flag=1;
                }
            }
        }
        arrayAux = (int*)realloc(array,sizeof(int)*tam-1);

        if(arrayAux!=NULL)
        {
            array=arrayAux;
        }
    }
}

