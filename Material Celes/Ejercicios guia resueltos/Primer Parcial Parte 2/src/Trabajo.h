/*
 * Trabajo.h
 *
 *  Created on: 12 may. 2021
 *      Author: celes
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#define T 1000
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
    int idBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;
/**
 * @fn void ObtenerId(int*)
 * @brief funcion que recibe como puntero el id para sumarle un numero mas
 *
 * @param idTrabajo valor id tipo puntero
 */
void ObtenerId (int* idTrabajo);
/**
 * @fn void Inicializar(eTrabajo[], int)
 * @brief inicializa toda la estructura en vacio
 *
 * @param lista array trabajo
 * @param tam tamaño del array
 */
void Inicializar(eTrabajo lista[], int tam);
/**
 * @fn int BuscarLibre(eTrabajo[], int)
 * @brief recorre el array con un for buscando el primer espacio libre que encuentra y devuelve su posicion
 *
 * @param lista array trabajo
 * @param tam tamaño del array
 * @return retorna -1 si salio todo mal o la posicion libre del array
 */
int BuscarLibre(eTrabajo lista[], int tam);
/**
 * @fn int BuscarTrabajoPorId(eTrabajo[], int, int)
 * @brief busca el id ingresado por parametro en el array de trabajo y devuelve la posicion en la que se encuentra
 *
 * @param lista array trabajo
 * @param tam tamaño del array
 * @param id id del trabajo buscado
 * @return retorna -1 si salio todo mal o la posicion donde se encuentra ese trabajo
 */
int BuscarTrabajoPorId(eTrabajo lista[], int tam, int id);


#endif /* TRABAJO_H_ */
