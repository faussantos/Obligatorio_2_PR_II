#ifndef LISTARECLAMOS_H_INCLUDED
#define LISTARECLAMOS_H_INCLUDED

#include "reclamo.h"
typedef struct Nodol
{
    reclamo info;
    Nodol* sig ;
} Nodo;
typedef Nodo * ListaR;

void Crear (ListaR &L);
boolean Vacia (ListaR L);
reclamo Primero (ListaR L);
void Resto (ListaR & L);
void InsFront (ListaR & L, reclamo r);

#endif // LISTARECLAMOS_H_INCLUDED
