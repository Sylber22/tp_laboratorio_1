#include <stdio.h>
#include <stdlib.h>
#include "Bertello.h"


int main ()
{
    //variables

    float operando1=0;
    float operando2=0;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    long int factorial1;
    long int factorial2;
    int bandera1=0;
    int bandera2=0;
    int opcion;

    do
    {
        system("pause");
        system("cls");
        printf(" \nMenu");
        printf("\n 1-Ingresar primer operando (A=%.2f).",operando1);
        printf("\n 2-Ingresar segundo operando (B=%.2f).",operando2);
        printf("\n 3-Calcular todas las operaciones:");
        printf("\n  a)Suma");
        printf("\n  b)Resta");
        printf("\n  c)Division");
        printf("\n  d)Multiplicacion");
        printf("\n  e)Factorial");
        printf("\n 4-Informar resultados.");
        printf("\n 5-Salir de la calculadora.");
        printf(" \n\n Elija una opcion: ");
        scanf ("%d", &opcion);

        switch(opcion)
        {
        case 1:
            bandera1=1;
            printf(" Ingrese primer numero: ");
            scanf ("%f", &operando1);

            break;
        case 2:
            bandera2=1;
            printf(" Ingrese segundo numero: ");
            scanf ("%f", &operando2);


            break;
        case 3:

            if (bandera1==1 && bandera2==1)
                {
                    suma=funcionSuma(operando1,operando2);
                    resta=funcionResta(operando1,operando2);
                    division=funcionDivision (operando1, operando2);
                    multiplicacion=funcionMultiplicacion (operando1, operando2);
                    factorial1=(int)funcionFactorial1 (operando1);
                    factorial2=(int)funcionFactorial2 (operando2);


                    printf("\n -Calculando-\n");

            }
            else
            {
              printf ("\n No se han ingresado numeros, por favor vuelva al menu\n");
            }

            break;
        case 4:
            if (bandera1==1 && bandera2==1)
            {

                printf("\n El resultado de la suma es: %.2f",suma);
                printf ("\n El resultado de la resta es:%.2f", resta);

                if (operando2 ==0 || operando1 ==0)
                {
                    printf("\n No es posible la division");
                }
                else
                {
                    printf ("\n El resultado de la division es:%.2f", division);
                }
                printf ("\n El resultado de la multiplicacion es:%.2f", multiplicacion);

                if (operando1<1 ||operando2<1)
                {
                    printf("\n No se puede factoriar un numero negativo o el Cero\n");
                }
                else
                {
                    printf ("\n El resultado del factoreo 1 es:%li", factorial1);
                    printf ("\n El resultado del factoreo 2 es:%li\n", factorial2);
                }
            }//if
            else
            {
                printf("\n Por favor vuelva al menu e ingrese dos numeros\n");
            }

            break;
        case 5:
            printf("\t Saliendo, gracias por usar la calculadora...");
            break;
        default:
            printf("Error. Ingrese un dato correcto\n");


        }// swicht


    }//fin del anidamiento
    while (opcion!=5);


    return 0;

}
