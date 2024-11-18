#ifndef ARBOLCLIENTE_H_INCLUDED
#define ARBOLCLIENTE_H_INCLUDED
#include "cliente.h"
typedef struct nodoA {

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


#endif // ARBOLCLIENTE_H_INCLUDED
