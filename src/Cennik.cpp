#include "Cennik.h"
#include <iostream>

using namespace std;

// Dodaj nowy karnet do cennika
void Cennik::dodajKarnet(TypKarnetu nowyTyp)
{
	this->typyKarnetow.push_back(nowyTyp);
}

// Usuñ karnet o podanej nazwie z cennika
void Cennik::usunKarnet(string nazwa)
{
	for (int i = 0; i < this->typyKarnetow.size(); i++)
	{
		if (this->typyKarnetow[i].getNazwa() == nazwa)
		{
			this->typyKarnetow.erase(this->typyKarnetow.begin() + i);
		}
	}
}

// Zmieñ istniej¹cy karnet na nowy
void Cennik::zmienKarnet(string nazwa, TypKarnetu zmienionyKarnet)
{
	for (int i = 0; i < this->typyKarnetow.size(); i++)
	{
		if (this->typyKarnetow[i].getNazwa() == nazwa)
		{
			this->typyKarnetow[i] = zmienionyKarnet;
		}
	}
}

// Wyœwietl wszystkie dostêpne karnety w cenniku
void Cennik::przegladajCennik()
{
	cout << "====== Dostepne Karnety ======" << endl << endl;
	for (int i = 1; i < this->typyKarnetow.size(); i++)
	{
		cout << " " << i << ") " << typyKarnetow[i].getNazwa() << endl;
		cout << " Cena: " << typyKarnetow[i].getCena() << "zl" << endl;
		if (this->typyKarnetow[i].getOpen())
		{
			cout << " Przywileje OPEN -> TAK " << endl;
		}
		else
		{
			cout << " Przywileje OPEN -> NIE " << endl;
		}
		if (this->typyKarnetow[i].getZajecia())
		{
			cout << " Dostepnosc zajec -> TAK " << endl;
		}
		else
		{
			cout << " Dostepnosc zajec -> NIE " << endl;
		}
		cout << endl;
	}
	cout << "==============================" << endl;
}

// Konstruktor z parametrami
Cennik::Cennik(vector<TypKarnetu> typyKarnetow)
{
	this->typyKarnetow = typyKarnetow;
}

// Konstruktor domyœlny
Cennik::Cennik()
{
}

// Destruktor
Cennik::~Cennik()
{
}

// Getter dla wektora z typami karnetów
vector<TypKarnetu>& Cennik::getTypyKarnetow() {
	return this->typyKarnetow;
}