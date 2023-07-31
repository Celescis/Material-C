#ifndef PARSER_H_
#define PARSER_H_

int parser_VentaFromText(FILE* pFile , LinkedList* pArrayListVenta);
int parser_IdFromText(FILE* pFile , LinkedList* pArrayListVenta, int* id);
int parser_VentaFromBinary(FILE* pFile , LinkedList* pArrayListVenta);

#endif /* PARSER_H_ */
