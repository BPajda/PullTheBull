#pragma once
#include <iostream>
#include "Pracownik.h"
#include <vector>

using namespace std;

class Zajecia
{
public:
	string prowadzacy;
	vector<string> loginyUczestnikow;
	string nazwa;
	string opis;
	time_t dataZajec;
	int czasTrwania;
	int liczbaMiejsc;
public:
	void modyfikujZajecia();

	Zajecia(string nazwa, string opis, time_t dataZajec, int czasTrwania, int liczbaMiejsc, string prowadzacy, vector<string> loginyUczestnikow);
	Zajecia();
	~Zajecia();

	string getProwadzacy();
	vector<string>& getLoginyUczestnikow();
	string getNazwa();
	string getOpis();
	time_t getDataZajec();
	int getCzasTrwania();
	int getLiczbaMiejsc();
	void info();
};

string wstawNowaLinie(const string& tekst, size_t dlugoscLinii);
string konwertujTimeT(time_t czas);