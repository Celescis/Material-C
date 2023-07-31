/*
 * Tipo.h
 *
 *  Created on: 4 may. 2021
 *      Author: celes
 */

#ifndef TIPO_H_
#define TIPO_H_
#define T 4


typedef struct
{
	int idTipo;
	char descripcionTipo[20];

}eTipoProducto;


void HardcodeoTipoProducto(eTipoProducto[]);
void MostrarUnTipo(eTipoProducto);
void MostrarListaTipos(eTipoProducto[],int);
int GetDescripcionT(eTipoProducto[],int,int,char[]);
int GetCodigoT(eTipoProducto[],int,char[],int*);


#endif /* TIPO_H_ */
