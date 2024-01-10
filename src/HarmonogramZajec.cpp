#include "HarmonogramZajec.h"
#include <iostream>

using namespace std;

// Dodaj nowe zajęcia do harmonogramu
void HarmonogramZajec::dodajZajecia(Zajecia zajecia)
{
	this->listaZajec.push_back(zajecia);
}

// Usuń zajęcia o podanej nazwie z harmonogramu
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

// Zmień istniejące zajęcia na nowe
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

// Wyświetl wszystkie zajęcia z harmonogramu
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

// Getter dla wektora z zajęciami w harmonogramie
vector<Zajecia>& HarmonogramZajec::getListaZajec()
{
	return this->listaZajec;
}

// Setter dla listy zajęć harmonogramu
void HarmonogramZajec::setListaZajec(vector<Zajecia> listaZajec)
{
	this->listaZajec = listaZajec;
}

// Konstruktor z parametrami
HarmonogramZajec::HarmonogramZajec(vector<Zajecia> listaZajec)
{
	this->listaZajec = listaZajec;
}

// Konstruktor domyślny
HarmonogramZajec::HarmonogramZajec()
{
}

// Destruktor
HarmonogramZajec::~HarmonogramZajec()
{
}