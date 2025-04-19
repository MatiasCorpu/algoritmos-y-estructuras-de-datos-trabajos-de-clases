#include "pila-hibrida.h"

void pilaCrear(tPila *pila)
{
    pila->tope = TAM_PILA - 1; // Inicializa el tope a la posición máxima
}

void pilaVaciar(tPila *pila)
{
    while (!pilaVacia(pila))
    {
        free(pila->pila[pila->tope + 1]->dato); // Libera el dato dentro de tDato
        free(pila->pila[pila->tope + 1]);       // Libera el tDato
        pila->tope++;
    }
}

int pilaVacia(const tPila *pila)
{
    return pila->tope == TAM_PILA - 1;
}

int pilaLlena(const tPila *pila)
{
    return pila->tope < 0;
}

int pilaApilar(tPila *pila, tDato *dato) // Comienza apilando el dato en la posicion tope, y luego decrementa el tope
{
    if (pilaLlena(pila))
        return PILA_LLENA;

    // Asignar memoria para el nuevo dato en la pila (tDato dato)
    pila->pila[pila->tope] = malloc(sizeof(tDato));
    if (!pila->pila[pila->tope])
        return SIN_MEMORIA;

    // Asignar memoria para el dato dentro de tDato (dato->dato)
    pila->pila[pila->tope]->dato = malloc(dato->tam);
    if (!pila->pila[pila->tope]->dato)
    {
        free(pila->pila[pila->tope]);
        return SIN_MEMORIA;
    }

    // Copiar el dato y su tamaño
    memcpy(pila->pila[pila->tope]->dato, dato->dato, dato->tam);
    pila->pila[pila->tope]->tam = dato->tam;

    pila->tope--;

    return OK;
}

int pilaVerTope(const tPila *pila, tDato *dato) // la contra de esta funcion es que no libera la memoria del dato se tiene que liberar afuera!!!
{
    if (pilaVacia(pila))
        return PILA_VACIA;

    // Asignar memoria para el dato a devolver y luego copia el dato y su tamaño
    dato->tam = pila->pila[pila->tope + 1]->tam;
    dato->dato = malloc(dato->tam);
    if (!dato->dato)
        return SIN_MEMORIA;
    memcpy(dato->dato, pila->pila[pila->tope + 1]->dato, dato->tam);

    return OK;
}

int pilaDesapilar(tPila *pila, tDato *dato) // la contra de esta funcion es la misma que la de pilaVerTope
{
    if (pilaVacia(pila))
        return PILA_VACIA;

    // Asignar memoria para el dato a devolver y luego copia el dato y su tamaño
    dato->tam = pila->pila[pila->tope + 1]->tam;
    dato->dato = malloc(dato->tam);
    if (!dato->dato)
        return SIN_MEMORIA;
    memcpy(dato->dato, pila->pila[pila->tope + 1]->dato, dato->tam);

    // Liberar el dato desapilado y corre el tope, es la unica diferencia con pilaVerTope
    free(pila->pila[pila->tope + 1]->dato);
    free(pila->pila[pila->tope + 1]);
    pila->tope++;

    return OK;
}
