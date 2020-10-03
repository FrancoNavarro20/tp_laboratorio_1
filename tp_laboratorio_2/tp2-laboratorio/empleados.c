#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "utn_estructuras.h"
#define TAM 1000
#define VACIO 0
#define LLENO 1



//---------------------------------------FUNCIONES MENU Y ENTRADA A LAS OPCIONES----------------------------------------------


int menu()
{
    char guardarOpcion[100];
    int opcion;



    printf("\n1.ALTAS\n");
    printf("2.MODIFICAR\n");
    printf("3.BAJA\n");
    printf("4.INFORMAR\n");
    printf("5.SALIR\n");

    ingresarOpcionChar(guardarOpcion,"Ingrese una opcion:");
    while(validarEnteroIsdigit(guardarOpcion) == 0)
    {
        ingresarOpcionChar(guardarOpcion,"Error, re-ingrese una opcion:");
    }
    opcion = atoi(guardarOpcion);
    opcion = validarDatosInt(opcion,1,5, "Error, re-ingrese la opcion:");

    return opcion;
}

int EntrarAopcionesMenu(Employee datosEmpleados[] , int opcion, int cant)
{
    int retorno = -1;
    int opcionID;
    int opcionSubMenu;
    char guardarOpcionSubMenu[100];
    int mostrarEmpleados;
    int modificarEmpleado;
    int eliminarEmpleado;
    int ordenarEmpleados;
    float sueldoTotal;
    int contadorEmployee;
    int empleadosPromedioTotalMas;
    float promedioEmployee;


    promedioEmployee = 0;

    switch(opcion)
    {
        case 1:
            system("cls");
            arrayEmployee(datosEmpleados,cant);
            system("cls");
            break;
        case 2:
            system("cls");
            mostrarEmpleados = mostrarArrayEmployee(datosEmpleados, cant);

            if(mostrarEmpleados == -1)
            {
                printf("\nNo se han ingresado a ningun empleado.\n");
            }
            else
            {
                opcionID = ingresarOpcionInt("\nIngrese el numero de ID que desea modificar:");
                opcionID = validarDatosInt(opcionID,1,10,"Error, re-ingrese:");

                modificarEmpleado = ModificarEmployee(datosEmpleados,opcionID, 1000);
                if(modificarEmpleado == -1)
                {
                    printf("\nHubo un error al modificar los empleados.\n");
                }

                printf("\nLa lista actualizada es:\n\n");
                mostrarEmpleados = mostrarArrayEmployee(datosEmpleados, cant);
                if(mostrarEmpleados == -1)
                {
                    printf("\nHubo un error al mostrar los empleados.\n");
                }

            }
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");


            mostrarEmpleados = mostrarArrayEmployee(datosEmpleados, 15);
            if(mostrarEmpleados == -1)
            {
                printf("\nNo se ha ingresado a ningun empleado.\n\n");
            }
            else
            {
                opcionID = ingresarOpcionInt("\nIngrese el numero de ID que desea eliminar:");
                opcionID = validarDatosInt(opcionID,1,1000,"Error, re-ingrese el ID que desea eliminar:");

                eliminarEmpleado = eliminarEmployee(datosEmpleados, opcionID,cant);
                if(eliminarEmpleado == -1)
                {
                    printf("\nLa lista quedo vacia, sin empleados cargargados.\n");
                }

                printf("\n\nLa lista actualizada es:\n");
                mostrarEmpleados = mostrarArrayEmployee(datosEmpleados, cant);
                if(mostrarEmpleados == -1)
                {
                    printf("\nLa lista quedo vacia, sin empleados cargargados.\n\n");
                }
            }

            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");

            if(datosEmpleados[0].isEmpty == VACIO)
            {
                 printf("\nNo se ha ingresado a ningun empleado.\n\n");
            }
            else
            {
                printf("1.Mostrar lista alfabeticamente\n");
                printf("2.Mostrar salario promedio total y cuantos empleados los superan\n");

                ingresarOpcionChar(guardarOpcionSubMenu,"Ingrese una opcion:");
                while(validarEnteroIsdigit(guardarOpcionSubMenu)== 0)
                {
                    ingresarOpcionChar(guardarOpcionSubMenu,"Error,re-ingrese una opcion:");
                }
                opcionSubMenu = atoi(guardarOpcionSubMenu);
                opcionSubMenu = validarDatosInt(opcionSubMenu,1,2,"Error, re-ingrese la opcion(1 o 2):");

                switch(opcionSubMenu)
                {
                    case 1:
                        ordenarEmpleados = ordenarEmployeePorApellido(datosEmpleados, cant);
                        if(ordenarEmpleados == -1)
                        {
                            printf("\nhubo un error al ordenar los empleados.\n");
                        }
                        else
                        {
                            printf("\nLos empleados se han ordenado correctamente.\n");
                            printf("\nLa lista actualizada es:\n");
                            mostrarEmpleados = mostrarEmployeeOrdenados(datosEmpleados,cant);
                        }
                        break;
                    case 2:
                        sueldoTotal = guardandoSueldosEmployee(datosEmpleados, cant);
                        contadorEmployee = ContadorEmployeeAltas(datosEmpleados,cant);
                        promedioEmployee = sueldoTotal/contadorEmployee;

                        if(promedioEmployee == 0)
                        {
                            printf("\nSe ha sacado el promedio de todos los sueldos correctamente.\n");
                        }
                        else
                        {
                            printf("\nSe ha sacado el promedio de todos los sueldos correctamente.\n");
                            printf("\n| Promedio total sueldos |\n");
                            printf("            %.2f        \n",promedioEmployee);
                            printf("\n\nEmpleados que superan el sueldo total Promedio:\n");
                            empleadosPromedioTotalMas = EmployeeQueSuperanElSueldoPromedio(datosEmpleados,promedioEmployee,cant);
                            if(empleadosPromedioTotalMas !=-1)
                            {
                                printf("\n\nSe saco los promedios exitosamente.\n");
                            }

                            printf("\nlos empleados que superan el promedio son: %d\n",empleadosPromedioTotalMas);
                        }
                        break;
                }

            }
            system("pause");
            system("cls");
            break;
        case 5:
            printf("\n Saliendo del programa.\n");
            break;

    }


    return retorno;
}

