#include <stdio.h>
#include <stdlib.h>

#include "pila-hibrida.h"
#include "archivo.h"

/*
nota: El archivo datos.dat fue generado tal que al leerse se pueda saber primero el tamaño de cada dato y luego el dato en sí.

datos.dat:

    BYTES | DATO
    4     | 42
    4     | 3.1415
    11    | "Hola Mundo\0"
    28    | {"Gonzalez", 12345, 8.75f}
    1     | 'A'

pila al finalizar la carga de datos:
    {
        0
        1<--tope
        2 dato :'A', tam: 1
        3 dato : {"Gonzalez", 12345, 8.75f}, tam: 28
        4 dato : "Hola Mundo", tam: 11
        5 dato : 3.1415, tam: 4
        6 dato : 42, tam: 4
    }
*/

int main()
{
    tPila pila;
    pilaCrear(&pila);

    FILE *pfDato = fopen("datos.dat", "rb");
    if (!pfDato)
        return ERROR;

    tDato dato;
    apilarDatosDeArchivoEnPila(pfDato, &pila, &dato); // utiliza -> pilaApilar
    fclose(pfDato);

    //----- CASOS DE PRUEBA -----//

    pilaVerTope(&pila, &dato);
    printf("VER TOPE  -> Tope: %c, Tamanio: %u\n", *(char *)dato.dato, dato.tam);
    free(dato.dato);

    pilaDesapilar(&pila, &dato);
    printf("DESAPILAR -> Desapilado: %c, Tamanio: %u\n", *(char *)dato.dato, dato.tam);
    free(dato.dato);

    pilaVerTope(&pila, &dato);
    printf("VER TOPE  -> Tope: {%s, %d, %.2f}, Tamanio: %u\n", ((Alumno *)dato.dato)->apellido, ((Alumno *)dato.dato)->id, ((Alumno *)dato.dato)->promedio, dato.tam);
    free(dato.dato);

    pilaDesapilar(&pila, &dato);
    printf("DESAPILAR -> Desapilado: {%s, %d, %.2f}, Tamanio: %u\n", ((Alumno *)dato.dato)->apellido, ((Alumno *)dato.dato)->id, ((Alumno *)dato.dato)->promedio, dato.tam);
    free(dato.dato);

    pilaVerTope(&pila, &dato);
    printf("VER TOPE  -> Tope: %s, Tamanio: %u\n", (char *)dato.dato, dato.tam);
    free(dato.dato);

    pilaDesapilar(&pila, &dato);
    printf("DESAPILAR -> Desapilado: %s, Tamanio: %u\n", (char *)dato.dato, dato.tam);
    free(dato.dato);

    pilaDesapilar(&pila, &dato);
    printf("DESAPILAR -> Desapilado: %f, Tamanio: %u\n", *(float *)dato.dato, dato.tam);
    free(dato.dato);

    pilaDesapilar(&pila, &dato);
    printf("DESAPILAR -> Desapilado: %d, Tamanio: %u\n", *(int *)dato.dato, dato.tam);
    free(dato.dato);

    pilaVerTope(&pila, &dato) == PILA_VACIA ? printf("Pila vacia, espacio disponible:%d posiciones\n", TAM_PILA) : printf("Pila no vacia, espacio disponible %d\n", TAM_PILA - (pila.tope + 1));

    pilaVaciar(&pila);
    return OK;
}
