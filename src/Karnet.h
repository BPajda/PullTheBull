#pragma once
#include <iostream>
#include "TypKarnetu.h"

using namespace std;

class Karnet
{
	time_t ostatniaPlatnosc;
	TypKarnetu typkarnetu;
public:
	bool sprawdzWaznosc();
	void oplacKarnet();
	void wyswietlKarnet();

	time_t getOstatniaPlatnosc();
	TypKarnetu getTypKarnetu();

	void setOstatniaPlatnosc(time_t ostatniaPlatnosc);
	void setTypKarnetu(TypKarnetu typKarnetu);

	Karnet(time_t ostatniaPlatnosc, TypKarnetu typKarnetu);
	Karnet();
	~Karnet();
};
