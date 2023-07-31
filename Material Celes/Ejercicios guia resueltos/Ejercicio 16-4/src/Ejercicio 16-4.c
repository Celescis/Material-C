/*
 ============================================================================
Ejercicio 16-4:
Realizar una función que respete el siguiente prototipo:
int Ordenador(eProducto*,int , int(*pFunc)(eProducto*, eProducto*));
La función Ordenador recibirá como parámetros:
el array de productos, dado por el puntero a eProducto
la cantidad de elementos del array
el criterio de ordenamiento, dado por la función pFunc.
Veamos un  ejemplo de la función criterio:
int CompararPorMarca(eProducto*,eProducto*);
int ComparaPorPrecio(eProducto*,eProducto*);

 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	int id;
	char marca[25];
	int precio;
}eProducto;

int Ordenador(eProducto*, int, int(*pFunc)(eProducto*, eProducto*));
int CompararPorMarca(eProducto*,eProducto*);
int ComparaPorPrecio(eProducto*,eProducto*);
int ComparaPorPrecioDos(eProducto* unProducto, eProducto* otroProducto);
int CompararPorMarcaDos(eProducto* unProducto, eProducto* otroProducto);

int main(void)
{
	setbuf(stdout,NULL);
	int i;
	eProducto unProducto[3]={{1,"Coca",20},{2,"Sprite",30},{3,"Agua",25}};
	printf("\n");
	printf("Marca de la A-Z\n");
	if(!Ordenador(unProducto,3,&CompararPorMarca))
	{
		for(i=0;i<3;i++)
		{
			printf("%d---%s---%d\n",(*(unProducto+i)).id
								   ,(*(unProducto+i)).marca
							       ,(*(unProducto+i)).precio);
		}
	}
	else
	{
		printf("Algo salio mal");
	}
	printf("\n");
	printf("Precio Menor a Mayor\n");
	if(!Ordenador(unProducto,3,&ComparaPorPrecio))
	{
		for(i=0;i<3;i++)
		{
			printf("%d---%s---%d\n",(*(unProducto+i)).id
								   ,(*(unProducto+i)).marca
								   ,(*(unProducto+i)).precio);
		}
	}
	else
	{
		printf("Algo salio mal");
	}
	printf("\n");
	printf("Marca de la Z-A\n");
	if(!Ordenador(unProducto,3,&CompararPorMarcaDos))
	{
		for(i=0;i<3;i++)
		{
			printf("%d---%s---%d\n",(*(unProducto+i)).id
								   ,(*(unProducto+i)).marca
								   ,(*(unProducto+i)).precio);
		}
	}
	else
	{
		printf("Algo salio mal");
	}
	printf("\n");
	printf("Precio Mayor a Menor\n");
	if(!Ordenador(unProducto,3,&ComparaPorPrecioDos))
		{
			for(i=0;i<3;i++)
			{
				printf("%d---%s---%d\n",(*(unProducto+i)).id
									   ,(*(unProducto+i)).marca
									   ,(*(unProducto+i)).precio);
			}
		}
		else
		{
			printf("Algo salio mal");
		}
	return EXIT_SUCCESS;
}

int Ordenador(eProducto* productos, int tam, int(*pFunc)(eProducto*, eProducto*))
{
	int isOk=-1;
	int i;
	int j;

	if(productos!=NULL && tam>0 && pFunc!=NULL)
	{
		for(i=0;i<tam-1;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				isOk=(*pFunc)((productos+i),(productos+j));
			}
		}
		isOk=0;
	}
	return isOk;
}
int CompararPorMarca(eProducto* unProducto, eProducto* otroProducto)
{
	int isOk=-1;
	eProducto auxProducto;

	if(unProducto!=NULL && otroProducto!=NULL)
	{
		if(stricmp(unProducto->marca,otroProducto->marca)>0)
		{
			auxProducto=*unProducto;
			*unProducto=*otroProducto;
			*otroProducto=auxProducto;
			isOk=0;
		}
	}
	return isOk;
}
int CompararPorMarcaDos(eProducto* unProducto, eProducto* otroProducto)
{
	int isOk=-1;
	eProducto auxProducto;

	if(unProducto!=NULL && otroProducto!=NULL)
	{
		if(stricmp(unProducto->marca,otroProducto->marca)<0)
		{
			auxProducto=*unProducto;
			*unProducto=*otroProducto;
			*otroProducto=auxProducto;
			isOk=0;
		}
	}
	return isOk;
}
int ComparaPorPrecio(eProducto* unProducto, eProducto* otroProducto)
{
	int isOk=-1;
	eProducto auxProducto;

	if(unProducto!=NULL && otroProducto!=NULL)
	{
		if(unProducto->precio > otroProducto->precio)
		{
			auxProducto=*unProducto;
			*unProducto=*otroProducto;
			*otroProducto=auxProducto;
			isOk=0;
		}
	}
	return isOk;
}

int ComparaPorPrecioDos(eProducto* unProducto, eProducto* otroProducto)
{
	int isOk=-1;
	eProducto auxProducto;

	if(unProducto!=NULL && otroProducto!=NULL)
	{
		if(unProducto->precio < otroProducto->precio)
		{
			auxProducto=*unProducto;
			*unProducto=*otroProducto;
			*otroProducto=auxProducto;
			isOk=0;
		}
	}
	return isOk;
}
