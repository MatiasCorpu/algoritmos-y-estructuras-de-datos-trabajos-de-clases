#include <stdio.h>
#include <stdlib.h>

#include "lista-simplemente-enlazada.h"
#include "utilidades.h"

int main()
{
    tLista lista;
    listaCrear(&lista);

    crearArchivoProductosTxt(NOM_ARCH);
    mostrarArchivo(NOM_ARCH);
    archivoTxtALista(&lista, NOM_ARCH);

    menu(&lista, NOM_ARCH);

    mostrarArchivo(NOM_ARCH);
    listaVaciar(&lista);
    return 0;
}
