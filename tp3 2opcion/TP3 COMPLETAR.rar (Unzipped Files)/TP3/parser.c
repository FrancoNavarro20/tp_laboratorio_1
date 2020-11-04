#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/* funsion orginal
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;

}

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee datosEmpleados[1000];
    char id[100];
    char nombre[100];
    char horasTrabajadas[100];
    char sueldo[100];
    int i = 0;
    int len = 0;
    int retorno = -1;


    if(pFile !=NULL)
    {
        //Primera lectura --> Lectura fantasma!!
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
            datosEmpleados[i].id = atoi(id);
            datosEmpleados[i].horasTrabajadas = atoi(horasTrabajadas);
            datosEmpleados[i].sueldo = atoi(sueldo);
            strcpy(datosEmpleados[i].nombre,nombre);

            //Mostrando
            printf("%d--%s--%d--%d\n",datosEmpleados[i].id,datosEmpleados[i].nombre
                                     ,datosEmpleados[i].horasTrabajadas,datosEmpleados[i].sueldo);

            //Agregando empleados a mi lista;
            ll_add(pArrayListEmployee,&datosEmpleados[i]);
            retorno = 0;
            i++;
        }

        fclose(pFile);
    }

    len = ll_len(pArrayListEmployee);

    printf("\nLectura exitosa, la cantidad de empleados leidos es: %d\n", len);

    return retorno;
}
*/

/*
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    char id[100];
    char nombre[100];
    char horasTrabajadas[100];
    char sueldo[100];
    int i = 0;
    int len = 0;
    int retorno = -1;
    Employee* datosEmpleados;

    if(pFile !=NULL)
    {

        datosEmpleados = (Employee*)malloc(sizeof(Employee)*1000);
        //datosEmpleados = employee_new();
        if(datosEmpleados !=NULL)
        {
            //Primera lectura --> Lectura fantasma!!
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

            printf(" ID   |  NOMBRE  |    HORAS T  |     SUELDO\n");
            while(!feof(pFile))
            {

                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

                datosEmpleados[i].id = atoi(id);
                datosEmpleados[i].horasTrabajadas = atoi(horasTrabajadas);
                datosEmpleados[i].sueldo = atoi(sueldo);
                strcpy(datosEmpleados[i].nombre,nombre);

                //new_con Parametros y que despues lo pasamos al ll_add;
                //Mostrando
                printf(" %-5d   %-12s   %-8d   %-5d\n\n",datosEmpleados[i].id,datosEmpleados[i].nombre
                                         ,datosEmpleados[i].horasTrabajadas,datosEmpleados[i].sueldo);

                //Agregando empleados a mi lista;
                ll_add(pArrayListEmployee,&datosEmpleados[i]);
                retorno = 0;
                i++;
            }
        }

    }

    len = ll_len(pArrayListEmployee);

    printf("\nLectura exitosa, la cantidad de empleados leidos es: %d\n", len);

    return retorno;

}


int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int i = 0;
    int len = 0;
    int retorno = -1;
    Employee* datosEmpleados;

    if(pFile !=NULL)
    {
        datosEmpleados = malloc(sizeof(Employee));

        //1.Leyendo los datos en binario -- Lectura fanasma

        //fread(&datosEmpleados[i],sizeof(Employee),1,pFile);

        if(datosEmpleados !=NULL)
        {
            printf(" ID   |  NOMBRE  |    HORAS T  |     SUELDO\n");
            while(!feof(pFile))
            {
                //1.Leyendo los datos en binario;
                fread(&datosEmpleados[i],sizeof(Employee),1,pFile);
                //2.Agregando empleados a mi lista de binarios;
                printf("  %-5d %-15s %-8d %-5d\n",datosEmpleados[i].id,datosEmpleados[i].nombre,datosEmpleados[i].horasTrabajadas,datosEmpleados[i].sueldo);
                ll_add(pArrayListEmployee,&datosEmpleados[i]);
                retorno = 0;
                i++;
            }
        }

    }

    len = ll_len(pArrayListEmployee);

    printf("\nLectura exitosa, la cantidad de empleados leidos en binario es: %d\n", len);

    return retorno;




    return 1;
}
*/

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee* pEmpleadoLocal;
    char* id=NULL;
    char* nombre=NULL;
    char* horas=NULL;
    char* sueldo=NULL;

    //Lectura fantasma
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);
    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);
        pEmpleadoLocal=employee_newParametros(id, nombre, horas, sueldo);
        if(pEmpleadoLocal != NULL)
        {
            ll_add(pArrayListEmployee, pEmpleadoLocal);
            retorno = 1;
        }
    }

    fclose(pFile);

    printf("\n*** DATOS IMPORTADOS CORRECTAMENTE. ***\n");

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee* pEmpleadoLocal;
    char* id=NULL;
    char* nombre=NULL;
    char* horas=NULL;
    char* sueldo=NULL;

    //Lectura fantasma - para que me omita el header;
    fread(pEmpleadoLocal,sizeof(Employee),1,pFile);
    while(!feof(pFile))
    {   /*
        id = (char*)malloc(sizeof(char*)*20);
        nombre = (char*)malloc(sizeof(char*)*128);
        horas = (char*)malloc(sizeof(char*)*20);
        sueldo = (char*)malloc(sizeof(char*)*20);
        */
        pEmpleadoLocal = employee_new();
        //pEmpleadoLocal=employee_newParametros(id, nombre, horas, sueldo);
        if(pEmpleadoLocal != NULL)
        {
            while(!feof(pFile))
            {
                fread(pEmpleadoLocal,sizeof(Employee),1,pFile);
                if(!feof(pFile))
                {
                    ll_add(pArrayListEmployee, pEmpleadoLocal);
                    retorno = 1;
                }

            }

        }
    }

    fclose(pFile);

    printf("\n*** DATOS IMPORTADOS CORRECTAMENTE. ***\n");

    free(id);
    free(nombre);
    free(horas);
    free(sueldo);

    return retorno;
}

