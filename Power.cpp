/*! @file Power.cpp
	@brief Implementation of class Power
	@author Chiara Nobile e Valentina De Marchi

	Details.
*/

#include "Power.h"


/// @brief default constructor
Power::Power(){

	cout << "-- DEFAULT CONSTRUCTOR POWER --" << endl;
	Init();

	}

/// @brief copy constructor
Power::Power(const Power &p){

	cout << "-- COPY CONSTRUCTOR POWER-- " << endl;
	cout << endl;

	k_coeff = p.k_coeff;
	e_coeff = p.e_coeff;
}

/// @brief destructor 
Power::~Power(){

	cout << "-- DEFAULT DESTRUCTOR POWER --" << endl;
	Reset();

}
///@brief default inizialization of the object
void Power::Init(){

	SetCoeffK(1);
	SetCoeffE(1);
}

/// @brief destructor: it "reset" the values with the default ones
void Power::Reset(){

	Init();

}

/// @brief get coefficient of power
/// @return k_coeff
double Power::GetCoeffK(){

	return k_coeff;

}

/// @brief get exponent of power
/// @return e_coeff
double Power::GetCoeffE(){

	return e_coeff;

}

/// @brief returns the value of the function, given an input 
/// @param in the input
/// @return the value of the function
double Power::GetValue(double in){

	double result;
	double x = in;

	result = ((k_coeff) * pow(x,e_coeff));

	return result;
}


///@brief sets the value of the k_coeff
void Power::SetCoeffK(double k){

	k_coeff = k;
}

///@brief sets the value of the e_coeff
void Power::SetCoeffE(double e){

	e_coeff = e;
}

/// @brief overload of operator =
Power& Power::operator=(const Power &p){

	cout << "Power - operator = " << endl;

	k_coeff = p.k_coeff;
	e_coeff = p.e_coeff;

	return *this;

}

/// @brief overload of operator ==
bool Power::operator==(const Power &p){

	if(k_coeff != p.k_coeff || e_coeff != p.e_coeff)
		return false;

	return true;
}

/// @brief writes an error message 
/// @param string message to be printed
void Power::ErrorMessage(const char *string){

	cout << "--- ERROR Power---  " << string << endl;
	cout << endl;

}

/// @brief writes a warning message 
/// @param string message to be printed
void Power::WarningMessage(const char *string){

	cout << "--- WARNING Power---  " << string << endl;
	cout << endl;

}

/// @brief gives the status of the object 
void Power::Dump(){

	double k, e;

	cout << endl;
	cout << "---Dump Power--- " << endl;
	cout << endl;

	k = GetCoeffK();
	cout << "Il coefficiente e':  " << k << endl;
	cout << endl;
	e = GetCoeffE();
	cout << "L'esponente e':  " << e << endl;
	cout << endl;

}
/// @brief print the function 
void Power::Dump2(){

	cout << endl;
	cout << "--Power-- ";
	cout << " " << k_coeff << "*x^(" << e_coeff << ")" << endl;

}
