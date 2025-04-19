#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR -1
#define PILA_VACIA -2
#define PILA_LLENA -3
#define SIN_MEMORIA -4
#define TAM_PILA 14

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
} tPila;

void pilaCrear(tPila *pila);
void pilaVaciar(tPila *pila);
int pilaLlena(const tPila *pila, unsigned tam);
int pilaVacia(const tPila *pila);
int pilaApilar(tPila *pila, const void *dato, unsigned tam);
int pilaVerTope(const tPila *pila, void *dato, unsigned cap);
int pilaDesapilar(tPila *pila, void *dato, unsigned cap);
 
#endif // PILA_ESTATICA_H_INCLUDED
