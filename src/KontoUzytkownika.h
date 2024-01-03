#include <iostream>
#include "Konto.h"

using namespace std;
class KontoUzytkownika:Konto
{
public:
    void rezerwacjaZajec();
    void usuniecieRezerwacji();
    void przegladajZajecia();
    void przegladajCennik();
    void wpiszDaneLogowania(string login, string haslo);
    void wyswietlKarnet();
    void zarzadzajKontemAdmin(string loginDoZmiany, string hasloDoZmiany);
    KontoUzytkownika();
    ~KontoUzytkownika();
};
