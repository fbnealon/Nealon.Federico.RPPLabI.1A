#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "lib.h"
#include "datastore.h"

#define TAM_CLIENTES 5
#define TAM_ALQUILERES 10
#define TAM_OPERADORES 3

void cargarVectores(eCliente clientes[], int tamClientes, eAlquiler alquileres[], int tamAlquileres, eOperador operadores[], int tamOperadores);

int main()
{
    char seguir='s', confirma='n';
    eCliente clientes[TAM_CLIENTES];
    eAlquiler alquileres[TAM_ALQUILERES];
    eOperador operadores[TAM_OPERADORES];
    eMasAlquileres masAlquileres[TAM_CLIENTES];
    int proximoIDCliente=1005;
    int proximoIDAlquiler=2005;
    int auxIDAlquiler;
    int rta;
    cliente_inicializar(clientes, TAM_CLIENTES);
    alquiler_inicializar(alquileres, TAM_ALQUILERES);

    cargarVectores(clientes, 5, alquileres, 5, operadores, 3);
    do
    {
        switch(menu())
        {
        case 1:
            if(cliente_alta(clientes, TAM_CLIENTES, proximoIDCliente)==1)
            {
                printf("Cliente dado de alta con exito!\n\n");
                proximoIDCliente++;
            }
            break;
        case 2:
            rta=cliente_modificar(clientes, TAM_CLIENTES);
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
            rta= cliente_baja(clientes, TAM_CLIENTES);
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

            if(alquiler_nuevo(alquileres, TAM_ALQUILERES, clientes, TAM_CLIENTES, operadores, TAM_OPERADORES)==1)
            {
                proximoIDAlquiler++;
            }
            break;
        case 5:
            alquiler_mostrarTodos(alquileres, TAM_ALQUILERES);
            auxIDAlquiler= getInt("Ingrese id de alquiler a finalizar: ", "ERROR, intente de nuevo: ", 2000, 2999);
            alquiler_fin(alquileres, TAM_ALQUILERES, clientes, TAM_CLIENTES, auxIDAlquiler);
            break;
        case 6:
            informe_cargarCantidadAlquileres(alquileres, TAM_ALQUILERES, clientes, TAM_CLIENTES, masAlquileres);
            informes_informar(alquileres, TAM_ALQUILERES, clientes, TAM_CLIENTES, operadores, TAM_OPERADORES, masAlquileres);
            break;
        case 7:
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

void cargarVectores(eCliente clientes[], int tamClientes, eAlquiler alquileres[], int tamAlquileres, eOperador operadores[], int tamOperadores)
{
    int i=0;
    for(i=0; i<tamClientes; i++)
    {
        clientes[i]=hClientes[i];
    }
    for(i=0; i<tamAlquileres; i++)
    {
        alquileres[i]=hAlquileres[i];
    }
    for(i=0; i<tamOperadores; i++)
    {
        operadores[i]=hOperadores[i];
    }
}