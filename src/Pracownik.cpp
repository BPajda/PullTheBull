#include "Pracownik.h"
#include <iostream>

using namespace std;

KontoPracownika Pracownik::getKontoPracownika()
{
	return this->kontoPracownika;
}

void Pracownik::setKontoPracownika(KontoPracownika kontoPracownika)
{
	this->kontoPracownika = kontoPracownika;
}

Pracownik::Pracownik(string imie, string nazwisko, string telefon, string email)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->telefon = telefon;
	this->email = email;
}

Pracownik::Pracownik()
{
}

Pracownik::~Pracownik()
{
}
