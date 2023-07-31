#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Venta.h"
#include "Menus.h"
#include "Utn.h"

Venta* venta_new(void)//ME HABILITA UNA DIRECCION DE MEMORIA PARA UN NUEVO EMPLEADO
{
	Venta* pVenta = NULL;
	int id;
	char nombre[128];
	int dia;
	int horario;
	int sala;
	int entrada;

	id=0;
	strcpy(nombre,"\0");
	dia=0;
	horario=0;
	sala=0;
	entrada=0;

	pVenta = (Venta*) malloc(sizeof(Venta));

	if(pVenta!=NULL)
	{
		venta_setVerifyInt(pVenta,id,nombre,dia,horario,sala,entrada);
	}

	return pVenta;
}

Venta* venta_newParametros(char* idStr, char* nombreStr, char* diaStr, char* horarioStr, char* salaStr, char* entradaStr)
{
	Venta* pVentaParam = NULL;

	if(idStr!=NULL && nombreStr!=NULL && diaStr!=NULL && horarioStr!=NULL && salaStr!=NULL && entradaStr!=NULL)
	{
		pVentaParam = venta_new();

		if(pVentaParam!=NULL)
		{
			if((venta_setVerifyChar(pVentaParam,idStr,nombreStr,diaStr,horarioStr,salaStr,entradasStr))!=0)
			{
				venta_delete(pVentaParam);
			}
		}
	}

	return pVentaParam;
}

void venta_delete(Venta* this)//PASAR A INT PARA VERIFICAR SI SALIO BIEN?
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

int ObtenerMayorId (LinkedList* listaVenta)
{
	int mayorId=0;
	int id;
	int len;
	int i;
	Venta* aux;

	if(listaVenta!=NULL)
	{
		len = ll_len(listaVenta);

		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				aux = (Venta*)ll_get(listaVenta,i);
				venta_getId(aux,&id);

				if(i==0 || (mayorId<id))
				{
					mayorId=id;
				}
			}
		}
	}

	return mayorId;
}

int venta_printOneVenta(Venta* this)
{
	int isOk = -1;
	int auxiliarID;
	char auxiliarNombre[128];
	int auxiliarHoras;
	int auxiliarSueldo;

	if(this!=NULL)
	{
		if(!venta_getVerify(this,&auxiliarID,auxiliarNombre,&auxiliarHoras,&auxiliarSueldo))
		{
			printf("%d\t%-10s\t%d\t%d\n",auxiliarID
										,auxiliarNombre
										,auxiliarHoras
										,auxiliarSueldo);
			isOk=0;
		}
		else
		{
			printf("Error para mostrar el empleado");
		}
	}

	return isOk;
}

int venta_printList(LinkedList* listaVenta)
{
	int isOk = -1;
	int len;
	int i;
	Venta* aux = NULL;

	if(listaVenta!=NULL)
	{
		len = ll_len(listaVenta);

		if(len>0)
		{
			printf("ID\tNOMBRE\t\tHORAS\tSUELDO\n");

			for(i=0; i<len ;i++)
			{
				aux = (Venta*) ll_get(listaVenta,i);

				if(aux != NULL)
				{
					venta_printOneVenta(aux);
					isOk=0;
				}
			}
		}
	}

	return isOk;
}

int venta_findID(LinkedList* listaVenta, int id)
{
	int i;
	int len;
	int index;
	Venta* auxiliar;

	if(listaVenta!=NULL)
	{
		len = ll_len(listaVenta);

		if(len>0)
		{
			for(i=0; i<len ;i++)
			{
				auxiliar = (Venta*)ll_get(listaVenta,i);
				if(auxiliar->id==id)
				{
					index=i;
					break;
				}
			}
		}
	}

	return index;
}

