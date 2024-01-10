#include "Zajecia.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// Konstruktor inicjalizuj¹cy obiekt Zajecia z podanymi danymi
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

// Konstruktor domyœlny
Zajecia::Zajecia()
{
}

// Destruktor
Zajecia::~Zajecia()
{
}

// Metoda zwracaj¹ca prowadz¹cego zajêcia
string Zajecia::getProwadzacy()
{
	return this->prowadzacy;
}

// Metoda zwracaj¹ca wektor loginów uczestników zajêæ
vector<string>& Zajecia::getLoginyUczestnikow()
{
	return this->loginyUczestnikow;
}

// Metoda zwracaj¹ca nazwê zajêæ
string Zajecia::getNazwa()
{
	return this->nazwa;
}

// Metoda zwracaj¹ca opis zajêæ
string Zajecia::getOpis()
{
	return this->opis;
}

// Metoda zwracaj¹ca datê zajêæ
time_t Zajecia::getDataZajec()
{
	return this->dataZajec;
}

// Metoda zwracaj¹ca czas trwania zajêæ
int Zajecia::getCzasTrwania()
{
	return this->czasTrwania;
}

// Metoda zwracaj¹ca liczbê miejsc na zajêciach
int Zajecia::getLiczbaMiejsc()
{
	return this->liczbaMiejsc;
}

// Metoda wyœwietlaj¹ca informacje o zajêciach
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

// Funkcja wstawiaj¹ca nowe linie do tekstu, aby nie przekracza³ okreœlonej d³ugoœci linii
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

// Funkcja konwertuj¹ca time_t na formatowany napis daty i czasu
string konwertujTimeT(time_t czas) {
    tm czasStruktura;
    localtime_s(&czasStruktura, &czas);
    stringstream ss;
    ss << put_time(&czasStruktura, "%d-%m-%Y %H:%M");

    return ss.str();
}