#include "archivo.h"

int guardarDatoEnArchivo(FILE *pf, const tDato *d)
{
    // primero se escribe el tamaño del dato luego el dato
    if (fwrite(&(d->tam), sizeof(unsigned), 1, pf) != 1)
        return 0;
    if (fwrite(d->dato, d->tam, 1, pf) != 1)
        return 0;
    return OK;
}

int archivoCrear(const char *nomArch)
{
    FILE *pf = fopen(nomArch, "wb");
    if (!pf)
        return ERROR;

    // ---------- Guardar un int ----------
    int entero = 42;
    tDato d1 = {&entero, sizeof(entero)};
    guardarDatoEnArchivo(pf, &d1);

    // ---------- Guardar un float ----------
    float decimal = 3.1415;
    tDato d2 = {&decimal, sizeof(decimal)};
    guardarDatoEnArchivo(pf, &d2);

    // ---------- Guardar un string ----------
    char mensaje[] = "Hola Mundo";
    tDato d3 = {mensaje, strlen(mensaje) + 1};
    guardarDatoEnArchivo(pf, &d3);

    // ---------- Guardar un struct Alumno ----------
    Alumno a1 = {"Gonzalez", 12345, 8.75f};
    tDato d4 = {&a1, sizeof(a1)};
    guardarDatoEnArchivo(pf, &d4);

    // ---------- Guardar un char ----------
    char letra = 'A';
    tDato d5 = {&letra, sizeof(letra)};
    guardarDatoEnArchivo(pf, &d5);

    fclose(pf);
    printf("Archivo 'archivo.dat' creado con éxito.\n");

    return OK;
}

int apilarDatosDeArchivoEnPila(FILE *pf, tPila *pila, tDato *dato)
{
    while (fread(&dato->tam, sizeof(dato->tam), 1, pf)) // Primero lee el tamaño del dato
    {
        dato->dato = malloc(dato->tam); // Asigna memoria para el dato según el tamaño leído
        if (!dato->dato)
            return SIN_MEMORIA;

        fread(dato->dato, dato->tam, 1, pf); // Luego lee el dato en sí

        if (pilaApilar(pila, dato) == PILA_LLENA)
        {
            free(dato->dato);
            break;
        }
        free(dato->dato);
    }

    return OK;
}