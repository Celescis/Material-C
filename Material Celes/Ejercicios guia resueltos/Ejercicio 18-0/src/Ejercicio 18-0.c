/**

Ejercicio 18-0:
Guardar en una variable nombre y apellido. Guardar el dato en un archivo de texto, leerlo y luego mostrarlo.

**/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombreyApellido[20];
    FILE* test;
    char lectura[100];

    strcpy(nombreyApellido,"Celeste Cisternas");

   test = fopen("Nombre.csv","w");

    if(test!=NULL)
    {
        fprintf(test, "%s\n",nombreyApellido);
    }
    fclose(test);

    test = fopen("Nombre.csv","r");

    if(test!=NULL)
    {
        fgets(lectura,100,test);
        printf("%s\n",lectura);
        //fscanf(test,"%[^\n]",lectura);
    }
    fclose(test);

    return 0;
}
