/*
 * nacionalidad.h
 *
 *  Created on: 9 may. 2021
 *      Author: celes
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_
#define N 3
#include "informes.h"

typedef struct
{
	int idNacionalidad;
	char descripcionNacionalidad[20];

}eNacionalidad;

eNacionalidad unaNacionalidad[N]=
			{
					{1,"EEUU"},
					{2,"CHINA"},
					{3,"OTRO"}
			};

int GetDescripcionN(eNacionalidad[],int,int,char[]);
int GetCodigoN(eNacionalidad[],int,char[],int*);

#endif /* NACIONALIDAD_H_ */
