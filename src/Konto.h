#pragma once
#include <iostream>

using namespace std;

class Konto 
{
protected:
    string login;
    string haslo;
    string IDKonta;
public:
    Konto();
    ~Konto();
};
