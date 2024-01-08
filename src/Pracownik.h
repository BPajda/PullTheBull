#pragma once
#include <iostream>
#include "KontoPracownika.h"
#include "Osoba.h"

using namespace std;

class Pracownik:Osoba
{
	KontoPracownika kontoPracownika;
public:
	KontoPracownika getKontoPracownika();
	void setKontoPracownika(KontoPracownika kontoPracownika);
	Pracownik(string imie, string nazwisko, string telefon, string email);
	Pracownik();
	~Pracownik();
 };
