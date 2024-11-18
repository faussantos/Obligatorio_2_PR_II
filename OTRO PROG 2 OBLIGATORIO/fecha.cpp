#include "fecha.h"
#include <stdio.h>
void cargaFecha (fecha &f)
{
    printf("Ingrese dia: ");
    scanf("%d",&f.dia);
    printf("Ingrese mes: ");
    scanf("%d",&f.mes);
    printf("Ingrese anio: ");
    scanf("%d",&f.anio);
}

void printFecha (fecha f)
{
    printf("%d/%d/%d",f.dia,f.mes,f.anio);
}

int darDia (fecha f)
{
    return f.dia;
}

int darMes (fecha f)
{
    return f.mes;
}

int darAnio (fecha f)
{
    return f.anio;
}

boolean validarFecha (fecha f)
{
    boolean valido=TRUE;
    switch(f.mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: if(f.dia<1||f.dia>31)
                    valido = FALSE;
                 break;
        case 4:
        case 6:
        case 9:
        case 11: if(f.dia<1||f.dia>30)
                    valido = FALSE;
                 break;
        case 2: if(f.anio%4==0)
                {
                    if(f.dia<1||f.dia>29)
                        valido = FALSE;
                }
                else
                {
                    if(f.dia<1||f.dia>28)
                        valido = FALSE;
                }
        default: valido = FALSE;
    }
    return valido;
}



