/*
 * Servicio.h
 *
 *  Created on: 12 may. 2021
 *      Author: celes
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_
#define S 4

typedef struct
{
	int id;
	char descripcion[25];
	float precio;
}eServicio;

void HardcodeoServicio(eServicio lista[], int* idServicio);
void MostrarServicio(eServicio servicio);
int MostrarListaServicios(eServicio servicios[], int tam);
int GetDescripcionServicio(eServicio lista[], int tam, int buscarCodigo, char descripcion[]);
eServicio BuscarServicioPorId(eServicio servicios[], int tam, int id);

#endif /* SERVICIO_H_ */
