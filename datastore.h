#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED

#include "lib.h"

eCliente hClientes[5]= {    {1000, "Federico", "Nealon", 37989151, 1},
                            {1001, "Joaquin", "Blanco", 3679125, 1},
                            {1002, "Florencia", "Vazquez", 39468234, 1},
                            {1003, "Nicolas", "Diaz", 38124765, 1},
                            /*{1004, "Agustin", "Lopez", 34258616, 1}*/ };

ePrestamo hPrestamos[5]= {  {2000, 1000, 1000000, 48, 0, 1},
                            {2001, 1000, 2000000, 48, 1, 1},
                            {2002, 1002, 3000000, 72, 1, 1},
                            {2003, 1002, 3000000, 48, 0, 1},
                            {2004, 1004, 2000000, 12, 1, 1} };




#endif // DATASTORE_H_INCLUDED
