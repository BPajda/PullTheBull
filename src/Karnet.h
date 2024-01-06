#pragma once
#include <iostream>
#include "TypKarnetu.h"

using namespace std;

class Karnet
{
public:
	TypKarnetu * typkarnetu;
	time_t ostatniaPlatnosc;
	bool sprawdzWaznosc();
	void oplacKarnet();
	Karnet();
	~Karnet();
};
