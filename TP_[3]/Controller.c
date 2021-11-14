#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "input.h"
#include "parser.h"
#include "menu.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	FILE* pArchivo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivo = fopen(path, "r");

		if(pArchivo!=NULL)
		{
			if(parser_EmployeeFromText( pArchivo, pArrayListEmployee))
			{
				printf("Se a cargado la lista con exitosamente!\n");
				todoOk=1;
			}

			fclose(pArchivo);
		}
	}
	else
	{
		printf("No se pudo cargar el archivo\n");
	}

    return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pArchivo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivo = fopen(path,"rb");

		if(pArchivo!= NULL)
		{
			if(parser_EmployeeFromBinary(pArchivo, pArrayListEmployee))
			{
				printf("Se cargo con exito el archivo binario\n");
				todoOk=1;
			}
			fclose(pArchivo);
		}
		else
		{
			printf("No se pudo cargar el archivo porque no existe u ocurrio un error al abrirse\n");
		}
	}

    return todoOk;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int seDioDeAltaUnEmpleado = 0;
    int idDelEmpleado;
    char confirmacionDeAlta;
    Employee* empleadoParaDarDeAlta=NULL;

    if(ll_isEmpty(pArrayListEmployee) >=0 && pArrayListEmployee!=NULL)
    {
        printf("--------------------------------------------------------------------------------------\n");
        printf("                           ***   Alta de Empleados   ***                              \n");
        printf("--------------------------------------------------------------------------------------\n");

        //Le pido al usuario los datos de los campos del empleado para luego asignaselo a dicho empleado
    	empleadoParaDarDeAlta = employee_AltaDeNuevoEmpleado();

    	idDelEmpleado=employee_ultimoIdParaUsar();
    	employee_setId(empleadoParaDarDeAlta, idDelEmpleado);

        if(empleadoParaDarDeAlta != NULL)
        {
        	//Muestro el empleado para buscar la confirmacion de que si lo quiere de dar de alta
            printf("\n %-10s %-15s %-15s %-15s \n","Id","Nombre","Horas","Sueldo");
            employee_mostrarUnEmpleado(empleadoParaDarDeAlta);

            validarCaracter(&confirmacionDeAlta, "Queres dar de alta a este empleado s/n?: ", "\nRespuesta invalida. 's' para confirmar. 'n' para cancelar el alta: ", 's', 'n');
            if(confirmacionDeAlta=='s')
            {
                if(!ll_add(pArrayListEmployee, empleadoParaDarDeAlta))
                {
                	seDioDeAltaUnEmpleado = 1;
                    printf("\nNuevo empleado cargado exitosamente\n");
                    employee_actualizarUltimoId(idDelEmpleado);
                }
                else
                {

					printf("\nError al cargar Empleado\n");
					employee_delete(empleadoParaDarDeAlta);
                }
            }
            else
            {
                printf("\nSe ha cancelado el ingreso del empleado\n");
                employee_delete(empleadoParaDarDeAlta);
                //Si cancela tambien cancelo el id que se le deberia haber asignado al empleado, para luego asignaselo al usuario que si confirme el alta
            }
        }
        else
        {
            printf("\nSe produjo un error al dar de alta un empleado");
        }

    }

    return seDioDeAltaUnEmpleado;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int seRealizoUnaModificacion=0;
	int idEmpleadoModificar;
	int indiceModificarEmpleado;
	char confirmacionModificacion;
	char nombreModificado[50];
	int salarioModificado;
	int horasTrabajadasModificadas;
	Employee* empleadoModificado=NULL;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                             ***   Modificar Empleado   ***                             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        //Pido id del empleado a modificar
        printf("Ingrese el ID del empleado a modificar: ");
        scanf("%d", &idEmpleadoModificar);

        //Busco el empleado atravez del id ingresado por el usuario
        indiceModificarEmpleado = controller_buscarEmpleadoPorId(pArrayListEmployee, idEmpleadoModificar);

        empleadoModificado = ll_get(pArrayListEmployee, indiceModificarEmpleado);


        if(indiceModificarEmpleado>=0 && empleadoModificado!=NULL)
        {
            printf("\n %-10s %-15s %-15s %-15s \n","Id","Nombre","Horas","Sueldo");
            employee_mostrarUnEmpleado(empleadoModificado);

            //Pido confirmacion para modificar, en caso de obtenerla le pregunto al usuario que campo del empleado desea modificar
            validarCaracter(&confirmacionModificacion, "Esta seguro que desea modificar este empleado s/n?: ", "Respuesta invalida. 's' para modificar. 'n' para cancelar la modificacion: ", 's', 'n');

            while(confirmacionModificacion=='s')
            {
            	switch(employee_menuDeModificacion())
            	{
					case 1:
						if(validarCadena(nombreModificado,"\nIngrese el nuevo nombre del empleado: ", "Nombre invalido. Ingrese el nuevo nombre del empleado: ", 50))
						{
							//Primero le asigno al empleado su nuevo nombre modificado
							employee_setNombre(empleadoModificado, nombreModificado);

							//segundo muestro el empleado actualizado, es decir, con la modificacion ya incluida
							printf("Modificacion exitosa!!!\n\nEmpleado con la modificacion actualizada:");
				            printf("\n %-10s %-15s %-15s %-15s \n","Id","Nombre","Horas","Sueldo");
				            employee_mostrarUnEmpleado(empleadoModificado);
				            seRealizoUnaModificacion=1;

				            //tercero le pregunto al usuario si quiere seguir modificando otro campo del mismo empleado
				            validarCaracter(&confirmacionModificacion, "\nDesea modificarle otro campo al mismo empleado? s/n?: ", "Respuesta invalida. 's' para modificar. 'n' para cancelar la modificacion: ", 's', 'n');

						}
						break;

					case 2:
						if(ingresoEntero(&horasTrabajadasModificadas, "\nIngrese las horas trabajadas modificadas (50 - 350): ", "Horas invalidas. Ingrese horas trabajadas modificadas (50 - 350): ", 50, 350))
						{
							employee_setHorasTrabajadas(empleadoModificado, horasTrabajadasModificadas);

							printf("Modificacion exitosa!!!\n\nEmpleado con la modificacion actualizada:");
				            printf("\n %-10s %-15s %-15s %-15s \n","Id","Nombre","Horas","Sueldo");
				            employee_mostrarUnEmpleado(empleadoModificado);
				            seRealizoUnaModificacion=1;

				            validarCaracter(&confirmacionModificacion, "\nDesea modificarle otro campo al mismo empleado? s/n?: ", "Respuesta invalida. 's' para modificar. 'n' para cancelar la modificacion: ", 's', 'n');
						}
						break;

					case 3:
						 if(ingresoEntero(&salarioModificado, "\nIngrese el salario modificado (10000 - 50000): ", "Salario invalido. Ingrese salario modificado (10000 - 50000): ", 10000, 50000))
						 {
							 employee_setSueldo(empleadoModificado, salarioModificado);

							printf("Modificacion exitosa!!!\n\nEmpleado con la modificacion actualizada:");
							printf("\n %-10s %-15s %-15s %-15s \n","Id","Nombre","Horas","Sueldo");
							employee_mostrarUnEmpleado(empleadoModificado);
							seRealizoUnaModificacion=1;

							validarCaracter(&confirmacionModificacion, "\nDesea modificarle otro campo al mismo empleado? s/n?: ", "Respuesta invalida. 's' para modificar. 'n' para cancelar la modificacion: ", 's', 'n');
						 }
						break;
					case 4:
                        printf("Se ha cancelado la modificacion\n");
                        confirmacionModificacion='n';
						break;

                    default:
                        printf("Opcion invalida!!!\n");
                        break;
            	}
            }

        }
        else
        {
            printf("No se encontro ningun empleado con id %d\n", idEmpleadoModificar);
        }

	}
    return seRealizoUnaModificacion;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int seDioDeBaja=0;
	int idEmpleadoBaja;
	int indiceDelEmpleadoParaDarBaja;
	char confirmacionBaja;
	Employee* empleadoBaja=NULL;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		printf("\n--------------------------------------------------------------------------------------\n");
		printf("                             ***   Baja de Empleado   ***                             \n");
		printf("--------------------------------------------------------------------------------------\n\n");

		//Pido id del empleado a dar de baja
		printf("Ingrese el ID del empleado al que quiera dar de baja: ");
		scanf("%d", &idEmpleadoBaja);

		//Busco el empleado atravez del id ingresado por el usuario
		indiceDelEmpleadoParaDarBaja = controller_buscarEmpleadoPorId(pArrayListEmployee, idEmpleadoBaja);

		empleadoBaja = ll_get(pArrayListEmployee, indiceDelEmpleadoParaDarBaja);


		if(indiceDelEmpleadoParaDarBaja>=0 && empleadoBaja!=NULL)
		{
			printf("\n %-10s %-15s %-15s %-15s \n","Id","Nombre","Horas","Sueldo");
			employee_mostrarUnEmpleado(empleadoBaja);

			//Pido confirmacion para dar de baja, en caso de obtenerla se dara de baja al empleado de forma definitiva
			validarCaracter(&confirmacionBaja, "Esta seguro que desea modificar este empleado s/n?: ", "Respuesta invalida. 's' para modificar. 'n' para cancelar la modificacion: ", 's', 'n');

			if(confirmacionBaja=='s')
			{
				ll_remove(pArrayListEmployee, indiceDelEmpleadoParaDarBaja);
				employee_delete(empleadoBaja);
				printf("\nEl empleado fue borrado con exito!\n");
				seDioDeBaja=1;
			}
			else
			{
				printf("\nSe cancelo la baja!\n");
			}
		}
	}
	return seDioDeBaja;
}



