#include "ArbolCliente.h"
#include <stdio.h>
void crear (ArbolCliente &a)
{
    a = NULL;
}
// Saber si un árbol está vacío
boolean esVacio (ArbolCliente a)
{
    boolean es = TRUE;
    if (a != NULL)
        es = FALSE;
    return es;
}
// Obtener la raíz del árbol
//Precondición: el árbol no es nulo
cliente darRaiz (ArbolCliente a)
{
    return a->info;
}
// Devolver un subárbol izquierdo
ArbolCliente hijoIzquierdo (ArbolCliente a)
{
    return a->hIzq;
}
// Devolver un subárbol derecho
ArbolCliente hijoDerecho (ArbolCliente a)
{
    return a->hDer;
}
// Dados dos árboles, construir otro árbol con una nueva raíz y que los tenga como hijos izq. y der.
void Cons (ArbolCliente i, ArbolCliente d, cliente raiz, ArbolCliente &a)
{
    a = new Nodo;
    a->info = raiz;
    a->hIzq = i;
    a->hDer = d;
}

void insertarCliente (ArbolCliente &a, cliente c)// c no pertence al arbol
{
    if (a==NULL)
    {
        a=new Nodo;
        a->info=c;
        a->hIzq=NULL;
        a->hDer=NULL;
    }
    else
    {
        if(darCedula_cliente(a->info)>darCedula_cliente(c))
        {
            insertarCliente(a->hIzq,c);
        }
        else
            insertarCliente(a->hDer,c);
    }
}
void borrarClienteminimo (ArbolCliente &a)
{
    ArbolCliente aux;


    if (a->hIzq==NULL)
    {
        aux=a->hDer;
        delete a;
        a=aux;
    }
    else
        borrarClienteminimo(a->hIzq);
}
