/*
 * ArrayEmployees.h
 *
 *  Created on: 15 oct. 2021
 *      Author: GabrielAlegre
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
     int id;
     char name[51];
     char lastName[51];
     float salary;
     int sector;
     int isEmpty;

} eEmployee;


#endif /* ARRAYEMPLOYEES_H_ */

int menu();

int initEmployees(eEmployee* list, int len);

int buscarLibre(eEmployee list[], int len);

int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);

int findEmployeeById(eEmployee* list, int len,int id);

void mostrarUnEmployee(eEmployee unaPersona);

int printEmployees(eEmployee* list, int length);

int removeEmployee(eEmployee* list, int len, int id);

int modifyEmployee(eEmployee* list, int len);

int menuDeModificacion();

int sortEmployees(eEmployee* list, int len, int order);

int informes(eEmployee list[], int tam);

int PromedioYContadorSalario(eEmployee list[], int tam);

int buscarSiHayUnEmpleado(eEmployee list[], int len, int* banderaHayUnEmpleado);

int EmpleadosQueSuperanSalarioProm(eEmployee list[], int tam, int salarioPromedio);
