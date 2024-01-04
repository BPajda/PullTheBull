#include <iostream>
#include "TypKarnetu.h"

using namespace std;

class Karnet
{
	int ostatniaPlatnosc;
	TypKarnetu * typkarnetu;
public:
	bool sprawdzWaznosc();
	void oplacKarnet();
	Karnet();
	~Karnet();
};
