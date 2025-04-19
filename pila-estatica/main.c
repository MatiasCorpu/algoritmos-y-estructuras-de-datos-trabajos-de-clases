#include <stdio.h>
#include <stdlib.h>

#include "pila-estatica.h"
//#include "pila-estatica.c"

int main() 
{
    tPila pila;
    pilaCrear(&pila);

    char dato1[2] = "si";
    pilaApilar(&pila, &dato1, sizeof(dato1));


    char dato2[4] = "hola";
    pilaApilar(&pila, &dato2, sizeof(dato2));


    char dato3[10];
    pilaDesapilar(&pila, &dato3, sizeof(dato3));


    pilaVaciar(&pila);
    return OK;
}
