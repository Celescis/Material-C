/*
 * Nacionalidad.c
 *
 *  Created on: 5 may. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Nacionalidad.h"

void HardcodearNacionalidad(eNacionalidad listaNacionalidad[])
{
	int auxId[N]={1,2,3};
	char auxDescripcion[N][20]={"EEUU","CHINA","OTRO"};
	int i;

	for(i=0;i<N;i++)
	{
		listaNacionalidad[i].idNacionalidad=auxId[i];
		strcpy(listaNacionalidad[i].descripcionNacionalidad,auxDescripcion[i]);
	}
}

void MostrarUnaNacionalidad(eNacionalidad unaNacionalidad)
{
	printf("%d. %s\n",unaNacionalidad.idNacionalidad,
					unaNacionalidad.descripcionNacionalidad);
}

void MostrarListaNacionalidad(eNacionalidad listaN[],int tamN)
{
	int i;
	for(i=0;i<tamN;i++)
	{
		MostrarUnaNacionalidad(listaN[i]);
	}
}


int GetCodigoN(eNacionalidad lista[], int tamN,char buscarDescripcionN[], int* codigoN)
{
	int isOk=-1;
	int i;

	if(lista!=NULL && buscarDescripcionN!=NULL && tamN>0)
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

	return isOk;
}

int GetDescripcionN(eNacionalidad lista[], int tamN, int buscarCodigoN,char descripcionN[])
{
	int isOk=-1;
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

	return isOk;
}

