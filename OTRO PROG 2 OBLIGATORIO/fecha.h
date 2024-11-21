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

boolean compararFecha (fecha f1, fecha f2);

boolean fechaMenor (fecha f1, fecha f2);

#endif // FECHA_H_INCLUDED
