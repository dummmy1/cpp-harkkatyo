#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>


using namespace std;

void varaaHuone(int huoneNum, bool varatutHuoneet[]) {
	int hinta = 100, yoMaara;

	if (!varatutHuoneet[huoneNum-1]) {
		varatutHuoneet[huoneNum-1] = true;
		cout << "Anna oiden maara: ";
		cin >> yoMaara;
		
	
		cout << "Hinta on " << hinta * yoMaara << " euroa.\n";
		cout << "Huone varattu!\n";
		

	}
	else {
		cout << "Huone on jo varattu\n";
	}
}

const int randomInt() {
	{
		return rand() % 10 + 1;
	}
}

int main() {

	const int hRooms = 100;
	int huoneNumero;

	bool varatut[hRooms] = {}, allTrue;

	while (true) {
		allTrue = (end(varatut)) == find(begin(varatut), end(varatut), false);
		if (allTrue) {
			cout << "Kaikki huoneet varattu!\n";
			cout << "Hei hei\n";
			return 0;
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
		
		if (huoneNumero > 0 && huoneNumero <= hRooms) {
			varaaHuone(huoneNumero,varatut);

		}
		
		else {
			cout << "Huonetta ei ole olemassa!" << endl;
		}	
	}

}

