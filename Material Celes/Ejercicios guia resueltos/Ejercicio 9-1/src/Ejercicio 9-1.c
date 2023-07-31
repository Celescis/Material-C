/*
============================================================================
Ejercicio 9-1:
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:

idProducto (numerico)
descripcion (alfanum�rico)
nacionalidad (num�rico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
tipo (num�rico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
precio (num�rico decimal)

Realizar un programa que permita interactuar con un men� de usuarios con las siguientes opciones:
ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
MODIFICACI�N Producto: A partir del ingreso del ID. Si existe se podr� modificar el precio o el tipo.
LISTADO Productos.
LISTADO ordenado por precio.
LISTADO ordenado por descripci�n.
Agregar los siguientes informes:
El/los  productos m�s caros.
Precio promedio por tipo de producto.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"


int main(void)
{
	eProducto miProducto[MAX];
	int carga;
	int i;

	setbuf(stdout, NULL);
	Iniciar(miProducto,MAX);
	for(i=0;i<MAX;i++)
	{
		carga=CargarProductos(miProducto,MAX);
		if(carga==-1)
		{
			printf("No hay lugar en la lista");
		}
		else
		{
			printf("Se ha cargado con exito!\n");
		}
	}
	MostrarListaProductos(miProducto,MAX);


	return EXIT_SUCCESS;
}
