/*
 * biblioteca.h
 *
 *  Created on: 20 may. 2021
 *      Author: celes
 */

#ifndef BICICLETA_H_
#define BICICLETA_H_
#define B 5
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int id;
	char marca[25];
	int rodado;
	char color[25];
}eBicicleta;

void HardcodeoBicicleta(eBicicleta bicicletas[], int* idBicicleta);
void MostrarBicicleta(eBicicleta bicicletas);
int MostrarListaBicicletas(eBicicleta bicicletas[], int tam);
eBicicleta AuxiliarBicicleta(eBicicleta bicicletas[], int tam, int id);
int GetMarcaBicicleta(eBicicleta bicicletas[], int tamB, int buscarCodigo, char marca[]);
int BuscarBicicletaPorId(eBicicleta bicicletas[], int tam, int id);

#endif /* BICICLETA_H_ */
