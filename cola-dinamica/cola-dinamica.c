#include "cola-dinamica.h"

void colaCrear(tCola *cola) // pone los 2 punteros en NULL
{
    cola->pri = NULL;
    cola->ult = NULL;
}

void colaVaciar(tCola *cola) // empieza a vaciar desde el primero al ultimo
{
    while (cola->pri)
    {
        tNodo *aux = cola->pri;
        cola->pri = aux->sig;
        free(aux->info);
        free(aux);
    }
    cola->ult = NULL; // pone el puntero ult en NULL
}

bool colaLlena(const tCola *cola, unsigned tamDato) // se fija si puede reservar mas memoria
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(tamDato);

    free(aux);
    free(info);
    return (info == NULL || aux == NULL);
}

bool colaVacia(const tCola *cola) // si el puntero pri de la cola esta NULL
{
    return cola->pri == NULL;
}

int colaVerPrimero(const tCola *cola, void *dato, unsigned tamDato) // ve el primero que apunta pri de la cola
{
    if(cola->pri == NULL)
        return COLA_VACIA;

    memcpy(dato, cola->pri->info, MINIMO(cola->pri->tamInfo, tamDato));
    return TODO_OK;
}

int colaSacarDato(tCola *cola, void *dato, unsigned tamDato) // saca el primer dato que esta apuntado por cola->pri 
{
    tNodo *aux = cola->pri;
    if (aux == NULL)
        return COLA_VACIA;

    cola->pri = aux->sig;
    memcpy(dato, aux->info, MINIMO(aux->tamInfo, tamDato));
    free(aux->info);
    free(aux);

    if (cola->pri == NULL) // si la cola->pri no apunta a nada -> la cola esta vacia, se debe indicar que ult tampoco apunte a nada
        cola->ult = NULL;

    return TODO_OK;
}

int colaInsertarDato(tCola *cola, const void *dato, unsigned tamDato) // se inserta un dato a lo ultimo de la cola 
{
    tNodo *nuevo;

    if ((nuevo = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nuevo->info = malloc(tamDato)) == NULL)
    {
        free(nuevo);
        return COLA_LLENA;
    }

    memcpy(nuevo->info, dato, tamDato);
    nuevo->tamInfo = tamDato;
    nuevo->sig = NULL; // no hay siguiente porque es el ultimo

    if (cola->ult) // si habia un ultimo se le debe indicar que no es el ultimo ahora, y que tiene un siguiente 
        cola->ult->sig = nuevo;
    else
        cola->pri = nuevo; // si no habia ultimo entonces es el primero

    cola->ult = nuevo; // finalmente se actualiza el ultimo 
    return TODO_OK;
}
