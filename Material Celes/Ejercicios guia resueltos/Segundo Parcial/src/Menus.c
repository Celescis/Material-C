#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menus.h"
#include "Utn.h"

int Menu()
{
	int opciones;

	printf("\n\t\t>-MENU-<\n");
	printf("1. Cargar datos desde un archivo.\n");
	printf("2. Ordenar lista por autor.\n");
	printf("3. Mostrar los datos.\n");
	printf("4. Aplicar descuentos a la editorial 'Planeta' y 'Siglo XXI'.\n");
	printf("5. Guardar datos en un archivo.\n");
	printf("0. Salir\n");

	utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",0,5,3,&opciones);

	return opciones;
}

int libro_menuOrden()
{
	int opciones;

	printf("\n\t>-MENU ORDEN-<\t\n");
	printf("1. Ordenar por Autor\n");
	printf("2. Mostrar lista ordenada\n");
	printf("0. Salir\n");

	utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",0,2,3,&opciones);

	return opciones;
}
