/*
 * Productos.c
 *
 *  Created on: 4 may. 2021
 *      Author: celes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Productos.h"


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
	printf("•0 SALIR\n");
	scanf("%d",&opciones);

	return opciones;
}

int BuscarLibre(eProducto lista[],int tam)
{
	int i;
	int index=-1;

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

	return index;
}

int PedirData(eProducto lista[], int tam, int* auxId, char auxDescripcion[], char auxDescripcionN[], char auxDescripcionT[], float* auxPrecio, int* index)
{
	int isOk=-1;

	if(lista!=NULL && tam>0 && auxId!=NULL && auxDescripcion!=NULL && auxDescripcionN!=NULL && auxDescripcionT!=NULL && auxPrecio>0 && index!=NULL)
	{
		*index=BuscarLibre(lista,tam);

		if(*index!=-1)
		{
			*auxId=ObtenerID();
			utn_getString("Ingrese la descripcion del producto\n","Error, reingrese\n",20,2,auxDescripcion);
			utn_getString("Ingrese la nacionalidad\n","Error, reingrese\n",20,2,auxDescripcionN);
			utn_getString("Ingrese el tipo de producto\n","Error, reingrese\n",20,2,auxDescripcionT);
			utn_getFloat("Ingrese el precio\n","Error, reingrese\n",100.00,10000.00,2,auxPrecio);

			isOk=0;
		}
	}

	return isOk;
}






