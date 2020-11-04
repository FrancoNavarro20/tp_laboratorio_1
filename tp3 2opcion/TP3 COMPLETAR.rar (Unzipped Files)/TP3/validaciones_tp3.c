#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones_tp3.h"
#define VACIO 0
#define LLENO 1




//Menu funcion

int menu(char opciones[], char texto[], char textoError[],int* opcionDevolvida)
{
    char guardarOpcion[100];
    int opcion;
    int retorno = -1;

    printf("%s\n",opciones);
    printf("%s",  texto);
    fflush(stdin);
    scanf("%[^\n]", guardarOpcion);
    while(validarEnteroIsdigit(guardarOpcion) == 0)
    {
        printf("%s",  textoError);
        fflush(stdin);
        scanf("%[^\n]", guardarOpcion);
        retorno = 0;
    }

    opcion = atoi(guardarOpcion);
    *opcionDevolvida = opcion;
    //validarDatosInt(opcion,1,4,textoError);
    return retorno;
}

//------------------Ingreso de datos y validacion--------------------

int ingresarOpcionInt(char texto[])
{
    int opcion;
    if(texto != NULL)
    {
        printf("%s", texto);
        scanf("%d",&opcion);
    }

    return opcion;
}

float ingresarOpcionFloat(char texto[])
{
    float opcion;
    if(texto != NULL)
    {
        printf("%s", texto);
        scanf("%f",&opcion);
    }

    return opcion;
}

void ingresarOpcionSoloUnChar(char* opcion, char texto[])
{
    if(texto != NULL)
    {
        printf("%s", texto);
        fflush(stdin);
        scanf("%c", opcion);
    }
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
    int retorno = -1;
    char guadarOpcion[20];

    while(dato < min || dato > max)
    {
        opcionErrorNumerosTipos(guadarOpcion,textoError,&dato);
        retorno =0;
    }


    return retorno;
}

float validarDatosFloat(float dato, float min, float max, char textoError[])
{
    float opcion;
    opcion = dato;

    while(opcion < min || opcion > max)
    {
        opcion = ingresarOpcionFloat(textoError);
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

int validarEnteroFlotante(char texto[])
{
    int i;
    int retorno = -1;
    int cantidadTexto = strlen(texto);

    if(texto != NULL)
    {
        for(i=0;i<cantidadTexto;i++)
        {
            if(!isdigit(texto[i])&& ispunct(texto[i+1]))
            {
                retorno = 0;
                break;
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

int opcionErrorNumeros(char opcion[],char textoError[],int* opcionValidada)
{
    int retorno = -1;
    if(opcion != NULL && textoError != NULL)
    {
       while(validarEnteroIsdigit(opcion)== 0)
       {
            printf("%s", textoError);
            scanf("%s", opcion);
            retorno =0;
       }

       *opcionValidada = atoi(opcion);
    }


    return retorno;
}

int opcionErrorNumerosSinPunteroInt(char opcion[],char textoError[])
{
    int retorno = -1;
    if(opcion != NULL && textoError != NULL)
    {
       while(validarEnteroIsdigit(opcion)== 0)
       {
            printf("%s", textoError);
            scanf("%s", opcion);
            retorno =0;
       }

       //*opcionValidada = atoi(opcion);
    }


    return retorno;
}

int opcionErrorNumerosTipos(char opcion[],char textoError[],int* opcionValidada)
{
    int retorno = -1;
    char guardarOpcion[20];
    if(opcion != NULL && textoError != NULL)
    {
       ingresarOpcionChar(guardarOpcion,"\nIngrese nuevamente la opcion:");
       while(validarEnteroIsdigit(guardarOpcion)== 0)
       {
            printf("%s", textoError);
            scanf("%s", guardarOpcion);
            retorno =0;
       }

       *opcionValidada = atoi(guardarOpcion);
    }


    return retorno;
}

int opcionErrorNumerosFlotantes(char opcion[],char textoError[])
{
    int retorno = -1;
    if(opcion != NULL && textoError != NULL)
    {
       while(validarEnteroFlotante(opcion)== 0)
       {
            printf("%s", textoError);
            scanf("%s", opcion);
            retorno =0;
       }
    }

    return retorno;
}


int opcionErrorCadena(char opcion[],char textoError[])
{
    int retorno = -1;
    if(opcion != NULL && textoError != NULL)
    {
       while(validarCharCadena(opcion)== 0)
       {
            printf("%s", textoError);
            scanf("%s", opcion);
            retorno =0;
       }
    }

    return retorno;
}

int opcionErrorSexo(char opcion,char textoError[])
{
    int retorno = -1;
    if(textoError != NULL)
    {
       while(opcion !='m' && opcion != 'f')
       {
            printf("%s", textoError);
            fflush(stdin);
            scanf("%c", &opcion);
            retorno =0;
       }
    }

    return retorno;
}

int opcionErrorTipo(char opcion[],char textoError[])
{
    int retorno = -1;
    int perro = strcmp(opcion,"perro");
    int gato = strcmp(opcion,"gato");
    int raro = strcmp(opcion,"raro");

    if(opcion != NULL && textoError != NULL)
    {

       while(perro != 0 && gato != 0 && raro != 0)
       {
            printf("%s", textoError);
            scanf("%s", opcion);
            retorno =0;
       }
    }

    return retorno;
}



