#ifndef CONTROL_DE_CALIDAD_H_INCLUDED
#define CONTROL_DE_CALIDAD_H_INCLUDED

#include <stdio.h>

/*
control de calidad durante el proceso de fabricacion
-> resultados individuales por lote de cada unidad = archivo

entrada.txt -> contiene los registros
    * codLote char[] (ej. `L001`)
    * idProducto unsigned
    * resultadoControl ok | falla


registros ordenados por lote
    L001
    L001
    L001
    L001
    L002
    L002
    L002
    ...


Escribir archivos de salida:
1) Si todos los productos del lote OK -> archivo "lotesAprobados.txt"
2) Si al menos uno de los productos del lote falla -> archivo "lotesObservados.txt"

fundamental:
    *los regisstros conserven el orden original
    *el archivo de entrada se lea una sola vez
    *La separacion en los archivos de salida se realize por lote completo, no por producto individual (NO ENTENDI)

DESARROLLAR:
1) mostrar un menu de opciones:
    a) procesar archivo de entrada: leer el archivo "entrada.txt" y generar "lotesAprobados.txt" y "lotesObservados.txt"
    b) Mostrar archivo de entrada
    c) Mostrar el contenido de los archivos de salida con un encabezado apropiado para cada uno

2) Entregar incluyendo un lote de prueba con la mayor cantidad posibles de situaciones.

*/

#endif // CONTROL_DE_CALIDAD_H_INCLUDED
