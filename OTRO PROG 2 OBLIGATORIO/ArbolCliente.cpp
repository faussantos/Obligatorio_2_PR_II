#include "ArbolCliente.h"

void crear (ArbolCliente &a)
{
    a = NULL;
}
//Saber si un árbol está vacío
boolean esVacio (ArbolCliente a)
{
    boolean es = TRUE;
    if (a != NULL)
        es = FALSE;
    return es;
}
//Obtener la raíz del árbol
//Precondición: el árbol no es nulo
cliente darRaiz (ArbolCliente a)
{
    return a->info;
}
//Devolver un subárbol izquierdo
ArbolCliente hijoIzquierdo (ArbolCliente a)
{
    return a->hIzq;
}
//Devolver un subárbol derecho
ArbolCliente hijoDerecho (ArbolCliente a)
{
    return a->hDer;
}
//Dados dos árboles, construir otro árbol con una nueva raíz y que los tenga como hijos izq. y der.
void Cons (ArbolCliente i, ArbolCliente d, cliente raiz, ArbolCliente &a)
{
    a = new NodoArbol;
    a->info = raiz;
    a->hIzq = i;
    a->hDer = d;
}

void insertarCliente (ArbolCliente &a, cliente c)// c no pertence al arbol
{
    if (a==NULL)
    {
        a=new NodoArbol;
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
            return 1+ContarCLientesNorec(a->hIzq)+ContarCLientesNorec(a->hDer);
        else
            return ContarCLientesNorec(a->hIzq)+ContarCLientesNorec(a->hDer);
    }
    else
        return 0;
}

//PRECONDICIÓN: EL ARBOL NO PUEDE ESTAR VACIO
void CedulaMasRec(ArbolCliente a, int &cantReclamos, long int &ci)
{
    if (a == NULL)
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

boolean ExisteCliente (ArbolCliente a, long int ci)// tiene q estar registrado ese numero de cedula
{
    boolean encontre = FALSE;
    while(a!=NULL && !encontre)
    {
        if (ci==darCedula_cliente(a->info))
            encontre = TRUE;
        else
        {
            if (ci<darCedula_cliente(a->info))
                a=a->hIzq;
            else
                a=a->hDer;
        }
    }
    return encontre;
}

int cant_clientes_apellido (strings apellido, ArbolCliente a)
{
    strings s;
    if(a==NULL)
        return 0;
    else
    {
        darNombre(a->info,s);

        if(streq(apellido,s) == TRUE)
            return 1 + cant_clientes_apellido(apellido,a->hIzq) + cant_clientes_apellido(apellido,a->hDer);
        else
            return cant_clientes_apellido(apellido,a->hIzq) + cant_clientes_apellido(apellido,a->hDer);
    }
}


void listar_cliente_ci(ArbolCliente a, long int ci)
{
    while(darCedula_cliente(a->info)!=ci && a!=NULL)
    {
        if(darCedula_cliente(a->info)>ci)
            a=a->hIzq;
        else
            a=a->hDer;
    }

    if(a!=NULL)
        printCliente(a->info);
    else
        printf("ERROR: Cliente no encontrado");
}

void listar_clientes_ordenados (ArbolCliente a)
{
    if(a != NULL)
    {
        listar_clientes_ordenados(a ->hIzq);
        printCliente(a->info);
        listar_clientes_ordenados(a ->hDer);
    }
}

//PRECONDICION: Arbol no está vacio
cliente clienteMinimo (ArbolCliente a)
{
    while(a->hIzq!=NULL)
    {
        a=a->hIzq;
    }
    return a->info;
}

/* Precondición : la ci existe en el árbol a */
void Borrar (long int ci, ArbolCliente &a)
{
    ArbolCliente aux;
    if (ci == darCedula_cliente(a->info))
    {
        if (a->hDer == NULL)
        {
            aux = a -> hIzq;
            delete a;
            a = aux;
        }
        else
        {
            if (a -> hIzq == NULL)
            {
                aux = a -> hDer;
                delete a;
                a = aux;
            }
            else
            {
                a -> info =  clienteMinimo(a -> hDer);
                borrarClienteminimo (a -> hDer);
            }
        }
    }
    else
    {
        if (ci < darCedula_cliente(a -> info))
            Borrar (ci, a -> hIzq);
        else
            Borrar (ci, a -> hDer);
    }
}

ArbolCliente devolverClienteCI(ArbolCliente a, long int ci)
{
    while(a!=NULL && darCedula_cliente(a->info)!=ci)
    {
        if(ci<darCedula_cliente(a->info))
            a=a->hIzq;
        else
            a=a->hDer;
    }
    return a;
}
