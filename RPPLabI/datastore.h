#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED

#include "lib.h"

eCliente hClientes[5]= {    {1000, "Federico", "Nealon", 37989151, 1},
                            {1001, "Joaquin", "Blanco", 3679125, 1},
                            {1002, "Florencia", "Vazquez", 39468234, 1},
                            {1003, "Nicolas", "Diaz", 38124765, 1},
                            {1004, "Agustin", "Lopez", 34258616, 1} };

eEquipo  hEquipos[3]= { {1, "Amoladora"},
                        {2, "Mezcladora"},
                        {3, "Taladro"} };

eAlquiler hAlquileres[5]= { {2000, 1000, 1, 40, 0, 3000, 4, 1},
                            {2001, 1000, 2, 50, 35, 3001, 5, 1},
                            {2002, 1002, 3, 35, 17, 3002, 5, 1},
                            {2003, 1002, 3, 36, 0, 3002, 4, 1},
                            {2004, 1004, 2, 50, 45, 3001, 5, 1} };

eOperador hOperadores[3]= { {3000, "Juan", "Perez"},
                            {3001, "Christian", "Baus"},
                            {3002, "Yanina", "Scudero"} };




#endif // DATASTORE_H_INCLUDED
