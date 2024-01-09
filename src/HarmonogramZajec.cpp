#include "HarmonogramZajec.h"
#include <iostream>

using namespace std;

void HarmonogramZajec::dodajZajecia(Zajecia zajecia)
{
	this->listaZajec.push_back(zajecia);
}

void HarmonogramZajec::usunZajecia(string nazwa)
{
	for (int i = 0; i < this->listaZajec.size(); i++)
	{
		if (this->listaZajec[i].getNazwa() == nazwa)
		{
			this->listaZajec.erase(this->listaZajec.begin() + i);
		}
	}
}

void HarmonogramZajec::zmienZajecia(string nazwa, Zajecia zajecia)
{
	for (int i = 0; i < this->listaZajec.size(); i++)
	{
		if (this->listaZajec[i].getNazwa() == nazwa)
		{
			this->listaZajec[i] = zajecia;
		}
	}
}

void HarmonogramZajec::przegladajHarmonogram()
{

	cout << "===== Harmonogram Zajec =====" << endl << endl;
	for (int i = 0; i < this->listaZajec.size(); i++)
	{
		cout << " " << i << ") ";
		listaZajec[i].info();
	}
	cout << "=============================" << endl;
}

vector<Zajecia>& HarmonogramZajec::getListaZajec()
{
	return this->listaZajec;
}

HarmonogramZajec::HarmonogramZajec(vector<Zajecia> listaZajec)
{
	this->listaZajec = listaZajec;
}

HarmonogramZajec::HarmonogramZajec()
{
}

HarmonogramZajec::~HarmonogramZajec()
{
}