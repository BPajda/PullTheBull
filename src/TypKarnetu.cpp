#include <iostream>
#include "TypKarnetu.h"

using namespace std;

void TypKarnetu::modyfikujDaneKarnetu(string nazwa, int cena, bool open, bool zajecia)
{
}

TypKarnetu::TypKarnetu(string nazwa, int cena, bool open, bool zajecia) 
{
	this->nazwa = nazwa;
	this->cena = cena;
	this->open = open;
	this->zajecia = zajecia;
}

TypKarnetu::TypKarnetu()
{
}

TypKarnetu::~TypKarnetu()
{
}

string TypKarnetu::getNazwa() 
{
	return this->nazwa;
}

int TypKarnetu::getCena()
{
	return this->cena;
}

bool TypKarnetu::getOpen()
{
	return this->open;
}
bool TypKarnetu::getZajecia()
{
	return this->zajecia;
}