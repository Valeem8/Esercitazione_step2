/*! @file menu.cpp
	@brief Implementation of menu
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

int DisplayMenu(){

	int choice;

	cout << "Benvenuto nel menu" << endl;
	cout << "Seleziona una delle opzioni: " << endl;
	cout << " 0 - Esci dal menu" << endl;
	cout << " 1 - Visualizza la lista delle funzioni" << endl;
	cout << " 2 - Inserisci una funzione" << endl;
	cout << " 3 - Elimina una funzione" << endl;
	cout << " 4 - Elimina tutte le funzioni" << endl;
	cout << " 5 - Seleziona una funzione" << endl;
	cout << "Inserisci la scelta: " << endl;
	cin << choice << endl;
	return choice;
}

void ExitMenu(){

	cout << "Exiting the Menu..." << endl;
	exit(-1);
}

void DisplayFunc(*funct){

	int i = 0;
	for(i; i<funct.size(); i++){
		cout << "N. " << i << endl;
		funct[i].Dump2();
		cout << "_______________________________" << endl;
	}

}
void InsertFunc(*funct){

	int type = 0;
	request();//funzione da aggiungere
	cout << "Inserire il tipo di funzione da inserire: 1 per Polynomial, 2 per Exponential e 3 per Power " << endl;
	cin << type << endl;
	switch(type){
		case 1:
			Function *p = new Polynomial	//se viene inserito un secondo polinomio funziona ancora... controllare...
			if (p == NULL) {
			cout<<"Cannot allocate memory")<< endl;
			exit(-1);
			}
			funct.pushback(p);
			break;
			
		case 2:
			Function *e = new Exponential	//se viene inserito un secondo polinomio funziona ancora... controllare...
			if (e == NULL) {
			cout<<"Cannot allocate memory")<< endl;
			exit(-1);
			}
			funct.pushback(e);
			break;
			
		case 3:
			Function *po = new Power	//se viene inserito un secondo polinomio funziona ancora... controllare...
			if (po == NULL) {
			cout<<"Cannot allocate memory")<< endl;
			exit(-1);
			}
			funct.pushback(po);
			break;
			
		case default:
			cout<< "option not valid" <<endl;
			break;
	}
}