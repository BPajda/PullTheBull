#include <iostream>
#include "Cennik.h"

using namespace std;

void Cennik::dodajKarnet(TypKarnetu nowyTyp)
{
	this->typyKarnetow.push_back(nowyTyp);
}

void Cennik::usunKarnet(string nazwa)
{
}

void Cennik::zmienKarnet(string nazwa)
{
}

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

Cennik::Cennik(vector<TypKarnetu> typyKarnetow)
{
	this->typyKarnetow = typyKarnetow;
}

Cennik::Cennik()
{
}

Cennik::~Cennik()
{
}