//---------------------------------------INICIALIZAR , CARGAR Y MOSTRAR EMPLEADOS----------------------------------------------


int initEmpleyees(Employee* datosEmpleados, int cant)
{
    int i;
    int retorno = -1;
    if(datosEmpleados != NULL && cant > 0)
    {
        retorno =0;
        for(i=0;i<cant;i++)
        {
            datosEmpleados[i].isEmpty = VACIO;
        }
    }

    return retorno;
}

int initEmpleyeesId (Employee* datosEmpleados, int cant)
{
    int i;
    int retorno = -1;
    if(datosEmpleados != NULL && cant > 0)
    {
        retorno =0;
        for(i=0;i<cant;i++)
        {
            datosEmpleados[i].id = VACIO;
        }
    }

    return retorno;
}



Employee cargarEmpleados()
{
    Employee datosEmpleados;
    char guardarSalario[20];
    char guardarSector[20];

    printf("Ingrese el nombre del empleado:");
    fflush(stdin);
    scanf("%[^\n]", datosEmpleados.name);
    while(validarCharCadena(datosEmpleados.name)== 0)
    {
        printf("Error solo letras,re-ingrese el nombre del empleado:");
        fflush(stdin);
        scanf("%[^\n]", datosEmpleados.name);
    }

    printf("Ingrese el apellido del empleado:");
    fflush(stdin);
    scanf("%[^\n]", datosEmpleados.lastName);
    while(validarCharCadena(datosEmpleados.lastName)== 0)
    {
        printf("Error solo letras,re-ingrese el apellido del empleado:");
        fflush(stdin);
        scanf("%[^\n]", datosEmpleados.lastName);
    }

    printf("Ingrese el salario del empleado:");
    fflush(stdin);
    scanf("%s", guardarSalario);
    while(validarEnteroIsdigit(guardarSalario) == 0)
    {
        printf("Error solo numeros, re-ingrese el salario del empleado:");
        fflush(stdin);
        scanf("%s", guardarSalario);
    }

    datosEmpleados.salary = atof(guardarSalario);

    printf("Ingrese el sector del empleado:");
    fflush(stdin);
    scanf("%s", guardarSector);
    while(validarEnteroIsdigit(guardarSector) == 0)
    {
        printf("Error solo numeros,re-ingrese el sector del empleado:");
        fflush(stdin);
        scanf("%s", guardarSector);
    }

    datosEmpleados.sector = atoi(guardarSector);


    return datosEmpleados;
}

int arrayEmployee(Employee* datosEmpleados, int cant)
{
    int retorno =-1;
    int i;
    if(datosEmpleados != NULL && cant > 0)
    {
        for(i=0;i<cant;i++)
        {

            if(datosEmpleados[i].isEmpty == VACIO)
            {
                retorno = 0;
                printf("EMPLEADO ID :%d\n", i+1);
               /* datosEmpleados[i].id = i+1;
                printf("id es : %d", datosEmpleados[i].id);*/
                datosEmpleados[i]= cargarEmpleados();
                datosEmpleados[i].isEmpty = LLENO;
                break;
            }


        }
    }

    return retorno;
}


int mostrarArrayEmployee(Employee datosEmpleados[], int cant)
{
    int retorno = -1;
    int i;
    if(datosEmpleados !=NULL && cant > 0)
    {   printf("\n  ID   | NOMBRE   | APELLIDO  | SALARIO  | SECTOR \n");
        for(i=0;i<cant;i++)
        {
            if(datosEmpleados[i].isEmpty == LLENO)
            {
                retorno = 0;
                datosEmpleados[i].id = i;
             // printf("%d ",datosEmpleados[i].id);
                printf("  %-4d | %-8s | %-9s | %-9.2f| %-4d\n",datosEmpleados[i].id+1,datosEmpleados[i].name,datosEmpleados[i].lastName,datosEmpleados[i].salary,datosEmpleados[i].sector);
            }
        }
    }

    return retorno;
}

