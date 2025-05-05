#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista-simplemente-enlazada.h"

#define TODO_BIEN 0
#define ERROR_ARCHIVO 1
#define ERROR_LINEA_LARGA 2

#define NOM_ARCH "productos.txt"
#define TAM_COD 4
#define TAM_DESC 50
#define TAM_LINEA 200
#define SALIR_MENU 10

typedef struct
{
    char cod[TAM_COD];
    char descipcion[TAM_DESC];
    unsigned cant;
} tProd;

int lineaAProducto(tProd *p, const char *linea);
int archivoTxtALista(tLista *pl, const char *nombreArchivo);
void crearArchivoProductosTxt(const char *nombreArchivo);
void mostrarArchivo(const char *nombreArchivo);

void accionMostrar(void *dato, void *parametro);
void accionAumentarStock(void *dato, void *parametro);

void mostrarLista(const tLista *pl);
void aumentarStockProductos(tLista *pl);
void agregarProductoAlInicio(tLista *pl);
void agregarProductoAlFinal(tLista *pl);
void eliminarPrimerProducto(tLista *pl);
void eliminarUltimoProducto(tLista *pl);
void verPrimerProducto(const tLista *pl);
void verUltimoProducto(const tLista *pl);
void guardarCambiosEnArchivo(tLista *pl, const char *nombreArchivo);

void menu(tLista *pl, const char *nombreArchivo);

#endif // UTILIDADES_H_INCLUDED
