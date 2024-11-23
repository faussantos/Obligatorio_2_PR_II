#ifndef RECLAMO_H_INCLUDED
#define RECLAMO_H_INCLUDED

#include "string_dinamico.h"
#include "fecha.h"
typedef struct
{
    int n_reclamo;
    fecha realizacion;
    strings motivo;
    long int ci_cliente;
    boolean solucionado;
} reclamo;

//FUNCIONES BASICAS
void cargaReclamo (reclamo &r, int x);

void printReclamo(reclamo r);

int darNumReclamo (reclamo r);

fecha darFecha(reclamo r);

void darMotivo (reclamo r, strings &s);

long int darCedula_reclamo (reclamo r);

boolean darSolucionado (reclamo r);

boolean validarReclamo (reclamo r, reclamo a);

//PRECONDICIÓN: El archivo viene abierto para lectura
void levantar_reclamo (reclamo &r, FILE * f);

//PRECONDICIÓN: El archivo viene abierto para escritura
void bajar_reclamo (reclamo r, FILE * f);

//FUNCIONES ADICIONALES

#endif // RECLAMO_H_INCLUDED
