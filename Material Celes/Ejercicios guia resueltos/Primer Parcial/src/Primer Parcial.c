/*
 ============================================================================
                       PRIMER PARCIAL LABORATORIO 2021
 Nombre      : Celeste Cisternas
 Curso       : 1ro B

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "Utn.h"
#define REALIZADO 1
#define NO_REALIZADO 0

int main(void)
{
	setbuf(stdout,NULL);
	char confirmar[4];
	int cantidad;
	int flag;
	int i;
	int idServicio=20000;
	eTrabajo unTrabajo[T];
	eServicio unServicio[S];
	int idAutoIncremental=0;

	Inicializar(unTrabajo,T);
	HardcodeoServicio(unServicio,&idServicio);
	HardcodeoTrabajo(unTrabajo);
	strcpy(confirmar,"no");

	do
	{
		switch(Menu())
		{
			case 0:
				utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
				break;
			case 1:
				i=0;
				printf(" \n\t\t>>ALTAS<<\t\t\n");
				utn_getInt("\n¿Cuantos trabajos desea dar de alta?\n","\nError, cantidad invalida\n",1,1000,3,&cantidad);
				do
				{
					if(!(AltaTrabajo(unTrabajo,T,unServicio,S,&idAutoIncremental)))
					{
						flag=REALIZADO;
					}
					else
					{
						flag=NO_REALIZADO;
					}
					if(flag==REALIZADO)
					{
						printf("\nSe han dado de alta con exito\n");
					}
					else
					{
						printf("\nError, no se han dado de alta\n");
					}
					i++;
				}while(cantidad!=i);
				break;
			case 2:
				printf("\t\t>>MODIFICAR<<\t\t\n");
				if(flag==REALIZADO)
				{
					 ModificarTrabajo(unTrabajo,T,unServicio,S);
				}
				else
				{
					printf("Error, no se han dado de alta ningun trabajo\n");
				}
				break;
			case 3:
				i=0;
				printf("\t\t>>BAJAS<<\t\t\n");
				if(flag==REALIZADO)
				{
					utn_getInt("¿Cuantos trabajos desea dar de baja?\n","Error, cantidad invalida\n",1,1000,3,&cantidad);
					do
					{
						if(BajaTrabajo(unTrabajo,T,unServicio,S))
						{
							printf("Ningun cambio realizado\n");
						}
						i++;
					}while(cantidad!=i);
				}
				else
				{
					printf("Error, no se ha dado de alta ningun trabajo\n");
				}
				break;
			case 4:
				printf("\t\t\t\t>>LISTA DE TRABAJOS<<\t\t\n");
				if(flag==REALIZADO)
				{
					OrdenarTrabajosPorAnio(unTrabajo,T);
					if(MostrarListaTrabajosConServicio(unTrabajo,T,unServicio,S)!=0)
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
				printf("\t  >>LISTA DE SERVICIOS<<\t\t\n");
				MostrarListaServicios(unServicio,S);
				break;
			case 6:
				printf("\t\t  >>TOTAL<<\t\t\n");
				TotalPesosServicio(unTrabajo,T,unServicio,S);
				break;
		}
	}while(stricmp(confirmar,"si"));
	printf("Gracias por utilizar nuestro servicio");

	return EXIT_SUCCESS;
}
