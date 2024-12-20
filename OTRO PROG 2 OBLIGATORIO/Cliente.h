#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "string_dinamico.h"
#include <stdio.h>

typedef struct
{
    long int ci;
    strings nombre;
    strings apellido;
    strings direccion;
    long int telefono;
    int cant_reclamos;
} cliente;

//FUNCIONES BASICAS
void cargaCliente(cliente &c);

void printCliente(cliente c);

long int darCedula_cliente(cliente c);

void darNombre (cliente c, strings &s);

void darApellido (cliente c, strings &s);

void darDireccion (cliente c, strings &s);

long int darTelefono(cliente c);

int darCantidadReclamos(cliente c);

void sumarUnReclamo (cliente &c);

void bajar_cliente (cliente c, FILE * f);

void levantar_cliente (cliente &c, FILE * f);

//FUNCIONES ADICIONALES


#endif // CLIENTE_H_INCLUDED
