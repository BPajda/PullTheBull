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
	void zwrocListeKarnetow();
	void modyfikujDaneKarnetu(string nazwa, int cena = 0, bool open = false, bool zajecia = false);

	TypKarnetu();
	~TypKarnetu();
};
