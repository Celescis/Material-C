#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libro.h"

eLibro* libro_new(void)
{
	eLibro* pLibro = NULL;
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int editorialId;

	id=0;
	strcpy(titulo,"\0");
	strcpy(autor,"\0");
	precio=0;
	editorialId=0;

	pLibro = (eLibro*) malloc(sizeof(eLibro));

	if(pLibro!=NULL)
	{
		libro_setVerifyInt(pLibro,id,titulo,autor,precio,editorialId);
	}

	return pLibro;
}

eLibro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialIdStr)
{
	eLibro* pLibroParam = NULL;

	if(idStr!=NULL && tituloStr!=NULL && autorStr!=NULL && precioStr!=NULL && editorialIdStr!=NULL)
	{
		pLibroParam = libro_new();

		if(pLibroParam!=NULL)
		{
			if((libro_setVerifyChar(pLibroParam,idStr,tituloStr,autorStr,precioStr,editorialIdStr))!=0)
			{
				libro_delete(pLibroParam);
			}
		}
	}

	return pLibroParam;
}

void libro_delete(eLibro* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

int BuscarIdEditorial(char* nombre, int* id)
{
	int isOk = -1;
	int idAux[6]={1,2,3,4,5,6};
	char nombreAux[6][25]={"PLANETA","SIGLO XXI EDITORES","PEARSON","MINOTAURO","SALAMANDRA","PENGUIN BOOKS"};

	if(nombre!=NULL && id!=NULL)
	{
		for(int i=0;i<6;i++)
		{
			if(!stricmp(nombreAux[i],nombre))
			{
				*id=idAux[i];
				isOk=0;
			}
		}
	}

	return isOk;
}

int BuscarNombreEditorial(int id, char* nombre)
{
	int isOk = -1;
	int idAux[6]={1,2,3,4,5,6};
	char nombreAux[6][25]={"PLANETA","SIGLO XXI EDITORES","PEARSON","MINOTAURO","SALAMANDRA","PENGUIN BOOKS"};

	if(nombre!=NULL && id>0)
	{
		for(int i=0;i<6;i++)
		{
			if(idAux[i]==id)
			{
				strcpy(nombre,nombreAux[i]);
				isOk=0;
			}
		}
	}

	return isOk;
}

//---------------------------------------------SETTERS---------------------------------------------
int libro_setId(eLibro* this, int id)
{
	int isOk = -1;

	if(this!=NULL && id>0)
	{
		this->id = id;
		isOk=0;
	}

	return isOk;
}

int libro_setTitulo(eLibro* this, char* titulo)
{
	int isOk = -1;

	if(this!=NULL && titulo!=NULL)
	{
		strcpy(this->titulo,titulo);
		isOk=0;
	}

	return isOk;
}

int libro_setAutor(eLibro* this, char* autor)
{
	int isOk = -1;

	if(this!=NULL && autor!=NULL)
	{
		strcpy(this->autor,autor);
		isOk=0;
	}

	return isOk;
}

int libro_setPrecio(eLibro* this, float precio)
{
	int isOk = -1;

	if(this!=NULL && precio>0)
	{
		this->precio = precio;
		isOk=0;
	}

	return isOk;
}

int libro_setEditorialId(eLibro* this, int editorialId)
{
	int isOk = -1;

	if(this!=NULL && editorialId>0)
	{
		this->editorialId = editorialId;
		isOk=0;
	}

	return isOk;
}

//---------------------------------------------GETTERS---------------------------------------------
int libro_getId(eLibro* this, int* id)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		isOk=0;
	}

	return isOk;
}
int libro_getTitulo(eLibro* this, char* titulo)
{
	int isOk = -1;

	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo,this->titulo);
		isOk=0;
	}

	return isOk;
}

int libro_getAutor(eLibro* this, char* autor)
{
	int isOk = -1;

	if(this!=NULL && autor!=NULL)
	{
		strcpy(autor,this->autor);
		isOk=0;
	}

	return isOk;
}

int libro_getPrecio(eLibro* this, float* precio)
{
	int isOk = -1;

	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		isOk=0;
	}

	return isOk;
}

int libro_getEditorialId(eLibro* this, int* editorialId)
{
	int isOk = -1;

	if(this!=NULL && editorialId!=NULL)
	{
		*editorialId = this->editorialId;
		isOk=0;
	}

	return isOk;
}

//----------------------------------VERIFICACIONES GET Y SET----------------------------------
int libro_setVerifyChar(eLibro* this, char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialIdStr)
{
	int isOk = -1;

	if(this!=NULL && idStr!=NULL && tituloStr!=NULL && autorStr!=NULL && precioStr!=NULL && editorialIdStr!=NULL)
	{
		if((!(libro_setId(this,atoi(idStr))) &&
			!(libro_setTitulo(this,tituloStr)) &&
			!(libro_setAutor(this,autorStr)) &&
			!(libro_setPrecio(this,atof(precioStr))) &&
			!(libro_setEditorialId(this,atoi(editorialIdStr)))))
		{
			isOk=0;
		}
	}

	return isOk;
}

