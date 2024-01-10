#include <iostream>
#include "Karnet.h"
#include <ctime>

using namespace std;

// SprawdŸ wa¿noœæ karnetu
bool Karnet::sprawdzWaznosc()
{
	// Karnet jest wa¿ny przez 30 dni (2592000 sekund)
	return (time(0) - this->ostatniaPlatnosc < 2592000);
}

// Op³aæ karnet (je¿eli wa¿ny, przed³u¿ wa¿noœæ, w przeciwnym razie ustaw aktualn¹ datê jako datê p³atnoœci)
void Karnet::oplacKarnet()
{
	if (this->sprawdzWaznosc())
	{
		// Dodaj 30 dni do ostatniej p³atnoœci
		this->ostatniaPlatnosc += 2592000;
	}
	else
	{
		// Ustaw aktualn¹ datê jako datê p³atnoœci
		this->ostatniaPlatnosc = time(0);
	}
}

// Konstruktor z parametrami
Karnet::Karnet(time_t ostatniaPlatnosc, TypKarnetu typKarnetu)
{
	this->ostatniaPlatnosc = ostatniaPlatnosc;
	this->typkarnetu = typKarnetu;
}

// Konstruktor domyœlny
Karnet::Karnet()
{
}

// Destruktor
Karnet::~Karnet()
{
}

// Getter dla typu karnetu
TypKarnetu Karnet::getTypKarnetu()
{
	return this->typkarnetu;
}

// Getter dla daty ostatniej p³atnoœci
time_t Karnet::getOstatniaPlatnosc()
{
	return this->ostatniaPlatnosc;
}

// Setter dla ostatniej p³atnoœci za karnet
void Karnet::setOstatniaPlatnosc(time_t ostatniaPlatnosc)
{
	this->ostatniaPlatnosc = ostatniaPlatnosc;
}

// Setter dla typu karnetu
void Karnet::setTypKarnetu(TypKarnetu typKarnetu)
{
	this->typkarnetu = typKarnetu;
}

// Wyœwietl informacje o karnecie
void Karnet::wyswietlKarnet()
{
	cout << "==== Posiadany karnet ====" << endl;
	cout << " Karnet " << this->getTypKarnetu().getNazwa() << endl;
	cout << " Cena " << this->getTypKarnetu().getCena() << endl;
	if (this->getTypKarnetu().getOpen())
	{
		cout << " Przywileje OPEN -> TAK " << endl;
	}
	else
	{
		cout << " Przywileje OPEN -> NIE " << endl;
	}
	if (this->getTypKarnetu().getZajecia())
	{
		cout << " Dostepnosc zajec -> TAK " << endl;
	}
	else
	{
		cout << " Dostepnosc zajec -> NIE " << endl;
	}
	if (this->ostatniaPlatnosc != 0)
	{
		time_t dataWaznosci = this->ostatniaPlatnosc + 2592000;
		tm data;
		localtime_s(&data, &dataWaznosci);
		cout << " Wazny do: " << data.tm_mday << "." << data.tm_mon + 1 << "." << data.tm_year + 1900 << "r." << endl;
	}
	cout << "=========================" << endl;
}