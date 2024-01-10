#pragma once
#include <iostream>


using namespace std;

class TypKarnetu
{
public:
	string nazwa;
	int cena;
	bool open;
	bool zajecia;

public:
	string getNazwa();
	int getCena();
	bool getOpen();
	bool getZajecia();
	TypKarnetu(string nazwa, int cena, bool open, bool zajecia);
	TypKarnetu();
	~TypKarnetu();
};
