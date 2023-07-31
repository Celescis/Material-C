/*
 * Tipo.c
 *
 *  Created on: 5 may. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Tipo.h"

void HardcodeoTipoProducto(eTipoProducto listaTipos[])
{
	int auxId[T]={1000,1001,1002,1003};
	char auxDescripcion[T][20]={"IPHONE","IPAD","MAC","ACCESORIOS"};
	int i;

	for(i=0;i<T;i++)
	{
		listaTipos[i].idTipo=auxId[i];
		strcpy(listaTipos[i].descripcionTipo,auxDescripcion[i]);
	}
}

void MostrarUnTipo(eTipoProducto unTipo)
{
	printf("%d %s\n",unTipo.idTipo,
					 unTipo.descripcionTipo);
}

void MostrarListaTipos(eTipoProducto listaT[],int tamT)
{
	int i;
	for(i=0;i<tamT;i++)
	{
		MostrarUnTipo(listaT[i]);
	}
}

int GetCodigoT(eTipoProducto lista[], int tamT,char buscarDescripcionT[], int* codigoT)
{
	int isOk=-1;
	int i;

	if(lista!=NULL && buscarDescripcionT!=NULL && tamT>0)
	{
		for(i=0;i<tamT;i++)
		{
			if(!strcmp(lista[i].descripcionTipo,buscarDescripcionT))//en otras ocasiones podria preguntar por el isEmpty ocupado
			{
				*codigoT=lista[i].idTipo;
				isOk=0;
			}
		}
	}

	return isOk;
}

int GetDescripcionT(eTipoProducto lista[], int tamT, int buscarCodigoT,char descripcionT[])
{
	int isOk=-1;
	int i;

	if(lista!=NULL && tamT>0 && descripcionT!=NULL)
	{
		for(i=0;i<tamT;i++)
		{
			if(lista[i].idTipo==buscarCodigoT)
			{
				strcpy(lista[i].descripcionTipo,descripcionT);
				isOk=0;
			}
		}
	}

	return isOk;
}


