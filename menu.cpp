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

using namespace std;
#define DIM 10

///@brief stampa le diverse voci del menu
///@param Nella variabile choice viene salvata la scelta: si controlla che sia un numero che sia ammesso
///@return Restituisce il valore di choice da usare per passare al case corrispondente nello switch del main
int DisplayMenu(){

	int choice;

	cout << "Benvenuto nel menu'" << endl;
	cout << "Seleziona una delle opzioni: " << endl;
	cout << " 0 - Esci dal menu'" << endl;
	cout << " 1 - Visualizza la lista delle funzioni" << endl;
	cout << " 2 - Inserisci una funzione" << endl;
	cout << " 3 - Elimina una funzione" << endl;
	cout << " 4 - Elimina tutte le funzioni" << endl;
	cout << " 5 - Seleziona una funzione" << endl;
	cout << "Inserisci la scelta: " << endl;
	while (!(cin >> choice)) {
		cout << "Input non valido. Inserire un numero: " << endl;
		cin.clear(); 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	return choice;
}

///@brief Esce dal menu e dal programma
///@param Non è necessario deallocare poichè il vector (istanziato nel main e mai allocato)
void ExitMenu(){

	cout << "Uscita dal Menu'..." << endl;
	exit(-1);
}

///@brief Stampa tutte le funzioni aggiunte nel vector
///@brief Si è scelto di stampare come numero identificativo la posizone nel vector +1 escludendo lo 0 come identificativo
void DisplayFunc(vector<Function*> &funct){

	if(funct.empty()){
		cout << "Nessuna funzione presente" << endl;
		cout << endl;
	}
	else{
		for(long unsigned int i=0; i<(funct.size()); i++){
			cout << "N. " << (i+1);
			cout << "	 ";
			funct.at(i)->Dump2();
			cout << "_____________________________________________________________________________" << endl;
		}
	}
}
///@brief Permette di aggiungere una funzione. 
///@brief Viene creato uno oggetto della classe indicata e aggiunto al fondo del vector
///@param La DIM viene definita al di fuori della funzione e può essere modificata prima di eseguire il programma
///@param Se si scegli lìopzione -1 si torna al menù principale
vector<Function*> InsertFunc(vector<Function*> &funct){

	int type = 0;
	int size = 0;
	int i;
	double b1, k1, c1, k2, e2;
	double pol[DIM]; // dichiaro vettore di dimensione fornita dall'utente
	Polynomial* P = new Polynomial();
	Exponential* E = new Exponential();
	Power* B = new Power();

//Scelta del nuovo oggetto, se non si inserisce una tra le possibilità viene chiesto nuovamente di scegliere altrimenti con -1 si esce
	cout << "Inserire il tipo di funzione da inserire: 1 per Polynomial, 2 per Exponential, 3 per Power";
	cout << " e -1 per non inserire ed uscire dal menu'" << endl;
	while (!(cin >> type)) {
		cout << "Input non valido. Inserire un numero: 1, 2, 3 o -1 : " << endl;
		cin.clear(); 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	switch(type){
//Caso 1: Polynomial
		case 1:
			if (P == NULL) {
				cout<<"Impossibile allocare"<< endl;
				break;
			}
			cout << "Type the dimension of the polynomial: " << endl;
//controllo che la size inserita sia effettivamente un numero di tipo int
			do {
				while (!(cin >> size)) {
					cout << "Input non valido. Inserire un numero > 0 e <= " << DIM << ": " << endl;
					cin.clear(); 
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if ((size > DIM) || (size < 1)){
					cout << "Input non valido. Inserire un numero > 0 e <= " << DIM << ": " << endl;
					cin.clear(); 
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} while ((size > DIM) || (size < 1));

//pulisco buffer input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
			for(i=0; i<size; i++){
				cout << "Inserire il coefficiente " << i <<endl;
//controllo che ciascun coefficiente inserito sia effettivamente un numero e di type giusto
				while (!(cin >> pol[i])) {
					cout << "Input non valido. Inserire nuovamente il coefficiente n. " << i << endl;
					cin.clear(); 
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;
			}
//chiedo conferma del polinomio da inserire, se viene data la conferma allora lo si aggiunge al vector altrimenti si dealloca il puntatore
			P->SetPolynomial(pol, size);
			if(request(P)){
				funct.push_back(P);
				cout << "La funzione e' stata inserita" << endl;
				cout << endl;
			}
			else{
				cout << "Annullamento inserimento..." << endl;
				cout << endl;
				delete P;
			}
			break;
//Caso 2: Exponential
		case 2:
			if (E == NULL) {
				cout<<"Impossibile allocare"<< endl;
				break;
			}
//definisco i valori dell'Exponential
			cout << "Inserire la base: " << endl;
//controllo che ciascun coefficiente inserito sia effettivamente un numero, di type giusto e non sia <=0
			do {
				while (!(cin >> b1)) {
					cout << "Input non valido. Inserire nuovamente la base: " << endl;
					cin.clear(); 
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (b1 <= 0){
					cout << "Input non valido. Inserire nuovamente la base: " << endl;
					cin.clear(); 
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} while (b1 <= 0);

//pulisco buffer input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Inserire il coefficiente: " << endl;
//controllo che ciascun coefficiente inserito sia effettivamente un numero e di type giusto
			while (!(cin >> k1)) {
				cout << "Input non valido. Inserire nuovamente il coefficiente: " << endl;
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

//pulisco buffer input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Inserire l'esponente: " << endl;
//controllo che ciascun coefficiente inserito sia effettivamente un numero e di type giusto
			while (!(cin >> c1)) {
				cout << "Input non valido. Inserire nuovamente l'esponente: " << endl;
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

//pulisco buffer input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			E->SetBase(b1); //b1 viene controllata quando viene chiesta prima
			E->SetCoeffK(k1);
			E->SetCoeffC(c1);
//chiedo conferma dell'Exponential da inserire, se viene data la conferma allora lo si aggiunge al vector altrimenti si dealloca il puntatore
			if(request(E)){
				funct.push_back(E);
				cout << "La funzione e' stata inserita" << endl;
				cout << endl;
			}
			else{
				cout << "Annullamento inserimento..." << endl;
				cout << endl;
				delete E;
			}
			break;
//Caso 3: Power
		case 3:
			if (B == NULL) {
				cout<<"Cannot allocate memory"<< endl;
				exit(-1);
			}
//definisco i valori del Power
			cout << "Inserire il coefficiente: " << endl;
//controllo che ciascun coefficiente inserito sia effettivamente un numero e di type giusto
			while (!(cin >> k2)) {
				cout << "Input non valido. Inserire nuovamente il coefficiente: " << k2 << endl;
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

//pulisco buffer input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Inserire l'esponente: " << endl;
//controllo che ciascun coefficiente inserito sia effettivamente un numero e di type giusto
			while (!(cin >> e2)) {
				cout << "Input non valido. Inserire nuovamente l'esponente: " << e2 << endl;
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

//pulisco buffer input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//chiedo conferma della Power da inserire, se viene data la conferma allora lo si aggiunge al vector altrimenti si dealloca il puntatore
			B->SetCoeffK(k2);
			B->SetCoeffE(e2);
			if(request(B)){
				funct.push_back(B);
				cout << "La funzione e' stata inserita" << endl;
				cout << endl;
			}
			else{
				cout << "Annullamento inserimento..." << endl;
				cout << endl;
				delete B;
			}
			break;

		case -1:
			cout << "Uscita dal menu di inserimento della funzione..." << endl;
			break;
			
		default:
			cout<< "Opzione non valida" << endl;
			cout << endl;
			break;
	}
	cout << endl;
	cout << endl;
	return funct;
}
///@brief Chiede conferma se si vuole inserire la funzione creata mostrandone prima la stampa finale
///@param Nella variabile c viene salvata la scelta
///@return Restituisce TRUE se si da conferma altrimenti FALSE se si decide di non inserire la funzione
bool request(Function *ptr){

	int c; 
	cout << "Questa e' la funzione inserita: ";
	ptr->Dump2();
	cout << endl;
	cout << "Se la si vuole inserire digitare 1 altrimenti 0: " << endl;
//controllo che sia stato inserito un numero
	do {
		while (!(cin >> c)) {
			cout << "Input non valido. Inserire nuovamente o 1 o 0: " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if ((c != 0) && (c != 1)){
			cout << "Input non valido. Inserire nuovamente o 1 o 0: " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while ((c != 0) && (c != 1));

//pulisco buffer input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	switch(c){
		case 0:
			return false;
			break;

		case 1:
			return true;
			break;

		default:
			cout << "Il valore inserito non e' valido exiting..." << endl;
			break;
	}
	return false;
}

///@brief Cancella una funzione aggiunta
///@param Nella variabile i salva il numero della funzione: i-1 poichè viene stampato come numero identificativo la posizione nell'array + 1 e poichè le posizioni sono numerate da 0 è necessario aggiungere -1
vector<Function*> DeleteFunc(vector<Function*> &funct){

	long unsigned int pos;
	Function *ptr;

	if(funct.empty()){
		cout << "Nessuna funzione presente" << endl;
		cout << endl;
	}
	else{
		cout << "Scegliere tra una delle seguenti funzioni elecante di seguito da eliminare" << endl;
		cout << endl;
		DisplayFunc(funct);
		cout << "Inserire il numero di riferimento della funzione che si desidera eliminare: " << endl;
		do {
			while (!(cin >> pos)) {
				cout << "Input non valido. Inserire il numero di riferimento della funzione che si desidera eliminare: " << endl;
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (pos <= 0 || pos > funct.size()){
				cout << "Input non valido. Inserire il numero di riferimento della funzione che si desidera eliminare: " << endl;
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (pos <= 0 || pos > funct.size());

//pulisco buffer input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		pos = pos-1;
		ptr = funct[pos];
//rimuove l'elemento dal vettore
		funct.erase(funct.begin() + pos);
//libera spazio da puntatore
		delete ptr;
	}

		return funct;
}

///@brief Cancella tutte le funzioni aggiunte nel vector
///@return Restituisce il puntatore al vector senza alcun elemento
vector<Function*> DeleteAll(vector<Function*> &funct){

	Function *ptr;

	if(funct.empty()){
		cout << "Nessuna funzione presente" << endl;
		cout << endl;
	}
	else{
		
		for(long int i=funct.size()-1;i>=0; i--){
			ptr = funct[i];
			funct.erase(funct.begin() + i);
//libera spazio da puntatore
			delete ptr;
		}
	}
	
	return funct;
}

///@brief Permette di scegliere una funzione tra quelle nel vettore e di calcolarne il valore per uno specifico valore di x
///@param Il valore di x viene chiesto dopo aver scelto la funzione entrambi con opportuni controlli che non vengano passati valori non compatibili
void SelectFunc(vector<Function*> &funct){

	double result, x = 0;
	long unsigned int pos = 0;
	
	if(funct.empty()){
		cout << "Nessuna funzione presente" << endl;
		cout << endl;
	}
	else{
		DisplayFunc(funct); //visualizzo la lista delle funzioni disponibili
		cout << "Inserire il numero di riferimento: " << endl;
		do {
			while (!(cin >> pos)) {
				cout << "Input non valido. Inserire un numero di riferimento: " << endl;
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (pos <= 0 || pos > funct.size()){
				cout << "Input non valido. Inserire un numero di riferimento: " << endl;
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (pos <= 0 || pos > funct.size());

//pulisco buffer input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		pos = pos-1;
		cout << "Inserire il valore di x per cui calcolare la funzione: " << endl;
		while (!(cin >> x)) {
			cout << "Input non valido. Inserire il valore di x per cui calcolare la funzione: " << endl;
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

//pulisco buffer input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		result = funct.at(pos)->GetValue(x);
		cout << "La funzione calcolata per x = " << x << " vale: " << result <<endl;
		cout << endl;
	}
}
