#include "pila-estatica.h"

void pilaCrear(tPila *pila)
{
    pila->tope = TAM_PILA;
}

void pilaVaciar(tPila *pila)
{
    pila->tope = TAM_PILA;
}

bool pilaLlena(const tPila *pila, unsigned tamDato)
{
    return pila->tope < tamDato + sizeof(unsigned);
}

bool pilaVacia(const tPila *pila)
{
    return pila->tope == TAM_PILA;
}

int pilaApilar(tPila *pila, const void *dato, unsigned tamDato)
{
    if (pila->tope < tamDato + sizeof(unsigned))
        return PILA_LLENA;

    pila->tope -= tamDato;
    memcpy(pila->pila + pila->tope, dato, tamDato);
    pila->tope -= sizeof(unsigned);
    memcpy(pila->pila + pila->tope, &tamDato, sizeof(unsigned));

    return TODO_OK;
}

int pilaDesapilar(tPila *pila, void *dato, unsigned tamDato)
{
    unsigned tamDatoPila;

    if (pila->tope == TAM_PILA)
        return PILA_VACIA;

    memcpy(&tamDatoPila, pila->pila + pila->tope, sizeof(unsigned));
    pila->tope += sizeof(unsigned);

    memcpy(dato, pila->pila + pila->tope, MIN(tamDatoPila, tamDato));
    pila->tope += tamDatoPila;

    return TODO_OK;
}

int pilaVerTope(const tPila *pila, void *dato, unsigned tamDato)
{
    unsigned tamDatoPila;

    if (pila->tope == TAM_PILA)
        return PILA_VACIA;

    memcpy(&tamDatoPila, pila->pila + pila->tope, sizeof(unsigned));
    memcpy(dato, pila->pila + pila->tope + sizeof(unsigned), MIN(tamDatoPila, tamDato));

    return TODO_OK;
}