int venta_add(LinkedList* listaVenta, int* id)
{
	int isOk = -1;
	char respuesta[4];
	int auxiliarID;
	char auxiliarNombre[128];
	int auxiliarHoras;
	int auxiliarSueldo;
	Venta* auxEmpleado = NULL;

	if(listaVenta!=NULL && id!=NULL)
	{
		auxEmpleado = venta_new();

		if(auxEmpleado!=NULL)
		{
			if((!(utn_getString("\nIngrese el nombre: ","\nError, reingrese: ",128,3,auxiliarNombre)) &&
				!(utn_getInt("\nIngrese las horas trabajadas: ","\nError, reingrese: ",1,400,3,&auxiliarHoras)) &&
				!(utn_getInt("\nIngrese sueldo: ","\nError, reingrese: ",1,10000,3,&auxiliarSueldo))))
			{
				SizeString(auxiliarNombre);
				auxiliarID = *id;
				auxiliarID+=1;

				if(!venta_setVerifyInt(auxEmpleado,auxiliarID,auxiliarNombre,auxiliarHoras,auxiliarSueldo))
				{
					venta_printOneVenta(auxEmpleado);
					utn_getString("\n¿Esta seguro que desea guardar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

					if(!(stricmp(respuesta,"si")))
					{
						ll_add(listaVenta, auxEmpleado);
						*id=auxiliarID;
						isOk=0;
					}
					else
					{
						venta_delete(auxEmpleado);
					}
				}
			}
			else
			{
				printf("\nReintente nuevamente");
			}
		}
		else
		{
			printf("No hay espacio para un nuevo empleado");
		}
	}

	return isOk;
}

int venta_remove(LinkedList* listaVenta)
{
	int isOk = -1;
	int id;
	int index = -1;
	char respuesta[4];
	Venta* aux = NULL;

	if(listaVenta!=NULL)
	{
		venta_printList(listaVenta);
		utn_getInt("Ingrese el ID para dar de baja: \n","Error, ID invalido\n",1,5000,3,&id);
		index = venta_findID(listaVenta,id);

		if(index!=-1)
		{
			aux = ll_get(listaVenta,index);
			venta_printOneVenta(aux);
			utn_getString("\n¿Esta seguro que desea eliminar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

			if(!(stricmp(respuesta,"si")))
			{
				ll_remove(listaVenta,index);
				printf("Baja realizada con exito\n");
			}
			else
			{
				printf("Baja cancelada\n");
			}
		}
		else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}

	return isOk;
}

int venta_modify(LinkedList* listaVenta)
{
	int isOk = -1;
	int id;
	int index = -1;
	char respuesta[4];
	char confirmar[4];
	Venta* aux;
	Venta auxiliar;
	strcpy(confirmar,"no");

	if(listaVenta!=NULL)
	{
		venta_printList(listaVenta);
		utn_getInt("Ingrese el ID para modificar\n","Error, ID invalido\n",1,5000,3,&id);
		index = venta_findID(listaVenta,id);

		if(index!=-1)
		{
			aux = (Venta*) ll_get(listaVenta,index);
			auxiliar=*aux;
			venta_printOneVenta(&auxiliar);
			utn_getString("\n¿Esta seguro que desea editar este empleado?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

			if(!(stricmp(respuesta,"si")))
			{
				do
				{
					switch(venta_menuModify())
					{
						case 0:
							utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
							break;
						case 1:
							venta_caseNombre(listaVenta,index,auxiliar);
							break;
						case 2:
							venta_caseHoras(listaVenta,index,auxiliar);
							break;
						case 3:
							venta_caseSueldo(listaVenta,index,auxiliar);
							break;
					}
				}while(stricmp(confirmar,"si"));
				printf("Modificacion realizada con exito\n");
			}
			else
			{
				printf("Modificacion cancelada\n");
			}
		}
		else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}
	else
	{
		printf("Error. Imposible realizar una modificacion\n");
	}

	return isOk;
}

int venta_caseNombre(LinkedList* listaVenta, int index, Venta auxiliar)
{
	int isOk = -1;
	char auxNombre[128];
	int opciones;

	if(listaVenta!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR NOMBRE****\t\n");
		utn_getString("Ingrese el nuevo nombre\n","Error, nombre invalido\n",128,3,auxNombre);
		SizeString(auxNombre);

		strcpy(auxiliar.nombre,auxNombre);
		venta_printOneVenta(&auxiliar);

		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			venta_modifyNombre(listaVenta,index,auxNombre);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}

	return isOk;
}

int venta_caseHoras(LinkedList* listaVenta, int index, Venta auxiliar)
{
	int isOk = -1;
	int auxHoras;
	int opciones;

	if(listaVenta!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR HORAS****\t\n");
		utn_getInt("Ingrese la nueva cantidad de horas\n","Error, cantidad invalida\n",1,100,3,&auxHoras);
		auxiliar.horasTrabajadas=auxHoras;
		venta_getHorasTrabajadas(&auxiliar,&auxHoras);
		venta_printOneVenta(&auxiliar);
		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			venta_modifyHorasTrabajadas(listaVenta,index,auxHoras);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}
	return isOk;
}

int venta_caseSueldo(LinkedList* listaVenta, int index, Venta auxiliar)
{
	int isOk = -1;
	int auxSueldo;
	int opciones;

	if(listaVenta!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR SUELDO****\t\n");
		utn_getInt("Ingrese el nuevo sueldo \n","Error, cantidad invalida\n",1000,100000,3,&auxSueldo);
		auxiliar.sueldo=auxSueldo;
		venta_printOneVenta(&auxiliar);
		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			venta_modifySueldo(listaVenta,index,auxSueldo);
			isOk=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}
	return isOk;
}

int venta_setVerifyChar(Venta* this, char* idStr, char* nombreStr, char* diaStr, char* horarioStr, char* salaStr, char* entradaStr)
{
	int isOk = -1;

	if(this!=NULL && idStr!=NULL && nombreStr!=NULL && diaStr!=NULL && entradaStr!=NULL)
	{
		if((!(venta_setId(this,atoi(idStr))) &&
		!(venta_setNombre(this,nombreStr)) &&
		!(venta_setDia(this,atoi(diaStr))) &&
		!(venta_setHorario(this,atoi(horarioStr))) &&
		!(venta_setSala(this,atoi(salaStr))) &&
		!(venta_setEntrada(this,atoi(entradaStr)))))
		{
			isOk=0;
		}
	}

	return isOk;
}

int venta_setVerifyInt(Venta* this, int id, char* nombre, int dia, int horario, int sala, int entrada)
{
	int isOk = -1;

	if(this!=NULL && id>0 && nombre!=NULL && horario>0 && sala>0 && entrada>0)
	{
		if((!(venta_setId(this,id)) &&
		!(venta_setNombre(this,nombre)) &&
		!(venta_setDia(this,dia)) &&
		!(venta_setHorario(this,horario)) &&
		!(venta_setSala(this,sala)) &&
		!(venta_setEntrada(this,entrada))))
		{
			isOk=0;
		}
	}

	return isOk;
}

int venta_getVerify(Venta* this, int* id, char* nombre, int* dia, int* horario, int* sala, int* entrada)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL && nombre!=NULL && dia!=NULL && horario!=NULL && sala!=NULL && entrada!=NULL)
	{
		if((!(venta_getId(this,id)) &&
		!(venta_getNombre(this,nombre)) &&
		!(venta_getDia(this,dia)) &&
		!(venta_getHorario(this,horario)) &&
		!(venta_getSala(this,sala)) &&
		!(venta_getEntrada(this,entrada))))
		{
			isOk=0;
		}
	}

	return isOk;
}

//---------------------------------------------SETTERS---------------------------------------------
int venta_setId(Venta* this, int id)
{
	int isOk = -1;

	if(this!=NULL && id>0)
	{
		this->id = id;
		isOk=0;
	}

	return isOk;
}

int venta_setNombre(Venta* this, char* nombre)
{
	int isOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		isOk=0;
	}

	return isOk;
}

