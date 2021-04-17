/*
 * operaciones.h
 *
 *  Created on: 14 abr. 2021
 *      Author: Nahiara
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_


/** \brief Realiza la suma entre dos numeros enteros
 *
 * \param a int primer operando
 * \param b int segundo operando
 * \return la suma de dos numeros enteros
 *
 */
 int sumar(int a , int b);

/** \brief Realiza la división entre dos enteros
 *
 * \param a dividendo de la operación
 * \param b divisor de la operación
 * \param float* resultado puntero
 * \return 1 si la división se logró o 0 si no se pudo lograr
 *
 */
 int dividir (int a, int b, float* resultado);


/** \brief Me va a restar dos numeros enteros
 *
 * \param a int primero operando
 * \param b int segundo operando
 * \return resultado de la resta de los dos operandos
 *
 */
int resta(int a, int b);

/** \brief multiplica dos numeros enteros
 *
 * \param a primer operando
 * \param b segundo operando
 * \return la multiplicación de un numero entero
 *
 */
int multiplicacion (int a, int b);

/** \brief Toma un numero, no puede ser mayor a 16 ni negativo
 *
 * \param num int numero a calcular
 * \return float devuelve su factorial
 *
 */
float factorial(int num);

#endif /* OPERACIONES_H_ */
