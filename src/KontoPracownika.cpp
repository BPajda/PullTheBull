#include <iostream>
#include "KontoPracownika.h"
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

// Funkcja sprawdzaj�ca czy podany napis jest liczb�
bool isNumber(string liczba) {
	if (liczba.empty()) {
		return false; // Pusty ci�g nie jest liczb�
	}

	// Sprawd�, czy ka�dy znak w ci�gu to cyfra lub pierwszy znak to znak '-' lub '+'
	for (size_t i = 0; i < liczba.length(); ++i) {
		if (i == 0 && (liczba[i] == '-' || liczba[i] == '+')) {
			continue; // Pierwszy znak mo�e by� '-' lub '+'
		}
		if (!isdigit(liczba[i])) {
			return false; // Znaleziono znak, kt�ry nie jest cyfr�
		}
	}

	return true; // Ci�g jest liczb�
}

// Funkcja szablonowa s�u��ca do przeszukiwania wektora podanego typu, przyjmuje szukan� fraz� jako parametr
template <typename T>
bool szukajWektor(vector<T> wektor, string nazwa) {
	for (T element : wektor) {
		if (element.getNazwa() == nazwa) {
			return true;
		}
	}
	return false;
}

// Funkcja zarz�dzaj�ca cennikiem karnet�w dla konta pracownika
void KontoPracownika::zarzadzajCennikiem(Cennik& cennik)
{
	char wybor;
	char wybrany;
	string nazwa;
	int cena;
	bool open, zajecia;
	do
	{
		// Menu zarz�dzania cennikiem
		system("cls");
		cennik.przegladajCennik();
		cout << " 1) Dodaj Karnet" << endl;
		cout << " 2) Usun Karnet" << endl;
		cout << " 3) Modyfikuj Karnet" << endl;
		cout << "ESC) Powrot" << endl;
		wybor = _getch();
	} while (wybor != 27 && wybor != '1' && wybor != '2' && wybor != '3');
	switch (wybor)
	{
	case '1':
		// Dodawanie nowego karnetu
		system("cls");
		cout << "Podaj nazwe nowego karnetu: ";
		cin >> nazwa;	
		// Sprawdzanie, czy karnet o podanej nazwie ju� istnieje
		while (szukajWektor(cennik.getTypyKarnetow(), nazwa))
		{
			cout << "Karnet o takiej nazwie juz istnieje. Podaj inna nazwe" << endl;
			cin >> nazwa;
		}
		// Podawanie ceny karnetu
		system("cls");
		cout << "Podaj cene karnetu: ";
		// Walidacja wprowadzonej ceny
		while (!(cin >> cena) || cena < 0)
		{
			system("cls");
			cout << "Podaj prawidlowa cene: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		// Wyb�r przywilej�w OPEN
		do
		{
			system("cls");
			cout << "Czy przysluguja przywileje OPEN?" << endl;
			cout << " T) TAK" << endl;
			cout << " N) NIE" << endl;
			wybor = _getch();
		} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
		if (wybor == 'T' || wybor == 't')
		{
			open = 1;
		}
		else
		{
			open = 0;
		}
		// Wyb�r dost�pno�ci zaj��
		do
		{
			system("cls");
			cout << "Czy karnet umozliwia udzial w zajeciach?" << endl;
			cout << " T) TAK" << endl;
			cout << " N) NIE" << endl;
			wybor = _getch();
		} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
		if (wybor == 'T' || wybor == 't')
		{
			zajecia = 1;
		}
		else
		{
			zajecia = 0;
		}
		// Potwierdzenie dodania karnetu
		do
		{
			system("cls");
			cout << "Czy chcesz dodac karnet: " << endl;

			// Wy�wietlanie informacji o nowym karnecie
			cout << "======================" << endl;
			cout << "Nazwa: " << nazwa << endl;
			cout << "Cena: " << cena << "zl" << endl;
			cout << "OPEN: " << (open ? "TAK" : "NIE") << endl;
			cout << "Zajecia: " << (zajecia ? "TAK" : "NIE") << endl;
			cout << "======================" << endl;
			cout << " T) TAK" << endl;
			cout << " N) NIE" << endl;
			wybor = _getch();
		} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
		// Dodanie karnetu do cennika
		if (wybor == 'T' || wybor == 't')
		{
			cennik.dodajKarnet(TypKarnetu(nazwa, cena, open, zajecia));

			// Aktualizacja pliku z typami karnet�w
			fstream plikAktualizuj;
			plikAktualizuj.open("src/TypyKarnetow.txt", ios::out);
			for (int i = 1; i < cennik.getTypyKarnetow().size(); i++)
			{
				plikAktualizuj << cennik.getTypyKarnetow()[i].getNazwa() << "\t" << cennik.getTypyKarnetow()[i].getCena() << "\t" 
					<< cennik.getTypyKarnetow()[i].getOpen() << "\t" << cennik.getTypyKarnetow()[i].getZajecia() << endl;
			}
			plikAktualizuj.close();
		}
		break;
	case '2':
		// Usuwanie karnetu
		do
		{
			system("cls");
			cennik.przegladajCennik();
			cout << "Ktory karnet chcesz usunac?" << endl;
			cout << "ESC) Powrot" << endl;
			wybrany = _getch();
		} while (wybrany != 27 && (wybrany < '0' || wybrany > cennik.getTypyKarnetow().size() + 48 - 1));
		if (wybrany == 27)
		{
			break;
		}
		else
		{
			// Potwierdzenie usuni�cia karnetu
			do
			{
				system("cls");
				cout << "Czy na pewno chcesz usunac karnet " << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << "?" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			// Usuni�cie karnetu z cennika
			if (wybor == 'T' || wybor == 't')
			{
				cennik.usunKarnet(cennik.getTypyKarnetow()[wybrany - 48].getNazwa());

				// Aktualizacja pliku z typami karnet�w
				fstream plikAktualizuj;
				plikAktualizuj.open("src/TypyKarnetow.txt", ios::out);
				for (int i = 1; i < cennik.getTypyKarnetow().size(); i++)
				{
					plikAktualizuj << cennik.getTypyKarnetow()[i].getNazwa() << "\t" << cennik.getTypyKarnetow()[i].getCena() << "\t"
						<< cennik.getTypyKarnetow()[i].getOpen() << "\t" << cennik.getTypyKarnetow()[i].getZajecia() << endl;
				}
				plikAktualizuj.close();
			}
		}
		break;
	case '3':
		// Modyfikowanie karnetu
		do
		{
			system("cls");
			cennik.przegladajCennik();
			cout << "Ktory karnet chcesz modyfikowac?" << endl;
			cout << "ESC) Powrot" << endl;
			wybrany = _getch();
		} while (wybrany != 27 && (wybrany < '0' || wybrany > cennik.getTypyKarnetow().size() + 48 - 1));
		// Anulowanie modyfikacji
		if (wybrany == 27)
		{
			break;
		}
		else
		{
			// Wy�wietlanie informacji o karnecie do modyfikacji
			system("cls");
			cout << "==========================" << endl;
			cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
			cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
			cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen() ? "TAK" : "NIE") << endl;
			cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
			cout << "==========================" << endl << endl;

			// Podawanie nowej nazwy karnetu
			cout << "Podaj nowa nazwe karnetu: ";
			cin >> nazwa;

			// Sprawdzanie, czy karnet o podanej nazwie ju� istnieje
			while (szukajWektor(cennik.getTypyKarnetow(), nazwa))
			{
				cout << "Karnet o takiej nazwie juz istnieje. Podaj inna nazwe" << endl;
				cin >> nazwa;
			}

			// Podawanie nowej ceny karnetu
			system("cls");
			cout << "==========================" << endl;
			cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
			cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
			cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen() ? "TAK" : "NIE") << endl;
			cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
			cout << "==========================" << endl << endl;

			cout << "Podaj zmieniona cene karnetu: ";
			// Walidacja wprowadzonej ceny
			while (!(cin >> cena) || cena < 0)
			{
				system("cls");
				cout << "Podaj prawidlowa cene: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			// Wyb�r przywilej�w OPEN
			do
			{
				system("cls");
				cout << "==========================" << endl;
				cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
				cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
				cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen() ? "TAK" : "NIE") << endl;
				cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
				cout << "==========================" << endl << endl;
				cout << "Czy maja przyslugugiwac przywileje OPEN?" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			if (wybor == 'T' || wybor == 't')
			{
				open = 1;
			}
			else
			{
				open = 0;
			}
			// Wyb�r dost�pno�ci zaj��
			do
			{
				system("cls");
				cout << "==========================" << endl;
				cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
				cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
				cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen() ? "TAK" : "NIE") << endl;
				cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
				cout << "==========================" << endl << endl;
				cout << "Czy karnet ma umozliwiac udzial w zajeciach?" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			if (wybor == 'T' || wybor == 't')
			{
				zajecia = 1;
			}
			else
			{
				zajecia = 0;
			}
			// Potwierdzenie zmian
			do
			{
				system("cls");
				cout << "Czy na pewno chcesz zmienic karnet: " << endl;
				cout << "==========================" << endl;
				cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
				cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
				cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen()?"TAK":"NIE") << endl;
				cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
				cout << "==========================" << endl;
				cout << "Na karnet:" << endl;
				cout << "==========================" << endl;
				cout << nazwa << endl;
				cout << "Cena: " << cena << endl;
				cout << "OPEN: " << (open ? "TAK" : "NIE") << endl;
				cout << "Zajecia: " << (zajecia? "TAK" : "NIE") << endl;
				cout << "==========================" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			// Zastosowanie zmian
			if (wybor == 'T' || wybor == 't')
			{
				// Aktualizacja danych karnetu w wektorze przechowuj�cym typy karnet�w
				cennik.zmienKarnet(cennik.getTypyKarnetow()[wybrany - 48].getNazwa(), TypKarnetu(nazwa, cena, open, zajecia));

				// Aktualizacja pliku przechowuj�cego dane o typach karnet�w
				fstream plikAktualizuj;
				plikAktualizuj.open("src/TypyKarnetow.txt", ios::out);
				for (int i = 1; i < cennik.getTypyKarnetow().size(); i++)
				{
					plikAktualizuj << cennik.getTypyKarnetow()[i].getNazwa() << "\t" << cennik.getTypyKarnetow()[i].getCena() << "\t"
						<< cennik.getTypyKarnetow()[i].getOpen() << "\t" << cennik.getTypyKarnetow()[i].getZajecia() << endl;
				}
				plikAktualizuj.close();
			}
		}
		break;
	case 27:
		return;
		break;
	}
}

// Funkcja zarz�dzaj�ca kontami u�ytkownik�w i pracownik�w dla konta pracownika
void KontoPracownika::zarzadzajKontami(Cennik cennik)
{
	char wybor;
	char wybrany;
	vector<string> konta;
	fstream plik;
	string imie;
	string nazwisko;
	string telefon;
	string email;
	string login;
	string haslo;
	int typKarnetu;
	int uprawnienia;
	time_t ostatniaPlatnosc;

	string wiersz;
	string szukanyLogin;

	string noweImie;
	string noweNazwisko;
	string nowyTelefon;
	string nowyEmail;
	string nowyLogin;
	string noweHaslo;
	int nowyTypKarnetu;
	int noweUprawnienia;
	time_t nowaOstatniaPlatnosc;
	bool znaleziony;
	do
	{
		system("cls");
		cout << " 1) Dodaj Konto" << endl;
		cout << " 2) Usun Konto" << endl;
		cout << " 3) Modyfikuj Konto" << endl;
		cout << "ESC) Powrot" << endl;
		wybor = _getch();
	} while (wybor != 27 && wybor != '1' && wybor != '2' && wybor != '3');
	switch (wybor)
	{
	case '1':
		// Dodawanie nowego konta
		cout << "======== Dodawanie konta ========" << endl;
		cout << "Podaj imie: ";
		cin >> imie;
		cout << "Podaj nazwisko: ";
		cin >> nazwisko;
		cout << "Podaj telefon: ";
		cin >> telefon;
		cout << "Podaj email: ";
		cin >> email;

		// Tworzenie unikalnego loginu
		tworzenieLoginu:
		cout << "Utworz login: ";
		cin >> login;

		plik.open("src/Konta.txt", ios::in);
		while (plik >> szukanyLogin) {
			getline(plik, wiersz);
			if (login == szukanyLogin) {
				cout << "Podany login jest juz wykorzystany!" << endl;
				plik.close();
				goto tworzenieLoginu;
			}
		}
		plik.close();

		// Tworzenie has�a z ukrytymi znakami
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
		// Dodawanie karnetu do konta (opcjonalne)
		do
		{
			system("cls");
			cout << "Czy chcesz dodac karnet do konta?" << endl;
			cout << " T) TAK" << endl;
			cout << " N) NIE" << endl;
			wybor = _getch();
		} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
		if (wybor == 'T' || wybor == 't')
		{
			// Wybieranie karnetu
			do
			{
				system("cls");
				cennik.przegladajCennik();
				cout << "Ktory karnet chcesz dodac do konta?" << endl;
				cout << "ESC) Anuluj dodawanie karnetu" << endl;
				wybrany = _getch();
			} while (wybrany != 27 && (wybrany < '1' || wybrany > cennik.getTypyKarnetow().size() + 48));
			if (wybrany == 27)
			{
				typKarnetu = 0;
			}
			else
			{
				typKarnetu = wybrany - 48;
			}
			// Wyb�r czy karnet ma by� aktualny
			do
			{
				system("cls");
				cout << "Czy karnet ma byc aktualny?" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			if (wybor == 'T' || wybor == 't')
			{
				ostatniaPlatnosc = time(0);
			}
			else
			{
				ostatniaPlatnosc = 0;
			}
		}
		else
		{
			typKarnetu = 0;
			ostatniaPlatnosc = 0;
		}
		// Wyb�r poziomu uprawnie�
		do
		{
			system("cls");
			cout << "Jakie uprawnienia ma miec konto?" << endl;
			cout << " K) Klient" << endl;
			cout << " P) Pracownik" << endl;
			wybor = _getch();
		} while (wybor != 'k' && wybor != 'K' && wybor != 'p' && wybor != 'P');
		if (wybor == 'k' || wybor == 'K')
		{
			uprawnienia = 0;
		}
		else
		{
			uprawnienia = 1;
		}
		// Potwierdzenie dodania konta
		do
		{
			system("cls");
			cout << "Czy na pewno chcesz dodac konto: " << endl;
			cout << "================================" << endl;
			cout << imie << " " << nazwisko << endl;
			cout << "Nr tel: " << telefon << endl;
			cout << "Email: " << email << endl;
			cout << "Login: " << login << endl;
			cout << "Haslo: " << haslo << endl;
			cout << "Poziom uprawnien: " << (uprawnienia ? "Pracownik" : "Klient") << endl;
			cout << "Karnet: " << cennik.getTypyKarnetow()[typKarnetu].getNazwa() << endl;
			if (typKarnetu && ostatniaPlatnosc)
			{
				cout << "Karnet wazny do: " << konwertujTimeT(ostatniaPlatnosc + 2592000) << endl;
			}
			cout << "================================" << endl;
			cout << " T) TAK" << endl;
			cout << " N) NIE" << endl;
			wybor = _getch();
		} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
		if (wybor == 'T' || wybor == 't')
		{
			// Dodanie konta do wektora kont
			konta.clear();
			plik.open("src/Konta.txt", ios::in);
			while (getline(plik, wiersz)) {
				konta.push_back(wiersz);
			}
			plik.close();
			konta.push_back(login + '\t' + haslo + '\t' + imie + '\t' + nazwisko + '\t' + telefon + '\t' + email + '\t' + to_string(typKarnetu)
				+ '\t' + to_string(uprawnienia) + '\t' + to_string(ostatniaPlatnosc));
			
			// Aktualizacja pliku przechowuj�cego konta
			plik.open("src/Konta.txt", ios::out);
			for (int i = 0; i < konta.size(); i++)
			{
				plik << konta[i] << endl;
			}
			plik.close();
		}
		break;
	case '2':
		// Usuwanie konta
		cout << "Podaj login konta do usuniecia" << endl;
		cin >> szukanyLogin;
		znaleziony = false;

		// Sprawdzenie czy konto istnieje
		plik.open("src/Konta.txt", ios::in);
		while (plik >> login) {
			getline(plik, wiersz);
			if (login == szukanyLogin) {
				znaleziony = true;
			}
		}
		plik.close();

		// Je�li konto istnieje
		if (znaleziony)
		{
			// Potwierdzenie trwa�ego usuni�cia konta
			do
			{
				system("cls");
				cout << "Czy na pewno chcesz trwale usunac konto " << szukanyLogin << "?" << endl;
				cout << "T) TAK" << endl;
				cout << "N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 't' && wybor != 'T' && wybor != 'n' && wybor != 'N');
			if (wybor == 't' || wybor == 'T')
			{
				// Przepisanie kont z pliku do wektora, z pomini�ciem usuwanego konta
				plik.open("src/Konta.txt", ios::in);
				konta.clear();
				while (getline(plik, wiersz))
				{
					istringstream strumien(wiersz);
					strumien >> login;
					if (login != szukanyLogin)
					{
						konta.push_back(wiersz);
					}
				}
				plik.close();

				// Aktualizacja pliku z kontami z wektora
				plik.open("src/Konta.txt", ios::out);
				for (int i = 0; i < konta.size(); i++)
				{
					plik << konta[i] << endl;
				}
				plik.close();
			}
		}
		else
		{
			// Informacja o braku konta o podanym loginie
			do
			{
				cout << "Konto o podanym loginie nie istnieje!" << endl;
				cout << "Wcisnij dowolny przycisk";
			} while (!_getch());
		}
		break;
	case '3':
		// Modyfikowanie konta
		cout << "Podaj login konta do zmiany" << endl;
		cin >> szukanyLogin;
		znaleziony = false;

		// Sprawdzenie czy konto istnieje
		plik.open("src/Konta.txt", ios::in);
		while (plik >> login) {
			getline(plik, wiersz);
			if (login == szukanyLogin) {
				znaleziony = true;
			}
		}
		plik.close();

		// Je�li konto istnieje
		if (znaleziony)
		{
			// Wczytanie kont z pliku do wektora
			konta.clear();
			plik.open("src/Konta.txt", ios::in);
			while (getline(plik, wiersz)) {
				konta.push_back(wiersz);
			}
			plik.close();
			// Znalezienie i modyfikacja konta w wektorze
			for (int i = 0; i < konta.size(); i++)
			{
				if (czyZawiera(konta[i], szukanyLogin))
				{
					wiersz = konta[i];
					istringstream strumien(wiersz);
					strumien >> login >> haslo >> imie >> nazwisko >> telefon >> email >> typKarnetu >> uprawnienia >> ostatniaPlatnosc;

					// Wy�wietlenie informacji o koncie przed zmianami
					system("cls");
					cout << "======== Zmieniane konto ========" << endl;
					cout << imie << " " << nazwisko << endl;
					cout << "Nr tel: " << telefon << endl;
					cout << "Email: " << email << endl;
					cout << "Login: " << login << endl;
					cout << "Haslo: " << haslo << endl;
					cout << "Poziom uprawnien: " << (uprawnienia ? "Pracownik" : "Klient") << endl;
					cout << "Karnet: " << cennik.getTypyKarnetow()[typKarnetu].getNazwa() << endl;
					if (typKarnetu && ostatniaPlatnosc)
					{
						cout << "Karnet wazny do: " << konwertujTimeT(ostatniaPlatnosc + 2592000) << endl;
					}

					// Modyfikacja poszczeg�lnych p�l konta
					cout << "=================================" << endl;
					cout << "Podaj zmienione imie" << endl;
					cin >> noweImie;
					
					system("cls");
					cout << "======== Zmieniane konto ========" << endl;
					cout << imie << " " << nazwisko << endl;
					cout << "Nr tel: " << telefon << endl;
					cout << "Email: " << email << endl;
					cout << "Login: " << login << endl;
					cout << "Haslo: " << haslo << endl;
					cout << "Poziom uprawnien: " << (uprawnienia ? "Pracownik" : "Klient") << endl;
					cout << "Karnet: " << cennik.getTypyKarnetow()[typKarnetu].getNazwa() << endl;
					if (typKarnetu && ostatniaPlatnosc)
					{
						cout << "Karnet wazny do: " << konwertujTimeT(ostatniaPlatnosc + 2592000) << endl;
					}
					cout << "=================================" << endl;
					cout << "Podaj zmienione nazwisko" << endl;
					cin >> noweNazwisko;

					system("cls");
					cout << "======== Zmieniane konto ========" << endl;
					cout << imie << " " << nazwisko << endl;
					cout << "Nr tel: " << telefon << endl;
					cout << "Email: " << email << endl;
					cout << "Login: " << login << endl;
					cout << "Haslo: " << haslo << endl;
					cout << "Poziom uprawnien: " << (uprawnienia ? "Pracownik" : "Klient") << endl;
					cout << "Karnet: " << cennik.getTypyKarnetow()[typKarnetu].getNazwa() << endl;
					if (typKarnetu && ostatniaPlatnosc)
					{
						cout << "Karnet wazny do: " << konwertujTimeT(ostatniaPlatnosc + 2592000) << endl;
					}
					cout << "=================================" << endl;
					cout << "Podaj zmieniony nr telefonu" << endl;
					cin >> nowyTelefon;

					system("cls");
					cout << "======== Zmieniane konto ========" << endl;
					cout << imie << " " << nazwisko << endl;
					cout << "Nr tel: " << telefon << endl;
					cout << "Email: " << email << endl;
					cout << "Login: " << login << endl;
					cout << "Haslo: " << haslo << endl;
					cout << "Poziom uprawnien: " << (uprawnienia ? "Pracownik" : "Klient") << endl;
					cout << "Karnet: " << cennik.getTypyKarnetow()[typKarnetu].getNazwa() << endl;
					if (typKarnetu && ostatniaPlatnosc)
					{
						cout << "Karnet wazny do: " << konwertujTimeT(ostatniaPlatnosc + 2592000) << endl;
					}
					cout << "=================================" << endl;
					cout << "Podaj zmieniony email" << endl;
					cin >> nowyEmail;

					system("cls");
					cout << "======== Zmieniane konto ========" << endl;
					cout << imie << " " << nazwisko << endl;
					cout << "Nr tel: " << telefon << endl;
					cout << "Email: " << email << endl;
					cout << "Login: " << login << endl;
					cout << "Haslo: " << haslo << endl;
					cout << "Poziom uprawnien: " << (uprawnienia ? "Pracownik" : "Klient") << endl;
					cout << "Karnet: " << cennik.getTypyKarnetow()[typKarnetu].getNazwa() << endl;
					if (typKarnetu && ostatniaPlatnosc)
					{
						cout << "Karnet wazny do: " << konwertujTimeT(ostatniaPlatnosc + 2592000) << endl;
					}
					cout << "=================================" << endl;
					nowyLogin:
					cout << "Podaj zmieniony login" << endl;
					cin >> nowyLogin;

					// Sprawdzenie unikalno�ci nowego loginu
					if(login != nowyLogin) 
					{ 
						plik.open("src/Konta.txt", ios::in);
						while (plik >> szukanyLogin) {
							getline(plik, wiersz);
							if (nowyLogin == szukanyLogin) {
								cout << "Podany login jest juz wykorzystany!" << endl;
								plik.close();
								goto nowyLogin;
							}
						}
						plik.close();
					}

					system("cls");
					cout << "======== Zmieniane konto ========" << endl;
					cout << imie << " " << nazwisko << endl;
					cout << "Nr tel: " << telefon << endl;
					cout << "Email: " << email << endl;
					cout << "Login: " << login << endl;
					cout << "Haslo: " << haslo << endl;
					cout << "Poziom uprawnien: " << (uprawnienia ? "Pracownik" : "Klient") << endl;
					cout << "Karnet: " << cennik.getTypyKarnetow()[typKarnetu].getNazwa() << endl;
					if (typKarnetu && ostatniaPlatnosc)
					{
						cout << "Karnet wazny do: " << konwertujTimeT(ostatniaPlatnosc + 2592000) << endl;
					}
					cout << "=================================" << endl;
					cout << "Podaj zmienione haslo" << endl;
					cin >> noweHaslo;

					// Wyb�r nowych uprawnie� (Klient/Pracownik)
					do
					{
						system("cls");
						cout << "======== Zmieniane konto ========" << endl;
						cout << imie << " " << nazwisko << endl;
						cout << "Nr tel: " << telefon << endl;
						cout << "Email: " << email << endl;
						cout << "Login: " << login << endl;
						cout << "Haslo: " << haslo << endl;
						cout << "Poziom uprawnien: " << (uprawnienia ? "Pracownik" : "Klient") << endl;
						cout << "Karnet: " << cennik.getTypyKarnetow()[typKarnetu].getNazwa() << endl;
						if (typKarnetu && ostatniaPlatnosc)
						{
							cout << "Karnet wazny do: " << konwertujTimeT(ostatniaPlatnosc + 2592000) << endl;
						}
						cout << "=================================" << endl;
						cout << "Jakie uprawnienia ma miec to konto?" << endl;
						cout << " K) Klient" << endl;
						cout << " P) Pracownik" << endl;
						wybor = _getch();
					} while (wybor != 'k' && wybor != 'K' && wybor != 'p' && wybor != 'P');
					// Przypisanie odpowiednich uprawnie� na podstawie wyboru
					if (wybor == 'k' || wybor == 'K')
					{
						noweUprawnienia = 0;
					}
					else
					{
						noweUprawnienia = 1;
					}
					
					// Wyb�r dodania karnetu do konta
					do
					{
						system("cls");
						cout << "======== Zmieniane konto ========" << endl;
						cout << imie << " " << nazwisko << endl;
						cout << "Nr tel: " << telefon << endl;
						cout << "Email: " << email << endl;
						cout << "Login: " << login << endl;
						cout << "Haslo: " << haslo << endl;
						cout << "Poziom uprawnien: " << (uprawnienia ? "Pracownik" : "Klient") << endl;
						cout << "Karnet: " << cennik.getTypyKarnetow()[typKarnetu].getNazwa() << endl;
						if (typKarnetu && ostatniaPlatnosc)
						{
							cout << "Karnet wazny do: " << konwertujTimeT(ostatniaPlatnosc + 2592000) << endl;
						}
						cout << "=================================" << endl;
						cout << "Czy chcesz dodac karnet do konta?" << endl;
						cout << " T) TAK" << endl;
						cout << " N) NIE" << endl;
						wybor = _getch();
					} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
					if (wybor == 'T' || wybor == 't')
					{
						// Wyb�r karnetu
						do
						{
							system("cls");
							cennik.przegladajCennik();
							cout << "Ktory karnet chcesz dodac do konta?" << endl;
							cout << "ESC) Anuluj dodawanie karnetu" << endl;
							wybrany = _getch();
						} while (wybrany != 27 && (wybrany < '1' || wybrany > cennik.getTypyKarnetow().size() + 48));

						// Anulowanie dodawania karnetu
						if (wybrany == 27)
						{
							nowyTypKarnetu = 0;
						}
						else
						{
							nowyTypKarnetu = wybrany - 48;

							// Wyb�r aktualno�ci karnetu
							do
							{
								system("cls");
								cout << "======== Zmieniane konto ========" << endl;
								cout << imie << " " << nazwisko << endl;
								cout << "Nr tel: " << telefon << endl;
								cout << "Email: " << email << endl;
								cout << "Login: " << login << endl;
								cout << "Haslo: " << haslo << endl;
								cout << "Poziom uprawnien: " << (uprawnienia ? "Pracownik" : "Klient") << endl;
								cout << "Karnet: " << cennik.getTypyKarnetow()[typKarnetu].getNazwa() << endl;
								if (typKarnetu && ostatniaPlatnosc)
								{
									cout << "Karnet wazny do: " << konwertujTimeT(ostatniaPlatnosc + 2592000) << endl;
								}
								cout << "=================================" << endl;
								cout << "Czy karnet ma byc aktualny?" << endl;
								cout << " T) TAK" << endl;
								cout << " N) NIE" << endl;
								wybor = _getch();
							} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
							// Aktualizacja daty ostatniej p�atno�ci na podstawie wyboru u�ytkownika
							if (wybor == 'T' || wybor == 't')
							{
								nowaOstatniaPlatnosc = time(0);
							}
							else
							{
								nowaOstatniaPlatnosc = 0;
							}
						}
					}
					else
					{
						nowyTypKarnetu = 0;
						nowaOstatniaPlatnosc = 0;
					}

					// Wyb�r u�ytkownika dotycz�cy akceptacji zmiany konta
					do
					{
						system("cls");
						cout << "Czy chcesz zmienic konto:" << endl;
						cout << "========== Aktualne konto ==========" << endl;
						cout << imie << " " << nazwisko << endl;
						cout << "Nr tel: " << telefon << endl;
						cout << "Email: " << email << endl;
						cout << "Login: " << login << endl;
						cout << "Haslo: " << haslo << endl;
						cout << "Poziom uprawnien: " << (uprawnienia ? "Pracownik" : "Klient") << endl;
						cout << "Karnet: " << cennik.getTypyKarnetow()[typKarnetu].getNazwa() << endl;
						if (typKarnetu && ostatniaPlatnosc)
						{
							cout << "Karnet wazny do: " << konwertujTimeT(ostatniaPlatnosc + 2592000) << endl;
						}
						cout << "=====================================" << endl;
						cout << "Na konto:" << endl;
						cout << "======== Zmodyfikowane konto ========" << endl;
						cout << noweImie << " " << noweNazwisko << endl;
						cout << "Nr tel: " << nowyTelefon << endl;
						cout << "Email: " << nowyEmail << endl;
						cout << "Login: " << nowyLogin << endl;
						cout << "Haslo: " << noweHaslo << endl;
						cout << "Poziom uprawnien: " << (noweUprawnienia ? "Pracownik" : "Klient") << endl;
						cout << "Karnet: " << cennik.getTypyKarnetow()[nowyTypKarnetu].getNazwa() << endl;
						if (nowyTypKarnetu && nowaOstatniaPlatnosc)
						{
							cout << "Karnet wazny do: " << konwertujTimeT(nowaOstatniaPlatnosc + 2592000) << endl;
						}
						cout << "=====================================" << endl;
						cout << " T) TAK" << endl;
						cout << " N) NIE" << endl;
						wybor = _getch();
					} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
					// Zastosowanie zmiany, je�li u�ytkownik zaakceptuje
					if (wybor == 'T' || wybor == 't')
					{
						// Wstawienie zmienionego rekordu na miejsce starego w wektorze
						konta[i] = nowyLogin + '\t' + noweHaslo + '\t' + noweImie + '\t' + noweNazwisko + '\t' + nowyTelefon + '\t' + nowyEmail + '\t' + to_string(nowyTypKarnetu)
							+ '\t' + to_string(noweUprawnienia) + '\t' + to_string(nowaOstatniaPlatnosc);

						// Aktualizacja pliku zawieraj�cego list� kont
						plik.open("src/Konta.txt", ios::out);
						for (int i = 0; i < konta.size(); i++)
						{
							plik << konta[i] << endl;
						}
						plik.close();
					}
				}
			}
		}
		else
		{
			// Podany login nieznaleziony
			do
			{
				cout << "Konto o podanym loginie nie istnieje!" << endl;
				cout << "Wcisnij dowolny przycisk";
			} while (!_getch());
		}
		break;
	case 27:
		return;
	}
}

// Funkcja zarz�dzaj�ca harmonogramem zaj�� dla konta pracownika
void KontoPracownika::zarzadzajHarmoZajec(HarmonogramZajec& harmonogram)
{
	{
		// Deklaracja zmiennych lokalnych
		char wybor;
		char wybrany;
		string nazwa;
		string opis;
		time_t dataZajec;
		int czasTrwania;
		int liczbaMiejsc;
		string prowadzacy;
		string dataString;
		vector<string> loginy = {};

		// Wy�wietlanie opcji menu
		do
		{
			system("cls");
			harmonogram.przegladajHarmonogram();
			cout << " 1) Dodaj Zajecia" << endl;
			cout << " 2) Usun Zajecia" << endl;
			cout << " 3) Modyfikuj Zajecia" << endl;
			cout << "ESC) Powrot" << endl;
			wybor = _getch();
		} while (wybor != 27 && wybor != '1' && wybor != '2' && wybor != '3');
		switch (wybor)
		{
		case '1':
			// Dodawanie nowych zaj��
			system("cls");
			cout << "Podaj nazwe nowych zajec: ";
			cin >> nazwa;

			// Sprawdzanie, czy zaj�cia o podanej nazwie ju� istniej�
			while (szukajWektor(harmonogram.getListaZajec(), nazwa))
			{
				cout << "Zajecia o takiej nazwie juz istnieja. Podaj inna nazwe" << endl;
				cin >> nazwa;
			}
			system("cls");
			cout << "Podaj opis zajec: ";
			getline(cin >> ws, opis);

			system("cls");
			cout << "Podaj liczbe miejsc: ";
			while (!(cin >> liczbaMiejsc) || liczbaMiejsc < 0)
			{
				system("cls");
				cout << "Podaj prawidlowa liczbe miejsc: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			system("cls");
			cout << "Podaj czas trwania zajec [min]: ";
			while (!(cin >> czasTrwania) || czasTrwania < 0)
			{
				system("cls");
				cout << "Podaj prawidlowy czas trwania zajec: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			system("cls");
			cout << "Podaj godzine i date zajec w formacie (godziny minuty dzien miesiac rok)" << endl;
			getline(cin >> ws, dataString);

			// Walidacja formatu daty
			while(dataString.size() != 14 || !dobryFormat(dataString))
			{
				cout << "Podaj poprawna date" << endl;
				getline(cin >> ws, dataString);
			}
			dataZajec = parsujDate(dataString);

			system("cls");
			cout << "Podaj prowadzacego zajecia: " << endl;
			cin >> prowadzacy;

			// Wy�wietlanie podsumowania wprowadzonych danych i potwierdzenie dodania zaj��
			do
			{
				system("cls");
				cout << "Czy chcesz dodac zajecia: " << endl;
				cout << "======================" << endl;
				cout << nazwa << endl;
				cout << "Opis: " << podlogiNaSpacje(opis) << endl;
				cout << "Liczba miejsc: " << liczbaMiejsc << endl;
				cout << "Czas trwania: " << czasTrwania << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(dataZajec) << endl;
				cout << "Prowadzacy: " << prowadzacy << endl;
				cout << "======================" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			// Dodanie zaj�� do harmonogramu
			if (wybor == 'T' || wybor == 't')
			{
				harmonogram.dodajZajecia(Zajecia(nazwa, opis, dataZajec, czasTrwania, liczbaMiejsc, prowadzacy, loginy));

				// Aktualizacja pliku z list� zaj��
				fstream plikAktualizuj;
				plikAktualizuj.open("src/ListaZajec.txt", ios::out);
				for (int i = 0; i < harmonogram.getListaZajec().size(); i++)
				{
					plikAktualizuj << harmonogram.getListaZajec()[i].getNazwa() << '\t' << spacjeNaPodlogi(harmonogram.getListaZajec()[i].getOpis()) << '\t' 
						<< harmonogram.getListaZajec()[i].getDataZajec() << '\t' << harmonogram.getListaZajec()[i].getCzasTrwania() << '\t' 
						<< harmonogram.getListaZajec()[i].getLiczbaMiejsc() << '\t' << harmonogram.getListaZajec()[i].getProwadzacy() << '\t';
					for (int j = 0; j < harmonogram.getListaZajec()[i].getLoginyUczestnikow().size(); j++)
					{
						plikAktualizuj << harmonogram.getListaZajec()[i].getLoginyUczestnikow()[j] << '\t';
					}
					plikAktualizuj << endl;
				}
				plikAktualizuj.close();
			}
			break;
		case '2':
			// Usuwanie zaj��
			do
			{
				// Wy�wietlanie listy zaj�� w harmonogramie
				system("cls");
				harmonogram.przegladajHarmonogram();
				cout << "Ktore zajecia chcesz usunac?" << endl;
				cout << "ESC) Powrot" << endl;
				wybrany = _getch();
			} while (wybrany != 27 && (wybrany < '0' || wybrany > harmonogram.getListaZajec().size() + 48-1));
			// Powr�t do menu g��wnego, je�li u�ytkownik naci�nie ESC
			if (wybrany == 27)
			{
				break;
			}
			else
			{
				do
				{
					// Wy�wietlanie potwierdzenia usuni�cia wybranych zaj��
					system("cls");
					cout << "Czy na pewno chcesz usunac zajecia " << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << "?" << endl;
					cout << " T) TAK" << endl;
					cout << " N) NIE" << endl;
					wybor = _getch();
				} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
				// Usuni�cie zaj��, je�li u�ytkownik potwierdzi
				if (wybor == 'T' || wybor == 't')
				{
					harmonogram.usunZajecia(harmonogram.getListaZajec()[wybrany - 48].getNazwa());

					// Aktualizacja pliku z list� zaj��
					fstream plikAktualizuj;
					plikAktualizuj.open("src/ListaZajec.txt", ios::out);
					for (int i = 0; i < harmonogram.getListaZajec().size(); i++)
					{
						plikAktualizuj << harmonogram.getListaZajec()[i].getNazwa() << '\t' << spacjeNaPodlogi(harmonogram.getListaZajec()[i].getOpis()) << '\t'
							<< harmonogram.getListaZajec()[i].getDataZajec() << '\t' << harmonogram.getListaZajec()[i].getCzasTrwania() << '\t'
							<< harmonogram.getListaZajec()[i].getLiczbaMiejsc() << '\t' << harmonogram.getListaZajec()[i].getProwadzacy() << '\t';
						for (int j = 0; j < harmonogram.getListaZajec()[i].getLoginyUczestnikow().size(); j++)
						{
							plikAktualizuj << harmonogram.getListaZajec()[i].getLoginyUczestnikow()[j] << '\t';
						}
						plikAktualizuj << endl;
					}
					plikAktualizuj.close();
				}
			}
			break;
		case '3':
			// Modyfikowanie zaj��
			do
			{
				// Wy�wietlanie listy zaj�� w harmonogramie
				system("cls");
				harmonogram.przegladajHarmonogram();
				cout << "Ktore zajecia chcesz modyfikowac?" << endl;
				cout << "ESC) Powrot" << endl;
				wybrany = _getch();
			} while (wybrany != 27 && (wybrany <= '0' || wybrany > harmonogram.getListaZajec().size() + 48-1));
			// Powr�t do menu g��wnego, je�li u�ytkownik naci�nie ESC
			if (wybrany == 27)
			{
				break;
			}
			else
			{
				// Wy�wietlanie informacji o wybranych zaj�ciach
				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;

				// Pobieranie nowych danych zaj��
				cout << "Podaj nowa nazwe zajec: ";
				cin >> nazwa;
				
				// Kontynuacja zmian danych
				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;
				cout << "Podaj zmieniony opis zajec: " << endl;

				getline(cin >> ws, opis);
				
				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;
				cout << "Podaj zmieniona godzine i date zajec w formacie (godziny minuty dzien miesiac rok)" << endl;

				// Walidacja poprawno�ci wprowadzonej daty
				getline(cin >> ws, dataString);
				dataZajec = parsujDate(dataString);

				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;

				// Walidacja poprawno�ci danych wej�ciowych
				cout << "Podaj zmieniony czas trwania zajec [min]: ";
				while (!(cin >> czasTrwania) || czasTrwania < 0)
				{
					system("cls");
					cout << "Podaj prawidlowy czas trwania zajec: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;

				// Walidacja poprawno�ci danych wej�ciowych
				cout << "Podaj zmieniona liczbe miejsc"<< endl;
				while (!(cin >> liczbaMiejsc) || liczbaMiejsc < 0)
				{
					system("cls");
					cout << "Podaj prawidlowa liczbe miejsc: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;
				cout << "Podaj zmienionego prowadzacego" << endl;
				cin >> prowadzacy;
				do
				{
					// Wy�wietlanie potwierdzenia zmiany zaj��
					system("cls");
					cout << "Czy na pewno chcesz zmienic zajecia: " << endl;
					cout << "==========================" << endl;
					cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
					cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
					cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
					cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
					cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
					cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
					cout << "==========================" << endl << endl;
					cout << "Na karnet:" << endl;
					cout << "==========================" << endl;
					cout << nazwa << endl;
					cout << "Opis: " << podlogiNaSpacje(opis) << endl;
					cout << "Liczba miejsc: " << liczbaMiejsc << endl;
					cout << "Czas trwania: " << czasTrwania << "min" << endl;
					cout << "Data zajec: " << konwertujTimeT(dataZajec) << endl;
					cout << "Prowadzacy: " << prowadzacy << endl;
					cout << "==========================" << endl << endl;
					cout << " T) TAK" << endl;
					cout << " N) NIE" << endl;
					wybor = _getch();
				} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
				// Aktualizacja danych zaj�� po potwierdzeniu zmian
				if (wybor == 'T' || wybor == 't')
				{
					harmonogram.zmienZajecia(harmonogram.getListaZajec()[wybrany - 48].getNazwa(), Zajecia(nazwa, opis, dataZajec, czasTrwania, liczbaMiejsc, prowadzacy, harmonogram.getListaZajec()[wybrany - 48].getLoginyUczestnikow()));
					
					// Aktualizacja pliku przechowuj�cego dane o zajeciach
					fstream plikAktualizuj;
					plikAktualizuj.open("src/ListaZajec.txt", ios::out);
					for (int i = 0; i < harmonogram.getListaZajec().size(); i++)
					{
						plikAktualizuj << harmonogram.getListaZajec()[i].getNazwa() << '\t' << spacjeNaPodlogi(harmonogram.getListaZajec()[i].getOpis()) << '\t'
							<< harmonogram.getListaZajec()[i].getDataZajec() << '\t' << harmonogram.getListaZajec()[i].getCzasTrwania() << '\t'
							<< harmonogram.getListaZajec()[i].getLiczbaMiejsc() << '\t' << harmonogram.getListaZajec()[i].getProwadzacy() << '\t';
						for (int j = 0; j < harmonogram.getListaZajec()[i].getLoginyUczestnikow().size(); j++)
						{
							plikAktualizuj << harmonogram.getListaZajec()[i].getLoginyUczestnikow()[j] << '\t';
						}
						plikAktualizuj << endl;
					}
					plikAktualizuj.close();
				}
			}
			break;
		case 27:
			// Powr�t z menu
			return;
		}
	}
}

// Konstruktor z parametrami
KontoPracownika::KontoPracownika(string login, string haslo)
{
	this->login = login;
	this->haslo = haslo;
}

// Konstruktor domy�lny
KontoPracownika::KontoPracownika()
{
}

// Destruktor
KontoPracownika::~KontoPracownika()
{
}

// Getter zwracaj�cy login pracownika
string KontoPracownika::getLogin()
{
	return this->login;
}

// Getter zwracaj�cy has�o pracownika
string KontoPracownika::getHaslo()
{
	return this->haslo;
}

// Setter ustawiaj�cy login pracownika
void KontoPracownika::setLogin(string login)
{
	this->login = login;
}

// Setter ustawiaj�cy haslo pracownika
void KontoPracownika::setHaslo(string haslo)
{
	this->haslo = haslo;
}

// Funkcja konwertuj�ca dat� wpisan� w odpowiednim formacie w stringu, na dat� w typie time_t
time_t parsujDate(string& dataStr) {
	tm strukturaCzasu = {}; // Inicjalizacja struktury tm

	istringstream strumien(dataStr);
	int godzina, minuta, dzien, miesiac, rok;

	// Parsowanie daty z formatu "hh mm dd mm yy"
	strumien >> godzina >> minuta >> dzien >> miesiac >> rok;

	// Sprawdzenie poprawno�ci parsowania
	if (strumien.fail()) {
		cerr << "B��d parsowania daty." << endl;
		return -1; // Zwr�cenie b��du
	}

	// Ustawienie p�l struktury tm
	strukturaCzasu.tm_hour = godzina-1;
	strukturaCzasu.tm_min = minuta;
	strukturaCzasu.tm_sec = 0;
	strukturaCzasu.tm_mday = dzien;
	strukturaCzasu.tm_mon = miesiac - 1; // tm_mon jest indeksowane od 0
	strukturaCzasu.tm_year = rok + 100; // tm_year liczone od 1900

	// Przekszta�cenie struct tm na time_t
	time_t znacznikCzasu = mktime(&strukturaCzasu);

	// Sprawdzenie poprawno�ci przekszta�cenia
	if (znacznikCzasu == -1) {
		cerr << "B��d przekszta�cania daty na znacznik czasu." << endl;
		return -1;
	}

	return znacznikCzasu;
}

// Funkcja ma za zadanie sprawdzi� czy podana data w stringu zgadza si� z formatem [hh mm dd mm yy]
// Ponadto sprawdza czy podane warto�ci godzin i dni miesi�ca s� poprawne wzgl�dem rzeczywisto�ci 
// np. jeden miesi�c ma maks. 31 dni
bool dobryFormat(string data)
{
	for (int i = 0; i < data.size(); i++)
	{
		if ((i % 3) + 1 == 3 && data[i] != ' ')
		{
			return false;
		}
	}
	if (data[0] < '0' || data[0] > '2')
	{
		return false;
	}
	if (data[0] == '2' && (data[1] < '0' || data[1] > '3'))
	{
		return false;
	}
	if (data[3] < '0' || data[3] > '5')
	{
		return false;
	}
	if (data[6] < '0' || data[6] > '3')
	{
		return false;
	}
	if (data[6] == '3' && (data[7] < '0' || data[7] > '1'))
	{
		return false;
	}
	if(data[9] < '0' || data[9] > '1')
	{
		return false;
	}
	if (data[9] == '1' && (data[10] < '0' || data[10] > '2'))
	{
		return false;
	}
	if (data[6] == '3' && data[7] == '1')
	{
		if (data[9] == '0' && data[10] == '4')
		{
			return false;
		}
		if (data[9] == '0' && data[10] == '6')
		{
			return false;
		}
		if (data[9] == '0' && data[10] == '6')
		{
			return false;
		}
		if (data[9] == '0' && data[10] == '9')
		{
			return false;
		}
		if (data[9] == '1' && data[10] == '1')
		{
			return false;
		}
	}
	if (data[9] == '0' && data[10] == '2')
	{
		if((data[6] == '2' && (data[7] < '0' || data[7] > '8')) || (data[6] == '3'))
		{
			return false;
		}
	}
	return true;
}

// Funkcja sprawdzaj�ca czy podany napis znajduje si� wewn�trz innego napisu
bool czyZawiera(string tekst, string podciag) {
	// Je�li find zwraca std::string::npos, to podci�g nie istnieje w tek�cie
	return tekst.find(podciag) != string::npos;
}