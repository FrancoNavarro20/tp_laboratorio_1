#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_estructuras.h"
#define TAM 1000
#define VACIO 0
#define LLENO 1



//Funcion Inicialisar los isEmpty;

int ingresarOpcionInt(char texto[])
{
    int opcion;

    printf("%s", texto);
    scanf("%d",&opcion);

    return opcion;
}

void ingresarOpcionChar(char opcion[], char texto[])
{

    if(opcion != NULL && texto != NULL)
    {
        printf("%s", texto);
        fflush(stdin);
        scanf("%[^\n]", opcion);
    }
}

int validarDatosInt(int dato, int min , int max, char textoError[])
{
    int opcion;
    opcion = dato;

    while(opcion < min || opcion > max)
    {
        opcion = ingresarOpcionInt(textoError);
    }


    return opcion;
}


int validarEnteroIsdigit(char texto[])
{
    int i;
    int retorno = 1;
    int cantidadTexto = strlen(texto);

    if(texto != NULL)
    {
        for(i=0;i<cantidadTexto;i++)
        {
            if(!isdigit(texto[i]))
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}


int validarCharCadena(char texto[])
{
    int i;
    int retorno = 1;
    int cantidadTexto = strlen(texto);

    if(texto != NULL)
    {
        for(i=0;i<cantidadTexto;i++)
        {
            if(!isalpha(texto[i]))
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}