int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	int tam;
	Employee* empleado=NULL;

	//Verifico que no haya ninguna direccion de memoria nula y en caso de estar todo ok recorro la lista mostrando cada empleado
	if(pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);

		if(tam>=1)
		{
			printf(" %-10s %-15s %-15s %-15s \n","Id","Nombre","Horas","Sueldo");
			for (int i = 0; i < tam; ++i)
			{
				empleado = ll_get(pArrayListEmployee, i);

				if(empleado!=NULL)
				{
					employee_mostrarUnEmpleado(empleado);
				}
			}
		}
		else
		{
			printf("No hay ningun empleado que mostrar\n");
		}

	}
    return todoOk;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	int order;

	if(!ll_isEmpty(pArrayListEmployee))
	{
		//Le pido al usuario el criterio de ornamiento (Ascendente o descendente)
		ingresoEntero(&order, "\nIngrese order 1 (Ascendente) o 0 (Descendente): ", "order invalido. 1 (Ascendente) o 0 (Descendente): ", 0, 1);

		//Y le pregunto atravez de que campo desea ordenar la lista
        switch(employee_menuDeOrdenamiento())
        {
            case 1:
                ll_sort(pArrayListEmployee, employee_compararNombre, order);
                controller_ListEmployee(pArrayListEmployee);
                printf("\nSe ordeno exitosamente la lista por nombre!\n");
                break;

            case 2:
                ll_sort(pArrayListEmployee, employee_compararSueldo, order);
                controller_ListEmployee(pArrayListEmployee);
                printf("\nSe ordeno exitosamente la lista por sueldo!\n");
                break;

            case 3:
                ll_sort(pArrayListEmployee, employee_compararHorasTrabajadas, order);
                controller_ListEmployee(pArrayListEmployee);
                printf("\nSe ordeno exitosamente la lista por Horas trabajadas!\n");
                break;

            case 4:
                ll_sort(pArrayListEmployee, employee_compararId, order);
                controller_ListEmployee(pArrayListEmployee);
                printf("\nSe ordeno exitosamente la lista por id!\n");
                break;

            case 5:
            	printf("Se cancelo el ordenamiento\n");
                break;

            default:
            	printf("Opcion invalida!\n");
            	break;
        }
		todoOk=1;
	}
	else
	{
		printf("No hay ningun elemento cargado\n");
	}

    return todoOk;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk= 0;
	int id;
	char nombre[50];
	int sueldo;
	int horas;

	Employee* empleado = NULL;
	FILE* pFile;

	//Verifico que este todo ok, en caso de estarlo abro el archivo y guardo cada empleado de la lista en el archivo txt
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");

		empleado = employee_new();

		if(empleado!=NULL)
		{
			fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
			for(int i=0; i<ll_len(pArrayListEmployee); i++)
			{
				empleado = (Employee*) ll_get(pArrayListEmployee, i);
				if(empleado != NULL)
				{
					employee_getId(empleado, &id);
					employee_getNombre(empleado, nombre);
					employee_getHorasTrabajadas(empleado, &horas);
					employee_getSueldo(empleado, &sueldo);

					fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
					todoOk = 1;
				}
				else
				{
					todoOk = 0;
					break;
				}
			}
		}
		fclose(pFile);

		if(todoOk)
		{
			printf("Se ha guardado correctamente el listado!\n");
		}
	}

    return todoOk;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* pArchivo;
	Employee* unEmpleado = NULL;

	//Verifico que este todo ok, en caso de estarlo abro el archivo y guardo cada empleado de la lista en el archivo txt
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivo = fopen(path,"wb");

		if(pArchivo!= NULL && ll_len(pArrayListEmployee)>0)
		{
			for(int i=0; i<ll_len(pArrayListEmployee) ;i++)
			{
				unEmpleado = (Employee*) ll_get(pArrayListEmployee,i);

				if(unEmpleado!=NULL)
				{
					fwrite(unEmpleado,sizeof(Employee),1,pArchivo);
					todoOk=1;
				}
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}

		fclose(pArchivo);

		if(todoOk)
		{
			printf("Se ha guardado correctamente el listado!\n");
		}
	}

    return todoOk;
}

int controller_buscarEmpleadoPorId(LinkedList* pArrayListEmployee, int idDelEmpleado)
{
	int idEncontrada;
	int indiceDelEmpleadoConIdEncontrado=-1;
	int tam;
	Employee* empleado;

	//Verifico que este todo ok, en caso de estarlo averiguo el tam de la lista para luego recorrerla y tratar de encontrar el id que estoy buscando
	if(pArrayListEmployee != NULL && idDelEmpleado >= 0)
	{
		tam = ll_len(pArrayListEmployee);

		for (int i = 0; i < tam; ++i) {

			empleado = ll_get(pArrayListEmployee, i);

			if(empleado != NULL)
			{
				employee_getId(empleado, &idEncontrada);
				//Valido si es el id que busco
				if(idDelEmpleado==idEncontrada)
				{
					indiceDelEmpleadoConIdEncontrado = i; //Le retorno el indice del empleado con la id que recibio como parametro la funcion
					break;
				}
			}
		}
	}
	return indiceDelEmpleadoConIdEncontrado;
}
