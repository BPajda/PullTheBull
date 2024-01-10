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

	KontoPracownika(string login, string haslo);
	KontoPracownika();
	~KontoPracownika();

	string getLogin();
	string getHaslo();

	void setLogin(string login);
	void setHaslo(string haslo);
};

string podlogiNaSpacje(string tekst);
string spacjeNaPodlogi(string tekst);
time_t parsujDate(string& dataStr);
bool dobryFormat(string data);
bool czyZawiera(string tekst, string podciag);