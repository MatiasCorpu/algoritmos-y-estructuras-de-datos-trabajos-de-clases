#ifndef LISTA_SIMPLEMENTE_ENLAZADA_H_INCLUDED
#define LISTA_SIMPLEMENTE_ENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TODO_BIEN 0
#define LISTA_LLENA 1
#define LISTA_VACIA 2

#define MINIMO(x, y) ((x) <= (y) ? (x) : (y))

typedef void (*Accion)(void *dato, void *parametro);

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
} tNodo;

typedef tNodo *tLista;

void listaCrear(tLista *pl);                                            //
void listaVaciar(tLista *pl);                                           //
bool listaVacia(const tLista *pl);                                      //
bool listaLlena(const tLista *pl, unsigned tamDato);                    //
int listaPonerAlInicio(tLista *pl, const void *dato, unsigned tamDato); //
int listaPonerAlFinal(tLista *pl, const void *dato, unsigned tamDato);  //
int listaSacarPrimero(tLista *pl, void *dato, unsigned tamDato);        //
int listaSacarUltimo(tLista *pl, void *dato, unsigned tamDato);         //
int listaVerPrimero(const tLista *pl, void *dato, unsigned tamDato);    //
int listaVerUltimo(const tLista *pl, void *dato, unsigned tamDato);     //
// funciones que no estan en los apuntes
void listaMap(tLista *pl, Accion accion, void *parametro);

#endif // LISTA_SIMPLEMENTE_ENLAZADA_H_INCLUDED
