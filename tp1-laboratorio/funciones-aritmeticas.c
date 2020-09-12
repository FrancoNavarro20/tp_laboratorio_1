#include <stdio.h>
#include <stdlib.h> //libreria para los system
#include "funciones-aritmeticas.h"

float SumarFlotantes(float primerNumero, float segundoNumero)
{
    float resultado;

    resultado = primerNumero + segundoNumero;

    return resultado;
}

float RestarFlotantes(float primerNumero, float segundoNumero)
{
    float resultado;

    resultado = primerNumero - segundoNumero;

    return resultado;
}

float DividirFlotantes(float primerNumero, float segundoNumero)
{
    float resultado;

    resultado = primerNumero / segundoNumero;

    return resultado;
}

float MultiplicacionFlotantes(float primerNumero, float segundoNumero)
{
    float resultado;

    resultado = primerNumero * segundoNumero;

    return resultado;
}

double FactorialFlotante(double Numero)
{
    double resultado;
    int i;

    resultado = 1;
    for(i=1;i<=Numero;i++)
    {
        resultado = resultado*i;
    }


    return resultado;
}
