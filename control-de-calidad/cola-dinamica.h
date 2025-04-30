#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TODO_OK 0
#define COLA_VACIA -1
#define COLA_LLENA -2

#define MINIMO(x, y) ((x) <= (y) ? (x) : (y))

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
} tNodo;

typedef struct
{
    tNodo *pri, *ult;
} tCola;

void colaCrear(tCola *cola);
void colaVaciar(tCola *cola);
bool colaVacia(const tCola *cola);
bool colaLlena(const tCola *cola, unsigned tamDato);
int colaVerPrimero(const tCola *cola, void *dato, unsigned tamDato);
int colaSacarDato(tCola *cola, void *dato, unsigned tamDato);
int colaInsertarDato(tCola *cola, const void *dato, unsigned tamDato);

#endif // COLA_DINAMICA_H_INCLUDED
