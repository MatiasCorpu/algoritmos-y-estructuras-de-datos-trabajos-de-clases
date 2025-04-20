#include "resolucion.h"

/*
Ejercicio 2.7
Resuelva el calculo de la suma de dos numeros enteros de muchos digitos (30 o muchos mas)
haciendo uso de dos pilas en las que almacena solo los digitos. Tenga en cuenta que debe utilizar una
tercera pila en la que ira cargando los resultados parciales. Compruebe que obtiene identicos
resultados con ambas implementaciones de Pila (estatica y dinamica).
*/

// IMPLEMENTACION DE PILA ESTATICA

int sumaUtilizandoPilasEstaticas(const char *numero1, const char *numero2, char *resultado, int tamResultado)
{
    tPila pila1, pila2, pilaResult;
    crearPilasEstaticas(&pila1, &pila2, &pilaResult);
    cargarNumerosEnPilasEstaticas(&pila1, numero1, &pila2, numero2);
    sumaPilasEstaticas(&pila1, &pila2, &pilaResult);
    convertirPilaEstaticaAcadena(&pilaResult, resultado, tamResultado);
    vaciarPilasEstaticas(&pila1, &pila2, &pilaResult);
    return TODO_OK;
}

void crearPilasEstaticas(tPila *pila1, tPila *pila2, tPila *pilaResult)
{
    pilaCrear(pila1);
    pilaCrear(pila2);
    pilaCrear(pilaResult);
}

void cargarNumerosEnPilasEstaticas(tPila *pila1, const char *numero1, tPila *pila2, const char *numero2)
{
    cargarNumeroEnPilaEstatica(pila1, numero1);
    cargarNumeroEnPilaEstatica(pila2, numero2);
}

void cargarNumeroEnPilaEstatica(tPila *pila, const char *numero)
{
    for (int i = 0; i < strlen(numero); i++)
    {
        int digito = numero[i] - '0'; // Convertir el caracter a entero
        pilaApilar(pila, &digito, sizeof(int));
    }
}

void sumaPilasEstaticas(tPila *pila1, tPila *pila2, tPila *pilaResult)
{
    unsigned dig1, dig2, suma, carry = 0;

    while (!pilaVacia(pila1) || !pilaVacia(pila2) || carry)
    {
        dig1 = dig2 = 0;

        if (!pilaVacia(pila1))
            pilaDesapilar(pila1, &dig1, sizeof(unsigned));

        if (!pilaVacia(pila2))
            pilaDesapilar(pila2, &dig2, sizeof(unsigned));

        suma = dig1 + dig2 + carry;
        carry = suma / 10;
        suma %= 10;

        pilaApilar(pilaResult, &suma, sizeof(unsigned));
    }
}

int convertirPilaEstaticaAcadena(tPila *pila, char *cadena, int tamCadena)
{
    if (pilaVacia(pila))
        return PILA_VACIA;

    int i = 0;
    while (!pilaVacia(pila) && i < tamCadena - 1)
    {
        unsigned digito;
        pilaDesapilar(pila, &digito, sizeof(unsigned));
        cadena[i++] = digito + '0'; // Convertir el entero a caracter
    }
    cadena[i] = '\0';

    return TODO_OK;
}

void vaciarPilasEstaticas(tPila *pila1, tPila *pila2, tPila *pilaResult)
{
    pilaVaciar(pila1);
    pilaVaciar(pila2);
    pilaVaciar(pilaResult);
}

// IMPLEMENTACION DE PILA DINAMICA