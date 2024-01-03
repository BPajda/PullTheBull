#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

int main() {
	bool dziala = true;
	while (dziala) {
		menu:
		char wybor;

		system("cls");
		cout << "=======================" << endl;
		cout << "Wybierz opcje:" << endl;
		cout << "0) Logowanie" << endl;
		cout << "1) Rejestracja" << endl;
		cout << "2) Wyjscie" << endl;
		cout << "=======================" << endl;
		wybor = _getch();

		string login = "";
		string haslo = "";
		fstream plik;
		string daneLogin;
		string daneHaslo;
		bool zalogowano = false;
		int iloscProbLogowania = 0;
		string imie;
		string nazwisko;
		string telefon;
		string email;
		string wiersz;

		switch (wybor) {
			case '0':
				plik.open("src/Konta.txt", ios::in);
				system("cls");
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
					while (plik >> daneLogin >> daneHaslo && !zalogowano) {
						getline(plik, wiersz);												// pominiecie reszty danych w bie¿¹cej linijce
						if (login == daneLogin && haslo == daneHaslo) {
							zalogowano = true;
						}
					}

					plik.clear();															// powrót wskaŸnika kursora w pliku na jego pocz¹tek
					plik.seekg(0, ios_base::beg);

					if (!zalogowano) {
						cout << "Bledne dane logowania!" << endl << endl;
						iloscProbLogowania++;
						if (iloscProbLogowania > 2) {
							goto menu;
						}
					}	
				}
				while (zalogowano) {
					cout << "Zalogowano, wpisz \"x\" aby wrocic do menu" << endl;
					if (_getch() == 'x') {
						goto menu;
					}
				}
				cout << "Pomyslnie zalogowano!" << endl;
				plik.close();
				break;
			case '1':
				cout << "======== Tworzenie konta ========" << endl;
				cout << "Podaj imie: ";
				cin >> imie;
				cout << "Podaj nazwisko: ";
				cin >> nazwisko;
				cout << "Podaj telefon: ";
				cin >> telefon;
				cout << "Podaj email: ";
				cin >> email;
				tworzenieLoginu:
				cout << "Utworz login: ";
				cin >> login;

				plik.open("src/Konta.txt", ios::in);
				while (plik >> daneLogin) {
					getline(plik, wiersz);
					if (login == daneLogin) {
						cout << "Podany login jest juz wykorzystany!" << endl;
						plik.close();
						goto tworzenieLoginu;
					}
				}
				plik.close();

				cout << "Utworz haslo: ";
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
				plik.open("src/Konta.txt", ios::out | ios_base::app);
				plik << login << "\t" << haslo << "\t" << imie << "\t" << nazwisko << "\t" << telefon << "\t" << email << "\t" << 0 << "\t" << 0 << "\n";
				plik.close();
				
				break;
			case '2':
				dziala = false;
				break;
			default:
				goto menu;
			}
	}
	return 0;
}