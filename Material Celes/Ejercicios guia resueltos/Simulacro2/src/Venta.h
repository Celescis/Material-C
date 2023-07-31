#ifndef venta_H_INCLUDED
#define venta_H_INCLUDED
typedef struct
{
	int id;
	char nombre[128];
	int dia;
	int horario;
	int sala;
	int entrada;
}Venta;

Venta* venta_new(void);
Venta* venta_newParametros(char* idStr, char* nombreStr, char* diaStr, char* horarioStr, char* salaStr, char* entradaStr);
void venta_delete(Venta* this);

//BUSCAR
int venta_findID(LinkedList* listaEmpleados, int id);
int venta_printOneVenta(Venta* this);
int venta_printList(LinkedList* listaEmpleados);
int ObtenerMayorId(LinkedList* listaEmpleados);

//ABM
int venta_add(LinkedList* listaEmpleados, int* id);
int venta_remove(LinkedList* listaEmpleados);
int venta_modify(LinkedList* listaEmpleados);

//VERIFICACIONES GET Y SET
int venta_setVerifyChar(Venta* this, char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
int venta_setVerifyInt(Venta* this, int id, char* nombre, int dia, int horario, int sala, int entrada);
int venta_getVerify(Venta* this, int* id, char* nombre, int* dia, int* horario, int* sala, int* entrada);

//SETTERS
int venta_setId(Venta* this, int id);
int venta_setNombre(Venta* this, char* nombre);
int venta_setDia(Venta* this, int dia);
int venta_setHorario(Venta* this, int horario);
int venta_setSala(Venta* this, int sala);
int venta_setEntrada(Venta* this, int entrada);

//GETTERS
int venta_getId(Venta* this, int* id);
int venta_getNombre(Venta* this, char* nombre);
int venta_getDia(Venta* this, int* dia);
int venta_getHorario(Venta* this, int* horario);
int venta_getSala(Venta* this, int* sala);
int venta_getEntrada(Venta* this, int* entrada);

//COMPARE
/*
int venta_compareById(void* empleado1, void* empleado2);
int venta_compareByNombre(void* empleado1, void* empleado2);
int venta_compareByHorasTrabajadas(void* empleado1, void* empleado2);
int venta_compareBySueldo(void* empleado1, void* empleado2);
*/

//MODIFY
int venta_modifyNombre(LinkedList* listaEmpleados, int index, char* auxNombre);
int venta_modifySueldo(LinkedList* listaEmpleados, int index, int auxSueldo);

//CASE
int venta_caseNombre(LinkedList* listaEmpleados, int index, Venta auxiliar);
int venta_caseHoras(LinkedList* listaEmpleados, int index, Venta auxiliar);
int venta_modifyHorasTrabajadas(LinkedList* listaEmpleados, int index, int auxHoras);
int venta_caseSueldo(LinkedList* listaEmpleados, int index, Venta auxiliar);

#endif // venta_H_INCLUDED
