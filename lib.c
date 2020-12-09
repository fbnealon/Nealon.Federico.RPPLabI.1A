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

int cliente_mostrarTodos(eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos)
{
    int ok=0;
    int flag=0;
    if(clientes!=NULL && tamClientes>0 && prestamos!=NULL && tamPrestamos>0)
    {
        printf(" ID                    NOMBRE                 APELLIDO         CUIL       PRESTAMOS ACTIVOS\n\n");
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].isEmpty == 1)
            {
                cliente_mostrarUno(clientes[i], prestamos, tamPrestamos);
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

void cliente_mostrarUno(eCliente unCliente, ePrestamo prestamos[], int tamPrestamos)
{
    int cantidad= cliente_cargarPrestamosActivos(unCliente, unCliente.id, prestamos, tamPrestamos);
    printf("%4d     %20s     %20s     %8d     %3d\n", unCliente.id, unCliente.nombre, unCliente.apellido, unCliente.cuil, cantidad);
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
            nuevoCliente.cuil= getInt("Ingrese el CUIL del cliente: ", "Valor invalido, intente de nuevo: ", 30000000, 60000000);

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

int cliente_modificar(eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos)
{
    int ok=0, idClienteAux;
    char confirma;

    if(clientes!=NULL && tamClientes>0)
    {
        system("cls");
        printf("***            **** Modificar cliente ****            ***\n\n\n");
        cliente_mostrarTodos(clientes, tamClientes, prestamos, tamPrestamos);
        idClienteAux= getInt("Ingrese ID de cliente a modificar: ", "ID invalido, intente de nuevo: ", 1000, 1999);
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].id==idClienteAux && clientes[i].isEmpty!=0)
            {
                printf("\n");
                cliente_mostrarUno(clientes[i], prestamos, tamPrestamos);
                printf("\n");
                confirma = getLetter("Confirma modificacion? ", "Caracter invalido, intente de nuevo: ");
                if(confirma == 's')
                {
                    clientes[i] = cliente_modificaciones(clientes[i], prestamos, tamPrestamos);
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

eCliente cliente_modificaciones(eCliente unCliente, ePrestamo prestamos[], int tamPrestamos)
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
        cliente_mostrarUno(unCliente, prestamos, tamPrestamos);
        printf("\n");
        printf("1 Modificar Nombre\n");
        printf("2 Modificar Apellido\n");
        printf("3 Modificar CUIL\n");
        printf("4 Salir\n");
        opcion = getInt("Ingrese opcion: ", "Caracter invalido, intente de nuevo: ", 1, 4);
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
            clienteAux.cuil= getInt("Ingrese el nuevo CUIL del cliente: ", "Error, intente de nuevo: ", 0, 60000000);
            confirma=getLetter("Confirma cambio de CUIL?: ", "Error, intente de nuevo: ");
            if(confirma=='s')
            {
                printf("Cambio de CUIL confirmado\n\n");
            }
            break;
        case 4:
            confirma=getLetter("Confirma salida al menu principal?: ", "Error, intente de nuevo");
            if(confirma=='s')
            {
                printf("Saliendo del menu de modificaciones...\n\n\n");
            }
            break;
        default:
            printf("Ha ingresado una opcion invalida\n\n");
            break;
        }
        unCliente=clienteAux;
    }
    while(opcion != 4);
    return unCliente;
}

int cliente_baja(eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos)
{
    int ok=0;
    int index;
    int id;
    char confirma;

    if(clientes!=NULL && tamClientes>0)
    {
        system("cls");
        printf("   **** Baja de cliente ****\n\n\n");
        cliente_mostrarTodos(clientes, tamClientes, prestamos, tamPrestamos);
        id = getInt("Ingrese ID del cliente a dar de baja: ", "ID invalido, intente de nuevo: ", 1000, 1999);

        index= cliente_buscar(clientes, tamClientes, id);

        if(index == -1)
        {
            printf("No hay ningun cliente con el ID ingresado\n\n");
        }
        else
        {
            cliente_mostrarUno(clientes[index], prestamos, tamPrestamos);
            confirma = getLetter("Confirma baja? ", "Caracter invalido, intente de nuevo: ");
            if(confirma == 's')
            {
                for(int i=0; i<tamPrestamos; i++)
                {
                    if(prestamos[i].isEmpty==1 && prestamos[i].idCliente== clientes[index].id)
                    {
                        prestamos[i].isEmpty=0;
                    }
                }
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

int cliente_cargarCuil(eCliente clientes[], int tamClientes, int id)
{
    int cuilAux=-1;
    if(clientes!=NULL && tamClientes>0 && id>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].isEmpty==1 && clientes[i].id==id)
            {
                cuilAux= clientes[i].cuil;
            }
        }
    }
    return cuilAux;
}

int cliente_cargarPrestamosActivos(eCliente unCliente, int id, ePrestamo prestamos[], int tamPrestamos)
{
    int cont=0;
    if(id>0 && prestamos!=NULL && tamPrestamos>0)
    {
        if(unCliente.isEmpty==1 && unCliente.id==id)
        {
            for(int j=0; j<tamPrestamos; j++)
            {
                if(prestamos[j].isEmpty==1 && prestamos[j].idCliente==unCliente.id && prestamos[j].estado==ACTIVO)
                {
                    cont++;
                }
            }
        }
    }
    return cont;
}

int cliente_cargarNombre(eCliente clientes[], int tamClientes, int id, char nombre[])
{
    int ok=0;
    if(clientes!=NULL && tamClientes>0 && id>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].isEmpty==1 && clientes[i].id==id)
            {
                strcpy(nombre, clientes[i].nombre);
            }
        }
        ok=1;
    }
    return ok;
}

