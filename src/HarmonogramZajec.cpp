#include "HarmonogramZajec.h"
#include <iostream>

using namespace std;

void HarmonogramZajec::dodajZajecia(string nazwa, int dataZajec)
{
}

void HarmonogramZajec::usunZajecia(string nazwa, int dataZajec)
{
}

void HarmonogramZajec::zmienZajecia(string nazwa, int dataZajec, int nowaData)
{
}

void HarmonogramZajec::przegladajHarmonogram()
{

	cout << "===== Harmonogram Zajec =====" << endl << endl;
	for (int i = 0; i < this->listaZajec.size(); i++)
	{
		cout << " " << i+1 << ") ";
		listaZajec[i].info();
	}
	cout << "=============================" << endl;
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