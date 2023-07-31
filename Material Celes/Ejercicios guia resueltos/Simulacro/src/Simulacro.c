/*
 ============================================================================
 Name        : Simulacro.c
 Author      : Celeste Cisternas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

int main(void)
{
	setbuf(stdout,NULL);
	char confirmar[4];
	int flag;
	int idTrabajo=0;
	int idServicio=20000;
	int idMascotas=14;
	eTrabajo unTrabajo[T];
	eServicio unServicio[S];
	eMascotas unaMascota[M];

	strcpy(confirmar,"no");
	Inicializar(unTrabajo,T);
	InicializarMascotas(unaMascota,T);
	HardcodeoServicio(unServicio,&idServicio);
	HardcodeoMascotas(unaMascota,&idMascotas);

	do
	{
		switch(Menu())
		{
			case 0:
				utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,2,confirmar);
				break;
			case 1:
				printf(" \n\t\t>ALTAS<\t\t\n");
				if(!(Altas(unTrabajo,T,unServicio,S,unaMascota,M,&idTrabajo,&idMascotas)))
				{
					flag=REALIZADO;
				}
				else
				{
					flag=NO_REALIZADO;
				}
				break;
			case 2:
				printf("\t\t>MODIFICAR<\t\t\n");
				if(flag==REALIZADO)
				{
					ModificarTrabajo(unTrabajo,T,unServicio,S,unaMascota,M);
				}
				else
				{
					printf("Error, no se han dado de alta trabajos\n");
				}
				break;
			case 3:
				printf("\t\t>BAJAS<\t\t\n");
				if(flag==REALIZADO)
				{
					Bajas(unTrabajo,T,unServicio,S,unaMascota,M);
				}
				else
				{
					printf("Error, no se ha dado de alta ningun trabajo\n");
				}
				break;
			case 4:
				printf("\t\t>>LISTA DE TRABAJOS<<\t\t\n");
				if(flag==REALIZADO)
				{
					//OrdenarTrabajosPorAnio(unTrabajo,T);
					OrdenarTrabajosNombreMascota(unTrabajo,T,unaMascota,M);
					if(MostrarListaTrabajosConServicioyMascota(unTrabajo,T,unServicio,unaMascota,S,M)!=0)
					{
						printf("No hay trabajos para mostrar\n");
					}
				}
				else
				{
					printf("Error, aún no se han dado de alta\n");
				}
				break;
			case 5:
				printf("\t\t>LISTA DE SERVICIOS<<\t\t\n");
				//MostrarListaServicios(unServicio,S);
				ServicioConMasTrabajos(unServicio,S,unTrabajo,T);
				break;
			case 6:
				printf("\t\t>LISTA DE MASCOTAS<<\t\t\n");
				MostrarListaMascotas(unaMascota,M);
				ListadoServiciosPorNombre(unServicio,S,unTrabajo,T,unaMascota,M);
				break;
			case 7:
				printf("\t\t>TOTAL<<\t\t\n");
				TotalPesosServicio(unTrabajo,T,unServicio,S);
				break;
		}
	}while(stricmp(confirmar,"si"));
	printf("Gracias por utilizar nuestro servicio");

	return EXIT_SUCCESS;
}
