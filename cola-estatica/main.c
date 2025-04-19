#include <stdio.h>
#include <stdlib.h>
#include "cola-estatica.h"
#include "cola-estatica.c"


int main()
{
    tCola cola;

    // Prueba colaCrear *****
    colaCrear(&cola);


    // Prueba colaVacia *****
    if(colaVacia(&cola))
        puts("cola vacia");
    else
        puts("cola no vacia");

    // Prueba colaLlena *****
    int tam = 1;
    while(tam > 0)
    {
        puts("ingresar un tamanio, sale con num negativo:");
        scanf("%d", &tam);

        if(colaLlena(&cola, tam))
           puts("cola llena");
        else
            puts("cola no llena");
    }

    // Prueba colaInsertarDato ****
    int vector[] = {1,3,7,5,9,10};

    for(int i = 0; i < (sizeof(vector)/sizeof(int)); i++)
        colaInsertarDato(&cola, &vector[i], sizeof(int));

    if(colaVacia(&cola))
        puts("cola vacia");
    else
        puts("cola no vacia");

    // Prueba colaSacarDato ****
    int dato1;
    colaSacarDato(&cola, &dato1, sizeof(int));
    printf("dato1 sacado = %d\n", dato1);

    int dato2;
    colaSacarDato(&cola, &dato2, sizeof(int));
    printf("dato2 sacado = %d\n", dato2);

    // Prueba colaVerPrimero ****
    int dato3;
    colaVerPrimero(&cola, &dato3, sizeof(int));
    printf("dato3 ver = %d\n", dato3);

    // Prueba colaVaciar ****
    colaVaciar(&cola);

    if(colaVacia(&cola))
        puts("cola vacia");
    else
        puts("cola no vacia");

    return TODO_OK;
}
