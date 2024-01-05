#pragma once
#include <iostream>

using namespace std;

class KontoPracownika
{
public:
	void zarzadzajCennikiem();
	void zarzadzajKontami();
	void zarzadzajHarmoZajec();
	void wpiszDaneLogowania(string login, string haslo);

	KontoPracownika();
	~KontoPracownika();
};
