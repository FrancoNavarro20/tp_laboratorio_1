#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones_tp3.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin/dat (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados falta
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto). listo
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario). listo
    10. Salir  / listo
*****************************************************/

//int FileEmployee(FILE* pFile,char* NombreArchivo,char* readWrite,Employee dataEmployee[]);

int main()
{
    LinkedList* miLista;
    LinkedList* miListaBinarios;
    miLista = ll_newLinkedList();
    miListaBinarios = ll_newLinkedList();
    int opcionMenu;
    int cargarTxt = 0;
    int cargarBinarios = 0;
    //char* opcionSalir;
    do
    {
        menu("1.Cargar los datos de los empleados(modo texto).\n2.Cargar los datos de los empleados (modo binario).\n3.Alta de empleado\n4.Modificar Empleado\n5.Baja de Empleado\n6.Listar empleados\n7.Ordenar empleados falta\n8.Guardar los datos en el archivo data.csv (modo texto)\n9.Guardar los datos en el archivo data.csv (modo binario).\n10.Salir"
             ,"\nIngrese una de las opciones:", "Error, re-ingrese la opcion:",&opcionMenu);
        switch(opcionMenu)
        {
            case 1:
                system("cls");
                if(cargarTxt == 0)
                {
                    controller_loadFromText("dataPrueba3.csv",miLista);
                    cargarTxt = 1;
                }
                else
                {
                    printf("\nSolo se puede cargar el archivo una ves\n");
                }
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                if(cargarBinarios == 0)
                {
                    controller_loadFromBinary("dataPrueba.bin",miListaBinarios);
                    cargarBinarios = 1;
                }
                else
                {
                    printf("\nSolo se puede cargar el archivo binario una ves\n");
                }
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                if(cargarTxt != 0)
                {
                    controller_addEmployee(miLista,miListaBinarios);
                }
                else
                {
                    printf("\nPara poner ingresar los todos primero cargue la lista de texto");
                }
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                if(cargarTxt !=0)
                {
                    controller_editEmployee(miLista);
                }
                else
                {
                    printf("\nPara poner modificar los todos primero cargue la lista de texto");
                }
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                if(cargarTxt != 0)
                {
                    controller_removeEmployee(miLista);
                }
                else
                {
                    printf("Primero tiene que cargar los empleados desde el archivo en formato texto con la opcion 1 y despues se mostraran\n");
                }
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                if(cargarTxt != 0)
                {
                    controller_ListEmployee(miLista);
                }
                else
                {
                    printf("Primero tiene que cargar los empleados desde el archivo en formato texto con la opcion 1 y despues se mostraran\n");
                }
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                controller_sortEmployee(miLista);
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                if(controller_saveAsText("dataPrueba3.csv",miLista)!= -1 && cargarTxt != 0)
                {
                    printf("\nLos archivos se guardaron correctamente.");
                }
                else{
                    printf("\nHubo un inconveniente y no se pudieron guardar los Archivos o puede ser que no se hayan cargado las listas en texto anteriormente\n");
                }
                system("pause");
                system("cls");
                break;
            case 9:
                system("cls");
                if(controller_saveAsBinary("dataPrueba.bin",miLista)!= -1 && cargarBinarios != 0)
                {
                    printf("\nLos archivos en binarios se guardaron correctamente.");
                }
                else
                {
                    printf("\nHubo un inconveniente y no se pudieron guardar los Archivos binarios o puede ser que no se hayan cargado las listas en binario anteriormente\n");
                }
                system("pause");
                system("cls");
                break;
            case 10:
                printf("\nSaliendo del programa\n");
                /*
                ingresarOpcionSoloUnChar(opcionSalir,"Esta seguro que desea salir del programa? si/no");
                while(opcionSalir != "si" && opcionSalir != "no")
                {
                    ingresarOpcionSoloUnChar(opcionSalir,"Esta seguro que desea salir del programa? si/no");
                }
                */
                break;
            default:
                printf("\nNinguna  de las opciones es una opcion;\n");
                //printf("Papi te ama!!no lo olvides El esta contigo!!\n");
                break;
        }

    }while(opcionMenu !=10);


    return 0;
}









 /*
    Employee datosEmpleados[1000];
    char id[100];
    char nombre[100];
    char horasTrabajadas[100];
    char sueldo[100];
    int i = 0;
    int len = 0;
    miLista = ll_newLinkedList();

    miArchivo = fopen("data.csv","r");
    if(miArchivo !=NULL)
    {
        //Lectura fantasma!!
        fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
        //fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        while(!feof(miArchivo))
        {
            fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
            datosEmpleados[i].id = atoi(id);
            datosEmpleados[i].horasTrabajadas = atoi(horasTrabajadas);
            datosEmpleados[i].sueldo = atoi(sueldo);
            strcpy(datosEmpleados[i].nombre,nombre);

            printf("%d--%s--%d--%d\n",datosEmpleados[i].id,datosEmpleados[i].nombre
                                     ,datosEmpleados[i].horasTrabajadas,datosEmpleados[i].sueldo);

            ll_add(miLista,&datosEmpleados[i]);
            i++;
        }

        fclose(miArchivo);
    }

    len = ll_len(miLista);

    printf("\n\n\nLa cantidad de empleados leidos es: %d", len);
    */
    /*
     LinkedList* miLista;
    //Employee* pEmployee;
    miLista = ll_newLinkedList();


    switch(opcion)
    {
        case 1:
            controller_loadFromText("data.csv",miLista);
            break;
    }
    */
    //pEmployee = employee_Final();

