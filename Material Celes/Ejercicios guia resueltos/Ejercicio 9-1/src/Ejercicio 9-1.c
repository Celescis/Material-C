/*
============================================================================
Ejercicio 9-1:
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:

idProducto (numerico)
descripcion (alfanumérico)
nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
precio (numérico decimal)

Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
LISTADO Productos.
LISTADO ordenado por precio.
LISTADO ordenado por descripción.
Agregar los siguientes informes:
El/los  productos más caros.
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
