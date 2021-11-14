
/**
 * @fn int controller_loadFromText(char*, LinkedList*)
 * @brief funcion que se encarga de carga en la lista los empleados que contenga el archivo de txt
 *
 * @param path ubicacion del archivo a cargar
 * @param pArrayListEmployee lista de empleados
 * @return retorna 0 si hubo algun error o 1 en caso de no haber error.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/**
 * @fn int controller_loadFromBinary(char*, LinkedList*)
 * @brief funcion que se encarga de carga en la lista los empleados que contenga el archivo binario
 *
 * @param path ubicacion del archivo a cargar
 * @param pArrayListEmployee lista de empleados
 * @return retorna 0 si hubo algun error o 1 en caso de no haber error.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/**
 * @fn int controller_addEmployee(LinkedList*, int*)
 * @brief funcion que se encarga de dar de alta un empleado
 *
 * @param pArrayListEmployee lista de empleados
 * @param idMaxima variable que contiene la id maxima
 * @return retorna 0 si hubo algun error o 1 en caso haber dado de alta un empleado exitosamente.
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_editEmployee(LinkedList*)
 * @brief funcion que permite modificar los campos de un empleado
 *
 * @param pArrayListEmployee lista de empleados
 * @return retorna 0 si hubo algun error y no se pudo realizar la modificacion o 1 en caso haber modificado exitosamente al menos un campo del empleado.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_removeEmployee(LinkedList*)
 * @brief funcion que permite permite dar de baja un empleado
 *
 * @param pArrayListEmployee lista de empleados
 * @return retorna 0 si no se pudo dar de baja al empleado o 1 en caso haber dado de baja exitosamente al empleado.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_ListEmployee(LinkedList*)
 * @brief funcion que se encarga de imprimir a todos los empleados que se encuentren en la lista
 *
 * @param pArrayListEmployee lista de empleados
 * @return retorna 0 si hubo algun error o 1 en caso de no haber error.
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_sortEmployee(LinkedList*)
 * @brief funcion para ordenar los empleados
 *
 * @param pArrayListEmployee lista de empleados a ordenar
 * @return retorna 0 si hubo algun error o 1 en caso de no haber error.
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief funcion que se encarga de guardar en el archivo txt lo que contenga la lista
 *
 * @param path ubicacion del archivo
 * @param pArrayListEmployee lista de empleados
 * @return 0 si hubo algun error o 1 en caso de no haber error.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/**
 * @fn int controller_saveAsBinary(char*, LinkedList*)
 * @brief funcion que se encarga de guardar en el archivo binario lo que contenga la lista
 *
 * @param path ubicacion del archivo
 * @param pArrayListEmployee lista de empleados
 * @return 0 si hubo algun error o 1 en caso de no haber error.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


/**
 * @fn int controller_buscarEmpleadoPorId(LinkedList*, int)
 * @brief Funcion que recorre la lista de empleados y para buscar buscar el empleado que tenga el id que esta funcion recibe como parametro
 *
 * @param pArrayListEmployee lista de empleados
 * @param idDelEmpleado id del empleado a buscar
 * @return Retorna el indice del empleado que tenga misma id que recibio la funcion como parametro o -1 en caso de haber un error
 */
int controller_buscarEmpleadoPorId(LinkedList* pArrayListEmployee, int idDelEmpleado);


