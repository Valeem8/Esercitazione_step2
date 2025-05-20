/*! @file Exponential.h
	@brief A class for Exponential functions
	@author Chiara Nobile e Valentina De Marchi

	Details.
*/

#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"

using namespace std;

class Exponential : public Function {

private:
	double b_coeff;
	double k_coeff;
	double c_coeff;

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Exponential();
	Exponential(const Exponential &p);
	~Exponential();
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Reset();
	/// @}

	/// @name GETTERS / SETTERS
	/// @{
	double GetBase();
	double GetCoeffK();
	double GetCoeffC();

	double GetValue(double in);

	void SetBase(double b);
	void SetCoeffK(double k);
	void SetCoeffC(double c);
	/// @}

	/// @name OPERATORS
	/// @{
	Exponential& operator=(const Exponential &p);
	bool operator==(const Exponential &p);
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