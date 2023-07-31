#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Venta.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int parser_VentaFromText(FILE* pFile , LinkedList* pArrayListVenta)
{
	int isOk = -1;
	char id[128];
	char nombre[128];
	char dia[128];
	char horario[128];
	char sala[128];
	char entradas[128];
	int header = 1;
	int cantidad = 0;
	Venta* auxiliar = NULL;

	if(pFile!=NULL && pArrayListVenta!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,nombre,dia,horario,sala,entradas);

			if((cantidad==6) && (header!=1))
			{
				auxiliar = venta_newParametros(id,nombre,dia,horario,sala,entradas);

				if(auxiliar!=NULL)
				{
					ll_add(pArrayListVenta, auxiliar);
					isOk=0;
				}
				else
				{
					venta_delete(auxiliar);
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

int parser_IdFromText(FILE* pFile , LinkedList* pArrayListVenta, int* id)
{
	int isOk = -1;
	char idTxt[128];
	int idInt;
	int cantidad = 0;
	int header=1;

	if(pFile!=NULL && pArrayListVenta!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^\n]\n",idTxt);

			if((cantidad==1) && (header!=1))
			{
				isOk = 0;
				idInt = atoi(idTxt);

				if(idInt>*id)
				{
					*id=idInt;
				}
			}
			else
			{
				header=0;
			}
		}
		while(!feof(pFile));
	}

    return isOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int parser_VentaFromBinary(FILE* pFile , LinkedList* pArrayListVenta)
{
	int isOk = -1;
	Venta* auxiliar = NULL;

	if(pFile!=NULL && pArrayListVenta!=NULL)
	{
		do
		{
			auxiliar = venta_new();

			if(auxiliar!=NULL)
			{
				if(fread(auxiliar,sizeof(Venta),1,pFile))
				{
					ll_add(pArrayListVenta,auxiliar);
					isOk=0;
				}
				else
				{
					venta_delete(auxiliar);
				}
			}
		}while(!feof(pFile));
	}

    return isOk;
}