int cliente_cargarApellido(eCliente clientes[], int tamClientes, int id, char apellido[])
{
    int ok=0;
    if(clientes!=NULL && tamClientes>0 && id>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].isEmpty==1 && clientes[i].id==id)
            {
                strcpy(apellido, clientes[i].apellido);
            }
        }
        ok=1;
    }
    return ok;
}

int cliente_cargarNombreCompleto(char nombre[], char apellido[], char completo[])
{
    int ok=0;
    if(nombre!=NULL && apellido!=NULL)
    {
        strcpy(completo, nombre);
        strcat(completo, " ");
        strcat(completo, apellido);
        ok=1;
    }
    return ok;
}

int prestamo_buscarLibre(ePrestamo prestamos[], int tamPrestamos)
{
    int index=-1;
    for(int i=0; i<tamPrestamos; i++)
    {
        if(prestamos[i].isEmpty == 0)
        {
            index=i;
            break;
        }
    }
    return index;
}

int prestamo_buscar(ePrestamo prestamos[], int tamPrestamos, int id)

{
    int index=-1;
    for(int i=0; i<tamPrestamos; i++)
    {
        if(prestamos[i].id==id && prestamos[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }
    return index;
}

int prestamo_inicializar(ePrestamo prestamos[], int tamPrestamos)
{
    int ok=0;
    if(prestamos!=NULL && tamPrestamos>0)
    {
        for(int i=0; i<tamPrestamos; i++)
        {
            prestamos[i].isEmpty=0;
        }
        ok=1;
    }
    return ok;
}

int prestamo_cargarEstado(ePrestamo unPrestamo, char estado[])
{
    int ok=0;
    if(unPrestamo.estado == ACTIVO)
    {
        strcpy(estado, "ACTIVO");
        ok=1;
    }
    if(unPrestamo.estado == SALDADO)
    {
        strcpy(estado, "SALDADO");
        ok=1;
    }
    return ok;
}

int prestamo_nuevo(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, int idPrestamo)
{
    int ok=0;
    int index;
    ePrestamo nuevoPrestamo;
    char confirma='n';

    if(prestamos!=NULL && tamPrestamos>0 && clientes!=NULL && tamClientes>0)
    {
        system("cls");
        printf("   **** NUEVO ALQUILER ****\n\n\n");
        index = prestamo_buscarLibre(prestamos, tamPrestamos);
        if(index == -1)
        {
            printf("Sistema completo\n\n");
        }
        else
        {
            nuevoPrestamo.id=idPrestamo;
            nuevoPrestamo.estado=ACTIVO;
            nuevoPrestamo.isEmpty= 1;

            if(cliente_mostrarTodos(clientes, tamClientes, prestamos, tamPrestamos)==1)
            {
                do
                {
                    nuevoPrestamo.idCliente= getInt("Ingrese el ID del cliente que quiere un nuevo prestamo: ", "ERROR, intente de nuevo: ", 1000, 1999);
                }
                while(cliente_buscar(clientes, tamClientes, nuevoPrestamo.idCliente)==-1);
            }

            nuevoPrestamo.importe= getInt("Ingrese el importe del prestamo (5 millones maximo): ", "ERROR, intente de nuevo: ", 0, 5000000);
            nuevoPrestamo.cantidadDeCuotas= getInt("Ingrese la cantidad de cuotas del prestamo (108 maximo): ", "ERROR, intente de nuevo: ", 0, 108);

            confirma=getLetter("Confirma nuevo prestamo?: ", "Caracter invalido, intente de nuevo: ");
            if(confirma=='s')
            {
                prestamos[index] = nuevoPrestamo;
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

int prestamo_saldar(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, int idPrestamo)
{
    int ok=0;
    int index;
    char confirma='n';
    if(prestamos!=NULL && tamPrestamos>0  && clientes!=NULL && tamClientes>0 && idPrestamo>0)
    {
        index= prestamo_buscar(prestamos, tamPrestamos, idPrestamo);

        if(index!=-1)
        {
            confirma=getLetter("Confirma saldo de prestamo?: ", "ERROR, intente de nuevo: ");
            if(confirma=='s')
            {
                prestamos[index].estado=SALDADO;
                ok=1;
            }
        }
    }

    return ok;
}

int prestamo_reanudar(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, int idPrestamo)
{
    int ok=0;
    int index;
    char confirma='n';
    if(prestamos!=NULL && tamPrestamos>0  && clientes!=NULL && tamClientes>0 && idPrestamo>0)
    {
        index= prestamo_buscar(prestamos, tamPrestamos, idPrestamo);

        if(index!=-1)
        {
            confirma=getLetter("Confirma reanudacion de prestamo?: ", "ERROR, intente de nuevo: ");
            if(confirma=='s')
            {
                prestamos[index].estado=ACTIVO;
                ok=1;
            }
        }
    }

    return ok;
}

int prestamo_mostrarTodos(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes)
{
    int ok=0;
    int flag=0;
    char nombreAux[20];
    char apellidoAux[20];
    char completoAux[20];
    char estado[20];
    if(prestamos!=NULL && tamPrestamos>0 && clientes!=NULL && tamClientes>0)
    {
        printf(" ID  CUIL CLIENTE     PRESTAMO     CUOTAS   ESTADO\n");
        for(int i=0; i<tamPrestamos; i++)
        {
            if(prestamos[i].isEmpty == 1)
            {
                cliente_cargarNombre(clientes, tamClientes, prestamos[i].idCliente, nombreAux);
                cliente_cargarApellido(clientes, tamClientes, prestamos[i].idCliente, apellidoAux);
                cliente_cargarNombreCompleto(nombreAux, apellidoAux, completoAux);
                prestamo_cargarEstado(prestamos[i], estado);

                prestamo_mostrarUno(prestamos[i], clientes, tamClientes, estado);
                flag=1;
                ok=1;
            }
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay prestamos cargados en la lista\n\n");
            ok=2;
        }

    }
    return ok;
}

int prestamo_mostrarActivos(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes)
{
    int ok=0;
    int flag=0;
    char nombreAux[20];
    char apellidoAux[20];
    char completoAux[20];
    char estado[20];
    if(prestamos!=NULL && tamPrestamos>0 && clientes!=NULL && tamClientes>0)
    {
        printf(" ID  CUIL CLIENTE      PRESTAMO     CUOTAS   ESTADO\n");
        for(int i=0; i<tamPrestamos; i++)
        {
            if(prestamos[i].isEmpty == 1 && prestamos[i].estado==ACTIVO)
            {
                cliente_cargarNombre(clientes, tamClientes, prestamos[i].idCliente, nombreAux);
                cliente_cargarApellido(clientes, tamClientes, prestamos[i].idCliente, apellidoAux);
                cliente_cargarNombreCompleto(nombreAux, apellidoAux, completoAux);
                prestamo_cargarEstado(prestamos[i], estado);

                prestamo_mostrarUno(prestamos[i], clientes, tamClientes, estado);
                flag=1;
                ok=1;
            }
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay prestamos activos en la lista\n\n");
            ok=2;
        }

    }
    return ok;
}

int prestamo_mostrarSaldados(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes)
{
    int ok=0;
    int flag=0;
    char nombreAux[20];
    char apellidoAux[20];
    char completoAux[20];
    char estado[20];
    if(prestamos!=NULL && tamPrestamos>0 && clientes!=NULL && tamClientes>0)
    {
        printf(" ID                         CLIENTE PRESTAMO     CUOTAS   ESTADO\n");
        for(int i=0; i<tamPrestamos; i++)
        {
            if(prestamos[i].isEmpty == 1 && prestamos[i].estado==SALDADO)
            {
                cliente_cargarNombre(clientes, tamClientes, prestamos[i].idCliente, nombreAux);
                cliente_cargarApellido(clientes, tamClientes, prestamos[i].idCliente, apellidoAux);
                cliente_cargarNombreCompleto(nombreAux, apellidoAux, completoAux);
                prestamo_cargarEstado(prestamos[i], estado);

                prestamo_mostrarUno(prestamos[i], clientes, tamClientes, estado);
                flag=1;
                ok=1;
            }
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay prestamos activos en la lista\n\n");
            ok=2;
        }

    }
    return ok;
}

void prestamo_mostrarUno(ePrestamo unPrestamo, eCliente clientes[], int tamClientes, char estado[])
{
    int cuil= cliente_cargarCuil(clientes, tamClientes, unPrestamo.idCliente);
    printf("%4d %12d %12d %8d %10s\n", unPrestamo.id, cuil, unPrestamo.importe, unPrestamo.cantidadDeCuotas, estado);
}

int informes_informar(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, eMasActivos masActivos[], eMasSaldados masSaldados[], eMasPrestamos masPrestamos[])
{
    int ok=0;
    char seguir='s';
    char confirma='n';

    if(prestamos!=NULL && tamPrestamos>0  && clientes!=NULL && tamClientes>0)
    {
        do
        {
            switch(informes_menu())
            {
            case 1:
                informe_clienteConMasActivos(masActivos, clientes, tamClientes, prestamos, tamPrestamos);
                break;
            case 2:
                informe_clienteConMasSaldados(masSaldados, clientes, tamClientes, prestamos, tamPrestamos);
                break;
            case 3:
                informe_clienteConMasPrestamos(masPrestamos, clientes, tamClientes, prestamos, tamPrestamos);
                break;
            case 4:
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
        ok=1;
    }
    return ok;
}

int masPrestamos_cargarCantidadPrestamos(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, eMasPrestamos masPrestamos[])
{
    int ok=0;
    int i=0, j=0;
    if(prestamos!=NULL && tamPrestamos>0 && clientes!=NULL && tamClientes>0)
    {
        for(i=0; i<tamClientes; i++)
        {
            masPrestamos[i].idCliente= clientes[i].id;
            masPrestamos[i].isEmpty= clientes[i].isEmpty;
            masPrestamos[i].cantidadDePrestamos=0;
            for(j=0; j<tamPrestamos; j++)
            {
                if(prestamos[j].idCliente==masPrestamos[i].idCliente && masPrestamos[i].isEmpty==1 && prestamos[j].isEmpty==1)
                {
                    masPrestamos[i].cantidadDePrestamos++;
                }
            }
        }
        ok=1;
    }


    return ok;
}

int masActivos_cargarCantidadActivos(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, eMasActivos masActivos[])
{
    int ok=0;
    int i=0, j=0;
    if(prestamos!=NULL && tamPrestamos>0 && clientes!=NULL && tamClientes>0)
    {
        for(i=0; i<tamClientes; i++)
        {
            masActivos[i].idCliente= clientes[i].id;
            masActivos[i].isEmpty= clientes[i].isEmpty;
            masActivos[i].cantidadActivos=0;
            for(j=0; j<tamPrestamos; j++)
            {
                if(prestamos[j].idCliente==masActivos[i].idCliente && masActivos[i].isEmpty==1 && prestamos[j].isEmpty==1 && prestamos[j].estado==ACTIVO)
                {
                    masActivos[i].cantidadActivos++;
                }
            }
        }
        ok=1;
    }


    return ok;
}

int masSaldados_cargarCantidadSaldados(ePrestamo prestamos[], int tamPrestamos, eCliente clientes[], int tamClientes, eMasSaldados masSaldados[])
{
    int ok=0;
    int i=0, j=0;
    if(prestamos!=NULL && tamPrestamos>0 && clientes!=NULL && tamClientes>0)
    {
        for(i=0; i<tamClientes; i++)
        {
            masSaldados[i].idCliente= clientes[i].id;
            masSaldados[i].isEmpty= clientes[i].isEmpty;
            masSaldados[i].cantidadSaldados=0;
            for(j=0; j<tamPrestamos; j++)
            {
                if(prestamos[j].idCliente==masSaldados[i].idCliente && masSaldados[i].isEmpty==1 && prestamos[j].isEmpty==1 && prestamos[j].estado==SALDADO)
                {
                    masSaldados[i].cantidadSaldados++;
                }
            }
        }
        ok=1;
    }


    return ok;
}

int informe_clienteConMasActivos(eMasActivos masActivos[], eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos)
{
    int ok=0;
    int auxMayor=0;
    int i=0;
    int auxIndex;
    char nombreAux[20];
    char apellidoAux[20];
    if(masActivos!=NULL && clientes!=NULL && tamClientes>0)
    {
        printf("Los clientes con mas prestamos activos son: \n\n");
        if(auxMayor<masActivos[i].cantidadActivos)
        {
            auxMayor=masActivos[i].cantidadActivos;
        }
    }
    for(i=0; i<tamClientes; i++)
    {
        if(auxMayor==masActivos[i].cantidadActivos)
        {
            auxIndex=cliente_buscar(clientes, tamClientes, masActivos[i].idCliente);
            cliente_cargarNombre(clientes, tamClientes, clientes[auxIndex].id, nombreAux);
            cliente_cargarApellido(clientes, tamClientes, clientes[auxIndex].id, apellidoAux);
            cliente_mostrarUno(clientes[auxIndex], prestamos, tamPrestamos);
        }
    }
    return ok;
}

int informe_clienteConMasSaldados(eMasSaldados masSaldados[], eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos)
{
    int ok=0;
    int auxMayor=0;
    int i=0;
    int auxIndex;

    if(masSaldados!=NULL && clientes!=NULL && tamClientes>0)
    {
        printf("Los clientes con mas prestamos activos son: \n\n");
        if(auxMayor<masSaldados[i].cantidadSaldados)
        {
            auxMayor=masSaldados[i].cantidadSaldados;
        }
    }
    for(i=0; i<tamClientes; i++)
    {
        if(auxMayor==masSaldados[i].cantidadSaldados)
        {
            auxIndex=cliente_buscar(clientes, tamClientes, masSaldados[i].idCliente);
            cliente_mostrarUno(clientes[auxIndex], prestamos, tamPrestamos);
        }
    }
    return ok;
}

int informe_clienteConMasPrestamos(eMasPrestamos masPrestamos[], eCliente clientes[], int tamClientes, ePrestamo prestamos[], int tamPrestamos)
{
    int ok=0;
    int auxMayor=0;
    int i=0;
    int auxIndex;

    if(masPrestamos!=NULL && clientes!=NULL && tamClientes>0)
    {
        printf("Los clientes con mas prestamos activos son: \n\n");
        if(auxMayor<masPrestamos[i].cantidadDePrestamos)
        {
            auxMayor=masPrestamos[i].cantidadDePrestamos;
        }
    }
    for(i=0; i<tamClientes; i++)
    {
        if(auxMayor==masPrestamos[i].cantidadDePrestamos)
        {
            auxIndex=cliente_buscar(clientes, tamClientes, masPrestamos[i].idCliente);
            cliente_mostrarUno(clientes[auxIndex], prestamos, tamPrestamos);
        }
    }
    return ok;
}
