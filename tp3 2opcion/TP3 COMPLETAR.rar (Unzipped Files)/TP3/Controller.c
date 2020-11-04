#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "validaciones_tp3.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;

    if(path !=NULL && pArrayListEmployee!=NULL)
    {
        pArchivo = fopen(path,"r");
        if(pArchivo !=NULL)
        {
            parser_EmployeeFromText(pArchivo,pArrayListEmployee);
            retorno = 0;
        }

        fclose(pArchivo);
    }

    return retorno;
}



int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    FILE* pArchivoBinario;

    if(path !=NULL && pArrayListEmployee!=NULL)
    {
        pArchivoBinario = fopen(path,"rb");
        if(pArchivoBinario !=NULL)
        {
            parser_EmployeeFromBinary(pArchivoBinario,pArrayListEmployee);
            retorno = 0;
        }

        fclose(pArchivoBinario);
    }

    return retorno;
}

//int controller_addEmployee(LinkedList* pArrayListEmployee)-- funcion orginal;
int controller_addEmployee(LinkedList* pArrayListEmployee,LinkedList* pArrayListEmployeeBinario)
{
    int retorno = -1;
    int len = ll_len(pArrayListEmployee);
    Employee* auxEmpleado;
    if(pArrayListEmployee != NULL)
    {
        auxEmpleado = employee_Final();
        auxEmpleado->id = len+1;
        //guardando en lista texto
        ll_add(pArrayListEmployee,auxEmpleado);
        //Guardando en lista binaria
        ll_add(pArrayListEmployeeBinario,auxEmpleado);
        retorno = 0;
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char guardarId[100];
    int idModificar;
    Employee* aux;
    if(pArrayListEmployee!=NULL)
    {
        //1.Mostrar lista;
        controller_ListEmployee(pArrayListEmployee);
        //2.Elegir el id que quiere borrar;
        ingresarOpcionChar(guardarId,"\nIngrese el id del Empleado que quiere modificar:");
        opcionErrorNumeros(guardarId,"Error solo numeros,re-ingrese el id del Empleado que quiere modificar:",&idModificar);
        if(idModificar > 0 && idModificar <= 1000) // hacer una funcion que me busque si existe el id !!
        {
            aux = employee_Final();
            ll_set(pArrayListEmployee,idModificar-1,aux);
            printf("\nEl empleado se modifico correctamente.\n");
            retorno = 0;
        }
        else
        {
            printf("\nNo se encontro el id que se ingreso para modificar al empleado\n");
        }
    }

    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char guardarId[100];
    int idEliminar;
    //1.Mostrar lista;
    controller_ListEmployee(pArrayListEmployee);
    //2.Elegir el id que quiere borrar;
    ingresarOpcionChar(guardarId,"\nIngrese el id del Empleado que quiere eliminar:");
    opcionErrorNumeros(guardarId,"Error solo numeros,re-ingrese el id del Empleado que quiere eliminar:",&idEliminar);
    if(idEliminar > 0 && idEliminar <= 1000) // hacer una funcion que me busque si existe el id !!
    {
        ll_remove(pArrayListEmployee,idEliminar-1);
        printf("\nEl empleado se elimino correctamente.\n");
        retorno = 0;
    }
    else
    {
        printf("\nNo se encontro el id que se ingreso\n");
    }
    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    //Mostrar la lista !!!
    int retorno = -1;
    int len;
    int i;
    int* pidEmpleado = NULL;
    char nombre[50];
    int* phorasTrabajadasEmpleado = NULL;
    int* psueldoEmpleado = NULL;
    int id;
    int horasTrabajo;
    int sueldoEmpleados;
    Employee* aux;

    len = ll_len(pArrayListEmployee);
    pidEmpleado = &id;
    psueldoEmpleado = &sueldoEmpleados;
    phorasTrabajadasEmpleado = &horasTrabajo;

    if(pArrayListEmployee !=NULL)
    {
        printf("  ID  |  NOMBRE  |    HORAS T  |     SUELDO\n");
        for(i=0;i<len;i++)
        {
            aux = (Employee*)ll_get(pArrayListEmployee,i);
            //Traer los valores de mi lista con los getter y guardarlo en una variable y despues lo mostramos;

            mostrarEmpleado(aux); // Agregar todos los getes a esa funcion!!
            employee_getId(aux,pidEmpleado);
            employee_getNombre(aux,nombre);
            employee_getHorasTrabajadas(aux,phorasTrabajadasEmpleado);
            employee_getSueldo(aux,psueldoEmpleado);

            printf("  %-5d   %-12s   %-8d   %-5d\n",id,nombre,horasTrabajo,sueldoEmpleados);
            retorno = 0;
        }
    }

    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee !=NULL)
    {   printf("Ordenando lista por Id\n");
        ll_sort(pArrayListEmployee,employee_CompareById,1);
        retorno = 0;
    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int len = ll_len(pArrayListEmployee);
    Employee* auxEmpleado;
    FILE* miArchivoGuardar;
    miArchivoGuardar = fopen(path,"w");

    if(miArchivoGuardar !=NULL)
    {
        for(i=0;i<len;i++)
        {
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);

            fprintf(miArchivoGuardar,"%d, %s, %d, %d\n",auxEmpleado->id,auxEmpleado->nombre
                                                       ,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
            retorno = 0;
        }

        fclose(miArchivoGuardar);
    }
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i = 0;
    //int len = ll_len(pArrayListEmployee);
    Employee* auxEmpleado;
    FILE* miArchivoGuardarBinario;
    miArchivoGuardarBinario = fopen(path,"wb");

    if(miArchivoGuardarBinario !=NULL)
    {
        //usar while feof();
        while(!feof(miArchivoGuardarBinario))
        {
            auxEmpleado =(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(&auxEmpleado,sizeof(auxEmpleado),1,miArchivoGuardarBinario);

            printf("%-5d, %-10s, %-12d, %-5d",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas
                                             ,auxEmpleado->sueldo);
            i++;
            retorno = 0;
        }
        //Cerrando el Archivo.
        fclose(miArchivoGuardarBinario);
    }

    return retorno;
}

