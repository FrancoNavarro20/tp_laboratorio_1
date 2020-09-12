#include <stdio.h>
#include <stdlib.h> //libreria para los system
#include <ctype.h>
#include <conio.h> //libreria para la funcion getch();
#include <string.h>
#include "funciones-aritmeticas.h"
#include "calculadora.h"

void Calculadora(void)
{
     //variables
    float primerNumero;
    float segundoNumero;
    int opcion;
    float OperacionSuma;
    float OperacionResta;
    float OperacionDivision;
    float OperacionMultiplicacion;
    double OperacionFactorialUno;
    double OperacionFactorialDos;
    int banderaPrimerNumero;
    int banderaSegundoNumero;
    int banderaOperacionesResueltas;
    int banderaCalcularOperaciones;
    char respuesta;


    banderaPrimerNumero =1;
    banderaSegundoNumero =1;
    banderaOperacionesResueltas =1;
    banderaCalcularOperaciones = 1;

    printf("********-Hola bienvenido a nuestra calculadora!!!-*************** \n");
    printf("\n");
    printf("Ingrese las opciones con los numeros correspondientes y le resolveremos los problemas :)");
    printf("\n");
    printf("\n");
    system("pause");
    system("cls");


    do
    {
        //MENU DE ENTRADA;
        printf(":::Calculadora::: \n \n");
        if(banderaPrimerNumero == 1)
        {
            printf("1.Ingrese 1er operando(A=x)\n");
        }
        else
        {
            printf("1.Ingrese 1er operando(A=%.2f)\n",primerNumero);
        }

        if(banderaSegundoNumero ==1)
        {
            printf("2.Ingrese 2do operando(B=y)\n");

        }
        else
        {
            printf("2.Ingrese 2do operando(B=%.2f)\n",segundoNumero);

        }

        printf("\n3.Calcular todas las operaciones");

        if(banderaPrimerNumero == 0 && banderaSegundoNumero == 0)
        {
            printf("\n  a) Calcular la suma(%.2f + %.2f)",primerNumero,segundoNumero);
            printf("\n  b) Calcular la resta(%.2f - %.2f)",primerNumero,segundoNumero);
            printf("\n  c) Calcular la division(%.2f / %.2f)",primerNumero,segundoNumero);
            printf("\n  d) Calcular la multiplicacion(%.2f * %.2f)",primerNumero,segundoNumero);
            printf("\n  f) Calcular la factorial A=%.2f! y el de B=%.2f \n",primerNumero,segundoNumero);
        }
        else
        {
            printf("\n  a) Calcular la suma(A + B)");
            printf("\n  b) Calcular la resta(A - B)");
            printf("\n  c) Calcular la division(A / B)");
            printf("\n  d) Calcular la multiplicacion(A * B)");
            printf("\n  f) Calcular la factorial A=! y el de B=! \n");
        }

        printf("\n4.informar resultados:");
        printf("\n");
        printf("\n5.Salir \n");
        printf("\n");
        opcion = IngresarOpcion(1,5);

        // SELECCION DE OPERACION;
        switch(opcion)
        {
            case 1:
                primerNumero = PedirFlotante("1.Ingrese 1er operando(A=x):");
                banderaPrimerNumero = 0;
                system("cls");
                break;
            case 2:
                system("cls");
                segundoNumero = PedirFlotante("2.Ingrese 2do operando(B=y):");
                banderaSegundoNumero = 0;
                system("cls");
                break;
            case 3:
                if(banderaPrimerNumero == 0 && banderaSegundoNumero == 0)
                {
                   //Realizando las operaciones;
                    OperacionSuma = SumarFlotantes(primerNumero,segundoNumero);
                    OperacionResta = RestarFlotantes(primerNumero,segundoNumero);
                    OperacionDivision = DividirFlotantes(primerNumero,segundoNumero);
                    OperacionMultiplicacion = MultiplicacionFlotantes(primerNumero,segundoNumero);
                    OperacionFactorialUno=FactorialFlotante(primerNumero);
                    OperacionFactorialDos=FactorialFlotante(segundoNumero);
                    banderaCalcularOperaciones=0;

                    system("cls");
                    printf("Bien hecho sean resuelto todas las operacion !!!\n");
                    printf("\n");
                    printf("Precione cualquier tecla para volver al menu...");
                    getch(); //parar consola
                    //system("pause");
                    system("cls");
                }
                else
                {   system("cls");
                    printf("Debes ingresar primero los numeros para que podamos resolver las operaciones.\n");
                    printf("\n");
                    printf("Precione cualquier tecla para volver al menu...");
                    getch(); //pausa
                    system("cls");
                    continue;
                }
                break;
            case 4:
                //system("cls");
                if(banderaPrimerNumero == 0 && banderaSegundoNumero == 0  && banderaCalcularOperaciones ==0)
                {
                    printf("\n");
                    printf("Los resultados son:\n");

                    //SUMA
                    printf("a)El resultado de(%.2f + %.2f) es: %.2f \n",primerNumero,segundoNumero,OperacionSuma);

                    //RESTA
                    printf("b)El resultado de(%.2f - %.2f) es: %.2f \n",primerNumero,segundoNumero,OperacionResta);

                    //DIVISION
                    if(segundoNumero == 0.00)
                    {
                        printf("c)El resultado de(%.2f / %.2f) es: No se puede dividir por cero \n",primerNumero,segundoNumero);
                    }
                    else
                    {
                        printf("c)El resultado de(%.2f / %.2f) es: %.2f \n",primerNumero,segundoNumero,OperacionDivision);
                    }

                    //MULTIPLICACION
                    printf("d)El resultado de(%.2f * %.2f) es: %.2f \n",primerNumero,segundoNumero,OperacionMultiplicacion);

                    //FACTORIALES
                    if(primerNumero<0)
                    {
                         printf("f)El factorial de %.2f es: no podemos realizar el factorial de un numero negativo.\n",primerNumero);
                    }
                    else
                    {
                        printf("f)El factorial de %.2f es: %.2f \n",primerNumero,OperacionFactorialUno);

                    }
                    if(segundoNumero <0)
                    {
                        printf("f)el factorial de %.2f es: no podemos realizar el factorial de un numero negativo.\n", segundoNumero);
                    }
                    else
                    {
                        printf("f)El factorial de %.2f es: %.2f \n",primerNumero,OperacionFactorialDos);
                    }

                    banderaOperacionesResueltas = 0;

                    printf("\n");
                    //system("pause");
                }
                else
                {   system("cls");
                    printf("Por favor, primero ingrese los numeros(opcion 1 y 2) y calcule sus operaciones(opcion 3) y luego de resolverlos le mostraremos los  resultados.\n");
                    printf("\n");
                    printf("Precione cualquier tecla para volver al menu...");
                    getch(); //parar consola
                    system("cls");
                }
                break;
            case 5:
                printf("\nMuchas gracias por usar nuestra calculadora.\n");
                break;

        }
        //Dejar un espacio al volver ejecutarse el programa;
        printf("\n");

        //Verificando si se realizaron las operaciones;
        if(banderaOperacionesResueltas == 0)
        {
            printf("¿Desea realizar otra operacion? (s/n):");
            fflush(stdin); //limpiar buffer
            scanf("%c",&respuesta);
            respuesta = tolower(respuesta);
            while(respuesta != 's' && respuesta != 'n')
            {
                printf("Error escriba 's' si quiere continuar o 'n' si no desea continuar(s/n):");
                fflush(stdin);
                scanf("%c",&respuesta);
            }

            if(respuesta == 's')
            {
                banderaPrimerNumero = 1;
                banderaSegundoNumero =1;
                banderaOperacionesResueltas = 1;
                banderaCalcularOperaciones =1;
            }
            else
            {
                printf("\nMuchas gracias por usar nuestra calculadora.\n");
                exit(-1);//salir del programa
            }

            //Limpiando la consola para volver  a introducir los datos;
            system("cls");
        }



    }while(opcion != 5);

}

float PedirFlotante(char texto[])
{
    float numero;

    system("cls");
    printf("%s",texto);
    scanf("%f",&numero);

    return numero;
}
int IngresarOpcion(int min, int max)
{
    int opcion;
    //OPCION Y VALIDACION
    printf("Ingrese una opcion:");
    scanf("%d", &opcion);
    while(opcion<min || opcion> max)
    {
        printf("Error, re-ingrese una opcion(1 al 5):");
        scanf("%d", &opcion);
    }

    return opcion;
}

