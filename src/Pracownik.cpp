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

// Getter dla imienia
string Pracownik::getImie()
{
	return this->imie;
}

// Getter dla nazwiska
string Pracownik::getNazwisko()
{
	return this->nazwisko;
}

// Getter dla telefonu
string Pracownik::getTelefon()
{
	return this->telefon;
}

// Getter dla email
string Pracownik::getEmail()
{
	return this->email;
}

// Setter dla imienia
void Pracownik::setImie(string imie)
{
	this->imie = imie;
}

// Setter dla nazwiska
void Pracownik::setNazwisko(string nazwisko)
{
	this->nazwisko = nazwisko;
}

// Setter dla email
void Pracownik::setEmail(string email)
{
	this->email = email;
}

// Setter dla telefonu
void Pracownik::setTelefon(string telefon)
{
	this->telefon = telefon;
}
