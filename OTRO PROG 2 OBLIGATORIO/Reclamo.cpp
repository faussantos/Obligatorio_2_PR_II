#include "reclamo.h"
#include <stdio.h>
void cargaReclamo (reclamo &r)//verificar q el cliente exista y ordenarlos cronolocgicamente tiene q ser despues del ultimo reclamo registeado
{
    printf("Ingrese fecha de realizacion: ");
    cargaFecha(r.realizacion);
    while (!validarFecha(r.realizacion))
    {
        printf("\n---FECHA INVALIDA INGRESE DEVUELTA----\n");
        printf("Ingrese fecha de realizacion: ");
        cargaFecha(r.realizacion);
    }
    printf("Ingrese motivo: ");
    scan(r.motivo);
    printf("Ingrese cedula del cliente:");
    scanf("%ld",&r.ci_cliente);
    printf("El problema fue solucionado?");
    cargaBool(r.solucionado);
}

void printReclamo(reclamo r)
{
    printf("NUMERO DE RECLAMO: %d",r.n_reclamo);
    printf("\nFECHA DE REALIZACION : ");
    printFecha(r.realizacion);
    printf("\nMOTIVO: ");
    print(r.motivo);
    printf("\nCEDULA: %ld",r.ci_cliente);
    if (r.solucionado==FALSE)
        printf("\nPROBLEMA SOLUCIONADO: NO");
    else
        printf("\nPROBLEMA SOLUCIONADO: SI");
}

int darNumReclamo (reclamo r)
{
    return r.n_reclamo;
}

fecha darFecha(reclamo r)
{

}

void darMotivo (reclamo r, strings &s)
{
    strcop(s,r.motivo);
}

long int darCedula_reclamo (reclamo r)
{
    return r.ci_cliente;
}

boolean darSolucionado (reclamo r)
{
    return r.solucionado;
}
