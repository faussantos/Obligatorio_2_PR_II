#include "boolean.h"
#include <stdio.h>
void cargaBool (boolean &b)
{
    char c;
    printf("Ingrese (V)Para SI o (F)Para NO: ");
    fflush(stdin);
    scanf("%c",&c);
    switch(c)
        {
        case 'V':
        case 'v':
            b = TRUE;
            break;
        case 'F':
        case 'f':
            b= FALSE;
        }
}

void printBool (boolean b)
{
    if(b==TRUE)
        printf("True");
    else
        printf("False");
}
