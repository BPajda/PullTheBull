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

// Metoda zwracaj�ca login konta u�ytkownika
string KontoUzytkownika::getLogin()
{
	return this->login;
}

// Getter dla has�a konta u�ytkownika
string KontoUzytkownika::getHaslo()
{
	return this->haslo;
}

// Setter ustawiaj�cy login dla konta u�ytkownika
void KontoUzytkownika::setLogin(string login)
{
	this->login = login;
}

// Setter ustawiaj�cy has�o dla konta u�ytkownika
void KontoUzytkownika::setHaslo(string haslo)
{
	this->haslo = haslo;
}

// Funkcja zamieniaj�ca podkre�lenia na spacje w tek�cie
string podlogiNaSpacje(string tekst) {
	for (char& znak : tekst) {
		if (znak == '_') {
			znak = ' ';
		}
	}
	return tekst;
}

// Funkcja zamieniaj�ca spacje na podkre�lenia w tek�cie
string spacjeNaPodlogi(string tekst) {
	for (char& znak : tekst) {
		if (znak == ' ') {
			znak = '_';
		}
	}
	return tekst;
}