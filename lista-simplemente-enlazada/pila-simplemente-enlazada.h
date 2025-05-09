#ifndef PILA_SIMPLEMENTE_ENLAZADA_H_INCLUDED
#define PILA_SIMPLEMENTE_ENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TODO_BIEN 0
#define LISTA_LLENA 1
#define LISTA_VACIA 2

// ERROR: los archivos se llaman a excepcion del proyecto se llaman "pila". Cambiar

#define MINIMO(x, y) ((x) <= (y) ? (x) : (y))

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
} tNodo;

typedef tNodo *tLista;

// 10 funciones
void listaCrear(tLista *pl);
void listaVaciar(tLista *pl);
bool listaVacia(const tLista *pl);
bool listaLlena(const tLista *pl, unsigned tamDato);
int listaPonerAlInicio(tLista *pl, const void *dato, unsigned tamDato);
int listaPonerAlFinal(tLista *pl, const void *dato, unsigned tamDato);
int listaSacarPrimero(tLista *pl, void *dato, unsigned tamDato);
int listaSacarUltimo(tLista *pl, void *dato, unsigned tamDato);
int listaVerPrimero(const tLista *pl, void *dato, unsigned tamDato);
int listaVerUltimo(const tLista *pl, void *dato, unsigned tamDato);

#endif // PILA_SIMPLEMENTE_ENLAZADA_H_INCLUDED
