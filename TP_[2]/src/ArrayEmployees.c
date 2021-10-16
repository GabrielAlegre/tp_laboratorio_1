/*
 * ArrayEmployees.c
 *
 *  Created on: 15 oct. 2021
 *      Author: GabrielAlegre
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "bibliotecaDeValidaciones.h"
#include <string.h>



int menu()
{
    int opcion;
    system("cls");
    printf("--------------------------------------------------------------------------------------\n");
    printf("                      *** Menu Employee ***            \n");
    printf("--------------------------------------------------------------------------------------\n\n");
    printf("1- Alta de un empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja de un empleado\n");
    printf("4- Informar\n");
    printf("5- Salir\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(eEmployee* list, int len)
{
    int huboError=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
        huboError=0;
    }
    return huboError;
}

int addEmployee(eEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int huboError=-1;
    int indiceLibre;

    if(list!=NULL && len>0 && name!=NULL && lastName!=NULL)
    {
        system("cls");
        indiceLibre=buscarLibre(list, len);

        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("--------------------------------------------------------------------------------------\n");
            printf("                     ***   Alta de Empleados   ***             \n");
            printf("--------------------------------------------------------------------------------------\n\n");

            list[indiceLibre].id=id;

            validarCadena(name, "Ingrese su Nombre: ", "Error, nombre demasiado largo o ingreso numeros: ", 51);
            strcpy(list[indiceLibre].name, name);

            validarCadena(lastName, "Ingrese su Apellido: ", "Error, apellido demasiado largo o ingreso numeros: ", 51);
            strcpy(list[indiceLibre].lastName, lastName);

            validarFlotante(&salary, "Ingrese su salario (15000 a 200000): ", "Error, salario invalido (15000 a 100000): ", 15000, 200000);
            list[indiceLibre].salary=salary;

            validarEntero(&sector, "Ingrese su sector de trabajo (1 a 10): ", "Error, ingrese su sector de trabajos (1 a 10): ", 1, 10);
            list[indiceLibre].sector=sector;

            list[indiceLibre].isEmpty=0;

            printf("\nExcelente. Se realizo correctamente la alta del empleado: \n");
            printf("Id       Nombre         Apellido\tSalario\t\tSector\n");
            mostrarUnEmployee(list[indiceLibre]);
        }
        huboError=0;
    }
    return huboError;
}

int findEmployeeById(eEmployee* list, int len,int id)
{
    int indiceDeIdEncontrado=-1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty==0)
            {
                indiceDeIdEncontrado=i;
                break;
            }
        }
    }
    return indiceDeIdEncontrado;
}


int buscarLibre(eEmployee list[], int len)
{
    int indiceLibre=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                indiceLibre=i;
                break;//xq solo necesitamos el PRIMER indice que encontremos libre una vez encontrado no hay que buscar mas.
            }
        }
    }
    return indiceLibre;
}

void mostrarUnEmployee(eEmployee unEmpleado)
{
        printf("%d\t%8s\t%8s\t%8.2f\t%d\n",
           unEmpleado.id,
           unEmpleado.name,
           unEmpleado.lastName,
           unEmpleado.salary,
           unEmpleado.sector);
}

int printEmployees(eEmployee* list, int length)
{
    int todoOk=0;

    if(list!=NULL && length>0)
    {
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Lista de Empleados   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");
        printf("Id       Nombre         Apellido\tSalario\t\tSector\n");

        for(int i=0; i<length; i++)
        {
            if(list[i].isEmpty==0)
            {
                mostrarUnEmployee(list[i]);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int removeEmployee(eEmployee* list, int len, int id)
{
    int noHuboError=0;
    int indicePersonaBajar;
    char confirmacionDeBaja;

    if(list!=NULL && len>0)
    {
        printf("\n");
        printEmployees(list, len);
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Dar de baja a un Empleado   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Ingrese el ID de la persona a dar de baja: ");
        scanf("%d", &id);

        indicePersonaBajar=findEmployeeById(list, len, id);

        if(indicePersonaBajar>=0)
        {
            printf("\n");
            printf("Id       Nombre         Apellido\tSalario\t\tSector\n");
            mostrarUnEmployee(list[indicePersonaBajar]);
            printf("\n");

            validarCaracter(&confirmacionDeBaja,
                            "Esta seguro que desea dar de baja a esta persona (s/n): ",
                            "Respuesta Invalida. 's' para confirmar baja o 'n' para cancelar baja: ",
                             's',
                             'n');

            if(confirmacionDeBaja=='s')
            {
                list[indicePersonaBajar].isEmpty=1;
                printf("Baja exitosa!\n");
                noHuboError=1;
            }
            else
            {
                printf("Se ha cancelado la baja\n");
            }
        }
        else
        {
            printf("No se encontro el ID: %d\n", id);
        }
    }
    return noHuboError;
}

int menuDeModificacion()
{
    int opcion;
    printf("\nQue le desea modificar al empleado: \n");
    printf("1- Modificar Nombre\n");
    printf("2- Modificar Apellido\n");
    printf("3- Modificar Salario\n");
    printf("4- Modificar sector\n");
    printf("5- Cancelar modificacion\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int modifyEmployee(eEmployee* list, int len)
{
    int todoOk=0;
    int id;
    int indiceAModificar;
    char auxString[150];
    char confirmacionModificar;
    eEmployee auxEmpleado;
    int opcion;

    if(list!=NULL && len>0)
    {
        system("cls");
        printEmployees(list, len);

        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Modificar Empleados   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Ingrese el ID del empleado que desea modificar: ");
        scanf("%d", &id);

        indiceAModificar=findEmployeeById(list, len, id);

        if(indiceAModificar>=0)
        {
            printf("\n");
            printf("Id       Nombre         Apellido\tSalario\t\tSector\n");
            mostrarUnEmployee(list[indiceAModificar]);
            printf("\n");

            validarCaracter(&confirmacionModificar,
                "Esta seguro que quiere modificar a esta persona (s/n): ",
                "Respuesta Invalida. 's' para confirmar o 'n' para cancelar: ",
                 's',
                 'n');

            while(confirmacionModificar=='s')
            {
                opcion=menuDeModificacion();
                switch(opcion)
                {
                     case 1:
                        if(validarCadena(auxString, "Ingrese Nombre modificado: ", "Error, nombre demasiado largo o ingreso numeros: ", 51))
                        {
                            strcpy(list[indiceAModificar].name, auxString);
                            printf("Modificacion exitosa!!!\n");
                        }
                        break;

                    case 2:
                        if(validarCadena(auxString, "Ingrese Apellido modificado: ", "Error, apellido demasiado largo o ingreso numeros: ", 51))
                        {
                            strcpy(list[indiceAModificar].lastName, auxString);
                            printf("Modificacion exitosa!!!\n");
                        }
                        break;

                    case 3:
                        if(validarFlotante(&auxEmpleado.salary, "Ingrese su salario modificado (15000 a 200000): ", "Error, salario demasiado alto (15000 a 200000): ", 15000, 200000))
                        {
                            list[indiceAModificar].salary=auxEmpleado.salary;
                            printf("Modificacion exitosa!!!\n");
                        }
                        break;
                    case 4:
                        if(validarEntero(&auxEmpleado.sector, "Ingrese su sector modificado (1 a 10): ", "Error, sector invalido (1 a 10): ", 1, 10))
                        {
                            list[indiceAModificar].sector=auxEmpleado.sector;
                            printf("Modificacion exitosa!!!\n");
                        }
                        break;

                    case 5:
                        printf("Se ha cancelado la modificacion\n");
                        confirmacionModificar='n';
                        break;

                    default:
                        printf("Opcion invalida!!!\n");
                        break;
                }

                if(opcion>0 && opcion <5)
                {
                    printf("\nEmpleado con la modificacion actualizada: \n");

                    printf("\nId       Nombre         Apellido\tSalario\t\tSector\n");
                    mostrarUnEmployee(list[indiceAModificar]);

                    validarCaracter(&confirmacionModificar,
                    "\nQuiere modificar otro campo de este empleado? (s/n): ",
                    "\nRespuesta Invalida. 's' para confirmar o 'n' para cancelar: ",
                     's',
                     'n');
                }
            }
            todoOk=1;
        }
        else
        {
            printf("No se encontro el ID: %d\n", id);
        }
    }
    return todoOk;
}

int sortEmployees(eEmployee* list, int len, int order)
{
    int todoOk=-1;
    eEmployee auxiliar;
    if(list!=NULL && len>0)
    {
        switch(order)
        {
            case 0: // Descendente
                for(int i=0; i<len-1; i++)
                {
                    for(int j=i+1; j<len; j++)
                    {
                        if(strcmp(list[i].lastName, list[j].lastName)<0 || (!strcmp(list[i].lastName, list[j].lastName) && list[i].sector<list[j].sector))
                        {
                            auxiliar=list[i];
                            list[i]=list[j];
                            list[j]=auxiliar;
                        }
                    }
                }
                printEmployees(list, len);
                break;

            case 1: //Ascendente
                for(int i=0; i<len-1; i++)
                {
                    for(int j=i+1; j<len; j++)
                    {
                        if(strcmp(list[i].lastName, list[j].lastName)>0 || (!strcmp(list[i].lastName, list[j].lastName) && list[i].sector>list[j].sector))
                        {
                            auxiliar=list[i];
                            list[i]=list[j];
                            list[j]=auxiliar;
                        }
                    }
                }
                printEmployees(list, len);
                break;
        }
        todoOk=0;
    }
    return todoOk;
}

int PromedioYContadorSalario(eEmployee list[], int tam)
{
    int todoOk=0;
    float acumSalario=0;
    int contador=0;
    float promedio;

    if(list!=NULL && tam>0)
    {
        system("cls");
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
        printf("        ***   Total y promedio de salarios e informe de empleados que superan el salario promedio   ***                   \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(!list[i].isEmpty)
            {
                acumSalario+=list[i].salary;
                contador++;
            }
        }

        if(contador>0)
        {
            promedio=acumSalario/contador;
        }
        else
        {
            printf("El promedio no se pudo calcular\n");
        }

        printf("La suma de los salarios es: %.3f \n\n", acumSalario);
        printf("El salario promedio es: %.3f \n\n", promedio);
        EmpleadosQueSuperanSalarioProm(list, tam, promedio);

        todoOk=1;
    }
    return todoOk;
}

int informes(eEmployee lista[], int tam)
{
    int todoOk=0;
    int opcion;
    int order;

    if(lista!=NULL && tam>0)
    {
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Informes de empleados   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");
        printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n\n");
        printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\n");
        printf("3. Cancelar\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                validarEntero(&order,
                "\n0- Ordenar de forma descendente (Z a A)\n\n1- Ordenar de forma ascendente (A a Z)\n\ningrese opcion: ",
                "Error. Solo puede ingresar 0(descendete) o 1(ascendente): ",
                0,
                1);
                sortEmployees(lista, tam, order);
                break;

            case 2:
                PromedioYContadorSalario(lista, tam);
                break;

            case 3:
                printf("Informe cancelado\n");
                break;

            default:
                printf("Opcion invalida!!!\n");
                break;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarSiHayUnEmpleado(eEmployee list[], int len, int* banderaHayUnEmpleado)
{
    int todoOk=0;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {
                *banderaHayUnEmpleado=1;
                break;
            }
            else
            {
                *banderaHayUnEmpleado=0;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int EmpleadosQueSuperanSalarioProm(eEmployee list[], int tam, int salarioPromedio)
{
    int todoOk=0;
    int contadorSuperanSalarioProm=0;

    if(list!=NULL && tam>0 && salarioPromedio>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!list[i].isEmpty && list[i].salary>salarioPromedio)
            {
                contadorSuperanSalarioProm++;
            }
        }
        printf("Los empleados que superan el salario promedio son %d: \n\n", contadorSuperanSalarioProm);
        printf("Id       Nombre         Apellido\tSalario\t\tSector\n");

        for(int i=0; i<tam; i++)
        {
            if(!list[i].isEmpty && list[i].salary>salarioPromedio)
            {
                mostrarUnEmployee(list[i]);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

