#include "TypKarnetu.h"
#include <iostream>

using namespace std;

// Konstruktor inicjalizuj¹cy obiekt TypKarnetu z podanymi danymi
TypKarnetu::TypKarnetu(string nazwa, int cena, bool open, bool zajecia) 
{
	this->nazwa = nazwa;
	this->cena = cena;
	this->open = open;
	this->zajecia = zajecia;
}

// Konstruktor domyœlny
TypKarnetu::TypKarnetu()
{
}

// Destruktor
TypKarnetu::~TypKarnetu()
{
}

// Metoda zwracaj¹ca nazwê karnetu
string TypKarnetu::getNazwa() 
{
	return this->nazwa;
}

// Metoda zwracaj¹ca cenê karnetu
int TypKarnetu::getCena()
{
	return this->cena;
}

// Metoda zwracaj¹ca informacjê, czy karnet ma przywileje OPEN
bool TypKarnetu::getOpen()
{
	return this->open;
}

// Metoda zwracaj¹ca informacjê, czy karnet obejmuje zajêcia dodatkowe
bool TypKarnetu::getZajecia()
{
	return this->zajecia;
}

//Setter dla typu karnetu
void TypKarnetu::setNazwa(string nazwa)
{
	this->nazwa = nazwa;
}

//Setter dla ceny
void TypKarnetu::setCena(int cena)
{
	this->cena = cena;
}

// Setter dla open
void TypKarnetu::setOpen(bool open)
{
	this->open = open;

}

// Setter dla zajęć
void TypKarnetu::setZajecia(bool zajecia)
{
	this->zajecia = zajecia;
}


