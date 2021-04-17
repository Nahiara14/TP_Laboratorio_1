/*
 ============================================================================
 Name        : calculadora_tp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operaciones.h"
#include "interfazdeusuario.h"

int main(void) {

	setbuf(stdout, NULL);

	char salir = 'n';
	int opcion;
	int num1;
	int num2;
	int flagPrimerOperando = 0;
	int flagSegundoOperando = 0;
	int flagMostrarResultados = 0;
	int resultadoSuma;
	int resultadoResta;
	float resultadoDiv;
	int respuesta;
	int resultadoMultiplicacion;
	int resultadoFact1;
	int resultadoFact2;

	do {

		system("@cls||clear");
		menuParametros(num1, num2, flagPrimerOperando, flagSegundoOperando);

		opcion = menu();

		switch (opcion) {
		case 1:
			num1 = pedirnumeros(num1);
			flagPrimerOperando = 1;
			system("pause");
			break;
		case 2:
			if (flagPrimerOperando)
			{
				num2 = pedirnumeros(num2);
				flagSegundoOperando = 1;
			} else
			{
				printf("Error, primero deberias ingresar el primer operando\n");
			}
			system("pause");
			break;
		case 3:
			if (!flagSegundoOperando)
			{
				printf("Primero deberias ingresar el primer y segundo operando\n");
			}
			else
			{
				resultadoSuma = sumar(num1, num2);
				respuesta = dividir(num1, num2, &resultadoDiv);
				resultadoResta = resta(num1, num2);
				resultadoMultiplicacion = multiplicacion(num1, num2);
				resultadoFact1 = factorial(num1);
				resultadoFact2 = factorial(num2);
				flagMostrarResultados = 1;
			}
			printf("Calculando las operaciones....\n");
			system("pause");
			break;
		case 4:
			if (!flagMostrarResultados)
			{
				printf("Error, primero deberias calcular las operaciones\n");
			}
			else
			{
				printf("El resultado de %d+%d es: %d\n", num1, num2,resultadoSuma);
				printf("El resultado de %d-%d es: %d\n", num1, num2,resultadoResta);
				if (respuesta)
				{
					printf("El resultado de %d/%d es: %.2f\n", num1, num2, resultadoDiv);
				}
				else
				{
					printf("No es posible dividir por 0\n");
				}
				printf("El resultado de %d*%d es: %d\n", num1, num2,resultadoMultiplicacion);
				printf("El resultado de !%d es: %d\n", num1, resultadoFact1);
				printf("El resultado de !%d es: %d\n", num2, resultadoFact2);
			}
			flagMostrarResultados = 0;
			flagPrimerOperando = 0;
			flagSegundoOperando = 0;
			system("pause");
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

	} while (salir == 'n');

	return EXIT_SUCCESS;
}
