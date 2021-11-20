#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Employee.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

/**
 * @fn Employee employee_new*()
 * @brief crea un nuevo empleado inicializando todos sus campos
 *
 * @return retorna el empleado nuevo
 */
Employee* employee_new();

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief crea un empleado inicializando todos sus campos con los valores que se le pasa por parametro
 *
 * @param idStr el id que se le va a asignar al empleado
 * @param nombreStr el nombre que se le va a asignar al empleado
 * @param horasTrabajadasStr las horas trabajadas que se le va a asignar al empleado
 * @param sueldoStr el sueldo que se le va a asignar al empleado
 * @return
 * @return retorna el empleado nuevo
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/**
 * @fn Employee employee_AltaDeNuevoEmpleado*()
 * @brief funcion que sera invocada a la hora de dar de alta un empleado para poder pedirle al usuario que ingrese los datos de los campos del empleado a dar de alta
 *
 * @return retorn retorna el empleado
 */
Employee* employee_AltaDeNuevoEmpleado();

/**
 * @fn int employee_delete(Employee*)
 * @brief Destructor de employee, libera de memoria dinamica y setea el puntero a NULL
 *
 * @param this empleado a eliminar
 * @return retorna 0 simbolizando error o 1 si se pudo eliminar el empleado correctamente
 */
int employee_delete(Employee* this);

/**
 * @fn int employee_setId(Employee*, int)
 * @brief Le asigna al empleado que recibe como parametro el valor de la variable que tambien recibe como parametro
 *
 * @param this el empleado al que se le va a asignar el id
 * @param id variable a asignar
 * @return retorna 0 en caso de error o 1 si esta todo ok
 */
int employee_setId(Employee* this,int id);

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief obtiene el valor de id del empleado que recibe como parametro y se lo asigna a la variable (por referencia) que tambien recibe por parametro
 *
 * @param this El empleado del cual se obtendra el valor
 * @param id variable a la cual se le asignara el id del empleado
 * @return retorna 0 en caso de error o 1 si esta todo ok
 */
int employee_getId(Employee* this,int* id);

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Le asigna al empleado que recibe como parametro el valor de la variable que tambien recibe como parametro
 *
 * @param this el empleado al que se le va a asignar el nombre
 * @param nombre variable a asignar
 * @return retorna 0 en caso de error o 1 si esta todo ok
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief obtiene el valor del nombre del empleado que recibe como parametro y se lo asigna a la variable (por referencia) que tambien recibe por parametro
 *
 * @param this El empleado del cual se obtendra el valor
 * @param nombre variable a la cual se le asignara el nombre del empleado
 * @return retorna 0 en caso de error o 1 si esta todo ok
 */
int employee_getNombre(Employee* this,char* nombre);


/**
 * @fn int employee_setId(Employee*, int)
 * @brief Le asigna al empleado que recibe como parametro el valor de la variable que tambien recibe como parametro
 *
 * @param this el empleado al que se le va a asignar las horas trabajadas
 * @param horasTrabajadas variable a asignar
 * @return retorna 0 en caso de error o 1 si esta todo ok
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief obtiene el valor de las horas trabajadas del empleado que recibe como parametro y se lo asigna a la variable (por referencia) que tambien recibe por parametro
 *
 * @param this El empleado del cual se obtendra el valor
 * @param horasTrabajadas variable a la cual se le asignara el horas Trabajadas del empleado
 * @return retorna 0 en caso de error o 1 si esta todo ok
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/**
 * @fn int employee_setId(Employee*, int)
 * @brief Le asigna al empleado que recibe como parametro el valor de la variable que tambien recibe como parametro
 *
 * @param this el empleado al que se le va a asignar el sueldo
 * @param sueldo variable a asignar
 * @return retorna 0 en caso de error o 1 si esta todo ok
 */
int employee_setSueldo(Employee* this,int sueldo);

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief obtiene el sueldo de las horas trabajadas del empleado que recibe como parametro y se lo asigna a la variable (por referencia) que tambien recibe por parametro
 *
 * @param this El empleado del cual se obtendra el valor
 * @param sueldo variable a la cual se le asignara el sueldo del empleado
 * @return retorna 0 en caso de error o 1 si esta todo ok
 */
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * @fn void employee_mostrarUnEmpleado(Employee*)
 * @brief muestra el empleado que recibe como parametro
 *
 * @param empleado empleado a mostrar
 */
void employee_mostrarUnEmpleado(Employee* empleado);

/**
 * @fn int employee_compararSueldo(void*, void*)
 * @brief compara el sueldo
 *
 * @param empUno primer empleado a comparar sueldo
 * @param empDos segundo empleado a comparar sueldo
 * @return retorna 1 si el sueldo del primer empleado es mayor al del segundo o -1 si el sueldo del primer empleado es menor al segundo
 */
int employee_compararSueldo(void* empUno, void* empDos);

/**
 * @fn int employee_compararHorasTrabajadas(void*, void*)
 * @brief compara las horas trabajadas
 *
 * @param empUno primer empleado a comparar horas trabajadas
 * @param empDos segundo empleado a comparar horas trabajadas
 * @return retorna 1 si las horas trabajadas del primer empleado es mayor al del segundo o -1 si las horas trabajadas del primer empleado es menor al segundo
 */
int employee_compararHorasTrabajadas(void* empUno, void* empDos);

/**
 * @fn int employee_compararNombre(void*, void*)
 * @brief compara los nombre
 *
 * @param empUno primer empleado a comparar nombre
 * @param empDos segundo empleado a comparar nombre
 * @return retorna 1 si el nombre del primer empleado es mayor al del segundo o -1 si el nombre empleado es menor al segundo
 */
int employee_compararNombre(void* empUno, void* empDos);

/**
 * @fn int employee_compararId(void*, void*)
 * @brief compara las id
 *
 * @param empUno primer empleado a comparar id
 * @param empDos segundo empleado a comparar id
 * @return retorna 1 si el id del primer empleado es mayor al del segundo o -1 si el id empleado es menor al segundo
 */
int employee_compararId(void* empUno, void* empDos);

/**
 * @fn int employee_reiniciarUltimoId(int)
 * @brief funcion que sera invocada cuando el usuario de alta empleados, por lo que la id se va a incrementar, pero no los guarda, por lo que el id se tiene que reiniciar al mismo valor en el que arranco
 *
 * @param unId el valor que tendra la id
 * @return retorna 1 en caso de salir todo bien o 0 en caso de error
 */
int employee_reiniciarUltimoId(int unId);

/**
 * @fn int employee_actualizarUltimoId(int)
 * @brief funcion que actualiza el archivo que contiene la id del empleado, ejemplo: si doy de alta al empleado 1001 esta funcion se encarga de actualizar el id a 1002 para cuando demos de alta al proximo empleado este tenga la id actualizada y correcta.
 *
 * @param idViejo el id que sera actualizado (se le incrementara 1)
 * @return retorna 0 en caso de error o retorna 1 en caso de salir correctamente
 */
int employee_actualizarUltimoId(int idViejo);
/**
 * @fn int employee_ultimoIdParaUsar()
 * @brief abre el archivo que contiene la id actualizada y la lee para poder retornarla
 *
 * @return retorna la ultima id para usar
 */
int employee_ultimoIdParaUsar();

#endif // employee_H_INCLUDED
