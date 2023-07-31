/*
 * tipo.c
 *
 *  Created on: 9 may. 2021
 *      Author: celes
 */

#include "tipo.h"

int GetCodigoT(eTipoProducto lista[], int tamT,char buscarDescripcionT[], int *codigoT)
{
	int isOk;
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
	else
	{
		isOk=-1;
	}

	return isOk;
}

int GetDescripcionT(eTipoProducto lista[], int tamT, int buscarCodigoT,char descripcionT[])
{
	int isOk;
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
	else
	{
		isOk=-1;
	}

	return isOk;
}
