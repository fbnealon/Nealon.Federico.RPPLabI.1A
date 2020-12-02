#include "lib.h"

int cliente_buscarLibre(eCliente clientes[], int tamClientes)
{
    int index=-1;
    for(int i=0; i<tamClientes; i++)
    {
        if(clientes[i].isEmpty == 0)
        {
            index=i;
            break;
        }
    }
    return index;
}

int cliente_buscar(eCliente clientes[], int tamClientes, int id)

{
    int index=-1;
    for(int i=0; i<tamClientes; i++)
    {
        if(clientes[i].id==id && clientes[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }
    return index;
}

int cliente_inicializar(eCliente clientes[], int tamClientes)
{
    int error=1;
    if(clientes!=NULL && tamClientes>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            clientes[i].isEmpty=0;
        }
        error=0;
    }
    return error;
}

int cliente_mostrarTodos(eCliente clientes[], int tamClientes)
{
    int ok=0;
    int flag=0;
    if(clientes!=NULL && tamClientes>0)
    {
        printf(" ID       NOMBRE               APELLIDO               DNI\n\n");
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].isEmpty == 1)
            {
                cliente_mostrarUno(clientes[i]);
                flag=1;
                ok=1;
            }
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay clientes cargados en la lista\n\n");
            ok=2;
        }

    }
    return ok;
}

void cliente_mostrarUno(eCliente unCliente)
{
    printf("%4d     %20s     %20s     %8d\n", unCliente.id, unCliente.nombre, unCliente.apellido, unCliente.dni);
}

int cliente_alta(eCliente clientes[], int tamClientes, int idCliente)
{
    int ok=0, index;
    eCliente nuevoCliente;
    char confirma='n';

    if(clientes!=NULL && tamClientes>0 && idCliente>0)
    {
        system("cls");
        printf("   **** ALTA CLIENTE ****\n\n\n");
        index = cliente_buscarLibre(clientes, tamClientes);
        if(index == -1)
        {
            printf("Sistema completo\n\n");
        }
        else
        {
            nuevoCliente.id= idCliente;

            nuevoCliente.isEmpty= 1;

            do
            {
                getStrings("Ingrese nombre de cliente: ", "Demasiado largo, intente de nuevo: ", 20, nuevoCliente.nombre);
            }
            while (strlen(nuevoCliente.nombre)<1 || strlen(nuevoCliente.nombre)>20);

            do
            {
                system("cls");
                printf("NOMBRE: %s\n\n", nuevoCliente.nombre);
                getStrings("Ingrese apellido de cliente: ", "Demasiado largo, intente de nuevo: ", 20, nuevoCliente.apellido);
            }
            while (strlen(nuevoCliente.apellido)<2 || strlen(nuevoCliente.apellido)>20);

            system("cls");
            printf("NOMBRE: %s\nAPELLIDO: %s\n\n", nuevoCliente.nombre, nuevoCliente.apellido);
            nuevoCliente.dni= getInt("Ingrese el DNI del cliente: ", "Valor invalido, intente de nuevo: ", 30000000, 60000000);

            confirma=getLetter("Confirma alta de cliente?: ", "Caracter invalido, intente de nuevo: ");
            if(confirma=='s')
            {
                clientes[index] = nuevoCliente;
                ok=1;
            }
            else
            {
                ok=-1;
            }

        }
    }
    return ok;
}

int cliente_modificar(eCliente clientes[], int tamClientes)
{
    int ok=0, idClienteAux;
    char confirma;

    if(clientes!=NULL && tamClientes>0)
    {
        system("cls");
        printf("***            **** Modificar cliente ****            ***\n\n\n");
        cliente_mostrarTodos(clientes, tamClientes);
        idClienteAux= getInt("Ingrese ID de cliente a modificar: ", "ID invalido, intente de nuevo: ", 1000, 1999);
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].id==idClienteAux && clientes[i].isEmpty!=0)
            {
                printf("\n");
                cliente_mostrarUno(clientes[i]);
                printf("\n");
                confirma = getLetter("Confirma modificacion? ", "Caracter invalido, intente de nuevo: ");
                if(confirma == 's')
                {
                    clientes[i] = cliente_modificaciones(clientes[i]);
                    ok=1;
                }
                else
                {
                    ok=2;
                }
            }
        }
    }
    return ok;
}

