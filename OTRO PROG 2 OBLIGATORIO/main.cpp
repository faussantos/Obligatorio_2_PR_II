#include <iostream>

#include "menu.h"
#include "ListaReclamos.h"

using namespace std;

void procesarAltasBajas(ListaR listaReclamos)
{
    int opcionAltasBajas;

    do
    {
        system("cls");
        mostrarMenuAltasBajas(opcionAltasBajas);

        switch(opcionAltasBajas)
        {
        case 1:
            //Agregar Cliente
            break;
        case 2:
            //Eliminar Cliente
            break;
        case 3:
            //Agregar Reclamo
            break;
        case 0:
            //Volver al menu principal
            break;
        default:
            system("cls");
            printf("OPCION INCORRECTA \n");
            system("pause");
            break;
        }
    }
    while (opcionAltasBajas != 0);
}

void procesarListados(ListaR listaReclamos)
{
    int opcionListados;

    do
    {
        system("cls");
        mostrarMenuListados(opcionListados);

        switch(opcionListados)
        {
        case 1:
            //Clientes
            break;
        case 2:
            //Reclamos por cliente
            break;
        case 3:
            //Reclamos por fecha
            break;
        case 4:
            //Cliente por reclamo
            break;
        case 0:
            //Volver
            break;
        default:
            system("cls");
            printf("OPCION INCORRECTA \n");
            system("pause");
            break;
        }
    }
    while (opcionListados != 0);
}

void procesarConsultas(ListaR listaReclamos)
{
    int opcionConsultas;

    do
    {
        system("cls");
        mostrarMenuConsultas(opcionConsultas);

        switch(opcionConsultas)
        {
        case 1:
            //Clientes con apellido repetido
            break;
        case 2:
            //Clientes sin reclamos
            break;
        case 3:
            //Reclamos solucionados / sin solucionar
            break;
        case 4:
            //Reclamos por rango de fechas
            break;
        case 5:
            //Cliente con mas reclamos
            break;
        case 0:
            //Volver
            break;
        default:
            system("cls");
            printf("OPCION INCORRECTA \n");
            system("pause");
            break;
        }
    }
    while (opcionConsultas != 0);
}

int main()
{
    int opcion;
    ListaR listaReclamos;

    do
    {
        system("cls");
        mostrarMenuPrincipal(opcion);

        switch(opcion)
        {
        case 1:
            procesarAltasBajas(listaReclamos);
            break;
        case 2:
            procesarListados(listaReclamos);
            break;
        case 3:
            procesarConsultas(listaReclamos);
            break;
        case 0:
            // Salir del programa
            break;
        default:
            system("cls");
            printf("OPCION INCORRECTA \n");
            system("pause");
            break;
        }
    }
    while (opcion != 0);

    return 0;
}
