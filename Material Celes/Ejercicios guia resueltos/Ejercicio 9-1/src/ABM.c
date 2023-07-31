/*
 * ABM.c
 *
 *  Created on: 28 abr. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"


void Iniciar(eProducto lista[], int tam)//INICIA LAS VARIABLES COMO VACIO
{
	int i;

	for(i=0;i<tam;i++)
	{
		lista[i].isEmpty=VACIO;
	}
}
int BuscarLibre(eProducto lista[],int tam)//BUSCA SI HAY UN ESPACIO VACIO
{
	int i;
	int index=-1;

	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty==VACIO)
		{
			index=i;
			break;
		}
	}

	return index;
}
eProducto PedirDatosProductos()//PIDE LOS DATOS AL USUARIO
{
	eProducto unProducto;

	printf("ID del producto: ");
	scanf("%d",&unProducto.idProducto);
	printf("Descripcion: ");
	fflush(stdin);
	scanf("%[^\n]", unProducto.descripcion);
	printf("Nacionalidad (Ingrese 1 para EEUU, 2 para CHINA, 3 para OTROS): ");
	scanf("%d", &unProducto.nacionalidad);
	printf("Tipo de producto: ");
	scanf("%d",&unProducto.tipo);
	printf("Precio del producto: ");
	scanf("%f",&unProducto.precio);
	unProducto.isEmpty=OCUPADO;//ESTADO OCUPADO DESPUES DE PEDIR DATOS

	return unProducto;
}
int CargarProductos(eProducto lista[], int tam)//CARGAR RECORRE EN BUSCA DE ESPACIO LIBRE Y SI LO ENCUENTRA PIDE A LA FUNCION PEDIR DATOS
{
	int aux;

	aux=BuscarLibre(lista, tam);

	if(aux!=-1)
	{
		lista[aux]=PedirDatosProductos();
	}

	return aux;
}
void MostrarProductos(eProducto unProducto)//MUESTRA UN PRODUCTO
{
	printf("ID del producto: %d\n", unProducto.idProducto);
	printf("Descripcion: %s\n", unProducto.descripcion);
	printf("Nacionalidad: %d\n", unProducto.nacionalidad);
	printf("Tipo de producto: %d\n", unProducto.tipo);
	printf("Precio del producto: %.2f\n", unProducto.precio);
}
void MostrarListaProductos(eProducto lista[], int tam)//MUESTRA LA LISTA PIDIENDO LA FUNCION MOSTRAR PRODUCTOS
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty==OCUPADO)
		{
			MostrarProductos(lista[i]);
		}
	}
}

