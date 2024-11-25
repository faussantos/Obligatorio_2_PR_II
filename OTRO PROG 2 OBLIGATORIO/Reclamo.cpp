#include "reclamo.h"
void cargaReclamo (reclamo &r,int x)//verificar q el cliente exista y  validarreclamo ==true;
{
    r.n_reclamo=x;
    printf("Ingrese fecha de reclamo");
    cargaFecha(r.realizacion);
    while (!validarFecha(r.realizacion))// y comprobar tb que sea posterior a la fecha anterior del ulitmo reclmao registrado
    {
        system("cls");
        printf("ERROR: Fecha invalida. Intente nuevamente: \n");
        printf("Ingrese fecha de reclamo");
        cargaFecha(r.realizacion);
    }
    printf("Ingrese motivo: ");
    scan(r.motivo);
    printf("Ingrese cedula del cliente: ");
    scanf("%ld",&r.ci_cliente);
    printf("El problema fue solucionado?\n");
    cargaBool(r.solucionado);

}

void printReclamo(reclamo r)
{
    printf("NUMERO DE RECLAMO: %d",r.n_reclamo);
    printf("  FECHA DE REALIZACION : ");
    printFecha(r.realizacion);
    printf("   MOTIVO: ");
    print(r.motivo);
    printf("   CEDULA: %ld",r.ci_cliente);
    if (r.solucionado==FALSE)
        printf("   PROBLEMA SOLUCIONADO: NO");
    else
        printf("   PROBLEMA SOLUCIONADO: SI");
}

int darNumReclamo (reclamo r)
{
    return r.n_reclamo;
}

fecha darFecha(reclamo r)
{
    return r.realizacion;
}

void darMotivo (reclamo r, strings &s)
{
    strcrear(s);
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
boolean validarReclamo (reclamo r, reclamo a)// EL PRIMER RECLAMO ES EL NUEVO A INGRESAR
{
    boolean b=FALSE;
    if (darAnio(r.realizacion)>darAnio(a.realizacion))
        b= TRUE;
    else
    {
        if (darMes(r.realizacion)==darMes(a.realizacion))
            b= TRUE;
        else
        {
            if (darDia(r.realizacion)>darDia(a.realizacion))
                b= TRUE;
            else
            {
                if (darDia(r.realizacion)==darDia(a.realizacion))
                    b=TRUE;
            }
        }
    }
    return b;
}

//PRECONDICIÓN: El archivo viene abierto para escritura
void bajar_reclamo (reclamo r, FILE * f)
{
    fwrite(&r.n_reclamo,sizeof(int),1,f);
    fwrite(&r.realizacion,sizeof(fecha),1,f);
    bajar_string(r.motivo,f);
    fwrite(&r.ci_cliente,sizeof(long int),1,f);
    fwrite(&r.solucionado,sizeof(boolean),1,f);
}

//PRECONDICIÓN: El archivo viene abierto para lectura
void levantar_reclamo (reclamo &r, FILE * f)
{
    fread(&r.n_reclamo,sizeof(int),1,f);
    fread(&r.realizacion,sizeof(fecha),1,f);
    strcrear(r.motivo);
    levantar_string(r.motivo,f);
    fread(&r.ci_cliente,sizeof(long int),1,f);
    fread(&r.solucionado,sizeof(boolean),1,f);
}
