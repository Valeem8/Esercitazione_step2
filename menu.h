/*! @file menu.h
	@brief Function to manage menu
	@author Chiara Nobile e Valentina De Marchi

	Details.
*/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstring>
#include "CFunction.h"
#include "Polynomial.h"
#include "Exponential.h"
#include "Power.h"

	void main();
	
///@brief print the different options
	int DisplayMenu();
	
///@brief exit the menu
	void ExitMenu();
	
///@brief print all the functions
	void DisplayFunc();

///@brief allow to add a function
	void InsertFunc();

///@brief delete a function added
	void DeleteFunc();
	
///@brief delete all the functions added
	void DeleteAll();

///@brief Select a function among the added ones and obtain its value for a specific value of x
	double SelectFunc(double x);

#endif
