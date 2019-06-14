#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "Validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    FILE* fp;
    fp= fopen(path, "r");
    if( fp!=NULL && path!=NULL)
    {
        if(!parser_EmployeeFromText(fp, pArrayListEmployee))
        {
            ret=0;
        }
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* fp = fopen(path, "rb");
    int ret= -1;
      if(fp!=NULL)
      {
          ret = parser_EmployeeFromBinary(fp, pArrayListEmployee);
      }
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    Employee* bufferEmployee = emp_new();
    //int lenLista= ll_len(pArrayListEmployee);
    char bufferId[4096];
    char bufferName[4096];
    char bufferWorkingHours[4096];
    char bufferSalary[4096];
    int bufferIdInt=-1;

     if(pArrayListEmployee!=NULL)
     {
         printf("---NUEVO EMPLEADO---\n");
         if(!getStringLetras(bufferName, "Ingrese el nombre: ", "Error\n", 2)&&
            (!getStringNumeros(bufferWorkingHours, "Ingrese horas trabajadas: ", "Error\n", 2))&&
             (!getStringNumeros(bufferSalary, "Ingrese salario: ", "Error\n", 2)))
            {
                bufferIdInt= controller_nextID(pArrayListEmployee);//BUSCAR EL ID MAS GRANDE Y DEVOLVERLO +1
                itoa(bufferIdInt,bufferId,10);
                emp_setStrId(bufferEmployee,bufferId);
                emp_setName(bufferEmployee, bufferName);
                emp_setStrWorkingHours(bufferEmployee, bufferWorkingHours);
                emp_setStrSalary(bufferEmployee, bufferSalary);

            }
       if((bufferName[0]=='\0')||( bufferWorkingHours[0]=='\0') || (bufferSalary[0]=='\0'))
       {
                printf("No se guardaron los datos");
       }
        else
        {
            bufferEmployee= emp_newParameters(bufferId, bufferName, bufferWorkingHours, bufferSalary);
            if(!ll_add(pArrayListEmployee, bufferEmployee))
            {
                printf("---EMPLEADO AGREGADO ID ASIGNADO:%s ---\n",bufferId);
                ret=0;
        }

        }
     }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    Employee* bufferEmployee;
    Employee* bufferNuevoEmployee= emp_new();
    int lenList= ll_len(pArrayListEmployee);
    char bufferIdChar[4096];
    char bufferNameChar[4096];
    char bufferWorkingHoursChar[4096];
    char bufferSalaryChar[4096];
    int bufferIdInt=-1;
    int bufferWorkingHours;
    int bufferSalary;
    char seguir = 'n';
    int i;
    int modificar;

    if(pArrayListEmployee != NULL)
    {
            bufferIdInt= getValidInt("Ingrese el ID del empleado a modificar: ", "\nID no pertenece a ningun empleado", 0, lenList+1);
            for(i = 0; i< lenList; i++)
            {
                bufferEmployee= ll_get(pArrayListEmployee, i);
                if(bufferIdInt== bufferEmployee->id)
                {
                    emp_printEmployee(bufferEmployee);
                    do
                    {
                        modificar=getValidInt("--MENU MODIFICAR--\n1)ID\n2)NOMBRE\n3)HORAS TRABAJADAS\n4)SUELDO\n5)Salir\nELIJA UNA OPCION: ", "ERROR",0,5);
                        switch(modificar)
                        {
                     case 1://ID
                        printf("--MODIFICAR ID--\n");

                        bufferIdInt= controller_nextID(pArrayListEmployee);//BUSCA UN NUEVO ID
                        itoa(bufferIdInt,bufferIdChar,10);//CONVIERTE EL INT EN STRIG BASE 10

                        bufferEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                        emp_getId(bufferEmployee, &bufferIdInt);
                        emp_getName(bufferEmployee, bufferNameChar);
                        emp_getWorkingHours(bufferEmployee, &bufferWorkingHours);
                        emp_getSalary(bufferEmployee, &bufferSalary);
                        printf("%d %s %d %d\n\n ",bufferIdInt,
                                                bufferNameChar,
                                                bufferWorkingHours,
                                                bufferSalary);
                        itoa(bufferSalary,bufferSalaryChar,10);
                        itoa(bufferWorkingHours,bufferWorkingHoursChar,10);
                        bufferNuevoEmployee= emp_newParameters(bufferIdChar, bufferNameChar, bufferWorkingHoursChar, bufferSalaryChar);
                        if(!ll_add(pArrayListEmployee, bufferNuevoEmployee))
                        {
                            printf("---NUEVO ID ASIGNADO:%s ---\n\n",bufferIdChar);
                            ret=0;
                        }
                        if (bufferIdInt== bufferEmployee->id)//BORRA EL ID ANTERIOR
                        {
                            ll_remove(pArrayListEmployee, i);
                           // emp_printEmployee(bufferEmployee);
                            emp_Delete(bufferEmployee);
                        }
                        break;
                    case 2://NOMBRE
                         printf("--MODIFICAR NOMBRE--\n");
                         getStringLetras(bufferNameChar,"Ingrese nuevo nombre: ", "ERROR",2);
                         if(!emp_setName(bufferEmployee, bufferNameChar))
                         {
                             printf("Nombre cambiado con exito\n");
                               ret=0;
                         }
                        break;
                    case 3://HORAS
                            printf("--MODIFICAR HORAS TRABAJADAS--\n");
                            getStringNumeros(bufferWorkingHoursChar,"Ingrese nuevas horas trabajadas: ", "\nERROR", 2);
                            bufferWorkingHours = atoi(bufferWorkingHoursChar);
                            if(!emp_setWorkingHours(bufferEmployee, bufferWorkingHours))
                            {
                                printf("Nuevas horas cambiadas\n");
                                ret=0;
                            }
                        break;
                    case 4://SUELDO
                         printf("--MODIFICAR SUELDO--\n");
                         getStringNumeros(bufferSalaryChar, "Ingrese nuevo sueldo: ", "ERROR", 2);
                         bufferSalary= atoi(bufferSalaryChar);
                         if(!emp_setSalary(bufferEmployee, bufferSalary))
                         {
                              printf("Nuevo sueldo cambiado\n");
                              ret=0;
                         }
                        break;
                    case 5://SALIR
                        printf("EXIT=>\n");
                        seguir = 's';
                        break;
                        }
                    }while(seguir != 's');//DO
                }//IF ID MACH
            }//FOR
    }
    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    Employee* bufferEmployee;
    int lenList=ll_len(pArrayListEmployee);
    int i;
    int bufferIdInt;

    if(pArrayListEmployee != NULL)
    {
        bufferIdInt= getValidInt("Ingrese ID a eliminar: ", "ERROR", 0,lenList+1);
        for(i=0; i<lenList; i++)
            {
                bufferEmployee=ll_get(pArrayListEmployee, i);
                if (bufferIdInt== bufferEmployee->id)
                 {
                    printf("ID\tNAME\tHOURS\tSALARY\n");
                    emp_printEmployee(bufferEmployee);
                    ll_remove(pArrayListEmployee, i);
                    printf("EMPLEADO ELIMINADO");
                    emp_Delete(bufferEmployee);
                    ret=0;
                    break;
                }//IF
            }//FOR
    }//NULL
    return ret;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ret=-1;
    Employee* bufferEmployee;
    int lenLista= ll_len(pArrayListEmployee);
    int bufferId;
    char bufferName[128];
    int bufferWorkedHours;
    int bufferSalary;
    int i;
    if((pArrayListEmployee!=NULL)&& (lenLista > 0))
    {
        printf("ID\tNAME\tHOURS\tSALARY\n");
        for(i=0; i<lenLista;i++)
        {
            bufferEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            emp_getId(bufferEmployee, &bufferId);
            emp_getName(bufferEmployee, bufferName);
            emp_getWorkingHours(bufferEmployee, &bufferWorkedHours);
            emp_getSalary(bufferEmployee, &bufferSalary);
            printf("%d %s %d %d\n ",bufferId,
                                    bufferName,
                                    bufferWorkedHours,
                                    bufferSalary);
            ret=0;
        }
    }
    else
    {
        printf("No se cargaron los datos.\n");
    }
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
        int ret=-1;
        int option;
        if(pArrayListEmployee!=NULL)
        {
            option= getValidInt("Ordenar por:\n1)ID\n2)NOMBRE\n3)MAS HORAS TRABAJADAS\n4)SUELDO\nELIJA UNA OPCION: ", "ERROR", 0,6);
            switch(option)
            {
        case 1://ID
            if(!ll_sort(pArrayListEmployee,emp_sortById,1))
            {
                ret=0;
                printf("Ordenado por id ascendente");
            }
            break;
        case 2://NOMBRE
            if(!ll_sort(pArrayListEmployee,emp_sortByName,1))
            {
                ret=0;
                printf("Ordenado por nombre alfabeticamente");
            }
            break;
        case 3://HORAS
            if(!ll_sort(pArrayListEmployee,emp_sortByWorkHours,1))
            {
                printf("Ordenado por cant de hs trabajadas ascendente");
                ret=0;
            }
            break;
        case 4://SUELDO
            if(!ll_sort(pArrayListEmployee,emp_sortBySalary,1))
            {
                printf("Ordenado por salario ascendente");
                ret=0;
            }
            break;
            }
        }
        return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int ret= -1;
    int lenLista = ll_len(pArrayListEmployee);
    Employee* bufferEmployee;
    FILE* fp = fopen(path, "w");
    int i;

    if((fp!=NULL) && (pArrayListEmployee!=NULL))
    {
        fprintf(fp, "id,nombre,horasTrabajadas,sueldo\n");
        for(i = 0; i < lenLista; i++)
        {
            bufferEmployee = (Employee*)ll_get(pArrayListEmployee, i);
             fprintf(fp, "%d,%s,%d,%d\n", bufferEmployee->id,
                                        bufferEmployee->name,
                                        bufferEmployee->workingHours,
                                        bufferEmployee->salary);
        }
        printf("Se ha realizado el guardado del archivo con exito\n");
ret=0;
    }
    fclose(fp);
    return ret;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int lenLista = ll_len(pArrayListEmployee);
    Employee* bufferEmployee;
    FILE* fp = fopen(path, "wb");
    int i;
    if(fp==NULL)
    {
        printf("Error al guardar\n");
        return ret;
    }
    if(pArrayListEmployee!=NULL)
    {
        for(i = 0; i < lenLista; i++)
        {
            bufferEmployee = ll_get(pArrayListEmployee, i);
            fwrite(bufferEmployee, sizeof(Employee), 1, fp);
        }
        printf("Se ha realizado el guardado del archivo con exito\n");
        ret = 0;
    }
    fclose(fp);
    return ret;
}

/** \brief genera in id nuevo.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_nextID(LinkedList* pArrayListEmployee)
{
    Employee* bufferArray;

    int i;
    int aux;
    int id= 0;
    int lenList= ll_len(pArrayListEmployee);
    int idAnterior;

    if((pArrayListEmployee != NULL)&&(lenList > 0))
    {
        for(i = 0; i<lenList; i++)
        {
            bufferArray = (Employee*)ll_get(pArrayListEmployee,i);
            emp_getId(bufferArray,&aux);
            if(aux > id)
            {
                idAnterior = id;
                id = aux;
                if(idAnterior + 1 != id)
                {
                    id = idAnterior;
                    break;
                }
            }
        }
            id++;
    }
    else
    {
        id = 1;
    }
    return id;
}
