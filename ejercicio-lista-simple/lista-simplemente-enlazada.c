#include "lista-simplemente-enlazada.h"

void listaCrear(tLista *pl)
{
    *pl = NULL;
}

void listaVaciar(tLista *pl)
{
    tNodo *aux;

    while (*pl)
    {
        aux = *pl;
        *pl = aux->sig;
        free(aux->info);
        free(aux);
    }
}

bool listaVacia(const tLista *pl)
{
    return *pl == NULL;
}

bool listaLlena(const tLista *pl, unsigned tamDato)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    aux->info = malloc(tamDato);

    free(aux->info);
    free(aux);
    return aux == NULL || aux->info == NULL;
}

int listaPonerAlInicio(tLista *pl, const void *dato, unsigned tamDato)
{
    tNodo *nuevo;

    if ((nuevo = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nuevo->info = malloc(tamDato)) == NULL)
    {
        free(nuevo);
        return LISTA_LLENA;
    }

    memcpy(nuevo->info, dato, tamDato);
    nuevo->tamInfo = tamDato;
    nuevo->sig = *pl;
    *pl = nuevo;
    return TODO_BIEN;
}

int listaPonerAlFinal(tLista *pl, const void *dato, unsigned tamDato)
{
    tNodo *nuevo;

    if ((nuevo = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nuevo->info = malloc(tamDato)) == NULL)
    {
        free(nuevo);
        return LISTA_LLENA;
    }

    memcpy(nuevo->info, dato, tamDato);
    nuevo->tamInfo = tamDato;
    nuevo->sig = NULL;

    while (*pl)
        pl = &(*pl)->sig;

    *pl = nuevo;
    return TODO_BIEN;
}

int listaSacarPrimero(tLista *pl, void *dato, unsigned tamDato)
{
    tNodo *aux = *pl;
    if (aux == NULL)
        return LISTA_VACIA;

    *pl = aux->sig;
    memcpy(dato, aux->info, MINIMO(tamDato, aux->tamInfo));
    free(aux->info);
    free(aux);
    return TODO_BIEN;
}

int listaSacarUltimo(tLista *pl, void *dato, unsigned tamDato)
{
    if (*pl == NULL)
        return LISTA_VACIA;

    while ((*pl)->sig)
        pl = &(*pl)->sig;

    memcpy(dato, (*pl)->info, MINIMO(tamDato, (*pl)->tamInfo));
    free((*pl)->info);
    free(*pl);
    *pl = NULL;
    return TODO_BIEN;
}

int listaVerPrimero(const tLista *pl, void *dato, unsigned tamDato)
{
    if (*pl == NULL)
        return LISTA_VACIA;

    memcpy(dato, (*pl)->info, MINIMO(tamDato, (*pl)->tamInfo));
    return TODO_BIEN;
}

int listaVerUltimo(const tLista *pl, void *dato, unsigned tamDato)
{
    if (*pl == NULL)
        return LISTA_VACIA;

    while ((*pl)->sig)
        pl = &(*pl)->sig;

    memcpy(dato, (*pl)->info, MINIMO(tamDato, (*pl)->tamInfo));
    return TODO_BIEN;
}

void listaMap(tLista *pl, Accion accion, void *parametro)
{
    while (*pl)
    {
        accion((*pl)->info, parametro);
        pl = &(*pl)->sig;
    }
}