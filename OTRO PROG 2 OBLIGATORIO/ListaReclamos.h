#ifndef LISTARECLAMOS_H_INCLUDED
#define LISTARECLAMOS_H_INCLUDED
#include <stdio.h>
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
int LargoReclamos (ListaR L);
void InsBack (ListaR &L, reclamo r);
//PRECONDICION: Ambas fechas son validas, la primera es menor o igual a la segunda y la lista no esta vacia
int cant_reclamos_2fechas(ListaR l, fecha f1, fecha f2);
//Devuelve la cedula de un cliente del primer reclamo
//PRECONDICION: RECLAMO NO PUEDE ESTAR VACIO
long int ci_numeroreclamo(ListaR l);
//DEVUELVE UN PUNTERO CON LA DIRECCION DE MEMORIA DEL RECLAMO EN CASO DE ENCONTRAR EL NUMERO DE RECLAMO. SINO DEVUELVE PUNTERO NULL
ListaR puntero_numReclamo (ListaR l, int num);

void CantidadResueltosSinResolver(ListaR L, int &resueltos, int &sinResolver);

#endif // LISTARECLAMOS_H_INCLUDED
