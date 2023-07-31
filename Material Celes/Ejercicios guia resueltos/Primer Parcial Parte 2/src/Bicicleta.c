/*
 * biblioteca.c
 *
 *  Created on: 20 may. 2021
 *      Author: celes
 */
#include "Bicicleta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utn.h"

void HardcodeoBicicleta(eBicicleta bicicletas[], int* idBicicleta)
{
	char auxMarca[B][25]={"Vairo","BMX","Snake","Kolke","Ambu"};
	int auxRodado[B]={12,14,16,18,20};
	char auxColor[B][25]={"Azul","Rosa","Rojo","Negro","Naranja"};
	int i;

	for(i=0;i<B;i++)
	{
		bicicletas[i].id=(*idBicicleta);
		strcpy(bicicletas[i].marca,auxMarca[i]);
		bicicletas[i].rodado=auxRodado[i];
		strcpy(bicicletas[i].color,auxColor[i]);
		(*idBicicleta)++;
	}
}

void MostrarBicicleta(eBicicleta bicicletas)
{
	printf( "%2d  \t\t  %-10s  \t\t  %2d  \t\t  %-10s\n", bicicletas.id
														, bicicletas.marca
														, bicicletas.rodado
														, bicicletas.color);

}

int MostrarListaBicicletas(eBicicleta bicicletas[], int tam)
{
	int isOk=-1;
	int i;

	if(bicicletas!=NULL && tam>0)
	{
		printf(" ID  \t\t  MARCA \t\t RODADO \t\t COLOR \n");
		for(i=0;i<tam;i++)
		{
			MostrarBicicleta(bicicletas[i]);
			isOk=0;
		}
	}

	return isOk;
}

eBicicleta AuxiliarBicicleta(eBicicleta bicicletas[], int tam, int id)
{
	eBicicleta auxBicicleta;
	int i;

	if(bicicletas!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(bicicletas[i].id==id)
			{
				auxBicicleta = bicicletas[i];
				break;
			}
		}
	}

	return auxBicicleta;
}

int GetMarcaBicicleta(eBicicleta bicicletas[], int tamB, int buscarCodigo, char marca[])
{
	int isOk=-1;
	int i;

	if(bicicletas!=NULL && tamB>0 && marca!=NULL)
	{
		for(i=0;i<tamB;i++)
		{
			if(bicicletas[i].id==buscarCodigo)
			{
				strcpy(marca,bicicletas[i].marca);
				isOk=0;
			}
		}
	}

	return isOk;
}

int BuscarBicicletaPorId(eBicicleta bicicletas[], int tam, int id)
{
	int index=-1;
	int i;

	if(bicicletas!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(bicicletas[i].id==id)
			{
				index=i;
				break;
			}
		}
	}

	return index;
}
