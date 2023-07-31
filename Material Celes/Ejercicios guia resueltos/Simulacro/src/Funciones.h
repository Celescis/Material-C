/*
 * Funciones.h
 *
 *  Created on: 12 may. 2021
 *      Author: celes
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#define REALIZADO 1
#define NO_REALIZADO 0
#include "Servicio.h"
#include "Trabajo.h"
#include "Mascotas.h"
#include "Utn.h"

int Menu();
int MenuAltas();
int MenuModificaciones();
int MenuBajas();
int AltaData(eTrabajo lista[], int tam, eServicio listaS[], int tamS, eMascotas listaM[], int tamM, int* id);
int MostrarTrabajoConServicioyMascota(eTrabajo unTrabajo, eServicio servicios[], eMascotas mascotas[], int tamS, int tamM);
int MostrarListaTrabajosConServicioyMascota(eTrabajo lista[], int tam, eServicio servicios[], eMascotas mascotas[], int tamS, int tamM);
int BajaTrabajo(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eMascotas mascotas[], int tamM);
int ModificarTrabajo(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eMascotas mascotas[], int tamM);
int TotalPesosServicio(eTrabajo lista[], int tam, eServicio servicios[], int tamS);
int Altas(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eMascotas mascotas[], int tamM, int* idTrabajo, int* idMascota);
int Bajas(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eMascotas mascotas[], int tamM);
int Modificaciones(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eMascotas mascotas[], int tamM);
int OrdenarTrabajosNombreMascota(eTrabajo lista[], int tam, eMascotas mascotas[], int tamM);
int ServicioConMasTrabajos(eServicio servicios[], int tamS, eTrabajo lista[], int tam);
int ListadoServiciosPorNombre(eServicio servicios[], int tamS, eTrabajo lista[], int tam, eMascotas mascotas[], int tamM);

#endif /* FUNCIONES_H_ */
