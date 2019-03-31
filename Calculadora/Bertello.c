#include <stdio.h>
#include <stdlib.h>
#include "Bertello.h"

//funciones
float funcionSuma(float operando1,float operando2)
{
    float suma;
    suma=operando1+operando2;
    return suma;
}
/**\brief Suma
*\param ingresan dos numeros
*\param se realiza la operacion suma
 * \return resultado de la operacion
 *
 */



float funcionResta (float operando1, float operando2)
{
    float resta;
    resta=operando1-operando2;
    return resta;
}
/**\brief Resta
*\param ingresan dos numeros
*\param se realiza la operacion resta
 * \return resultado de la operacion
 *
 */


float funcionDivision (float operando1, float operando2)//correjir
{
    float division;
    division=operando1/operando2;
    return division;
}
/**\brief Division
*\param ingresan dos numeros
*\param se realiza la operacion division
*\param mensaje para avisar que no se puede dividir por 0
*/

float funcionMultiplicacion(float operando1, float operando2)
{
    float multiplicacion;
    multiplicacion=operando1*operando2;
    return multiplicacion;
}
/**\brief Multimplicacion
*\param ingresan dos numeros
*\param se realiza la operacion multiplicacion
*/
int funcionFactorial1 (int operando1)
    {
        int resultado1=1;
        int auxop1;
        int contador1;

        auxop1=operando1;

        for(contador1=0; contador1<operando1; contador1++)
        {
            resultado1=resultado1*auxop1;
            auxop1=auxop1-1;
        }

        return resultado1;
    }

int funcionFactorial2 (int operando2)

{
    int resultado2=1;
        int auxop2;
        int contador2;

        auxop2=operando2;

        for(contador2=0; contador2<operando2; contador2++)
        {
            resultado2=resultado2*auxop2;
            auxop2=auxop2-1;
        }

        return resultado2;
}

/**\brief Factorial
*\param ingresan los numeros de a uno
*\param se realiza la operacion factoreo
*\param se muestra mensaje de que no se puede factorear por menos de 0
*/


