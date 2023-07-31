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
/**
 * @fn void HardcodeoServicio(eServicio[], int*)
 * @brief funcion para guardar valores predeterminados de servicio
 *
 * @param lista recibe el array de servicio
 * @param idServicio recibe el id en forma de puntero para autoincrementarlo
 */
void HardcodeoServicio(eServicio lista[], int* idServicio);
/**
 * @fn void MostrarServicio(eServicio)
 * @brief muestra un servicio
 *
 * @param servicio
 */
void MostrarServicio(eServicio servicio);
/**
 * @fn int MostrarListaServicios(eServicio[], int)
 * @brief muestra la lista de servicios
 *
 * @param servicios recibe el array de servicios
 * @param tam tamaño del array
 * @return retorna -1 si salio todo mal y 0 si salio todo bien
 */
int MostrarListaServicios(eServicio servicios[], int tam);
/**
 * @fn int GetDescripcionServicio(eServicio[], int, int, char[])
 * @brief
 *
 * @param lista recibe el array de servicios
 * @param tam tamaño del array
 * @param buscarCodigo
 * @param descripcion
 * @return
 */
int GetDescripcionServicio(eServicio lista[], int tam, int buscarCodigo, char descripcion[]);
/**
 * @fn eServicio AuxiliarServicio(eServicio[], int, int)
 * @brief
 *
 * @param servicios
 * @param tam
 * @param id
 * @return
 */
eServicio AuxiliarServicio(eServicio servicios[], int tam, int id);

#endif /* SERVICIO_H_ */
