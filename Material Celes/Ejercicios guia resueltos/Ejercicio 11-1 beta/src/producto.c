/*
 * producto.c
 *
 *  Created on: 9 may. 2021
 *      Author: celes
 */

#include "producto.h"

int idIncremental=0;

int ObtenerID()
{
	return idIncremental+=1;
}

void Inicializar(eProducto listaProducto[],int tamP)
{
	int i;

	for(i=0;i<tamP;i++)
	{
		listaProducto[i].isEmpty=VACIO;
	}
}

int Menu()
{
	int opciones;

	printf("\t\t\t<Elija una opcion>\t\t\t\n");
	printf("•1 ALTA de producto\n");
	printf("•2 MODIFICAR producto\n");
	printf("•3 BAJA de producto\n");
	printf("•4 MOSTRAR productos\n");
	printf("•0 SALIR");
	scanf("%d",&opciones);

	return opciones;
}

int BuscarLibre(eProducto lista[],int tam)
{
	int i;
	int index;

	if(lista!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==VACIO)
			{
				index=i;
			}
		}
	}
	else
	{
		index=-1;
	}

	return index;
}

int PedirData(eProducto lista[], int tam, int* auxId, char auxDescripcion[], char auxDescripcionN[], char auxDescripcionT[], float* auxPrecio, int* index)
{
	int isOk;

	if(lista!=NULL && tam>0 && auxId!=NULL && auxDescripcion!=NULL && auxDescripcionN!=NULL && auxDescripcionT!=NULL && auxPrecio>0 && index!=NULL)
	{
		*index=BuscarLibre(lista,tam);

		if(*index!=-1)
		{
			*auxId=ObtenerID();
			utn_getName("Ingrese la descripcion del producto\n","Error, reingrese\n",1,sizeof(auxDescripcion),2,auxDescripcion);
			utn_getName("Ingrese la nacionalidad\n","Error, reingrese\n",1,sizeof(auxDescripcionN),2,auxDescripcionN);
			utn_getName("Ingrese el tipo de producto\n","Error, reingrese\n",1,sizeof(auxDescripcionT),2,auxDescripcionT);
			utn_getFloat("Ingrese el precio\n","Error, reingrese\n",1,sizeof(double),100,10000,2,auxPrecio);

			isOk=0;
		}
	}
	else
	{
		isOk=-1;
	}


	return isOk;
}
