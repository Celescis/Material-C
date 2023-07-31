/*
 * Utn.c
 *
 *  Created on: 8 may. 2021
 *      Author: celes
 */
#include "UtnGenerico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define VACIO 0
#define OCUPADO 1

int idIncremental=0;

//-----------------------------------CHAR-----------------------------------
int isChar(char string[])
{
	int isOk = 0;
	int i;
	int stringTam = strlen(string);

	for(i = 0; i<stringTam; i++)
	{
		if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
		{
			isOk = -1;
			break;
		}
	}

	return isOk;
}
int getString(char input[], int tam)
{
    char auxString[tam];
    int isOk = -1;

    if (input != NULL && tam > 0)
    {
        fflush(stdin);
        fgets(auxString,tam,stdin);
        if (auxString[strlen(auxString)-1]=='\n')//le cambia el enter por el final
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= tam)
        {
            strncpy(input, auxString, tam);//copia cadena en la variable destino
            isOk=0;
        }
    }

    return isOk;
}
int SizeString(char string[])
{
	int isOk = -1;
	int i = 0;

	if(string != NULL)
	{
		strlwr(string);//convierte la cadena en minuscula
		string[0] = toupper(string[0]); //toupper convierte la primer letra en mayuscula
		while(string[i] != '\0')
		{
			if(string[i] == ' ')
			{
				string[i + 1] = toupper(string[i + 1]);
				isOk = 0;
			}
			i++;
		}
	}

	return isOk;
}
int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos, char input[])
{
	int isOk = 1;
    char auxString[tam];

    if(input != NULL && mensaje != NULL && mensajeError != NULL && tam > 0 && reintentos >= 0)
    {
        do{
        	printf("%s", mensaje);
            if(!(getString(auxString,tam)) && !(isChar(auxString)))
            {
                strncpy(input,auxString,tam);
                isOk = 0;
                break;
            }
            else
            {
            	printf("%s", mensajeError);
            	reintentos--;
            }

        }while(reintentos>=0);
    }

    return isOk;
}
//-----------------------------------INT-----------------------------------
int isInt(char input[])
{
    int isOk = 0;
    int i = 0;
    int stringTam = strlen(input); //devuelve la longitud de la cadena sin contar el nulo final \0

    for(i=0; i<stringTam ;i++)
    {
    	if(input[i]< '0' || input[i]> '9' )
        {
    		isOk=-1;
            break;
        }
    }

    return isOk;
}
int getInt(int* input)
{
    char auxString[400];
    int isOk = -1;

    if(!(getString(auxString,sizeof(auxString))) && !(isInt(auxString))) //podria usar sizeof(auxString) en vez del valor fijo 400
    {
    	*input=atoi(auxString); // RECIBE UNA CADENA Y DEVUELVE UN VALOR INT
    	isOk=0;
    }

    return isOk;
}
int utn_getInt(char mensaje[], char mensajeError[], int min, int max, int reintentos, int* input)
{
    int isOk=-1;
    int auxInt;

   if(mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0 && input != NULL)
   {
	   do
	   {
			reintentos--;
			printf("%s", mensaje);
			if(!(getInt(&auxInt)) && auxInt >= min && auxInt <= max)
			{
				*input= auxInt;
				isOk = 0;
				break;
			}
			else
			{
				printf("%s ",mensajeError);
			}
	   }
	   while(reintentos >= 0);
   }

    return isOk;
}
//-----------------------------------FLOAT-----------------------------------
int isFloat(char input[])
{
    int isOk = 0;
    int i;
    int stringTam = strlen(input);

    for(i=0; i<stringTam ;i++)
    {
        if((input[i]< '0' || input[i]> '9' ) && (input[i]!='.'))
        {
        	isOk = -1;
            break;
        }
    }

    return isOk;
}
int getFloat(float* input)
{
    char auxString[200];
    int isOk =-1;

    if(!(getString(auxString,200)) && !(isFloat(auxString)))
    {
        *input = atof(auxString); //CONVIERTE A FLOAT LA CADENA
        isOk = 0;
    }

    return isOk;
}
int utn_getFloat(char mensaje[], char mensajeError[], float min, float max, int reintentos, float* input)
{
    int isOk = -1;
    float auxFloat;

    if(input != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
    {
        do
        {
        	printf("%s", mensaje);
        	if(!(getFloat(&auxFloat)) && auxFloat >= min && auxFloat <= max)
        	{
        		*input= auxFloat;
        		isOk = 0;
        		break;
        	}
        	else
        	{
        		printf("%s ",mensajeError);
        		reintentos--;
        	}
        }
        while(reintentos >= 0);
    }

    return isOk;
}

//-----------------------------------OTRAS-----------------------------------
int ObtenerID()
{
	return idIncremental+=1;
}
void Inicializar(eProducto lista[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		lista[i].isEmpty=VACIO;
	}
}

int Menu()
{
	int opciones;

	printf("\n\t>ABM<\t\n");
	printf("1. ALTA\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. MOSTRAR lista trabajos\n");
	printf("0. SALIR\n");
	utn_getInt("\nIngrese una opcion: \n","Error, opcion invalida",0,4,2,&opciones);

	return opciones;
}
int MenuModificaciones()
{
	int opciones;

	printf("\n\t>MODIFICAR<\t\n");
	printf("1. Nombre\n");
	printf("2. Apellido\n");
	printf("3. Salario\n");
	printf("4. Sector\n");
	printf("0. SALIR\n");
	utn_getInt("\nIngrese una opcion para modificar: \n","Error, opcion invalida",0,4,2,&opciones);

	return opciones;
}
void HardcodeoSector(eSector lista[])
{
	int auxId[S]={1,2,3};
	char auxDescripcion[S][25]={"RRHH","VENTAS","IT"};
	int i;

	for(i=0;i<S;i++)
	{
		lista[i].id=auxId[i];
		strcpy(lista[i].descripcion,auxDescripcion[i]);
	}
}

//-----------------------------------------------ABM------------------------------------------------------
int PedirData(eEmpleado lista[], int tam, eSector sectores[], int tamS, int* id, char auxNombre[], char auxApellido[], float* auxSalario, int* auxIdSector, int* index)
{
	int isOk=-1;

	if(lista != NULL && tam> 0 && id != NULL && auxNombre != NULL && auxApellido != NULL && auxIdSector != NULL)
	{
		*index = BuscarLibre(lista, tam);

		if(index < 0)
		{
			printf("No hay espacio libre\n");
		}
		else
		{
			utn_getString("Ingrese el nombre\n","Error, incompatible\n",50,2,auxNombre);
			utn_getString("Ingrese el apellido\n","Error, incompatible\n",50,2,auxApellido);
			utn_getFloat("Ingrese el salario\n","Error, cantidad incorrecta\n",1.00,100000.00,2,auxSalario);
			MostrarListaSectores(sectores,tamS);
			utn_getInt("Ingrese el sector\n","Error, sector incorrecta\n",1,S,2,auxIdSector);
			(*id)++;
			isOk = 0;
		}
	}

	return isOk;
}
int AltaTrabajo(eTrabajo lista[], int tam, eServicio listaS[], int tamS, int* id)
{
	int isOk=-1;
	int index;

	if(lista!=NULL && tam>0 && listaS!=NULL && tamS>0)
	{
		index=BuscarLibre(lista,tam);

		if(index<0)
		{
			printf("No hay espacio libre\n");
		}
		else
		{
			ObtenerId(id);
			lista[index].id=*id;
			utn_getString("Ingrese la marca: \n","Error, reingrese\n",25,2,lista[index].marcaBicicleta);
			SizeString(lista[index].marcaBicicleta);
			utn_getInt("Ingrese el rodado: \n","Error, reingrese\n",12,29,2,&lista[index].rodadoBicicleta);
			MostrarListaServicios(listaS,tamS);
			utn_getInt("Ingrese el ID del servicio: \n","Error, reingrese\n",20000,20004,2,&lista[index].idServicio);
			printf("Ingrese fecha de ingreso dd/mm/aaaa: \n");
			utn_getInt("Ingrese dia \n","Error, reingrese\n",1,31,2,&lista[index].fecha.dia);
			utn_getInt("Ingrese mes \n","Error, reingrese\n",1,12,2,&lista[index].fecha.mes);
			utn_getInt("Ingrese año [1970-2021]\n","Error, reingrese [1970-2021]\n",1970,2021,2,&lista[index].fecha.anio);
			lista[index].isEmpty=OCUPADO;

			isOk=0;
		}
	}

	return isOk;
}
int AltaEmpleado(eEmpleado lista[], int tam, eSector sectores[],int tamS, int id, char nombre[], char apellido[], float salario, int idSector, int index)
{
	int isOk=-1;

	if(lista!=NULL && tam>0 && id>0 && nombre!=NULL && apellido!=NULL && salario>0 && idSector>0)
	{

		lista[index].id=id;
		SizeString(nombre);
		strcpy(lista[index].nombre,nombre);
		SizeString(apellido);
		strcpy(lista[index].apellido,apellido);
		lista[index].salario=salario;
		lista[index].idSector=idSector;
		lista[index].isEmpty=OCUPADO;
		isOk=0;
	}

	return isOk;
}
int BajaEmpleado(eEmpleado lista[], int tam,eSector sectores[], int tamS, int *id)
{
	int isOk=-1;
	char respuesta[4];
	int index;

	if(lista != NULL && tam>0)
	{
		MostrarListaEmpleadosConSector(lista,tam,sectores,tamS);
		utn_getInt("Ingrese el ID para dar de baja\n","Error, ID invalido\n",1,tam,2,id);//REVISAR TAM PQ TAM ES LA CANTIDAD DE EMPLEADOS NO ID
		index=BuscarEmpleadosPorId(lista,tam,id);
		MostrarEmpleado(lista[index],sectores,tamS);
		utn_getString("\n¿Esta seguro que desea eliminar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,2,respuesta);
		if(!(stricmp(respuesta,"si")))
		{
			lista[index].isEmpty=VACIO;
			printf("\nEl empleado %s %s con ID %d se ha dado de baja correctamente\n",lista[index].nombre,
																				      lista[index].apellido,
																				      lista[index].id);
			isOk=0;
		}
	}

	return isOk;
}
int ModificarEmpleado(eEmpleado listaE[], int tamE, eSector listaS[], int tamS, int auxId, char auxNombre[50], char auxApellido[50], float auxSalario, int auxIdSector, int index)
{
	int isOk=-1;
	char respuesta[4];
	char confirmar[4];
	strcpy(confirmar,"no");
	MostrarListaEmpleadosConSector(listaE,tamE,listaS,tamS);
	utn_getInt("Ingrese el ID del empleado a modificar: \n","Error, ID invalido\n",1,tamE,2,&auxId);
	index=BuscarEmpleadosPorId(listaE, tamE, &auxId);
	MostrarEmpleado(listaE[index],listaS,tamS);
	utn_getString("¿Esta seguro que desea modificar este empleado? [si/no]\n","Error, ingrese [si/no]\n",4,2,respuesta);
	if(!(stricmp(respuesta,"si")))
	{
		do
		{
			switch(MenuModificaciones())
			{
				case 0:
					utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,2,confirmar);
					break;
				case 1:
					printf("\t****MODIFICAR NOMBRE****\t\n");
					utn_getString("Ingrese el nuevo nombre\n","Error, nombre invalido\n",50,2,auxNombre);
					strcpy(listaE[index].nombre,auxNombre);
					break;
				case 2:
					printf("\t****MODIFICAR APELLIDO****\t\n");
					utn_getString("Ingrese el nuevo apellido\n","Error, apellido invalido\n",50,2,auxApellido);
					strcpy(listaE[index].apellido,auxApellido);
					break;
				case 3:
					printf("\t****MODIFICAR SALARIO****\t\n");
					utn_getFloat("Ingrese el nuevo salario\n","Error, salario invalido\n",1.00,100000.00,2,&auxSalario);
					listaE[index].salario=auxSalario;
					break;
				case 4:
					printf("\t****MODIFICAR SECTOR****\t\n");
					MostrarListaSectores(listaS,tamS);
					utn_getInt("Ingrese el nuevo sector\n","Error, sector incorrecta\n",1,S,2,&auxIdSector);
					listaE[index].idSector=auxIdSector;
					break;
			}
		}while(stricmp(confirmar,"si"));

		isOk=0;
	}
	else
	{
		printf("No se realizo ningun cambio\n");
	}

	return isOk;
}

//----------------------------------------------BUSQUEDAS-------------------------------------------------
int BuscarLibre(eProducto lista[],int tam)
{
	int i;
	int index=-1;

	if(lista!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==VACIO)
			{
				index=i;
			}
		}
	}

	return index;
}
int GetCodigoN(eNacionalidad lista[], int tamN,char buscarDescripcionN[], int* codigoN)
{
	int isOk=-1;
	int i;

	if(lista!=NULL && buscarDescripcionN!=NULL && tamN>0)
	{
		for(i=0;i<tamN;i++)
		{
			if(!strcmp(lista[i].descripcionNacionalidad,buscarDescripcionN))//en otras ocasiones podria preguntar por el isEmpty ocupado
			{
				*codigoN=lista[i].idNacionalidad;
				isOk=0;
			}
		}
	}

	return isOk;
}
int GetDescripcionServicio(eServicio lista[], int tam, int buscarCodigo, char descripcion[])
{
	int isOk=-1;
	int i;

	if(lista!=NULL && tam>0 && descripcion!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].id==buscarCodigo)
			{
				strcpy(descripcion,lista[i].descripcion);
				isOk=0;
			}
		}
	}

	return isOk;
}
int BuscarEmpleadosPorId(eEmpleado lista[], int tam, int* id)
{
	int isOk=-1;
	int i;
	if(lista!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==OCUPADO && lista[i].id==*id)
			{
				isOk=i;
				break;
			}
		}
	}

	return isOk;
}
eCurso BuscarCursoPorId(eCurso lista[],int tam, int* id)
{
	eCurso miCurso;
	int i;

	for(i=0;i<tam;i++)
	{
		if(lista[i].idCurso==*id && lista[i].isEmpty==OCUPADO)
		{
			miCurso=lista[i];
			break;
		}
	}
	return miCurso;
}

