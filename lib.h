#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "input.h"

#define ACTIVO 1
#define SALDADO 0

typedef struct
{
    int id; //DE 1000 a 1999
    char nombre[20];
    char apellido[20];
    int cuil;
    int isEmpty; //1 OCUPADO, 0 LIBRE
}eCliente;

typedef struct
{
    int id; //de 2000 a 2999
    int idCliente;
    int importe;
    int cantidadDeCuotas;
    int estado; //1 ACTIVO, 0 SALDADO
    int isEmpty; //1 OCUPADO, 0 LIBRE
}ePrestamo;

typedef struct
{
    int idCliente;
    int cantidadDePrestamos;
    int isEmpty;  //1 OCUPADO, 0 LIBRE
}eMasPrestamos;

typedef struct
{
    int idCliente;
    int cantidadActivos;
    int isEmpty;  //1 OCUPADO, 0 LIBRE
}eMasActivos;

typedef struct
{
    int idCliente;
    int cantidadSaldados;
    int estado; //1 ACTIVO, 0 SALDADO
    int isEmpty;  //1 OCUPADO, 0 LIBRE
}eMasSaldados;






int cliente_buscarLibre(eCliente clientes[], int tamClientes);

int cliente_buscar(eCliente clientes[], int tamClientes, int id);

int cliente_alta(eCliente clientes[], int tamClientes, int idCliente);

int cliente_inicializar(eCliente clientes[], int tamClientes);

int cliente_mostrarTodos(eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos);

void cliente_mostrarUno(eCliente unCliente, ePrestamo prestamos[], int tamPrestamos);

int cliente_modificar(eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos);

eCliente cliente_modificaciones(eCliente unCliente, ePrestamo prestamos[], int tamPrestamos);

int cliente_baja(eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos);

int cliente_cargarNombre(eCliente clientes[], int tamClientes, int id, char nombre[]);

int cliente_cargarApellido(eCliente clientes[], int tamClientes, int id, char apellido[]);

int cliente_cargarNombreCompleto(char nombre[], char apellido[], char completo[]);

int cliente_cargarCuil(eCliente clientes[], int tamClientes, int id);

int cliente_cargarPrestamosActivos(eCliente unCliente, int id, ePrestamo prestamos[], int tamPrestamos);




int prestamo_inicializar(ePrestamo prestamos[], int tamPrestamos);

int prestamo_buscarLibre(ePrestamo prestamos[], int tamPrestamos);

int prestamo_buscar(ePrestamo prestamos[], int tamPrestamos, int id);

int prestamo_nuevo(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, int idPrestamo);

int prestamo_saldar(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, int idPrestamo);

int prestamo_reanudar(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, int idPrestamo);

int prestamo_mostrarTodos(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes);

int prestamo_mostrarActivos(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes);

int prestamo_mostrarSaldados(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes);

void prestamo_mostrarUno(ePrestamo unPrestamo, eCliente clientes[], int tamClientes, char estado[]);





int masPrestamos_cargarCantidadPrestamos(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, eMasPrestamos masPrestamos[]);

int masActivos_cargarCantidadActivos(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, eMasActivos masActivos[]);

int masSaldados_cargarCantidadSaldados(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, eMasSaldados masSaldados[]);





int informes_informar(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, eMasActivos masActivos[], eMasSaldados masSaldados[], eMasPrestamos masPrestamos[]);

int informe_clienteConMasActivos(eMasActivos masActivos[], eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos);

int informe_clienteConMasSaldados(eMasSaldados masSaldados[], eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos);

int informe_clienteConMasPrestamos(eMasPrestamos masPrestamos[], eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos);

#endif // CLIENTE_H_INCLUDED
