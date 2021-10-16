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

/**
 * @fn int menu()
 * @brief Funcion que muestra el menu del ABM con sus respectivas opciones.
 *
 * @return retorna la opcion elegida por el usuario.
 */
int menu();

/**
 * @fn int menuDeModificacion()
 * @brief Funcion que muestra el menu con las opciones de modificion de empleado.
 *
 * @return retorna la opcion elegida por el usuario.
 */
int menuDeModificacion();

/**
 * @fn int initEmployees(eEmployee*, int)
 * @brief Para indicar que todas las posiciones del array están vacías, esta función pone los isEmpty en TRUE(1) en todas las posiciones del array.
 *
 * @param list eEmployee* puntero al array de empleados.
 * @param len Tamanio del array de empleados.
 * @return retorna 0 si no hubo error y la funcion se realizo correctamente o -1 si hubo error y no se pudo realizar la funcion.
 */
int initEmployees(eEmployee* list, int len);

/**
 * @fn int buscarLibre(eEmployee[], int)
 * @brief Esta funcion recorre todas las posiciones del array hasta encontrar el primer indice libre (isEmpty en 1) para luego retornarlo.
 *
 * @param list eEmployee* puntero al array lista de empleados.
 * @param len Tamanio del array de empleados.
 * @return retorna el indice libre del primer empleado con isEmpty en 1 o -1 si no se encontro un indice libre o si hubo un error y nose pudo completar la funcion.
 */
int buscarLibre(eEmployee list[], int len);

/**
 * @fn int addEmployee(eEmployee*, int, int, char[], char[], float, int)
 * @brief Funcion que verifica si hay un indice libre en la lista de empleados, de haberlo, da de alta a un empleado cargando todos los campos de la estructura.
 *
 * @param list eEmployee* puntero al array de la lista de empleados.
 * @param len Tamanio del array de empleados.
 * @param id variable donde se le asignara a cada empleado su correspondiente id.
 * @param name variable donde el usuario va a cargar el nombre del empleado.
 * @param lastName variable donde el usuario va a cargar el apellido del empleado.
 * @param salary variable donde el usuario va a cargar el salario del empleado.
 * @param sector variable donde el usuario va a cargar el sector del empleado.
 * @return retorna 0 si no hubo error o -1 si la funcion no se pudo realizar correctamente.
 */
int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * @fn int findEmployeeById(eEmployee*, int, int)
 * @brief Se le pedira al usuario ingresar un id y la funcion se encargara de busca y encontra al empleado que coincida con dicha id ingresada.
 *
 * @param list array que contiene a todos los empleados, que sera recorrido hasta encontrar a la persona que coincida con el id.
 * @param len Tamanio del array de empleados.
 * @param id  variable que contiene el valor del id del empleado a buscar.
 * @return retorna el indice donde se encuntra el empleado que coincide con la id o -1 si no se encontro la persona o si la funcion no se pudo realizar correctamente.
 */
int findEmployeeById(eEmployee* list, int len,int id);

/**
 * @fn void mostrarUnEmployee(eEmployee)
 * @brief funcion que recibe la estructura de un empleado como parametro e imprime el valor de sus campos.
 *
 * @param unEmpleado estructura del empleado del cual se le implimiran sus datos.
 */
void mostrarUnEmployee(eEmployee unaPersona);

/**
 * @fn int printEmployees(eEmployee*, int)
 * @brief esta funcion busca a todos los empleados activos que se encuentren en el array e imprime sus datos.
 *
 * @param list array de empleado.
 * @param length Tamanio del array.
 * @return retorna 0 en caso de realizarse correctamente la funcion o -1 en caso de error.
 */
int printEmployees(eEmployee* list, int length);

/**
 * @fn int removeEmployee(eEmployee*, int, int)
 * @brief Elimina de manera lógica (isEmpty en 1) a un empleado atravez del numero de id que recibe como parámetro.
 *
 * @param list array que contiene a todos los empleados.
 * @param len Tamanio del array.
 * @param id El numero del id de la persona a eliminar.
 * @return retorna 0 en caso de no haber ningun error o -1 en caso de error.
 */
int removeEmployee(eEmployee* list, int len, int id);

/**
 * @fn int modifyEmployee(eEmployee*, int)
 * @brief Funcion que permite modificar los datos de un empleado atravez de un numero de id. Permitiendo modificar: Nombre, Apellido, Salario o Sector.
 *
 * @param list array que contiene a todos los empleados.
 * @param len Tamanio del array.
 * @return retorna 1 en caso de no haber ningun error o 0 en caso de error.
 */
int modifyEmployee(eEmployee* list, int len);

/**
 * @fn int sortEmployees(eEmployee*, int, int)
 * @brief Funcion que ordena el array de empleados por apellido y sector de manera descendente o ascendente segun elija el usuario.
 *
 * @param list array de empleados que sera recorrido para verificar que el empleado este ordenado correctamente segun el criterio de ordenamiento seleccionado por el usuario.
 * @param len Tamanio del array.
 * @param order criterio de ornedamiento; 1 implica ordenar de manera ascendente y 0 de manera descendente.
 * @return retorna 0 en caso de no haber ningun error o -1 en caso de error.
 */
int sortEmployees(eEmployee* list, int len, int order);

/**
 * @fn int informes(eEmployee[], int)
 * @brief funcion que contiene un subMenu con las opciones correspondientes a la opcion informar (opcion 4) del menu principal.
 *
 * @param list array de empleados.
 * @param tam Tamanio del array.
 * @return Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 */
int informes(eEmployee list[], int tam);

/**
 * @fn int PromedioYContadorSalario(eEmployee[], int)
 * @brief Funcion que calcula el total y el promedio de los salarios e informa que cantidad y cuales empleados son los que superan el salario promedio.
 *
 * @param list Array de empleados que sera recorrido para obtener el salario de cada uno de los empleado.
 * @param tam Tamanio del array.
 * @return Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 */
int PromedioYContadorSalario(eEmployee list[], int tam);

/**
 * @fn int EmpleadosQueSuperanSalarioProm(eEmployee[], int, int)
 * @brief Funcion que cuenta y muestra la cantidad de empleados que superan el salario promedio.
 *
 * @param list Array de empleados que sera recorrido para verificar que empleados cumplen con la condicion de tener un salario superior al promedio.
 * @param tam Tamanio del empleado
 * @param salarioPromedio Variable que contiene el salario promedio para luego verificar cuales son los empleados lo superen.
 * @return Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 */
int EmpleadosQueSuperanSalarioProm(eEmployee list[], int tam, int salarioPromedio);

/**
 * @fn int buscarSiHayUnEmpleado(eEmployee[], int, int*)
 * @brief Funcion que verifica si hay al menos un empleado activo (isEmpty en 0) en el array, de ser asi cambia el valor de la bandera a 1
 * de no encontrarse con ningun usuario activo (todos isEmpty en 1) en el array, el valor de la bandera sera 0.
 *
 * @param list array de empleados que sera recorrido hasta encontrar a un usuario activo.
 * @param len Tamanio del array.
 * @param banderaHayUnEmpleado en caso de encontrar al menos un empleado activo esta bandera cambiara a valor 1, volvera al valor 0 si y solo si no se encuentra ningun empleado activo en el array (todos isEmpty en 1).
 * @return Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 */
int buscarSiHayUnEmpleado(eEmployee list[], int len, int* banderaHayUnEmpleado);
