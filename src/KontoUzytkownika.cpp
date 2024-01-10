#include "KontoUzytkownika.h"
#include <iostream>

using namespace std;

// Konstruktor inicjalizuj¹cy obiekt KontoUzytkownika z podanym loginem i has³em
KontoUzytkownika::KontoUzytkownika(string login, string haslo)
{
	this->login = login;
	this->haslo = haslo;
}

// Konstruktor domyœlny
KontoUzytkownika::KontoUzytkownika()
{
}

// Destruktor
KontoUzytkownika::~KontoUzytkownika()
{
}

// Metoda wyœwietlaj¹ca zajêcia przypisane do danego konta u¿ytkownika
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

// Metoda do wprowadzania danych logowania (puste, poniewa¿ dane s¹ ustawiane w konstruktorze)
void KontoUzytkownika::wpiszDaneLogowania(string login, string haslo)
{
}

void KontoUzytkownika::zarzadzajKontemAdmin(string loginDoZmiany, string hasloDoZmiany)
{
}

// Metoda zwracaj¹ca login konta u¿ytkownika
string KontoUzytkownika::getLogin()
{
	return this->login;
}