#pragma once
#include <iostream>
#include "KontoPracownika.h"
#include "Osoba.h"

using namespace std;

class Pracownik:Osoba
{
	KontoPracownika kontoPracownika;
public:
	void setImie(string imie);
	void setNazwisko(string nazwisko);
	void setEmail(string email);
	void setTelefon(string telefon);

	string getImie();
	string getNazwisko();
	string getEmail();
	string getTelefon();

	KontoPracownika getKontoPracownika();
	void setKontoPracownika(KontoPracownika kontoPracownika);
	Pracownik(string imie, string nazwisko, string telefon, string email);
	Pracownik();
	~Pracownik();
 };