eCliente cliente_modificaciones(eCliente unCliente)
{
    eCliente clienteAux= unCliente;
    int opcion;
    char confirma='n';
    char nombreAux[20];
    char apellidoAux[20];

    do
    {
        system("cls");
        printf("          ***   Modificaciones de cliente   ***\n\n\n");
        cliente_mostrarUno(unCliente);
        printf("\n");
        printf("1 Modificar Nombre\n");
        printf("2 Modificar Apellido\n");
        printf("3 Salir\n");
        opcion = getInt("Ingrese opcion: ", "Caracter invalido, intente de nuevo: ", 1, 3);
        switch(opcion)
        {
        case 1:
            getStrings("Ingrese nuevo nombre: ", "Error, intente de nuevo: ", 20, nombreAux);
            confirma= getLetter("Confirma cambio de nombre?: ", "Error, intente de nuevo: ");
            if(confirma=='s')
            {
                strcpy(clienteAux.nombre, nombreAux);
                printf("Cambio de nombre confirmado\n\n");
                break;
            }
            else
            {
                printf("Cambio de nombre cancelado por el usuario\n\n");
            }
            system("pause");
            break;
        case 2:
            getStrings("Ingrese nuevo apellido: ", "Error, intente de nuevo: ", 20, apellidoAux);
            confirma= getLetter("Confirma cambio de apellido?: ", "Error, intente de nuevo: ");
            if(confirma=='s')
            {
                strcpy(clienteAux.apellido, apellidoAux);
                printf("Cambio de apellido confirmado\n\n");
            }
            else
            {
                printf("Cambio de apellido cancelado por el usuario\n\n");
            }
            system("pause");
            break;
        case 3:
            printf("Saliendo del menu de modificaciones...\n\n\n");
            break;
        default:
            printf("Ha ingresado una opcion invalida\n\n");
            break;
        }
        unCliente=clienteAux;
    }
    while(opcion != 3);
    return unCliente;
}

int cliente_baja(eCliente clientes[], int tamClientes)
{
    int ok=0;
    int index;
    int id;
    char confirma;

    if(clientes!=NULL && tamClientes>0)
    {
        system("cls");
        printf("   **** Baja de cliente ****\n\n\n");
        cliente_mostrarTodos(clientes, tamClientes);
        id = getInt("Ingrese ID del cliente a dar de baja: ", "ID invalido, intente de nuevo: ", 1000, 1999);

        index= cliente_buscar(clientes, tamClientes, id);

        if(index == -1)
        {
            printf("No hay ningun cliente con el ID ingresado\n\n");
        }
        else
        {
            cliente_mostrarUno(clientes[index]);
            confirma = getLetter("Confirma baja? ", "Caracter invalido, intente de nuevo: ");
            if(confirma == 's')
            {
                clientes[index].isEmpty=0;
                ok=1;
            }
            else
            {
                ok=2;
            }
        }
    }
    return ok;
}

int operador_mostrarTodos(eOperador operadores[], int tamOperadores)
{
    int ok=0;
    if(operadores!=NULL && tamOperadores>0)
    {
        for(int i=0; i<tamOperadores; i++)
        {
            operador_mostrarUno(operadores[i]);
        }
        ok=1;
    }
    return ok;
}

void operador_mostrarUno(eOperador unOperador)
{
    printf("%4d     %20s     %20s\n", unOperador.id, unOperador.nombre, unOperador.apellido);
}

int operador_cargarApellido(eOperador operadores[], int tamOperadores, int id, char apellido[])
{
    int ok=0;
    if(operadores!=NULL && tamOperadores>0 && id>0)
    {
        for(int i=0; i<tamOperadores; i++)
        {
            if(operadores[i].id == id)
            {
                strcpy(apellido, operadores[i].apellido);
                ok=1;
            }
        }
    }
    return ok;
}

int alquiler_buscarLibre(eAlquiler alquileres[], int tamAlquileres)
{
    int index=-1;
    for(int i=0; i<tamAlquileres; i++)
    {
        if(alquileres[i].isEmpty == 0)
        {
            index=i;
            break;
        }
    }
    return index;
}

int alquiler_buscar(eAlquiler alquileres[], int tamAlquileres, int id)

