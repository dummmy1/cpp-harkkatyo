#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iterator>


using namespace std;

void varaaHuone(int huoneNum, vector<bool> huoneita) {
	int hinta = rand() % 20 + 80, yoMaara;

	if (!huoneita[huoneNum-1]) {
		huoneita[huoneNum-1] = true;
		cout << "Anna oiden maara: ";
		cin >> yoMaara;
		
		cout << "Hinta on " << hinta * yoMaara << " euroa.\n";
		cout << "Huone varattu!\n";
		
	}
	else {
		cout << "Huone on jo varattu\n";
	}
}
	int roomChecker(vector<bool> huoneita){

		//iterate thorugh vector and check if any rooms are free
		for (int i = 0; i < huoneita.size(); i++) {
			if (huoneita[i] == false) {
				return 1;
			}
		}
		return 0;

		// for (auto & huone : huoneita){
		// 	if (huoneita[huone] == false) 
		// 		return 1;
		// }
		// return 0;

	}

int main() {
	int huoneMaara = rand() % 40 + 30;
	cout << "Tervetuloa hotelliin!\n";
	cout << "Huoneita on " << huoneMaara << endl;

	vector<bool> huoneet(huoneMaara,false);
	int huoneNumero;
	
	while (true) {
		if (roomChecker(huoneet) == 0){ // jos kaikki huoneet on varattu
			cout << "Kaikki huoneet varattu!\n";
			cout << "Hei hei\n";
			return 0;	// lopetetaan ohjelma
		}

		cout << "Valitse huoneen numero: ";
		cin >> huoneNumero;
		

		while (cin.fail()) {
			cout << "Ei ole numero\n";
			cin.clear();
			cin.ignore(256, '\n');
			
			cout << "Valitse huoneen numero: ";
			cin >> huoneNumero;
			
			if (!cin.fail())
				break;
		}
		
		if (huoneNumero > 0 && huoneNumero <= huoneMaara) {
			varaaHuone(huoneNumero,huoneet);

		}
		
		else {
			cout << "Huonetta ei ole olemassa!" << endl;
		}	
	}

}

