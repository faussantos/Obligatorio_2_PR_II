#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ListaReclamos.h"
#include "ArbolCliente.h"

void procesarAltasBajas(ListaR &listaReclamos, ArbolCliente &ArbolClientes)
{
    int opcionAltasBajas;
    reclamo nuevoReclamo;
    int siguienteNumeroReclamo;
    long int ci;
    cliente c;
    do
    {
        system("cls");
        mostrarMenuAltasBajas(opcionAltasBajas);
        system("cls");
        switch(opcionAltasBajas)
        {
        case 1:
            printf(":: INGRESO DE CLIENTE ::\n");
            cargaCliente(c);
            if(!ExisteCliente(ArbolClientes,darCedula_cliente(c)))
            {
                insertarCliente(ArbolClientes,c);
                printf("Cliente ingresado con exito.\n");
            }
            else
                printf("\nERROR: Cedula ya registrada");
            system("pause");
            break;
        case 2:
            //Eliminar Cliente
            printf("Ingrese la cedula del cliente a eliminar: ");
            scanf("%ld",&ci);
            if(ExisteCliente(ArbolClientes,ci))
            {
                Borrar(ci,ArbolClientes);
                printf("Cliente eliminado exitosamente.");
            }
            else
                printf("Error: No existe cliente con esa cedula");
            system("pause");
            break;
        case 3:
            //Agregar Reclamo
            siguienteNumeroReclamo = LargoReclamos(listaReclamos) + 1;
            cargaReclamo(nuevoReclamo,siguienteNumeroReclamo);
            if(ExisteCliente(ArbolClientes,darCedula_reclamo(nuevoReclamo)))
            {
                InsBack(listaReclamos,nuevoReclamo);
                printf("Reclamo ingresado con exito\n");
            }
            else
                printf("ERROR: No existe cliente con esa cedula.\n");
            system("pause");
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

void procesarListados(ListaR listaReclamos, ArbolCliente ArbolClientes)
{
    int opcionListados;
    fecha fechaIngresada;
    long int ci;
    do
    {
        system("cls");
        mostrarMenuListados(opcionListados);
        system("cls");
        switch(opcionListados)
        {
        case 1:
            //Clientes
            if(!esVacio(ArbolClientes))
                listar_clientes_ordenados(ArbolClientes);
            else
                printf("Lista vacia");
            system("pause");
            break;
        case 2:
            //Reclamos por cliente
            printf("Ingrese la cedula del cliente a mostrar reclamos: ");
            scanf("%ld",&ci);
            if(ExisteCliente(ArbolClientes,ci))
            {
                printf("::RECLAMOS DEL CLIENTE ::\n");
                ListarReclamosCliente(listaReclamos,ci);
            }
            else
                printf("Error: No existe cliente con esa cedula");
            system("pause");
            break;
        case 3:
            //Reclamos por fecha
            cargaFecha(fechaIngresada);
            if(validarFecha(fechaIngresada))
            {
                ListarReclamosFecha(listaReclamos,fechaIngresada);
            }
            else
            {
                printf("Fecha incorrecta");
            }
            system("pause");
            break;
        case 4:
            //Cliente por reclamo
            system("pause");
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
    int reclamosResueltos;
    int reclamosSinResolver;
    do
    {
        system("cls");
        mostrarMenuConsultas(opcionConsultas);
        system("cls");
        switch(opcionConsultas)
        {
        case 1:
            //Clientes con apellido repetido
            break;
        case 2:
            //Clientes sin reclamos
            break;
        case 3:
            CantidadResueltosSinResolver(listaReclamos, reclamosResueltos, reclamosSinResolver);
            printf("+ RESUELTOS: %d", reclamosResueltos);
            printf("+ SIN RESOLVER: %d", reclamosSinResolver);
            system("pause");
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
    ArbolCliente ArbolClientes;
    crear(ArbolClientes);
    Crear(listaReclamos);

    do
    {
        system("cls");
        mostrarMenuPrincipal(opcion);

        switch(opcion)
        {
        case 1:
            procesarAltasBajas(listaReclamos, ArbolClientes);
            break;
        case 2:
            procesarListados(listaReclamos, ArbolClientes);
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
}
