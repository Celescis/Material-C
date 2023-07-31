/*
 ============================================================================
Ejercicio 10-3:
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:

	idProducto (numerico)
	descripcion (alfanumérico)
	nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
	tipo (numérico)
	precio (numérico decimal)
Agregar la estructura etipoProducto, que definirá los siguientes campos:

	idTipo (numérico)
	descripcionTipo(alfanumérico)

Para esta estructura en principio trabajaremos con datos hardcodeados:

	idTipo descripcionTipo
	1000 Iphone
	1001 Ipad
	1002 Mac
	1003 Accesorios

Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
ALTA Producto:
Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
Al momento de dar de alta el producto, el usuario podrá elegir el tipo de producto, de una lista que se le desplegará en pantalla.
BAJA Producto:
A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
MODIFICACIÓN Producto:
A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
Si modifica el tipo de producto, se utilizara el mismo criterio que para dar de alta.
LISTADO Productos.
LISTADO ordenado por precio.
LISTADO ordenado por descripción.
Agregar los siguientes informes:
El/los  productos más caros.
Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.
Se agregan los siguientes listados:
El listado de todos los productos con la descripción del tipo.
Por cada tipo la lista de productos.
CELESTE CISTERNAS 1RO B
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define T 2
#define N 3
#define P 4
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int idNacionalidad;
	char descripcionNacionalidad[20];
}eNacionalidad;//ESTRUCTURA NACIONALIDAD

typedef struct
{
	int idTipo;
	char descripcionTipo[20];
}eTipoProducto;//ESTRUCTURA TIPO

typedef struct
{
	int idProducto;
	char descripcionProducto[20];
	int idNacionalidad;
	float precio;
	int idTipo;
	int isEmpty;
}eProducto; //ESTRUCTURA PRODUCTO

int idDinamico=0;

//INICIAR ABM
int IdDinamico();
void Iniciar(eProducto[], int);
int BuscarLibre(eProducto[], int);
//FUNCIONES ALTA
int CargarProductos(eProducto[],int,eTipoProducto[],int,eNacionalidad[],int);
eProducto PedirProductos(eTipoProducto[],int,eNacionalidad[],int);
void MostrarProducto(eProducto);
void MostrarListaProductos(eProducto listaProducto[],int tamP);
void MostrarListaProductosCompleto(eProducto lista[], int tam,eNacionalidad listaN[],int tamN,eTipoProducto listaT[],int tamT);
//FUNCIONES RELACION PK FK
void MostrarPorNacionalidad(eProducto[],int,eNacionalidad[],int);
void MostrarUnaNacionalidad(eNacionalidad);
void MostrarListaNacionalidades(eNacionalidad[],int);
void MostrarPorTipo(eProducto[],int,eTipoProducto[],int);
void MostrarUnTipo(eTipoProducto);
void MostrarListaTipos(eTipoProducto[],int);
int CargarNacionalidad(int,eNacionalidad[],int,char[]);
void MostrarConTodo(eProducto,eNacionalidad[],int,eTipoProducto[],int);
int CargarTipo(int id, eTipoProducto listaTipo[],int tamT,char descripcion[]);
//void MostrarTodo(eProducto[],int,eTipoProducto[],int,eNacionalidad[],int);
//BAJAS
void EliminarProducto(eProducto[], int);
//MODIFICACION
void ModificarProducto(eProducto[],int);

int main(void)
{
	setbuf(stdout, NULL);
	int i;
	int carga;

	eProducto miProducto[T];
	eTipoProducto miTipoProducto[P]={{1000,"IPHONE"},{1001,"IPAD"},{1002,"MAC"},{1003,"ACCESORIOS"}};
	eNacionalidad miNacionalidad[N]={{1,"EEUU"},{2,"CHINA"},{3,"OTRO"}};

	Iniciar(miProducto,T);

	for(i=0;i<T;i++)
	{
		carga=CargarProductos(miProducto,T,miTipoProducto,P,miNacionalidad,N);
		if(carga==-1)
		{
			printf("\nNo se encontro espacio libre\n");
		}else
		{
			printf("\nSe cargaron los datos con exito\n");
		}
	}
	 MostrarListaProductosCompleto(miProducto,T,miNacionalidad,N,miTipoProducto,P);
	 EliminarProducto(miProducto,T);
	 MostrarListaProductosCompleto(miProducto,T,miNacionalidad,N,miTipoProducto,P);
	//MostrarConNacionalidad(unProducto,miNacionalidad,N);
	//MostrarPorNacionalidad(miProducto,T,miNacionalidad,N);
	//MostrarTipo(miProducto,T,miTipoProducto,T);
	//MostrarTodo(miProducto,T,miTipoProducto,P,miNacionalidad,N);

	return EXIT_SUCCESS;

}
int IdDinamico()
{
	return idDinamico += 1;
}
void Iniciar(eProducto lista[],int tam)//INICIO LA ESTRUCTURA COMO VACIO
{
	int i;

	for(i=0;i<tam;i++)
	{
		lista[i].isEmpty=VACIO;
	}
}
int BuscarLibre(eProducto lista[], int tam)//BUSCO LUGARES LIBRES
{
	int i;
	int index=-1;

	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty==VACIO)
		{
			index=i;
			break;
		}
	}
	return index;
}
int BuscarProducto(eProducto listaProducto[], int tamP, int id)
{
	int i;
    int indice = -1;

    for(i = 0; i < tamP; i++)
    {
        if(listaProducto[i].isEmpty==OCUPADO && listaProducto[i].idProducto == id)
        {
        	indice = i;
            break;
        }
    }
    return indice;
}
eProducto PedirProductos(eTipoProducto listaTipo[],int tamT,eNacionalidad listaNacionalidad[],int tamN)//FUNCION QUE LE PIDE AL USUARIO LOS DATOS
{
	eProducto datos;
	//ID DINAMICO
	datos.idProducto=IdDinamico();
	//INGRESE DESCRIPCION
	printf("Ingrese la descripcion del producto: \n");
	fflush(stdin);
	scanf("%[^\n]",datos.descripcionProducto);
	//INGRESE ID DE LA LISTA
	MostrarListaNacionalidades(listaNacionalidad,tamN);
	printf("Ingrese el ID de nacionalidad: \n");
	scanf("%d",&datos.idNacionalidad);
	//INGRESE ID DE LA LISTA
	MostrarListaTipos(listaTipo,tamT);
	printf("Ingrese el ID del tipo de producto: \n");
	scanf("%d",&datos.idTipo);
	//INGRESE EL PRECIO MAYOR A CERO
	printf("Ingrese el precio: \n");
	scanf("%f",&datos.precio);
	while(datos.precio<0)
	{
		printf("Error, reingrese el precio");
		scanf("%f",&datos.precio);
	}
	//ESTADO OCUPADO
	datos.isEmpty=OCUPADO;

	return datos;
}
int CargarProductos(eProducto lista[],int tam,eTipoProducto listaTipo[],int tamT,eNacionalidad listaNacionalidad[], int tamN)//FUNCION QUE SE FIJA SI HAY LUGAR LIBRE Y CARGA EN ESE ESPACIO LOS DATOS PEDIDOS EN FUNCION PEDIR
{
	int aux;
	aux=BuscarLibre(lista,tam);

	if(aux!=-1)
	{
		lista[aux]=PedirProductos(listaTipo,tamT,listaNacionalidad,tamN);
	}
	return aux;
}
void MostrarProducto(eProducto unProducto)//FUNCION MOSTRAR SIMPLE, MUESTRA 1 LISTA DE PRODUCTOS
{
	printf("El ID es: %d \n"
			"La descripcion del producto es: %4s\n"
			"La nacionalidad es: %4d\n"
			"El tipo de producto es: %4d\n"
			"El precio es: %.2f\n", unProducto.idProducto,
			                        unProducto.descripcionProducto,
									unProducto.idNacionalidad,
									unProducto.idTipo,
									unProducto.precio);
}
void MostrarListaProductos(eProducto listaProducto[],int tamP)
{
	int i;

	for(i=0;i<tamP;i++)
	{
		if(listaProducto[i].isEmpty==OCUPADO)
		{
			MostrarProducto(listaProducto[i]);
		}
		else
		{
			printf("No se han ingresado productos");
		}
	}
}
void MostrarListaProductosCompleto(eProducto lista[], int tam,eNacionalidad listaN[],int tamN,eTipoProducto listaT[],int tamT)//FUNCION QUE LLAMA A FUNCION MOSTRAR Y MUESTRA UNA LISTA DE PRODUCTOS
{
	int i;

	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty==OCUPADO)
		{
			MostrarConTodo(lista[i],listaN,tamN,listaT,tamT);
		}
	}
}
void MostrarPorNacionalidad(eProducto listaProducto[],int tamP,eNacionalidad listaNacionalidad[],int tamN)//
{
	int i;
	int j;
	for(i=0;i<tamP;i++)//PK PRODUCTO Y FK NACIONALIDAD
	{
		for(j=0;j<tamN;j++)
		{
			if(listaProducto[i].idNacionalidad==listaNacionalidad[j].idNacionalidad)
			{
				printf("El ID es: %4d \n"
						"La descripcion del producto es: %4s\n"
						"La nacionalidad es: %4s\n"
						"El tipo de producto es: %4d\n"
						"El precio es: %.2f\n", listaProducto[i].idProducto,
						                        listaProducto[i].descripcionProducto,
												listaNacionalidad[j].descripcionNacionalidad,
												listaProducto[i].idTipo,
												listaProducto[i].precio);
				break;
			}
		}
	}
}
void MostrarUnaNacionalidad(eNacionalidad unaNacionalidad)
{
	printf("\n%d . %s\n", unaNacionalidad.idNacionalidad,
			        unaNacionalidad.descripcionNacionalidad);
}
void MostrarListaNacionalidades(eNacionalidad listaNacionalidad[],int tam)
{
	int i;
	printf("\n> LISTA DE NACIONALIDADES:");
	for(i=0;i<tam;i++)
	{
		MostrarUnaNacionalidad(listaNacionalidad[i]);
	}
}
void MostrarPorTipo(eProducto listaProducto[],int tamP,eTipoProducto listaTipo[],int tamT)
{
	int i;
	int j;

	for(i=0;i<tamP;i++)//PK PRODUCTO Y FK TIPO
	{
		for(j=0;j<tamT;j++)
		{
			if(listaProducto[i].idTipo==listaTipo[j].idTipo)
			{
				printf("El ID es: %4d \n"
						"La descripcion del producto es: %4s\n"
						"La nacionalidad es: %d\n"
						"El tipo de producto es: %4s\n"
						"El precio es: %.2f\n", listaProducto[i].idProducto,
						                        listaProducto[i].descripcionProducto,
												listaProducto[i].idNacionalidad,
												listaTipo[j].descripcionTipo,
												listaProducto[i].precio);
			}
		}
	}
}

void MostrarUnTipo(eTipoProducto unTipo)
{
	printf("\n %d . %s\n", unTipo.idTipo,
			             unTipo.descripcionTipo);
}
void MostrarListaTipos(eTipoProducto listaTipo[],int tam)
{
	int i;
	printf("\n> LISTA DE TIPOS:");
	for(i=0; i<tam; i++)
	{
		MostrarUnTipo(listaTipo[i]);
	}
}
int CargarNacionalidad(int id,eNacionalidad listaNacionalidad[],int tamN,char descripcion[])
{
	int i;
	int todoOk=-1;
	if(listaNacionalidad != NULL && tamN > 0 && descripcion != NULL)
	    {
	        for(i = 0; i < tamN; i++)
	        {
	            if(listaNacionalidad[i].idNacionalidad==id)
	            {
	                strcpy(descripcion, listaNacionalidad[i].descripcionNacionalidad);
	                todoOk = 1;
	                break;
	            }
	        }
	    }
	return todoOk;
}
int CargarTipo(int id, eTipoProducto listaTipo[],int tamT,char descripcion[])
{
	int i;
	int todoOk=-1;
	if(listaTipo != NULL && tamT > 0 && descripcion != NULL)
    {
		for(i = 0; i < tamT; i++)
		{
			if(listaTipo[i].idTipo==id)
			{
				strcpy(descripcion, listaTipo[i].descripcionTipo);
				todoOk = 1;
				break;
			}
		}
    }
	return todoOk;
}
void MostrarConTodo(eProducto unProducto,eNacionalidad listaN[],int tamN,eTipoProducto listaT[],int tamT)
{
    char descripcionN[20];
    char descripcionT[20];

    CargarNacionalidad(unProducto.idNacionalidad, listaN, tamN, descripcionN);
    CargarTipo(unProducto.idTipo,listaT,tamT,descripcionT);

    printf("El ID es: %4d \n"
    	   "La descripcion del producto es: %4s\n"
           "La nacionalidad es: %s\n"
           "El tipo de producto es: %4s\n"
    	   "El precio es: %.2f\n", unProducto.idProducto,
		   	   	   	   	   	   	   unProducto.descripcionProducto,
								   descripcionN,
								   descripcionT,
								   unProducto.precio);
}

void EliminarProducto(eProducto listaProducto[], int tamP)//PIDE ID Y BUSCA EN LA LISTA EL MISMO PARA VACIAR LOS DATOS Y DEJARLO LIBRE DE NUEVO
{
	int id;
	int indice;
	char respuesta;

	MostrarListaProductos(listaProducto,tamP);
	printf("Ingrese el ID del producto a eliminar: \n");
	scanf("%d",&id);
	indice=BuscarProducto(listaProducto,tamP,id);

	if(indice!=-1)
	{
		printf("-----------------------------------\n");
		MostrarProducto(listaProducto[indice]);
		printf("Esta seguro que desea eliminarlo? [y/n]\n");
		fflush(stdin);
		scanf("%c",&respuesta);
		if(respuesta=='y')
		{
			printf("Se ha borrado con exito");
			listaProducto[indice].isEmpty=VACIO;
			//MostrarListaProductos(listaProducto,tamP);
		}else
		{
			printf("No se han realizado cambios");
		}
	}
	else
	{
		printf("No se encontro un producto con ese ID");
	}
}
void ModificarProducto(eProducto listaProducto[],int tamP)
{
	int i;
	int idProducto;

	printf("Ingrese el ID del producto a modificar: \n");
	scanf("%d",&idProducto);

	for(i=0;i<tamP;i++)
	{
		if(listaProducto[i].idProducto==idProducto)
		{

		}
	}
}

