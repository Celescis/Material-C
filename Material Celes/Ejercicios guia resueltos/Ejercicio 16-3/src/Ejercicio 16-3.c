/*
 ============================================================================
Ejercicio 16-3:
Realizar una funci�n que respete el siguiente prototipo:
int Calculador(int, int(*pFunc)(int, int), int, int*);
Dicha funci�n deber� recibir dos operandos y un operador representado mediante la funci�n pasada como par�metro.
El puntero a entero, servir� como par�metro de salida y guardar� el resultado de la operaci�n.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Calculador(int, int(*pFunc)(int, int), int, int*);
int Sumar(int a,int b);

int main(void)
{
	setbuf(stdout,NULL);
	int op1;
	int op2;
	int resultados;

	printf("Ingrese un numero: ");
	scanf("%d",&op1);
	printf("Ingrese un numero: ");
	scanf("%d",&op2);

	if(!Calculador(op1,Sumar,op2,&resultados))
	{
		printf("El resultado es: %d",resultados);
	}
	else
	{
		printf("Algo salio mal");
	}
	return EXIT_SUCCESS;
}

int Calculador(int operador1, int(*pFunc)(int, int), int operador2, int* resultado)
{
	int isOk=-1;

	if(resultado!=NULL && pFunc!=NULL)
	{
		*resultado = pFunc(operador1,operador2);
		isOk=0;
	}

	return isOk;
}

int Sumar(int a,int b)
{
	return a+b;
}
