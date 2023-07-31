/******************************************************************************

Ejercicio 8-1:
Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
Crear una función que permita cargar los datos de un jugador y otra que los muestre.
Una tercera función calculará el promedio de goles.

CELESTE CISTERNAS 1RO B
*******************************************************************************/


#include <stdio.h>

typedef struct
{
    char nombre[20];
    int goles_metidos;
    int partidos_jugados;
    float promedio_goles;
}eJugador;

eJugador PedirDatos();
void MostrarDatos(eJugador);
float Promedio(int, int);


int main()
{
	setbuf(stdout,NULL);
	eJugador miJugador;


	miJugador=PedirDatos();
	MostrarDatos(miJugador);

	return 0;
}

eJugador PedirDatos()
{
    eJugador data;

    printf("Ingrese nombre: ");
	scanf("%s", data.nombre);
	printf("Ingrese la cantidad de goles: ");
	fflush(stdin);
	scanf("%d", &data.goles_metidos);
	printf("Ingrese la cantidad de partidos jugados: ");
	scanf("%d", &data.partidos_jugados);

    return data;
}

void MostrarDatos(eJugador data)
{
    data.promedio_goles=Promedio(data.goles_metidos,data.partidos_jugados);

    printf("El jugador %s hizo %d goles en %d partidos y el promedio de goles es %.2f", data.nombre,
                                                                                        data.goles_metidos,
                                                                                        data.partidos_jugados,
                                                                                        data.promedio_goles);
}

float Promedio(int goles, int partidos)
{
	float pr;

	pr = goles / partidos;

	return pr;
}