int libro_setVerifyInt(eLibro* this, int id, char* titulo, char* autor, float precio, int editorialId)
{
	int isOk = -1;

	if(this!=NULL && id>0 && titulo!=NULL && autor!=NULL && precio>0 && editorialId>0)
	{
		if((!(libro_setId(this,id)) &&
			!(libro_setTitulo(this,titulo)) &&
			!(libro_setAutor(this,autor)) &&
			!(libro_setPrecio(this,precio)) &&
			!(libro_setEditorialId(this,editorialId))))
		{
			isOk=0;
		}
	}

	return isOk;
}

int libro_getVerify(eLibro* this, int* id, char* titulo, char* autor, float* precio, int* editorialId)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL && titulo!=NULL && autor!=NULL && precio!=NULL && editorialId!=NULL)
	{
		if((!(libro_getId(this,id)) &&
			!(libro_getTitulo(this,titulo)) &&
			!(libro_getAutor(this,autor)) &&
			!(libro_getPrecio(this,precio)) &&
			!(libro_getEditorialId(this,editorialId))))
		{
			isOk=0;
		}
	}

	return isOk;
}

//---------------------------------------------PRINT---------------------------------------------
int libro_printOneLibro(eLibro* this)
{
	int isOk = -1;
	int auxiliarID;
	char auxiliarTitulo[128];
	char auxiliarAutor[128];
	float auxiliarPrecio;
	int auxiliarEditorialId;
	char editorial[128];

	if(this!=NULL)
	{
		if(!libro_getVerify(this,&auxiliarID,auxiliarTitulo,auxiliarAutor,&auxiliarPrecio,&auxiliarEditorialId))
		{
			BuscarNombreEditorial(auxiliarEditorialId,editorial);
			printf("| %2d |%-50s|%-16s|$%-7.2f|     %2d     |%-18s|\n",auxiliarID
												 	 	 	 	 	  ,auxiliarTitulo
																	  ,auxiliarAutor
																	  ,auxiliarPrecio
																	  ,auxiliarEditorialId
																	  ,editorial);
			isOk=0;
		}
		else
		{
			printf("Error para mostrar el libro");
		}
	}

	return isOk;
}

int libro_printList(LinkedList* listaLibros)
{
	int isOk = -1;
	int len;
	int i;
	eLibro* aux = NULL;

	if(listaLibros!=NULL)
	{
		len = ll_len(listaLibros);

		if(len>0)
		{
			printf(" _________________________________________________________________________________________________________________\n");
			printf("| ID |                     TITULO                       |      AUTOR     | PRECIO |ID EDITORIAL| NOMBRE EDITORIAL |\n");
			printf("|____|__________________________________________________|________________|________|____________|__________________|\n");

			for(i=0; i<len ;i++)
			{
				aux = (eLibro*) ll_get(listaLibros,i);

				if(aux != NULL)
				{
					libro_printOneLibro(aux);
					isOk=0;
				}
			}
			printf("|____|__________________________________________________|________________|________|____________|__________________|\n");
		}
	}

	return isOk;
}

//---------------------------------------------COMPARE---------------------------------------------
int libro_compareByAutor(void* libro1, void* libro2)
{
	int resultado = -1;
	eLibro* lib1 = NULL;
	eLibro* lib2 = NULL;
	char nombre1[128];
	char nombre2[128];

	if(libro1!=NULL && libro2!=NULL)
	{
		lib1 = (eLibro*) libro1;
		lib2 = (eLibro*) libro2;

		if((!libro_getAutor(lib1,nombre1)) && (!libro_getAutor(lib2,nombre2)))
		{
			resultado = strcmp(nombre1,nombre2);
		}
	}

	return resultado;
}

//---------------------------------------------MAPEO---------------------------------------------
void* libro_descuentos(void* libros)
{
	eLibro* pElement = NULL;
	int auxId;
	float auxPrecio;
	float newPrecio=0;
	char auxNombre[128];

	if(libros!=NULL)
	{
		pElement= (eLibro*) libros;
		if(!libro_getEditorialId(pElement,&auxId))
		{
			BuscarNombreEditorial(auxId,auxNombre);
			if(stricmp(auxNombre,"Planeta")==0)
			{
				libro_getPrecio(pElement,&auxPrecio);
				if(auxPrecio>=300)
				{
					newPrecio=auxPrecio-(auxPrecio*20/100);
					libro_setPrecio(pElement,newPrecio);
				}
			}
			else
			{
				if(stricmp(auxNombre,"SIGLO XXI EDITORES")==0)
				{
					libro_getPrecio(pElement,&auxPrecio);
					if(auxPrecio<=200)
					{
						newPrecio=auxPrecio-(auxPrecio*10/100);
						libro_setPrecio(pElement,newPrecio);
					}
				}
			}
		}
	}

	return pElement;
}

