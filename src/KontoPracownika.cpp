#include <iostream>
#include "KontoPracownika.h"
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

bool isNumber(string liczba) {
	if (liczba.empty()) {
		return false; // Pusty ciπg nie jest liczbπ
	}

	// Sprawdü, czy kaødy znak w ciπgu to cyfra lub pierwszy znak to znak '-' lub '+'
	for (size_t i = 0; i < liczba.length(); ++i) {
		if (i == 0 && (liczba[i] == '-' || liczba[i] == '+')) {
			continue; // Pierwszy znak moøe byÊ '-' lub '+'
		}
		if (!isdigit(liczba[i])) {
			return false; // Znaleziono znak, ktÛry nie jest cyfrπ
		}
	}

	return true; // Ciπg jest liczbπ
}

template <typename T>
bool szukajWektor(vector<T> wektor, string nazwa) {
	for (T element : wektor) {
		if (element.getNazwa() == nazwa) {
			return true;
		}
	}
	return false;
}

void KontoPracownika::zarzadzajCennikiem(Cennik& cennik)
{
	char wybor;
	char wybrany;
	string nazwa;
	int cena;
	bool open, zajecia;
	do
	{
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
		system("cls");
		cout << "Podaj nazwe nowego karnetu: ";
		cin >> nazwa;	
		while (szukajWektor(cennik.getTypyKarnetow(), nazwa))
		{
			cout << "Karnet o takiej nazwie juz istnieje. Podaj inna nazwe" << endl;
			cin >> nazwa;
		}
		system("cls");
		cout << "Podaj cene karnetu: ";
		while (!(cin >> cena) || cena < 0)
		{
			system("cls");
			cout << "Podaj prawidlowa cene: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
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
		do
		{
			system("cls");
			cout << "Czy chcesz dodac karnet: " << endl;
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
		if (wybor == 'T' || wybor == 't')
		{
			cennik.dodajKarnet(TypKarnetu(nazwa, cena, open, zajecia));
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
			do
			{
				system("cls");
				cout << "Czy na pewno chcesz usunac karnet " << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << "?" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			if (wybor == 'T' || wybor == 't')
			{
				cennik.usunKarnet(cennik.getTypyKarnetow()[wybrany - 48].getNazwa());
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
		do
		{
			system("cls");
			cennik.przegladajCennik();
			cout << "Ktory karnet chcesz modyfikowac?" << endl;
			cout << "ESC) Powrot" << endl;
			wybrany = _getch();
		} while (wybrany != 27 && (wybrany < '0' || wybrany > cennik.getTypyKarnetow().size() + 48 - 1));
		if (wybrany == 27)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "==========================" << endl;
			cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
			cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
			cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen() ? "TAK" : "NIE") << endl;
			cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
			cout << "==========================" << endl << endl;
			cout << "Podaj nowa nazwe karnetu: ";
			cin >> nazwa;
			while (szukajWektor(cennik.getTypyKarnetow(), nazwa))
			{
				cout << "Karnet o takiej nazwie juz istnieje. Podaj inna nazwe" << endl;
				cin >> nazwa;
			}
			system("cls");
			cout << "==========================" << endl;
			cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
			cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
			cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen() ? "TAK" : "NIE") << endl;
			cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
			cout << "==========================" << endl << endl;
			cout << "Podaj zmieniona cene karnetu: ";
			while (!(cin >> cena) || cena < 0)
			{
				system("cls");
				cout << "Podaj prawidlowa cene: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
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
			if (wybor == 'T' || wybor == 't')
			{
				cennik.zmienKarnet(cennik.getTypyKarnetow()[wybrany - 48].getNazwa(), TypKarnetu(nazwa, cena, open, zajecia));
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
		cout << "======== Dodawanie konta ========" << endl;
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
		while (plik >> szukanyLogin) {
			getline(plik, wiersz);
			if (login == szukanyLogin) {
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
		}
		else
		{
			typKarnetu = 0;
		}
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
			konta.clear();
			plik.open("src/Konta.txt", ios::in);
			while (getline(plik, wiersz)) {
				konta.push_back(wiersz);
			}
			plik.close();
			konta.push_back(login + '\t' + haslo + '\t' + imie + '\t' + nazwisko + '\t' + telefon + '\t' + email + '\t' + to_string(typKarnetu)
				+ '\t' + to_string(uprawnienia) + '\t' + to_string(ostatniaPlatnosc));
			plik.open("src/Konta.txt", ios::out);
			for (int i = 0; i < konta.size(); i++)
			{
				plik << konta[i] << endl;
			}
			plik.close();
		}
		break;
	case '2':
		cout << "Podaj login konta do usuniecia" << endl;
		cin >> szukanyLogin;
		znaleziony = false;
		plik.open("src/Konta.txt", ios::in);
		while (plik >> login) {
			getline(plik, wiersz);
			if (login == szukanyLogin) {
				znaleziony = true;
			}
		}
		plik.close();
		if (znaleziony)
		{
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
			do
			{
				cout << "Konto o podanym loginie nie istnieje!" << endl;
				cout << "Wcisnij dowolny przycisk";
			} while (!_getch());
		}
		break;
	case '3':
		cout << "Podaj login konta do zmiany" << endl;
		cin >> szukanyLogin;
		znaleziony = false;
		plik.open("src/Konta.txt", ios::in);
		while (plik >> login) {
			getline(plik, wiersz);
			if (login == szukanyLogin) {
				znaleziony = true;
			}
		}
		plik.close();
		if (znaleziony)
		{
			konta.clear();
			plik.open("src/Konta.txt", ios::in);
			while (getline(plik, wiersz)) {
				konta.push_back(wiersz);
			}
			plik.close();
			for (int i = 0; i < konta.size(); i++)
			{
				if (czyZawiera(konta[i], szukanyLogin))
				{
					// tutaj wszystkie zmiany co do konta
					wiersz = konta[i];
					istringstream strumien(wiersz);
					strumien >> login >> haslo >> imie >> nazwisko >> telefon >> email >> typKarnetu >> uprawnienia >> ostatniaPlatnosc;
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
					if (wybor == 'k' || wybor == 'K')
					{
						noweUprawnienia = 0;
					}
					else
					{
						noweUprawnienia = 1;
					}
					
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
							nowyTypKarnetu = 0;
						}
						else
						{
							nowyTypKarnetu = wybrany - 48;
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
					if (wybor == 'T' || wybor == 't')
					{
						// wstawienie zmienionego rekordu na miejsce starego w wektorze
						konta[i] = nowyLogin + '\t' + noweHaslo + '\t' + noweImie + '\t' + noweNazwisko + '\t' + nowyTelefon + '\t' + nowyEmail + '\t' + to_string(nowyTypKarnetu)
							+ '\t' + to_string(noweUprawnienia) + '\t' + to_string(nowaOstatniaPlatnosc);
						// uaktualnienie pliku zawierajacego liste kont
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

void KontoPracownika::zarzadzajHarmoZajec(HarmonogramZajec& harmonogram)
{
	{
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
			system("cls");
			cout << "Podaj nazwe nowych zajec: ";
			cin >> nazwa;
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

			while(dataString.size() != 14 || !dobryFormat(dataString))
			{
				cout << "Podaj poprawna date" << endl;
				getline(cin >> ws, dataString);
			}
			dataZajec = parsujDate(dataString);

			system("cls");
			cout << "Podaj prowadzacego zajecia: " << endl;
			cin >> prowadzacy;
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
			if (wybor == 'T' || wybor == 't')
			{
				harmonogram.dodajZajecia(Zajecia(nazwa, opis, dataZajec, czasTrwania, liczbaMiejsc, prowadzacy, loginy));
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
			do
			{
				system("cls");
				harmonogram.przegladajHarmonogram();
				cout << "Ktore zajecia chcesz usunac?" << endl;
				cout << "ESC) Powrot" << endl;
				wybrany = _getch();
			} while (wybrany != 27 && (wybrany < '0' || wybrany > harmonogram.getListaZajec().size() + 48-1));
			if (wybrany == 27)
			{
				break;
			}
			else
			{
				do
				{
					system("cls");
					cout << "Czy na pewno chcesz usunac zajecia " << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << "?" << endl;
					cout << " T) TAK" << endl;
					cout << " N) NIE" << endl;
					wybor = _getch();
				} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
				if (wybor == 'T' || wybor == 't')
				{
					harmonogram.usunZajecia(harmonogram.getListaZajec()[wybrany - 48].getNazwa());
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
			do
			{
				system("cls");
				harmonogram.przegladajHarmonogram();
				cout << "Ktore zajecia chcesz modyfikowac?" << endl;
				cout << "ESC) Powrot" << endl;
				wybrany = _getch();
			} while (wybrany != 27 && (wybrany <= '0' || wybrany > harmonogram.getListaZajec().size() + 48-1));
			if (wybrany == 27)
			{
				break;
			}
			else
			{
				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;
				cout << "Podaj nowa nazwe zajec: ";
				cin >> nazwa;
				
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
				if (wybor == 'T' || wybor == 't')
				{
					harmonogram.zmienZajecia(harmonogram.getListaZajec()[wybrany - 48].getNazwa(), Zajecia(nazwa, opis, dataZajec, czasTrwania, liczbaMiejsc, prowadzacy, harmonogram.getListaZajec()[wybrany - 48].getLoginyUczestnikow()));
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
			return;
		}
	}
}

void KontoPracownika::wpiszDaneLogowania(string login, string haslo)
{
}

KontoPracownika::KontoPracownika(string login, string haslo)
{
	this->login = login;
	this->haslo = haslo;
}

KontoPracownika::KontoPracownika()
{
}

KontoPracownika::~KontoPracownika()
{
}

string KontoPracownika::getLogin()
{
	return this->login;
}

time_t parsujDate(string& dataStr) {
	tm strukturaCzasu = {}; // Inicjalizacja struktury tm

	istringstream strumien(dataStr);
	int godzina, minuta, dzien, miesiac, rok;

	// Parsowanie daty z formatu "hh mm dd mm yy"
	strumien >> godzina >> minuta >> dzien >> miesiac >> rok;

	// Sprawdzenie poprawnoúci parsowania
	if (strumien.fail()) {
		cerr << "B≥πd parsowania daty." << endl;
		return -1; // ZwrÛcenie b≥Ídu
	}

	// Ustawienie pÛl struktury tm
	strukturaCzasu.tm_hour = godzina-1;
	strukturaCzasu.tm_min = minuta;
	strukturaCzasu.tm_sec = 0;
	strukturaCzasu.tm_mday = dzien;
	strukturaCzasu.tm_mon = miesiac - 1; // tm_mon jest indeksowane od 0
	strukturaCzasu.tm_year = rok + 100; // tm_year liczone od 1900

	// Przekszta≥cenie struct tm na time_t
	time_t znacznikCzasu = mktime(&strukturaCzasu);

	// Sprawdzenie poprawnoúci przekszta≥cenia
	if (znacznikCzasu == -1) {
		cerr << "B≥πd przekszta≥cania daty na znacznik czasu." << endl;
		return -1;
	}

	return znacznikCzasu;
}

bool dobryFormat(string data)		// funkcja ma za zadanie sprawdzic czy podana data w stringu zgadza sie z formatem hh mm dd mm yy,
{									// ponadto sprawdza czy podane wartosci godzin i dni miesiaca sa poprawne wzgledem rzeczywistosci np. miesiac ma maks. 31 dni
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

bool czyZawiera(string tekst, string podciag) {
	// Jeúli find zwraca std::string::npos, to podciπg nie istnieje w tekúcie
	return tekst.find(podciag) != string::npos;
}