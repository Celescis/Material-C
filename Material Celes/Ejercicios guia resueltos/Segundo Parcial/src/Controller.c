#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Utn.h"
#include "Libro.h"
#include "parser.h"
#include "Menus.h"
#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListLibro)
{
	int isOk = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListLibro!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL)
		{
			if(!parser_libroFromText(pArchivo, pArrayListLibro))
			{
				printf("Se cargo con exito\n");
				isOk=0;
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}

		fclose(pArchivo);
	}

    return isOk;
}

int controller_listLibro(LinkedList* pArrayListLibro)
{
	int isOk = -1;

	if(pArrayListLibro!=NULL)
	{
		printf("LISTA DE EMPLEADOS\n");
		if(libro_printList(pArrayListLibro)!=0)
		{
			printf("No hay libros para mostrar");
			isOk=0;
		}
	}

    return isOk;
}

int controller_sortLibro(LinkedList* pArrayListLibro)
{
	int isOk = -1;
	char confirmar[4];
	strcpy(confirmar,"no");
	LinkedList* clon = NULL;

	if(pArrayListLibro!=NULL)
	{
		clon = ll_clone(pArrayListLibro);

		if(clon!=NULL)
		{
			do
			{
				switch(libro_menuOrden())
				{
					case 0:
						utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
						if(stricmp(confirmar,"no"))
						{
							ll_deleteLinkedList(clon);
						}
						break;
					case 1:
						if(!ll_sort(clon,libro_compareByAutor,1))
						{
							printf("Se ha ordenado la lista por autor de manera ascendente");
						}
						else
						{
							printf("No pudo ordenarse la lista");
						}
						break;
					case 2:
						controller_listLibro(clon);
						break;
				}
			}while(stricmp(confirmar,"si"));
		}
	}

	return isOk;
}

int controller_mapeadoDescuentos(LinkedList* pArrayListLibro)
{
	int isOk = -1;

	if(pArrayListLibro!=NULL)
	{
		pArrayListLibro = ll_map(pArrayListLibro,libro_descuentos);
		printf("Se ha aplicado el descuento con exito");
		isOk=0;
	}
	return isOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListLibro)
{
	int isOk = -1;
	int i;
	int len;
	int auxiliarID;
	char auxiliarTitulo[128];
	char auxiliarAutor[128];
	float auxiliarPrecio;
	int auxiliarEditorialId;
	char auxiliarEditorialNombre[128];
	FILE* pArchivo;
	eLibro* aux = NULL;

	if(path!=NULL && pArrayListLibro!=NULL)
	{
		pArchivo = fopen(path,"w");

		len = ll_len(pArrayListLibro);

		if(pArchivo!= NULL && len>0)
		{
			fprintf(pArchivo,"id,titulo,autor,precio,editorialId\n");

			for(i=0; i<len ;i++)
			{
				aux = (eLibro*) ll_get(pArrayListLibro,i);

				if(aux!=NULL)
				{
					if(!libro_getVerify(aux,&auxiliarID,auxiliarTitulo,auxiliarAutor,&auxiliarPrecio,&auxiliarEditorialId))
					{
						BuscarNombreEditorial(auxiliarEditorialId,auxiliarEditorialNombre);
						fprintf(pArchivo,"%d,%s,%s,%2.f,%s\n",auxiliarID,auxiliarTitulo,auxiliarAutor,auxiliarPrecio,auxiliarEditorialNombre);
						isOk=0;
					}
					else
					{
						libro_delete(aux);
						printf("No se pudo guardar el archivo\n");
					}
				}
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}

	if(!isOk)
	{
		printf("El archivo fue guardado con exito!\n");
	}
	return isOk;
}
