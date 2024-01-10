#pragma once
#include <iostream>
#include "Konto.h"
#include "HarmonogramZajec.h"
#include "Cennik.h"

using namespace std;

class KontoPracownika:Konto
{
public:
	void zarzadzajCennikiem(Cennik& cennik);
	void zarzadzajKontami(Cennik cennik);
	void zarzadzajHarmoZajec(HarmonogramZajec& harmonogram);
	void wpiszDaneLogowania(string login, string haslo);

	KontoPracownika(string login, string haslo);
	KontoPracownika();
	~KontoPracownika();

	string getLogin();
};

string podlogiNaSpacje(string tekst);
string spacjeNaPodlogi(string tekst);
time_t parsujDate(string& dataStr);
bool dobryFormat(string data);
bool czyZawiera(string tekst, string podciag);