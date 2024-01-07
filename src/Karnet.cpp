#include <iostream>
#include "Karnet.h"
#include <ctime>

using namespace std;

bool Karnet::sprawdzWaznosc()
{
	return (time(0) - this->ostatniaPlatnosc < 2592000);
}

void Karnet::oplacKarnet()
{
	if (this->sprawdzWaznosc())
	{
		this->ostatniaPlatnosc += 2592000;
	}
	else
	{
		this->ostatniaPlatnosc = time(0);
	}
}

Karnet::Karnet(time_t ostatniaPlatnosc, TypKarnetu typKarnetu)
{
	this->ostatniaPlatnosc = ostatniaPlatnosc;
	this->typkarnetu = typKarnetu;
}

Karnet::Karnet()
{
}

Karnet::~Karnet()
{
}

TypKarnetu Karnet::getTypKarnetu()
{
	return this->typkarnetu;
}

time_t Karnet::getOstatniaPlatnosc()
{
	return this->ostatniaPlatnosc;
}

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