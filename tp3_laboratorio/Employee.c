#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "Biblo_UTN.h"
#include "Validaciones.h"
#include "Controller.h"
#include "Parser.h"



/** \brief devuelve un puntero al lugar de memoria
 *
 * \param void
 * \return puntero
 *
 */
Employee* emp_new()
{
    return(Employee*)malloc(sizeof(Employee));
}

/** \brief le da nuevos para metros a la estructura de empleado y crea la una lista
 *
 * \param cadena de los campos de la estructura
 * \return la lista llena
 *
 */
Employee* emp_newParameters(char* pId,char* pName,char* pWorkingHours, char* pSalary)
{
    Employee* bufferEmployee= emp_new();

    if(bufferEmployee!=NULL)
    {
     if((emp_setStrId(bufferEmployee, pId))||
        (emp_setName(bufferEmployee, pName))||
         (emp_setStrWorkingHours(bufferEmployee, pWorkingHours))||
          (emp_setStrSalary(bufferEmployee, pSalary)))
           {
             emp_Delete(bufferEmployee);
           }
    }
    return bufferEmployee;// DEVUELVE LA LIST LLENA
}

/** \brief borra el empleado
 *
 * \param la lista
 * \return -1 si dio erro y 0 si se pudo borra el empleado
 *
 */
int emp_Delete(Employee* this)
{
    int ret = -1;
    if(this != NULL)
    {
        free(this);
        ret = 0;
    }
    return ret;
}

/** \brief Recibe una cadena y verifica si se pudo convertir a un entero valido
 *
 * \param la lista de empleados
 * \param la cadena que contiene el id
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setStrId(Employee* this, char* strId)
{
    int ret=-1;
    int bufferId;
    if(this!=NULL && esNumerico(strId))
    {
        bufferId= atoi(strId);
        if(!emp_setId(this, bufferId))
        {
          ret=0;
        }
    }
    return ret;
}

/** \brief recibe un entero y verifica si es un id valido y lo guarda
 *
 * \param la lista de empleados
 * \param el numero entero: id
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setId(Employee* this,int id)
{
    int ret = -1;
    if(this != NULL && id >0)
    {
        this->id = id;
        ret = 0;
    }
    return ret;
}

/** \brief guar el id en el campo id de la estructura
 *
 * \param la lista de empleados
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_getId(Employee* this,int* id)
{
    int ret = -1;
    if(this!=NULL)
    {
        *id = this->id;
        ret = 0;
    }
    return ret;
}


/** \brief recibe una cadena y lo guarda en el elemento nombre
 *
 * \param la lista de empleados
 * \param la cadena
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setName(Employee* this, char* name)
{
    int ret=-1;
    if (this!=NULL && strlen(name)>0)
        {
            strncpy(this->name, name, sizeof(this->name));
            ret=0;
        }
    return ret;
}

/** \brief toma una cadena y la muestra
 *
 * \param lista de empleados
 * \param cadena nombre
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_getName(Employee* this,char* name)
{
    int ret= -1;
    if(this!=NULL)//VALIDAR NAME
    {
        strcpy ( name, this->name);
        ret = 0;
    }
    return ret;
}

/** \brief  recibe la cadena 'horas trabajadas' y la valida
 *
 * \param lista de empleados
 * \param acadena 'horas trabajadas'
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setStrWorkingHours(Employee* this, char* strWorkingHours)
{
     int ret=-1;
     int bufferWorkingHours;
    if(this!=NULL && esNumerico(strWorkingHours))
    {
        bufferWorkingHours = atoi(strWorkingHours);
        if(!emp_setWorkingHours(this, bufferWorkingHours))
        {
          ret=0;
        }
    }
    return ret;
}

/** \brief recibe una cadena y la guarda en un campo de la estructura
 *
 * \param lista de empleados
 * \param numero entero
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setWorkingHours(Employee* this,int workingHours)
{
    int ret=-1;
    if(this!=NULL)
       {
           if(workingHours> 0 || workingHours>24)
         {
            this-> workingHours= workingHours;
            ret=0;
         }
    }
    return ret;
}

/** \brief toma la el entero del campo
 *
 * \param lista de empleados
 * \param numero entero
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_getWorkingHours(Employee* this,int* workingHours)
{
    int ret = -1;
    if(this!=NULL)
    {
        *workingHours = this->workingHours;
        ret= 0;
    }
    return ret;
}

/** \brief valida la cadena y la guardar
 *
 * \param lista de empleados
 * \param cadena
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setStrSalary(Employee* this, char* pSalary)
{
    int ret=-1;
    float bufferSalary;
    if(this!=NULL && esNumericoFlotante(pSalary))
    {
        bufferSalary = atof(pSalary);
        if(!emp_setSalary(this, bufferSalary))
        {
            ret= 0;
        }
    }
    return ret;
}

/** \brief guarda la cadena en el campo de la estructura
 *
 * \param lista de empleados
 * \param numero entero
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_setSalary(Employee* this,int salary)
{
    int ret=-1;
    if(this!=NULL)
    {
        if(salary>1000 || salary<999999999)
        {
            this-> salary= salary;
            ret=0;
        }
    }
    return ret;
}

/** \brief toma el valor del campo
 *
 * \param lista de empleados
 * \param puntero al valor
 * \return 0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_getSalary(Employee* this,int* salary)
{
   int ret = -1;
    if(this!=NULL)
    {
        *salary = this->salary;
        ret = 0;
    }
    return ret;

}

/** \brief imprime un empleado
 *
 * \param lista de empleados
 * \return -
 *
 */
