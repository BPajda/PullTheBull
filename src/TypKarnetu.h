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
	void modyfikujDaneKarnetu(string nazwa, int cena = 0, bool open = false, bool zajecia = false);
	string getNazwa();
	int getCena();
	bool getOpen();
	bool getZajecia();
	TypKarnetu(string nazwa, int cena, bool open, bool zajecia);
	TypKarnetu();
	~TypKarnetu();
};
