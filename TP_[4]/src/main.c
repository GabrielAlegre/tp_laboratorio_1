/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Employee.h"
#include "../inc/input.h"
#include "../inc/parser.h"
#include "../inc/menu.h"

// Indice de donde utilice todas las funciones de la linkedlist:

// ll_newLinkedList - utilizada en el main.c linea 65
// ll_len - la utilice muchas veces por ejemplo: en el controller.c linea 713
// getNode - test_getNode
// addNode - test_addNode
// ll_add - utilizada en el controller.c linea 293
// ll_get - la utilice muchas veces por ejemplo: en el controller.c linea 348 o linea 452
// ll_set - utilizada en el controller.c linea 160
// ll_remove - utilizada en el controller.c linea 465
// ll_clear - utilizada en el main.c linea 104
// ll_deleteLinkedList - la utilice muchas veces por ejemplo: utilizada en el main.c linea 275 o en el controller.c linea 571
// ll_indexOf - utilizada en el controller.c linea 80
// ll_isEmpty - la utilice muchas veces por ejemplo: en el controller.c linea 117
// ll_push - utilizada en el controller.c linea 239
// ll_pop - use controller.c linea 88
// ll_contains - utilizada en el controller.c linea 147 o linea 458
// ll_containsAll - utilizada en el controller.c linea 534
// ll_subList - utilizada en el controller.c linea 631
// ll_clone - utilizada en el controller.c linea 531
// ll_sort - utilizada en el controller.c linea 543

