#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct
{
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int editorialId;
}eLibro;

/**
 * @brief Genera espacio en memoria para mi lista e inicializo en cero la estructura
 *
 * @return puntero
 */
eLibro* libro_new(void);//CONSTRUCTOR POR DEFECTO
/**
 * @brief Genera el espacio en memoria con libro_new y settea los valores que se ingresan por parametros
 *
 * @param idStr char
 * @param tituloStr char
 * @param autorStr char
 * @param precioStr char
 * @param editorialIdStr char
 * @return puntero
 */
eLibro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialIdStr);//CONSTRUCTOR PARAMETRIZADO
/**
 * @brief Libera la memoria
 *
 * @param this puntero al elemento
 */
void libro_delete(eLibro* this);
/**
 * @brief Busca el id de la editorial con ese nombre
 *
 * @param nombre
 * @param id
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int BuscarIdEditorial(char* nombre, int* id);
/**
 * @brief Busca el nombre de la editorial con el id
 *
 * @param id
 * @param nombre
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int BuscarNombreEditorial(int id, char* nombre);

//SETTERS
/**
 * @brief Guarda el id en la estructura
 *
 * @param this
 * @param id
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_setId(eLibro* this, int id);
/**
 * @brief Guarda el titulo en la estructura
 *
 * @param this
 * @param titulo
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_setTitulo(eLibro* this, char* titulo);
/**
 * @brief Guarda el autor en la estructura
 *
 * @param this
 * @param autor
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_setAutor(eLibro* this, char* autor);
/**
 * @brief Guarda el precio en la estructura
 *
 * @param this
 * @param precio
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_setPrecio(eLibro* this, float precio);
/**
 * @brief Guarda el id de la editorial en la estructura
 *
 * @param this
 * @param editorialId
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_setEditorialId(eLibro* this, int editorialId);

//GETTERS
/**
 * @brief Devuelve por puntero el id
 *
 * @param this
 * @param id
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_getId(eLibro* this, int* id);
/**
 * @brief Devuelve por puntero el titulo
 *
 * @param this
 * @param titulo
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_getTitulo(eLibro* this, char* titulo);
/**
 * @brief Devuelve por puntero el autor
 *
 * @param this
 * @param autor
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_getAutor(eLibro* this, char* autor);
/**
 * @brief Devuelve por puntero el precio
 *
 * @param this
 * @param precio
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_getPrecio(eLibro* this, float* precio);
/**
 * @brief Devuelve por puntero el id de la editorial
 *
 * @param this
 * @param editorialId
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_getEditorialId(eLibro* this, int* editorialId);

//VERIFICACIONES GET Y SET
/**
 * @brief Verifica los setters en char si estan todos correctos
 *
 * @param this
 * @param idStr
 * @param tituloStr
 * @param autorStr
 * @param precioStr
 * @param editorialIdStr
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_setVerifyChar(eLibro* this, char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialIdStr);
/**
 * @brief Verifica que los setters con los valores de estructura esten bien
 *
 * @param this
 * @param id
 * @param titulo
 * @param autor
 * @param precio
 * @param editorialId
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_setVerifyInt(eLibro* this, int id, char* titulo, char* autor, float precio, int editorialId);
/**
 * @brief Verifica que los getter esten correctos
 *
 * @param this
 * @param id
 * @param titulo
 * @param autor
 * @param precio
 * @param editorialId
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_getVerify(eLibro* this, int* id, char* titulo, char* autor, float* precio, int* editorialId);

//PRINT
/**
 * @brief Muestra un libro
 *
 * @param this
 * @return 0 si esta todo bien, -1 si esta todo mal
 */
int libro_printOneLibro(eLibro* this);
/**
 * @brief Muestra la lista de libros
 *
 * @param listaLibros
 * @return  0 si esta todo bien, -1 si esta todo mal
 */
int libro_printList(LinkedList* listaLibros);

//COMPARE
/**
 * @brief Compara los nombres de los autores buscando ordenar de mayor a menor
 *
 * @param libro1
 * @param libro2
 * @return -1 si es menor, 0 si son iguales, 1 si es mayor
 */
int libro_compareByAutor(void* libro1, void* libro2);

//MAPEO
/**
 * @brief Aplica descuentos dependiendo de la editorial
 *
 * @param libros
 */
void* libro_descuentos(void* libros);


#endif /* LIBRO_H_ */
