/*
 ============================================================================
 Ejercicio 10-1:
Dada la estructura eAlumno (legajo, nombre, nota1, nota2, promedio), de qué manera la podría relacionar con la estructura eCurso
(idCurso, descripcion, duracion), teniendo en cuenta que un alumno puede cursar solo un curso

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define T 2

typedef struct
{
	int legajo;
	char nombre[15];
	int nota1;
	int nota2;
	float promedio;
	int idCurso;
}eAlumno;

typedef struct
{
	int idCurso;
	char descripcion[20];
	int duracion;
}eCurso;

void MostrarAlumnosPorCurso(eAlumno[], int, eCurso[],int);

int main(void) {
	setbuf(stdout, NULL);
	eAlumno miAlumno[3]=
	{
			{1000, "juan", 7, 8, 7, 105},
			{1010, "camilo", 5, 6, 5, 106},
			{1020, "ricardito", 3, 4, 4, 105}
	};
	eCurso miCurso[2]={{105, "JAVA", 10},{106,"PHP", 20}};
	MostrarAlumnosPorCurso(miAlumno,3,miCurso,2);


	return EXIT_SUCCESS;
}
void MostrarAlumnosPorCurso(eAlumno listaAlumnos[],int tamA, eCurso listaCurso[], int tamC)
{
	int i;
	int j;

	for(i=0;i<tamA;i++)
	{
		for(j=0;j<tamC;j++)
		{
			if(listaAlumnos[i].idCurso==listaCurso[j].idCurso)
			{
				printf("%4d, %15s, %4d, %4d, %.2f, %15s, %4d \n",listaAlumnos[i].legajo,
							                          	         listaAlumnos[i].nombre,
																 listaAlumnos[i].nota1,
																 listaAlumnos[i].nota2,
																 listaAlumnos[i].promedio,
																 listaCurso[j].descripcion,
																 listaCurso[j].duracion);
				break;
			}
		}
	}












}
