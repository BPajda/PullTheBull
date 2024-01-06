#pragma once
#include <iostream>
#include "Karnet.h"
#include "KontoUzytkownika.h"
#include "Osoba.h"


using namespace std;

class Klient:Osoba
{
public:
	Karnet posiadanyKarnet;
	KontoUzytkownika kontoUzytkownika;
	void wpiszDane(string imie, string nazwisko, string telefon, string email);

	Klient();
	~Klient();
};
