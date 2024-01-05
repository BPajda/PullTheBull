#include <iostream>
#include "Karnet.h"
#include "KontoUzytkownika.h"

using namespace std;

class Klient
{
	Karnet posiadanyKarnet;
	KontoUzytkownika kontoUzytkownika;
public:
	void wpiszDane(string imie, string nazwisko, string adres, string telefon, string email);

	Klient();
	~Klient();
};
