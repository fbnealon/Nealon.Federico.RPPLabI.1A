#include "menu.h"

int menu()
{
    int opcion;
    system("cls");

    printf("-----------------ABM CLIENTES-----------------\n\n");
    printf("1 Alta de cliente\n");
    printf("2 Modificar datos del cliente\n");
    printf("3 Baja del cliente\n");
    printf("4 Nuevo alquiler\n");
    printf("5 Fin del alquiler\n");
    printf("6 Informar\n");
    printf("7 Salir\n\n");
    opcion = getInt("Ingrese opcion: ", "Caracter invalido, intente de nuevo: ", 1, 7);

    return opcion;
}

int informes_menu()
{
    int opcion;
    system("cls");

    printf("-----------------MENU INFORMES-----------------\n\n");
    printf("1 Nombre y apellido del asociado con mas alquileres\n");
    printf("2 El o los equipos mas alquilados y su cantidad\n");
    printf("3 El tiempo promedio real de alquiler de los equipos\n");
    printf("4 Todos los clientes con sus alquileres\n");
    printf("5 Salir al menu principal\n");
    opcion = getInt("Ingrese opcion: ", "Caracter invalido, intente de nuevo: ", 1, 5);

    return opcion;
}
