#include <iostream>
#include "KontoPracownika.h"
#include <conio.h>
#include <fstream>
#include <string>

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

bool szukajWektor(vector<TypKarnetu> wektor, string nazwa)
{
	for (int i = 0; i < wektor.size(); i++)
	{
		if (wektor[i].getNazwa() == nazwa)
		{
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
		break;
	case 27:
		return;
		break;
	}
}

void KontoPracownika::zarzadzajKontami()
{
}

void KontoPracownika::zarzadzajHarmoZajec(HarmonogramZajec& harmonogram)
{
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