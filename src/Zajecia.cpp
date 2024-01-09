#include "Zajecia.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void Zajecia::modyfikujZajecia()
{
}

Zajecia::Zajecia(string nazwa, string opis, time_t dataZajec, int czasTrwania, int liczbaMiejsc, string prowadzacy, vector<string> loginyUczestnikow)
{
    this->prowadzacy = prowadzacy;
    this->nazwa = nazwa;
    this->opis = opis;
    this->dataZajec = dataZajec;
    this->czasTrwania = czasTrwania;
    this->liczbaMiejsc = liczbaMiejsc;
    this->loginyUczestnikow = loginyUczestnikow;
}

Zajecia::Zajecia()
{
}

Zajecia::~Zajecia()
{
}

string Zajecia::getProwadzacy()
{
    return this->prowadzacy;
}

vector<string>& Zajecia::getLoginyUczestnikow()
{
    return this->loginyUczestnikow;
}

string Zajecia::getNazwa()
{
    return this->nazwa;
}

string Zajecia::getOpis()
{
    return this->opis;
}

time_t Zajecia::getDataZajec()
{
    return this->dataZajec;
}

int Zajecia::getCzasTrwania()
{
    return this->czasTrwania;
}

int Zajecia::getLiczbaMiejsc()
{
    return this->liczbaMiejsc;
}

void Zajecia::info()
{
    cout << this->nazwa << endl;
    cout << wstawNowaLinie(this->opis, 80) << endl;
    cout << "Data zajec: " << konwertujTimeT(this->dataZajec) << endl;
    cout << "Czas trwania zajec: " << this->czasTrwania << "min" << endl;
    cout << "Liczba miejsc: " << this->liczbaMiejsc << endl;
    cout << "Liczba wolnych miejsc: " << this->liczbaMiejsc - this->loginyUczestnikow.size() << endl;
    cout << "Prowadzacy: " << this->prowadzacy << endl << endl;
}

string wstawNowaLinie(const string& tekst, size_t dlugoscLinii) {
    string wynik;
    istringstream strumien(tekst);
    string slowo;

    size_t aktualnaDlugosc = 0;

    while (strumien >> slowo) {
        if (aktualnaDlugosc + slowo.length() <= dlugoscLinii) {
            // Dodaj s³owo do bie¿¹cej linii
            if (!wynik.empty()) {
                wynik += ' ';
                aktualnaDlugosc++;
            }
            wynik += slowo;
            aktualnaDlugosc += slowo.length();
        }
        else {
            // Rozpocznij now¹ liniê z bie¿¹cym s³owem
            wynik += '\n' + slowo;
            aktualnaDlugosc = slowo.length();
        }
    }

    return wynik;
}

string konwertujTimeT(time_t czas) {
    tm czasStruktura;
    localtime_s(&czasStruktura, &czas);
    stringstream ss;
    ss << put_time(&czasStruktura, "%d-%m-%Y %H:%M");

    return ss.str();
}