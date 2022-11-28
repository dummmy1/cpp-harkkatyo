#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iterator>


using namespace std;

void varaaJarjestelma(){
	cout << "Varaa jarjestelma" << endl;
}


int roomChecker(vector<bool> huoneita){

	//iterate thorugh vector and check if any rooms are free
	for (int i = 0; i <= huoneita.size(); i++) { 
		if (huoneita[i] == false) {
			return 1;
		}
	}
	return 0;
	}


	void varaaItse(vector<bool> huoneVektori) {
		int huoneNumero;
		int hinta = rand() % 20 + 80, yoMaara;
		cout << "Valitse huoneen numero: ";
		cin >> huoneNumero;
		
		while (cin.fail()) { //kasitellaan virheellinen syote
			cout << "Ei ole numero\n";
			cin.clear();
			cin.ignore(256, '\n');
			
			cout << "Valitse huoneen numero: ";
			cin >> huoneNumero;
			
			if (!cin.fail())
				break;
		}





		if (!huoneVektori[huoneNumero-1]) {
			huoneVektori[huoneNumero-1] = true;
			cout << "Anna oiden maara: ";
			cin >> yoMaara;
			
			cout << "Hinta on " << hinta * yoMaara << " euroa.\n";
			cout << "Huone varattu!\n";
			
		}
		else {
			cout << "Huone on jo varattu\n";
		}

	}

int main() {
	int huoneMaara = rand() % 40 + 30, toiminto;
	cout << "Tervetuloa hotelliin!\n";
	cout << "Huoneita on " << huoneMaara << endl;

	vector<bool> huoneet(huoneMaara,false);
	cout << huoneet.size() << endl;

	
	while (true) {
		if (roomChecker(huoneet) == 0) { // jos kaikki huoneet on varattu
			cout << "Kaikki huoneet varattu!\n";
			cout << "Tervetuloa uudestaan!\n";
			return 0;	// lopetetaan ohjelma
		}
		cout << "Valitse toiminto:\n1. Valitse itse nummero\n2. Järjestelmä varaa vapaan huoneen\n3. Lopeta\n";
		cin >> toiminto;

		
		//kasitellaan virheellinen syote
		while (cin.fail()) {
			cout << "Ei ole numero 1-3\n";
			cin.clear();
			cin.ignore(256, '\n');	
			cout << "Valitse toiminto:\n1. Valitse itse nummero\n2. Järjestelmä varaa vapaan huoneen\n3. Lopeta\n";
			cin >> toiminto;
			if (!cin.fail() && toiminto > 0 && toiminto < 4){
				break;
			}		

		}
		switch (toiminto) { // switch case mitä tehdaan valitun numeron mukaan
		case 1:
			varaaItse(huoneet);
			break;
		case 2:
			varaaJarjestelma();
			break;
		case 3:
			cout << "Tervetuloa uudestaan!\n";
			return 0;
		}
	}


}

