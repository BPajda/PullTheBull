#include "Zajecia.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// Konstruktor inicjalizuj�cy obiekt Zajecia z podanymi danymi
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

// Konstruktor domy�lny
Zajecia::Zajecia()
{
}

// Destruktor
Zajecia::~Zajecia()
{
}

// Metoda zwracaj�ca prowadz�cego zaj�cia
string Zajecia::getProwadzacy()
{
	return this->prowadzacy;
}

// Metoda zwracaj�ca wektor login�w uczestnik�w zaj��
vector<string>& Zajecia::getLoginyUczestnikow()
{
	return this->loginyUczestnikow;
}

// Metoda zwracaj�ca nazw� zaj��
string Zajecia::getNazwa()
{
	return this->nazwa;
}

// Metoda zwracaj�ca opis zaj��
string Zajecia::getOpis()
{
	return this->opis;
}

// Metoda zwracaj�ca dat� zaj��
time_t Zajecia::getDataZajec()
{
	return this->dataZajec;
}

// Metoda zwracaj�ca czas trwania zaj��
int Zajecia::getCzasTrwania()
{
	return this->czasTrwania;
}

// Metoda zwracaj�ca liczb� miejsc na zaj�ciach
int Zajecia::getLiczbaMiejsc()
{
	return this->liczbaMiejsc;
}

// Metoda wy�wietlaj�ca informacje o zaj�ciach
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

// Funkcja wstawiaj�ca nowe linie do tekstu, aby nie przekracza� okre�lonej d�ugo�ci linii
string wstawNowaLinie(const string& tekst, size_t dlugoscLinii) {
    string wynik;
    istringstream strumien(tekst);
    string slowo;

    size_t aktualnaDlugosc = 0;

    while (strumien >> slowo) {
        if (aktualnaDlugosc + slowo.length() <= dlugoscLinii) {
            // Dodaj s�owo do bie��cej linii
            if (!wynik.empty()) {
                wynik += ' ';
                aktualnaDlugosc++;
            }
            wynik += slowo;
            aktualnaDlugosc += slowo.length();
        }
        else {
            // Rozpocznij now� lini� z bie��cym s�owem
            wynik += '\n' + slowo;
            aktualnaDlugosc = slowo.length();
        }
    }

    return wynik;
}

// Funkcja konwertuj�ca time_t na formatowany napis daty i czasu
string konwertujTimeT(time_t czas) {
    tm czasStruktura;
    localtime_s(&czasStruktura, &czas);
    stringstream ss;
    ss << put_time(&czasStruktura, "%d-%m-%Y %H:%M");

    return ss.str();
}