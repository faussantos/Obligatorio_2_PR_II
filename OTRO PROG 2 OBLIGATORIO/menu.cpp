#include <iostream>
#include "menu.h"

void mostrarMenuPrincipal (int &opcion)
{
    printf(":: MENU PRINCIPAL ::\n");
    printf("\n1 - Altas / Bajas");
    printf("\n2 - Listados");
    printf("\n3 - Consultas");
    printf("\n\n0 - Salir");

    printf("\n\nSELECCIONE UNA OPCION: ");
    scanf("%d", &opcion);
}

void mostrarMenuAltasBajas (int &opcion)
{
    printf(":: ALTAS Y BAJAS ::\n");
    printf("\n1 - Agregar Cliente");
    printf("\n2 - Eliminar Cliente");
    printf("\n3 - Agregar Reclamo");
    printf("\n\n0 - Volver");

    printf("\n\nSELECCIONE UNA OPCION: ");
    scanf("%d", &opcion);
}

void mostrarMenuListados (int &opcion)
{
    printf(":: LISTADOS ::\n");
    printf("\n1 - Clientes");
    printf("\n2 - Reclamos por cliente");
    printf("\n3 - Reclamos por fecha");
    printf("\n4 - Cliente por reclamo");
    printf("\n\n0 - Volver");

    printf("\n\nSELECCIONE UNA OPCION: ");
    scanf("%d", &opcion);
}

void mostrarMenuConsultas (int &opcion)
{
    printf(":: CONSULTAS ::");
    printf("\n1 - Clientes con apellido repetido");
    printf("\n2 - Clientes sin reclamos");
    printf("\n3 - Reclamos solucionados / sin solucionar");
    printf("\n4 - Reclamos por rango de fechas");
    printf("\n5 - Cliente con mas reclamos");
    printf("\n\n0 - Volver");

    printf("\n\nSELECCIONE UNA OPCION: ");
    scanf("%d", &opcion);
}


