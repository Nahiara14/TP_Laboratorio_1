/*
 * arrayEmployees.c
 *
 *  Created on: 15 may. 2021
 *      Author: Nahiara Zabaljauregui
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"

int menu()
{
    int opcion;

    system("cls");//limpiamos la pantalla
    printf("   *** ABM empleados ***\n\n");
    printf("1.Alta empleado\n");
    printf("2.Modificar\n");
    printf("3.Baja empleado\n");
    printf("4.Informar\n");
    printf("5.Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
int initEmployees(eEmployee list[], int len)
{
    int todoOk=0;
    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
            todoOk=1;
        }
    }
    return todoOk;
}
int findEmployee(eEmployee list[], int len)
{
    int indice=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int addEmployee(eEmployee list[], int len, int* pId)
{
    int todoOk=0;
    eEmployee auxEmpleado;
    int indice;

    system("cls");
    printf("    Alta empleado\n\n    ");
    printf("Id: %d\n\n", *pId);

    if( list != NULL && len >0 && pId != NULL)
    {

        indice=findEmployee(list, len);
        if(indice== -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxEmpleado.name);

            while(validarCadena(auxEmpleado.name)==0)
            {
                printf("Error, reingrese nombre: ");
                fflush(stdin);
                gets(auxEmpleado.name);
            }

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(auxEmpleado.lastName);

            while(validarCadena(auxEmpleado.lastName)==0)
            {
                printf("Error, reingrese apellido: ");
                fflush(stdin);
                gets(auxEmpleado.lastName);
            }

            auxEmpleado.salary=pedirNumero("Ingrese salario: ");




            auxEmpleado.sector=pedirNumero("Ingrese sector: ");




            auxEmpleado.id = *pId;
            auxEmpleado.isEmpty=0;
            *pId = *pId + 1;

            list[indice]=auxEmpleado;
            todoOk=1;

        }

    }
    return todoOk;
}


void printEmployee(eEmployee anEmployee)
{
    printf(" %d  %10s  %10s   %10.2f    %3d \n",
           anEmployee.id,
           anEmployee.name,
           anEmployee.lastName,
           anEmployee.salary,
           anEmployee.sector
          );
}
void printEmployees(eEmployee list[], int len)
{

    int flag=1;

    printf("-------------------------------------------\n");
    printf("   <<<<<   Listado de empleados   >>>>>\n\n");
    printf("--------------------------------------------\n");
    printf(" Id    nombre      apellido     salario    sector \n\n");

    if(list!= NULL && len >0)
    {

        for(int i=0; i<len; i++)
        {
            if( !list[i].isEmpty)
            {
                printEmployee(list[i]);
                flag=0;

            }

        }
        if(flag)
        {
            printf("No hay empleados que mostrar");
        }
        printf("\n\n");
    }
}
void printEmployeesMain(eEmployee list[], int len)
{
    sortEmployees(list,len);
    int flag=1;

    printf("-------------------------------------------\n");
    printf("   <<<<<   Listado de empleados   >>>>>\n\n");
    printf("--------------------------------------------\n");
    printf(" Id    nombre      apellido     salario    sector \n\n");
    for(int i=0; i<len; i++)
    {
        if( !list[i].isEmpty)
        {
            printEmployee(list[i]);
            flag=0;
        }

    }
    if(flag)
    {
        printf("No hay empleados que mostrar");
    }
    totalSalaryE(list, len);
    printf("\n\n");
}
int searchEmployee(eEmployee list[], int len,int id)
{
    int indice=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int modifyEmployee(eEmployee list[], int len)
{
    int todoOk=0;
    int id;
    int indice;
    int retorno;

    if(list!= NULL && len>0)
    {

    }
    printEmployees(list, len);
    printf("Ingrese el ID del empleado a modificar:\n ");
    scanf("%d", &id);

    indice=searchEmployee(list,len, id);

    if(indice==-1)
    {
        printf("Id no existente\n");
    }
    else
    {
        printf("Bienvenido a la modificacion de empleados\n");
        printf("¿Que quiere modificar?\n");
        printf("1.Nombre:\n");
        printf("2.Apellido:\n");
        printf("3.Salario:\n");
        printf("4.Sector:\n");

        printf("Ingrese opcion: ");
        scanf("%d",&retorno);

        switch(retorno)
        {
        case 1:
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(list[indice].name);
            todoOk=1;
            break;
        case 2:
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(list[indice].lastName);
            todoOk=1;
            break;
        case 3:
            printf("Ingrese salario: ");
            scanf("%f", &list[indice].salary);
            todoOk=1;
            break;
        case 4:
            printf("Ingrese sector: ");
            scanf("%d", &list[indice].sector);
            todoOk=1;
            break;

        }
    }
    return todoOk;
}
int removeEmployee(eEmployee list[], int len)
{
    int todoOk=0;
    int id;
    int indice;
    char seguir;

    printEmployees(list, len);
    printf("Ingrese el ID del empleado a dar la baja:\n ");
    scanf("%d", &id);

    indice=searchEmployee(list,len, id);

    if(indice==-1)
    {
        printf("Id no existente\n");
    }
    else
    {
        printf("Esta seguro que desea eliminar el empleado si o no?\n");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir=='s')
        {
            list[indice].isEmpty=1;
            todoOk=1;
        }
        else
        {
            printf("Se cancela la baja\n");
        }
    }
    return todoOk;
}
void sortEmployees(eEmployee list[], int len)
{
    eEmployee auxEmpleado;
    if(list!= NULL && len>0)
    {

        for(int i=0; i<len-1; i++)
        {
            for(int j= i+1; j<len; j++)
            {
                if( strcmp (list[i].lastName, list[j].lastName) >0  || (strcmp (list[i].lastName, list[j].lastName)==0 && list[i].sector >list[j].sector))
                {
                    auxEmpleado=list[i];
                    list[i]=list[j];
                    list[j]=auxEmpleado;
                }

            }
        }

    }
}
void totalSalaryE(eEmployee list[], int len)
{

    float total=0;
    int contador=0;
    int contador2=0;
    float promedio;

    printf("\n<<<<Total sueldo de los empleados<<<< \n");

    if(list!= NULL && len>0)
    {

        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                total+=list[i].salary;
                contador++;
            }
        }
        promedio=total/contador;

        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0 && list[i].salary > promedio)
            {
                contador2++;
            }
        }

    }

    printf("\nEl total del salario es %.2f\n\nEl promedio es %.2f\n\nY los empleados que superan el salario promedio son: %d\n\n",total, promedio,contador2);

}

int validarCadena(char* string)
{
    int retorno=0;
    int i=-1;
    int tamanio=strlen(string);

    for (i=0; i<tamanio; i++)
    {
        if (!((string[i]>='a' && string[i]<='z')|| (string[i]>='A' && string[i]<='Z') || string[i]=='\n' || string[i]=='\0') && tamanio>0)
        {
            retorno=0;
            break;
        }
    }
    if (i==tamanio)
    {
        retorno=1;
    }
    return retorno;
}

int pedirNumero(char mensaje[])
{
    int retorno;
    char num[10];

    printf("%s",mensaje);
    scanf("%s",num);

    for (int i = 0; i < strlen(num); i++)
    {
        while(!isdigit(num[i]) )
        {
            printf("Error. %s",mensaje);
            scanf("%s",num);
        }
        break;
    }

    retorno = atoi(num);

    return retorno;
}
