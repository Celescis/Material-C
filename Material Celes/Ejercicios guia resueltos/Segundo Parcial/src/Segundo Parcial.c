/*
 ============================================================================
                     SEGUNDO PARCIAL LABORATORIO 2021
 Nombre      : Celeste Cisternas
 Curso       : 1ro B

 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libro.h"
#include "Menus.h"
#include "Utn.h"
#define REALIZADO 1
#define NO_REALIZADO 0
#define SIZE 128

int main(void)
{
	setbuf(stdout,NULL);
	char confirmar[4];
	int flagTxt = NO_REALIZADO;
	int flagSaveTxt = NO_REALIZADO;
	strcpy(confirmar,"no");
	char path[SIZE];
	LinkedList* listaLibros = ll_newLinkedList();

	do
	{
		switch(Menu())
		{
			case 0:
				if(flagSaveTxt==NO_REALIZADO && !ll_isEmpty(listaLibros))
				{
					utn_getString("\n¿Esta seguro que desea salir sin guardar?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
					if(stricmp(confirmar,"si"))
					{
						controller_saveAsText("mapeado.csv",listaLibros);
						flagSaveTxt=REALIZADO;
						strcpy(confirmar,"si");
					}
					else
					{
						strcpy(confirmar,"si");
					}
				}
				else
				{
					strcpy(confirmar,"si");
				}
				break;
			case 1:
				if(ll_isEmpty(listaLibros) || flagTxt == NO_REALIZADO)
				{
					getStringPath("\nIngrese el nombre del archivo a cargar (EJ: Datos): ","Error, intente nuevamente",SIZE,3,path);
					if(!controller_loadFromText(path,listaLibros))
					{
						flagTxt=REALIZADO;
					}
					else
					{
						flagTxt=NO_REALIZADO;
					}
				}
				else
				{
					printf("Ya ha cargado un archivo");
				}
				break;
			case 2:
				if(!ll_isEmpty(listaLibros))
				{
					controller_sortLibro(listaLibros);
				}
				else
				{
					printf("No hay libros para ordenar");
				}
				break;
			case 3:
				if(!ll_isEmpty(listaLibros))
				{
					controller_listLibro(listaLibros);
				}
				else
				{
					printf("No hay libros para mostrar");
				}
				break;
			case 4:
				if(!ll_isEmpty(listaLibros))
				{
					controller_mapeadoDescuentos(listaLibros);
				}
				else
				{
					printf("No hay libros para hacer descuentos");
				}
				break;
			case 5:
				if(!ll_isEmpty(listaLibros))
				{
					controller_saveAsText("mapeado.csv",listaLibros);
					flagSaveTxt=REALIZADO;
				}
				else
				{
					printf("No hay nada en la lista para guardar");
				}
				break;
			default:
				printf("Opcion invalida");
				break;
		}
	}while(stricmp(confirmar,"si"));
	printf("Gracias por utilizar nuestro servicio");

	return 0;
}
