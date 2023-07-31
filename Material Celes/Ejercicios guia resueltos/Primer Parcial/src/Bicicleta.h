/*
 * biblioteca.h
 *
 *  Created on: 20 may. 2021
 *      Author: celes
 */

#ifndef BICICLETA_H_
#define BICICLETA_H_
#define B 5

typedef struct
{
	int id;
	char marca[25];
	int rodado;
	char color[25];
}eBicicleta;

void HardcodeoBicicleta(eBicicleta bicicletas[]);



#endif /* BICICLETA_H_ */
