/*
 * tipo.h
 *
 *  Created on: 9 may. 2021
 *      Author: celes
 */

#ifndef TIPO_H_
#define TIPO_H_
#define T 4
#include "informes.h"

typedef struct
{
	int idTipo;
	char descripcionTipo[20];

}eTipoProducto;

eTipoProducto x[T]=
			{
					{1000, "IPHONE"},
					{1001,"IPAD"},
					{1002,"MAC"},
					{1003,"ACCESORIOS"}
			};

int GetDescripcionT(eTipoProducto[],int,int,char[]);
int GetCodigoT(eTipoProducto[],int,char[],int*);

#endif /* TIPO_H_ */
