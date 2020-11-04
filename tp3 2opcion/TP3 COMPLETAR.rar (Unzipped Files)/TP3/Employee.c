#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validaciones_tp3.h"

//Cargando espacio en memoria de empleado!!!
Employee* employee_new()
{
    Employee* pEmpleado;
    //eEmpleado* pEmpleado;

    pEmpleado = malloc(sizeof(Employee));

    return pEmpleado;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}
 /*
    pEmpleado->id=id;
    strcpy(pEmpleado->nombre, nombreStr);
    pEmpleado->horasTrabajadas = horasTrabajo;
    pEmpleado->sueldo = sueldo;

    int id;
    int horasTrabajo;
    int sueldo;

    pEmpleado =  employee_new();

    id = atoi(idStr);
    horasTrabajo = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);
    if(pEmpleado != NULL)
    {

        employee_setId(pEmpleado,id);
        employee_setNombre(pEmpleado,nombreStr);
        employee_setHorasTrabajadas(pEmpleado,horasTrabajo);
        employee_setSueldo(pEmpleado,sueldo);
    }

*/

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleado;

    pEmpleado = employee_new();

    if(pEmpleado != NULL)
    {
        if(!verify_Employees_data(pEmpleado,idStr,nombreStr,horasTrabajadasStr,sueldoStr))
        {
            //free(pEmpleado);
            employee_delete(pEmpleado); // -> estoy liberando el espacio si no se asigno las variables
            pEmpleado = NULL;
        }

    }

    return pEmpleado;
}

Employee* employee_Final()
{
    Employee* pEmpleadoCargado;
    //Aca tiene que cargar el usuario los datos y validarlo;
    char id[100] = "10"; // Despues se pisa en el controller
    char nombre[100];
    char horasTrabajo[100];
    char sueldoEmployee[100];

    ingresarOpcionChar(nombre,"Ingrese el nombre del Empleado:");
    opcionErrorCadena(nombre,"Error solo letras,re-Ingrese el nombre del Empleado:");

    ingresarOpcionChar(horasTrabajo,"Ingrese las horas trabajadas por el Empleado:");
    opcionErrorNumerosSinPunteroInt(horasTrabajo,"Error solo numeros,re-Ingrese las horas trabajadas por el Empleado:");

    ingresarOpcionChar(sueldoEmployee,"Ingrese el sueldo del Empleado:");
    opcionErrorNumerosSinPunteroInt(sueldoEmployee,"Error solo numeros,re-Ingrese el sueldo del Empleado:");


    pEmpleadoCargado = employee_newParametros(id,nombre,horasTrabajo,sueldoEmployee);

    return pEmpleadoCargado;
}


int verify_Employees_data(Employee* this,char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    //Employee* pEmpleado;
    int id;
    int horasTrabajo;
    int sueldo;
    int retorno = 0;

    id = atoi(idStr);
    horasTrabajo = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);


    if(employee_setId(this,id))
    {
        if(employee_setNombre(this,nombreStr))
        {
            if(employee_setHorasTrabajadas(this,horasTrabajo))
            {
                if(employee_setSueldo(this,sueldo))
                {
                    retorno = 1;
                }
            }
        }
    }

    return retorno;
}



//----Getters y Setter id------
int employee_setId(Employee* this,int id)
{
    int setteo = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        setteo = 1;
    }

    return setteo;
}

int employee_getId(Employee* this,int* id)
{
    int getteo = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        getteo = 1;
    }
    return getteo;
}

//----Getters y Setter nombre------
int employee_setNombre(Employee* this,char* nombre)
{
    int setteo = 0;
    if(this !=NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        setteo = 1;
    }
    return setteo;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int getteo = 0;
    if(this !=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        getteo = 1;
        //strcpy(this->nombre,nombre);
        //getteo = 1;
    }

    return getteo;
}

//----Getters y Setter horasTrabajadas------


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int setteo = 0;
    if(this != NULL && horasTrabajadas>0)
    {

        this->horasTrabajadas = horasTrabajadas;
        setteo = 1;
    }

    return setteo;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int getteo = 0;
    if(this!=NULL && horasTrabajadas != NULL)
    {
        //*id = this->id;
        *horasTrabajadas = this->horasTrabajadas;
        getteo = 1;
    }

    return getteo;
}

//----Getters y Setter sueldo------

int employee_setSueldo(Employee* this,int sueldo)
{
    int setteo = 0;
    if(this != NULL && sueldo>0)
    {

        this->sueldo = sueldo;
        setteo = 1;
    }

    return setteo;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int getteo = 0;
    if(this!=NULL && sueldo != NULL)
    {
        //*id = this->id;
        *sueldo = this->sueldo;
        getteo = 1;
    }

    return getteo;
}

//------Funciones de comparacion nombre y id--------
//int employee_CompareById(void* e1, void* e2)
int employee_CompareById(Employee* e1, Employee* e2)
{

    int empleado1;
    int empleado2;
    int compara = 0;
    //int idRetornadoUno;

    //getters usarlo !!
    employee_getId(e1,&empleado1);
    employee_getId(e2,&empleado2);

    if(empleado1 > empleado2)
    {
        compara = 1;
    }
    else
    {
        if(empleado1 < empleado2)
        {
            compara = -1;
        }

        /*
        if(e1->id < e2->id)
        {
            compara = -1;
        }
        */
    }

    return compara;
}

int employee_CompareByName(Employee* e1, Employee* e2)
{
    int compara = 0;
    char empleadoUno[100];
    char empleadoDos[100];
    //gettes - me traigo el dato;
    employee_getNombre(e1,empleadoUno);
    employee_getNombre(e2,empleadoDos);

    if(strcmp(empleadoUno,empleadoDos) > 0)
    {
        compara = 1;
    }
    else
    {
        if(strcmp(empleadoUno,empleadoDos) < 0)
        {
            compara = -1;
        }
    }
    return compara;
}


