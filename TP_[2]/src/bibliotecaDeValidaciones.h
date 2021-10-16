/*
 * bibliotecaDeValidaciones.h
 *
 *  Created on: 15 oct. 2021
 *      Author: GabrielAlegre
 */

#ifndef BIBLIOTECADEVALIDACIONES_H_
#define BIBLIOTECADEVALIDACIONES_H_



#endif /* BIBLIOTECADEVALIDACIONES_H_ */
/**
 * @fn int validarEntero(int*, char[], char[], int, int)
 * @brief funcion que permite pedir un numero entero y a su vez validarlo.
 *
 * @param enteroValidado Puntero a entero que se le asignara el valor del numero ya validado.
 * @param mensaje Cadena de caracteres que contiene el mensaje que le aparecera al usuario al momento de pedir un numero entero.
 * @param mensajeError Cadena de caracteres que contiene un mensaje de error que le aparecera al usuario al momento de ingresar un numero entero invalido.
 * @param min Valor minimo que debe tener el numero entero.
 * @param max Valor maximo que debe tener el numero entero.
 * @return Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 */
int validarEntero(int* enteroValidado, char mensaje[], char mensajeError[], int min, int max);

/**
 * @fn int validarFlotante(float*, char[], char[], float, float)
 * @brief Funcion que permite pedir un numero flotante y a su vez validarlo.
 *
 * @param flotanteValidado Puntero a float al cual se le asignara el valor del numero ya validado segun los parametros min y max.
 * @param mensaje Cadena de caracteres que contiene el mensaje que le aparecera al usuario al momento de pedir un numero flotante.
 * @param mensajeError Cadena de caracteres que contiene un mensaje de error que le aparecera al usuario al momento de ingresar un numero flotante invalido.
 * @param min Valor minimo que debe tener el numero flotante.
 * @param max Valor maximo que debe tener el numero entero.
 * @return Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 */
int validarFlotante(float* flotanteValidado, char mensaje[], char mensajeError[], float min, float max);

/**
 * @fn int validarCadena(char[], char[], char[], int)
 * @brief Funcion que recibe una cadena de caracteres (por ejemplo un nombre) y lo valida verificando que esta no tenga mas caracteres de los permitidos y que no contenga ningun numero.
 *
 * @param cadena Cadena de caracteres a validar.
 * @param mensaje Mensaje que le aparecera al usuario al momento de pedir una cadena de caracteres.
 * @param mensajeError Mensaje de error que le aparecera al usuario al momento de ingresar un string invalido, por ejemplo si ingresa un string con mas caracteres de los permitidos.
 * @param max la cantidad maxima de caracteres que puede llegar a tener la cadena de caracteres.
 * @return Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 */
int validarCadena(char cadena[], char mensaje[], char mensajeError[], int max);

/**
 * @fn int validarCaracter(char*, char[], char[], char, char)
 * @brief Funcion que le pide al usuario un char y valida que dicho char este dentro de las 2 opciones recibidas en el parametro.
 *	por ejemplo, si quiero verificar que el usuario ingrese s/n la opcion1 va a ser 's' y la opcion2 'n', si el char ingresado
 *	no coincide con ninguna de las dos opciones le aparecera el mensaje de error hasta que lo ingrese correctamente.
 *
 * @param respuesta Char a verificar.
 * @param mensaje Mensaje que le aparecera al usuario al momento de pedir el char.
 * @param mensajeError Mensaje de error que le aparecera al usuario al momento de ingresar un caracter invalido.
 * @param opcionUno primera opcion que puede ingresar el usuario.
 * @param opcionDos segunda opcion que puede ingresar el usuario.
 * @return Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 */
int validarCaracter(char* respuesta, char mensaje[], char mensajeError[], char opcionUno, char opcionDos);
/**
 * @fn int SoloLetras(char[])
 * @brief verifica que una cadena de caracteres (por ejemplo un nombre) contenga solo letras.
 *
 * @param palabra Cadena de caracteres a validar que contenga solo letras.
 * @return Retorna 1 si se verifica que la palabra solo contiene letras y retorna 0 si la palabra contiene algo distinto a solo letras.
 */
int SoloLetras(char palabra[]);

/**
 * @fn int ordenarCadena(char[])
 * @brief funcion que "ordena" una cadena de caracteres. Por ejemplo, si ingresa: "dAniEl sEbAStiAn" la funcion lo ordena a: "Daniel Sebastian"
 *
 * @param cadena Cadena de caracteres a ordenar.
 * @return
 */
int ordenarCadena(char cadena[]);
