/*
 * utn.h
 *
 *  Created on: 8 may. 2021
 *      Author: celes
 */

#ifndef UTNGENERICO_H_
#define UTNGENERICO_H_

//-----------------------------------------------CHAR----------------------------------------------------
int SizeString(char string[]);//convierte toda la cadena en minuscula y le cambia a mayus la primera letra
int isChar(char string[]);//verifica si es una letra o cadena
int getString(char string[], int tam);//cambia el \n por el \0
int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos,char input[]);

//-----------------------------------------------INT-----------------------------------------------------
int isInt(char resultado[]);//verifica si la cadena tiene numeros
int getInt(int* input);//verifica que sea int
int utn_getInt(char mensaje[],char mensajeError[],int min,int max,int reintentos,int* input);

//----------------------------------------------FLOAT----------------------------------------------------
int isFloat(char resultado[]);//verifica si la cadena son numeros y que tenga el '.'
int getFloat(float* input);//verifica que sea float
int utn_getFloat(char mensaje[], char mensajeError[], float min, float max, int reintentos, float* input);

//----------------------------------------------OTROS----------------------------------------------------
int ObtenerID();//ID autoincremental
void Inicializar(eProducto lista[],int tam)//inicializo la estructura en vacio
int Menu();//menu generico
int MenuModificaciones();//menu modificaciones generico
void HardcodeoSector(eSector lista[]);

//-----------------------------------------------ABM------------------------------------------------------
int PedirData(eEmpleado lista[], int tam, eSector sectores[], int tamS,int* id, char auxNombre[], char auxApellido[], float* auxSalario, int* auxIdSector, int* index);//pido datos al usuario + idIncremental
int AltaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS, int* id);
int AltaEmpleado(eEmpleado lista[], int tam, eSector sectores[],int tamS, int id, char nombre[], char apellido[], float salario, int idSector, int index);
int BajaEmpleado(eEmpleado lista[], int tam,eSector sectores[], int tamS, int *id);
int ModificarEmpleado(eEmpleado listaE[], int tamE, eSector listaS[], int tamS, int auxId, char auxNombre[50], char auxApellido[50], float auxSalario, int auxIdSector, int index);

//----------------------------------------------BUSQUEDAS-------------------------------------------------
int BuscarLibre(eProducto lista[],int tam);//busco el espacio libre
int GetCodigoN(eNacionalidad lista[], int tamN,char buscarDescripcionN[], int* codigoN);//obtengo id/codigo pasandole la descripcion
int GetDescripcionN(eNacionalidad lista[], int tamN, int buscarCodigoN,char descripcionN[]);//obtengo descripcion pasandole el id/codigo
int BuscarEmpleadosPorId(eEmpleado lista[], int tam, int* id);//paso el id y me devuelve el index, osea en la posicion en que se encuentra ese empleado
eCurso BuscarCursoPorId(eCurso lista[],int tam, int* id);//busco pasando toda la estructura
Employee* AuxiliarEmpleado(LinkedList* listaEmpleados, int* id, int* index);

//----------------------------------------------INFORMES--------------------------------------------------
int OrdenarAlumnosPorNombre(eAlumno lista[], int tam);//ordenar empleados alfabeticamente
int MostrarAlumnosConDescripcionCurso(eAlumnos listaA[],int tamA,eCursos listaC[],int tamC);//muestro los alumnos con la descripcion del curso
int MostrarEmpleadoConSector(eEmpleado unEmpleado, eSector sectores[], int tamS);//muestro UN solo empleado con la descripcion del sector en vez del id
int MostrarListaEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamS);//muestro la lista de empleados con su descripcion del sector
int OrdenarTrabajos(eTrabajo lista[], int tam);//LISTAR TRABAJOS: Hacer un único listado de todos los trabajos ordenados por año y ante igualdad de año por nombre de mascota.
int MostrarServicio(eServicio servicio);//muestro un solo servicio
int MostrarListaServicios(eServicio servicios[], int tam);
int OrdenarEmpleados(eEmpleado lista[], int tam, int orden);
int sectorMayorSueldo(eEmpleado lista[], int tam, eSector sectores[], int tamSec);


#endif /* UTNGENERICO_H_ */
