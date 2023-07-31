/*
 ============================================================================
 Name        : Generico.c
 Author      : Celeste Cisternas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


#include "ABM.h"
#define TAM 5

int main(void) {
	setbuf(stdout, NULL);

	int opciones;
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eGen Gen[TAM];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	Inicializar(Gen, TAM);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		//Menu();
		printf("INGRESE OPCION: ");
		scanf("%d", &opciones);

		//MENU SWITCH
		switch (opciones)
		{
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			opciones = 0;
			break;
		case 1:
			//ALTA
			if (Alta(Gen, TAM)) {
				puts(" * Gen DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Gen");
			}
			system("pause");
			break;
		case 2:
			//BAJA
			if (Baja(Gen, TAM)) {
				puts("\n * BAJA DE Gen EXITOSA");
				MostrarTodos(Gen, TAM);
			} else {
				puts("\n * BAJA DE Gen CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//MODIFICACION
			if (Modificar(Gen, TAM)) {
				puts("\n * MODIFICACION DE Gen EXITOSA\n");
				MostrarTodos(Gen, TAM);
			} else {
				puts("\n * MODIFICACION DE Gen CANCELADA");
			}
			system("pause");
			break;
		case 4:
			//LISTADO Gen
			MostrarTodos(Gen, TAM);
			system("pause");
			break;
		case 5:
			//ORDENAR Gen
			criterioDeOrdenamiento = 1; //PEDIR CRITERIO DE ORDENAMIENTO
			Ordenar(Gen, TAM, criterioDeOrdenamiento);
			system("pause");
			break;
		}
	} while (opciones != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}

