#include "KontoUzytkownika.h"
#include <iostream>

using namespace std;

// Konstruktor inicjalizuj�cy obiekt KontoUzytkownika z podanym loginem i has�em
KontoUzytkownika::KontoUzytkownika(string login, string haslo)
{
	this->login = login;
	this->haslo = haslo;
}

// Konstruktor domy�lny
KontoUzytkownika::KontoUzytkownika()
{
}

// Destruktor
KontoUzytkownika::~KontoUzytkownika()
{
}

// Metoda wy�wietlaj�ca zaj�cia przypisane do danego konta u�ytkownika
void KontoUzytkownika::przegladajZajecia(vector<int> indeksyZajec, vector<Zajecia> listaZajec)
{
	int liczbaZajec = 0;
	cout << "===== Twoje Zajecia =====" << endl << endl;
	for (int i = 0; i < indeksyZajec.size(); i++)
	{
				cout << indeksyZajec[i] << ") ";
				listaZajec[indeksyZajec[i]].info();
	}
	cout << "=========================" << endl;
}

// Metoda do wprowadzania danych logowania (puste, poniewa� dane s� ustawiane w konstruktorze)
void KontoUzytkownika::wpiszDaneLogowania(string login, string haslo)
{
}

void KontoUzytkownika::zarzadzajKontemAdmin(string loginDoZmiany, string hasloDoZmiany)
{
}

// Metoda zwracaj�ca login konta u�ytkownika
string KontoUzytkownika::getLogin()
{
	return this->login;
}