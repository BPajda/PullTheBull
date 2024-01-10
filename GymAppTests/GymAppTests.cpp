#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Karnet.cpp"
#include "../src/Klient.cpp"
#include "../src/Cennik.cpp"
#include "../src/HarmonogramZajec.cpp"
#include "../src/Konto.cpp"
#include "../src/KontoPracownika.cpp"
#include "../src/KontoUzytkownika.cpp"
#include "../src/Osoba.cpp"
#include "../src/Pracownik.cpp"
#include "../src/TypKarnetu.cpp"
#include "../src/Zajecia.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace GymAppTests
{
	TEST_CLASS(KarnetClass)
	{
	public:
		
		TEST_METHOD(sprawdzWaznosc)
		{
			Karnet karnet1;
			karnet1.setOstatniaPlatnosc(time(0));

			Assert::IsTrue(karnet1.sprawdzWaznosc());

			karnet1.setOstatniaPlatnosc(3592000);
			Assert::IsFalse(karnet1.sprawdzWaznosc());


		}
		TEST_METHOD(oplacKarnet)
		{
			Karnet karnet2;
			karnet2.setOstatniaPlatnosc(100000);
			karnet2.oplacKarnet();

			Assert::AreEqual(time(0), karnet2.getOstatniaPlatnosc());

		}
		TEST_METHOD(KarnetConstr)
		{
			Karnet karnet3;
			TypKarnetu typkarnetu1;
			time_t czas = time(0);
			karnet3 = Karnet(czas, typkarnetu1);
			
			Assert::AreEqual(karnet3.getOstatniaPlatnosc(), czas);
			Assert::AreEqual(karnet3.getTypKarnetu().getNazwa(), typkarnetu1.getNazwa());
			Assert::AreEqual(karnet3.getTypKarnetu().getCena(), typkarnetu1.getCena());
			Assert::AreEqual(karnet3.getTypKarnetu().getOpen(), typkarnetu1.getOpen());
			Assert::AreEqual(karnet3.getTypKarnetu().getZajecia(), typkarnetu1.getZajecia());

		}
		TEST_METHOD(getTypKarnetu)
		{
			Karnet karnet4;
			TypKarnetu typKarnetu4;
			karnet4.setTypKarnetu(typKarnetu4);

			Assert::AreEqual(typKarnetu4.getNazwa(), karnet4.getTypKarnetu().getNazwa());
			Assert::AreEqual(typKarnetu4.getCena(), karnet4.getTypKarnetu().getCena());
			Assert::AreEqual(typKarnetu4.getOpen(), karnet4.getTypKarnetu().getOpen());
			Assert::AreEqual(typKarnetu4.getZajecia(), karnet4.getTypKarnetu().getZajecia());
		}
		TEST_METHOD(getOstatniaPlatnosc)
		{
			Karnet karnet5;
			time_t czas = time(0);
			karnet5.setOstatniaPlatnosc(czas);

			Assert::AreEqual(czas, karnet5.getOstatniaPlatnosc());
		}

	};
	TEST_CLASS(KlientClass)
	{
		TEST_METHOD(KlientConstr)
		{
			Klient klient1;
			string imie = "Jan";
			string nazwisko= "Kowalski";
			string telefon= "444444444";
			string email= "j.kowal@gmail.com";


			klient1 = Klient(imie, nazwisko, telefon, email);
			Assert::AreEqual(klient1.getImie(), imie);
			Assert::AreEqual(klient1.getNazwisko(), nazwisko);
			Assert::AreEqual(klient1.getTelefon(), telefon);
			Assert::AreEqual(klient1.getEmail(), email);
		}
		TEST_METHOD(getIndeksyZajec)
		{
			Klient klient2;
			vector <int> indeksy = { 2, 5 };
			klient2.setIndeksyZajec(indeksy);

			Assert::AreEqual(indeksy[0], klient2.getIndeksyZajec()[0]);
			Assert::AreEqual(indeksy[1], klient2.getIndeksyZajec()[1]);
		}
		TEST_METHOD(getKarnet)
		{
			Klient klient2;
			Karnet karnet1;
			klient2.setKarnet(karnet1);

			Assert::AreEqual(karnet1.getTypKarnetu().getNazwa(), klient2.getKarnet().getTypKarnetu().getNazwa());
			Assert::AreEqual(karnet1.getOstatniaPlatnosc(), klient2.getKarnet().getOstatniaPlatnosc());
		}
		TEST_METHOD(getKontoUzytkownika)
		{
			Klient klient2;
			KontoUzytkownika konto1;
			klient2.setKontoUzytkownika(konto1);

			Assert::AreEqual(konto1.getLogin(), klient2.getKontoUzytkownika().getLogin());
			
		}
		TEST_METHOD(getImie)
		{
			Klient klient2;
			string imie = "adam";
			klient2.setImie(imie);

			Assert::AreEqual(imie, klient2.getImie());
		}
		TEST_METHOD(getNazwisko)
		{
			Klient klient2;
			string nazwisko = "kowal";
			klient2.setNazwisko(nazwisko);

			Assert::AreEqual(nazwisko, klient2.getNazwisko());
		}
		TEST_METHOD(getTelefon)
		{
			Klient klient2;
			string telefon = "444444444";
			klient2.setTelefon(telefon);

			Assert::AreEqual(telefon, klient2.getTelefon());
		}
		TEST_METHOD(getEmail)
		{
			Klient klient2;
			string email = "akowal@gmail.com";
			klient2.setEmail(email);

			Assert::AreEqual(email, klient2.getEmail());
		}
	};
	TEST_CLASS(KontoUzytkownikaClass)
	{
		TEST_METHOD(KontoUzytkownikaConstr)
		{
			KontoUzytkownika konto1;
			string login = "jkowal";
			string haslo = "1234";
			konto1 = KontoUzytkownika(login, haslo);


			Assert::AreEqual(login, konto1.getLogin());
			Assert::AreEqual(haslo, konto1.getHaslo());
		}
		TEST_METHOD(getLogin)
		{
			KontoUzytkownika konto1;
			string login = "jkowal";
			konto1.setLogin(login);

			Assert::AreEqual(login, konto1.getLogin());
		}
		TEST_METHOD(getHaslo)
		{
			KontoUzytkownika konto1;
			string haslo = "1234";
			konto1.setHaslo(haslo);

			Assert::AreEqual(haslo, konto1.getHaslo());
		}
	};
	TEST_CLASS(TypKarnetuClass)
	{
	public:

		TEST_METHOD(TypKarnetuConstr)
		{
			TypKarnetu karnet1;
			karnet1.setNazwa("miesieczny");
			karnet1.setCena(100);
			karnet1.setOpen(true);
			karnet1.setZajecia(false);

			karnet1 = TypKarnetu("semsetralny", 120, false, true);
			Assert::AreEqual(120, karnet1.getCena());
			Assert::AreEqual(false, karnet1.getOpen());
			Assert::AreEqual(true, karnet1.getZajecia());
		}
		TEST_METHOD(getNazwa)
		{
			TypKarnetu karnet1;
			string nazwa = "1234";
			karnet1.setNazwa(nazwa);

			Assert::AreEqual(nazwa, karnet1.getNazwa());
		}
		TEST_METHOD(getCena)
		{
			TypKarnetu karnet1;
			int cena = 100;
			karnet1.setCena(cena);

			Assert::AreEqual(cena, karnet1.getCena());
		}
		TEST_METHOD(GetOpen)
		{
			TypKarnetu karnet1;
			bool open = true;
			karnet1.setOpen(open);

			Assert::AreEqual(open, karnet1.getOpen());
		}
		TEST_METHOD(GetZajecia)
		{
			TypKarnetu karnet1;
			bool zajecia = true;
			karnet1.setZajecia(zajecia);

			Assert::AreEqual(zajecia, karnet1.getZajecia());
		}
		
	};
	TEST_CLASS(CennikClass)
	{
	public:

		TEST_METHOD(dodajKarnet)
		{
			Cennik cennik1;
			TypKarnetu weekendowy;
			weekendowy = TypKarnetu("weekendowy", 100, true, true);
			cennik1.dodajKarnet(weekendowy);
			Assert::AreEqual(weekendowy.getNazwa(), cennik1.getTypyKarnetow()[cennik1.getTypyKarnetow().size() - 1].getNazwa());
			Assert::AreEqual(weekendowy.getCena(), cennik1.getTypyKarnetow()[cennik1.getTypyKarnetow().size() - 1].getCena());
			Assert::AreEqual(weekendowy.getOpen(), cennik1.getTypyKarnetow()[cennik1.getTypyKarnetow().size() - 1].getOpen());
			Assert::AreEqual(weekendowy.getZajecia(), cennik1.getTypyKarnetow()[cennik1.getTypyKarnetow().size() - 1].getZajecia());

		}
		TEST_METHOD(usunKarnet)
		{
			Cennik cennik2;
			TypKarnetu weekendowy;
			weekendowy = TypKarnetu("weekendowy", 100, true, true);
			cennik2.dodajKarnet(weekendowy);
			unsigned long long  i = cennik2.getTypyKarnetow().size();
			cennik2.usunKarnet("weekendowy");
			Assert::AreNotEqual(i, cennik2.getTypyKarnetow().size());

		}
		TEST_METHOD(zmienKarnet)
		{
			//Pierwsza Opcja
			Cennik cennik2;
			TypKarnetu weekendowy, miesieczny;
			weekendowy = TypKarnetu("weekendowy", 100, true, true);
			miesieczny = TypKarnetu("miesieczny", 90, false, false);
			cennik2.dodajKarnet(weekendowy);
			cennik2.zmienKarnet("weekendowy", miesieczny);
			Assert::AreEqual(cennik2.getTypyKarnetow()[0].getNazwa(), miesieczny.getNazwa());
			Assert::AreEqual(cennik2.getTypyKarnetow()[0].getCena(), miesieczny.getCena());
			Assert::AreEqual(cennik2.getTypyKarnetow()[0].getOpen(), miesieczny.getOpen());
			Assert::AreEqual(cennik2.getTypyKarnetow()[0].getZajecia(), miesieczny.getZajecia());
			
			//Druga opcja
			Cennik cennik3;
			TypKarnetu weekendowy2, miesieczny2;
			weekendowy2 = TypKarnetu("weekendowy", 100, true, true);
			miesieczny2 = TypKarnetu("miesieczny", 90, false, false);
			cennik3.dodajKarnet(weekendowy2);
			cennik3.zmienKarnet("wieczorny", miesieczny2);
			Assert::AreNotEqual(cennik3.getTypyKarnetow()[0].getNazwa(), miesieczny2.getNazwa());
			Assert::AreNotEqual(cennik3.getTypyKarnetow()[0].getCena(), miesieczny2.getCena());
			Assert::AreNotEqual(cennik3.getTypyKarnetow()[0].getOpen(), miesieczny2.getOpen());
			Assert::AreNotEqual(cennik3.getTypyKarnetow()[0].getZajecia(), miesieczny2.getZajecia());
		}
		TEST_METHOD(CennikConstr)
		{
			Cennik cennik3;
			TypKarnetu karnet1, karnet2;
			vector<TypKarnetu> lista = { karnet1, karnet2 };
			cennik3.setTypyKarnetow(lista);
			cennik3 = Cennik(lista);
			Assert::AreEqual(lista[0].getNazwa(), cennik3.getTypyKarnetow()[0].getNazwa());
			Assert::AreEqual(lista[0].getCena(), cennik3.getTypyKarnetow()[0].getCena());
			Assert::AreEqual(lista[0].getOpen(), cennik3.getTypyKarnetow()[0].getOpen());
			Assert::AreEqual(lista[0].getZajecia(), cennik3.getTypyKarnetow()[0].getZajecia());
			Assert::AreEqual(lista[1].getNazwa(), cennik3.getTypyKarnetow()[1].getNazwa());
			Assert::AreEqual(lista[1].getCena(), cennik3.getTypyKarnetow()[1].getCena());
			Assert::AreEqual(lista[1].getOpen(), cennik3.getTypyKarnetow()[1].getOpen());
			Assert::AreEqual(lista[1].getZajecia(), cennik3.getTypyKarnetow()[1].getZajecia());
		}
		TEST_METHOD(getTypyKarnetow)
		{
			Cennik cennik4;
			TypKarnetu karnet1, karnet2;
			vector<TypKarnetu> lista = { karnet1, karnet2 };
			cennik4.setTypyKarnetow(lista);
			
			Assert::AreEqual(lista[0].getNazwa(), cennik4.getTypyKarnetow()[0].getNazwa());
			Assert::AreEqual(lista[0].getCena(), cennik4.getTypyKarnetow()[0].getCena());
			Assert::AreEqual(lista[0].getOpen(), cennik4.getTypyKarnetow()[0].getOpen());
			Assert::AreEqual(lista[0].getZajecia(), cennik4.getTypyKarnetow()[0].getZajecia());
			Assert::AreEqual(lista[1].getNazwa(), cennik4.getTypyKarnetow()[1].getNazwa());
			Assert::AreEqual(lista[1].getCena(), cennik4.getTypyKarnetow()[1].getCena());
			Assert::AreEqual(lista[1].getOpen(), cennik4.getTypyKarnetow()[1].getOpen());
			Assert::AreEqual(lista[1].getZajecia(), cennik4.getTypyKarnetow()[1].getZajecia());

		}

	};
	TEST_CLASS(HarmonogramClass)
	{
	public:

		TEST_METHOD(dodajZajecia)
		{
			HarmonogramZajec harmonogram1;
			Zajecia zajecia1, zajecia2;
			vector<string> uczestnicy = { "ania", "basia" };
			zajecia1 = Zajecia("pilates", "trudne", time(0), 3600, 10, "Adam", uczestnicy);
			unsigned long long i = harmonogram1.getListaZajec().size();
			harmonogram1.dodajZajecia(zajecia2);
			Assert::AreEqual(i, harmonogram1.getListaZajec().size() - 1);

		}
		TEST_METHOD(usunZajecia)
		{
			HarmonogramZajec harmonogram2;
			Zajecia zajecia1;
			vector<string> uczestnicy = { "ania", "basia" };
			zajecia1 = Zajecia("pilates", "trudne", time(0), 3600, 10, "Adam", uczestnicy);
			harmonogram2.dodajZajecia(zajecia1);
			unsigned long long  i = harmonogram2.getListaZajec().size();
			harmonogram2.usunZajecia("pilates");
			Assert::AreEqual(i, harmonogram2.getListaZajec().size() + 1);

		}
		TEST_METHOD(zmienKarnet)
		{
			//Pierwsza Opcja
			HarmonogramZajec harmonogram2;
			Zajecia zajecia1, zajecia2;
			vector<string> uczestnicy = { "ania", "basia" };
			vector<string> uczestnicy2 = { "bartek", "kuba" };
			zajecia1 = Zajecia("pilates", "trudne", time(0), 3600, 10, "Adam", uczestnicy);
			zajecia2 = Zajecia("box", "latwe", time(0) - 100000, 2600, 12, "Kasia", uczestnicy2);
			harmonogram2.dodajZajecia(zajecia1);
			harmonogram2.zmienZajecia("pilates", zajecia2);
			Assert::AreEqual(harmonogram2.getListaZajec()[0].getNazwa(), zajecia2.getNazwa());
			Assert::AreEqual(harmonogram2.getListaZajec()[0].getOpis(), zajecia2.getOpis());
			Assert::AreEqual(harmonogram2.getListaZajec()[0].getDataZajec(), zajecia2.getDataZajec());
			Assert::AreEqual(harmonogram2.getListaZajec()[0].getCzasTrwania(), zajecia2.getCzasTrwania());
			Assert::AreEqual(harmonogram2.getListaZajec()[0].getLiczbaMiejsc(), zajecia2.getLiczbaMiejsc());		
			Assert::AreEqual(harmonogram2.getListaZajec()[0].getProwadzacy(), zajecia2.getProwadzacy());
			Assert::AreEqual(harmonogram2.getListaZajec()[0].getLoginyUczestnikow()[0], zajecia2.getLoginyUczestnikow()[0]);
			Assert::AreEqual(harmonogram2.getListaZajec()[0].getLoginyUczestnikow()[1], zajecia2.getLoginyUczestnikow()[1]);




			//Druga opcja
			HarmonogramZajec harmonogram3;
			Zajecia zajecia3, zajecia4;
			vector<string> uczestnicy3 = { "ania", "basia" };
			vector<string> uczestnicy4 = { "bartek", "kuba" };
			zajecia3 = Zajecia("pilates", "trudne", time(0), 3600, 10, "Adam", uczestnicy3);
			zajecia4 = Zajecia("box", "latwe", time(0) - 100000, 2600, 12, "Kasia", uczestnicy4);
			harmonogram3.dodajZajecia(zajecia3);
			harmonogram3.zmienZajecia("mma", zajecia4);
			Assert::AreNotEqual(harmonogram3.getListaZajec()[0].getNazwa(), zajecia4.getNazwa());
			Assert::AreNotEqual(harmonogram3.getListaZajec()[0].getOpis(), zajecia4.getOpis());
			Assert::AreNotEqual(harmonogram3.getListaZajec()[0].getDataZajec(), zajecia4.getDataZajec());
			Assert::AreNotEqual(harmonogram3.getListaZajec()[0].getCzasTrwania(), zajecia4.getCzasTrwania());
			Assert::AreNotEqual(harmonogram3.getListaZajec()[0].getLiczbaMiejsc(), zajecia4.getLiczbaMiejsc());
			Assert::AreNotEqual(harmonogram3.getListaZajec()[0].getProwadzacy(), zajecia4.getProwadzacy());
			Assert::AreNotEqual(harmonogram3.getListaZajec()[0].getLoginyUczestnikow()[0], zajecia4.getLoginyUczestnikow()[0]);
			Assert::AreNotEqual(harmonogram3.getListaZajec()[0].getLoginyUczestnikow()[1], zajecia4.getLoginyUczestnikow()[1]);
		}
		TEST_METHOD(getListaZajec) 
		{
			HarmonogramZajec harmonogram5;
			Zajecia zajecia3, zajecia4;
			vector<string> uczestnicy3 = { "ania", "basia" };
			vector<string> uczestnicy4 = { "bartek", "kuba" };
			zajecia3 = Zajecia("pilates", "trudne", time(0), 3600, 10, "Adam", uczestnicy3);
			zajecia4 = Zajecia("box", "latwe", time(0) - 100000, 2600, 12, "Kasia", uczestnicy4);
			vector<Zajecia> lista = { zajecia3, zajecia4 };
			harmonogram5.setListaZajec(lista);

			Assert::AreEqual(lista[0].getNazwa(), harmonogram5.getListaZajec()[0].getNazwa());
			Assert::AreEqual(lista[0].getOpis(), harmonogram5.getListaZajec()[0].getOpis());
			Assert::AreEqual(lista[0].getDataZajec(), harmonogram5.getListaZajec()[0].getDataZajec());
			Assert::AreEqual(lista[0].getCzasTrwania(), harmonogram5.getListaZajec()[0].getCzasTrwania());
			Assert::AreEqual(lista[0].getLiczbaMiejsc(), harmonogram5.getListaZajec()[0].getLiczbaMiejsc());
			Assert::AreEqual(lista[0].getProwadzacy(), harmonogram5.getListaZajec()[0].getProwadzacy());
			Assert::AreEqual(lista[0].getLoginyUczestnikow()[0], harmonogram5.getListaZajec()[0].getLoginyUczestnikow()[0]);
			Assert::AreEqual(lista[0].getLoginyUczestnikow()[1], harmonogram5.getListaZajec()[0].getLoginyUczestnikow()[1]);
			Assert::AreEqual(lista[1].getNazwa(), harmonogram5.getListaZajec()[1].getNazwa());
			Assert::AreEqual(lista[1].getOpis(), harmonogram5.getListaZajec()[1].getOpis());
			Assert::AreEqual(lista[1].getDataZajec(), harmonogram5.getListaZajec()[1].getDataZajec());
			Assert::AreEqual(lista[1].getCzasTrwania(), harmonogram5.getListaZajec()[1].getCzasTrwania());
			Assert::AreEqual(lista[1].getLiczbaMiejsc(), harmonogram5.getListaZajec()[1].getLiczbaMiejsc());
			Assert::AreEqual(lista[1].getProwadzacy(), harmonogram5.getListaZajec()[1].getProwadzacy());
			Assert::AreEqual(lista[1].getLoginyUczestnikow()[0], harmonogram5.getListaZajec()[1].getLoginyUczestnikow()[0]);
			Assert::AreEqual(lista[1].getLoginyUczestnikow()[1], harmonogram5.getListaZajec()[1].getLoginyUczestnikow()[1]);
		}
		
		TEST_METHOD(HarmonogramConstr)
		{
			HarmonogramZajec harmonogram3;
			Zajecia zajecia1, zajecia2;
			vector<Zajecia> lista = { zajecia1, zajecia2 };
			harmonogram3.setListaZajec(lista);
			harmonogram3 = HarmonogramZajec(lista);
			Assert::AreEqual(lista[0].getProwadzacy(), harmonogram3.getListaZajec()[0].getProwadzacy());
			Assert::AreEqual(lista[0].getNazwa(), harmonogram3.getListaZajec()[0].getNazwa());
			Assert::AreEqual(lista[0].getOpis(), harmonogram3.getListaZajec()[0].getOpis());
			Assert::AreEqual(lista[0].getDataZajec(), harmonogram3.getListaZajec()[0].getDataZajec());
			Assert::AreEqual(lista[0].getCzasTrwania(), harmonogram3.getListaZajec()[0].getCzasTrwania());
			Assert::AreEqual(lista[0].getLiczbaMiejsc(), harmonogram3.getListaZajec()[0].getLiczbaMiejsc());
			Assert::AreEqual(lista[1].getProwadzacy(), harmonogram3.getListaZajec()[1].getProwadzacy());
			Assert::AreEqual(lista[1].getNazwa(), harmonogram3.getListaZajec()[1].getNazwa());
			Assert::AreEqual(lista[1].getOpis(), harmonogram3.getListaZajec()[1].getOpis());
			Assert::AreEqual(lista[1].getDataZajec(), harmonogram3.getListaZajec()[1].getDataZajec());
			Assert::AreEqual(lista[1].getCzasTrwania(), harmonogram3.getListaZajec()[1].getCzasTrwania());
			Assert::AreEqual(lista[1].getLiczbaMiejsc(), harmonogram3.getListaZajec()[1].getLiczbaMiejsc());

		}
		

	};
	TEST_CLASS(KontoPracownikaClass)
	{
	public:

		TEST_METHOD(KontoUzytkownikaConstr)
		{
			KontoPracownika konto1;
			string login = "jkowal";
			string haslo = "1234";
			konto1 = KontoPracownika(login, haslo);

			Assert::AreEqual(konto1.getLogin(), login);
			Assert::AreEqual(konto1.getHaslo(), haslo);
		}
		TEST_METHOD(getLogin)
		{
			KontoPracownika konto1;
			string login = "jkowal";
			konto1.setLogin(login);

			Assert::AreEqual(konto1.getLogin(), login);
		}
		TEST_METHOD(getHaslo)
		{
			KontoPracownika konto1;
			string haslo = "1234";
			konto1.setHaslo(haslo);

			Assert::AreEqual(konto1.getHaslo(), haslo);
		}

	};
	TEST_CLASS(ZajeciaClass)
	{
	public:

		TEST_METHOD(ZajeciaConstr)
		{
			Zajecia zajecia1;
			string nazwa = "box";
			string opis = "latwe";
			time_t dataZajec = time(0);
			int czasTrwania = 1000;
			int liczbaMiejsc = 12;
			string prowadzacy = "Kasia";
			vector<string> loginyUczestnikow = {"kasia", "asia"};
			
			zajecia1 = Zajecia(nazwa, opis, dataZajec, czasTrwania, liczbaMiejsc, prowadzacy, loginyUczestnikow);
			Assert::AreEqual(nazwa, zajecia1.getNazwa());
			Assert::AreEqual(opis, zajecia1.getOpis());
			Assert::AreEqual(dataZajec, zajecia1.getDataZajec());
			Assert::AreEqual(czasTrwania, zajecia1.getCzasTrwania());
			Assert::AreEqual(liczbaMiejsc, zajecia1.getLiczbaMiejsc());
			Assert::AreEqual(prowadzacy, zajecia1.getProwadzacy());
			Assert::AreEqual(loginyUczestnikow[0], zajecia1.getLoginyUczestnikow()[0]);
			Assert::AreEqual(loginyUczestnikow[1], zajecia1.getLoginyUczestnikow()[1]);
		}
		TEST_METHOD(getProwadzacy)
		{
			Zajecia zajecia1;
			string prowadzacy = "Adam";
			zajecia1.setProwadzacy("Adam");
			
			Assert::AreEqual(prowadzacy, zajecia1.getProwadzacy());
		}
		TEST_METHOD(getLoginyUczestnikow)
		{
			Zajecia zajecia1;
			vector<string> loginyUczestnikow = { "kasia", "asia" };
			zajecia1.setLoginyUczestnikow(loginyUczestnikow);

			Assert::AreEqual(loginyUczestnikow[0], zajecia1.getLoginyUczestnikow()[0]);
			Assert::AreEqual(loginyUczestnikow[1], zajecia1.getLoginyUczestnikow()[1]);

		}
		TEST_METHOD(getNazwa)
		{
			Zajecia zajecia1;
			string nazwa = "pilates";
			zajecia1.setNazwa("pilates");

			Assert::AreEqual(nazwa, zajecia1.getNazwa());
		}
		TEST_METHOD(getOpis)
		{
			Zajecia zajecia1;
			string opis = "trudne";
			zajecia1.setOpis("trudne");

			Assert::AreEqual(opis, zajecia1.getOpis());
		}
		TEST_METHOD(getDataZajec)
		{
			Zajecia zajecia1;
			time_t dataZajec = time(0);
			zajecia1.setDataZajec(time(0));

			Assert::AreEqual(dataZajec, zajecia1.getDataZajec());
		}
		TEST_METHOD(getCzasTrwania)
		{
			Zajecia zajecia1;
			int czasTrwania = 3600;
			zajecia1.setCzasTrwania(3600);

			Assert::AreEqual(czasTrwania, zajecia1.getCzasTrwania());
		}
		TEST_METHOD(getLicbzaMiejsc)
		{
			Zajecia zajecia1;
			int liczbaMiejsc = 15;
			zajecia1.setLiczbaMiejsc(15);

			Assert::AreEqual(liczbaMiejsc, zajecia1.getLiczbaMiejsc());
		}

	};
}
