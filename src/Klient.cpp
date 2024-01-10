#include "Klient.h"
#include <iostream>

using namespace std;

// Setter ustawiaj�cy imi� klienta
void Klient::setImie(string imie)
{
	this->imie = imie;
}

// Setter ustawiaj�cy nazwisko klienta
void Klient::setNazwisko(string nazwisko)
{
	this->nazwisko = nazwisko;
}

// Setter ustawiaj�cy telefon klienta
void Klient::setTelefon(string telefon)
{
	this->telefon = telefon;
}

// Setter ustawiaj�cy email klienta
void Klient::setEmail(string email)
{
	this->email = email;
}

// Konstruktor z parametrami
Klient::Klient(string imie, string nazwisko, string telefon, string email)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->telefon = telefon;
	this->email = email;
}

// Konstruktor domy�lny
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

// Ustawienie konta u�ytkownika klienta
void Klient::setKontoUzytkownika(KontoUzytkownika konto) 
{
	this->kontoUzytkownika = konto;
}

// Ustawienie indeks�w zaj��, na kt�re zapisany jest klient
void Klient::setIndeksyZajec(vector<int> indeksyZajec)
{
	this->indeksyZajec = indeksyZajec;
}

// Getter dla indeks�w zaj�� klienta
vector<int>& Klient::getIndeksyZajec()
{
	return this->indeksyZajec;
}

// Getter dla karnetu klienta
Karnet& Klient::getKarnet() 
{
	return this->posiadanyKarnet;
}

// Getter dla konta u�ytkownika klienta
KontoUzytkownika Klient::getKontoUzytkownika() 
{
	return this->kontoUzytkownika;
}

// Getter dla imienia klienta
string Klient::getImie() {
	return this->imie;
}

// Getter dla nazwiska klienta
string Klient::getNazwisko() 
{
	return this->nazwisko;
}

// Getter dla telefonu klienta
string Klient::getTelefon() 
{
	return this->telefon;
}

// Getter dla emaila klienta
string Klient::getEmail() 
{
	return this->email;
}