#include <stdio.h>
#include <stdlib.h>
#include "Biblo_UTN.h"
#include "Validaciones.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int flagDatosCargadosTexto= 0;
    int flagDatosCargadosBinario= 0;
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        option= menu();
        switch(option)
        {
           case 1://CARGA DATOS DESDE ARCHIVO TEXTO
            if (flagDatosCargadosTexto==0 && flagDatosCargadosBinario!=1)
            {
                   if(!controller_loadFromText("data.csv",listaEmpleados))
                   {
                        printf("DATOS CARGADOS");
                        flagDatosCargadosTexto=1;
                   }
                    else
                   {
                       printf("NO SE PUDIERON CARGAR LOS DATOS");
                   }
            }
             else
                {
                    printf("DATOS YA CARGADOS");
                }
                break;
            case 2://CARGA DATOS DESDE ARCHIVO BINARIO
                   if(flagDatosCargadosBinario== 0 && flagDatosCargadosTexto!= 1)
                   {
                        controller_loadFromBinary("data.bin",listaEmpleados);
                        flagDatosCargadosBinario=1;
                   }
                    else
                    {
                        printf("DATOS YA CARGADOS");
                    }
                break;
            case 3://ALTA EMPLEADO
                if (flagDatosCargadosTexto== 1 || flagDatosCargadosBinario== 1)
                {
                    controller_addEmployee(listaEmpleados);
                }
                else
                {
                    printf("Debe cargar los datos antes de hacer un alta");
                }
                break;
            case 4://MODIFICAR EMPLEADO
                if(flagDatosCargadosTexto== 1 || flagDatosCargadosBinario== 1)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("Debe cargar los datos antes de hacer una modificacion");
                }
                break;
            case 5://BAJA EMPLEADO
                  if(flagDatosCargadosTexto== 1 || flagDatosCargadosBinario== 1)
                {
                   controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("Debe cargar los datos para poder eliminar un empleado");
                }

                break;
            case 6://LISTAR
                  if(flagDatosCargadosTexto== 1 || flagDatosCargadosBinario== 1)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("Debe cargar los datos antes poder listar los empleados");
                }

                break;
            case 7://ORDENAR
                  if(flagDatosCargadosTexto== 1 || flagDatosCargadosBinario== 1)
                {
                   controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("Debe cargar los datos para poder ordenarlos");
                }
                break;
            case 8://GUARDAR TEXTO
                   controller_saveAsText("data.csv",listaEmpleados);
                   system("pause");
                break;
            case 9://GUARDAR BINARIO
                 controller_saveAsBinary("data.bin", listaEmpleados);
                 system("pause");
                break;
            case 10://SALIR
                break;
        }
    }while(option != 10);
    return 0;
}
