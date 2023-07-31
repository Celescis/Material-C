/*
 * Servicio.c
 *
 *  Created on: 12 may. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Servicio.h"
#include "Utn.h"

void HardcodeoServicio(eServicio lista[], int* idServicio)
{
	char auxDescripcion[S][25]={"Limpieza","Parche","Centrado","Cadena"};
	float auxPrecio[S]={250,300,400,350};
	int i;

	for(i=0;i<S;i++)
	{
		lista[i].id=*idServicio;
		strcpy(lista[i].descripcion,auxDescripcion[i]);
		lista[i].precio=auxPrecio[i];

		(*idServicio)++;
	}
}

void MostrarServicio(eServicio servicio)
{
	printf("%2d  \t\t  %-10s  \t\t  %.2f\n", servicio.id
										   , servicio.descripcion
							               , servicio.precio);
}

int MostrarListaServicios(eServicio servicios[], int tam)
{
	int isOk=-1;
	int i;

	if(servicios!=NULL && tam>0)
	{
		printf(" ID  \t\t  DESCRIPCION \t\t PRECIO  \n");
		for(i=0;i<tam;i++)
		{
			MostrarServicio(servicios[i]);
			isOk=0;
		}
	}

	return isOk;
}

int GetDescripcionServicio(eServicio lista[], int tam, int buscarCodigo, char descripcion[])
{
	int isOk=-1;
	int i;

	if(lista!=NULL && tam>0 && descripcion!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].id==buscarCodigo)
			{
				strcpy(descripcion,lista[i].descripcion);
				isOk=0;
			}
		}
	}

	return isOk;
}

eServicio BuscarServicioPorId(eServicio servicios[], int tam, int id)
{
	eServicio unServicio;
	int i;

	if(servicios!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(servicios[i].id==id)
			{
				unServicio = servicios[i];
				break;
			}
		}
	}

	return unServicio;
}
