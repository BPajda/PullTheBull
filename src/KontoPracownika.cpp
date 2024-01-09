#include <iostream>
#include "KontoPracownika.h"
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

bool isNumber(string liczba) {
	if (liczba.empty()) {
		return false; // Pusty ciπg nie jest liczbπ
	}

	// Sprawdü, czy kaødy znak w ciπgu to cyfra lub pierwszy znak to znak '-' lub '+'
	for (size_t i = 0; i < liczba.length(); ++i) {
		if (i == 0 && (liczba[i] == '-' || liczba[i] == '+')) {
			continue; // Pierwszy znak moøe byÊ '-' lub '+'
		}
		if (!isdigit(liczba[i])) {
			return false; // Znaleziono znak, ktÛry nie jest cyfrπ
		}
	}

	return true; // Ciπg jest liczbπ
}

template <typename T>
bool szukajWektor(vector<T> wektor, string nazwa) {
	for (T element : wektor) {
		if (element.getNazwa() == nazwa) {
			return true;
		}
	}
	return false;
}

void KontoPracownika::zarzadzajCennikiem(Cennik& cennik)
{
	char wybor;
	char wybrany;
	string nazwa;
	int cena;
	bool open, zajecia;
	do
	{
		system("cls");
		cennik.przegladajCennik();
		cout << " 1) Dodaj Karnet" << endl;
		cout << " 2) Usun Karnet" << endl;
		cout << " 3) Modyfikuj Karnet" << endl;
		cout << "ESC) Powrot" << endl;
		wybor = _getch();
	} while (wybor != 27 && wybor != '1' && wybor != '2' && wybor != '3');
	switch (wybor)
	{
	case '1':
		system("cls");
		cout << "Podaj nazwe nowego karnetu: ";
		cin >> nazwa;	
		while (szukajWektor(cennik.getTypyKarnetow(), nazwa))
		{
			cout << "Karnet o takiej nazwie juz istnieje. Podaj inna nazwe" << endl;
			cin >> nazwa;
		}
		system("cls");
		cout << "Podaj cene karnetu: ";
		while (!(cin >> cena) || cena < 0)
		{
			system("cls");
			cout << "Podaj prawidlowa cene: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		do
		{
			system("cls");
			cout << "Czy przysluguja przywileje OPEN?" << endl;
			cout << " T) TAK" << endl;
			cout << " N) NIE" << endl;
			wybor = _getch();
		} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
		if (wybor == 'T' || wybor == 't')
		{
			open = 1;
		}
		else
		{
			open = 0;
		}
		do
		{
			system("cls");
			cout << "Czy karnet umozliwia udzial w zajeciach?" << endl;
			cout << " T) TAK" << endl;
			cout << " N) NIE" << endl;
			wybor = _getch();
		} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
		if (wybor == 'T' || wybor == 't')
		{
			zajecia = 1;
		}
		else
		{
			zajecia = 0;
		}
		do
		{
			system("cls");
			cout << "Czy chcesz dodac karnet: " << endl;
			cout << "======================" << endl;
			cout << "Nazwa: " << nazwa << endl;
			cout << "Cena: " << cena << "zl" << endl;
			cout << "OPEN: " << (open ? "TAK" : "NIE") << endl;
			cout << "Zajecia: " << (zajecia ? "TAK" : "NIE") << endl;
			cout << "======================" << endl;
			cout << " T) TAK" << endl;
			cout << " N) NIE" << endl;
			wybor = _getch();
		} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
		if (wybor == 'T' || wybor == 't')
		{
			cennik.dodajKarnet(TypKarnetu(nazwa, cena, open, zajecia));
			fstream plikAktualizuj;
			plikAktualizuj.open("src/TypyKarnetow.txt", ios::out);
			for (int i = 1; i < cennik.getTypyKarnetow().size(); i++)
			{
				plikAktualizuj << cennik.getTypyKarnetow()[i].getNazwa() << "\t" << cennik.getTypyKarnetow()[i].getCena() << "\t" 
					<< cennik.getTypyKarnetow()[i].getOpen() << "\t" << cennik.getTypyKarnetow()[i].getZajecia() << endl;
			}
			plikAktualizuj.close();
		}
		break;
	case '2':
		do
		{
			system("cls");
			cennik.przegladajCennik();
			cout << "Ktory karnet chcesz usunac?" << endl;
			cout << "ESC) Powrot" << endl;
			wybrany = _getch();
		} while (wybrany != 27 && (wybrany < '0' || wybrany > cennik.getTypyKarnetow().size() + 48 - 1));
		if (wybrany == 27)
		{
			break;
		}
		else
		{
			do
			{
				system("cls");
				cout << "Czy na pewno chcesz usunac karnet " << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << "?" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			if (wybor == 'T' || wybor == 't')
			{
				cennik.usunKarnet(cennik.getTypyKarnetow()[wybrany - 48].getNazwa());
				fstream plikAktualizuj;
				plikAktualizuj.open("src/TypyKarnetow.txt", ios::out);
				for (int i = 1; i < cennik.getTypyKarnetow().size(); i++)
				{
					plikAktualizuj << cennik.getTypyKarnetow()[i].getNazwa() << "\t" << cennik.getTypyKarnetow()[i].getCena() << "\t"
						<< cennik.getTypyKarnetow()[i].getOpen() << "\t" << cennik.getTypyKarnetow()[i].getZajecia() << endl;
				}
				plikAktualizuj.close();
			}
		}
		break;
	case '3':
		do
		{
			system("cls");
			cennik.przegladajCennik();
			cout << "Ktory karnet chcesz modyfikowac?" << endl;
			cout << "ESC) Powrot" << endl;
			wybrany = _getch();
		} while (wybrany != 27 && (wybrany < '0' || wybrany > cennik.getTypyKarnetow().size() + 48 - 1));
		if (wybrany == 27)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "==========================" << endl;
			cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
			cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
			cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen() ? "TAK" : "NIE") << endl;
			cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
			cout << "==========================" << endl << endl;
			cout << "Podaj nowa nazwe karnetu: ";
			cin >> nazwa;
			while (szukajWektor(cennik.getTypyKarnetow(), nazwa))
			{
				cout << "Karnet o takiej nazwie juz istnieje. Podaj inna nazwe" << endl;
				cin >> nazwa;
			}
			system("cls");
			cout << "==========================" << endl;
			cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
			cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
			cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen() ? "TAK" : "NIE") << endl;
			cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
			cout << "==========================" << endl << endl;
			cout << "Podaj zmieniona cene karnetu: ";
			while (!(cin >> cena) || cena < 0)
			{
				system("cls");
				cout << "Podaj prawidlowa cene: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			do
			{
				system("cls");
				cout << "==========================" << endl;
				cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
				cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
				cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen() ? "TAK" : "NIE") << endl;
				cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
				cout << "==========================" << endl << endl;
				cout << "Czy maja przyslugugiwac przywileje OPEN?" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			if (wybor == 'T' || wybor == 't')
			{
				open = 1;
			}
			else
			{
				open = 0;
			}
			do
			{
				system("cls");
				cout << "==========================" << endl;
				cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
				cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
				cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen() ? "TAK" : "NIE") << endl;
				cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
				cout << "==========================" << endl << endl;
				cout << "Czy karnet ma umozliwiac udzial w zajeciach?" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			if (wybor == 'T' || wybor == 't')
			{
				zajecia = 1;
			}
			else
			{
				zajecia = 0;
			}
			do
			{
				system("cls");
				cout << "Czy na pewno chcesz zmienic karnet: " << endl;
				cout << "==========================" << endl;
				cout << cennik.getTypyKarnetow()[wybrany - 48].getNazwa() << endl;
				cout << "Cena: " << cennik.getTypyKarnetow()[wybrany - 48].getCena() << endl;
				cout << "OPEN: " << (cennik.getTypyKarnetow()[wybrany - 48].getOpen()?"TAK":"NIE") << endl;
				cout << "Zajecia: " << (cennik.getTypyKarnetow()[wybrany - 48].getZajecia() ? "TAK" : "NIE") << endl;
				cout << "==========================" << endl;
				cout << "Na karnet:" << endl;
				cout << "==========================" << endl;
				cout << nazwa << endl;
				cout << "Cena: " << cena << endl;
				cout << "OPEN: " << (open ? "TAK" : "NIE") << endl;
				cout << "Zajecia: " << (zajecia? "TAK" : "NIE") << endl;
				cout << "==========================" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			if (wybor == 'T' || wybor == 't')
			{
				cennik.zmienKarnet(cennik.getTypyKarnetow()[wybrany - 48].getNazwa(), TypKarnetu(nazwa, cena, open, zajecia));
				fstream plikAktualizuj;
				plikAktualizuj.open("src/TypyKarnetow.txt", ios::out);
				for (int i = 1; i < cennik.getTypyKarnetow().size(); i++)
				{
					plikAktualizuj << cennik.getTypyKarnetow()[i].getNazwa() << "\t" << cennik.getTypyKarnetow()[i].getCena() << "\t"
						<< cennik.getTypyKarnetow()[i].getOpen() << "\t" << cennik.getTypyKarnetow()[i].getZajecia() << endl;
				}
				plikAktualizuj.close();
			}
		}
		break;
	case 27:
		return;
		break;
	}
}

void KontoPracownika::zarzadzajKontami()
{
}

void KontoPracownika::zarzadzajHarmoZajec(HarmonogramZajec& harmonogram)
{
	{
		char wybor;
		char wybrany;
		string nazwa;
		string opis;
		time_t dataZajec;
		int czasTrwania;
		int liczbaMiejsc;
		string prowadzacy;
		string dataString;
		vector<string> loginy = {};
		
		do
		{
			system("cls");
			harmonogram.przegladajHarmonogram();
			cout << " 1) Dodaj Zajecia" << endl;
			cout << " 2) Usun Zajecia" << endl;
			cout << " 3) Modyfikuj Zajecia" << endl;
			cout << "ESC) Powrot" << endl;
			wybor = _getch();
		} while (wybor != 27 && wybor != '1' && wybor != '2' && wybor != '3');
		switch (wybor)
		{
		case '1':
			system("cls");
			cout << "Podaj nazwe nowych zajec: ";
			cin >> nazwa;
			while (szukajWektor(harmonogram.getListaZajec(), nazwa))
			{
				cout << "Zajecia o takiej nazwie juz istnieja. Podaj inna nazwe" << endl;
				cin >> nazwa;
			}
			system("cls");
			cout << "Podaj opis zajec: ";
			getline(cin, opis);
			opis = spacjeNaPodlogi(opis);
			system("cls");
			cout << "Podaj liczbe miejsc: ";
			while (!(cin >> liczbaMiejsc) || liczbaMiejsc < 0)
			{
				system("cls");
				cout << "Podaj prawidlowa liczbe miejsc: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			system("cls");
			cout << "Podaj czas trwania zajec [min]: ";
			while (!(cin >> czasTrwania) || czasTrwania < 0)
			{
				system("cls");
				cout << "Podaj prawidlowy czas trwania zajec: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			system("cls");
			cout << "Podaj godzine i date zajec w formacie (godziny minuty dzien miesiac rok)" << endl;
			
			getline(cin >> ws, dataString);
			dataZajec = parsujDate(dataString);

			system("cls");
			cout << "Podaj prowadzacego zajecia: " << endl;
			cin >> prowadzacy;
			do
			{
				system("cls");
				cout << "Czy chcesz dodac zajecia: " << endl;
				cout << "======================" << endl;
				cout << nazwa << endl;
				cout << "Opis: " << podlogiNaSpacje(opis) << endl;
				cout << "Liczba miejsc: " << liczbaMiejsc << endl;
				cout << "Czas trwania: " << czasTrwania << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(dataZajec) << endl;
				cout << "Prowadzacy: " << prowadzacy << endl;
				cout << "======================" << endl;
				cout << " T) TAK" << endl;
				cout << " N) NIE" << endl;
				wybor = _getch();
			} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
			if (wybor == 'T' || wybor == 't')
			{
				harmonogram.dodajZajecia(Zajecia(nazwa, spacjeNaPodlogi(opis), dataZajec, czasTrwania, liczbaMiejsc, prowadzacy, loginy));
				fstream plikAktualizuj;
				plikAktualizuj.open("src/ListaZajec.txt", ios::out);
				for (int i = 0; i < harmonogram.getListaZajec().size(); i++)
				{
					plikAktualizuj << harmonogram.getListaZajec()[i].getNazwa() << '\t' << spacjeNaPodlogi(harmonogram.getListaZajec()[i].getOpis()) << '\t' 
						<< harmonogram.getListaZajec()[i].getDataZajec() << '\t' << harmonogram.getListaZajec()[i].getCzasTrwania() << '\t' 
						<< harmonogram.getListaZajec()[i].getLiczbaMiejsc() << '\t' << harmonogram.getListaZajec()[i].getProwadzacy() << '\t';
					for (int j = 0; j < harmonogram.getListaZajec()[i].getLoginyUczestnikow().size(); j++)
					{
						plikAktualizuj << harmonogram.getListaZajec()[i].getLoginyUczestnikow()[j] << '\t';
					}
					plikAktualizuj << endl;
				}
				plikAktualizuj.close();
			}
			break;
		case '2':
			do
			{
				system("cls");
				harmonogram.przegladajHarmonogram();
				cout << "Ktore zajecia chcesz usunac?" << endl;
				cout << "ESC) Powrot" << endl;
				wybrany = _getch();
			} while (wybrany != 27 && (wybrany < '0' || wybrany > harmonogram.getListaZajec().size() + 48-1));
			if (wybrany == 27)
			{
				break;
			}
			else
			{
				do
				{
					system("cls");
					cout << "Czy na pewno chcesz usunac zajecia " << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << "?" << endl;
					cout << " T) TAK" << endl;
					cout << " N) NIE" << endl;
					wybor = _getch();
				} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
				if (wybor == 'T' || wybor == 't')
				{
					harmonogram.usunZajecia(harmonogram.getListaZajec()[wybrany - 48].getNazwa());
					fstream plikAktualizuj;
					plikAktualizuj.open("src/ListaZajec.txt", ios::out);
					for (int i = 0; i < harmonogram.getListaZajec().size(); i++)
					{
						plikAktualizuj << harmonogram.getListaZajec()[i].getNazwa() << '\t' << spacjeNaPodlogi(harmonogram.getListaZajec()[i].getOpis()) << '\t'
							<< harmonogram.getListaZajec()[i].getDataZajec() << '\t' << harmonogram.getListaZajec()[i].getCzasTrwania() << '\t'
							<< harmonogram.getListaZajec()[i].getLiczbaMiejsc() << '\t' << harmonogram.getListaZajec()[i].getProwadzacy() << '\t';
						for (int j = 0; j < harmonogram.getListaZajec()[i].getLoginyUczestnikow().size(); j++)
						{
							plikAktualizuj << harmonogram.getListaZajec()[i].getLoginyUczestnikow()[j] << '\t';
						}
						plikAktualizuj << endl;
					}
					plikAktualizuj.close();
				}
			}
			break;
		case '3':
			do
			{
				system("cls");
				harmonogram.przegladajHarmonogram();
				cout << "Ktore zajecia chcesz modyfikowac?" << endl;
				cout << "ESC) Powrot" << endl;
				wybrany = _getch();
			} while (wybrany != 27 && (wybrany <= '0' || wybrany > harmonogram.getListaZajec().size() + 48-1));
			if (wybrany == 27)
			{
				break;
			}
			else
			{
				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;
				cout << "Podaj nowa nazwe zajec: ";
				cin >> nazwa;
				
				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;
				cout << "Podaj zmieniony opis zajec: " << endl;

				getline(cin >> ws, opis);
				
				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;
				cout << "Podaj zmieniona godzine i date zajec w formacie (godziny minuty dzien miesiac rok)" << endl;

				getline(cin >> ws, dataString);
				dataZajec = parsujDate(dataString);

				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;
				cout << "Podaj zmieniony czas trwania zajec [min]: ";
				while (!(cin >> czasTrwania) || czasTrwania < 0)
				{
					system("cls");
					cout << "Podaj prawidlowy czas trwania zajec: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;
				cout << "Podaj zmieniona liczbe miejsc"<< endl;
				while (!(cin >> liczbaMiejsc) || liczbaMiejsc < 0)
				{
					system("cls");
					cout << "Podaj prawidlowa liczbe miejsc: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				system("cls");
				cout << "==========================" << endl;
				cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
				cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
				cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
				cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
				cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
				cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
				cout << "==========================" << endl << endl;
				cout << "Podaj zmienionego prowadzacego" << endl;
				cin >> prowadzacy;
				do
				{
					system("cls");
					cout << "Czy na pewno chcesz zmienic zajecia: " << endl;
					cout << "==========================" << endl;
					cout << harmonogram.getListaZajec()[wybrany - 48].getNazwa() << endl;
					cout << "Opis: " << podlogiNaSpacje(harmonogram.getListaZajec()[wybrany - 48].getOpis()) << endl;
					cout << "Liczba miejsc: " << harmonogram.getListaZajec()[wybrany - 48].getLiczbaMiejsc() << endl;
					cout << "Czas trwania: " << harmonogram.getListaZajec()[wybrany - 48].getCzasTrwania() << "min" << endl;
					cout << "Data zajec: " << konwertujTimeT(harmonogram.getListaZajec()[wybrany - 48].getDataZajec()) << endl;
					cout << "Prowadzacy: " << harmonogram.getListaZajec()[wybrany - 48].getProwadzacy() << endl;
					cout << "==========================" << endl << endl;
					cout << "Na karnet:" << endl;
					cout << "==========================" << endl;
					cout << nazwa << endl;
					cout << "Opis: " << podlogiNaSpacje(opis) << endl;
					cout << "Liczba miejsc: " << liczbaMiejsc << endl;
					cout << "Czas trwania: " << czasTrwania << "min" << endl;
					cout << "Data zajec: " << konwertujTimeT(dataZajec) << endl;
					cout << "Prowadzacy: " << prowadzacy << endl;
					cout << "==========================" << endl << endl;
					cout << " T) TAK" << endl;
					cout << " N) NIE" << endl;
					wybor = _getch();
				} while (wybor != 'T' && wybor != 't' && wybor != 'N' && wybor != 'n');
				if (wybor == 'T' || wybor == 't')
				{
					harmonogram.zmienZajecia(harmonogram.getListaZajec()[wybrany - 48].getNazwa(), Zajecia(nazwa, opis, dataZajec, czasTrwania, liczbaMiejsc, prowadzacy, harmonogram.getListaZajec()[wybrany - 48].getLoginyUczestnikow()));
					fstream plikAktualizuj;
					plikAktualizuj.open("src/ListaZajec.txt", ios::out);
					for (int i = 0; i < harmonogram.getListaZajec().size(); i++)
					{
						plikAktualizuj << harmonogram.getListaZajec()[i].getNazwa() << '\t' << spacjeNaPodlogi(harmonogram.getListaZajec()[i].getOpis()) << '\t'
							<< harmonogram.getListaZajec()[i].getDataZajec() << '\t' << harmonogram.getListaZajec()[i].getCzasTrwania() << '\t'
							<< harmonogram.getListaZajec()[i].getLiczbaMiejsc() << '\t' << harmonogram.getListaZajec()[i].getProwadzacy() << '\t';
						for (int j = 0; j < harmonogram.getListaZajec()[i].getLoginyUczestnikow().size(); j++)
						{
							plikAktualizuj << harmonogram.getListaZajec()[i].getLoginyUczestnikow()[j] << '\t';
						}
						plikAktualizuj << endl;
					}
					plikAktualizuj.close();
				}
			}
			break;
		case 27:
			return;
			break;
		}
	}
}

void KontoPracownika::wpiszDaneLogowania(string login, string haslo)
{
}

KontoPracownika::KontoPracownika(string login, string haslo)
{
	this->login = login;
	this->haslo = haslo;
}

KontoPracownika::KontoPracownika()
{
}

KontoPracownika::~KontoPracownika()
{
}

string KontoPracownika::getLogin()
{
	return this->login;
}

time_t parsujDate(string& dataStr) {
	tm strukturaCzasu = {}; // Inicjalizacja struktury tm

	istringstream strumien(dataStr);
	int godzina, minuta, dzien, miesiac, rok;

	// Parsowanie daty z formatu "hh mm dd mm yy"
	strumien >> godzina >> minuta >> dzien >> miesiac >> rok;

	// Sprawdzenie poprawnoúci parsowania
	if (strumien.fail()) {
		cerr << "B≥πd parsowania daty." << endl;
		return -1; // ZwrÛcenie b≥Ídu
	}

	// Ustawienie pÛl struktury tm
	strukturaCzasu.tm_hour = godzina;
	strukturaCzasu.tm_min = minuta;
	strukturaCzasu.tm_sec = 0;
	strukturaCzasu.tm_mday = dzien;
	strukturaCzasu.tm_mon = miesiac - 1; // tm_mon jest indeksowane od 0
	strukturaCzasu.tm_year = rok + 100; // tm_year liczone od 1900

	// Przekszta≥cenie struct tm na time_t
	time_t znacznikCzasu = mktime(&strukturaCzasu);

	// Sprawdzenie poprawnoúci przekszta≥cenia
	if (znacznikCzasu == -1) {
		cerr << "B≥πd przekszta≥cania daty na znacznik czasu." << endl;
		return -1; // ZwrÛcenie b≥Ídu
	}

	return znacznikCzasu; // ZwrÛcenie znacznika czasu
}