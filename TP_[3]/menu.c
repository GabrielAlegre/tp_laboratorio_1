#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
    int opcion;
    system("cls");
    printf("--------------------------------------------------------------------------------------\n");
    printf("                      *** Menu Employee ***            \n");
    printf("--------------------------------------------------------------------------------------\n\n");
    printf("1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2- Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3- Alta de empleados\n");
    printf("4- Modificar datos de empleado\n");
    printf("5- Baja de empleado\n");
    printf("6- Listar empleados\n");
    printf("7- Ordenar Empleados\n");
    printf("8- Guardar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("9- Guardar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("10- Salir\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);
    fflush(stdin);

    return opcion;
}

int employee_menuDeModificacion()
{
    int opcion;

    printf("\nQue le desea modificar al empleado: \n");
    printf("1- Modificar Nombre\n");
    printf("2- Modificar Horas de trabajo \n");
    printf("3- Modificar Sueldo\n");
    printf("4- Cancelar Modificacion\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);


    return opcion;
}

int employee_menuDeOrdenamiento()
{
    int opcion;

    printf("\nComo desea ordenar la lista?: \n");
    printf("1- Ordenar por Nombre\n");
    printf("2- Ordenar por Sueldo \n");
    printf("3- Ordenar por Horas trabajadas\n");
    printf("4- Ordenar por Id\n");
    printf("5- Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    printf("Ordenando lista, por favor espere......\n");

    return opcion;
}
