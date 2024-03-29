#pragma once
#include "KontoUzytkownika.h"
#include "Karnet.h"
#include "Osoba.h"
#include <iostream>

using namespace std;

class Klient:Osoba
{
	Karnet posiadanyKarnet;
	KontoUzytkownika kontoUzytkownika;
	vector<int> indeksyZajec;
public:
	void setImie(string imie);
	void setNazwisko(string nazwisko);
	void setTelefon(string telefon);
	void setEmail(string email);
	void setKarnet(Karnet karnet);
	void setKontoUzytkownika(KontoUzytkownika konto);
	void setIndeksyZajec(vector<int> indeksyZajec);

	vector<int>& getIndeksyZajec();
	Karnet& getKarnet();
	KontoUzytkownika getKontoUzytkownika();
	string getImie();
	string getNazwisko();
	string getTelefon();
	string getEmail();

	Klient(string imie, string nazwisko, string telefon, string email);
	Klient();
	~Klient();
};
