#include "cliente.h"
#include <stdio.h>

//FUNCIONES BASICAS
void cargaCliente(cliente &c)// verificar q no exista alguein con  la misma cedula
{
    strcrear(c.nombre);
    strcrear(c.apellido);
    strcrear(c.direccion);
    printf("Ingrese la cedula: ");
    scanf("%ld",&c.ci);
    printf("Ingrese el nombre: ");
    scan(c.nombre);
    printf("Ingrese el apellido: ");
    scan(c.apellido);
    printf("Ingrese la direccion: ");
    scan(c.direccion);
    printf("Ingrese el telefono: ");
    scanf("%ld",&c.telefono);
    c.cant_reclamos = 0;
}

void printCliente(cliente c)
{
    printf("DATOS DEL CLIENTE:\n");
    printf("Cedula: %ld",c.ci);
    printf("\nNombre: ");
    print(c.nombre);
    printf("\nApellido: ");
    print(c.apellido);
    printf("\nDireccion: ");
    print(c.direccion);
    printf("\nTelefono: ");
    printf("%ld",c.telefono);
    printf("\nCantidad de reclamos: ");
    printf("%d",c.cant_reclamos);
}

long int darCedula_cliente(cliente c)
{
    return c.ci;
}

void darNombre (cliente c, strings &s)
{
    strcop(s,c.nombre);
}

void darApellido (cliente c, strings &s)
{
    strcop(s,c.apellido);
}

void darDireccion (cliente c, strings &s)
{
    strcop(s,c.direccion);
}

long int darTelefono(cliente c)
{
    return c.telefono;
}

int darCantidadReclamos(cliente c)
{
    return c.cant_reclamos;
}



////FUNCIONES ADICIONALESK
//Dada la cédula que identifica a un cliente, borrar dicho cliente del sistema. Se debe verificar
//previamente que la cédula del cliente a borrar exista en el sistema. Además de borrar el
//cliente, también se deben borrar todos los reclamos que hayan sido hechos por dicho cliente.
