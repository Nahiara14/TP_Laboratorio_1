/*
 ============================================================================
 Name        : Nahiara Zabaljauregui
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define LEN 1000

int main(void) {
	    setbuf(stdout,NULL);
	    eEmployee payroll[LEN];
	    int nextId=1;

	    initEmployees(payroll, LEN);

	    char salir='n';
	    int flag=0;

	    do
	    {
	        switch(menu())
	        {

	        case 1:
	            if( addEmployee(payroll,LEN, &nextId))
	            {
	                printf("Alta exitosa!!!\n");
	                flag=1;
	            }
	            else
	            {
	                printf("Sucedio un problema al realizar el alta\n");
	            }
	            break;
	        case 2:
	            system("cls");
	            if(flag!=0)
	            {
	                modifyEmployee(payroll,LEN);
	            }
	            else
	            {
	                printf("Error, primero deberia dar de alta un empleado\n");
	            }
	            break;
	        case 3:
	            system("cls");
	            if(flag!= 0)
	            {
	                removeEmployee(payroll,LEN);
	                flag--;
	            }
	            else
	            {
	                printf("Error, primero deberia dar de alta un empleado\n");
	            }
	            break;
	        case 4:
	            system("cls");
	            if(flag!=0)
	            {
	                printEmployeesMain(payroll,LEN);
	            }
	            else
	            {
	                printf("Error, primero deberia dar de alta un empleado\n");
	            }
	            break;
	        case 5:
	            printf("Esta seguro que quiere salir? ");
	            fflush(stdin);
	            scanf("%c", &salir);
	            break;
	        default:
	            printf("Opcion invalida\n");
	            system("pause");
	        }
	        system("pause");
	    }
	    while(salir=='n');
	return EXIT_SUCCESS;
}
