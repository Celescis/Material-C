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

void HardcodeoTrabajo(eTrabajo listaT[])
{
	int id[3]={1,2,3};
	char marcaBicicleta[3][25]={"Marca1","Marca2","Marca3"};
	int rodadoBicicleta[3]={12,16,18};
	int idServicio[3]={20000,20001,20002};
	eFecha fecha[3]={{1,2,2020},{10,10,1998},{12,5,2015}};
	int i;

	for(i=0;i<3;i++)
	{
		listaT[i].id=id[i];
		strcpy(listaT[i].marcaBicicleta,marcaBicicleta[i]);
		listaT[i].rodadoBicicleta=rodadoBicicleta[i];
		listaT[i].idServicio=idServicio[i];
		listaT[i].fecha=fecha[i];
		listaT[i].isEmpty=OCUPADO;
	}
}

void ObtenerId (int* idAutoIncremental)
{
	*idAutoIncremental+=1;
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

int OrdenarTrabajosPorAnio(eTrabajo lista[], int tam)
{
	eTrabajo auxTrabajo;
	int isOk = -1;

	for(int i = 0; i < tam-1; i++)
	{
		for(int j = i+1; j < tam ; j++)
		{
			if(lista[i].fecha.anio==lista[j].fecha.anio)
			{
				if(strcmp(lista[i].marcaBicicleta,lista[j].marcaBicicleta)>0)
				{
					auxTrabajo = lista[i];
					lista[i] = lista[j];
					lista[j] = auxTrabajo;
					isOk = 0;
				}
			}
			else
			{
				if(lista[i].fecha.anio>lista[j].fecha.anio)
				{
					auxTrabajo = lista[i];
					lista[i] = lista[j];
					lista[j] = auxTrabajo;
					isOk = 0;
				}
			}
		}
	}
	return isOk;
}
