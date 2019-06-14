#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "Biblo_UTN.h"
#include "Validaciones.h"

int getStringAlpha(char* pResultado, char* msg, char* msgError, int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while((reintentos>=0) && (ret==-1))
    {
         if(!getString(bufferStr,msg)&&(pResultado!=NULL)&&(esAlfaNumerico(bufferStr)))
        {
            strncpy(pResultado,bufferStr,sizeof(bufferStr));
            ret=0;

        }//ES ALFANUMERICA
        else
        {
            printf(msgError);
            reintentos--;
        }
    }//WHILE
    return ret;
}
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param pResultado Array donde se cargará el texto ingresado
  * \param magError mensaje a ser mostrado en caso de error
 * \param reintentos cantidad de reintentos habilitadas para ingresar un dato correcto
 * \return 0 si el texto contiene solo números -1 si no
 */
int getStringNumeros(char* pResultado,char* msg,char* msgError, int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg)&&(pResultado!=NULL)&&(esNumerico(bufferStr)))
        {
            strncpy(pResultado,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
             printf(msgError);
             reintentos--;
        }
    }
    return ret;
}



/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param msg Es el mensaje a ser mostrado
 * \param pResultado Array donde se cargará el texto ingresado
 * \param magError mensaje a ser mostrado en caso de error
 * \param reintentos cantidad de reintentos habilitadas para ingresar un dato correcto
 * \return 0 si el texto contiene solo números con coma
 */
int getStringNumerosFlotantes(char* pResultado,char* msg,char* msgError, int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg)&&(esNumericoFlotante(bufferStr)))
        {
            strncpy(pResultado,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
            printf(msgError);
            reintentos--;
        }
    }
    return ret;
}
/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param Msg Es el mensaje a ser mostrado para solicitar el dato
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
float getValidFloat(char* msg, char* msgError, int lowLimit, int hiLimit)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (getStringNumerosFlotantes(auxStr,msg, msgError,2)==-1)
        {
            printf ("%s\n",msgError);
            continue;
        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxFloat;
    }
}
/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param Msg Es el mensaje a ser mostrado para solicitar el dato
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \param low y hi Limit, parametros delimitadores de la eleccion del numero
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char* msg,char* msgError, int lowLimit, int hiLimit)
{
    char bufferNumero[256];
    int auxInt;
    while(1)
    {
        if (getStringNumeros(bufferNumero,msg, msgError,2)==-1)
        {
            printf ("%s\n",msgError);
            continue;
        }
        auxInt = atoi(bufferNumero);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;
    }
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param pResultado Array donde se cargará el texto ingresado
 * \param magError mensaje a ser mostrado en caso de error
 * \param reintentos cantidad de reintentos habilitadas para ingresar un dato correcto
 * \return 0 si el texto contiene solo letras -1 si no
 */
int getStringLetras(char* pResultado, char* msg, char* msgError, int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while((reintentos>=0) && (ret==-1))
    {
        if(!getString(bufferStr,msg)&&(pResultado!=NULL)&&(esSoloLetras(bufferStr)))
        {
            strncpy(pResultado,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
            printf(msgError);
            reintentos--;
        }
    }
    return ret;
}
/** \brief Valida los tres enteros ingresados como fecha.
 *
 * \param day
 * \param month
 * \param year
 * \return Retorna 0 si es valida o -1 si no lo es.
 *
 */

int isValidDate(int day, int month, int year)
{
    int ret = -1;
    if (year>=1895 && year <=2019)
    {


        if ( month >= 1 && month <= 12 )
        {
            switch (month)
            {
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 :
                if (day >= 1 && day <= 31)
                {
                    ret = 0;
                    break;
                }
            case  4 :
            case  6 :
            case  9 :
            case 11 :
                if ( day >= 1 && day <= 30 )
                {
                    ret = 0;
                    break;
                }
            case  2 :
                if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )
                {
                    if ( day >= 1 && day <= 29 )
                    {
                        ret = 0;
                    }
                }
                else if ( day >= 1 && day <= 28 )
                {
                    ret = 0;
                }
            }
        }
    }
    return ret;
}
