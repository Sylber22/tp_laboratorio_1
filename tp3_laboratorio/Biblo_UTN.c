#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "Biblo_UTN.h"
#include "Validaciones.h"

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param buffer Se crea un auxiliar para cargar el dato
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \param pResultado donde se carga el resultado
 * \return '-1' si hubo un error y '0' si esta todo bien
 */
int getInt(int* pResultado, char* msg, char* msgError)
{
    int buffer;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%d",&buffer)==1)
    {
        (*pResultado)=buffer;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
        fflush(stdin);
        //fpurge(stdin);
    }
    return ret;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param buffer Se crea un auxiliar para cargar el dato
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \param pResultado donde se carga el resultado
 * \return '-1' si hubo un error y '0' si esta todo bien
 */
int getFloat(float* pResultado, char* msg, char* msgError)
{
    float buffer;
    int ret=-1;

    printf("%s",msg);
    if(scanf("%f",&buffer)==1)
    {
        (*pResultado)=buffer;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
    }
    return ret;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param buffer Se crea un auxiliar para cargar el dato
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \return El caracter ingresado por el usuario
 */
int getChar(char* pResultado,char* msg, char* msgError)
{
    char buffer;
    int ret=-1;

    printf("%s",msg);
    if(scanf("%c",&buffer)==1)
    {
        (*pResultado)=buffer;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
        fflush(stdin);
        //fpurge(stdin);
    }
    return ret;
}

/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo espacios y letras y -1 si no lo es
 */
int esSoloLetras(char* str)
{
    int ret=-1;
    int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
         ret=0;
        }
        i++;
    }
   return ret;
}

/**
 * \brief Verifica si el valor recibido son numeros
 * \param str Array con la cadena a ser analizada
 * \return 0 si es númerico y -1 si no lo es
 */
int esNumerico(char* str)
{
    int ret=-1;
    int i=0;
    while(str[i] != '\0')
   {
        if(str[i] < '0' || str[i] > '9')
       {
          ret=0;
       }
    i++;
   }
   return ret;
}


/**
 * \brief Verifica si el valor recibido contiene solo números y guiones o espacios
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo numeros, espacios y un guion, -1 si no tiene
 */
int esTelefono(char* str)
{
    int i=0;
    int contadorGuion=0;
    while(str[i]!='\0')
    {
        if((str[i]!=' ')&&(str[i]!='-')&&(str[i]<'0' || str[i]>'9'))
        {
            return 0;
        }
        if(str[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1)
        {
            return 1;
        }
    return 0;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo espacio o letras y números, y -1 si no lo es
 */
int esAlfaNumerico(char* str)
{
    int ret=-1;
    int i=0;
    while(str[i] != '\0')
    {
       if((str[i] != ' ') &&
          (str[i] < 'a' || str[i] > 'z') &&
          (str[i] < 'A' || str[i] > 'Z') &&
          (str[i] < '0' || str[i] > '9'))
       {
           ret=0;
       }
       i++;
   }
   return ret;
}

/**
 * \brief Verifica si el valor recibido es un numero, entero o con coma
 * \param str Array con la cadena a ser analizada
 * \return 0 si es númerico y 1 si no lo es
 */
int esNumericoFlotante(char* str)
{
    int i=0;
    int contadorPuntos=0;

    while(str[i]!='\0')
    {
            if((str[i]<'0' || str[i]>'9')&&(str[i]!='.'))
        {
            return 0;
        }
        if(str[i]=='.')
        {
            contadorPuntos++;
            if(contadorPuntos>1)
            {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

/**
 * \brief Solicita un dato al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \param pResultado Array donde se cargará el dato ingresado
 * \return 0
 */
int getString(char* pResultado, char* msg)
{
    char bufferStr[20];
    printf(msg);
    fflush(stdin);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    if(pResultado!=NULL)
    {
        strncpy(pResultado,bufferStr,sizeof(bufferStr));
    }
      return 0;
}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 */
void cleanStdin(void)
{
    int x;
    do {
        x = getchar();
    } while (x != '\n' && x != EOF);
}

/**
 * \brief Menu de opciones
 * \param imprime un menu de opciones para
    que el usuario elija mediante numeros
 * \return 0
 */
int menu()
{
    int opcionElegida;
    printf("\n---------MENU-----------\n");
    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
    printf("\n3. Alta de empleado");
    printf("\n4. Modificar datos de empleado");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
    printf("\n10. Salir");
    getInt(&opcionElegida,"\nOPCION: ", "\n-INGRESO MAL EL DATO-\n");
   return opcionElegida;
}

