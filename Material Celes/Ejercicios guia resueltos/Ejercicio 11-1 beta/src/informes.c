/*
 * informes.c
 *
 *  Created on: 9 may. 2021
 *      Author: celes
 */

#include "informes.h"


int AltaProducto(eProducto lista[], int tam, eNacionalidad listaN[], int tamN, eTipoProducto listaT[], int tamT, int id, char descripcion[], char descripcionN[], char descripcionT[], float precio, int index)
{
	int isOk;

	if(lista!=NULL && tam>0 && listaN!=NULL && tamN>0 && listaT!=NULL && tamT>0 && id!=NULL && descripcion!=NULL && descripcionN!=NULL && descripcionT!=NULL && precio>0)
	{

		lista[index].idProducto=id;
		strcpy(lista[index].descripcion,descripcion);
		GetCodigoN(listaN,tamN,descripcionN,lista[index].idNacionalidad);
		GetCodigoT(listaT,tamT,descripcionT,lista[index].idTipo);
		lista[index].precio=precio;
		lista[index].isEmpty=OCUPADO;

		isOk=0;
	}
	else
	{
		isOk=-1;
	}

	return isOk;
}
