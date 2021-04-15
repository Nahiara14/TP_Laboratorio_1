#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

/*
 * operaciones.c
 *
 *  Created on: 14 abr. 2021
 *      Author: Nahiara
 */

int sumar(int a, int b)
{
    int resultado;

    resultado= a + b;

    return resultado;
}

int resta(int a, int b)
{
    int resultado;

    resultado=a-b;

    return resultado;

}

int dividir (int a, int b, float* resultado)
{
    int respuestaOk=0;

    if( b != 0 && resultado != NULL)
    {
        *resultado= (float) a/b;
        respuestaOk=1;
    }

    return respuestaOk;

}

int multiplicacion (int a, int b)
{

    int resultado;

    resultado= a*b;

    return resultado;

}

float factorial(int num)
{
    float resultado = 1;

    for (int i = 1; i <= num; i++)
    {
        resultado = resultado * i;
    }

    return (float) resultado;
}


