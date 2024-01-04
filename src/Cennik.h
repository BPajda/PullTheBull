#pragma once
#include <iostream>

using namespace std;

class Cennik
{
public:
	void dodajKarnet(string nazwa);
	void usunKarnet();
	void zmienKarnet();
	void przegladajCennik();

	Cennik();
	~Cennik();
};
