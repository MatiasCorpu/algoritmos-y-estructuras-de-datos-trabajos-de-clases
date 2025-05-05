#include "utilidades.h"

void crearArchivoProductosTxt(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "wt");
    if (archivo == NULL)
        return;

    tProd productos[] = {
        {"A01", "Monitor", 10},
        {"B01", "Teclado", 20},
        {"C01", "Mouse", 30},
        {"D01", "CPU", 40},
        {"E01", "Impresora", 50},
        {"F01", "Escaner", 60},
        {"G01", "Proyector", 70},
        {"H01", "Parlantes", 80},
        {"I01", "Webcam", 90},
        {"J01", "Router", 100}};

    for (int i = 0; i < sizeof(productos) / sizeof(tProd); i++)
        fprintf(archivo, "%s;%s;%u\n", productos[i].cod, productos[i].descipcion, productos[i].cant);

    fclose(archivo);
}

void mostrarArchivo(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rt");
    if (archivo == NULL)
        return;

    char linea[TAM_LINEA];
    printf("ARCHIVO %s:\n", nombreArchivo);
    while (fgets(linea, TAM_LINEA, archivo))
        printf("%s", linea);
    fclose(archivo);
}

int archivoTxtALista(tLista *pl, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rt");
    if (!archivo)
        return ERROR_ARCHIVO;

    char linea[TAM_LINEA];
    tProd producto;

    while (fgets(linea, TAM_LINEA, archivo))
    {
        lineaAProducto(&producto, linea);
        listaPonerAlFinal(pl, &producto, sizeof(tProd)); // logica FIFO: primero en entrar, primero en salir
    }
    fclose(archivo);
    printf("\nArchivo %s cargado a la lista.\n", nombreArchivo);
    return TODO_BIEN;
}

int lineaAProducto(tProd *p, const char *linea)
{
    char *ptr = strchr(linea, '\n');
    if (!ptr)
        return ERROR_LINEA_LARGA;

    // CANTIDAD
    *ptr = '\0';
    ptr = strrchr(linea, ';');
    p->cant = atoi(ptr + 1);

    // DESCRIPCION
    *ptr = '\0';
    ptr = strrchr(linea, ';');
    strcpy(p->descipcion, ptr + 1);

    // CODIGO
    *ptr = '\0';
    strcpy(p->cod, linea);

    return TODO_BIEN;
}

void accionMostrar(void *dato, void *parametro)
{
    tProd *p = (tProd *)dato;
    printf("%4s%12s%4u\n", p->cod, p->descipcion, p->cant);
}

void accionAumentarStock(void *dato, void *parametro)
{
    tProd *p = (tProd *)dato;
    unsigned porcentaje = *(unsigned *)parametro;
    p->cant += (p->cant * porcentaje) / 100;
}

