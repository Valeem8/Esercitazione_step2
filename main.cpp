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
			DisplayFunc(funct);
			break;
			
		case 2:
			InsertFunc(funct);
			break;
		
		case 3:
			DeleteFunc(funct);
			break;
		
		case 4:
			DeleteAll(funct);
			break;
		
		case 5:
			SelectFunc(funct);
			break;
	
		default:
			cout << endl;
			cout <<"Scelta non possibile. Riprovare."<< endl;
			cout << endl;
			break;
		}
	}
	return 0;
}
