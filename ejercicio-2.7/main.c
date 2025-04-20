#include <stdio.h>
#include <stdlib.h>
#include "pila-estatica.h"
#include "resolucion.h"

#define TAM_RESULTADO 40

int main()
{
    char numero1[] = "8888888888888888888888888888888"; // 31 digitos
    char numero2[] = "2222222222222222222222222222223"; 
    char resultado[TAM_RESULTADO];

    sumaUtilizandoPilasEstaticas(numero1, numero2, resultado, sizeof(resultado));
    printf("%s + %s = %s\n", numero1, numero2, resultado);

    return TODO_OK;
}
