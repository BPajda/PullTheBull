#pragma once
#include <iostream>
#include "Zajecia.h"
#include <vector>

using namespace std;

class HarmonogramZajec
{
	vector<Zajecia> listaZajec;
public:
	void dodajZajecia(string nazwa, int dataZajec);
	void usunZajecia(string nazwa, int dataZajec);
	void zmienZajecia(string nazwa, int dataZajec, int nowaData);
	void przegladajHarmonogram();

	HarmonogramZajec(vector<Zajecia> listaZajec);
	HarmonogramZajec();
	~HarmonogramZajec();
};

string wstawNowaLinie(const string& tekst, size_t dlugoscLinii);
string konwertujTimeT(time_t czas);