void emp_printEmployee(Employee* this)
{
    printf("%5d  %10s %10d  %10d\n",this->id, this->name, this->workingHours, this->salary);

}

/** \brief ordena por id
 *
 * \param void a empleado
 * \param void a empleado
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_sortById(void* empA, void* empB)
{
    int ret=0;
    int idUno;
    int idDos;

    emp_getId(empA, &idUno);
    emp_getId(empB, &idDos);

    if(empA!=NULL && empB!=NULL)
    {
        if(idUno > idDos)
        {
             ret = 1;
        }
        else if(idUno < idDos)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief ordena por nombre
 *
 * \param void a empleado
 * \param void a empleado
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_sortByName(void* empA, void* empB)
{
    int ret=0;
    char nameUno[51];
    char nameDos[51];

    emp_getName(empA, nameUno);
    emp_getName(empB, nameDos);

    if(empA!=NULL && empB!=NULL)
    {
        if(strcmp(nameUno, nameDos) > 0)
        {
             ret = 1;
        }
        else if(strcmp(nameUno, nameDos) < 0)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief ordena por horas trabajadas
 *
 * \param void a empleado
 * \param void a empleado
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_sortByWorkHours(void* empA, void* empB)
{
    int ret=0;
    int hoursUno;
    int hoursDos;

    emp_getWorkingHours(empA, &hoursUno);
    emp_getWorkingHours(empB, &hoursDos);

    if(empA!=NULL && empB!=NULL)
    {
        if(hoursUno > hoursDos)
        {
             ret = 1;
        }
        else if(hoursUno < hoursDos)
        {
            ret = -1;
        }
    }
    return ret;
}
/** \brief ordena por salario
 *
 * \param void a empleado
 * \param void a empleado
 * \return  0 si se pudo convertir, -1 si hubo error
 *
 */
int emp_sortBySalary(void* empA, void* empB)
{
    int ret=0;
    int salaryUno;
    int salaryDos;

    emp_getSalary(empA, &salaryUno);
    emp_getSalary(empB, &salaryDos);

    if(empA!=NULL && empB!=NULL)
    {
        if(salaryUno > salaryDos)
        {
             ret = 1;
        }
        else if(salaryUno < salaryDos)
        {
            ret = -1;
        }
    }
    return ret;
}
