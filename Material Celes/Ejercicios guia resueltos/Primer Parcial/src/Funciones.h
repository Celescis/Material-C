/*
 * Funciones.h
 *
 *  Created on: 13 may. 2021
 *      Author: celes
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include "Bicicleta.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Utn.h"


int Menu();
int MenuModificaciones();
int AltaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS, int* id);
int MostrarTrabajoConServicio(eTrabajo unTrabajo, eServicio servicios[], int tamS);
int MostrarListaTrabajosConServicio(eTrabajo lista[], int tam, eServicio servicios[], int tamS);
int BajaTrabajo(eTrabajo lista[], int tam,eServicio servicios[], int tamS);
int ModificarTrabajo(eTrabajo lista[], int tam, eServicio servicios[], int tamS);
int TotalPesosServicio(eTrabajo lista[], int tam, eServicio servicios[], int tamS);







#endif /* FUNCIONES_H_ */
