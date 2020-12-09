#include "menu.h"

int menu()
{
    int opcion;
    system("cls");

    printf("-----------------BANCO-----------------\n\n");
    printf("1 Alta de cliente\n");
    printf("2 Modificar datos del cliente\n");
    printf("3 Baja del cliente\n");
    printf("4 Prestamo\n");
    printf("5 Saldar prestamo\n");
    printf("6 Reanudar prestamo\n");
    printf("7 Imprimir clientes\n");
    printf("8 Imprimir prestamos\n");
    printf("9 Informar clientes\n");
    printf("10 Salir\n\n");
    opcion = getInt("Ingrese opcion: ", "Caracter invalido, intente de nuevo: ", 1, 10);

    return opcion;
}

int informes_menu()
{
    int opcion;
    system("cls");

    printf("-----------------MENU INFORMES-----------------\n\n");
    printf("1 Cliente con mas prestamos activos\n");
    printf("2 Clietne con mas prestamos saldados\n");
    printf("3 Cliente con mas prestamos\n");
    printf("4 Salir al menu principal\n");
    opcion = getInt("Ingrese opcion: ", "Error, intente de nuevo: ", 1, 4);

    return opcion;
}