//----------------------------------------------INFORMES--------------------------------------------------
int OrdenarAlumnosPorNombre(eAlumno lista[], int tam)
{
    int i;
    int j;
    int isOk;
    eAlumno auxAlumno;

    if(lista != NULL && tam>0)
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(strcmp(lista[i].nombre, lista[j].nombre)>0)
                {
                    auxAlumno = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxAlumno;
                    isOk=0;
                }
            }
        }
    }

    return isOk;
}
int MostrarAlumnosConDescripcionCurso(eAlumnos lista[],int tam,eCursos listaC[],int tamC)
{
	int i;
	int isOk=-1;
	eCursos miCurso;

	if(lista != NULL && tam>0 && listaC != NULL && tamC>0)
	{
		for(i=0;i<tam;i++)
		{
			miCurso=BuscarCursoPorId(listaC,tamC,lista[i].idCurso);

			printf("%d %s %s",lista[i].legajo,
							  lista[i].nombre,
							  miCurso.descripcionCurso);
		}
		isOk=0;
	}

	return isOk;
}
int MostrarEmpleadoConSector(eEmpleado unEmpleado, eSector sectores[], int tamS)
{
	int isOk=-1;
	char descripcionS[20];
	if(sectores != NULL && tamS>0)
	{
		GetDescripcionS(sectores,tamS,unEmpleado.idSector,descripcionS);
		printf("ID \t Nombre \t Apellido \t Salario \t Sector \n"
			   "%d  \t  %s    \t   %s     \t  %.2f   \t  %s \n", unEmpleado.id
															   , unEmpleado.nombre
															   , unEmpleado.apellido
															   , unEmpleado.salario
															   , descripcionS);
		isOk=0;
	}

	return isOk;
}
int MostrarListaEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
	int isOk=-1;
	int i;

	if(lista!=NULL && tam>0)
	{
		printf("\n> LISTA DE EMPLEADOS: \n");
		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				MostrarEmpleado(lista[i],sectores,tamS);
				isOk=0;
			}
		}
	}

	return isOk;
}
int OrdenarTrabajos(eTrabajo lista[], int tam)
{
	eTrabajo auxTrabajo;
	int todoOk = -1;

	for(int i = 0; i < tam-1; i++)
	{
		for(int j = i+1; j < tam ; j++)
		{
			if(lista[i].fecha.anio==lista[j].fecha.anio)//si son iguales los años
			{
				if(strcmp(lista[i].mascota,lista[j].mascota)>0)//ordena de a-z nombre de mascota
				{

					auxTrabajo = lista[i];
					lista[i] = lista[j];
					lista[j] = auxTrabajo;
					todoOk = 0;
				}
			}
			else
			{
				if(lista[i].fecha.anio>lista[j].fecha.anio)//ordena todos los años de menor a mayor
				{
					auxTrabajo = lista[i];
					lista[i] = lista[j];
					lista[j] = auxTrabajo;
					todoOk = 0;
				}
			}
		}
	}
	return todoOk;
}
int MostrarServicio(eServicio servicio)
{
	int isOk=-1;
	if(servicio != NULL)
	{
		printf( "\t> LISTA SERVICIOS \n"
				"ID del servicio: %d\n"
			    "Descripcion: %s\n"
			    "Precio: %.2f\n", servicio.id,
								  servicio.descripcion,
								  servicio.precio);
		isOk=0;
	}

	return isOk;
}
int MostrarListaServicios(eServicio servicios[], int tam)
{
	int isOk=-1;
	int i;

	if(servicios!=NULL && tam>0)
	{
		printf("\t> LISTA DE SERVICIOS: \n");
		for(i=0;i<tam;i++)
		{
			MostrarServicio(servicios[i]);
			isOk=0;
		}
	}

	return isOk;
}
int OrdenarEmpleados(eEmpleado lista[], int tam, int orden)
{
	int i;
	int j;
	eEmpleado auxEmpleado;
	int isOk=-1;

	for(i=0;i<tam-1;i++)
	{
		for(j=i+1;j<tam;j++)
		{
			if(strcmp(lista[i].apellido,lista[j].apellido)>0 && (lista[i].id==lista[j].id) && (orden==1))
			{
				auxEmpleado=lista[i];
				lista[i]=lista[j];
				lista[j]=auxEmpleado;
				isOk=0;
			}
			else
			{
				if(strcmp(lista[i].apellido,lista[j].apellido)<0 && (lista[i].id==lista[j].id) && (orden==1))
				{
					auxEmpleado=lista[i];
					lista[i]=lista[j];
					lista[j]=auxEmpleado;
					isOk=0;
				}
			}
		}
	}

	return isOk;
}
//----------------------------------------------RANDOM--------------------------------------------------
int DameCantidadReemplazos(char palabra[],char unaLetra, char otraLetra)
{
    int i;
    int lenght;
    int contador = 0;

    lenght = strlen(palabra);

    for(i = 0; i < lenght; i++)
    {
        if(tolower(palabra[i]) == tolower(unaLetra))
        {
            palabra[i] = otraLetra;
            contador++;
        }
    }
    if(contador != 0)
    {
        printf("%s\n", palabra);
    }
    return contador;
}

