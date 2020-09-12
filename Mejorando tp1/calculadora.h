#include <stdio.h>
#include <stdlib.h>


/** \brief La funcion pide el ingreso de un numero flotante.
 *
 * \param char texto[] ,escribe el texto correspondiente al dato que se quiere tomar.
 *
 * \return retorna el numero flotante ingresado.
 *
 */
float PedirFlotante(char texto[]);


/** \brief la funcion pide que ingreses una opcion en numeros, y te valida en que rango de numeros podes ingresarlo.
 *
 * \param int min, la cantidad minima para validar la opcion ingresada.
 * \param int max, la cantidad maxima para validar la opcion ingresada.
 * \return retorna la opcion validada.
 *
 */
int IngresarOpcion(int min, int max);



/** \brief La funcion calculadora te  realiza todas las operaciones aritmeticas de dos numeros ingresados y te da la opcion te seguir ingresando numeros o no.
 *
 * \return la funcion no retorna nada.
 *
 */
void Calculadora(void);


