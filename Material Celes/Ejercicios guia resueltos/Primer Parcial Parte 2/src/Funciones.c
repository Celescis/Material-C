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
	printf("6. MOSTRAR servicios con mas trabajos\n");
	printf("7. MOSTRAR servicio con su bicicleta\n");
	printf("8. MOSTRAR cantidad bicicletas rojas\n");
	printf("9. TOTAL en pesos por los servicios prestados\n");
	printf("0. SALIR\n");

	utn_getInt("\nIngrese una opcion: \n","Error, opcion invalida\n",0,9,3,&opciones);

	return opciones;
}

int MenuModificaciones()
{
	int opciones;

	printf("\n\t>-MODIFICAR-<\t\n");
	printf("1. Marca de la bicicleta\n");
	printf("2. Servicio\n");
	printf("0. Volver al menu Principal\n");

	utn_getInt("\nIngrese una opcion para modificar: \n","Error, opcion invalida\n",0,2,3,&opciones);

	return opciones;
}

int AltaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS, eBicicleta bicicletas[], int tamB, int* id)
{
	int isOk=-1;
	int index;

	if(lista!=NULL && tam>0 && listaS!=NULL && tamS>0 && bicicletas!=NULL && tamB>0 && id!=NULL)
	{
		index=BuscarLibre(lista,tam);

		if(index<0)
		{
			printf("No hay espacio libre\n");
		}
		else
		{

			ObtenerId(id);
			lista[index].id=(*id);
			MostrarListaBicicletas(bicicletas,tamB);
			utn_getInt("Ingrese el ID de la bicicleta: \n","Error, no existe ese id\n",25,29,3,&lista[index].idBicicleta);
			MostrarListaServicios(listaS,tamS);
			utn_getInt("Ingrese el ID del servicio: \n","Error, no existe ese id\n",20000,20004,3,&lista[index].idServicio);
			printf("Ingrese fecha de ingreso dd/mm/aaaa: \n");
			utn_getInt("Ingrese dia \n","Error, reingrese\n",1,31,3,&lista[index].fecha.dia);
			utn_getInt("Ingrese mes \n","Error, reingrese\n",1,12,3,&lista[index].fecha.mes);
			utn_getInt("Ingrese año [1970-2021]\n","Error, reingrese [1970-2021]\n",1970,2021,3,&lista[index].fecha.anio);
			lista[index].isEmpty=OCUPADO;

			isOk=0;
		}
	}

	return isOk;
}

int MostrarTrabajoCompleto(eTrabajo unTrabajo, eServicio servicios[], int tamS, eBicicleta bicicletas[], int tamB)
{
	eServicio auxServicio;
	eBicicleta auxBicicleta;
	int isOk=-1;
	//char descripcionS[25];

	if(servicios != NULL && tamS>0 && bicicletas!=NULL && tamB>0)
	{
		//GetDescripcionServicio(servicios,tamS,unTrabajo.idServicio,descripcionS);
		auxBicicleta = AuxiliarBicicleta(bicicletas,tamB,unTrabajo.idBicicleta);
		auxServicio = AuxiliarServicio(servicios,tamS,unTrabajo.idServicio);
		printf("%2d  \t\t  %-10s  \t\t  %2d  \t\t  %2d  \t\t %-10s  \t\t  %02d/%02d/%d\n", unTrabajo.id
																						 , auxBicicleta.marca
																						 , auxBicicleta.rodado
																						 , unTrabajo.idServicio
																						 , auxServicio.descripcion
																						 , unTrabajo.fecha.dia
																						 , unTrabajo.fecha.mes
																						 , unTrabajo.fecha.anio);
		isOk=0;
	}

	return isOk;
}

int MostrarListaTrabajosCompleto(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eBicicleta bicicletas[], int tamB)
{
	int isOk=-1;
	int i;

	if(lista!=NULL && tam>0 && servicios!=NULL && tamS>0 && bicicletas!=NULL && tamB>0)
	{
		printf(" ID  \t\t  MARCA \t\t RODADO \tID SERVICIO \t\t DESCRIPCION \t\t   FECHA \n");
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				MostrarTrabajoCompleto(lista[i],servicios,tamS,bicicletas,tamB);
				isOk=0;
			}
		}
	}

	return isOk;
}

