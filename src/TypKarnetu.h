#pragma once
#include <iostream>


using namespace std;

class TypKarnetu
{
	string nazwa;
	int cena;
	bool open;
	bool zajecia;

public:
	string getNazwa();
	int getCena();
	bool getOpen();
	bool getZajecia();

	void setNazwa(string nazwa);
	void setCena(int cena);
	void setOpen(bool open);
	void setZajecia(bool zajecia);

	TypKarnetu(string nazwa, int cena, bool open, bool zajecia);
	TypKarnetu();
	~TypKarnetu();
};