//----------------------------------------------ORDENAMIENTO-----------------------------------------------
int ordenamientoInt(int lista[], int tam, int orden)
{
    int aux;
    int todoOk = 0;

    if(lista != NULL && tam > 0 && (orden == 1 || orden == 0))
    {
        if(orden == 1)
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(lista[i] > lista[j])
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                }
            }
            todoOk = 1;
        }
        else
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(lista[i] < lista[j])
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int ordenamientoString(char nombre[][20], int tam, int orden)
{
    char aux[20];
    int todoOk = 0;

    if(nombre != NULL && tam > 0 && (orden == 1 || orden == 0))
    {
        if(orden == 1)
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(strcmp(nombre[i], nombre[j]) > 0)
                    {
                        strcpy(aux, nombre[i]);
                        strcpy(nombre[i], nombre[j]);
                        strcpy(nombre[j], aux);
                    }
                }
            }
            todoOk = 1;
        }
        else
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(strcmp(nombre[i], nombre[j]) < 0)
                    {
                        strcpy(aux, nombre[i]);
                        strcpy(nombre[i], nombre[j]);
                        strcpy(nombre[j], aux);
                    }
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int invertirCadena(char cadena[])
{
    int todoOk = 0;
    int longitud = strlen(cadena);
    int tam;
    char aux;

    tam = strlen(cadena) / 2;

    if(cadena != NULL)
    {
        for (int i = 0; i < tam; i++)
        {
            aux = cadena[i];
            cadena[i] = cadena[longitud - i - 1];
            cadena[longitud - i - 1] = aux;
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarCaracteres(char nombre[], int orden)
{
    char aux;
    int todoOk = 0;
    int tam;
    tam = strlen(nombre);

    if(nombre != NULL)
    {
        if(orden == 1)
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(nombre[i] > nombre[j])
                    {
                        aux = nombre[i];
                        nombre[i] = nombre[j];
                        nombre[j] = aux;
                    }
                }
            }
        }
        else
        {
            for(int i = 0; i < tam-1; i++)
            {
                for(int j = i+1; j < tam ; j++)
                {
                    if(nombre[i] < nombre[j])
                    {
                        aux = nombre[i];
                        nombre[i] = nombre[j];
                        nombre[j] = aux;
                    }
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}
int sectorMayorSueldo(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    float subtotal;
    float total[tamSec];

    if(lista != NULL && tam > 0 && sectores != NULL && tamSec > 0)
    {
        for(int i = 0; i < tamSec; i++)
        {
            total[i] = 0;
            subtotal = 0;
            for(int j = 0; j < tam; j++)
            {
                if(lista[j].isEmpty == 0 && lista[j].idSector == sectores[i].id)
                {
                    subtotal += lista[j].sueldo;
                }
            }
            total[i] += subtotal;
        }
        todoOk = 1;
    }
    return todoOk;
}

Employee* AuxiliarEmpleado(LinkedList* listaEmpleados, int* id, int* index)
{
	Employee* auxiliar;
	int i;
	int len;

	if(listaEmpleados!=NULL)
	{
		len = ll_len(listaEmpleados);

		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				auxiliar = (Employee*)ll_get(listaEmpleados,i);
				if(!employee_getId(auxiliar,id))
				{
					*index=i;
					break;
				}
			}
		}
	}

	return auxiliar;
}
