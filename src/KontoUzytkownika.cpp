#include "KontoUzytkownika.h"
#include <iostream>

using namespace std;

// Konstruktor inicjalizujący obiekt KontoUzytkownika z podanym loginem i hasłem
KontoUzytkownika::KontoUzytkownika(string login, string haslo)
{
	this->login = login;
	this->haslo = haslo;
}

// Konstruktor domyślny
KontoUzytkownika::KontoUzytkownika()
{
}

// Destruktor
KontoUzytkownika::~KontoUzytkownika()
{
}

// Metoda wyświetlająca zajęcia przypisane do danego konta użytkownika
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

// Metoda zwracająca login konta użytkownika
string KontoUzytkownika::getLogin()
{
	return this->login;
}

// Getter dla hasła konta użytkownika
string KontoUzytkownika::getHaslo()
{
	return this->haslo;
}

// Setter ustawiający login dla konta użytkownika
void KontoUzytkownika::setLogin(string login)
{
	this->login = login;
}

// Setter ustawiający hasło dla konta użytkownika
void KontoUzytkownika::setHaslo(string haslo)
{
	this->haslo = haslo;
}