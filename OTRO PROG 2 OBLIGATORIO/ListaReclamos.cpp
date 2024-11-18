#include "ListaReclamos.h"
#include "stdio.h"
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
