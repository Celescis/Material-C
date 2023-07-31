/*
 * Nacionalidad.h
 *
 *  Created on: 4 may. 2021
 *      Author: celes
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_
#define N 3


typedef struct
{
	int idNacionalidad;
	char descripcionNacionalidad[20];

}eNacionalidad;

void HardcodearNacionalidad(eNacionalidad[]);
void MostrarUnaNacionalidad(eNacionalidad unaNacionalidad);
void MostrarListaNacionalidad(eNacionalidad listaN[],int tamN);
int GetDescripcionN(eNacionalidad[],int,int,char[]);
int GetCodigoN(eNacionalidad[],int,char[],int*);


#endif /* NACIONALIDAD_H_ */