{
    int index=-1;
    for(int i=0; i<tamAlquileres; i++)
    {
        if(alquileres[i].id==id && alquileres[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }
    return index;
}

int alquiler_inicializar(eAlquiler alquileres[], int tamAlquileres)
{
    int ok=0;
    if(alquileres!=NULL && tamAlquileres>0)
    {
        for(int i=0; i<tamAlquileres; i++)
        {
            alquileres[i].isEmpty=0;
        }
        ok=1;
    }
    return ok;
}

int alquiler_nuevo(eAlquiler alquileres[], int tamAlquileres, eCliente clientes[], int tamClientes, eOperador operadores[], int tamOperadores)
{
    int ok=0;
    int index;
    eAlquiler nuevoAlquiler;
    char confirma='n';

    if(alquileres!=NULL && tamAlquileres>0 && clientes!=NULL && tamClientes>0)
    {
        system("cls");
        printf("   **** NUEVO ALQUILER ****\n\n\n");
        index = alquiler_buscarLibre(alquileres, tamAlquileres);
        if(index == -1)
        {
            printf("Sistema completo\n\n");
        }
        else
        {
            nuevoAlquiler.estado=ALQUILADO;
            nuevoAlquiler.tiempoReal=0;
            nuevoAlquiler.isEmpty= 1;

            do
            {
                nuevoAlquiler.equipo=getInt("1 Amoladora\n2 Mezcladora\n3 Taladro\nElija equipo a alquilar:\n\n", "ERROR, intente de nuevo: ", 1, 3);
            }while (nuevoAlquiler.equipo<1 || nuevoAlquiler.equipo>3);

                if(cliente_mostrarTodos(clientes, tamClientes)==1)
                {
                    do
                    {
                        nuevoAlquiler.idCliente= getInt("Ingrese el ID del cliente que alquilara el equipo: ", "ERROR, intente de nuevo: ", 1000, 1999);
                    }while(cliente_buscar(clientes, tamClientes, nuevoAlquiler.idCliente)==-1);
                }

            nuevoAlquiler.tiempoEstimado= getInt("Ingrese el tiempo estimado de uso (1 a 50 hs): ", "ERROR, intente de nuevo: ", 1, 50);
            nuevoAlquiler.tiempoReal=0;

            operador_mostrarTodos(operadores, tamOperadores);
            nuevoAlquiler.idOperador=getInt("Ingrese ID de operador: ", "Error, intente de nuevo: ", 3000, 3002);

            confirma=getLetter("Confirma nuevo alquiler?: ", "Caracter invalido, intente de nuevo: ");
            if(confirma=='s')
            {
                alquileres[index] = nuevoAlquiler;
                ok=1;
            }
            else
            {
                ok=-1;
            }

        }
    }
    return ok;
}

int alquiler_fin(eAlquiler alquileres[], int tamAlquileres, eCliente clientes[], int tamClientes, int idAlquiler)
{
    int ok=0;
    int index;
    if(alquileres!=NULL && tamAlquileres>0  && clientes!=NULL && tamClientes>0 && idAlquiler>0)
    {
        index= alquiler_buscar(alquileres, tamAlquileres, idAlquiler);

        if(index!=-1)
        {
            alquileres[index].tiempoReal= getInt("Ingrese el tiempo real de alquiler (1 a 50 hs): ", "ERROR, intente de nuevo: ", 1, 50);
            alquileres[index].estado=FINALIZADO;
        }
        ok=1;
    }

    return ok;
}

int alquiler_mostrarTodos(eAlquiler alquileres[], int tamAlquileres)
{
    int ok=0;
    int flag=0;
    if(alquileres!=NULL && tamAlquileres>0)
    {
        printf(" ID       ID CLIENTE               EQUIPO               TIEMPO ESTIMADO         TIEMPO REAL         ID OPERADOR         ESTADO\n\n");
        for(int i=0; i<tamAlquileres; i++)
        {
            if(alquileres[i].isEmpty == 1)
            {
                alquiler_mostrarUno(alquileres[i]);
                flag=1;
                ok=1;
            }
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay alquileres cargados en la lista\n\n");
            ok=2;
        }

    }
    return ok;
}

void alquiler_mostrarUno(eAlquiler unAlquiler)
{
    printf("%4d  %4d  %2d  %3d  %3d  %4d  %2d\n", unAlquiler.id, unAlquiler.idCliente, unAlquiler.equipo, unAlquiler.tiempoEstimado, unAlquiler.tiempoReal, unAlquiler.idOperador, unAlquiler.estado);
}

int informes_informar(eAlquiler alquileres[], int tamAlquileres, eCliente clientes[], int tamClientes, eOperador operadores[], int tamOperadores, eMasAlquileres masAlquileres[])
{
    int ok=0;
    char seguir='s';
    char confirma='n';

    if(alquileres!=NULL && tamAlquileres>0  && clientes!=NULL && tamClientes>0 && operadores!=NULL && tamOperadores>0)
    {
        do
        {
            switch(informes_menu())
            {
            case 1:
                informe_nombreCompletoMasAlquileres(masAlquileres, clientes, tamClientes);
                break;
            case 2:
                informe_equiposMasAlquilados(alquileres, tamAlquileres);
                break;
            case 3:
                printf("El tiempo promedio real del alquiler de equipos es %.2f\n\n", informe_promedioTiempoReal(alquileres, tamAlquileres));
                break;
            case 4:
                informe_clientesConAlquileres(clientes, tamClientes, alquileres, tamAlquileres);
                break;
            case 5:
                confirma = getLetter("Confirma salida?: ", "Caracter invalido, intente de nuevo: ");
                if(confirma == 's')
                {
                    seguir = 'n';
                }
                break;
            }
            system("pause");
            system("cls");
        }while(seguir=='s');
        ok=1;
    }
    return ok;
}

int informe_cargarCantidadAlquileres(eAlquiler alquileres[], int tamAlquileres, eCliente clientes[], int tamClientes, eMasAlquileres masAlquileres[])
{
    int ok=0;
    int i=0;
    if(alquileres!=NULL && tamAlquileres>0 && clientes!=NULL && tamClientes>0)
    {
        for(i=0; i<tamClientes; i++)
        {
            masAlquileres[i].idCliente= clientes[i].id;
            masAlquileres[i].cantidadAlquileres=0;
        }
        for(i=0; i<tamAlquileres;i++)
        {
            if(masAlquileres[i].idCliente==alquileres[i].idCliente && alquileres[i].isEmpty==1)
            {
                masAlquileres[i].cantidadAlquileres++;
            }
        }

        ok=1;
    }


    return ok;
}

int informe_nombreCompletoMasAlquileres(eMasAlquileres masAlquileres[], eCliente clientes[], int tamClientes)
{
    int ok=0, auxMayor=0, i=0, auxIndex;
    if(masAlquileres!=NULL && clientes!=NULL && tamClientes>0)
    {
        printf("Los clientes con mas alquileres son: \n\n");
        for(i=0; i<tamClientes; i++)
        {
            if(auxMayor<masAlquileres[i].cantidadAlquileres)
            {
                auxMayor=masAlquileres[i].cantidadAlquileres;
            }
        }
        for(i=0; i<tamClientes; i++)
        {
            if(auxMayor==masAlquileres[i].cantidadAlquileres)
            {
                auxIndex=cliente_buscar(clientes, tamClientes, masAlquileres[i].idCliente);
                cliente_mostrarUno(clientes[auxIndex]);
            }
        }
        printf("\n\n");
        ok=1;
    }
    return ok;
}

int informe_equiposMasAlquilados(eAlquiler alquileres[], int tamAlquileres)
{
    int i=0, ok=0, cantAmoladoras=0, cantMezcladoras=0, cantTaladros=0;
    if(alquileres!=NULL && tamAlquileres>0)
    {
        for(i=0; i<tamAlquileres; i++)
        {
            if(alquileres[i].equipo==AMOLADORA && alquileres[i].isEmpty==1)
            {
                cantAmoladoras++;
            }
            else if(alquileres[i].equipo==MEZCLADORA && alquileres[i].isEmpty==1)
            {
                cantMezcladoras++;
            }
            else if(alquileres[i].equipo==TALADRO && alquileres[i].isEmpty==1)
            {
                cantTaladros++;
            }
        }
        if(cantAmoladoras>cantMezcladoras && cantAmoladoras>cantMezcladoras)
        {
            printf("El equipo mas alquilado es la amoladora con %d alquileres\n\n", cantAmoladoras);
        }
        else if(cantMezcladoras>cantAmoladoras && cantMezcladoras>cantTaladros)
        {
            printf("El equipo mas alquilado es la mezcladora con %d alquileres\n\n", cantMezcladoras);
        }
        else if(cantTaladros>cantAmoladoras && cantTaladros>cantMezcladoras)
        {
            printf("El equipo mas alquilado es el taladro con %d alquileres\n\n", cantTaladros);
        }
        ok=1;
    }
    return ok;
}

float informe_promedioTiempoReal(eAlquiler alquileres[], int tamAlquileres)
{
    int i=0, totalTiempo=0, cont=0;
    float promedio;
    if(alquileres!=NULL && tamAlquileres>0)
    {
        for(i=0; i<tamAlquileres; i++)
        {
            if(alquileres[i].isEmpty==1)
            {
                totalTiempo+= alquileres[i].tiempoReal;
                cont++;
            }
        }
        promedio= totalTiempo/cont;
    }
    return promedio;
}

int informe_clientesConAlquileres(eCliente clientes[], int tamClientes, eAlquiler alquileres[], int tamAlquileres)
{
    int ok=0;

    if(clientes!=NULL && tamClientes>0 && alquileres!=NULL && tamAlquileres>0)
    {
        for(int i=0;i<tamClientes;i++)
        {
            if(clientes[i].isEmpty==1)
            {
                cliente_mostrarUno(clientes[i]);
                printf("\n\n");
                for(int j=0; j<tamAlquileres;j++)
                {
                    if(alquileres[j].isEmpty==1 && alquileres[j].idCliente==clientes[i].id)
                    {
                        alquiler_mostrarUno(alquileres[j]);
                        printf("\n");
                    }
                }
            }
        }
        ok=1;
    }
    return ok;
}
