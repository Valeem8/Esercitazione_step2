/*! @file menu.h
	@brief Function to manage menu
	@author Chiara Nobile e Valentina De Marchi

	Details.
*/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstring>
#include <vector>
#include "CFunction.h"
#include "Polynomial.h"
#include "Exponential.h"
#include "Power.h"

	/// @name DISPLAY
	/// @{
	int DisplayMenu();
	void DisplayFunc(vector<Function*> &funct);
	/// @}

	void ExitMenu();

	/// @name OPERATORS
	/// @{
	vector<Function*> InsertFunc(vector<Function*> &funct);
	vector<Function*> DeleteFunc(vector<Function*> &funct);
	vector<Function*> DeleteAll(vector<Function*> &funct);
	void SelectFunc(vector<Function*> &funct);
	/// @}

	bool request(Function *ptr);

#endif
