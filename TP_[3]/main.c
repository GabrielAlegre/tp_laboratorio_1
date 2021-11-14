#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"
#include "parser.h"
#include "menu.h"
int main()
{
	setbuf(stdout, NULL);

	char salir='n';
	int cargoLista=0;
	int dioAlMenosUnAlta=0;
	char ConfirmaGuardarTxt;
	int guardoLista=0;
	int modificoLista=0;
	int idInicializado=employee_ultimoIdParaUsar();//Inicializo el id con 1001

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
            	if(cargoLista==1)
            	{
            		printf("Ya cargo la lista, no se puede cargarla 2 veces la lista\n");
            	}
            	else
            	{
            		printf("Cargando lista...\n");
            		printf("La lista puede tardar unos segundos en cargar, por favor espere...\n");
					if(controller_loadFromText("data.csv",listaEmpleados))
					{
						cargoLista=1;

					}
            	}
                break;

            case 2:
            	if(cargoLista==1)
            	{
            		printf("Ya cargo la lista, no se puede cargarla 2 veces la lista\n");
            	}
            	else
            	{
            		if(controller_loadFromBinary("data.bin", listaEmpleados))
					{
						cargoLista=1;

					}
            	}
                break;

            case 3:
				if(controller_addEmployee(listaEmpleados))
				{
					dioAlMenosUnAlta=1;
					modificoLista=1;
				}
                break;

            case 4:
				if(dioAlMenosUnAlta || cargoLista)
				{
					controller_editEmployee(listaEmpleados);
					modificoLista=1;
				}
				else
				{
					printf("No hay empleados para modificar\n");
				}
                break;

            case 5:
				if(dioAlMenosUnAlta || cargoLista)
				{
					controller_removeEmployee(listaEmpleados);
					modificoLista=1;
				}
				else
				{
					printf("No hay empleados para dar de baja\n");
				}
                break;

            case 6:
				if(dioAlMenosUnAlta || cargoLista)
				{
					controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("No hay empleados para listar\n");
				}
                break;

            case 7:
				if(dioAlMenosUnAlta || cargoLista)
				{
					controller_sortEmployee(listaEmpleados);

				}
				else
				{
					printf("No hay empleados para ordenar\n");
				}
                break;

            case 8:
            	if(dioAlMenosUnAlta==0 && cargoLista==0)
            	{
            		printf("No se puede guardar la lista sin cargarla o dar de alta al menos un empleado\n");
            	}
            	else
            	{
            		if(modificoLista==1)
            		{
            			validarCaracter(&ConfirmaGuardarTxt, "Usted modifico la lista, esta seguro que desea guardarla? Si guarda se sobreescribiran todos los datos (s/n): ", "Respuesta invalida. 's' para confirmar guardar. 'n' para cancelar: ", 's', 'n');
                    	if(ConfirmaGuardarTxt=='s')
                    	{
                    		controller_saveAsText("data.csv", listaEmpleados);
                    		guardoLista=1;
                    	}
                    	else
                    	{
                    		printf("Se cancelo guardar la lista\n");
                    	}
            		}
                	else
                	{
                		printf("Se le van a guardar los mismos datos que recibio\n");
                		controller_saveAsText("data.csv", listaEmpleados);
                	}
            	}
                break;

            case 9:
            	if(dioAlMenosUnAlta==0 && cargoLista==0)
            	{
            		printf("No se puede guardar la lista sin cargarla o dar de alta al menos un empleado\n");
            	}
            	else
            	{
                	controller_saveAsBinary("data.bin", listaEmpleados);
                	guardoLista=1;
            	}
                break;

            case 10:
            	if(dioAlMenosUnAlta==1 && guardoLista==0)
            	{
            		validarCaracter(&salir, "Esta seguro que desea salir sin antes guardar la lista? s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
            		if(salir=='s')
            		{
            			employee_reiniciarUltimoId(idInicializado);
            			ll_deleteLinkedList(listaEmpleados);
            		}
            	}
            	else
            	{
            		validarCaracter(&salir, "Esta seguro que desea salir? s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
            		ll_deleteLinkedList(listaEmpleados);
            	}

                break;

            default:
			printf("Opcion invalida!\n");
				break;

        }

    }while(salir=='n');

    return 0;
}

