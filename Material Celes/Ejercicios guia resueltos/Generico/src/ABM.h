#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EGEN_H_
#define EGEN_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define VACIO 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct
{
	int idGen;
	int isEmpty;
} eGen;
//***

/** INICIO CABECERAS DE FUNCION*/
void Inicializar(eGen array[], int TAM);
int ObtenerID(void);
int BuscarLibre(eGen array[], int TAM);
int BuscarPorID(eGen array[], int TAM, int ID);
void MostrarUno(eGen Gen);
int MostrarTodos(eGen array[], int TAM);
int MostrarBajas(eGen array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int Ordenar(eGen array[], int TAM, int criterio);

//ABM
eGen CargarDatos(void);
eGen ModificarUno(eGen Gen);
int Alta(eGen array[], int TAM);
int Baja(eGen array[], int TAM);
int Modificar(eGen array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