int main(void)
{
	setbuf(stdout, NULL);
	char salir='n';
	int cargoLista=0;
	int dioAlMenosUnAlta=0;
	int altasNoGuardadas=0;
	char confirmaGuardarTxt;
	char confirmaReiniciarLista;
	int guardoLista=0;

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
				if(dioAlMenosUnAlta || cargoLista)
				{
					controller_EliminarEmpleadoConMayorSueldo(listaEmpleados);
				}
				else
				{
					printf("Primero debe dar de alta al menos un empleado o cargar la lista\n");
				}
				break;

			case 3:
				if(cargoLista==1)
				{
					validarCaracter(&confirmaReiniciarLista, "Esta seguro que desea reiniciar la lista (se le eliminaran todos los elementos)?  (s/n): ", "Respuesta invalida. 's' para confirmar reiniciado. 'n' para cancelar: ", 's', 'n');
					if(confirmaReiniciarLista=='s')
					{
						if(ll_clear(listaEmpleados)==0)
						{
							printf("Se reinicio la lista correctamente\n");

						}
						else
						{
							printf("No se pudo reiniciar la lista correctamente\n");
						}
					}
					else
					{
						printf("Se cancelo correctamente la reinicializacion\n");
					}
				}
				else
				{
					printf("Primero debe cargar la lista para poder reiniciarla\n");
				}
				break;

			case 4:
				if(dioAlMenosUnAlta || cargoLista)
				{
					ll_crearSubLista(listaEmpleados);
				}
				else
				{
					printf("Primero debe dar de alta al menos un empleado o cargar la lista\n");
				}
				break;

			case 5:

				if(dioAlMenosUnAlta || cargoLista)
				{
					controller_remplazarUnEmpleado(listaEmpleados);
				}
				else
				{
					printf("Primero debe dar de alta al menos un empleado o cargar la lista\n");
				}

				break;

			case 6:
				if(controller_addEmployee(listaEmpleados))
				{
					dioAlMenosUnAlta=1;
					altasNoGuardadas++;
				}
				break;

			case 7:
				if(dioAlMenosUnAlta || cargoLista)
				{
					controller_editEmployee(listaEmpleados);

				}
				else
				{
					printf("No hay empleados para modificar\n");
				}
				break;

			case 8:
				if(dioAlMenosUnAlta || cargoLista)
				{
					controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("No hay empleados para dar de baja\n");
				}
				break;

			case 9:
				if(dioAlMenosUnAlta || cargoLista)
				{
					controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("No hay empleados para listar\n");
				}
				break;

			case 10:
				if(dioAlMenosUnAlta || cargoLista)
				{
					controller_sortEmployee(listaEmpleados);

				}
				else
				{
					printf("No hay empleados para ordenar\n");
				}
				break;

			case 11:
				if(dioAlMenosUnAlta || cargoLista)
				{
					if(controller_altaEmpleadoEligiendoLugar(listaEmpleados))
					{
						dioAlMenosUnAlta=1;
						altasNoGuardadas++;
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un empleado o cargar la lista\n");
				}
				break;

			case 12:
				if(dioAlMenosUnAlta==0 && cargoLista==0)
				{
					printf("No se puede guardar la lista sin antes cargarla o dar de alta al menos un empleado\n");
				}
				else if(cargoLista && altasNoGuardadas>0)
				{
					validarCaracter(&confirmaGuardarTxt, "Usted modifico la lista, esta seguro que desea guardarla? Si guarda se sobreescribiran todos los datos (s/n): ", "Respuesta invalida. 's' para confirmar guardar. 'n' para cancelar: ", 's', 'n');
					if(confirmaGuardarTxt=='s')
					{
						controller_saveAsText("data.csv", listaEmpleados);
						guardoLista++;
						//Si guarda lista, las altas no guardadas se reinician
						altasNoGuardadas=0;
					}
					else
					{
						printf("Se cancelo guardar la lista\n");
					}
				}
				else if (cargoLista==0 && dioAlMenosUnAlta)
				{
					printf("AVISO, no cargo la lista, todo lo que haya en ella se sobreescribiran por los %d empleados nuevos que cargo\n", altasNoGuardadas);
					validarCaracter(&confirmaGuardarTxt, "Esta seguro que desea guardar?  (s/n): ", "Respuesta invalida. 's' para confirmar guardar. 'n' para cancelar: ", 's', 'n');
					if(confirmaGuardarTxt=='s')
					{
						controller_saveAsText("data.csv", listaEmpleados);
						guardoLista++;
						//Si guarda lista, las altas no guardadas se reinician
						altasNoGuardadas=0;
					}
					else
					{
						printf("Se cancelo guardar la lista\n");
					}
				}
				else
				{
					printf("No hay nada que guardar, en la lista estan los mismos datos que antes\n");
				}

				break;

			case 13:

				if(altasNoGuardadas>0 && cargoLista)
				{
					printf("AVISO: dio de alta a %d nuevos empleados y no los guardo, ", altasNoGuardadas);
					validarCaracter(&salir, "Esta seguro que desea salir? s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
					if(salir=='s')
					{
						ll_deleteLinkedList(listaEmpleados);
						printf("Salida exitosa!\n");
					}
				}
				else
				{
					validarCaracter(&salir, "Esta seguro que desea salir? s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
					ll_deleteLinkedList(listaEmpleados);
					printf("Salida exitosa!\n");
				}
				break;

			default:
			printf("Opcion invalida!\n");
				break;
		}

	}while(salir=='n');

	/*
	startTesting(1); // ll_newLinkedList - utilizada en el main.c linea 65
	startTesting(2); // ll_len - la utilice muchas veces por ejemplo: en el controller.c linea 713
	startTesting(3); // getNode - test_getNode
	startTesting(4); // addNode - test_addNode
	startTesting(5); // ll_add - utilizada en el controller.c linea 293
	startTesting(6); // ll_get - la utilice muchas veces por ejemplo: en el controller.c linea 348 o linea 452
	startTesting(7); // ll_set - utilizada en el controller.c linea 160
	startTesting(8); // ll_remove - utilizada en el controller.c linea 465
	startTesting(9); // ll_clear - utilizada en el main.c linea 104
	startTesting(10);// ll_deleteLinkedList - la utilice muchas veces por ejemplo: utilizada en el main.c linea 275 o en el controller.c linea 571
	startTesting(11);// ll_indexOf utilizada en el controller.c linea 80
	startTesting(12);// ll_isEmpty la utilice muchas veces por ejemplo: en el controller.c linea 117
	startTesting(13);// ll_push utilizada en el controller.c linea 239
	startTesting(14);// ll_pop use controller.c linea 88
	startTesting(15);// ll_contains utilizada en el controller.c linea 147 o linea 458
	startTesting(16);// ll_containsAll utilizada en el controller.c linea 534
	startTesting(17);// ll_subList utilizada en el controller.c linea 631
	startTesting(18);// ll_clone utilizada en el controller.c linea 531
	startTesting(19);// ll_sort utilizada en el controller.c linea 543
	*/

	//Aclaracion: Cuando me descargue la cascara del tp ya me vino con warnings incluidos en la carpeta de testing, intente solucionarlos y no supe como.

    return 0;
}
