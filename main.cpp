#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <sstream>
#include <climits> 
#include <windows.h>
#include <windows.system.h>
#undef max

using namespace std;



void cinClear(int& annettu){
	while (!(cin >> annettu)) {
		#undef max
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "Ei ole numero\n";
		//cin >> annettu;
	}
}

void cinClearSize(int& annettu, int size){
	while (!(cin >> annettu) || !(annettu > 0 && annettu <= size)) {
		#undef max
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "Ei ole numero 1-" << size << " valilla.\n";
		//cin >> annettu;
		
	}
	
}


void varaaJarjestelma(vector<bool>& huoneVektori, int yonHinta){

	while(true){
		int varausYot, huoneenNumero = rand() % huoneVektori.size(); //, jarjestelmaVaraus = rand() % huoneVektori.size();
		cout << "Jarjestelma varaa sinulle huoneen!" << endl;
		cout << "Kuinka monta yota haluat varata? (0 palaa takas päävalikkoon)\n\n";

		cinClear(varausYot);

		if(varausYot == 0){
			break;
		}

		if (huoneVektori[huoneenNumero-1] == false){
			//cout << "\nHuoneen numero: " << huoneenNumero << "\n";
			huoneVektori[huoneenNumero-1] = true;
			cout << "\nHuone numero " << huoneenNumero <<" varattu!\n";
			cout << "Hinta: " << yonHinta * varausYot << "\n";
			break;
		}
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
		cout << "Valitse huoneen numero: (0 menee takaisin paavalikkoon)\n\n";
		
		cinClearSize(huoneNumero, huoneVektori.size());//katso input

		if(huoneNumero > 0 && huoneNumero <= huoneVektori.size()){
			if(!huoneVektori[huoneNumero-1]) {
				
				cout << "\nAnna oiden maara: (0 menee takaisin paavalikkoon)\n";

				cinClear(yoMaara);
				if (yoMaara == 0)
					break;

				huoneVektori[huoneNumero-1] = true;
				cout << "\nHuone "<< huoneNumero <<" varattu!";
				cout << "\nHinta on " << yoHinta * yoMaara << " euroa.\n";
				break;
			}
			else {
				cout << "\nHuone "<< huoneNumero << " on jo varattu!" << endl;
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

		cout << "\nValitse toiminto:\n1. Valitse itse nummero\n2. Jarjestelma varaa vapaan huoneen\n3. Lopeta\n";

		cinClearSize(toiminto, 3);
		
		switch (toiminto) { 
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