#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TODO_OK 0
#define PILA_VACIA -1
#define PILA_LLENA -2

#define MINIMO(x, y) ((x) <= (y) ? (x) : (y))

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
} tNodo;

typedef tNodo *tPila; // apunta al tope de la pila

void pilaCrear(tPila *pila);
void pilaVaciar(tPila *pila);
bool pilaVacia(const tPila *pila);
bool pilaLlena(const tPila *pila, unsigned tamInfo);
int pilaVerTope(const tPila *pila, void *dato, unsigned tamDato);
int pilaDesapilar(tPila *pila, void *dato, unsigned tamDato);
int pilaApilar(tPila *pila, const void *dato, unsigned tamDato);

#endif // PILA_DINAMICA_H_INCLUDED
