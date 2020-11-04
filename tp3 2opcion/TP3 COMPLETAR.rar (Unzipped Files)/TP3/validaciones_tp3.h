#ifndef VALIDACIONES_TP3_H_INCLUDED
#define VALIDACIONES_TP3_H_INCLUDED






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


/** \brief Funcion que te permite realizar un menu, que te pide una opcion y que te valida esa opcion si no es un numero.
 *
 * \param opciones[] char , texto donde podes ingresar todas las opciones que queres presentarle al usuario.
 * \param texto[] char , texto para preguntarle al usuario la opcion que quiere ingresar.
 * \param textoError[] char, texto error en el caso que se haya ingresado un dato incorrecto.
* \param opcionDevolvida *int, te devuelve la opcion validada atraves de un puntero.
 * \return int , devuelve la opcion que el usuario ingreso validada.
 *
 */
int menu(char opciones[], char texto[], char textoError[],int* opcionDevolvida);


/** \brief  funcion de validacion, valida si el dato ingresado no es un numero.
 *
 * \param opcion[] char ingresa el dato que se quiere validar
 * \param textoError[] char, el texto error en caso que el dato ingresado sea incorrecto.
 * \return int, devuelve 0 si no es un numero y -1 si esta todo correctamente.
 *
 */
int opcionErrorNumeros(char opcion[],char textoError[],int* opcionValidada);

/** \brief  funcion de validacion, valida si el dato ingresado no es una letra.
 *
 * \param opcion[] char ingresa el dato que se quiere validar
 * \param textoError[] char, el texto error en caso que el dato ingresado sea incorrecto.
 * \return int, devuelve 0 si no es un numero y -1 si esta todo correctamente.
 *
 */
int opcionErrorCadena(char opcion[],char textoError[]);

/** \brief funcion que te permite ingresar un dato flotante.
 *
 * \param texto[] char , texto donde pones lainformacion que le queres pedir al usuario.
 * \return float , devuelve la opcion ingresada.
 *
 */
float ingresarOpcionFloat(char texto[]);

/** \brief funcion que te valida el entero flotante.
 *
 * \param texto[] char, ingresamos la variable en formado de cadena para verificar si es flotante.
 * \return int, devuelve 0 si no es un flotante y -1 si la funcion no tuvo ningun problema.
 *
 */
int validarEnteroFlotante(char texto[]);

/** \brief Funcion que te permite solamente ingresar un char, solo un caracter.
 *
 * \param opcion char , la variable a la cual se le va a guardar el dato ingresado, tomado por usuario
 * \param texto[] char, el texto que queres que se le ingrese en relacion al dato que queres pedir al usuario.
 * \return void, no devuelve nada la funcion.
 *
 */
void ingresarOpcionSoloUnChar(char* opcion, char texto[]);


/** \brief funcion que te valida el entero flotante entre un maximo y un minimo
 *
 * \param dato float , el dato flotante que se quiere validar.
 * \param min float ,el dato flotante minimo con el que se quiere validar.
 * \param max float ,el dato flotante maximo con el que se quiere validar.
 * \param textoError[] char, poner texto de error en caso que se haya ingresado un dato erroneo.
 * \return float , devuelve el flotante validado entre el minimo y el maximo ingresado anteriormente.
 *
 */
float validarDatosFloat(float dato, float min, float max, char textoError[]);



int opcionErrorSexo(char opcion,char textoError[]);

int opcionErrorTipo(char opcion[],char textoError[]);


int opcionErrorNumerosFlotantes(char opcion[],char textoError[]);


int opcionErrorNumerosTipos(char opcion[],char textoError[],int* opcionValidada);

int opcionErrorNumerosSinPunteroInt(char opcion[],char textoError[]);

#endif // VALIDACIONES_TP3_H_INCLUDED
