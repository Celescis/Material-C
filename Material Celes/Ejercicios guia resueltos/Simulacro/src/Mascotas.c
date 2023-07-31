/*
 * Mascotas.c
 *
 *  Created on: 20 may. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Mascotas.h"
#include "Utn.h"

void ObtenerIdMascotas (int* idMascotas)
{
	*idMascotas+=1;
}

void HardcodeoMascotas(eMascotas lista[], int* idMascotas)
{
	char auxNombre[5][25]={"Pepe","Kira","Gero","Rufus","Michi"};
	int auxEdad[5]={2,4,5,6,10};
	char auxRaza[5][25]={"Peluda","Atigrado","Bulldog","Doberman","Pelado"};
	int i;

	for(i=0;i<5;i++)
	{
		ObtenerIdMascotas(idMascotas);
		lista[i].id=(*idMascotas);
		strcpy(lista[i].nombreMascota,auxNombre[i]);
		lista[i].edad=auxEdad[i];
		strcpy(lista[i].raza,auxRaza[i]);
		lista[i].isEmpty=OCUPADO;
	}
}

void MostrarMascota(eMascotas mascotas)
{
	printf( "%2d  \t\t  %-10s  \t\t  %2d  \t\t  %-10s\n", mascotas.id
														, mascotas.nombreMascota
														, mascotas.edad
														, mascotas.raza);

}

int MostrarListaMascotas(eMascotas mascotas[], int tam)
{
	int isOk=-1;
	int i;

	if(mascotas!=NULL && tam>0)
	{
		printf(" ID  \t\t  NOMBRE \t\t EDAD \t\t RAZA \n");
		for(i=0;i<tam;i++)
		{
			if(mascotas[i].isEmpty==OCUPADO)
			{
				MostrarMascota(mascotas[i]);
				isOk=0;
			}
		}
	}

	return isOk;
}

eMascotas AuxiliarMascota(eMascotas mascotas[], int tam, int id)
{
	eMascotas auxMascota;
	int i;

	if(mascotas!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(mascotas[i].id==id)
			{
				auxMascota = mascotas[i];
				break;
			}
		}
	}

	return auxMascota;
}

int BuscarMascotaPorId(eMascotas mascotas[], int tam, int id)
{
	int index=-1;
	int i;

	if(mascotas!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(mascotas[i].isEmpty==OCUPADO && mascotas[i].id==id)
			{
				index=i;
				break;
			}
		}
	}

	return index;
}

void InicializarMascotas(eMascotas mascotas[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		mascotas[i].isEmpty=VACIO;
	}
}

int BuscarLibreMascotas(eMascotas mascotas[], int tam)
{
	int i;
	int index=-1;

	if(mascotas!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(mascotas[i].isEmpty==VACIO)
			{
				index=i;
				break;
			}
		}
	}

	return index;
}

int GetNombreMascota(eMascotas mascotas[], int tam, int buscarCodigo, char nombre[])
{
	int isOk=-1;
	int i;

	if(mascotas!=NULL && tam>0 && nombre!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(mascotas[i].id==buscarCodigo)
			{
				strcpy(nombre,mascotas[i].nombreMascota);
				isOk=0;
			}
		}
	}

	return isOk;
}

int AltaDataMascotas(eMascotas listaM[], int tamM, int* id)
{
	int isOk=-1;
	int index;

	if(listaM!=NULL && tamM>0)
	{
		index = BuscarLibreMascotas(listaM,tamM);

		if(index<0)
		{
			printf("No hay espacio libre\n");
		}
		else
		{
			ObtenerIdMascotas(id);
			listaM[index].id=(*id);
			utn_getString("Ingrese el nombre de la mascota: \n","Error, reingrese\n",25,3,listaM[index].nombreMascota);
			utn_getInt("Ingrese la edad: \n","Error, reingrese\n",1,100,3,&listaM[index].edad);
			utn_getString("Ingrese la raza:\n","Error, reingrese\n",25,3,listaM[index].raza);
			listaM[index].isEmpty=OCUPADO;

			isOk=0;
		}
	}

	return isOk;
}

int BajaMascotas(eMascotas mascotas[], int tamM)
{
	int isOk=-1;
	char respuesta[4];
	int index;
	eMascotas auxMascota;
	int id;

	if(mascotas != NULL && tamM>0)
	{
		MostrarListaMascotas(mascotas,tamM);
		utn_getInt("Ingrese el ID para dar de baja\n","Error, ID invalido\n",15,tamM,3,&id);
		auxMascota = AuxiliarMascota(mascotas,tamM,id);
		MostrarMascota(auxMascota);
		index= BuscarMascotaPorId(mascotas,tamM,auxMascota.id);
		utn_getString("\n¿Esta seguro que desea eliminarlo?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);
		if(!(stricmp(respuesta,"si")))
		{
			mascotas[index].isEmpty=VACIO;
			printf("\nLa mascota %s con ID %d se ha dado de baja correctamente\n", auxMascota.nombreMascota
																				 , auxMascota.id);
			isOk=0;
		}
	}

	return isOk;
}
