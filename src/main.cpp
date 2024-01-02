#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

int main() {
	bool dziala = true;
	while (dziala) {
		menu:
		int wybor;

		system("cls");
		cout << "=======================" << endl;
		cout << "Wybierz opcje:" << endl;
		cout << "0) Logowanie" << endl;
		cout << "1) Rejestracja" << endl;
		cout << "2) Wyjscie" << endl;
		cout << "=======================" << endl;
		cin >> wybor;

		string login;
		string haslo;
		fstream plik;
		string daneLogin;
		string daneHaslo;
		bool zalogowano = false;
		int iloscProbLogowania = 0;

		switch (wybor) {
			case 0:
				plik.open("src/Konta.txt", ios::in);
				
				while (!zalogowano) {
					cout << "login: ";
					cin >> login;
					cout << "haslo: ";

					//maskowanie hasla
					char znak;												
					haslo = "";
					while ((znak = _getch()) != '\r') {
						if (znak == '\b') {
							if (!haslo.empty()) {
								haslo.pop_back();							
								cout << "\b \b";
							}
						}
						else {
							haslo.push_back(znak);
							cout << '*';
						}
					}
					cout << endl;
					//

					while (!plik.eof() && !zalogowano) {
						plik >> daneLogin;
						plik >> daneHaslo;
						if (login == daneLogin && haslo == daneHaslo) {
							zalogowano = true;
						}
					}
					if (!zalogowano) {
						cout << "Bledne dane logowania!" << endl << endl;
						iloscProbLogowania++;
						if (iloscProbLogowania > 2) {
							goto menu;
						}
					}	
					plik.seekg(0, ios_base::beg);
				}
				cout << "Pomyslnie zalogowano!" << endl;

				plik.close();
				break;
			case 1:
				break;
			case 2:
				dziala = false;
				break;
			default:
				cin >> wybor;
			}
	}
	return 0;
}