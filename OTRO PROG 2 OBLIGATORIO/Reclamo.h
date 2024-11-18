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
void cargaReclamo (reclamo &r);

void printReclamo(reclamo r);

int darNumReclamo (reclamo r);

fecha darFecha(reclamo r);

void darMotivo (reclamo r, strings &s);

long int darCedula_reclamo (reclamo r);

boolean darSolucionado (reclamo r);

//FUNCIONES ADICIONALES

#endif // RECLAMO_H_INCLUDED
