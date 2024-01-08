#include "Klient.h"
#include <iostream>

using namespace std;

void Klient::wpiszDane(string imie, string nazwisko, string telefon, string email)
{
}

Klient::Klient(string imie, string nazwisko, string telefon, string email)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->telefon = telefon;
	this->email = email;
}

Klient::Klient() 
{
}

Klient::~Klient()
{
}

void Klient::setKarnet(Karnet karnet) 
{
	this->posiadanyKarnet = karnet;
}

void Klient::setKontoUzytkownika(KontoUzytkownika konto) 
{
	this->kontoUzytkownika = konto;
}

void Klient::setIndeksyZajec(vector<int> indeksyZajec)
{
	this->indeksyZajec = indeksyZajec;
}

vector<int>& Klient::getIndeksyZajec()
{
	return this->indeksyZajec;
}

Karnet& Klient::getKarnet() 
{
	return this->posiadanyKarnet;
}

KontoUzytkownika Klient::getKontoUzytkownika() 
{
	return this->kontoUzytkownika;
}