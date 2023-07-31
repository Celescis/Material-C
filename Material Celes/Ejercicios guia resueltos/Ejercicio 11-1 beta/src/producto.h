/*
 * producto.h
 *
 *  Created on: 9 may. 2021
 *      Author: celes
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#define TAM 4
#include "informes.h"

typedef struct
{
	int idProducto;
	char descripcion[20];
	int idNacionalidad;
	int idTipo;
	float precio;
	int isEmpty;

}eProducto;

int Menu();
int ObtenerID();
void Inicializar(eProducto[],int);
int BuscarLibre(eProducto[],int);
int PedirData(eProducto[],int,int*,char[],char[],char[],float*,int*);


#endif /* PRODUCTO_H_ */
