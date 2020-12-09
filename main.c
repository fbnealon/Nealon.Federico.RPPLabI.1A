#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "lib.h"
#include "datastore.h"

#define TAM_CLIENTES 5
#define TAM_PRESTAMOS 10

void cargarVectores(eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos);

int main()
{
    char seguir='s', confirma='n';
    eCliente clientes[TAM_CLIENTES];
    ePrestamo prestamos[TAM_PRESTAMOS];
    eMasPrestamos masPrestamos[TAM_CLIENTES];
    eMasActivos masActivos[TAM_CLIENTES];
    eMasSaldados masSaldados[TAM_CLIENTES];
    int proximoIDCliente=1005;
    int proximoIDPrestamo=2005;
    int auxIDPrestamo;
    int rta;
    int auxIndex;
    int i=0;
    cliente_inicializar(clientes, TAM_CLIENTES);
    prestamo_inicializar(prestamos, TAM_PRESTAMOS);

    cargarVectores(clientes, 5, prestamos, 5);
    do
    {
        switch(menu())
        {
        case 1:
            if(cliente_alta(clientes, TAM_CLIENTES, proximoIDCliente)==1)
            {
                printf("Cliente dado de alta con exito con ID %d\n\n", proximoIDCliente);
                proximoIDCliente++;
            }
            break;
        case 2:
            rta=cliente_modificar(clientes, TAM_CLIENTES, prestamos, TAM_PRESTAMOS);
            if(rta==1)
            {
                printf("Cliente modificado con exito\n\n");
            }
            else if(rta==2)
            {
                printf("Modificacion cancelada\n\n");
            }
            else
            {
                printf("Error al modificar\n\n");
            }
            break;
        case 3:
            rta= cliente_baja(clientes, TAM_CLIENTES, prestamos, TAM_PRESTAMOS);
            if(rta==1)
            {
                printf("Cliente dado de baja con exito\n\n");
            }
            else if(rta==2)
            {
                printf("Baja cancelada\n\n");
            }
            else
            {
                printf("Error al intentar dar de baja un cliente\n\n");
            }
            break;
        case 4:
            if(prestamo_nuevo(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES, proximoIDPrestamo)==1)
            {
                printf("Nuevo prestamo generado con ID %d\n\n", proximoIDPrestamo);
                proximoIDPrestamo++;
            }
            else
            {
                printf("Prestamo no generado\n\n");
            }
            break;
        case 5:
            prestamo_mostrarActivos(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES);
            auxIDPrestamo= getInt("Ingrese el ID del prestamo a saldar: ", "Error, intente de nuevo: ", 2000, 2999);
            for(i=0; i<TAM_PRESTAMOS; i++)
            {
                if(auxIDPrestamo==prestamos[i].id && prestamos[i].isEmpty==1)
                {
                    printf("Datos de cliente: \n");
                    auxIndex= cliente_buscar(clientes, TAM_CLIENTES, prestamos[i].idCliente);
                    cliente_mostrarUno(clientes[auxIndex], prestamos, TAM_PRESTAMOS);
                }
            }
            if(prestamo_saldar(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES, auxIDPrestamo))
            {
                printf("Prestamo saldado\n\n");
            }
            break;
        case 6:
            prestamo_mostrarSaldados(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES);
            auxIDPrestamo= getInt("Ingrese el ID del prestamo a reanudar: ", "Error, intente de nuevo: ", 2000, 2999);
            for(i=0; i<TAM_PRESTAMOS; i++)
            {
                if(auxIDPrestamo==prestamos[i].id && prestamos[i].isEmpty==1)
                {
                    printf("Datos de cliente: \n");
                    auxIndex= cliente_buscar(clientes, TAM_CLIENTES, prestamos[i].idCliente);
                    cliente_mostrarUno(clientes[auxIndex], prestamos, TAM_PRESTAMOS);
                }
            }
            if(prestamo_reanudar(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES, auxIDPrestamo))
            {
                printf("Prestamo reanudado\n\n");
            }
            break;
        case 7:
            cliente_mostrarTodos(clientes, TAM_CLIENTES, prestamos, TAM_PRESTAMOS);
            break;
        case 8:
            prestamo_mostrarTodos(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES);
            break;
        case 9:
            masActivos_cargarCantidadActivos(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES, masActivos);
            masSaldados_cargarCantidadSaldados(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES, masSaldados);
            masPrestamos_cargarCantidadPrestamos(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES, masPrestamos);
            informes_informar(prestamos, TAM_PRESTAMOS, clientes, TAM_CLIENTES, masActivos, masSaldados, masPrestamos);
            break;
        case 10:
            confirma = getLetter("Confirma salida?: ", "Caracter invalido, intente de nuevo: ");
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
    return 0;
}

void cargarVectores(eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos)
{
    int i=0;
    for(i=0; i<tamClientes; i++)
    {
        clientes[i]=hClientes[i];
    }
    for(i=0; i<tamPrestamos; i++)
    {
        prestamos[i]=hPrestamos[i];
    }
}
