/*
 ============================================================================
Ejercicio 10-2:
Crear las siguientes estructuras en c, y definir la manera mas optima de relacionarlas.
1) Producto-Proveedor (Donde el producto solo puede tener un único proveedor)
	Producto
	Proveedor
	idProducto (int)
	idProveedor(int)
	descripcion(string)
	razonSocial(string)
	precio(float)
	direccion(eDireccion)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct //SIEMPRE QUE ENLAZO UNA ESTRUCTURA A OTRA, PRIMERO DEFINO LA QUE VOY A INCLUIR
{
	char calle[20];
	int numero;
}eDireccion;

typedef struct
{
	int idProveedor;
	char proveedor;
	char razonSocial[20];
	eDireccion direccion;
	int isEmpty;
}eProveedor;

typedef struct
{
	int idProducto;
	char descripcion[20];
	float precio;
	int idProveedor;
	int isEmpty;
}eProducto;
/*
 * 3)Alumno-Localidad (Donde un alumno solo vive en una localidad)
 * 	Alumno
	Localidad
	idAlumno(int)
	idLocalida(int)
	nombre(string)
	descripcion(string)
	codigoPostal(int)
 */
typedef struct
{
	int idLocalidad;
	char descripcion[20];
	int codigoPostal;
	int isEmpty;

}eLocalidad;

typedef struct
{
	int idAlumno;
	char nombre[20];
	int idLocalidad;
	int isEmpty;

}eAlumno;



int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
