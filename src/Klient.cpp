#include "Klient.h"
#include <iostream>

using namespace std;

// Funkcja do wprowadzania danych klienta (niezaimplementowana w kodzie)
void Klient::wpiszDane(string imie, string nazwisko, string telefon, string email)
{
}

// Konstruktor z parametrami
Klient::Klient(string imie, string nazwisko, string telefon, string email)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->telefon = telefon;
	this->email = email;
}

// Konstruktor domyœlny
Klient::Klient() 
{
}

// Destruktor
Klient::~Klient()
{
}

// Ustawienie danych posiadanego karnetu
void Klient::setKarnet(Karnet karnet) 
{
	this->posiadanyKarnet = karnet;
}

// Ustawienie konta u¿ytkownika klienta
void Klient::setKontoUzytkownika(KontoUzytkownika konto) 
{
	this->kontoUzytkownika = konto;
}

// Ustawienie indeksów zajêæ, na które zapisany jest klient
void Klient::setIndeksyZajec(vector<int> indeksyZajec)
{
	this->indeksyZajec = indeksyZajec;
}

// Getter dla indeksów zajêæ klienta
vector<int>& Klient::getIndeksyZajec()
{
	return this->indeksyZajec;
}

// Getter dla karnetu klienta
Karnet& Klient::getKarnet() 
{
	return this->posiadanyKarnet;
}

// Getter dla konta u¿ytkownika klienta
KontoUzytkownika Klient::getKontoUzytkownika() 
{
	return this->kontoUzytkownika;
}