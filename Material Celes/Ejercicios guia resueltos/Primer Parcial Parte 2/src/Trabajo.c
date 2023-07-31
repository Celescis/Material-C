/*
 * Trabajo.c
 *
 *  Created on: 12 may. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Trabajo.h"
#include "Utn.h"

void ObtenerId (int* idTrabajo)
{
	*idTrabajo+=1;
}

void Inicializar(eTrabajo lista[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		lista[i].isEmpty=VACIO;
	}
}

int BuscarLibre(eTrabajo lista[], int tam)
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
				break;
			}
		}
	}

	return index;
}

int BuscarTrabajoPorId(eTrabajo lista[], int tam, int id)
{
	int index=-1;
	int i;

	if(lista!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==OCUPADO && lista[i].id==id)
			{
				index=i;
				break;
			}
		}
	}

	return index;
}


