#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila-hibrida.h"

typedef struct
{
    char apellido[20];
    int id;
    float promedio;
} Alumno;

int archivoCrear(const char *nomArch);
int guardarDatoEnArchivo(FILE *pf, const tDato *d);
int apilarDatosDeArchivoEnPila(FILE *pf, tPila *pila, tDato *dato);

#endif // ARCHIVO_H_INCLUDED
