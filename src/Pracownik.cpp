#include "Pracownik.h"
#include <iostream>

using namespace std;

// Metoda zwracaj¹ca obiekt KontoPracownika przypisany do pracownika
KontoPracownika Pracownik::getKontoPracownika()
{
	return this->kontoPracownika;
}

// Metoda ustawiaj¹ca obiekt KontoPracownika dla pracownika
void Pracownik::setKontoPracownika(KontoPracownika kontoPracownika)
{
	this->kontoPracownika = kontoPracownika;
}

// Konstruktor inicjalizuj¹cy obiekt Pracownik z podanymi danymi
Pracownik::Pracownik(string imie, string nazwisko, string telefon, string email)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->telefon = telefon;
	this->email = email;
}

// Konstruktor domyœlny
Pracownik::Pracownik()
{
}

// Destruktor
Pracownik::~Pracownik()
{
}
