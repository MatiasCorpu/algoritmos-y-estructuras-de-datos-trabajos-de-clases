#ifndef COLA_ESTATICA_H_INCLUDED
#define COLA_ESTATICA_H_INCLUDED

#define TAM_COLA 30
#define TODO_OK 0
#define COLA_LLENA -1
#define COLA_VACIA -2
#define MIN(x,y) (((x)<(y))?x:y)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char cola[TAM_COLA];
    unsigned pri;
    unsigned ult;
    unsigned tamDisponible;
} tCola;


void colaCrear(tCola *cola);
void colaVaciar(tCola *cola);
bool colaVacia(const tCola *cola);
bool colaLlena(const tCola *cola, unsigned tamDato);
int colaInsertarDato(tCola *cola, const void *dato, unsigned tamDato);
int colaSacarDato(tCola *cola, void *dato, unsigned tamDato);
int colaVerPrimero(const tCola *cola, void *dato, unsigned tamDato);

#endif // COLA_ESTATICA_H_INCLUDED
