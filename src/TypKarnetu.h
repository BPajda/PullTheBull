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
	void modyfikujDaneKarnetu(string nazwa, int cena = 0, bool open = false, bool zajecia = false);

	TypKarnetu(string nazwa, int cena, bool open, bool zajecia);
	TypKarnetu();
	~TypKarnetu();
};