void menu(tLista *pl, const char *nombreArchivo)
{
    int opcion;

    do
    {
        printf("----------------------\n");
        printf("1. Mostrar lista\n");
        printf("2. Aumentar stock de productos\n");
        printf("3. Agregar producto al inicio\n");
        printf("4. Agregar producto al final\n");
        printf("5. Eliminar primer producto\n");
        printf("6. Eliminar ultimo producto\n");
        printf("7. Ver primer producto\n");
        printf("8. Ver ultimo producto\n");
        printf("9. Guardar cambios en archivo %s\n", nombreArchivo);
        printf("10. Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        printf("----------------------\n");

        switch (opcion)
        {
        case 1:
            mostrarLista(pl);
            break;
        case 2:
            aumentarStockProductos(pl);
            break;
        case 3:
            agregarProductoAlInicio(pl);
            break;
        case 4:
            agregarProductoAlFinal(pl);
            break;
        case 5:
            eliminarPrimerProducto(pl);
            break;
        case 6:
            eliminarUltimoProducto(pl);
            break;
        case 7:
            verPrimerProducto(pl);
            break;
        case 8:
            verUltimoProducto(pl);
            break;
        case 9:
            guardarCambiosEnArchivo(pl, nombreArchivo);
            break;
        case 10:
            printf("Saliendo del menu...\n");
            break;
        default:
            printf("Opcion invalida. Intente nuevamente.\n");
            break;
        }
    } while (opcion != SALIR_MENU);
}

void mostrarLista(const tLista *pl)
{
    printf("LISTA DE PRODUCTOS:\n");
    listaMap(pl, accionMostrar, NULL);
}

void aumentarStockProductos(tLista *pl)
{
    unsigned porcentaje;
    printf("Ingrese el porcentaje a aumentar: ");
    fflush(stdin);
    do
    {
        scanf("%u", &porcentaje);
        if (porcentaje < 0 || porcentaje > 100)
            printf("Porcentaje invalido. Ingrese un valor entre 0 y 100: ");
    } while (porcentaje < 0 || porcentaje > 100);

    listaMap(pl, accionAumentarStock, &porcentaje);
}

void agregarProductoAlInicio(tLista *pl)
{
    tProd producto;
    printf("Ingrese codigo, descripcion y cantidad del producto (separados por espacio): ");
    fflush(stdin);
    scanf("%s %s %u", producto.cod, producto.descipcion, &producto.cant);
    if (listaPonerAlInicio(pl, &producto, sizeof(tProd)) == LISTA_LLENA)
        printf("Error: lista llena. No se puede agregar el producto.\n");
    else
        printf("Producto agregado al inicio de la lista.\n");
}

void agregarProductoAlFinal(tLista *pl)
{
    tProd producto;
    printf("Ingrese codigo, descripcion y cantidad del producto (separados por espacio): ");
    fflush(stdin);
    scanf("%s %s %u", producto.cod, producto.descipcion, &producto.cant);
    if (listaPonerAlFinal(pl, &producto, sizeof(tProd)) == LISTA_LLENA)
        printf("Error: lista llena. No se puede agregar el producto.\n");
    else
        printf("Producto agregado al final de la lista.\n");
}

void eliminarPrimerProducto(tLista *pl)
{
    tProd producto;
    if (listaSacarPrimero(pl, &producto, sizeof(tProd)) == LISTA_VACIA)
        printf("Error: lista vacia. No se puede eliminar el producto.\n");
    else
        printf("Producto eliminado: %s %s %u\n", producto.cod, producto.descipcion, producto.cant);
}

void eliminarUltimoProducto(tLista *pl)
{
    tProd producto;
    if (listaSacarUltimo(pl, &producto, sizeof(tProd)) == LISTA_VACIA)
        printf("Error: lista vacia. No se puede eliminar el producto.\n");
    else
        printf("Producto eliminado: %s %s %u\n", producto.cod, producto.descipcion, producto.cant);
}

void verPrimerProducto(const tLista *pl)
{
    tProd producto;
    if (listaVerPrimero(pl, &producto, sizeof(tProd)) == LISTA_VACIA)
        printf("Error: lista vacia. No se puede ver el producto.\n");
    else
        printf("Primer producto: %s %s %u\n", producto.cod, producto.descipcion, producto.cant);
}

void verUltimoProducto(const tLista *pl)
{
    tProd producto;
    if (listaVerUltimo(pl, &producto, sizeof(tProd)) == LISTA_VACIA)
        printf("Error: lista vacia. No se puede ver el producto.\n");
    else
        printf("Ultimo producto: %s %s %u\n", producto.cod, producto.descipcion, producto.cant);
}

void guardarCambiosEnArchivo(tLista *pl, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "wt");
    if (archivo == NULL)
        return;

    tProd producto;
    while (!listaVacia(pl))
    {
        listaSacarPrimero(pl, &producto, sizeof(tProd));
        fprintf(archivo, "%s;%s;%u\n", producto.cod, producto.descipcion, producto.cant);
    }
    fclose(archivo);
    printf("Cambios guardados en el archivo %s.\n", nombreArchivo);
}
