/*
 * miBibliotecaAlegre.h
 *
 *  Created on: 22 sep. 2021
 *      Author: GabrielAlegre
 */

#ifndef MIBIBLIOTECAALEGRE_H_
#define MIBIBLIOTECAALEGRE_H_

#endif /* MIBIBLIOTECAALEGRE_H_ */

/**
 * @fn int funcionMenu(float, float, int, int)
 * @brief Funcion que muestra el menu de la calculadora con sus respectivas opciones. Cada vez que el usario ingrese un numero el menu se actualizara con los valores actuales cargados en los operandos a y b.
 *
 * @param x Primer operando que ingresa el usario para luego cargarlo en el menu.
 * @param y Segundo operando que ingresa el usario para luego cargarlo en el munu.
 * @param banderaPrimerOperador flag que se utiliza para saber si el usuario ya ingreso el primer operando, de ser asi esta estara cargada con 1, y se mostrara el valor del primer operando en el menu.
 * @param banderaSegundoOperador flag que se utiliza para saber si el usuario ya ingreso el segundo operando, de ser asi esta estara cargada con 1, y se mostrara el valor del segundo operando en el menu.
 * @return retorna la opcion elegida por el usuario.
 */
int funcionMenu(float x, float y, int banderaPrimerOperador, int banderaSegundoOperador);

/**
 * @fn float funcionSumar(float, float)
 * @brief Funcion que realiza la suma de dos operandos (x siendo el primer operando e y el segundo operando).
 *
 * @param x Primer operando a sumar.
 * @param y Segundo operando a sumar.
 * @return Retorna el resultado de la suma de x e y.
 */
float funcionSumar(float x, float y);

/**
 * @fn float funcionRestar(float, float)
 * @brief Funcion que realiza la resta de dos operandos (x siendo el primer operando e y el segundo operando).
 *
 * @param x Primer operando a restar.
 * @param y Segundo operando a restar.
 * @return Retorna el resulado de la resta de x e y.
 */
float funcionRestar(float x, float y);

/**
 * @fn float funcionMultiplicar(float, float)
 * @brief Funcion que realiza la multiplicacion de dos operandos (x siendo el primer operando e y el segundo operando).
 *
 * @param x Primer operando a multiplicar.
 * @param y Segundo operando a multiplicar.
 * @return Retorna el resultado de la multiplicacion de x e y
 */
float funcionMultiplicar(float x, float y);

/**
 * @fn int funcionDividir(float, float, float*)
 * @brief Funcion que realiza la division de dos operandos (x siendo el primer operando e y el segundo operando).
 *
 * @param x Primer operando ingresado por el usuario, el cual sera el numerador de la division.
 * @param y Segundo operando ingresado por el usuario, el cual sera el denominador de la division.
 * @param pResultadoDeLaDivision puntero a float que recibe una direccion de memoria para luego escribir el resultado de la divison en ella.
 * @return retorna un 1 si se pudo realizar la division correctamente, de no ser asi y no poder realizarse la division se retornara un 0.
 */
int funcionDividir(float x, float y, float* pResultadoDeLaDivision);

/**
 * @fn int funcionFactorial(float, int*)
 * @brief Funcion que realiza el factorial de un numero solo si este es un numero positivo y entero.
 *
 * @param numeroIngresado numero al cual se le realizara el factorial.
 * @param resultadoFactorial puntero a entero que recibe una direccion de memoria para luego escribir el resultado del factorial en ella.
 * @return retorna un 1 si se pudo realizar el factorial del numero ingresado, de no ser y no poder realizar el factorial se retornara un 0.
 */
int funcionFactorial(float numeroIngresado, int* pResultadoFactorial);

/**
 * @fn int realizarOperaciones(float, float, float*, float*, float*, int*, int*, float*, int*, int*, int*)
 * @brief funcion donde se realizan todas las operaciones pedidas.
 *
 * @param x primer operando ingresado por el usuario con el que luego se realizaran las operacion.
 * @param y segundo operando ingresado por el usuario con el que luego se realizaran las operacion.
 * @param suma puntero a float que recibe la direccion de memoria de la variable "suma" declarada en el main para luego escribir el resultado de la suma en ella.
 * @param resta puntero a float que recibe una direccion de memoria para luego escribir el resultado de la resta en ella.
 * @param division puntero a float que recibe una direccion de memoria para luego escribir el resultado de la division en ella.
 * @param factorialDeA puntero a entero que recibe una direccion de memoria para luego escribir el resultado del factorial de x en ella.
 * @param factorialDeB puntero a entero que recibe una direccion de memoria para luego escribir el resultado del factorial de y en ella.
 * @param multiplicacion puntero a float que recibe una direccion de memoria para luego escribir el resultado de la multiplicacion en ella.
 * @param sePudoDividir guarda el retorno de la llamada a la "funcionDividir", se carga con 1 si se pudo realizar correctamente la division o con 0 si no se pudo realizar la operacion.
 * @param seHizoFactorialDeA guarda el retorno de la llamada a la "funcionFactorial", se carga con 1 si se pudo realizar correctamente el factorial de A o con 0 si no se pudo realizar la operacion.
 * @param seHizoFactorialDeB guarda el retorno de la llamada a la "funcionFactorial", se carga con 1 si se pudo realizar correctamente el factorial de B o con 0 si no se pudo realizar la operacion.
 * @return retorna un 1 si la funcion se realizo correctamente o un 0 si no se pudo realizar.
 */
int realizarOperaciones(float x, float y, float*suma, float*resta, float*division, int*factorialDeA, int*factorialDeB, float*multiplicacion, int*sePudoDividir, int*seHizoFactorialDeA, int*seHizoFactorialDeB);

/**
 * @fn void informarResultados(float, float, float, float, float, int, int, float, int, int, int)
 * @brief funcion que informa los resultados de las operaciones solo si corresponde.
 *
 * @param x el primer operando ingresado por el usuario.
 * @param y el segundo operando ingresado por el usuario.
 * @param suma contiene el resultado de la suma de x e y para luego informarla.
 * @param resta contiene el resultado de la resta de los operandos x e y para luego informarla.
 * @param division contiene el resultado de la division de x e y para luego informarlo.
 * @param factorialDeA contiene el resultado del factorial del primer operando (x) para luego informarlo.
 * @param factorialDeB contiene el resultado del factorial del segundo operando (y) para luego informarlo.
 * @param multiplicacion contiene el resultado de la multiplicacion de los operando x e y para luego informarlo.
 * @param sePudoDividir variable que viene cargada con 0 o 1, si esta cargada con 1 significa que se realizo correctamente la division y por lo tanto se informara el resultado de la misma, en caso contrario, estara cargada con 0 y se informara que no se pudo realizar la operacion.
 * @param seHizoFactorialDeA variable que viene cargada con el valor 0 o 1, si esta cargada con 1 significa que se realizo correctamente el factorial y por lo tanto se informara el resultado del factorial de A, en caso contrario, estara cargada con 0 y se informara que no se pudo realizar la operacion.
 * @param seHizoFactorialDeB variable que viene cargada con el valor 0 o 1, si esta cargada con 1 significa que se realizo correctamente el factorial y por lo tanto se informara el resultado del factorial de B, en caso contrario, estara cargada con 0 y se informara que no se pudo realizar la operacion.
 */
void informarResultados(float x, float y, float suma, float resta, float division, int factorialDeA, int factorialDeB, float multiplicacion, int sePudoDividir, int seHizoFactorialDeA, int seHizoFactorialDeB);
