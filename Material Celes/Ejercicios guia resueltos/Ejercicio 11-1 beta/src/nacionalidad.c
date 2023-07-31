/*
 * nacionalidad.c
 *
 *  Created on: 9 may. 2021
 *      Author: celes
 */

#include "nacionalidad.h"


int GetCodigoN(eNacionalidad lista[], int tamN,char buscarDescripcionN[], int *codigoN)
{
	int isOk;
	int i;

	if(lista!=NULL && buscarDescripcionN!=NULL && tamN>0 && codigoN!=NULL)
	{
		for(i=0;i<tamN;i++)
		{
			if(!strcmp(lista[i].descripcionNacionalidad,buscarDescripcionN))//en otras ocasiones podria preguntar por el isEmpty ocupado
			{
				*codigoN=lista[i].idNacionalidad;
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

int GetDescripcionN(eNacionalidad lista[], int tamN, int buscarCodigoN,char descripcionN[])
{
	int isOk;
	int i;

	if(lista!=NULL && tamN>0 && descripcionN!=NULL)
	{
		for(i=0;i<tamN;i++)
		{
			if(lista[i].idNacionalidad==buscarCodigoN)
			{
				strcpy(lista[i].descripcionNacionalidad,descripcionN);
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
