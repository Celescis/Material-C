/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : Celeste Cisternas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#define REALIZADO 1
#define NO_REALIZADO -1

int main(void) {
	setbuf(stdout, NULL);
	eProducto unProducto[TAM];
	eNacionalidad unaNacionalidad[N];
	eTipoProducto unTipo[T];
	int opciones;
	int cantidad;
	int i;
	int flag;
	int auxId;
	char auxDescripcion[20];
	char auxDescripcionN[20];
	char auxDescripcionT[20];
	float auxPrecio;
	int index;

	Inicializar(unProducto,TAM);
	HardcodeoTipoProducto(unTipo);
	HardcodearNacionalidad(unaNacionalidad);

	do
	{
		opciones=Menu();

		switch(opciones)
		{
		case 1:
			printf("**********ALTA**********");
			utn_getInt("Ingrese la cantidad de productos a dar de alta","Error, numero invalido",1,TAM,2,&cantidad);
			i=0;
			do
			{
				if(!(PedirData(unProducto,TAM,&auxId,auxDescripcion,auxDescripcionN,auxDescripcionT,&auxPrecio,&index))&&!(AltaProducto(unProducto,TAM,unaNacionalidad,N,unTipo,T,auxId,auxDescripcion,auxDescripcionN,auxDescripcionT,auxPrecio,index)))
				{
					printf("Se han dado de alta los productos correctamente\n");
					flag=REALIZADO;
				}
				else
				{
					flag=NO_REALIZADO;
				}

				i++;
			}while(cantidad!=i);
			break;
		case 2:
			printf("********MODIFICAR********\n");
			break;
		case 3:
			printf("**********BAJA**********\n");
			break;
		case 4:
			printf("********MOSTRAR********\n");
			MostrarListaNacionalidad(unaNacionalidad,N);
			printf("LISTA TIPOS\n");
			MostrarListaTipos(unTipo,T);
			break;
		}

	}while(!opciones);


	return EXIT_SUCCESS;
}
