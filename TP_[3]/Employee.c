#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "input.h"
#include <string.h>

Employee* employee_new()
{
	Employee* nuevoEmpleado=NULL;

    nuevoEmpleado = (Employee*) malloc(sizeof (Employee));
    if(nuevoEmpleado != NULL)
    {
		employee_setId(nuevoEmpleado, 0);
		employee_setNombre(nuevoEmpleado, "nn");
		employee_setHorasTrabajadas(nuevoEmpleado, 0);
		employee_setSueldo(nuevoEmpleado,0);
    }

    return nuevoEmpleado;
}


Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado = NULL;
    nuevoEmpleado = employee_new();

    if(nuevoEmpleado != NULL)
    {
        if(!(employee_setId(nuevoEmpleado, atoi(idStr))
        && employee_setNombre(nuevoEmpleado, nombreStr)
        && employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))
        && employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))))
        {
        	employee_delete(nuevoEmpleado);
        }
    }
    return nuevoEmpleado;
}


//Setters
int employee_setId(Employee* this, int id)
{
    int todoOk=0;
    if(this != NULL && id>=0)
    {
        this->id = id;
        todoOk=1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=0;
    if(this != NULL && nombre!=NULL)
    {
        if(strlen(nombre)<40 && strlen(nombre)>1)
        {
            strcpy(this->nombre, nombre);
            todoOk=1;
        }
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;
    if(this != NULL && horasTrabajadas>=50 && horasTrabajadas<=350)
    {
    	this->horasTrabajadas=horasTrabajadas;
    	todoOk=1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;
    //Lo del sueldo igual a 0 es para cuando uso la funcion Employee* employee_new() que le asigna todos los campos a 0 pueda pasar la validacion
    if((this != NULL && sueldo>=10000 && sueldo <=50000) || (this != NULL && sueldo==0))
    {
        this->sueldo = sueldo;
        todoOk=1;
    }
    return todoOk;
}

//Getters
int employee_getId(Employee* this,int* id)
{

	int todoOk = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}

	return todoOk;
}


int employee_getNombre(Employee* this,char* nombre)
{
	int todoOk = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk = 1;
	}
	return todoOk;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_delete(Employee* this)
{
    int empleadoEliminado = 0;

    if(this != NULL)
    {
        free(this);
        empleadoEliminado = 1;
    }
    return empleadoEliminado;
}

Employee* employee_AltaDeNuevoEmpleado()
{
    Employee* empleado=NULL;
    int horasTrabajadas;
    int salario;
    char nombre[128];

    empleado = employee_new();

    //A la hora de dar de alta un empleado se invocara esta funcion para poder pedirle y validar los datos que ingrese el usuario
    if(empleado != NULL)
    {
        fflush(stdin);
        validarCadena(nombre,"\nIngrese el nombre del empleado: ", "Nombre invalido. Ingrese el nombre nuevamente: ", 50);
        ingresoEntero(&horasTrabajadas, "\nIngrese las horas trabajadas (50 - 350): ", "Horas invalidas. Ingrese horas trabajadas (50 - 350): ", 50, 350);
        ingresoEntero(&salario, "\nIngrese el salario (10000 - 50000): ", "Salario invalido. Ingrese salario (10000 - 50000): ", 10000, 50000);
        employee_setHorasTrabajadas(empleado, horasTrabajadas);
        employee_setNombre(empleado, nombre);
        employee_setSueldo(empleado, salario);

    }
    return empleado;
}

void employee_mostrarUnEmpleado(Employee* empleado)
{
	int id;
	char nombre[124];
	int horas;
	int sueldo;

	if(empleado != NULL )
	{
		employee_getId(empleado, &id);
		employee_getNombre(empleado, nombre);
		employee_getHorasTrabajadas(empleado, &horas);
		employee_getSueldo(empleado, &sueldo);

		printf(" %-10d %-15s %-15d %-15d \n",id, nombre, horas, sueldo);
	}
}

//Funciones para el ll_sort
int employee_compararSueldo(void* empUno, void* empDos)
{
	int retorno;
	int sueldoUno;
	int sueldoDos;
	retorno = 0;
	Employee* primerEmpleado;
	Employee* segundoEmpleado;

	primerEmpleado = (Employee*) empUno;
	segundoEmpleado = (Employee*) empDos;

	if(primerEmpleado != NULL && segundoEmpleado != NULL)
	{
		employee_getSueldo(primerEmpleado, &sueldoUno);
		employee_getSueldo(segundoEmpleado, &sueldoDos);

		if(sueldoUno > sueldoDos)
		{
			retorno=1;
		}
		else
		{
			if(sueldoUno < sueldoDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_compararHorasTrabajadas(void* empUno, void* empDos)
{
	int retorno;
	int horasUno;
	int horasDos;
	retorno = 0;
	Employee* primerEmpleado;
	Employee* segundoEmpleado;

	primerEmpleado = (Employee*) empUno;
	segundoEmpleado = (Employee*) empDos;

	if(primerEmpleado != NULL && segundoEmpleado != NULL)
	{
		employee_getHorasTrabajadas(primerEmpleado, &horasUno);
		employee_getHorasTrabajadas(segundoEmpleado, &horasDos);

		if(horasUno > horasDos)
		{
			retorno=1;
		}
		else
		{
			if(horasUno < horasDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_compararNombre(void* empUno, void* empDos)
{
	int retorno;
	char unNombre[124];
	char otroNombre[124];
	Employee* primerEmpleado;
	Employee* segundoEmpleado;

	primerEmpleado = (Employee*) empUno;
	segundoEmpleado = (Employee*) empDos;

	if(primerEmpleado != NULL && segundoEmpleado != NULL)
	{
		employee_getNombre(primerEmpleado, unNombre);
		employee_getNombre(segundoEmpleado, otroNombre);
		if(strcmp(unNombre, otroNombre)<0)
		{
			retorno = -1;
		}
		else
		{
			if(strcmp(unNombre, otroNombre)>0)
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

int employee_compararId(void* empUno, void* empDos)
{
	int retorno;
	int idUno;
	int idDos;
	retorno = 0;
	Employee* primerEmpleado;
	Employee* segundoEmpleado;

	primerEmpleado = (Employee*) empUno;
	segundoEmpleado = (Employee*) empDos;

	if(primerEmpleado != NULL && segundoEmpleado != NULL)
	{
		employee_getId(primerEmpleado, &idUno);
		employee_getId(segundoEmpleado, &idDos);

		if(idUno > idDos)
		{
			retorno=1;
		}
		else
		{
			if(idUno < idDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_ultimoIdParaUsar()
{
	int ultimoId;
	char ultimoIdStr[100];

	FILE* pFile = fopen("ultimoId.txt", "r");

	if(pFile != NULL)
	{
		fscanf(pFile, "%[^\n]", ultimoIdStr);

		ultimoId = atoi(ultimoIdStr);
	}
	fclose(pFile);

	return ultimoId;
}


int employee_actualizarUltimoId(int idViejo)
{
	int todoOk = 0;

	FILE* pFile = fopen("ultimoId.txt", "w");

	if(pFile != NULL)
	{
		fprintf(pFile, "%d\n", idViejo+1);
		todoOk = 1;
	}
	fclose(pFile);

	return todoOk;
}

int employee_reiniciarUltimoId(int unId)
{
	int todoOk = 0;

	FILE* pFile = fopen("ultimoId.txt", "w");

	if(pFile != NULL)
	{
		fprintf(pFile, "%d\n", unId);
		todoOk = 1;
	}
	fclose(pFile);

	return todoOk;
}

