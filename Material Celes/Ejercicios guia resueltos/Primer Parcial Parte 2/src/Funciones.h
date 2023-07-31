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
int AltaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS, eBicicleta bicicletas[], int tamB, int* id);
int MostrarTrabajoCompleto(eTrabajo unTrabajo, eServicio servicios[], int tamS, eBicicleta bicicletas[], int tamB);
int MostrarListaTrabajosCompleto(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eBicicleta bicicletas[], int tamB);
int BajaTrabajo(eTrabajo lista[], int tam,eServicio servicios[], int tamS, eBicicleta bicicletas[], int tamB);
int ModificarTrabajo(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eBicicleta bicicletas[], int tamB);
int TotalPesosServicio(eTrabajo lista[], int tam, eServicio servicios[], int tamS);
int OrdenarTrabajosPorAnioyMarca(eTrabajo lista[], int tam, eBicicleta bicicletas[], int tamB);
int ServicioConMasTrabajos(eServicio servicios[], int tamS, eTrabajo lista[], int tam);
int ListadoServiciosPorBicicleta(eServicio servicios[], int tamS, eTrabajo lista[], int tam, eBicicleta bicicletas[], int tamB);
int CantidadBicisRojas(eBicicleta bicicletas[], int tamB, eTrabajo lista[], int tam);




#endif /* FUNCIONES_H_ */
