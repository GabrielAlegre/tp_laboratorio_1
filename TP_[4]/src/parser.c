#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	char id[10];
	char horasTrabajadas[5];
	char salario[10];
	char nombre[50];
	Employee* empleado=NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, salario);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, salario)==4)
			{
				empleado=employee_newParametros(id, nombre, horasTrabajadas, salario);

				if(empleado!=NULL)
				{
					if(ll_add(pArrayListEmployee, empleado)==-1)
					{
						employee_delete(empleado);
						break;
					}
					else
					{
						todoOk=1;
					}
				}
			}
			else
			{
				break;
			}
		}
		while(!feof(pFile));
	}
	return todoOk;
}
