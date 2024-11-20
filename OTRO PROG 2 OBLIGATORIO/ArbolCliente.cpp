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

int ContarClientes (ArbolCliente a)
{
    if (a == NULL)
        return 0;
    else
        return 1 + ContarClientes (a -> hIzq) + ContarClientes (a -> hDer);
}
int ContarCLientesNorec (ArbolCliente a)
{
    if (a!=NULL)
    {
        if (darCantidadReclamos(a->info)==0)
            return 1+ContarCLientesNorec(a->hDer)+ContarCLientesNorec(a->hIzq);
        else
            return ContarCLientesNorec(a->hDer)+ContarCLientesNorec(a->hIzq);
    }
    return 0;
}

void CedulaMasRec(ArbolCliente a, int &cantReclamos, long int &ci)
{
    if (a != NULL)
    {
        int reclamosActual = darCantidadReclamos(a->info);
        long int cedulaActual = darCedula_cliente(a->info);
        cantReclamos = reclamosActual;
        ci = cedulaActual;

        if (a->hIzq != NULL)
        {
            int cantReclamosIzq;
            long int ciIzq;
            CedulaMasRec(a->hIzq, cantReclamosIzq, ciIzq);
            if (cantReclamosIzq > cantReclamos)
            {
                cantReclamos = cantReclamosIzq;
                ci = ciIzq;
            }
        }
        if (a->hDer != NULL)
        {
            int cantReclamosDer;
            long int ciDer;
            CedulaMasRec(a->hDer, cantReclamosDer, ciDer);
            if (cantReclamosDer > cantReclamos)
            {
                cantReclamos = cantReclamosDer;
                ci = ciDer;
            }
        }
    }
}
