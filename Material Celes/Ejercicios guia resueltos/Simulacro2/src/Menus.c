#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menus.h"
#include "Utn.h"

int Menu()
{
	int opciones;

	printf("\n\t\t\t\t>-MENU-<\t\t\t\t\n");
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n");

	utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",1,10,3,&opciones);

	return opciones;
}

int venta_menuModify()
{
	int opciones;

	printf("\n\t>-MENU MODIFICACIONES-<\t\n");
	printf("1. Modificar nombre\n");
	printf("2. Modificar horas trabajadas\n");
	printf("3. Modificar sueldo\n");
	printf("0. Salir\n");

	utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",0,3,3,&opciones);

	return opciones;
}

int venta_menuOrden()
{
	int opciones;

	printf("\n\t>-MENU ORDEN-<\t\n");
	printf("1. Ordenar por ID\n");
	printf("2. Ordenar por nombre\n");
	printf("3. Ordenar por horas trabajadas\n");
	printf("4. Ordenar por sueldo\n");
	printf("5. Mostrar lista ordenada\n");
	printf("0. Salir\n");

	utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",0,5,3,&opciones);

	return opciones;
}

int venta_subMenuOrden()
{
	int opciones;

	printf("\n\t>-CRITERIO DE ORDEN-<\t\n");
	printf("0. Descendente\n");
	printf("1. Ascendente\n");

	utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",0,1,3,&opciones);

	return opciones;
}
