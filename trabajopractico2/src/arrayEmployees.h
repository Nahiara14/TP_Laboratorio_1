/*
 * arrayEmployees.h
 *
 *  Created on: 15 may. 2021
 *      Author: Nahiara Zabaljauregui
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

#endif /* ARRAYEMPLOYEES_H_ */

/** \brief shows options menu
 *
 * \return int selected option
 *
 */
int menu();
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int initEmployees(eEmployee list[], int len);


/** \brief returns the index position in array.
 *
 * \param list[] eEmployee
 * \param len int
 * \return intemployee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployee(eEmployee list[], int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list[] eEmployee
 * \param len int
 * \param pId int*
 * \return int Return (0) if Error [Invalid length or NULL pointer or without
  free space] - (1) if Ok
 */
int addEmployee(eEmployee list[], int len, int* pId);

/** \brief prints the content of an employee's matrix, passing this function to print employees
 *
 * \param anEmployee eEmployee
 * \return void
 *
 */
void printEmployee(eEmployee anEmployee);

/** \brief  print the content of employees array
 *
 * \param list[] eEmployee
 * \param len int
 * \return void
 *
 */
void printEmployees(eEmployee list[], int len);

/** \brief search for employees with the same ID
 *
 * \param list[] eEmployee
 * \param len int
 * \return int Return employee index position or (-1) if [Invalid length or NULL
 pointer received or employee not found]
 *
 */
int searchEmployee(eEmployee list[], int len, int id);
//int freePlace(eEmployee list[], int len);

/** \brief modify the employee's data indicating their ID
 *
 * \param list[] eEmployee
 * \param len int
 * \return int int Return (0) if Error [Invalid length or NULL pointer or without
  free space] - (1) if Ok
 *
 */
int modifyEmployee(eEmployee list[], int len);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \return int Return (0) if Error [Invalid length or NULL pointer or if can't
find a employee] - (1) if Ok
 *
 */
int removeEmployee(eEmployee list[], int len);

/** \brief Sort the elements in the array of employees, the argument order
 *
 * \param list Employee*
 * \param len int
 * \return void
 *
 */
void sortEmployees(eEmployee list[], int len);

/** \brief  print the content of employees array
 *
 * \param list[] eEmployee
 * \param len int
 * \return void
 *
 */
void printEmployeesMain(eEmployee list[], int len);

/** \brief Calculate total and average salaries, how many employees exceed average salary and report
 *
 * \param list[] eEmployee
 * \param len int
 * \return void
 *
 */
void totalSalaryE(eEmployee list[], int len);

/** \brief validate that no numbers are entered
 *
 * \param string char*
 * \return int Return (0) if Error [Invalid length or NULL pointer or if can't
 find a employee] - (1) if Ok
 *
 */
int validarCadena(char* string);

/** \brief validates that no letters or string of characters are entered
 *
 * \param mensaje[] char
 * \return int number
 *
 */
int pedirNumero(char mensaje[]);
