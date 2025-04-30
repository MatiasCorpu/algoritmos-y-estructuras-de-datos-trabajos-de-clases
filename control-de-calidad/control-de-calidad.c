#include "control-de-calidad.h"
#include "cola-dinamica.h"

int procesarArchivoDeEntrada(const char *lotesEntrada, const char *lotesAprobados, const char *lotesObservados)
{
    FILE *entrada = fopen(lotesEntrada, "rt");
    if (!entrada)
        return ERROR_ARCHIVO;

    FILE *aprobados = fopen(lotesAprobados, "wt");
    if (!aprobados)
    {
        fclose(entrada);
        return ERROR_ARCHIVO;
    }

    FILE *observados = fopen(lotesObservados, "wt");
    if (!observados)
    {
        fclose(entrada);
        fclose(aprobados);
        return ERROR_ARCHIVO;
    }

    tProductoCalidad producto, productoIni;
    tCola cola;
    colaCrear(&cola);
    char linea[TAM_MAX_LINEA];

    fgets(linea, TAM_MAX_LINEA, entrada);
    lineaAEstructuraProductoCalidad(&producto, linea);
    bool hayFalla = strcmpi(producto.resultadoControl, "FALLA") == 0;
    colaInsertarDato(&cola, &producto, sizeof(tProductoCalidad));

    while (fgets(linea, TAM_MAX_LINEA, entrada))
    {
        lineaAEstructuraProductoCalidad(&producto, linea);

        colaVerPrimero(&cola, &productoIni, sizeof(tProductoCalidad));

        if (strcmp(producto.codLote, productoIni.codLote) != 0)
        {

            hayFalla == true ? escribirLoteEnArchivo(observados, &cola) : escribirLoteEnArchivo(aprobados, &cola);
            colaVaciar(&cola);
            hayFalla = false;
        }

        colaInsertarDato(&cola, &producto, sizeof(tProductoCalidad));
        hayFalla |= strcmpi(producto.resultadoControl, "FALLA") == 0;
    }

    hayFalla == true ? escribirLoteEnArchivo(observados, &cola) : escribirLoteEnArchivo(aprobados, &cola);

    colaVaciar(&cola);
    fclose(entrada);
    fclose(aprobados);
    fclose(observados);
    return TODO_OK;
}

int escribirLoteEnArchivo(FILE *archivo, tCola *cola)
{
    tProductoCalidad producto;

    while (colaSacarDato(cola, &producto, sizeof(tProductoCalidad)) != COLA_VACIA)
    {
        fprintf(archivo, "%s,%u,%s\n", producto.codLote, producto.idProducto, producto.resultadoControl);
    }

    return TODO_OK;
}

int lineaAEstructuraProductoCalidad(tProductoCalidad *producto, const char *linea)
{
    // L001,1001,OK\n
    char *ptr = strchr(linea, '\n');
    if (!ptr)
        return ERROR_LINEA;

    // ESTADO
    *ptr = '\0';
    ptr = strrchr(linea, ',');
    strcpy(producto->resultadoControl, ptr + 1);

    // ID PRODUCTO
    *ptr = '\0';
    ptr = strrchr(linea, ',');
    producto->idProducto = atoi(ptr + 1);

    // COD LOTE
    *ptr = '\0';
    strcpy(producto->codLote, linea);

    return TODO_OK;
}

void mostrarArchivoProductoTxt(const char *nomArch, const char *encavezado)
{
    FILE *archivo = fopen(nomArch, "rt");
    if (!archivo)
        return;

    printf("\n\n%s", encavezado);

    char linea[TAM_MAX_LINEA];
    while (fgets(linea, TAM_MAX_LINEA, archivo))
        printf("%s", linea);

    fclose(archivo);
}

void mostrarArchivoDeEntrada(const char *nomArch)
{
    mostrarArchivoProductoTxt(nomArch, "ARCHIVO DE ENTRADA:\n");
}

void mostrarArchivosDeSalida(const char *lotesAprobados, const char *lotesObservados)
{
    mostrarArchivoProductoTxt(lotesAprobados, "ARCHIVO DE LOTES APROBADOS:\n");
    mostrarArchivoProductoTxt(lotesObservados, "ARCHIVO DE LOTES OBSERVADOS:\n");
}

int menu()
{
    int opcion;

    do
    {
        printf("\n_______________________________\n");
        printf("|                               |\n");
        printf("|       MENU DE OPCIONES        |\n");
        printf("|_______________________________|\n");
        printf("|                               |\n");
        printf("|1) Procesar archivo de entrada |\n");
        printf("|2) Mostrar archivo de entrada  |\n");
        printf("|3) Mostrar archivos de salida  |\n");
        printf("|4) Salir                       |\n");
        printf("|_______________________________|\n");
        printf("Ingrese una opcion: ");

        scanf("%d", &opcion);

        do
        {
            if (opcion < 1 || opcion > 4)
            {
                printf("Opcion invalida. Ingrese nuevamente: ");
                fflush(stdin);
                scanf("%d", &opcion);
            }
        } while (opcion < 1 || opcion > 4);

        switch (opcion)
        {
        case 1:
            procesarArchivoDeEntrada("entrada.txt", "lotesAprobados.txt", "lotesObservados.txt");
            break;
        case 2:
            mostrarArchivoDeEntrada("entrada.txt");
            break;
        case 3:
            mostrarArchivosDeSalida("lotesAprobados.txt", "lotesObservados.txt");
            break;
        case 4:
            printf("Saliendo...\n");
            return 0;
        }
    } while (opcion != 4);

    return TODO_OK;
}
