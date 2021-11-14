#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/*
 * parser.h
 *
 *  Created on: 11 nov. 2021
 *      Author: GabrielAlegre
 */

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */

/**
 * @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
 * @brief Parsea los datos de los empleados desde el archivo data.txt (modo texto).
 *
 * @param pFile ubicacion del archivo
 * @param pArrayListEmployee lista de empleados
 * @return retorna 0 si hubo algun error o 1 en caso de no haber error.
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/**
 * @fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
 * @brief Parsea los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * @param pFile ubicacion del archivo
 * @param pArrayListEmployee lista de empleados
 * @return retorna 0 si hubo algun error o 1 en caso de no haber error.
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
