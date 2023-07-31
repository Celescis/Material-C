/*
 * Productos.h
 *
 *  Created on: 4 may. 2021
 *      Author: celes
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_
#define TAM 4
#define VACIO 0
#define OCUPADO 1

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



#endif /* PRODUCTOS_H_ */
