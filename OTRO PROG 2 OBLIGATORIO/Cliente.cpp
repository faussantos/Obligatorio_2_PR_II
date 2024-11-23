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
    printf("CI: %ld",c.ci);
    printf("  Nombre: ");
    print(c.nombre);
    printf("  Apellido: ");
    print(c.apellido);
    printf("  Direccion: ");
    print(c.direccion);
    printf("  Tel: ");
    printf(" %ld",c.telefono);
    printf("  Cantidad de reclamos: ");
    printf(" %d",c.cant_reclamos);
    printf("\n");
}

long int darCedula_cliente(cliente c)
{
    return c.ci;
}

void darNombre (cliente c, strings &s)
{
    strcrear(s);
    strcop(s,c.nombre);
}

void darApellido (cliente c, strings &s)
{
    strcrear(s);
    strcop(s,c.apellido);
}

void darDireccion (cliente c, strings &s)
{
    strcrear(s);
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

void sumarUnReclamo (cliente &c)
{
    c.cant_reclamos++;
}

//PRECONDICIÓN: El archivo viene abierto para escritura
void bajar_cliente (cliente c, FILE * f)
{
    fwrite(&c.ci,sizeof(long int),1,f);
    bajar_string(c.nombre,f);
    bajar_string(c.apellido,f);
    bajar_string(c.direccion,f);
    fwrite(&c.telefono,sizeof(long int),1,f);
    fwrite(&c.cant_reclamos,sizeof(int),1,f);
}

//PRECONDICIÓN: El archivo viene abierto para lectura
void levantar_cliente (cliente &c, FILE * f)
{
    fread(&c.ci,sizeof(long int),1,f);
    strcrear(c.nombre);
    levantar_string(c.nombre,f);
    strcrear(c.apellido);
    levantar_string(c.apellido,f);
    strcrear(c.direccion);
    levantar_string(c.direccion,f);
    fread(&c.telefono,sizeof(long int),1,f);
    fread(&c.cant_reclamos,sizeof(int),1,f);
}

////FUNCIONES ADICIONALES
//Dada la cédula que identifica a un cliente, borrar dicho cliente del sistema. Se debe verificar
//previamente que la cédula del cliente a borrar exista en el sistema. Además de borrar el
//cliente, también se deben borrar todos los reclamos que hayan sido hechos por dicho cliente.
