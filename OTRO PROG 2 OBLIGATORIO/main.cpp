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
    ArbolCliente aux;
    do
    {
        system("cls");
        mostrarMenuAltasBajas(opcionAltasBajas);
        system("cls");
        switch(opcionAltasBajas)
        {
        case 1:
            //Ingresar Cliente
            printf(":: INGRESO DE CLIENTE ::\n\n");
            cargaCliente(c);
            if(!ExisteCliente(ArbolClientes,darCedula_cliente(c)))
            {
                insertarCliente(ArbolClientes,c);
                printf("\nCliente ingresado con exito.\n");
            }
            else
                printf("\nERROR: Cedula ya registrada\n");
            system("pause");
            break;
        case 2:
            //Eliminar Cliente
            printf(":: ELIMINAR CLIENTE ::\n\n");
            printf("Ingrese la cedula del cliente a eliminar: ");
            scanf("%ld",&ci);
            if(ExisteCliente(ArbolClientes,ci))
            {
                Borrar(ci,ArbolClientes);
                printf("\nCliente eliminado con exito.\n");
            }
            else
                printf("\nError: No existe cliente con esa cedula\n");
            system("pause");
            break;
        case 3:
            //Agregar Reclamo
            printf(":: AGREGAR RECLAMO ::\n\n");
            siguienteNumeroReclamo = LargoReclamos(listaReclamos) + 1;
            cargaReclamo(nuevoReclamo, siguienteNumeroReclamo);
            aux=devolverClienteCI(ArbolClientes,darCedula_reclamo(nuevoReclamo));
            if(aux!=NULL)
            {
                sumarUnReclamo(aux->info);
                if(Vacia(listaReclamos) == TRUE || fechaMenor(darFecha(nuevoReclamo), ObtenerFechaUltimoReclamo(listaReclamos)) == FALSE)
                {
                    InsBack(listaReclamos,nuevoReclamo);
                    printf("\nReclamo ingresado con exito\n");
                }
                else
                {
                    printf("\nERROR: La fecha ingresada debe ser mayor o igual a la del ultimo reclamo.\n");
                }
            }
            else
                printf("\nERROR: No existe cliente con esa cedula.\n");
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
    int nroReclamo;

    do
    {
        system("cls");
        mostrarMenuListados(opcionListados);
        system("cls");
        switch(opcionListados)
        {
        case 1:
            //Clientes
            printf(":: LISTADO DE CLIENTES ::\n\n");
            if(!esVacio(ArbolClientes))
                listar_clientes_ordenados(ArbolClientes);
            else
                printf("Lista vacia");
            printf("\n");
            system("pause");
            break;
        case 2:
            //Reclamos por cliente
            printf(":: LISTADO DE RECLAMOS ::\n\n");
            printf("Ingrese la cedula del cliente a mostrar reclamos: ");
            scanf("%ld",&ci);
            if(ExisteCliente(ArbolClientes,ci))
            {
                printf("\nReclamos:\n\n");
                ListarReclamosCliente(listaReclamos,ci);
            }
            else
                printf("Error: No existe cliente con esa cedula");

            printf("\n");
            system("pause");
            break;
        case 3:
            //Reclamos por fecha
            printf(":: RECLAMOS DE FECHA ::");
            cargaFecha(fechaIngresada);

            printf("\n");

            if(validarFecha(fechaIngresada))
            {
                printf("\nReclamos:\n\n");
                ListarReclamosFecha(listaReclamos,fechaIngresada);
            }
            else
            {
                printf("Fecha incorrecta");
            }

            printf("\n\n");
            system("pause");
            break;
        case 4:
            //Cliente por reclamo
            printf(":: INFORMACION DE CLIENTE POR NUMERO DE RECLAMO ::\n\n");
            printf("Ingrese el numero de reclamo: ");
            scanf("%d",&nroReclamo);

            printf("\n");

            if (ExisteReclamo(listaReclamos, nroReclamo) == TRUE)
            {
                ci = ObtenerCedulaClienteReclamo(listaReclamos, nroReclamo);
                listar_cliente_ci(ArbolClientes, ci);
            }
            else
            {
                printf("El numero de reclamo ingresado no existe");
            }

            printf("\n");
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

void procesarConsultas(ListaR listaReclamos, ArbolCliente ArbolClientes)
{
    int cantidadClientesApellido;
    strings apellidoIngresado;

    int opcionConsultas;
    int reclamosResueltos;
    int reclamosSinResolver;

    int cantidadReclamosRangoFechas;
    fecha fechaIngresada1;
    fecha fechaIngresada2;

    long int ciMasReclamos;
    int cantMayorReclamos;
    do
    {
        system("cls");
        mostrarMenuConsultas(opcionConsultas);
        system("cls");
        switch(opcionConsultas)
        {
        case 1:
            //Clientes con apellido repetido
            printf(":: CANTIDAD DE CLIENTES CON EL MISMO APELLIDO ::\n\n");
            printf("Ingrese un apellido: ");
            scan(apellidoIngresado);
            cantidadClientesApellido = cant_clientes_apellido(apellidoIngresado, ArbolClientes);
            printf("Existen %d clientes con el apellido ingresado", cantidadClientesApellido);
            system("pause");
            break;
        case 2:
            //Clientes sin reclamos
            printf(":: CANTIDAD DE CLIENTES SIN RECLAMOS ::\n\n");
            printf("Cantidad: %d\n\n",ContarCLientesNorec(ArbolClientes));
            system("pause");
            break;
        case 3:
            //Cant reclamos resueltos y sin resolver
            printf(":: CANTIDAD DE RECLAMOS RESUELTOS Y SIN RESOLVER :: \n\n");
            CantidadResueltosSinResolver(listaReclamos, reclamosResueltos, reclamosSinResolver);
            printf("Resueltos: %d", reclamosResueltos);
            printf("\nSin resolver: %d", reclamosSinResolver);

            printf("\n\n");
            system("pause");
            //Reclamos solucionados / sin solucionar
            break;
        case 4:
            //Reclamos por rango de fechas
            printf(":: RECLAMOS POR RANGO DE FECHAS ::\n\n");
            printf("Ingrese la fecha 1:");
            cargaFecha(fechaIngresada1);
            printf("\nIngrese la fecha 2:");
            cargaFecha(fechaIngresada2);

            if(validarFecha(fechaIngresada1) == TRUE && validarFecha(fechaIngresada2) == TRUE)
            {
                if(compararFecha(fechaIngresada1, fechaIngresada2) == TRUE || fechaMenor(fechaIngresada1, fechaIngresada2) == TRUE)
                {
                    if(!Vacia(listaReclamos))
                    {
                        cantidadReclamosRangoFechas = cant_reclamos_2fechas(listaReclamos, fechaIngresada1, fechaIngresada2);
                        printf("\nExisten %d reclamos en el rango de fechas ingresado\n",cantidadReclamosRangoFechas);
                    }
                    else
                        printf("\nERROR: No existen reclamos cargados\n");
                }
                else
                {
                    printf("La primer fecha ingresada debe ser menor o igual a la segunda");
                }
            }
            else
            {
                printf("\nERROR: Una de las fechas ingresadas no es valida\n");
            }

            system("pause");
            break;
        case 5:
            //Cliente con mas reclamos
            if(!esVacio(ArbolClientes))
            {
                printf(":: CLIENTE CON MAS RECLAMOS ::\n\n");
                CedulaMasRec(ArbolClientes,cantMayorReclamos,ciMasReclamos);
                printf("Cedula: %ld",ciMasReclamos);
                printf("\nCantidad de reclamos: %d\n\n",cantMayorReclamos);
            }
            else
                printf("ERROR: No hay clientes registrados\n");
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
    while (opcionConsultas != 0);
}

int main()
{
    int opcion;

    ArbolCliente ArbolClientes;
    crear(ArbolClientes);

    if(existeArchivoArbol())
        levantar_abb(ArbolClientes);

    ListaR listaReclamos;
    Crear(listaReclamos);

    if(existeArchivoLista())
        Levantar_Lista(listaReclamos);

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
            procesarConsultas(listaReclamos, ArbolClientes);
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

    bajar_abb(ArbolClientes);
    Bajar_Lista(listaReclamos);
}
