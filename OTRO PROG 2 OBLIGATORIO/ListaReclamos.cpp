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
