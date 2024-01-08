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
	void zarzadzajKontami();
	void zarzadzajHarmoZajec(HarmonogramZajec& harmonogram);
	void wpiszDaneLogowania(string login, string haslo);

	KontoPracownika(string login, string haslo);
	KontoPracownika();
	~KontoPracownika();

	string getLogin();
};
