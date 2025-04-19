#include "pila-estatica.h"

void pilaCrear(tPila *pila)
{
    pila->tope = TAM_PILA;
}

void pilaVaciar(tPila *pila)
{
    pila->tope = TAM_PILA;
}

int pilaLlena(const tPila *pila, unsigned tam)
{
    return pila->tope < tam + sizeof(unsigned);
}

int pilaVacia(const tPila *pila)
{
    return pila->tope == TAM_PILA;
}

int pilaVerTope(const tPila *pila, void *dato, unsigned cap)
{
    if (pilaVacia(pila))
        return PILA_VACIA;

    unsigned tam;

    memcpy(&tam, pila->pila + pila->tope, sizeof(unsigned));
    if (tam > cap)
        return ERROR;

    memcpy(dato, pila->pila + pila->tope + sizeof(unsigned), tam);

    return OK;
} 

int pilaApilar(tPila *pila, const void *dato, unsigned tam)
{
    if (pilaLlena(pila, tam))
        return PILA_LLENA;

    pila->tope -= tam;

    memcpy(pila->pila + pila->tope, dato, tam);

    pila->tope -= sizeof(unsigned);
    memcpy(pila->pila + pila->tope, &tam, sizeof(unsigned));

    return OK;
}

int pilaDesapilar(tPila *pila, void *dato, unsigned cap)
{
    if (pilaVacia(pila))
        return PILA_VACIA;

    unsigned tam;

    memcpy(&tam, pila->pila + pila->tope, sizeof(unsigned));
    if (tam > cap)
        return ERROR;

    pila->tope += sizeof(unsigned);
    memcpy(dato, pila->pila + pila->tope, tam);
    pila->tope += tam;

    return OK;
}
