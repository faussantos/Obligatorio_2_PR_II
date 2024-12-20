#ifndef LISTARECLAMOS_H_INCLUDED
#define LISTARECLAMOS_H_INCLUDED
#include <stdio.h>
#include "reclamo.h"
typedef struct Nodol
{
    reclamo info;
    Nodol* sig ;
} NodoLista;
typedef NodoLista * ListaR;

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

void ListarReclamosFecha (ListaR L, fecha f);

void CantidadResueltosSinResolver(ListaR L, int &resueltos, int &sinResolver);

void ListarReclamosCliente (ListaR L, long int ci);

long int ObtenerCedulaClienteReclamo (ListaR L, int numeroReclamo);

boolean ExisteReclamo (ListaR L, int numeroReclamo);

fecha ObtenerFechaUltimoReclamo (ListaR L);

void Bajar_Lista (ListaR l);

void Levantar_Lista (ListaR &l);

boolean existeArchivoLista ();

void BorrarReclamoCliente (ListaR &L, long int ci);

#endif // LISTARECLAMOS_H_INCLUDED
