#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "boolean.h"

typedef struct{
    int dia;
    int mes;
    int anio;
} fecha;

void cargaFecha (fecha &f);

void printFecha (fecha f);

int darDia (fecha f);

int darMes (fecha f);

int darAnio (fecha f);

boolean validarFecha (fecha f);

#endif // FECHA_H_INCLUDED
