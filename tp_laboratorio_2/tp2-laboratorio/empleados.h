#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

//----------------------------------------MENU Y ENTRADA A LAS OPCIONES----------------------------------------------


/** \brief te muestra el munu de opciones a las que puedes ingresar y al final la opcion de elegir a que opcion entrear
 *
 * \param No recibe parametros;
 * \return devuelve la opcion ingresada;
 *
 */

int menu();


/** \brief
 *
 * \param recibe el array de la estructura Employee
 * \param recibe la opcion de la funcion Menu();
 * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve 0 si esta todo bien y -1  si no pudo entrar a ninguna opcion
 */

int EntrarAopcionesMenu(Employee datosEmpleados[] , int opcion, int cant);

//---------------------------------------INICIALIZAR , CARGAR Y MOSTRAR EMPLEADOS----------------------------------------------


/** \brief te carga los datos de un solo empleado:
 *
 * \param no
 * \param no
 * \return devuelve los datos del empleado cargado;
 *
 */

Employee cargarEmpleados();

/** \brief  funcion para inicializar a los IsEmpty
 *
 * \param recibe el array de la estructura Employee
 * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve 0 si esta todo bien y -1  si no pudo inicializar
 *
 */

int initEmpleyees(Employee* datosEmpleados, int cant);

/** \brief funcion para inicializar a los Id
 *
 * \param  recibe el array de la estructura Employee
 * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve 0 si esta todo bien y -1  si no pudo inicializar
 *
 */
int initEmpleyeesId (Employee* datosEmpleados, int cant);

/** \brief te carga los datos de todos  los empleado de a uno;
 *
 * \param recibe el array de la estructura Employee
 * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve 0 si esta todo bien y -1  si no pudo cargar los datos
 *
 */

int arrayEmployee(Employee* datosEmpleados, int cant);

/** \brief te muestra los datos de todos  los empleado en fila;
 *
 * \param recibe el array de la estructura Employee
 * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve 0 si esta todo bien y -1 si no pudo mostrar los datos
 *
 */

int mostrarArrayEmployee(Employee datosEmpleados[], int cant);


//------------------------GUARDAR SUELDO , CONTADOR ALTAS Y CUANTOS SUPERAN EL SUELDO PROMEDIO----------------------------------------------


/** \brief te guarda la sumatoria de todos los sueldos de los empleados
 *
 * \param recibe el array de la estructura Employee
 * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve la cantidad de la sumatoria completa de los sueldos;
 *
 */

float guardandoSueldosEmployee(Employee datosEmpleados[], int cant);

/** \brief te cuenta la sumatoria de todos los empleados que estan de ALTA;
 *
 * \param recibe el array de la estructura Employee
 * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve la cantidad de empleados de ALTA como entero;
 *
 */

int ContadorEmployeeAltas(Employee datosEmpleados[], int cant);

/** \brief te dice la cantidad de empleados que superan el sueldo promedio
 *
 * \param recibe el array de la estructura Employee
 * \param recibe el salario promedio sacado de otra funcion;
 * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve la cantidad de personas que superan el sueldo promedio como entero;
 *
 */

int EmployeeQueSuperanElSueldoPromedio(Employee datosEmpleados[],float salarioPromedio, int cant);


//-----------------------------------------------MODIFICAR Y ELIMINAR EMPLEADOS----------------------------------------------

/** \brief ingresas el id de cual empleado queres modificar y podes cambiarle todos los datos para modificarlos
 *
 * \param recibe el array de la estructura Employee
 * \param recibe el id al cual queremos modificar;
 * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve 0 si esta todo bien y -1 si no pudo mostrar los datos;
 *
 */

int ModificarEmployee(Employee datosEmpleados[], int id,int cant);


/** \brief ingresas el id de cual empleado queres eliminar y automaticamente se eliminar y te muestra que empleado fue eliminado;
 *
 * \param recibe el array de la estructura Employee
 * \param recibe el id al cual queremos modificar;
  * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve 0 si esta todo bien y -1 si no pudo mostrar los datos;
 *
 */

int eliminarEmployee(Employee datosEmpleados[], int id, int cant);

//-----------------------------------------------ORDENAR EMPLEADOS POR NOMBRE Y MOSTRAR EMPLEADOS ORDENADOS------------------------------------------------------------------------------------

/** \brief Te ordena los empleados por  apellido dentro del array Employee;
 *
 * \param recibe el array de la estructura Employee
 * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve 0 si esta todo bien y -1 si no pudo mostrar los datos;
 *
 */

int ordenarEmployeePorApellido(Employee datosEmpleados[], int cant);


/** \brief te muestra los empleados ordenados por consola
 *
 * \param recibe el array de la estructura Employee
 * \param la cantidad de veces que queres que itere la estructura repetitiva
 * \return devuelve 0 si esta todo bien y -1 si no pudo mostrar los datos;
 *
 */

int mostrarEmployeeOrdenados(Employee datosEmpleados[],int cant);

#endif // EMPLEADOS_H_INCLUDED

