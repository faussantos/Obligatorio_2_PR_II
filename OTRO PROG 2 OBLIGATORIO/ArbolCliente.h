#ifndef ARBOLCLIENTE_H_INCLUDED
#define ARBOLCLIENTE_H_INCLUDED
#include "cliente.h"
#include <stdio.h>
typedef struct nodoA
{
    cliente info;
    nodoA * hIzq;
    nodoA * hDer;
} NodoArbol;

typedef NodoArbol * ArbolCliente;

void crear (ArbolCliente &a);

boolean esVacio (ArbolCliente a);

cliente darRaiz (ArbolCliente a);

ArbolCliente hijoIzquierdo (ArbolCliente a);

ArbolCliente hijoDerecho (ArbolCliente a);

void borrarClienteminimo (ArbolCliente &a);

void Cons (ArbolCliente i, ArbolCliente d, cliente raiz, ArbolCliente &a);

void insertarCliente (ArbolCliente &a, cliente c);// c no pertence al arbol

int ContarClientes (ArbolCliente a);

int ContarCLientesNorec (ArbolCliente a);

//PRECONDICIÓN: EL ARBOL NO PUEDE ESTAR VACIO
void CedulaMasRec(ArbolCliente a, int &cantReclamos, long int &ci);

boolean ExisteCliente (ArbolCliente a, long int ci);

void listar_cliente_ci(ArbolCliente a, long int ci);

int cant_clientes_apellido (strings apellido, ArbolCliente a);

void listar_clientes_ordenados (ArbolCliente a);

void Borrar (long int ci, ArbolCliente &a);

cliente clienteMinimo (ArbolCliente a);

ArbolCliente devolverClienteCI (ArbolCliente a, long int ci);

void bajar_abb_aux (ArbolCliente a, FILE * f);

void bajar_abb (ArbolCliente a);

void levantar_abb (ArbolCliente &a);

boolean existeArchivoArbol ();

#endif // ARBOLCLIENTE_H_INCLUDED
