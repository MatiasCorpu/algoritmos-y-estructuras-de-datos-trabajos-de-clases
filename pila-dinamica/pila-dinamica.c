#include "pila-dinamica.h"

void pilaCrear(tPila *pila)
{
    *pila = NULL;
}

void pilaVaciar(tPila *pila)
{
    while (*pila)
    {
        tNodo *aux = *pila;

        *pila = aux->sig;
        free(aux->info);
        free(aux);
    }
}

bool pilaVacia(const tPila *pila)
{
    return *pila == NULL;
}

bool pilaLlena(const tPila *pila, unsigned tamInfo)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(tamInfo);

    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int pilaVerTope(const tPila *pila, void *dato, unsigned tamDato)
{
    if (*pila == NULL)
        return PILA_VACIA;

    memcpy(dato, (*pila)->info, MINIMO((*pila)->tamInfo, tamDato));
    return TODO_OK;
}

int pilaDesapilar(tPila *pila, void *dato, unsigned tamDato)
{
    tNodo *aux = *pila;
    if (*pila == NULL)
        return PILA_VACIA;

    *pila = aux->sig;
    memcpy(dato, (*pila)->info, MINIMO((*pila)->tamInfo, tamDato));

    free(aux->info);
    free(aux);
    return TODO_OK;
}

int pilaApilar(tPila *pila, const void *dato, unsigned tamDato)
{
    tNodo *nuevo;
    if ((nuevo = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nuevo->info = malloc(tamDato)) == NULL)
    {
        free(nuevo);
        return PILA_LLENA;
    }

    memcpy(nuevo->info, dato, tamDato);
    nuevo->tamInfo = tamDato;
    nuevo->sig = *pila;
    *pila = nuevo;
    return TODO_OK;
}
