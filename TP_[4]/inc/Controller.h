
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
 * @fn int controller_buscarEmpleadoPorId(LinkedList*, int)
 * @brief Funcion que recorre la lista de empleados y para buscar buscar el empleado que tenga el id que esta funcion recibe como parametro
 *
 * @param pArrayListEmployee lista de empleados
 * @param idDelEmpleado id del empleado a buscar
 * @return Retorna el indice del empleado que tenga misma id que recibio la funcion como parametro o -1 en caso de haber un error
 */
int controller_buscarEmpleadoPorId(LinkedList* pArrayListEmployee, int idDelEmpleado);

/**
 * @fn int controller_EliminarEmpleadoConMayorSueldo(LinkedList*)
 * @brief funcion que busca el sueldo maximo y al primer empleado con dicho sueldo maximo para luego eliminarlo
 *
 * @param pArrayListEmployee lista de empleados
 * @return retorna 0 en caso de error o 1 si se pudo eliminar el empleado correctamente
 */
int controller_EliminarEmpleadoConMayorSueldo(LinkedList* pArrayListEmployee);
/**
 * @fn int ll_crearSubLista(LinkedList*)
 * @brief funcion que crea una subLista de la lista original
 *
 * @param pArrayListEmployee lista de empleados
 * @return retorna 0 en caso de error o 1 si se creo correctamente la sub lista
 */
int ll_crearSubLista(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_remplazarUnEmpleado(LinkedList*)
 * @brief funcion en la cual se da de alta un nuevo empleado para luego remplazar dicho empleado nuevo por uno que este en la lista
 *
 * @param pArrayListEmployee lista de empleados
 * @return retorna 0 en caso de error o 1 si se pudo remplazar el empleado correctamente
 */
int controller_remplazarUnEmpleado(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_altaEmpleadoEligiendoLugar(LinkedList*)
 * @brief funcion en la cual se da de alta a un empleado y luego le pregunta al usuario en que posicion de la lista desea colocarlo
 *
 * @param pArrayListEmployee lista de empleados
 * @return retorna 0 en caso de error o 1 en caso de exito
 */
int controller_altaEmpleadoEligiendoLugar(LinkedList* pArrayListEmployee);


