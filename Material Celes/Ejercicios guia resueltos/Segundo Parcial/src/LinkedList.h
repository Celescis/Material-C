/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas
LinkedList* ll_newLinkedList(void);//ME GENERA UNA NUEVA LISTA
int ll_len(LinkedList* this);//REVISA LA CANTIDAD QUE VA A TENER MI LISTA
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);//AGREGA EMPLEADOS A LA LISTA
void* ll_get(LinkedList* this, int index);//BUSCA EN LA LISTA POR INDEX
int ll_set(LinkedList* this, int index,void* pElement);//GUARDA EL ELEMENTO EN LA POSICION DE LA LISTA
int ll_remove(LinkedList* this,int index);//ELIMINA UN EMPLEADO DE LA LISTA
int ll_clear(LinkedList* this);//LIMPIA LA LISTA
int ll_deleteLinkedList(LinkedList* this);//BORRA LA LISTA
int ll_indexOf(LinkedList* this, void* pElement);//ME PASA EL INDEX DEL ELEMENTO QUE LE PASO
int ll_isEmpty(LinkedList* this);//REVISA SI LA LISTA TIENE ELEMENTOS
int ll_push(LinkedList* this, int index, void* pElement);//METE UN EMPLEADO ENTRE OTRO
void* ll_pop(LinkedList* this,int index);//BORRA UN EMPLEADO Y LO DEVUELVE
int ll_contains(LinkedList* this, void* pElement);//REVISA SI LA LISTA CONTIENE ESE ELEMENTO
int ll_containsAll(LinkedList* this,LinkedList* this2);//REVISA SI LA LISTA CONTIENE ELEMENTOS DE LA OTRA LISTA
LinkedList* ll_subList(LinkedList* this,int from,int to);//RETORNA UNA NUEVA LISTA
LinkedList* ll_clone(LinkedList* this);//CLONA LA LISTA ORIGINAL
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//ORDENA LA LISTA DEPENDIENDO DEL CRITERIO DE LA FUNCION
LinkedList* ll_map(LinkedList* this, void* (pFunc)(void*));//HACE MODIFICACIONES EN LA LISTA DEPENDIENDO DE LA CONDICION DE LA FUNCION

