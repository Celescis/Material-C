/** \brief Controla la carga de los datos de los libros desde el archivo (modo texto).
 *
 * \param path char* nombre del archivo
 * \param pArrayListLibro LinkedList* lista de libros
 * \return int devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListLibro);
/**
 * @brief Controla el funcionamiento de la funcion de lista
 *
 * @param pArrayListLibro recibe la lista de libros
 * @return int devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int controller_listLibro(LinkedList* pArrayListLibro);
/**
 * @brief Controla que el ordenamiento este funcionando correctamente
 *
 * @param pArrayListLibro recibe la lista de libros
 * @return int devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int controller_sortLibro(LinkedList* pArrayListLibro);
/**
 * @brief Controla el mapeo de la funcion que le asigne
 *
 * @param pArrayListLibro recibe la lista de libros
 * @return int devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 */
int controller_mapeadoDescuentos(LinkedList* pArrayListLibro);
/** \brief Controla el guardado de datos de los libros en el archivo (modo texto).
 *
 * \param path char* nombre del archivo
 * \param pArrayListLibro LinkedList* lista de libros
 * \return int devuelve 0 si salio todo bien, devuelve -1 si salio todo mal
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);