int BajaTrabajo(eTrabajo lista[], int tam,eServicio servicios[], int tamS, eBicicleta bicicletas[], int tamB)
{
	int isOk=-1;
	char respuesta[4];
	int index;
	int id;
	eBicicleta auxBicicleta;

	if(lista != NULL && tam>0 && servicios!=NULL && tamS>0 && bicicletas!=NULL && tamB>0)
	{
		MostrarListaTrabajosCompleto(lista,tam,servicios,tamS,bicicletas,tamB);
		utn_getInt("Ingrese el ID para dar de baja\n","Error, ID invalido\n",1,tam,3,&id);
		index=BuscarTrabajoPorId(lista,tam,id);
		MostrarTrabajoCompleto(lista[index],servicios,tamS,bicicletas,tamB);
		auxBicicleta = AuxiliarBicicleta(bicicletas,tamB,lista[index].idBicicleta);
		utn_getString("\n¿Esta seguro que desea eliminar este trabajo?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);
		if(!(stricmp(respuesta,"si")))
		{
			lista[index].isEmpty=VACIO;
			printf("\nEl trabajo de la bicicleta marca %s , rodado %d , color %s y con ID %d se ha dado de baja correctamente\n",auxBicicleta.marca
																												   	   	   	    ,auxBicicleta.rodado
																																,auxBicicleta.color
																																,lista[index].id);
			isOk=0;
		}
	}

	return isOk;
}

int ModificarTrabajo(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eBicicleta bicicletas[], int tamB)
{
	int isOk=-1;
	char respuesta[4];
	char confirmar[4];
	int index;
	int auxId;
	int auxIdBicicleta;
	int auxIdServicio;

	strcpy(confirmar,"no");

	if(lista!=NULL && tam>0 && servicios!=NULL && tamS>0 && bicicletas!=NULL && tamB>0)
	{
		MostrarListaTrabajosCompleto(lista,tam,servicios,tamS,bicicletas,tamB);
		utn_getInt("Ingrese el ID del trabajo a modificar: \n","Error, ID invalido\n",1,tam,3,&auxId);
		index=BuscarTrabajoPorId(lista, tam, auxId);
		MostrarTrabajoCompleto(lista[index],servicios,tamS,bicicletas,tamB);
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
						MostrarListaBicicletas(bicicletas,tamB);
						utn_getInt("Ingrese la nueva marca\n","Error, nombre invalido\n",25,29,3,&auxIdBicicleta);
						lista[index].idBicicleta=auxIdBicicleta;
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
	}

	return isOk;
}

int TotalPesosServicio(eTrabajo lista[], int tam, eServicio servicios[], int tamS)
{
	eServicio auxServicio;
	int isOk=-1;
	int i;
	float auxPrecio=0;

	if(lista!=NULL && tam>0 && servicios!=NULL && tamS>0)
	{
		for(i=0; i<tam ; i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				auxServicio = AuxiliarServicio(servicios,tamS,lista[i].idServicio);
				auxPrecio += auxServicio.precio;
				isOk=0;
			}
		}

		printf("El total en pesos por los servicios prestados es: $%.2f ",auxPrecio);
	}

	return isOk;
}

