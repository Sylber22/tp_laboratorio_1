#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char name[128];
    int workingHours;
    int salary;
}Employee;

Employee* emp_new();
Employee* emp_newParameters(char* pId,char* pName,char* pWorkingHours, char* pSalary);
int emp_Delete(Employee* this);

int emp_setId(Employee* this,int id);
int emp_setStrId(Employee* this, char* strId);
int emp_getId(Employee* this,int* id);

int emp_setName(Employee* this,char* name);
int emp_getName(Employee* this,char* name);

int emp_setWorkingHours(Employee* this,int workingHours);
int emp_setStrWorkingHours(Employee* this, char* strWorkingHours);
int emp_getWorkingHours(Employee* this,int* workingHours);

int emp_setSalary(Employee* this,int salary);
int emp_setStrSalary(Employee* this, char* strSalary);
int emp_getSalary(Employee* this,int* salary);
//------------------------------------------------
void emp_printEmployee(Employee* this);

int emp_sortByName(void* empleadoA, void* empleadoB);
int emp_sortById(void* empleadoA, void* empleadoB);
int emp_sortByWorkHours(void* empleadoA, void* empleadoB);
int emp_sortBySalary(void* empleadoA, void* empleadoB);

#endif // employee_H_INCLUDED
