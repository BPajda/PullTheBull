#pragma once
#include <iostream>
//#include "Zajecia.h"

using namespace std;

class HarmonogramZajec
{
	//Zajecia zajecia[];
public:
	void dodajZajecia(string nazwa, int dataZajec);
	void usunZajecia(string nazwa, int dataZajec);
	void zmienZajecia(string nazwa, int dataZajec, int nowaData);
	void przegladajHarmonogram();

	HarmonogramZajec();
	~HarmonogramZajec();
};
