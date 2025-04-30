#ifndef CONTROL_DE_CALIDAD_H_INCLUDED
#define CONTROL_DE_CALIDAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cola-dinamica.h"

#define TODO_OK 0
#define ERROR_ARCHIVO 1
#define ERROR_LINEA 2

#define TAM_MAX_LINEA 500
#define TAM_MAX_COD_LOTE 5
#define TAM_MAX_RESULTADO 5

typedef struct
{
    char codLote[TAM_MAX_COD_LOTE];           // L001
    unsigned idProducto;                      // 12345678
    char resultadoControl[TAM_MAX_RESULTADO]; // ok | falla
} tProductoCalidad;

int escribirLoteEnArchivo(FILE *archivo, tCola *cola);
int lineaAEstructuraProductoCalidad(tProductoCalidad *producto, const char *linea);
int procesarArchivoDeEntrada(const char *entrada, const char *lotesAprobados, const char *lotesObservados);

void mostrarArchivoDeEntrada(const char *nomArch);
void mostrarArchivosDeSalida(const char *lotesAprobados, const char *lotesObservados);
void mostrarArchivoProductoTxt(const char *nomArch, const char *encavezado);

int menu();

#endif // CONTROL_DE_CALIDAD_H_INCLUDED