int venta_setDia(Venta* this, int dia)
{
	int isOk = -1;

	if(this!=NULL && dia>0)
	{
		this->dia = dia;
		isOk=0;
	}

	return isOk;
}

int venta_setHorario(Venta* this, int horario)
{
	int isOk = -1;

	if(this!=NULL && horario>0)
	{
		this->horario = horario;
		isOk=0;
	}

	return isOk;
}

int venta_setSala(Venta* this, int sala)
{
	int isOk = -1;

	if(this!=NULL && sala>0)
	{
		this->sala = sala;
		isOk=0;
	}

	return isOk;
}

int venta_setEntrada(Venta* this, int entrada)
{
	int isOk = -1;

	if(this!=NULL && entrada>0)
	{
		this->entrada = entrada;
		isOk=0;
	}

	return isOk;
}

//---------------------------------------------GETTERS---------------------------------------------
int venta_getId(Venta* this, int* id)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		isOk=0;
	}

	return isOk;
}

int venta_getNombre(Venta* this, char* nombre)
{
	int isOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		isOk=0;
	}

	return isOk;
}

int venta_getDia(Venta* this, int* dia)
{
	int isOk = -1;

	if(this!=NULL && dia!=NULL)
	{
		*dia = this->dia;
		isOk=0;
	}

	return isOk;
}

int venta_getHorario(Venta* this, int* horario)
{
	int isOk = -1;

	if(this!=NULL && horario!=NULL)
	{
		*horario = this->horario;
		isOk=0;
	}

	return isOk;
}

int venta_getSala(Venta* this, int* sala)
{
	int isOk = -1;

	if(this!=NULL && sala>0)
	{
		*sala = this->sala;
		isOk=0;
	}

	return isOk;
}

