#include "ArbolCliente.h"

void crear (ArbolCliente &a)
{
    a = NULL;
}

//PRECONDICION: El arbol debe haberse inicializado anteriormente
//Saber si un árbol está vacío
boolean esVacio (ArbolCliente a)
{
    boolean es = TRUE;
    if (a != NULL)
        es = FALSE;

    return es;
}


//PRECONDICION: el árbol no es nulo
//Obtener la raíz del árbol
cliente darRaiz (ArbolCliente a)
{
    return a->info;
}

//PRECONDICION: el árbol no es nulo
//Devolver un subárbol izquierdo
ArbolCliente hijoIzquierdo (ArbolCliente a)
{
    return a->hIzq;
}

//PRECONDICION: el árbol no es nulo
//Devolver un subárbol derecho
ArbolCliente hijoDerecho (ArbolCliente a)
{
    return a->hDer;
}


//PRECONDICION: El arbol debe haberse inicializado anteriormente
//PRECONDICION: El nro de cedula de c no debe pertenecer al arbol
void insertarCliente (ArbolCliente &a, cliente c)
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

//PRECONDICION: El arbol debe haberse inicializado anteriormente
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

//PRECONDICION: El arbol debe haberse inicializado anteriormente
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

//PRECONDICIÓN: El arbol no puede estar vacío
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

//PRECONDICION: El arbol debe haberse inicializado anteriormente
boolean ExisteCliente (ArbolCliente a, long int ci)
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

//PRECONDICION: El arbol debe haberse inicializado anteriormente
int cant_clientes_apellido (strings apellido, ArbolCliente a)
{
    strings s;
    if(a==NULL)
        return 0;
    else
    {
        darApellido(a->info,s);

        if(streq(apellido,s) == TRUE)
            return 1 + cant_clientes_apellido(apellido,a->hIzq) + cant_clientes_apellido(apellido,a->hDer);
        else
            return cant_clientes_apellido(apellido,a->hIzq) + cant_clientes_apellido(apellido,a->hDer);
    }
}

//PRECONDICION: El arbol debe haberse inicializado anteriormente
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

//PRECONDICION: El arbol debe haberse inicializado anteriormente
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

//PRECONDICION: El arbol debe haberse inicializado anteriormente
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

//Dados dos árboles, construir otro árbol con una nueva raíz y que los tenga como hijos izq. y der.
void Cons (ArbolCliente i, ArbolCliente d, cliente raiz, ArbolCliente &a)
{
    a = new NodoArbol;
    a->info = raiz;
    a->hIzq = i;
    a->hDer = d;
}

// ------------ FILE

//PRECONDICIÓN: El archivo viene abierto
void bajar_abb_aux (ArbolCliente a, FILE * f)
{
    if(a!=NULL)
    {
        bajar_cliente(a->info,f);
        bajar_abb_aux(a->hIzq,f);
        bajar_abb_aux(a->hDer,f);
    }

}

void bajar_abb (ArbolCliente a)
{
    FILE * f;
    f=fopen("Clientes.dat","wb");
    bajar_abb_aux(a,f);
    fclose(f);
}

//PRECONDICIÓN: El archivo existe
void levantar_abb (ArbolCliente &a)
{
    cliente c;
    FILE * f;
    f=fopen("Clientes.dat","rb");
    levantar_cliente(c,f);
    while(!feof(f))
    {
        insertarCliente(a,c);
        levantar_cliente(c,f);
    }
    fclose(f);
}

boolean existeArchivoArbol ()
{
    boolean existe=FALSE;
    FILE * a;
    a = fopen("Clientes.dat", "rb");
    if(a!=NULL)
        existe= TRUE;
    fclose(a);
    return existe;
}

// ------------ FILE
