/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Gabriel Alegre
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "miBibliotecaAlegre.h"

int main()
{
	setbuf(stdout,NULL);
	float a;
	float b;
	int factorialDeA;
	int factorialDeB;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	int ingresoPrimerOperando=0;
	int ingresoSegundoOperando=0;
	int realizoLasOperaciones=0;
    int sePudoDividir;
    int seHizoFactorialDeA;
    int seHizoFactorialDeB;
    char salir='n';

    do
    {
        switch(funcionMenu(a, b, ingresoPrimerOperando, ingresoSegundoOperando))
        {
            case 1:
                if(ingresoPrimerOperando==0)
                {
                	printf("Ingrese el primer operando: ");
					scanf("%f", &a);
					ingresoPrimerOperando=1;
                }
                else
                {
                	printf("Ya ingreso como primer operando el numero: %.1f\n",a);
                }
                break;

            case 2:
                if(ingresoPrimerOperando==0)
                {
                    printf("Para poder ingresar el segundo operando primero debe ingresar el primer operando.\n");
                }
                else
                {
                    if(ingresoSegundoOperando==1)
                    {
                        printf("Ya ingreso como segundo operando el numero: %.1f\n", b);
                    }
                    else
                    {
                        printf("Ingrese el segundo operando: ");
                        scanf("%f", &b);
                        ingresoSegundoOperando=1;
                    }
                }
                break;

            case 3:
                if(ingresoSegundoOperando==1)
                {
                    if(realizarOperaciones(a, b, &suma, &resta, &division, &factorialDeA, &factorialDeB, &multiplicacion, &sePudoDividir, &seHizoFactorialDeA, &seHizoFactorialDeB)==1)
                    {
                        printf("Se realizaron correctamente las operaciones. Si desea que le informemos los resultados seleccione la opcion 4.\n");
                    }
                    else
                    {
                        printf("No se pudo calcular las operaciones.\n");
                    }
                    realizoLasOperaciones=1;
                }
                else
                {
                    if(ingresoPrimerOperando==0)
                    {
                        printf("Para poder calcular las operaciones primero se debe ingresar el primer y segundo operando.\n");
                    }
                    else
                    {
                        printf("Debe ingresar el segundo operando para poder calcular las operaciones.\n");
                    }
                }
                break;
            case 4:
                if(realizoLasOperaciones==1)
                {
                    informarResultados(a, b, suma, resta, division, factorialDeA, factorialDeB, multiplicacion, sePudoDividir, seHizoFactorialDeA, seHizoFactorialDeB);
                    ingresoPrimerOperando=0;
                    ingresoSegundoOperando=0;
                    realizoLasOperaciones=0;
                }
                else
                {
                    printf("Para informar los resultados primero se deben calcular las operaciones (opcion 3).\n");
                }
                break;

            case 5:
                printf("Esta seguro que desea salir s/n: ");
                fflush(stdin);
                scanf("%c",&salir);
                break;
            default:
                printf("Opcion invalida!\n");
                break;
        }
        system("pause");

    }while(salir=='n');

    return 0;
}
