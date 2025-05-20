/*! @file main.cpp
	@brief execution of menu
	@author Chiara Nobile e Valentina De Marchi

	Details.
*/

#include <iostream>
#include <cstring>
#include <vector>
#include "CFunction.h"
#include "Polynomial.h"
#include "Exponential.h"
#include "Power.h"
#include "menu.h"

#define SIZE 10

using namespace std;

int main(){

	int choice = 10;
	vector<Function*> funct;
	
	while(choice != 0){
	
	choice = DisplayMenu();
		switch (choice){

		case 0:
			ExitMenu();
			break;
			
		case 1:
			DisplayFunc(*funct);
			break;
			
		case 2:
			InsertFunc();
			break;
		
		case 3:
			DeleteFunc();
			break;
		
		case 4:
			DeleteAll();
			break;
		
		case 5:
			SelectFunc(double x);
			break;
	
		default:
			cout <<"Not allowed choice. Try again!"<< endl;
			break;
		}
	}
	return 0;
}
