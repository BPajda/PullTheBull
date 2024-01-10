#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Zajecia
{
	string prowadzacy;
	vector<string> loginyUczestnikow;
	string nazwa;
	string opis;
	time_t dataZajec;
	int czasTrwania;
	int liczbaMiejsc;
public:

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

	void setProwadzacy(string prowadzacy);
	void setLoginyUczestnikow(vector<string> loginyUczestnikow);
	void setNazwa(string nazwa);
	void setOpis(string opis);
	void setDataZajec(time_t dataZajec);
	void setCzasTrwania(int czasTrwania);
	void setLiczbaMiejsc(int liczbaMiejsc);

	void info();
};

string wstawNowaLinie(const string& tekst, size_t dlugoscLinii);
string konwertujTimeT(time_t czas);