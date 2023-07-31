#ifndef PARSER_H_
#define PARSER_H_
/**
 * @brief Funcion que convierte los datos del archivo a los datos de la estructura
 *
 * @param pFile recibe el path
 * @param pArrayListLibro recibe la lista de libros
 * @return int devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int parser_libroFromText(FILE* pFile , LinkedList* pArrayListLibro);

#endif /* PARSER_H_ */
