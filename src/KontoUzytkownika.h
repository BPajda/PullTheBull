#pragma once
#include "Konto.h"
#include "Zajecia.h"
#include <iostream>

using namespace std;

class KontoUzytkownika:Konto
{
public:
    void przegladajZajecia(vector<int> indeksyZajec, vector<Zajecia> listaZajec);
    void wpiszDaneLogowania(string login, string haslo);
    void zarzadzajKontemAdmin(string loginDoZmiany, string hasloDoZmiany);

    KontoUzytkownika(string login, string haslo);
    KontoUzytkownika();
    ~KontoUzytkownika();

    string getLogin();
};