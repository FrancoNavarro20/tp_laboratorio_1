#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "utn_estructuras.h"
#define TAM 1000
#define VACIO 0
#define LLENO 1





int main()
{
    Employee datosEmpleados[TAM];
    int MenuOpcion;
    int inicialarIsEmpty;
    int inicialarId;
    int EntrarAOpciones;

    //inicializar a todos los empleados;
    inicialarIsEmpty = initEmpleyees(datosEmpleados, TAM);
    inicialarId = initEmpleyeesId(datosEmpleados,TAM);

    if(inicialarId ==0 && inicialarIsEmpty == 0)
    {
        printf("||--------------------------------Bienvenido al programa para cargar Empleados------------------||\n");
        printf("\nEsta todo listo para empezar el programa\n");

        system("pause");
        system("cls");
    }
    else
    {
        printf("Hubo problemas y no se puede inicial el programa");
        exit(-1);
    }


    do
    {
         printf("||--------------------------------Cargar Empleados---------------------------------------||\n");
        //Menu
        MenuOpcion = menu();

        //Entrar a las opciones;
        EntrarAOpciones = EntrarAopcionesMenu(datosEmpleados, MenuOpcion, TAM);
        if(EntrarAOpciones == 0)
        {
            printf("\n\nLa operacion se ejecuto exitosamente.\n");
        }
    }while(MenuOpcion != 5);

    return 0;
}



















