/*! @file Power.h
	@brief A class for Power functions
	@author Chiara Nobile e Valentina De Marchi

	Details.
*/

#ifndef POWER_H
#define POWER_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"

using namespace std;

class Power : public Function {

private:
	double k_coeff;
	double e_coeff;

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Power();
	Power(const Power &p);
	~Power();
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Reset();
	/// @}

	/// @name GETTERS / SETTERS
	/// @{
	double GetCoeffK();
	double GetCoeffE();

	double GetValue(double in);

	void SetCoeffK(double k);
	void SetCoeffE(double e);
	/// @}

	/// @name OPERATORS
	/// @{
	Power& operator=(const Power &p);
	bool operator==(const Power &p);
	/// @}

	/// @name DEBUG and SERIALIZATION
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	void Dump2();
	/// @}
};

#endif