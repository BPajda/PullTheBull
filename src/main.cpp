#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Klient.h"
#include <vector>
#include <sstream>
#include "Cennik.cpp"
#include "HarmonogramZajec.h"
#include "Pracownik.h"

using namespace std;

bool szukajWektor(vector<int> wektor, int liczba)
{
	for (int i = 0; i < wektor.size(); i++)
	{
		if (wektor[i] == liczba)
		{
			return true;
		}
	}
	return false;
}

string podlogiNaSpacje(string tekst) {
	for (char& znak : tekst) {
		if (znak == '_') {
			znak = ' ';
		}
	}
	return tekst;
}

string spacjeNaPodlogi(string tekst) {
	for (char& znak : tekst) {
		if (znak == ' ') {
			znak = '_';
		}
	}
	return tekst;
}

int main() {

	fstream pliki;
	string nazwa;
	int cena;
	bool open;
	bool zajecia;

	vector<TypKarnetu> typyKarnetow;
	int indeksTypuKarnetu;
	typyKarnetow.push_back(TypKarnetu("BRAK", 0, 0, 0));
	pliki.open("src/TypyKarnetow.txt", ios::in);
	while (pliki >> nazwa >> cena >> open >> zajecia) {
		typyKarnetow.push_back(TypKarnetu(nazwa, cena, open, zajecia));
	}
	pliki.close();

	string opis;
	time_t dataZajec;
	int czasTrwania;
	int liczbaMiejsc;
	string loginProwadzacego;
	string uczestnicy;
	string loginUczestnika;

	vector<Zajecia> listaZajec;
	vector<string> loginyUczestnikow;

	pliki.open("src/ListaZajec.txt", ios::in);
	while (pliki >> nazwa >> opis >> dataZajec >> czasTrwania >> liczbaMiejsc >> loginProwadzacego)
	{
		uczestnicy = "";
		loginyUczestnikow.clear();
		getline(pliki, uczestnicy);
		istringstream strumien(uczestnicy);
		while(strumien >> loginUczestnika)
		{
			loginyUczestnikow.push_back(loginUczestnika);
		}
		listaZajec.push_back(Zajecia(nazwa, podlogiNaSpacje(opis), dataZajec, czasTrwania, liczbaMiejsc, loginProwadzacego, loginyUczestnikow));
	}
	pliki.close();

	Cennik cennik = Cennik(typyKarnetow); // tworzenie cennika
	HarmonogramZajec harmonogram = HarmonogramZajec(listaZajec); // tworzenie harmonogramu

	bool dziala = true;
	while (dziala) {
	menu:
		char wybor;

		system("cls");
		cout << "========= MENU =========" << endl;
		cout << " 1) Logowanie" << endl;
		cout << " 2) Rejestracja" << endl;
		cout << "ESC) Wyjscie" << endl;
		cout << "========================" << endl;
		wybor = _getch();

		fstream plik;
		string szukanyLogin = "";
		string login = "";
		string haslo = "";
		string daneLogin;
		string daneHaslo;
		bool zalogowano = false;
		int iloscProbLogowania = 0;
		string imie;
		string nazwisko;
		string telefon;
		string email;
		int typKarnetu;
		string wiersz;
		char uprawnienia;
		time_t dataOplacenia;
		Klient klient;
		vector<string> konta;
		string linia;
		fstream plikUsuwanie;
		char wybrany;
		fstream plikAktualizuj;

		switch (wybor) {
		case '1':
			plik.open("src/Konta.txt", ios::in);
			system("cls");
			while (!zalogowano) {
				cout << "login: ";
				cin >> login;
				cout << "haslo: ";

				//maskowanie hasla
				char znak;
				haslo = "";
				while ((znak = _getch()) != '\r') {
					if (znak == '\b') {
						if (!haslo.empty()) {
							haslo.pop_back();
							cout << "\b \b";
						}
					}
					else {
						haslo.push_back(znak);
						cout << '*';
					}
				}
				cout << endl;
				//
				while (plik >> daneLogin >> daneHaslo && !zalogowano) {
					if (login == daneLogin && haslo == daneHaslo) {
						zalogowano = true;
						plik >> imie;
						plik >> nazwisko;
						plik >> telefon;
						plik >> email;
						plik >> typKarnetu;
						plik >> uprawnienia;
						plik >> wiersz;
						long long pomocnicza = stoll(wiersz);
						dataOplacenia = static_cast<time_t>(pomocnicza);
					}
					getline(plik, wiersz);
				}

				plik.clear();														// powrót wskaŸnika kursora w pliku na jego pocz¹tek
				plik.seekg(0, ios_base::beg);

				if (!zalogowano) {
					cout << "Bledne dane logowania!" << endl << endl;
					iloscProbLogowania++;
					if (iloscProbLogowania > 2) {
						goto menu;
					}
				}
			}
			
			if (zalogowano && (uprawnienia == '0' || uprawnienia == 0)) {
				klient = Klient(imie, nazwisko, telefon, email);
				klient.setKarnet(Karnet(dataOplacenia, typyKarnetow[typKarnetu]));
				klient.setKontoUzytkownika(KontoUzytkownika(login, haslo));
				vector<int> indeksyZajec;
				for (int i = 0; i < listaZajec.size(); i++)
				{
					for (int j = 0; j < listaZajec[i].getLoginyUczestnikow().size(); j++)
					{
						if (login == listaZajec[i].getLoginyUczestnikow()[j])
						{
							indeksyZajec.push_back(i);
						}
					}
				}
				klient.setIndeksyZajec(indeksyZajec);
			}
			
			while (zalogowano) {
				zalogowany:
				system("cls");
				switch (uprawnienia) {
				case '0':
					cout << "==== Zalogowano jako " << login << " ====" << endl;
					cout << " 1) Wyswietl Karnet" << endl;
					cout << " 2) Weryfikacja Karnetu" << endl;
					cout << " 3) Przegladaj Cennik" << endl;
					cout << " 4) Moje Zajecia" << endl;
					cout << " 5) Przegladaj Zajecia" << endl;
					cout << " 6) Usun Konto" << endl;
					cout << "ESC) Wyloguj" << endl;
					wybor = _getch();
					switch (wybor) {
					case '1':
						do {
							system("cls");
							klient.getKarnet().wyswietlKarnet();
							cout << "ESC) Powrot" << endl;
						} while (_getch() != 27);
						break;
					case '2':
						do {
							system("cls");
							if (klient.getKarnet().sprawdzWaznosc()) {
								cout << " Karnet jest aktualny" << endl;
							}
							else {
								cout << " Karnet wygasl" << endl;
							}
							cout << "ESC) Powrot" << endl;
						} while (_getch() != 27);
						break;
					case '3':
						cennik:
						do 
						{
							system("cls");
							cennik.przegladajCennik();
							cout << " 1) Kup Karnet" << endl;
							cout << "ESC) Powrot" << endl;
							wybor = _getch();
						} while (wybor != 27 && wybor != '1');
						switch (wybor)
						{
						case '1':
							do
							{
								system("cls");
								cout << "Wybierz karnet z oferty" << endl;
								cennik.przegladajCennik();
								cout << "ESC) Powrot" << endl;										
								wybrany = _getch();
							} while (wybrany != 27 && (wybrany < '1' || wybrany > typyKarnetow.size()+48-1));		// typyKarnetow[0] przechowuje placeholder BRAK KARNETU
							if (wybrany == 27)
							{
								goto cennik;
							}
							else if (wybrany >= '1' && wybrany <= static_cast<char>(typyKarnetow.size()+48-1))
							{
								do
								{
									system("cls");
									cout << "Czy na pewno chcesz dokonac zakupu karnetu " << typyKarnetow[wybrany - 48].getNazwa() << "?" << endl;
									cout << "T) TAK" << endl;
									cout << "N) NIE" << endl;
									wybor = _getch();
								} while (wybor != 't' && wybor != 'T' && wybor != 'n' && wybor != 'N');
								if (wybor == 't' || wybor == 'T')
								{
									if (klient.getKarnet().getTypKarnetu().getNazwa() == typyKarnetow[wybrany - 48].getNazwa()) 
									{
										do
										{
											system("cls");
											cout << "Posiadasz juz ten karnet, czy chcesz przedluzyc jego okres waznosci?" << endl;
											cout << "T) TAK" << endl;
											cout << "N) NIE" << endl;
											wybor = _getch();
										} while (wybor != 't' && wybor != 'T' && wybor != 'n' && wybor != 'N');
										if (wybor == 't' || wybor == 'T')
										{
											klient.getKarnet().oplacKarnet();
										}
										else
										{
											goto cennik;
										}
									}
									else
									{
										klient.setKarnet(Karnet(time(0), typyKarnetow[wybrany - 48]));
									}
									// aktualizacja karnetow w pliku konta.txt
									plikAktualizuj.open("src/Konta.txt", ios::in);
									konta.clear();
									while (getline(plikAktualizuj, wiersz))
									{
										istringstream strumien(wiersz);
										strumien >> szukanyLogin;
										if (klient.getKontoUzytkownika().getLogin() != szukanyLogin)
										{
											konta.push_back(wiersz);
										}
										else
										{
											
											for (int i = 0; i < typyKarnetow.size(); i++)
											{
												if (klient.getKarnet().getTypKarnetu().getNazwa() == typyKarnetow[i].getNazwa())
												{
													indeksTypuKarnetu = i;
												}
											}
											wiersz = klient.getKontoUzytkownika().getLogin() + "\t" + haslo + "\t" + imie + "\t" + nazwisko + "\t"
												+ telefon + "\t" + email + "\t" + (char)(indeksTypuKarnetu + 48) + "\t" + uprawnienia + "\t"
												+ to_string(klient.getKarnet().getOstatniaPlatnosc());
											konta.push_back(wiersz);
										}
									}
									plikAktualizuj.close();
									plikAktualizuj.open("src/Konta.txt", ios::out);
									for (int i = 0; i < konta.size(); i++)
									{
										plikAktualizuj << konta[i] << endl;
									}
									plikAktualizuj.close();
									
								}
							}
							break;
						case 27:
							goto zalogowany;
						default:
							goto cennik;
						}
						break;
					case '4':
						zajecia:
						do {
							system("cls");
							klient.getKontoUzytkownika().przegladajZajecia(klient.getIndeksyZajec(), listaZajec);
							cout << " 1) Usun rezerwacje" << endl;
							cout << "ESC) Powrot" << endl;
							wybor = _getch();
						} while (wybor != 27 && wybor != '1');
						if (wybor == 27)
						{
							goto zalogowany;
						}
						else
						{
							do
							{
								system("cls");
								cout << "Wybierz zajecia, z ktorych chcesz zrezygnowac" << endl;
								klient.getKontoUzytkownika().przegladajZajecia(klient.getIndeksyZajec(), listaZajec);
								cout << "ESC) Powrot" << endl;
								wybrany = _getch();
							} while (wybrany != 27 && (!szukajWektor(klient.getIndeksyZajec(), wybrany -48)));
							if (wybrany == 27)
							{
								goto zajecia;
							}
							else
							{
								do
								{
									system("cls");
									cout << "Czy na pewno chcesz zrezygnowac z zajec " << listaZajec[wybrany -48].getNazwa() << "?" << endl;
									cout << "T) TAK" << endl;
									cout << "N) NIE" << endl;
									wybor = _getch();
								} while (wybor != 't' && wybor != 'T' && wybor != 'n' && wybor != 'N');
								if (wybor == 't' || wybor == 'T')
								{
									for (int l = 0; l < listaZajec[wybrany - 48].getLoginyUczestnikow().size(); l++)
									{
										if (listaZajec[wybrany - 48].getLoginyUczestnikow()[l] == login)
										{
											listaZajec[wybrany - 48].getLoginyUczestnikow().erase(listaZajec[wybrany - 48].getLoginyUczestnikow().begin() + l);
											harmonogram = HarmonogramZajec(listaZajec);
											for (int k = 0; k < klient.getIndeksyZajec().size(); k++)
											{
												if (klient.getIndeksyZajec()[k] == wybrany-48)
												{
													klient.getIndeksyZajec().erase(klient.getIndeksyZajec().begin() + k);
												}
											}
											plikAktualizuj.open("src/ListaZajec.txt", ios::out);
											for (int i = 0; i < listaZajec.size(); i++)
											{
												plikAktualizuj << listaZajec[i].getNazwa() << "\t" << spacjeNaPodlogi(listaZajec[i].getOpis()) << "\t" << listaZajec[i].getDataZajec() << "\t" <<
													listaZajec[i].getCzasTrwania() << "\t" << listaZajec[i].getLiczbaMiejsc() << "\t" << listaZajec[i].getProwadzacy() << "\t";
												for (int j = 0; j < listaZajec[i].getLoginyUczestnikow().size(); j++)
												{
													plikAktualizuj << listaZajec[i].getLoginyUczestnikow()[j] << "\t";
												}
												plikAktualizuj << endl;
											}
											plikAktualizuj.close();
										}
									}
								}
								else
								{
									goto zajecia;
								}
							}
						}
						break;
					case '5':
						harmonogram:
						do {
							system("cls");
							harmonogram.przegladajHarmonogram();
							cout << " 1) Zarezerwuj miejsce" << endl;
							cout << "ESC) Powrot" << endl;
							wybor = _getch();
						} while (wybor != 27 && wybor != '1');
						if (wybor == 27)
						{
							goto zalogowany;
						}
						else
						{
							do
							{
								system("cls");
								cout << "Na ktore zajecia chcesz zarezerwowac miejsce?" << endl;
								harmonogram.przegladajHarmonogram();
								cout << "ESC) Powrot" << endl;
								wybrany = _getch();
							} while (wybrany != 27 && (wybrany < '1' || wybrany > listaZajec.size()+48));
							if (wybrany == 27)
							{
								goto harmonogram;
							}
							else
							{
								for (int i = 0; i < listaZajec[wybrany - 48 - 1].getLoginyUczestnikow().size(); i++)
								{
									if (listaZajec[wybrany - 48 - 1].getLoginyUczestnikow()[i] == login)
									{
										do
										{
											system("cls");
											cout << "Jestes juz wpisany na te zajecia" << endl;
											cout << "ESC) Powrot" << endl;
										} while (_getch() != 27);
										goto harmonogram;
									}
								}
								if (listaZajec[wybrany - 48 - 1].getLiczbaMiejsc() - listaZajec[wybrany - 48 - 1].getLoginyUczestnikow().size() > 0)
								{
									listaZajec[wybrany - 48 - 1].getLoginyUczestnikow().push_back(login);
									harmonogram = HarmonogramZajec(listaZajec);
									plikAktualizuj.open("src/ListaZajec.txt", ios::out);
									for (int i = 0; i < listaZajec.size(); i++)
									{
										plikAktualizuj << listaZajec[i].getNazwa() << "\t" << spacjeNaPodlogi(listaZajec[i].getOpis()) << "\t" << listaZajec[i].getDataZajec() << "\t" <<
											listaZajec[i].getCzasTrwania() << "\t" << listaZajec[i].getLiczbaMiejsc() << "\t" << listaZajec[i].getProwadzacy() << "\t";
										for (int j = 0; j < listaZajec[i].getLoginyUczestnikow().size(); j++)
										{
											plikAktualizuj << listaZajec[i].getLoginyUczestnikow()[j] << "\t";
										}
										plikAktualizuj << endl;
									}
									plikAktualizuj.close();
									klient.getIndeksyZajec().push_back(wybrany - 48 - 1);
									do
									{
										system("cls");
										cout << "Pomyslnie zarezerwowano miejsce" << endl;
										cout << "ESC) Powrot" << endl;
									} while (_getch() != 27);
								}
								else
								{
									do
									{
										system("cls");
										cout << "Brak wolnych miejsc" << endl;
										cout << "ESC) Powrot" << endl;
									} while (_getch() != 27);
									goto harmonogram;
								}
							}
							
						}
						break;
					case '6':
						do 
						{
							system("cls");
							cout << "Po usunieciu konta nastapi wylogowanie" << endl;
							cout << "Czy na pewno chcesz trwale usunac konto?" << endl;
							cout << "T) TAK" << endl;
							cout << "N) NIE" << endl;
							wybor = _getch();
						} while (wybor != 't' && wybor != 'T' && wybor != 'n' && wybor != 'N');
						if(wybor == 't' || wybor == 'T') 
						{
							plikUsuwanie.open("src/Konta.txt", ios::in);
							konta.clear();
							while (getline(plikUsuwanie, wiersz))
							{
								istringstream strumien(wiersz);
								strumien >> szukanyLogin;
								if (klient.getKontoUzytkownika().getLogin() != szukanyLogin)
								{
									konta.push_back(wiersz);
								}
							}
							plikUsuwanie.close();
							plikUsuwanie.open("src/Konta.txt", ios::out);
							for (int i = 0; i < konta.size(); i++)
							{
								plikUsuwanie << konta[i] << endl;
							}
							plikUsuwanie.close();
							goto menu;
						}
						break;
					case 27:
						goto menu;
					default:
						break;
					}
					break;
				case '1':
					cout << "==== Zalogowano jako " << login << " ====" << endl;
					cout << " 1) Zarzadzanie Cennikiem" << endl;
					cout << " 2) Zarzadzanie Kontami" << endl;
					cout << " 3) Zarzadzanie Harmonogramem Zajec" << endl;
					cout << "ESC) Wyloguj" << endl;
					wybor = _getch();
					switch (wybor) {
					case '1':
						break;
					case '2':
						break;
					case '3':
						break;
					case 27:
						goto menu;
						break;
					default:
						break;
					}
				default:
					goto zalogowany;
					break;
				}
			}
			plik.close();
			break;
		case '2':
			cout << "======== Tworzenie konta ========" << endl;
			cout << "Podaj imie: ";
			cin >> imie;
			cout << "Podaj nazwisko: ";
			cin >> nazwisko;
			cout << "Podaj telefon: ";
			cin >> telefon;
			cout << "Podaj email: ";
			cin >> email;
		tworzenieLoginu:
			cout << "Utworz login: ";
			cin >> login;

			plik.open("src/Konta.txt", ios::in);
			while (plik >> daneLogin) {
				getline(plik, wiersz);
				if (login == daneLogin) {
					cout << "Podany login jest juz wykorzystany!" << endl;
					plik.close();
					goto tworzenieLoginu;
				}
			}
			plik.close();

			cout << "Utworz haslo: ";
			char znak;
			haslo = "";
			while ((znak = _getch()) != '\r') {
				if (znak == '\b') {
					if (!haslo.empty()) {
						haslo.pop_back();
						cout << "\b \b";
					}
				}
				else {
					haslo.push_back(znak);
					cout << '*';
				}
			}
			plik.open("src/Konta.txt", ios::out | ios_base::app);
			plik << login << "\t" << haslo << "\t" << imie << "\t" << nazwisko << "\t" << telefon << "\t" << email << "\t" << 0 << "\t" << 0 << "\t" << 0 << "\n";
			plik.close();

			break;
		case 27:
			dziala = false;
			break;
		default:
			goto menu;
		}
	}
	return 0;
}