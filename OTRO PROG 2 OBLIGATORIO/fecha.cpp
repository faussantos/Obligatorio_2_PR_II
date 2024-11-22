#include "fecha.h"
#include <stdio.h>
void cargaFecha (fecha &f)
{
    printf("\nDia: ");
    scanf("%d",&f.dia);
    printf("Mes: ");
    scanf("%d",&f.mes);
    printf("Anio: ");
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
    case 12:
        if(f.dia<1||f.dia>31)
            valido = FALSE;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(f.dia<1||f.dia>30)
            valido = FALSE;
        break;
    case 2:
        if(f.anio%4==0)
        {
            if(f.dia<1||f.dia>29)
                valido = FALSE;
        }
        else
        {
            if(f.dia<1||f.dia>28)
                valido = FALSE;
        }
        break;
    default:
        valido = FALSE;
    }
    return valido;
}

boolean compararFecha (fecha f1, fecha f2)
{
    boolean iguales=FALSE;

    if(f1.dia==f2.dia && f1.mes==f2.mes && f1.anio==f2.anio)
        iguales = TRUE;

    return iguales;
}

//COMPARAR SI LA FECHA 1 ES MENOR QUE LA FECHA 2
boolean fechaMenor (fecha f1, fecha f2)
{
    boolean menor = FALSE;

    if(f1.anio < f2.anio)
        menor = TRUE;
    else
    {
        if (f1.anio==f2.anio && f1.mes < f2.mes)
            menor = TRUE;
        else
        {
            if(f1.anio==f2.anio && f1.mes==f2.mes && f1.dia < f2.dia)
                menor = TRUE;
        }
    }
    return menor;
}


