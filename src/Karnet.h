#pragma once
#include <iostream>
#include "TypKarnetu.h"

using namespace std;

class Karnet
{

public:
	time_t ostatniaPlatnosc;
	TypKarnetu typkarnetu;

	bool sprawdzWaznosc();
	void oplacKarnet();
	void wyswietlKarnet();

	time_t getOstatniaPlatnosc();
	TypKarnetu getTypKarnetu();

	Karnet(time_t ostatniaPlatnosc, TypKarnetu typKarnetu);
	Karnet();
	~Karnet();
};
