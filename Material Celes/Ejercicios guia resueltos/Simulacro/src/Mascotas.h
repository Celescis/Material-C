/*
 * Mascotas.h
 *
 *  Created on: 20 may. 2021
 *      Author: celes
 */

#ifndef MASCOTAS_H_
#define MASCOTAS_H_
#define M 1000
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int id;
	char nombreMascota[25];
	int edad;
	char raza[25];
	int isEmpty;
}eMascotas;

void HardcodeoMascotas(eMascotas mascotas[], int* idMascotas);
void MostrarMascota(eMascotas mascotas);
int MostrarListaMascotas(eMascotas mascotas[], int tam);
eMascotas AuxiliarMascota(eMascotas mascotas[], int tam, int id);
int GetNombreMascota(eMascotas mascotas[], int tam, int buscarCodigo, char nombre[]);
int BuscarMascotaPorId(eMascotas mascotas[], int tam, int id);
int AltaDataMascotas(eMascotas listaM[], int tamM, int* id);
void InicializarMascotas(eMascotas mascotas[], int tam);
int BuscarLibreMascotas(eMascotas mascotas[], int tam);
int BajaMascotas(eMascotas mascotas[], int tamM);







#endif /* MASCOTAS_H_ */
