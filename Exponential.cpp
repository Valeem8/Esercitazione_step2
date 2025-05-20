/*! @file Exponential.cpp
	@brief Implementation of class Exponential
	@author Chiara Nobile e Valentina De Marchi

	Details.
*/

#include "Exponential.h"


/// @brief default constructor
Exponential::Exponential(){

	cout << "-- DEFAULT CONSTRUCTOR EXPONENTIAL --" << endl;
	Init();

	}

/// @brief copy constructor
/// @param Si effettua solo il controllo della base poiché anche se k e c fossero 0 o < 0 la funzione ha senso.
Exponential::Exponential(const Exponential &p){	

	cout << "-- COPY CONSTRUCTOR EXPONENTIAL-- " << endl;
	cout << endl;

	if(p.b_coeff <= 0.){ 
		ErrorMessage("Copy constructor: the object to be copied has not a valid base");
		exit(-1);
	}
	b_coeff = p.b_coeff;
	k_coeff = p.k_coeff;
	c_coeff = p.c_coeff;
}

/// @brief destructor: it "reset" the values with the default ones
Exponential::~Exponential(){

	cout << "-- DEFAULT DESTRUCTOR Exponential --" << endl;
	Reset();

}
///@brief default inizialization of the object
void Exponential::Init(){

	SetBase(1);
	SetCoeffK(1);
	SetCoeffC(1);
}

///@brief total reset of the object
void Exponential::Reset(){

	Init();

}

/// @brief get base of exponential
/// @return b_coeff
double Exponential::GetBase(){

	return b_coeff;

}

/// @brief get coefficient of exponential
/// @return k_coeff
double Exponential::GetCoeffK(){

	return k_coeff;

}

/// @brief get exponent of exponential
/// @return c_coeff
double Exponential::GetCoeffC(){

	return c_coeff;

}

/// @brief returns the value of the function, given an input 
/// @param in the input
/// @return the value of the function
double Exponential::GetValue(double in){

	double x = in;
	double result = 0.0;

	if(b_coeff <= 0.){
		WarningMessage("The function has the base <= 0");
		exit(-1);
	}

	result = ((k_coeff)*pow(b_coeff,c_coeff*x));

	return result;
}

///@brief sets the value of the b_coeff
void Exponential::SetBase(double b){

	if (b <= 0.) {
		WarningMessage("-- SetBase: b_coeff should not be <= 0. Value not changed.");
		return;
	}
	b_coeff = b;
}

///@brief sets the value of the k_coeff
void Exponential::SetCoeffK(double k){

	k_coeff = k;
}

///@brief sets the value of the c_coeff
void Exponential::SetCoeffC(double c){

	c_coeff = c;
}

/// @brief overload of operator =
Exponential& Exponential::operator=(const Exponential &p){

	cout << "Exponential - operator = " << endl;

	if(b_coeff < 0){
		ErrorMessage("It is not possible to procede. Copy impossible.");
		exit(-1);
	}

	b_coeff = p.b_coeff;
	k_coeff = p.k_coeff;
	c_coeff = p.c_coeff;


	return *this;

}

/// @brief overload of operator ==
bool Exponential::operator==(const Exponential &p){

	if(b_coeff <= 0.){
		WarningMessage("The Exponential has base <= 0.");
		return false;
	}

	if(b_coeff != p.b_coeff || k_coeff != p.k_coeff || c_coeff != p.c_coeff)
		return false;

	return true;

}

/// @brief writes an error message 
/// @param string message to be printed
void Exponential::ErrorMessage(const char *string){

	cout << "--- ERROR Exponential---  " << string << endl;
	cout << endl;

}

/// @brief writes a warning message 
/// @param string message to be printed
void Exponential::WarningMessage(const char *string){

	cout << "--- WARNING Exponential---  " << string << endl;
	cout << endl;

}

/// @brief gives the status of the object 
void Exponential::Dump(){

	double b, k, c;

	cout << endl;
	cout << "---Dump Exponential--- " << endl;
	cout << endl;

	if (b_coeff <= 0.){
		WarningMessage("The Exponential is not valid");
		return;
	}

	b = GetBase();
	cout << "La base e' :  " << b << endl;
	cout << endl;
	k = GetCoeffK();
	cout << "Il coefficiente e':  " << k << endl;
	cout << endl;
	c = GetCoeffC(); 
	cout << "L'esponente e':  " << c << endl;
	cout << endl;

}
/// @brief print the function 
void Exponential::Dump2(){

	cout << endl;
	cout << "---Dump Exponential--- " << endl;
	cout << endl;
	cout << " " << k_coeff << "*" << b_coeff << "^" << "(x* " << c_coeff << ")" << endl;
	cout << endl;
}