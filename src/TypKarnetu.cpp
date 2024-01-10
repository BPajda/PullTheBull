#include "TypKarnetu.h"
#include <iostream>

using namespace std;

// Konstruktor inicjalizuj�cy obiekt TypKarnetu z podanymi danymi
TypKarnetu::TypKarnetu(string nazwa, int cena, bool open, bool zajecia) 
{
	this->nazwa = nazwa;
	this->cena = cena;
	this->open = open;
	this->zajecia = zajecia;
}

// Konstruktor domy�lny
TypKarnetu::TypKarnetu()
{
}

// Destruktor
TypKarnetu::~TypKarnetu()
{
}

// Metoda zwracaj�ca nazw� karnetu
string TypKarnetu::getNazwa() 
{
	return this->nazwa;
}

// Metoda zwracaj�ca cen� karnetu
int TypKarnetu::getCena()
{
	return this->cena;
}

// Metoda zwracaj�ca informacj�, czy karnet ma przywileje OPEN
bool TypKarnetu::getOpen()
{
	return this->open;
}

// Metoda zwracaj�ca informacj�, czy karnet obejmuje zaj�cia dodatkowe
bool TypKarnetu::getZajecia()
{
	return this->zajecia;
}