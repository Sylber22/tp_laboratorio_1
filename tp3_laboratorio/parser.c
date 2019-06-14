#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    char bufferId[4096];
    char bufferName[4096];
    char bufferWorkingHours[4096];
    char bufferSalary[4096];
    int i=0;
    int r=0;
    Employee *bufferEmployee= emp_new();

    if(pFile != NULL)
    {
        //CABECERA
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                  bufferName,
                                                  bufferWorkingHours,
                                                  bufferSalary);
        while(!feof(pFile))
        {
            r= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferName,
                                                  bufferWorkingHours,
                                                  bufferSalary);
            if(r==4)
            {
                bufferEmployee = emp_newParameters( bufferId,
                                                    bufferName,
                                                    bufferWorkingHours,
                                                    bufferSalary);
                 if((bufferEmployee != NULL)&&(!ll_add(pArrayListEmployee,bufferEmployee)))
                    {
                        i++;
                        ret=0;
                    }

            }//IF==4
            else
               {
                    break;
                }
        }//WHILE
    }//IF NULL
    return ret;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    int contador=0;

    Employee* bufferEmployee;

    while(!feof(pFile))
     {
        bufferEmployee = emp_new();
        if(bufferEmployee!=NULL)
        {
            if((fread(bufferEmployee, sizeof(Employee), 1, pFile))==1)//MIENTRAS LEA UN EMPLEADO
            {
                emp_setId(bufferEmployee,bufferEmployee->id);
                emp_setName(bufferEmployee,bufferEmployee->name);
                emp_setWorkingHours(bufferEmployee,bufferEmployee->workingHours);
                emp_setSalary(bufferEmployee,bufferEmployee->salary);
                if(!ll_add(pArrayListEmployee, bufferEmployee))//LO AGREGA
                {
                    ret = 0;
                    contador ++;
                }
            }
        }
        else// SI NO AGREGA MAS EMPLEADOS LIBERA ESPACIO
            {
                emp_Delete(bufferEmployee);
            }
     }
     printf("Se han cargado %d de usuarios\n", contador);
    return ret;
}
