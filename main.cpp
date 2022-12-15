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
#include <random>
#include <windows.system.h>
#undef max


using namespace std;

void ostoskarry(map<int, string>& varausLista){
	map<int, string>::iterator itr;
    cout << "\nVaraukset : \n";
    cout << "\tVarausnumero\tNimi\n";
    for (itr = varausLista.begin(); itr != varausLista.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << "\t" << itr->second
             << '\n';
    }
    cout << endl;
}


float alennusRand(){
	
	int aleRand = rand() % 2 + 1;

	switch (aleRand){
		case 1:
			return 0.9;
		case 2:
			return 0.8;
		default:
			return 1;
	}
}


void cinClear(int& annettu){ //Funktio joka ottaa syotteen muuttujaan ja katsoo onko se numero
	while (!(cin >> annettu)) {
		#undef max
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cin tyhjaksi ilman "taikanumeroa" kuten esim 256
		cout << "Ei ole numero\n";
	}
}

void cinClearSize(int& annettu, int size, int alkuNum){ //Funktio joka ottaa syotteen muuttujaan ja katsoo onko se numero 1-(annettu lukumaara) valilta
	
	if (alkuNum == 0){
		while (!(cin >> annettu) || !(annettu >= 0 && annettu <= size)) {
			#undef max
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "Ei ole numero 0-" << size << " valilla.\n";
		
		}
	}
	
	else{
		while (!(cin >> annettu) || !(annettu > 0 && annettu <= size)) {
			#undef max
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "Ei ole numero 1-" << size << " valilla.\n";
		
		}
	}
	// xd vähä tyhmä
}




void varaaJarjestelma(vector<bool>& huoneVektori, int yonHinta, map<int, string>& varausMap){ // Funktio jossa jarjestelma varaa sinulle huoneen vapaista olevista huoneista

	cout << "Jarjestelma varaa sinulle huoneen!" << endl;
	double alennus = alennusRand(); //arpoo luvun 1-max huoneet
	int tilausNumero = rand() %  99999 + 10000;


	while(true){
		

		int varausYot, aleRand = rand() % 2 + 1, huoneenNumero, huoneKoko;


		cout << "Yhden vai kahden hengen huone? (1=Yhden hengen, 2=Kahden hengen, 0 palaa takaisin menuun";
		cinClearSize(huoneKoko, 2, 0);


		// XD ei saa kysyy miks taa on tallee
		if (huoneKoko == 2){
			huoneenNumero = rand() % huoneVektori.size() + (huoneVektori.size()/2);
		}
		else if (huoneKoko == 0)
			break;
		else huoneenNumero = rand() % (huoneVektori.size()/2); 
		


		if (huoneVektori[huoneenNumero-1] == false){ // 
			string nimi;
			cout << "Kuinka monta yota haluat varata? (0 palaa takas päävalikkoon)\n\n";

			cinClear(varausYot); // pyytää funktiota ottamaan luvun (kuinka monta yota haluaa varata) ja katsomaan onko se numero

			if(varausYot == 0){ // voi menna takaisin menuun jos painoi vahingossa tätä numeroa
				break;
			}
			//cout << "\nHuoneen numero: " << huoneenNumero << "\n";
			huoneVektori[huoneenNumero-1] = true;
			cout << "\nHuone numero " << huoneenNumero <<" varattu!\nMille nimelle varataan?\n";
			cin.ignore();
			getline(cin, nimi);

			if (huoneenNumero >= (huoneVektori.size()/2)){
				cout << "Hinta: " << ((yonHinta+50)*alennus) * varausYot << "\n";	
			}
			else cout << "Hinta: " << (yonHinta * alennus) * varausYot << "\n";
			
			varausMap.insert(pair<int, string>(tilausNumero, nimi));


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


void varaaItse(vector<bool>& huoneVektori, int yoHinta, map<int, string>& varausMap) {
	int huoneNumero, aleRand = rand() % 2 + 1, yoMaara;
	double alennus = alennusRand();
	

	while (true){
		cout << "\nValitse huoneen numero: (Yhden henkilön huoneet numerosta 1-" << huoneVektori.size()/2 << ", loput ovat kahden henkilon huoneita " << "0 menee takaisin paavalikkoon)\n";
		
		cinClearSize(huoneNumero, huoneVektori.size(), 1);//ottaa input ja tarkistaa onko se numero 1-annetun luvun välillä



		if(!huoneVektori[huoneNumero-1]) {
			
			cout << "\nAnna oiden maara: (0 menee takaisin paavalikkoon)\n";

			cinClear(yoMaara);
			if (yoMaara == 0)
				break;

			huoneVektori[huoneNumero-1] = true;
			cout << "\nHuone "<< huoneNumero <<" varattu!";
			if (huoneNumero-1 >= (huoneVektori.size()/2)){
				cout << "Hinta: " << yoHinta+50 * yoMaara << "\n";	
			}
			else cout << "Hinta: " << yoHinta * yoMaara << "\n";

			break;
		}
		else {
			cout << "\nHuone "<< huoneNumero << " on jo varattu!" << endl;
		}

		if (huoneNumero == 0) {
			cout << "Palataan valikkoon.\n";
			break;
		}
	}
}

int main() {

	map<int,string> varaukset;



	// Koneen aika tollasena seedina randomi generointi homma bla bla
    srand((unsigned) time(NULL)); 

    int huoneMaara = rand() % 259 + 40, hinta = 100, toiminto;

	if (huoneMaara % 2 != 0)
		huoneMaara += 1;

	cout << "Tervetuloa hotelliin!\n";
	cout << "Huoneita on " << huoneMaara << endl;

	// Vektori jossa huoneet
	vector<bool> huoneet(huoneMaara,false);
	
	cout << huoneet.size() << endl;

	//menu 
	while (true) {
		if (roomChecker(huoneet) == 0) { // jos kaikki huoneet on varattu
			cout << "Kaikki huoneet varattu!\n";
			cout << "Tervetuloa uudestaan!\n";
			return 0;	// lopetetaan ohjelma
		}

		cout << "\nValitse toiminto:\n1. Valitse itse nummero\n2. Jarjestelma varaa vapaan huoneen\n3. Ostoskärry\n4. Lopeta\n";

		cinClearSize(toiminto, 4, 1);
		
		switch (toiminto) { 
		case 1:
			varaaItse(huoneet, hinta, varaukset);
			break;
		case 2:
			varaaJarjestelma(huoneet, hinta, varaukset);
			break;
		case 3:
			cout << "Ostoskärry\n";
			ostoskarry(varaukset);
			break;
			//ostoskarry();
		case 4:
			cout << "Tervetuloa uudestaan!\n";
			return 0;

		}
	}
}