int OrdenarTrabajosPorAnioyMarca(eTrabajo lista[], int tam, eBicicleta bicicletas[], int tamB)
{
	int isOk=-1;
	int i;
	int j;
	eTrabajo auxTrabajo;
	char auxMarcaI[25];
	char auxMarcaJ[25];

	if(lista!=NULL && tam>0 && bicicletas!=NULL && tamB>0)
	{
		for(i = 0; i < tam-1; i++)
		{
			GetMarcaBicicleta(bicicletas,tamB,lista[i].idBicicleta,auxMarcaI);

			for(j = i+1; j < tam ; j++)
			{
				GetMarcaBicicleta(bicicletas,tamB,lista[j].idBicicleta,auxMarcaJ);

				if(lista[i].fecha.anio>lista[j].fecha.anio)
				{
					auxTrabajo = lista[i];
					lista[i] = lista[j];
					lista[j] = auxTrabajo;
					isOk = 0;
				}
				else
				{
					if(lista[i].fecha.anio==lista[j].fecha.anio)
					{
						if((strcmp(auxMarcaI,auxMarcaJ))>0)
						{
							auxTrabajo = lista[i];
							lista[i] = lista[j];
							lista[j] = auxTrabajo;
							isOk = 0;
						}
					}
				}
			}
		}
	}

	return isOk;
}

int ServicioConMasTrabajos(eServicio servicios[], int tamS, eTrabajo lista[], int tam)
{
	int isOk=-1;
	int contador[tamS];
	int cantidad=0;
	int id;
	int index;
	char descripcion[25];
	eServicio auxServicio[tamS];
	int i;
	int j;
	int c;

	if(servicios!=NULL && tamS>0 && lista!=NULL && tam>0)
	{
		for(i=0; i<tamS ;i++)
		{
			contador[i]=0;
			index=i;
			auxServicio[i].id=servicios[i].id;
			for(j=0;j<tam;j++)
			{
				if((lista[j].isEmpty==OCUPADO) && (lista[j].idServicio==auxServicio[i].id))
				{
					contador[index]++;
				}
			}
		}

		for(c=0;c<tamS;c++)
		{
			if(c==0 || (cantidad<contador[c]))
			{
				cantidad=contador[c];
				id=auxServicio[c].id;
				isOk=0;
			}
		}
		GetDescripcionServicio(servicios,tamS,id,descripcion);
		printf("Id del servicio con mayor cantidad de trabajos: %d\n"
			   "Descripcion: %s\n"
				"Cantidad de trabajos: %d\n",id
											,descripcion
											,cantidad);
	}

	return isOk;
}

int ListadoServiciosPorBicicleta(eServicio servicios[], int tamS, eTrabajo lista[], int tam, eBicicleta bicicletas[], int tamB)
{
	int isOk=-1;
	int i;
	int j;
	char descripcion[25];
	char auxMarca[25];
	int index;
	int flag;

	if(servicios!=NULL && tamS>0 && lista!=NULL && tam>0 && bicicletas!=NULL && tam>0)
	{
		for(i=0; i<tamS ;i++)
		{
			GetDescripcionServicio(servicios,tamS,servicios[i].id,descripcion);
			printf("Servicio: %s \n",descripcion);
			flag=0;
			for(j=0; j<tam ;j++)
			{
				if((lista[j].isEmpty==OCUPADO) && (lista[j].idServicio==servicios[i].id))
				{
					GetMarcaBicicleta(bicicletas,tamB,lista[j].idBicicleta,auxMarca);
					index = BuscarBicicletaPorId(bicicletas,tamB,lista[j].idBicicleta);
					printf("ID: %d, Marca: %s, Rodado: %d, Color: %s\n",lista[j].idBicicleta
																	   ,auxMarca
																	   ,bicicletas[index].rodado
																	   ,bicicletas[index].color);
					flag=1;
					isOk=0;
				}
			}
			if(flag==0)
			{
				printf("\nNo hay bicicletas para este servicio\n");
			}
			printf("\n");
		}
	}

	return isOk;
}

int CantidadBicisRojas(eBicicleta bicicletas[], int tamB, eTrabajo lista[], int tam)
{
	int isOk=-1;
	int contador=0;
	int i;
	int index;

	if(bicicletas!=NULL && tamB>0 && lista!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				index = BuscarBicicletaPorId(bicicletas,tamB,lista[i].idBicicleta);
				if(!(stricmp(bicicletas[index].color,"rojo")))
				{
					contador++;
					isOk=0;
				}
			}
		}
		printf("La cantidad de bicicletas rojas es: %d",contador);
	}

	return isOk;
}













