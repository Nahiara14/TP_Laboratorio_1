/*
 * interfazdeusuario.h
 *
 *  Created on: 14 abr. 2021
 *      Author: Nahiara
 */

#ifndef INTERFAZDEUSUARIO_H_
#define INTERFAZDEUSUARIO_H_

/** \brief muestra el menú de opciones
 *
 * \return char devuelve la opción seleccionada
 *
 */
int menu();


/** \brief
 *
 * \param a int primer operando
 * \param b int segundo operando
 * \param flagPrimerOperando int bandera del primer operando para saber si es la primera vez que se ingresa el numero o la segunda
 * \param flagSegundoOperando int bandera del segundo operando para saber si es la primera vez que se ingresa el numero o la segunda
 * \return void
 *
 */
void menuParametros(int a, int b, int flagPrimerOperando, int flagSegundoOperando);

/** \brief se pide el ingreso de un numero
 *
 * \param num1 int operando a evaluar
 * \return int devuelve el numero
 *
 */
int pedirnumeros(int num1);

#endif /* INTERFAZDEUSUARIO_H_ */
