/*
 * Funciones.c
 *
 *  Created on: 13 may. 2021
 *      Author: celes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"

int Menu()
{
	int opciones;

	printf("\n\t>-ABM TRABAJOS-<\t\n");
	printf("1. ALTA\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. MOSTRAR lista trabajos\n");
	printf("5. MOSTRAR lista servicios\n");
	printf("6. TOTAL en pesos por los servicios prestados\n");
	printf("0. SALIR\n");

	utn_getInt("\nIngrese una opcion: \n","Error, opcion invalida\n",0,6,3,&opciones);

	return opciones;
}

int MenuModificaciones()
{
	int opciones;

	printf("\n\t>-MODIFICAR-<\t\n");
	printf("1. Marca de la bicicleta\n");
	printf("2. Servicio\n");
	printf("0. SALIR\n");

	utn_getInt("\nIngrese una opcion para modificar: \n","Error, opcion invalida\n",0,2,3,&opciones);

	return opciones;
}

int AltaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS, int* id)
{
	int isOk=-1;
	int index;

	if(lista!=NULL && tam>0 && listaS!=NULL && tamS>0)
	{
		index=BuscarLibre(lista,tam);

		if(index<0)
		{
			printf("No hay espacio libre\n");
		}
		else
		{
			/*
			ObtenerId(id);
			lista[index].id=*id;
			utn_getString("Ingrese la marca: \n","Error, reingrese\n",25,3,lista[index].marcaBicicleta);
			SizeString(lista[index].marcaBicicleta);
			utn_getInt("Ingrese el rodado: \n","Error, reingrese\n",12,29,3,&lista[index].rodadoBicicleta);
			MostrarListaServicios(listaS,tamS);
			utn_getInt("Ingrese el ID del servicio: \n","Error, no existe ese id\n",20000,20004,3,&lista[index].idServicio);
			printf("Ingrese fecha de ingreso dd/mm/aaaa: \n");
			utn_getInt("Ingrese dia \n","Error, reingrese\n",1,31,3,&lista[index].fecha.dia);
			utn_getInt("Ingrese mes \n","Error, reingrese\n",1,12,3,&lista[index].fecha.mes);
			utn_getInt("Ingrese año [1970-2021]\n","Error, reingrese [1970-2021]\n",1970,2021,3,&lista[index].fecha.anio);
			lista[index].isEmpty=OCUPADO;
*/
			isOk=0;
		}
	}

	return isOk;
}

int MostrarTrabajoConServicio(eTrabajo unTrabajo, eServicio servicios[], int tamS)
{
	eServicio auxServicio;
	int isOk=-1;
	//char descripcionS[25];

	if(servicios != NULL && tamS>0)
	{
		//GetDescripcionServicio(servicios,tamS,unTrabajo.idServicio,descripcionS);

		auxServicio = BuscarServicioPorId(servicios,tamS,unTrabajo.idServicio);
		printf("%2d  \t\t  %-10s  \t\t  %2d  \t\t  %2d  \t\t %-10s  \t\t  %02d/%02d/%d\n", unTrabajo.id
																						 , unTrabajo.marcaBicicleta
																						 , unTrabajo.rodadoBicicleta
																						 , unTrabajo.idServicio
																						 , auxServicio.descripcion
																						 , unTrabajo.fecha.dia
																						 , unTrabajo.fecha.mes
																						 , unTrabajo.fecha.anio);
		isOk=0;
	}

	return isOk;
}

int MostrarListaTrabajosConServicio(eTrabajo lista[], int tam, eServicio servicios[], int tamS)
{
	int isOk=-1;
	int i;

	if(lista!=NULL && tam>0 && servicios!=NULL && tamS>0)
	{
		printf(" ID  \t\t  MARCA \t\t RODADO \tID SERVICIO \t\t DESCRIPCION \t\t   FECHA \n");
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				MostrarTrabajoConServicio(lista[i],servicios,tamS);
				isOk=0;
			}
		}
	}

	return isOk;
}

int BajaTrabajo(eTrabajo lista[], int tam,eServicio servicios[], int tamS)
{
	int isOk=-1;
	char respuesta[4];
	int index;
	int id;

	if(lista != NULL && tam>0)
	{
		MostrarListaTrabajosConServicio(lista,tam,servicios,tamS);
		utn_getInt("Ingrese el ID para dar de baja\n","Error, ID invalido\n",1,tam,3,&id);
		index=BuscarTrabajoPorId(lista,tam,id);
		MostrarTrabajoConServicio(lista[index],servicios,tamS);
		utn_getString("\n¿Esta seguro que desea eliminar este trabajo?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);
		if(!(stricmp(respuesta,"si")))
		{
			lista[index].isEmpty=VACIO;
			printf("\nEl trabajo de la bicicleta marca %s y rodado %d con ID %d se ha dado de baja correctamente\n",lista[index].marcaBicicleta
																												   ,lista[index].rodadoBicicleta
																												   ,lista[index].id);
			isOk=0;
		}
	}

	return isOk;
}

int ModificarTrabajo(eTrabajo lista[], int tam, eServicio servicios[], int tamS)
{
	int isOk=-1;
	char respuesta[4];
	char confirmar[4];
	int index;
	int auxId;
	char auxMarca[25];
	int auxIdServicio;

	strcpy(confirmar,"no");

	MostrarListaTrabajosConServicio(lista,tam,servicios,tamS);
	utn_getInt("Ingrese el ID del trabajo a modificar: \n","Error, ID invalido\n",1,tam,3,&auxId);
	index=BuscarTrabajoPorId(lista, tam, auxId);
	MostrarTrabajoConServicio(lista[index],servicios,tamS);
	utn_getString("¿Esta seguro que desea modificar este trabajo? [si/no]\n","Error, ingrese [si/no]\n",4,3,respuesta);

	if(!(stricmp(respuesta,"si")))
	{
		do
		{
			switch(MenuModificaciones())
			{
				case 0:
					utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
					break;
				case 1:
					printf("\t****MODIFICAR MARCA****\t\n");
					utn_getString("Ingrese la nueva marca\n","Error, nombre invalido\n",25,3,auxMarca);
					SizeString(auxMarca);
					strcpy(lista[index].marcaBicicleta,auxMarca);
					break;
				case 2:
					printf("\t****MODIFICAR SERVICIO****\t\n");
					MostrarListaServicios(servicios,tamS);
					utn_getInt("Ingrese el ID del nuevo servicio\n","Error, id invalido\n",20000,20004,3,&auxIdServicio);
					lista[index].idServicio=auxIdServicio;
					break;
			}
		}while(stricmp(confirmar,"si"));

		isOk=0;
	}
	else
	{
		printf("No se realizo ningun cambio\n");
	}

	return isOk;
}

int TotalPesosServicio(eTrabajo lista[], int tam, eServicio servicios[], int tamS)
{
	eServicio auxServicio;
	int isOk=-1;
	int i;
	float auxPrecio=0;

	for(i=0; i<tam ; i++)
	{
		if(lista[i].isEmpty==OCUPADO)
		{
			auxServicio = BuscarServicioPorId(servicios,tamS,lista[i].idServicio);
			auxPrecio += auxServicio.precio;
			isOk=0;
		}
	}

	printf("El total en pesos por los servicios prestados es: $%.2f ",auxPrecio);

	return isOk;
}
