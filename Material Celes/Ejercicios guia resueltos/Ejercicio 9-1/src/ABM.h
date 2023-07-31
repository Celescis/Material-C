/*
 * ABM.h
 *
 *  Created on: 28 abr. 2021
 *      Author: celes
 */

#ifndef ABM_H_
#define ABM_H_
#include "ABM.h"
#define MAX 2
#define EEUU 1
#define CHINA 2
#define OTROS 3
#define IPHONE 0
#define MAC 1
#define IPAD 2
#define ACCESORIOS 3
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int idProducto;
	char descripcion[20];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;
}eProducto;

void Iniciar(eProducto[], int);
int BuscarLibre(eProducto[],int);

//ALTA
eProducto PedirDatosProductos();
int CargarProductos(eProducto[], int);
void MostrarProductos(eProducto);
void MostrarListaProductos(eProducto[], int);

#endif /* ABM_H_ */
