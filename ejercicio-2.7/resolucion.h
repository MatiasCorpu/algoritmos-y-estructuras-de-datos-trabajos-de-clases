#ifndef RESOLUCION_H_INCLUDED
#define RESOLUCION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila-estatica.h"

void sumaPilasEstaticas(tPila *pila1, tPila *pila2, tPila *pilaResult);
int convertirPilaEstaticaAcadena(tPila *pila, char *cadena, int tamCadena);
void cargarNumeroEnPilaEstatica(tPila *pila, const char *numero);
void crearPilasEstaticas(tPila *pila1, tPila *pila2, tPila *pilaResult);
void vaciarPilasEstaticas(tPila *pila1, tPila *pila2, tPila *pilaResult);
void cargarNumerosEnPilasEstaticas(tPila *pila1, const char *numero1, tPila *pila2, const char *numero2);
int sumaUtilizandoPilasEstaticas(const char *numero1, const char *numero2, char *resultado, int tamResultado);

#endif // RESOLUCION_H_INCLUDED
