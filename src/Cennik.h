#pragma once
#include <iostream>
#include "TypKarnetu.h"
#include <vector>

using namespace std;

class Cennik
{
	vector<TypKarnetu> typyKarnetow;
public:
	void dodajKarnet(TypKarnetu nowyTyp);
	void usunKarnet(string nazwa);
	void zmienKarnet(string nazwa);
	void przegladajCennik();

	Cennik(vector<TypKarnetu> typyKarnetow);
	Cennik();
	~Cennik();
};