int venta_getEntrada(Venta* this, int* entrada)
{
	int isOk = -1;

	if(this!=NULL && entrada>0)
	{
		*entrada = this->entrada;
		isOk=0;
	}

	return isOk;
}

//-------------------------------------------MODIFICADORES-------------------------------------------
int venta_modifyNombre(LinkedList* listaVenta, int index, char* auxNombre)
{
	int isOk = -1;
	Venta* aux;

	if(listaVenta!=NULL && index>=0 && auxNombre!=NULL)
	{
		aux = (Venta*) ll_get(listaVenta,index);
		SizeString(auxNombre);

		if(aux!=NULL)
		{
			if(!venta_setNombre(aux,auxNombre))
			{
				printf("Se cargo correctamente el nuevo nombre\n");
			}
			else
			{
				printf("No se pudo modificar el nombre\n");
			}
			isOk=0;
		}
	}

	return isOk;
}
int venta_modifyHorasTrabajadas(LinkedList* listaVenta, int index, int auxHoras)
{
	int isOk = -1;
	Venta* aux;

	if(listaVenta!=NULL && index>=0 && auxHoras>0)
	{

		aux = (Venta*) ll_get(listaVenta,index);

		if(aux!=NULL)
		{
			if(!venta_setHorasTrabajadas(aux,auxHoras))
			{
				printf("Se cargo correctamente la nueva cantidad de horas\n");
			}
			else
			{
				printf("No se pudo modificar las horas\n");
			}
			isOk=0;
		}
	}
	return isOk;
}
int venta_modifySueldo(LinkedList* listaVenta, int index, int auxSueldo)
{
	int isOk = -1;
	Venta* aux;

	if(listaVenta!=NULL && index>=0 && auxSueldo>=1000)
	{

		aux = (Venta*) ll_get(listaVenta,index);

		if(aux!=NULL)
		{
			if(!venta_setSueldo(aux,auxSueldo))
			{
				printf("Se cargo correctamente el nuevo sueldo\n");
			}
			else
			{
				printf("No se pudo modificar el sueldo\n");
			}
			isOk=0;
		}
	}
    return isOk;
}

//-----------------------------------------ORDENADORES-----------------------------------------
/*
int venta_compareById(void* venta1, void* venta2)
{
	int resultado = 0;//si son iguales
	Venta* emp1 = NULL;
	Venta* emp2 = NULL;
	int id1;
	int id2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Venta*) empleado1;
		emp2 = (Venta*) empleado2;

		if((!venta_getId(emp1,&id1)) && (!venta_getId(emp2,&id2)))
		{
			if(id1 > id2)//mayores
			{
				resultado = 1;
			}
			else
			{
				if(id1 < id2)//menores
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}
int venta_compareByNombre(void* empleado1, void* empleado2)
{
	int resultado = -1;
	Venta* emp1 = NULL;
	Venta* emp2 = NULL;
	char nombre1[128];
	char nombre2[128];

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Venta*) empleado1;
		emp2 = (Venta*) empleado2;

		if((!venta_getNombre(emp1,nombre1)) && (!venta_getNombre(emp2,nombre2)))
		{
			resultado = strcmp(nombre1,nombre2);
		}
	}

	return resultado;
}

int venta_compareByHorasTrabajadas(void* empleado1, void* empleado2)
{
	int resultado = 0;//si son iguales
	Venta* emp1;
	Venta* emp2;
	int horas1;
	int horas2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Venta*) empleado1;
		emp2 = (Venta*) empleado2;

		if((!venta_getHorasTrabajadas(emp1,&horas1)) && (!venta_getHorasTrabajadas(emp2,&horas2)))//mayores
		{
			if(horas1 > horas2)//menores
			{
				resultado = 1;
			}
			else
			{
				if(horas1 < horas2)//menores
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}

int venta_compareBySueldo(void* empleado1, void* empleado2)
{
	int resultado = 0;//si son iguales
	Venta* emp1 = NULL;
	Venta* emp2 = NULL;
	int sueldo1;
	int sueldo2;

	if(empleado1!=NULL && empleado2!=NULL)
	{
		emp1 = (Venta*) empleado1;
		emp2 = (Venta*) empleado2;

		if((!venta_getSueldo(emp1,&sueldo1)) && (!venta_getSueldo(emp2,&sueldo2)))
		{
			if(sueldo1 > sueldo2)//mayores
			{
				resultado=1;
			}
			else
			{
				if(sueldo1 < sueldo2)//menores
				{
					resultado=-1;
				}
			}
		}
	}

	return resultado;
}
*/
