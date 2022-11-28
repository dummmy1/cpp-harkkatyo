#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include<cstdlib>


using namespace std;

void varaaJarjestelma(vector<bool>& huoneVektori, int yonHinta){
	int varausYot, huoneenNumero = rand() % huoneVektori.size(), jarjestelmaVaraus = rand() % huoneVektori.size();
	cout << "Jarjestelma varaa sinulle huoneen!" << endl;
	cout << "Kuinka monta yota haluat varata?\n";
	cin >> varausYot;
	if (huoneVektori[huoneenNumero] == false){
		cout << "Huoneen numero: " << huoneenNumero << endl;
		cout << "Hinta: " << yonHinta * varausYot << endl;
		huoneVektori[huoneenNumero] = true;
	}

}


int roomChecker(vector<bool>& huoneita){

	//rullaa läpi ja katsoo onko huoneita vapaana
	for (int i = 0; i < huoneita.size(); i++) { 
		if (huoneita[i] == false) {
			return 1;
		}
	}
	return 0;
}


void varaaItse(vector<bool>& huoneVektori, int yoHinta) {
	int huoneNumero;
	int yoMaara;

	while (true){
		cout << "Valitse huoneen numero: (0 menee takaisin paavalikkoon)\n";
		cin >> huoneNumero;
		
		while (cin.fail()) { //kasitellaan virheellinen syote
			cout << "Ei ole numero\n";
			cin.clear();
			cin.ignore(256, '\n');
			
			cout << "Valitse huoneen numero: ";
			cin >> huoneNumero;
			
			if (!cin.fail()) {
				break;
			}
			else {
				cout << "Ei ole numero 1-"<< huoneVektori.size() << endl;
			}
		}
		if(huoneNumero > 0 && huoneNumero <= huoneVektori.size()){
			if(!huoneVektori[huoneNumero-1]) {
				
				cout << "Anna oiden maara: ";
				cin >> yoMaara;
				

				while (cin.fail()) { //kasitellaan virheellinen syote
					cout << "Ei ole numero\n";
					cin.clear();
					cin.ignore(256, '\n');
					
					cout << "Anna oiden maara: ";
					cin >> yoMaara;
					
					if (!cin.fail()) {
						break;
					}
				}


				cout << "Hinta on " << yoHinta * yoMaara << " euroa.\n";
				cout << "Huone varattu!\n";
				huoneVektori[huoneNumero-1] = true;
				break;
			}
			else {
				cout << "Huone on jo varattu!" << endl;
			}
		}

		else if (huoneNumero == 0) {
			cout << "Palataan valikkoon.\n";
			break;
		}
		else if (huoneNumero > huoneVektori.size()){
			cout << "Huonetta ei ole olemassa.\n";
		}

	}

}

int main() {

	// Koneen aika tollasena auttavana randomi generointi hommana
    srand((unsigned) time(NULL)); 

    int huoneMaara = rand() % 40 + 30, hinta = rand() % 20 + 80, toiminto;

	cout << "Tervetuloa hotelliin!\n";
	cout << "Huoneita on " << huoneMaara << endl;

	// Vektori jossa huoneet
	vector<bool> huoneet(huoneMaara,false);
	cout << huoneet.size() << endl;

	
	while (true) {
		if (roomChecker(huoneet) == 0) { // jos kaikki huoneet on varattu
			cout << "Kaikki huoneet varattu!\n";
			cout << "Tervetuloa uudestaan!\n";
			return 0;	// lopetetaan ohjelma
		}
		cout << "Valitse toiminto:\n1. Valitse itse nummero\n2. Jarjestelma varaa vapaan huoneen\n3. Lopeta\n";
		cin >> toiminto;

		
		//kasitellaan virheellinen syote
		while (cin.fail()) {
			cout << "Ei ole numero 1-3\n";
			cin.clear();
			cin.ignore(256, '\n');	
			cout << "Valitse toiminto:\n1. Valitse itse nummero\n2. Jarjestelma varaa vapaan huoneen\n3. Lopeta\n";
			cin >> toiminto;
			if (!cin.fail() && toiminto > 0 && toiminto < 4){
				break;
			}		

		}
		switch (toiminto) { // switch case mitä tehdaan valitun numeron mukaan
		case 1:
			varaaItse(huoneet, hinta);
			break;
		case 2:
			varaaJarjestelma(huoneet, hinta);
			break;
		case 3:
			cout << "Tervetuloa uudestaan!\n";
			return 0;
		}
	}


}

