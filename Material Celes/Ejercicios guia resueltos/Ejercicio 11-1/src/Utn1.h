/*
 * utn.h
 *
 *  Created on: 8 may. 2021
 *      Author: celes
 */

#ifndef UTN1_H_
#define UTN1_H_

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



#endif /* UTN1_H_ */
