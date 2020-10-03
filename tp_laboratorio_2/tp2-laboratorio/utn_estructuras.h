#ifndef UTN_ESTRUCTURAS_H_INCLUDED
#define UTN_ESTRUCTURAS_H_INCLUDED

/** \brief te pide un numero;
 *
 * \param texto : podes escribir el texto que vos quieras
 * \return devuelve la opcion que se ingreso
 *
 */

int ingresarOpcionInt(char texto[]);

/** \brief valida un numero entre rangos minimos y maximos;
 *
 * \param dato: recibe el dato a validar
 * \param min : es el rango minimo a validar;
 * \param max : es el rango maximo a validar;
 * \param textoError: ingresar un texto erroneo si el usuario se equivo al ingresar la opcion;
 * \return devuelve el dato validado
 */
int validarDatosInt(int dato, int min , int max, char textoError[]);

/** \brief recibe una cadena y te valida si lo que ingresaste es o no letras;
 *
 * \param texto: la cadena a validar
 * \return devuelve 0 si no es una letra y 1 si es una letra
 *
 */

int validarCharCadena(char texto[]);


/** \brief  recibe una cadena y te valida si lo que ingresaste es o no digitos;
 *
 * \param texto: la cadena a validar
 * \return devuelve 0 si no es una letra y 1 si es un digito
 *
 */

int validarEnteroIsdigit(char texto[]);



/** \brief te pide que ingreses una cadena de caracteres
 *
 * \param opcion : va a ser el lugar donde se va a guardar la cadena
 * \param texto : el texto que se le quiera poner dentro del printf;
 * \return no devuelve nada;
 *
 */

void ingresarOpcionChar(char opcion[], char texto[]);


#endif // UTN_ESTRUCTURAS_H_INCLUDED
