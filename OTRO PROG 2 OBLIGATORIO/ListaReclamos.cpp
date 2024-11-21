#include "ListaReclamos.h"

void Crear (ListaR &L)
{
    L = NULL;
}
boolean Vacia (ListaR L)
{
    boolean es = FALSE;
    if (L == NULL)
        es = TRUE;
    return es;
}
/* Precondici�n: lista NO vac�a */
reclamo Primero (ListaR L)
{
    return L -> info;
}
/* Precondici�n: lista NO vac�a */
void Resto (ListaR & L)
{
    ListaR aux = L;
    L = L -> sig;
    delete aux;
}
void InsFront (ListaR & L, reclamo r)
{
    ListaR aux = new Nodo;
    aux -> info = r;
    aux -> sig = L;
    L = aux;
}

int LargoReclamos (ListaR L)
//indica el largo de la cantidad de reclamos para poder restarle a la cantidad total
//de clientes de esa manerra la diferencia sera la cantidad de cleintes q no reclamaron
{
    if (L == NULL)
        return 0;
    else
        return 1 + LargoReclamos (L -> sig);
}

void ListarReclamosCliente (ListaR L, long int ci)// usarlo con un while existe cliente dentro del main
{
    while (L!=NULL)
    {
        if(ci==darCedula_reclamo(L->info))
           {
               printReclamo(L->info);
               L=L->sig;
           }
        else
            L=L->sig;
    }
}
void InsBack (ListaR &L, reclamo r)
{
    ListaR aux = L;

    while(aux -> sig != NULL)
    {
        aux = aux -> sig;
    }

    aux -> sig = new Nodo;

    aux -> sig -> sig = NULL;
    aux -> sig -> info = r;
}

//PRECONDICION: Ambas fechas son validas, la primera es menor o igual a la segunda y la lista no esta vacia
int cant_reclamos_2fechas(ListaR l, fecha f1, fecha f2)
{
    int cant = 0;
    while(fechaMenor(darFecha(l->info),f1)==TRUE && l!=NULL)
    {
        l=l->sig;
    }
    while(fechaMenor(darFecha(l->info),f2) && l!=NULL)
    {
        cant++;
        l=l->sig;
    }
    return cant;
}

//Devuelve la cedula de un cliente del primer reclamo
//PRECONDICION: RECLAMO NO PUEDE ESTAR VACIO
long int ci_numeroreclamo(ListaR l)
{
    return darCedula_reclamo(l->info);
}

//DEVUELVE UN PUNTERO CON LA DIRECCION DE MEMORIA DEL RECLAMO EN CASO DE ENCONTRAR EL NUMERO DE RECLAMO. SINO DEVUELVE PUNTERO NULL
ListaR puntero_numReclamo (ListaR l, int num)
{
    while(l!=NULL && num!=darNumReclamo(l->info))
    {
        l=l->sig;
    }
    return l;
}

void CantidadResueltosSinResolver(ListaR L, int &resueltos, int &sinResolver)
{
    resueltos = 0;
    sinResolver = 0;

    while (L!=NULL)
    {
        if(darSolucionado(L->info) == TRUE)
            resueltos++;
        else
            sinResolver++;

        L=L->sig;
    }
}