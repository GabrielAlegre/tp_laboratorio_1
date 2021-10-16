/*
 * bibliotecaDeValidaciones.h
 *
 *  Created on: 15 oct. 2021
 *      Author: GabrielAlegre
 */

#ifndef BIBLIOTECADEVALIDACIONES_H_
#define BIBLIOTECADEVALIDACIONES_H_



#endif /* BIBLIOTECADEVALIDACIONES_H_ */

int validarEntero(int* enteroValidado, char mensaje[], char mensajeError[], int min, int max);
int validarFlotante(float* flotanteValidado, char mensaje[], char mensajeError[], float min, float max);
int validarCadena(char cadena[], char mensaje[], char mensajeError[], int max);
char InputChar();
int validarCaracter(char* respuesta, char mensaje[], char mensajeError[], char opcionUno, char opcionDos);
int SoloLetras(char palabra[]);
int ordenarCadena(char cadena[]);
