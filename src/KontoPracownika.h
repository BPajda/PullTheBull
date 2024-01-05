#include <iostream>

using namepspace std;

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
