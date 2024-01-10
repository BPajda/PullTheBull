#include "HarmonogramZajec.h"
#include <iostream>

using namespace std;

// Dodaj nowe zaj�cia do harmonogramu
void HarmonogramZajec::dodajZajecia(Zajecia zajecia)
{
	this->listaZajec.push_back(zajecia);
}

// Usu� zaj�cia o podanej nazwie z harmonogramu
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

// Zmie� istniej�ce zaj�cia na nowe
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

// Wy�wietl wszystkie zaj�cia z harmonogramu
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

// Getter dla wektora z zaj�ciami w harmonogramie
vector<Zajecia>& HarmonogramZajec::getListaZajec()
{
	return this->listaZajec;
}

// Konstruktor z parametrami
HarmonogramZajec::HarmonogramZajec(vector<Zajecia> listaZajec)
{
	this->listaZajec = listaZajec;
}

// Konstruktor domy�lny
HarmonogramZajec::HarmonogramZajec()
{
}

// Destruktor
HarmonogramZajec::~HarmonogramZajec()
{
}