/////////////////////////////////////////////////////////////////////////////////
/*
Employee dataEmployee[1000];
    FILE* pFile;

    //FileEmployee(pMiArchivo,"data.csv","r",allEmployee);

int FileEmployee(FILE* pFile,char* NombreArchivo,char* readWrite,Employee dataEmployee[])
{

    char id[100];
    char nombre[200];
    char horasTrabajasdas[200];
    char sueldo[200];
    int i =0;

    pFile = fopen("data.csv", "r");

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,horasTrabajasdas,sueldo);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,horasTrabajasdas,sueldo);

            dataEmployee[i].id = atoi(id);
            strcpy(dataEmployee[i].nombre, nombre);
            dataEmployee[i].horasTrabajadas = atoi(horasTrabajasdas);
            dataEmployee[i].sueldo = atof(sueldo);


        i++;
        printf("%d-%s-%d-%d\n", dataEmployee[i].id, dataEmployee[i].nombre,dataEmployee[i].horasTrabajadas,dataEmployee[i].sueldo);
    }

    fclose(pFile);



    return 0;
}
*/


//Practica

    /*
  //Crear lista
    LinkedList* miLista;
    int len;
    int set;
    miLista = ll_newLinkedList();
    Employee* aux;
  //----Creando empleados---

    Employee* e1;
    Employee* e2;
    Employee* e3;
    Employee* e4;

    e1 = (Employee*) malloc(sizeof(Employee));
    e1->id = 100;
    e1->horasTrabajadas = 80;
    e1->sueldo = 80000;
    strcpy(e1->nombre, "Pedro");



    e2 = (Employee*) malloc(sizeof(Employee));
    e2->id = 153;
    e2->horasTrabajadas = 20;
    e2->sueldo = 10000;
    strcpy(e2->nombre, "Javier");

    e3 = (Employee*)malloc(sizeof(Employee));
    e3->id = 304;
    e3->horasTrabajadas = 30;
    e3->sueldo = 12000;
    strcpy(e3->nombre, "Ariel");

    e4 = (Employee*) malloc(sizeof(Employee));
    e4->id = 100;
    e4->horasTrabajadas = 255;
    e4->sueldo = 5150000;
    strcpy(e4->nombre, "Maria");


    //Agregando empleados a la lista!!
    ll_add(miLista,e1);
    ll_add(miLista,e2);
    ll_add(miLista,e3);

    //Verificando cuando empleados hay;
    len = ll_len(miLista);

    printf("cantidad de emplados: %d\n", len);

    //Mostrar Empleados!!
    showing_Employee(miLista);
    printf("\n");
    //Removiendo Empleado
    ll_remove(miLista,1);
    showing_Employee(miLista);

    len = ll_len(miLista);
    printf("la cantidad de Empleados es: %d\n\n", len);

    printf("\n");

    //SET
    set = ll_set(miLista,1,e2);

    printf("funcion set : %d\n", set);

    showing_Employee(miLista);

    len = ll_len(miLista);
    printf("la cantidad de Empleados es: %d\n\n", len);


    //PUSH
    ll_push(miLista,1,e3);

    showing_Employee(miLista);

    len = ll_len(miLista);
    printf("la cantidad de Empleados es: %d\n", len);

    //POP

    aux = ll_pop(miLista, 0);

    printf("\nEliminamos con pop: %4d %10s %8d %8d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);


    len = ll_len(miLista);

    printf("Cantidad de elementos: %d\n", len);

    showing_Employee(miLista);

    */







