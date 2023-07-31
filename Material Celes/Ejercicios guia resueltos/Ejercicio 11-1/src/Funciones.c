/*
 * Informes.c
 *
 *  Created on: 8 may. 2021
 *      Author: celes
 */
#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int AltaProducto(eProducto lista[], int tam, eNacionalidad listaN[], int tamN, eTipoProducto listaT[], int tamT, int id, char descripcion[], char descripcionN[], char descripcionT[], float precio, int index)
{
	int isOk=-1;
	int idN;
	int idT;

	if(lista!=NULL && tam>0 && listaN!=NULL && tamN>0 && listaT!=NULL && tamT>0 && descripcion!=NULL && descripcionN!=NULL && descripcionT!=NULL && precio>0)
	{

		lista[index].idProducto=id;
		SizeString(descripcion);
		strcpy(lista[index].descripcion,descripcion);
		GetCodigoN(listaN,tamN,descripcionN,&idN);
		lista[index].idNacionalidad=idN;
		GetCodigoT(listaT,tamT,descripcionT,&idT);
		lista[index].idTipo=idT;
		lista[index].precio=precio;
		lista[index].isEmpty=OCUPADO;

		isOk=0;
	}

	return isOk;
}

