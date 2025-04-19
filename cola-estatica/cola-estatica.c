#include "cola-estatica.h"

void colaCrear(tCola *cola)
{
    cola->pri = 0;
    cola->ult = 0;
    cola->tamDisponible = TAM_COLA;
}

void colaVaciar(tCola *cola)
{
    cola->ult = cola->pri;
    cola->tamDisponible = TAM_COLA;
}

bool colaVacia(const tCola *cola)
{
    return cola->tamDisponible == TAM_COLA;
}

bool colaLlena(const tCola *cola, unsigned tamDato)
{
    return tamDato + sizeof(unsigned) > cola->tamDisponible;
}

int colaInsertarDato(tCola *cola, const void *dato, unsigned tamDato)
{
    unsigned ini, fin;

    if(colaLlena(cola, tamDato))
        return COLA_LLENA;

    // reservo memoria en la pila
    cola->tamDisponible -= (tamDato + sizeof(unsigned));

    // GUARDO EL TAM DEL DATO--------------------------
    ini = MIN(sizeof(unsigned), TAM_COLA - cola->ult);
    if(ini != 0)
        memcpy(cola->cola + cola->ult, &tamDato, ini);

    fin = sizeof(unsigned) - ini;
    if(fin != 0)
        memcpy(cola->cola, (char *)&tamDato + ini, fin);

    // muevo el cola->ult porque ya se copio el tamDato correctamente
    cola->ult = fin ? fin : cola->ult + ini;

    // GUARDO EL DATO----------------------------------
    ini = MIN(tamDato, TAM_COLA - cola->ult);
    if(ini != 0)
        memcpy(cola->cola + cola->ult, dato, ini);

    fin = tamDato - ini;
    if(fin != 0)
        memcpy(cola->cola, (char *)dato + ini, fin);

    // muevo el cola->ult porque ya se copio el dato correctamente
    cola->ult = fin ? fin : cola->ult + ini;

    return TODO_OK;
}

int colaSacarDato(tCola *cola, void *dato, unsigned tamDato)
{
    unsigned ini, fin, tamDatoCola;

    if(colaVacia(cola))
        return COLA_VACIA;

    // RECUPERO TAM DEL DATO
    ini = MIN(sizeof(unsigned), TAM_COLA - cola->pri);
    if(ini != 0)
        memcpy(&tamDatoCola, cola->cola + cola->pri, ini);

    fin = sizeof(unsigned) - ini;
    if(fin != 0)
        memcpy((char*)&tamDatoCola + ini, cola->cola, fin);
    cola->pri = fin ? fin : cola->pri + ini;

    // RECUPERO DATO
    ini = MIN(MIN(tamDato, tamDatoCola), TAM_COLA - cola->pri);
    if(ini != 0)
        memcpy(dato, cola->cola + cola->pri, ini);

    fin = tamDatoCola - ini;
    if(fin != 0)
        memcpy((char *)dato + ini, cola->cola, fin);
    cola->pri = fin ? fin : cola->pri + ini;

    // LIBERO ESPACIO
    cola->tamDisponible += tamDatoCola + sizeof(unsigned);

    return TODO_OK;
}

int colaVerPrimero(const tCola *cola, void *dato, unsigned tamDato)
{
    unsigned ini, fin, tamDatoCola;
    unsigned pos = cola->pri;

    if(colaVacia(cola))
        return COLA_VACIA;

    // RECUPERO TAM DEL DATO
    ini = MIN(sizeof(unsigned), TAM_COLA - pos);
    if(ini != 0)
        memcpy(&tamDatoCola, cola->cola + pos, ini);

    fin = sizeof(unsigned) - ini;
    if(fin != 0)
        memcpy((char *)&tamDatoCola + ini, cola->cola, fin);

    pos = fin ? fin : pos + ini;

    // RECUPERO EL DATO SIN MOVER EL cola->pri
    ini = MIN(MIN(tamDato, tamDatoCola), TAM_COLA - pos);
    if(ini != 0)
        memcpy(dato, cola->cola + pos, ini);

    fin = tamDatoCola - ini;
    if(fin != 0)
        memcpy((char *)dato + ini, cola->cola, fin);

    return TODO_OK;
}
