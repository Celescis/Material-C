#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Libro.h"

int parser_libroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
	int isOk = -1;
	char id[128];
	char titulo[128];
	char autor[128];
	char precio[128];
	char editorial[128];
	int header = 1;
	int cantidad = 0;
	int idEditorial;
	eLibro* auxiliar = NULL;

	if(pFile!=NULL && pArrayListLibro!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,titulo,autor,precio,editorial);

			if((cantidad==5) && (header!=1))
			{
				BuscarIdEditorial(editorial,&idEditorial);
				itoa(idEditorial,editorial,128);
				auxiliar = libro_newParametros(id,titulo,autor,precio,editorial);
				if(auxiliar!=NULL)
				{
					ll_add(pArrayListLibro, auxiliar);
					isOk=0;
				}
				else
				{
					libro_delete(auxiliar);
				}
			}
			else
			{
				header=0;//evita el titulo
			}
		}
		while(!feof(pFile));
	}

    return isOk;
}
