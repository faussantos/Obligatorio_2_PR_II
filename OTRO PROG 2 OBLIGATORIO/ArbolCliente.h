#ifndef ARBOLCLIENTE_H_INCLUDED
#define ARBOLCLIENTE_H_INCLUDED
#include "cliente.h"
#include <stdio.h>
typedef struct nodoA
{

    cliente info;
    nodoA * hIzq;
    nodoA * hDer;
} Nodo;

typedef Nodo * ArbolCliente;
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
void CedulaMasRec(ArbolCliente a, int &cantReclamos, long int &ci);
boolean ExisteCliente (ArbolCliente a, long int ci);
void listar_cliente_ci(ArbolCliente a, long int ci);
int cant_clientes_apellido (strings apellido, ArbolCliente a);

#endif // ARBOLCLIENTE_H_INCLUDED
