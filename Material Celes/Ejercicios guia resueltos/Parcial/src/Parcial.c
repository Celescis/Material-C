/*
 ============================================================================
 Name        : Parcial.c
 Author      : Celeste Cisternas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 2. Crear dos funciones. Una que permita guardar en un archivo binario, un dato del tipo de la estructura creada en el punto 2.
 El nombre del archivo estará dado por el atributo del tipo cadena de la estructura. La otra leerá dicho dato y lo mostrará por
 pantalla (En una variable distinta a la creada en el punto 2). En todos los casos se utilizará memoria dinámica.
 Respetar las reglas de estilo vistas en la cátedra. *
*/
typedef struct
{
    int id;
    char marca[20];
}eCafetera;

eCafetera* NuevoProducto();
eCafetera* NuevoProductoParam(int id, char* marca);
int MostrarUno(eCafetera*);
int LeerBinario(char* archivo);
int GuardarBinario(char* archivo,eCafetera* producto);
int getId(eCafetera* producto, int* id);
int setId(eCafetera* producto, int id);

int main(void)
{
	eCafetera* pProducto = NULL;
	int id=200;
	char marca[20];
	strcpy(marca,"cabrales");

	pProducto = NuevoProductoParam(id,marca);

	if(pProducto!=NULL)
	{
		//MostrarUno(pProducto);
		GuardarBinario("Cafe.bin",pProducto);
		LeerBinario("Cafe.bin");
	}

	return EXIT_SUCCESS;
}

eCafetera* NuevoProducto()//constructor por defecto
{
	eCafetera* unProducto = NULL;

	unProducto = (eCafetera*)malloc(sizeof(eCafetera));

	if(unProducto!=NULL)
	{
		unProducto->id=0;
		strcpy(unProducto->marca,"\0");
	}

	return unProducto;
}

eCafetera* NuevoProductoParam(int id, char* marca)//constructor parametrizado
{
	eCafetera* unProducto;

	unProducto = NuevoProducto();

	if(unProducto!=NULL)
	{
		setId(unProducto,id);
		strcpy(unProducto->marca,marca);
	}

	return unProducto;
}

int MostrarUno(eCafetera* unProducto)
{
	int isOk = -1;
	int id;
	getId(unProducto,&id);

	printf("El id es: %d\n"
		   "La marca es: %s\n",id
		   	   	   	   	   ,unProducto->marca);
	return isOk;
}

int LeerBinario(char* archivo)
{
	int isOk=-1;
	FILE* pArchivo;
	eCafetera* aux =NULL;
	pArchivo = fopen(archivo,"rb");
	aux=NuevoProducto();
	if(pArchivo!= NULL)
	{
		if(fread(aux,sizeof(eCafetera),1,pArchivo))
		{
			MostrarUno(aux);
		}

		fclose(pArchivo);
		isOk=0;
	}
	return isOk;
}

int GuardarBinario(char* archivo,eCafetera* producto)
{
	int isOk=-1;
	FILE* pArchivo;
	eCafetera* aux = NULL;
	aux=producto;
	pArchivo = fopen(archivo,"wb");

	if(pArchivo!= NULL)
	{
		fwrite(aux,sizeof(eCafetera),1,pArchivo);
		fclose(pArchivo);
		isOk=0;
	}
	return isOk;
}

int setId(eCafetera* producto, int id)
{
	int isOk=-1;

	if(producto!=NULL && id>0)
	{
		producto->id=id;
		isOk=0;
	}
	return isOk;
}

int getId(eCafetera* producto, int* id)
{
	int isOk=-1;

	if(producto!=NULL && id!=NULL)
	{
		*id=producto->id;
		isOk=0;
	}

	return isOk;
}
