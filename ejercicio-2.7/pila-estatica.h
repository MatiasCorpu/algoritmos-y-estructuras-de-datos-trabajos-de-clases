#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_PILA 1000 // bytes

#define TODO_OK 0
#define PILA_LLENA -1
#define PILA_VACIA -2

#define MIN(x, y) ((x) <= (y) ? (x) : (y))

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
} tPila;

void pilaCrear(tPila *pila);
void pilaVaciar(tPila *pila);
bool pilaLlena(const tPila *pila, unsigned tamDato);
bool pilaVacia(const tPila *pila);
int pilaApilar(tPila *pila, const void *dato, unsigned tamDato);
int pilaDesapilar(tPila *pila, void *dato, unsigned tamDato);
int pilaVerTope(const tPila *pila, void *dato, unsigned tamDato);

#endif // PILA_ESTATICA_H_INCLUDED
