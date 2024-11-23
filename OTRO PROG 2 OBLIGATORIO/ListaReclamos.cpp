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
    ListaR aux = new NodoLista;
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
            printf("\n");
        }

        L=L->sig;
    }
}

void ListarReclamosFecha (ListaR L, fecha f)
{
    while (L!=NULL)
    {
        if(compararFecha(darFecha(L->info), f) == TRUE)
        {
            printReclamo(L->info);
        }

        L=L->sig;
    }
}

long int ObtenerCedulaClienteReclamo (ListaR L, int numeroReclamo)
{
    long int ci;
    boolean encontre = FALSE;

    while (L!=NULL && encontre == FALSE)
    {
        if(darNumReclamo(L->info) == numeroReclamo)
        {
            ci = darCedula_reclamo(L->info);
            encontre = TRUE;
        }

        L=L->sig;
    }

    return ci;
}

boolean ExisteReclamo (ListaR L, int numeroReclamo)
{
    boolean encontre = FALSE;

    while (L!=NULL && encontre == FALSE)
    {
        if(darNumReclamo(L->info) == numeroReclamo)
        {
            encontre = TRUE;
        }

        L=L->sig;
    }

    return encontre;
}

void InsBack (ListaR &L, reclamo r)
{
    if(L!=NULL)
    {
        ListaR aux = L;
        while(aux -> sig != NULL)
        {
            aux = aux -> sig;
        }
        aux -> sig = new NodoLista;
        aux -> sig -> sig = NULL;
        aux -> sig -> info = r;
    }
    else
    {
        L = new NodoLista;
        L -> sig = NULL;
        L -> info = r;
    }
}

//PRECONDICION: La lista de reclamos no puede estar vacia
fecha ObtenerFechaUltimoReclamo (ListaR L)
{
    ListaR aux = L;

    while(aux -> sig != NULL)
    {
        aux = aux -> sig;
    }

    return darFecha(aux ->info);
}

//PRECONDICION: Ambas fechas son validas, la primera es menor o igual a la segunda y la lista no esta vacia
int cant_reclamos_2fechas(ListaR l, fecha f1, fecha f2)
{
    int cant = 0;
    boolean seguir=TRUE;
    while(l!=NULL && seguir)
    {
        if(fechaMenor(f1,darFecha(l->info)) == TRUE || compararFecha(f1,darFecha(l->info)) == TRUE)
            seguir = FALSE;
        else
            l=l->sig;
    }
    seguir = TRUE;
    while(l!=NULL && seguir)
    {
        if(fechaMenor(darFecha(l->info),f2) == FALSE&&compararFecha(darFecha(l->info),f2)==FALSE)
            seguir = FALSE;
        else
        {
            cant++;
            l=l->sig;
        }
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

void Bajar_Lista (ListaR l)
{
    FILE * f;
    f = fopen("Reclamos.dat","wb");
    while(l!=NULL)
    {
        bajar_reclamo(l->info,f);
        l=l->sig;
    }
    fclose(f);
}

void Levantar_Lista (ListaR &l)
{
    FILE * f;
    f = fopen("Reclamos.dat","rb");
    reclamo r;
    levantar_reclamo(r,f);
    while(!feof(f))
    {
        InsBack(l,r);
        levantar_reclamo(r,f);
    }
    fclose(f);
}

boolean existeArchivoLista ()
{
    boolean existe=FALSE;
    FILE * a;
    a = fopen("Reclamos.dat", "rb");
    if(a!=NULL)
        existe= TRUE;
    fclose(a);
    return existe;
}
