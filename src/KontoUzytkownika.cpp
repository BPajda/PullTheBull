#include "KontoUzytkownika.h"
#include <iostream>

using namespace std;

KontoUzytkownika::KontoUzytkownika(string login, string haslo)
{
	this->login = login;
	this->haslo = haslo;
}

KontoUzytkownika::KontoUzytkownika()
{
}

KontoUzytkownika::~KontoUzytkownika()
{
}

void KontoUzytkownika::przegladajZajecia(vector<int> indeksyZajec, vector<Zajecia> listaZajec)
{
	int liczbaZajec = 0;
	cout << "===== Twoje Zajecia =====" << endl << endl;
	for (int i = 0; i < indeksyZajec.size(); i++)
	{
				cout << indeksyZajec[i] << ") ";
				listaZajec[indeksyZajec[i]].info();
	}
	cout << "=========================" << endl;
}

void KontoUzytkownika::wpiszDaneLogowania(string login, string haslo)
{
}

void KontoUzytkownika::zarzadzajKontemAdmin(string loginDoZmiany, string hasloDoZmiany)
{
}

string KontoUzytkownika::getLogin()
{
	return this->login;
}