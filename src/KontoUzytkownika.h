#pragma once
#include "Konto.h"
#include "Zajecia.h"
#include <iostream>

using namespace std;

class KontoUzytkownika:Konto
{
public:
    void przegladajZajecia(vector<int> indeksyZajec, vector<Zajecia> listaZajec);

    string getLogin();
    string getHaslo();

    void setLogin(string login);
    void setHaslo(string haslo);

    KontoUzytkownika(string login, string haslo);
    KontoUzytkownika();
    ~KontoUzytkownika();
};