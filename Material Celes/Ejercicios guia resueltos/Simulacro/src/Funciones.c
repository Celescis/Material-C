 /*
 * Funciones.c
 *
 *  Created on: 12 may. 2021
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

	printf("\n\t>ABM TRABAJOS<\t\n");
	printf("1. ALTA\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. MOSTRAR lista trabajos\n");
	printf("5. MOSTRAR lista servicios\n");
	printf("6. MOSTRAR lista mascotas\n");
	printf("7. TOTAL en pesos por los servicios prestados\n");
	printf("0. SALIR\n");

	utn_getInt("\nIngrese una opcion: \n","Error, opcion invalida\n",0,7,3,&opciones);

	return opciones;
}
int MenuAltas()
{
	int opciones;

	printf("1. Nuevo trabajo\n");
	printf("2. Nueva mascota\n");
	printf("0. Menu Principal\n");

	utn_getInt("\nIngrese una opcion para dar de alta: \n","Error, opcion invalida\n",0,2,3,&opciones);

	return opciones;
}
int MenuBajas()
{
	int opciones;

	printf("1. Baja trabajo\n");
	printf("2. Baja mascota\n");
	printf("0. Menu Principal\n");

	utn_getInt("\nIngrese una opcion para dar de baja: \n","Error, opcion invalida\n",0,2,3,&opciones);

	return opciones;
}
int MenuModificaciones()
{
	int opciones;

	printf("\n\t>MODIFICAR<\t\n");
	printf("1. Mascota\n");
	printf("2. Servicio\n");
	printf("0. Menu Principal\n");

	utn_getInt("\nIngrese una opcion para modificar: \n","Error, opcion invalida\n",0,2,3,&opciones);

	return opciones;
}

int AltaData(eTrabajo lista[], int tam, eServicio listaS[], int tamS, eMascotas listaM[], int tamM, int* id)
{
	int isOk=-1;
	int index;

	if(lista!=NULL && tam>0 && listaS!=NULL && tamS>0 && listaM!=NULL && tamM>0)
	{
		index = BuscarLibre(lista,tam);

		if(index<0)
		{
			printf("No hay espacio libre\n");
		}
		else
		{
			ObtenerId(id);
			lista[index].id=(*id);
			MostrarListaMascotas(listaM,tamM);
			utn_getInt("Ingrese el ID de la mascota: \n","Error, reingrese\n",15,1500,3,&lista[index].idMascota);
			MostrarListaServicios(listaS,tamS);
			utn_getInt("Ingrese el ID del servicio: \n","Error, reingrese\n",20000,20002,3,&lista[index].idServicio);
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

int BajaTrabajo(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eMascotas mascotas[], int tamM)
{
	int isOk=-1;
	char respuesta[4];
	int index;
	int id;
	eMascotas auxMascota;

	if(lista != NULL && tam>0)
	{
		MostrarListaTrabajosConServicioyMascota(lista,tam,servicios,mascotas,tamS,tamM);
		utn_getInt("Ingrese el ID para dar de baja\n","Error, ID invalido\n",1,tam,3,&id);
		index=BuscarTrabajoPorId(lista,tam,id);
		MostrarTrabajoConServicioyMascota(lista[index],servicios,mascotas,tamS,tamM);
		utn_getString("\n¿Esta seguro que desea eliminar este trabajo?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);
		auxMascota = AuxiliarMascota(mascotas,tamM,lista[index].idMascota);
		if(!(stricmp(respuesta,"si")))
		{
			lista[index].isEmpty=VACIO;
			printf("\nEl trabajo realizado a la mascota %s con ID %d se ha dado de baja correctamente\n", auxMascota.nombreMascota
																									    , auxMascota.id);
			isOk=0;
		}
	}

	return isOk;
}

int MostrarTrabajoConServicioyMascota(eTrabajo unTrabajo, eServicio servicios[], eMascotas mascotas[], int tamS, int tamM)
{
	int isOk=-1;
	char descripcionS[25];
	eMascotas auxMascota;

	if(servicios != NULL && tamS>0)
	{
		GetDescripcionServicio(servicios,tamS,unTrabajo.idServicio,descripcionS);
		auxMascota = AuxiliarMascota(mascotas,tamM,unTrabajo.idMascota);
		printf("%2d  \t\t  %2d  \t\t  %20s \t\t  %2d  \t\t %-10s  \t\t %02d/%02d/%d\n", unTrabajo.id
				                    			 	  	   	   	    					 , unTrabajo.idMascota
			   	   	   	   	   	   	  	  	  	  	  	  	  	  	  	  	  	  	  	 , auxMascota.nombreMascota
																						 , unTrabajo.idServicio
																						 , descripcionS
																						 , unTrabajo.fecha.dia
																						 , unTrabajo.fecha.mes
																						 , unTrabajo.fecha.anio);
		isOk=0;
	}

	return isOk;
}

int MostrarListaTrabajosConServicioyMascota(eTrabajo lista[], int tam, eServicio servicios[], eMascotas mascotas[], int tamS, int tamM)
{
	int isOk=-1;
	int i;

	if(lista!=NULL && tam>0 && servicios!=NULL && tamS>0)
	{
		printf(" ID \t\t ID MASCOTA \t\t\t NOMBRE \t ID SERVICIO \t\t DESCRIPCION \t\t\t FECHA \n");
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				MostrarTrabajoConServicioyMascota(lista[i],servicios,mascotas,tamS,tamM);
				isOk=0;
			}
		}
	}

	return isOk;
}

int ModificarTrabajo(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eMascotas mascotas[], int tamM)
{
	int isOk=-1;
	char respuesta[4];
	char confirmar[4];
	int index;
	int auxId;
	int auxIdServicio;
	int auxIdMascota;

	strcpy(confirmar,"no");

	MostrarListaTrabajosConServicioyMascota(lista,tam,servicios,mascotas,tamS,tamM);
	utn_getInt("Ingrese el ID del trabajo a modificar: \n","Error, ID invalido\n",1,tam,3,&auxId);
	index = BuscarTrabajoPorId(lista, tam, auxId);
	MostrarTrabajoConServicioyMascota(lista[index],servicios,mascotas,tamS,tamM);
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
					printf("\t****MODIFICAR NOMBRE****\t\n");
					utn_getInt("Ingrese el nuevo ID de la mascota\n","Error, nombre invalido\n",15,19,3,&auxIdMascota);
					lista[index].idMascota=auxIdMascota;
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
	int isOk=-1;
	int i;
	int j;
	float auxPrecio;

	for(i=0; i<tam-1 ; i++)
	{
		for(j=i+1; j<tamS ; j++)
		{
			if((lista[i].isEmpty==OCUPADO) && (lista[i].idServicio==servicios[j].id))
			{
				auxPrecio += servicios[j].precio;
				isOk=0;
			}
		}
	}

	printf("El total en pesos por los servicios prestados es: $%.2f ",auxPrecio);

	return isOk;
}

int Altas(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eMascotas mascotas[], int tamM, int* idTrabajo, int* idMascota)
{
	int isOk=-1;
	char salida[4];
	int cantidad;
	int i;

	strcpy(salida,"no");

	switch(MenuAltas())
	{
		case 0:
			utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,salida);
			break;
		case 1:
			utn_getInt("\n¿Cuantos trabajos desea dar de alta?\n","\nError, cantidad invalida\n",1,1000,3,&cantidad);
			i=0;
			do
			{
				if(!(AltaData(lista,tam,servicios,tamS,mascotas,tamM,idTrabajo)))
				{
					isOk=0;
				}
				else
				{
					isOk=-1;
				}
				i++;
			}while(cantidad!=i);
			break;
		case 2:
			utn_getInt("\n¿Cuantas mascotas desea dar de alta?\n","\nError, cantidad invalida\n",1,1000,3,&cantidad);
			i=0;
			do
			{
				if(!(AltaDataMascotas(mascotas,tamM,idMascota)))
				{
					isOk=0;
				}
				else
				{
					isOk=-1;
				}
				i++;
			}while(cantidad!=i);
			break;
	}

	return isOk;
}

int Bajas(eTrabajo lista[], int tam, eServicio servicios[], int tamS, eMascotas mascotas[], int tamM)
{
	int isOk=-1;
	char salida[4];
	int cantidad;
	int i;

	strcpy(salida,"no");

	switch(MenuBajas())
	{
		case 0:
			utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,salida);
			break;
		case 1:
			utn_getInt("\n¿Cuantos trabajos desea dar de baja?\n","\nError, cantidad invalida\n",1,1000,3,&cantidad);
			i=0;
			do
			{
				if(!(BajaTrabajo(lista,tam,servicios,tamS,mascotas,tamM)))
				{
					isOk=0;
				}
				else
				{
					isOk=-1;
				}
				i++;
			}while(cantidad!=i);
			break;
		case 2:
			utn_getInt("\n¿Cuantas mascotas desea dar de baja?\n","\nError, cantidad invalida\n",1,1000,3,&cantidad);
			i=0;
			do
			{
				if(!(BajaMascotas(mascotas,tamM)))
				{
					isOk=0;
				}
				else
				{
					isOk=-1;
				}
				i++;
			}while(cantidad!=i);
			break;
	}

	return isOk;
}
//Listado de todos los trabajos ordenados por nombre de mascota.
int OrdenarTrabajosNombreMascota(eTrabajo lista[], int tam, eMascotas mascotas[], int tamM)
{
	int isOk=-1;
	int i;
	int j;
	eTrabajo auxTrabajo;
	char auxNombreI[25];
	char auxNombreJ[25];


	if(lista != NULL && tam>0 && mascotas!=NULL && tamM>0)
	{
		for(i=0; i<tam-1; i++)
		{
			GetNombreMascota(mascotas,tam,lista[i].idMascota,auxNombreI);
			for(j=i+1; j<tam; j++)
			{
				GetNombreMascota(mascotas,tam,lista[j].idMascota,auxNombreJ);
				if(lista[i].isEmpty==OCUPADO && lista[j].isEmpty==OCUPADO)
				{
					if(strcmp(auxNombreI,auxNombreJ)>0 || (!(strcmp(auxNombreI,auxNombreJ)) && (lista[i].id>lista[j].id)))
					{
						auxTrabajo = lista[i];
						lista[i] = lista[j];
						lista[j] = auxTrabajo;
						isOk=0;
					}
				}
			}
		}
	}

	return isOk;
}
//H. El o los servicios con más trabajos realizados.
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
		}
	}
	GetDescripcionServicio(servicios,tamS,id,descripcion);
	printf("Cantidad mayor %d "
		   "Id del servicio %d\n"
		   "Descripcion servicio %s\n",cantidad
		   	   	   	   	   	   	   	  ,id
									  ,descripcion);


	return isOk;
}

int ListadoServiciosPorNombre(eServicio servicios[], int tamS, eTrabajo lista[], int tam, eMascotas mascotas[], int tamM)
{
	int isOk=-1;
	int i;
	int j;
	char descripcion[25];
	char nombre[25];
	int flag;

	for(i=0;i<tamS;i++)
	{
		GetDescripcionServicio(servicios,tamS,servicios[i].id,descripcion);
		flag=0;
		printf("Servicio: %s \n",descripcion);
		for(j=0;j<tam;j++)
		{
			if((lista[j].isEmpty==OCUPADO) && (lista[j].idServicio==servicios[i].id))
			{
				GetNombreMascota(mascotas,tamM,lista[j].idMascota,nombre);
				printf(" %s ,",nombre);
				flag=1;
			}
		}
		printf("\n");
		if(flag==0)
		{
			printf("No hay mascotas para este servicio ");
		}
	}

	return isOk;
}