//------------------------GUARDAR SUELDO , CONTADOR ALTAS Y CUANTOS SUPERAN EL SUELDO PROMEDIO----------------------------------------------


int EmployeeQueSuperanElSueldoPromedio(Employee datosEmpleados[],float salarioPromedio, int cant)
{
    int cantidad= 0;
    int i;
    if(datosEmpleados != NULL && salarioPromedio >0 && cant > 0)
    {

        for(i=0;i<cant;i++)
        {
            if(datosEmpleados[i].salary > salarioPromedio)
            {
                cantidad++;
            }
        }
    }

    return cantidad;
}

float guardandoSueldosEmployee(Employee datosEmpleados[], int cant)
{
    float totalSueldosEmpleados =0;
    int i;

    if(datosEmpleados !=NULL && cant > 0)
    {
        for(i=0;i<cant;i++)
        {
            if(datosEmpleados[i].isEmpty == LLENO)
            {
                totalSueldosEmpleados+= datosEmpleados[i].salary;
            }
        }
    }


    return totalSueldosEmpleados;
}
int ContadorEmployeeAltas(Employee datosEmpleados[], int cant)
{
    int contadorEmployee =0;
    int i;

    if(datosEmpleados !=NULL && cant > 0)
    {

        for(i=0;i<cant;i++)
        {
            if(datosEmpleados[i].isEmpty == LLENO)
            {
                contadorEmployee++;
            }
        }
    }


    return contadorEmployee;
}




//-----------------------------------------------MODIFICAR Y ELIMINAR EMPLEADOS------------------------------------------------------------------------------------


int eliminarEmployee(Employee datosEmpleados[], int id, int cant)
{
    int retorno = -1;
    char nombre[51];
    char apellido[51];

    int i;
    if(datosEmpleados != NULL && id > 0 && cant > 0)
    {
        for(i=0;i<cant;i++)
        {
            if(datosEmpleados[i].id == id-1)
            {
                retorno = 0;
                datosEmpleados[i].isEmpty = VACIO;
                strncpy(nombre, datosEmpleados[i].name,51);
                strncpy(apellido, datosEmpleados[i].lastName,51);
                break;
            }
        }


    }

    if(retorno == 0)
    {
         printf("El empleado %s %s con el ID %d se ha eliminado correctamente.", nombre, apellido, id);
    }

    return retorno;
}

int ModificarEmployee(Employee datosEmpleados[], int id,int cant)
{
    int retorno = -1;
    int i;
    if(datosEmpleados != NULL && id > 0 && cant > 0)
    {
        for(i=0;i<cant;i++)
        {
            if(datosEmpleados[i].id == id-1)
            {
                retorno = 0;
                datosEmpleados[i].isEmpty = VACIO;
                printf("\nModificando el empleado:\n");
                datosEmpleados[i] = cargarEmpleados();
                datosEmpleados[i].isEmpty = LLENO;
                printf("\n\nEl empleado fue modificado correctamente.\n");
                break;
            }
        }
    }


    return retorno;
}

//-----------------------------------------------ORDENAR EMPLEADOS POR APELLIDO Y MOSTRAR EMPLEADOS ORDENADOS------------------------------------------------------------------------------------



int mostrarEmployeeOrdenados(Employee datosEmpleados[],int cant)
{
    int retorno=-1;
    int i;
    if(datosEmpleados != NULL && cant > 0)
    {   printf("\n NOMBRE      |  APELLIDO      |   SALARIO         |  SECTOR \n");
        for(i=0;i<cant;i++)
        {
            if(datosEmpleados[i].isEmpty == LLENO)
            {
                retorno = 0;
                printf(" %-12s| %-14s | %-14.2f    |   %-4d\n",datosEmpleados[i].name,datosEmpleados[i].lastName,datosEmpleados[i].salary,datosEmpleados[i].sector);
            }
        }
    }


    return retorno;
}


int ordenarEmployeePorApellido(Employee datosEmpleados[], int cant)
{
    int retorno = -1;
    int i,j;
    Employee auxiliarEmpleados;
    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(strcmp(datosEmpleados[i].lastName, datosEmpleados[j].lastName) > 0)
            {
                retorno =0;
                auxiliarEmpleados = datosEmpleados[i];
                datosEmpleados[i] = datosEmpleados[j];
                datosEmpleados[j] = auxiliarEmpleados;
            }
            else
            {
                //Para  si hay solo un nombre  entre y muestre la lista;
               retorno =0;
            }
        }
    }
    return retorno;
}

//-----------------------------------------------------FIN DE FUNCIONES------------------------------------------------------------------------------------



