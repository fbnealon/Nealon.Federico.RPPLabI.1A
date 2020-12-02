#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "input.h"

#define AMOLADORA 1
#define MEZCLADORA 2
#define TALADRO 3

#define ALQUILADO 4
#define FINALIZADO 5

typedef struct
{
    int id; //DE 1000 a 1999
    char nombre[20];
    char apellido[20];
    int dni;
    int isEmpty; //1 OCUPADO, 0 LIBRE
}eCliente;

typedef struct
{
    int id; //de 2000 a 2999
    int idCliente;
    int equipo;
    int tiempoEstimado;
    int tiempoReal;
    int idOperador;
    int estado;
    int isEmpty; //1 OCUPADO, 0 LIBRE
}eAlquiler;

typedef struct
{
    int id; //3000 a 3999
    char nombre[20];
    char apellido[20];
}eOperador;

typedef struct
{
    int idCliente;
    int cantidadAlquileres;
}eMasAlquileres;

int cliente_buscarLibre(eCliente clientes[], int tamClientes);

int cliente_buscar(eCliente clientes[], int tamClientes, int id);

int cliente_alta(eCliente clientes[], int tamClientes, int idCliente);

int cliente_inicializar(eCliente clientes[], int tamClientes);

int cliente_mostrarTodos(eCliente clientes[], int tamClientes);

void cliente_mostrarUno(eCliente unCliente);

int cliente_modificar(eCliente clientes[], int tamClientes);

eCliente cliente_modificaciones(eCliente unCliente);

int cliente_baja(eCliente clientes[], int tamClientes);



int operador_mostrarTodos(eOperador operadores[], int tamOperadores);

void operador_mostrarUno(eOperador unOperador);

int operador_cargarApellido(eOperador operadores[], int tamOperadores, int id, char apellido[]);






int alquiler_nuevo(eAlquiler alquileres[], int tamAlquileres, eCliente clientes[], int tamClientes, eOperador operadores[], int tamOperadores);

int alquiler_buscarLibre(eAlquiler alquileres[], int tamAlquileres);

int alquiler_buscar(eAlquiler alquileres[], int tamAlquileres, int id);

int alquiler_inicializar(eAlquiler alquileres[], int tamAlquileres);

int alquiler_fin(eAlquiler alquileres[], int tamAlquileres, eCliente clientes[], int tamClientes, int idAlquiler);

int alquiler_mostrarTodos(eAlquiler alquileres[], int tamAlquileres);

void alquiler_mostrarUno(eAlquiler unAlquiler);




int informes_informar(eAlquiler alquileres[], int tamAlquileres, eCliente clientes[], int tamClientes, eOperador operadores[], int tamOperadores, eMasAlquileres masAlquileres[]);

int informe_cargarCantidadAlquileres(eAlquiler alquileres[], int tamAlquileres, eCliente clientes[], int tamClientes, eMasAlquileres masAlquileres[]);

int informe_nombreCompletoMasAlquileres(eMasAlquileres masAlquileres[], eCliente clientes[], int tamClientes);

int informe_equiposMasAlquilados(eAlquiler alquileres[], int tamAlquileres);

float informe_promedioTiempoReal(eAlquiler alquileres[], int tamAlquileres);

int informe_clientesConAlquileres(eCliente clientes[], int tamClientes, eAlquiler alquileres[], int tamAlquileres);

#endif // CLIENTE_H_INCLUDED
