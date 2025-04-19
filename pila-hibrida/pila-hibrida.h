#ifndef PILA_HIBRIDA_H_INCLUDED
#define PILA_HIBRIDA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR -1
#define PILA_VACIA -2
#define PILA_LLENA -3
#define SIN_MEMORIA -4
#define TAM_PILA 7

typedef struct
{
    void *dato;
    unsigned tam;
} tDato;

typedef struct
{
    tDato *pila[TAM_PILA];
    int tope;
} tPila;

void pilaCrear(tPila *pila);
void pilaVaciar(tPila *pila);
int pilaVacia(const tPila *pila);
int pilaLlena(const tPila *pila);
int pilaApilar(tPila *pila, tDato *dato);
int pilaVerTope(const tPila *pila, tDato *dato);
int pilaDesapilar(tPila *pila, tDato *dato);

#endif // PILA_HIBRIDA_H_INCLUDED
