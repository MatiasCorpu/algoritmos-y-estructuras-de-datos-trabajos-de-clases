#include "cola-dinamica.h"

void colaCrear(tCola *cola)
{
    cola->pri = NULL;
    cola->ult = NULL;
}

void colaVaciar(tCola *cola)
{
    while (cola->pri)
    {
        tNodo *aux = cola->pri;
        cola->pri = aux->sig;
        free(aux->info);
        free(aux);
    }
    cola->ult = NULL;
}

bool colaVacia(const tCola *cola)
{
    return cola->pri == NULL;
}

bool colaLlena(const tCola *cola, unsigned tamDato)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(tamDato);

    free(aux);
    free(info);
    return (aux == NULL || info == NULL);
}

int colaVerPrimero(const tCola *cola, void *dato, unsigned tamDato)
{
    if (cola->pri == NULL)
        return COLA_VACIA;

    memcpy(dato, cola->pri->info, MINIMO(tamDato, cola->pri->tamInfo));
    return TODO_OK;
}

int colaSacarDato(tCola *cola, void *dato, unsigned tamDato)
{
    tNodo *datoAsacar = cola->pri;
    if (datoAsacar == NULL)
        return COLA_VACIA;

    cola->pri = datoAsacar->sig;
    memcpy(dato, datoAsacar->info, MINIMO(tamDato, datoAsacar->tamInfo));
    free(datoAsacar->info);
    free(datoAsacar);

    if (cola->pri == NULL)
        cola->ult = NULL;

    return TODO_OK;
}

int colaInsertarDato(tCola *cola, const void *dato, unsigned tamDato)
{
    tNodo *nuevo;

    if ((nuevo = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nuevo->info = malloc(tamDato)) == NULL)
    {
        free(nuevo);
        return COLA_LLENA;
    }

    memcpy(nuevo->info, dato, tamDato);
    nuevo->tamInfo = tamDato;
    nuevo->sig = NULL;

    if (cola->ult)
        cola->ult->sig = nuevo;
    else
        cola->pri = nuevo;

    cola->ult = nuevo;
    return TODO_OK;
}