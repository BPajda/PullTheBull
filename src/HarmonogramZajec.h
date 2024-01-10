#pragma once
#include "Zajecia.h"
#include <iostream>
#include <vector>

using namespace std;

class HarmonogramZajec
{
   vector<Zajecia> listaZajec;
public:
	void dodajZajecia(Zajecia zajecia);
	void usunZajecia(string nazwa);
	void zmienZajecia(string nazwa, Zajecia zajecia);
	void przegladajHarmonogram();

	HarmonogramZajec(vector<Zajecia> listaZajec);
	HarmonogramZajec();
	~HarmonogramZajec();

	vector<Zajecia>& getListaZajec();
};

string wstawNowaLinie(const string& tekst, size_t dlugoscLinii);
string konwertujTimeT(time_t czas);