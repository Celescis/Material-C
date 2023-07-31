#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/**
 * @brief Reemplaza en la palabra, la primera letra por la segunda
 *
 * @param palabra
 * @param unaLetra
 * @param otraLetra
 * @return
 */
int CantidadReemplazos(char palabra[], char unaLetra, char otraLetra);
/**
 * @brief Calcula la cantidad de divisores que tiene el numero
 *
 * @param numero
 * @return
 */
int CantidadDivisores(int numero);
/**
 * @brief Cambia de lugar las letras, invirtiendo la palabra
 *
 * @param cadena
 * @return
 */
int InvertirCadena(char cadena[]);
/**
 * @brief
 *
 * @param array
 * @param caracter
 * @return
 */
int BuscarCaracter(char array[], char caracter);
/**
 * @brief Ordena el nombre y apellido como "Apellido, Nombre"
 *
 * @param nombre
 * @param apellido
 * @return
 */
int ReacomodarPalabras(char nombre[], char apellido[]);

#endif /* FUNCIONES_H_ */
