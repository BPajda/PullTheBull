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
			karnet1.ostatniaPlatnosc = time(0);

			Assert::IsTrue(karnet1.sprawdzWaznosc());

			karnet1.ostatniaPlatnosc = 3592000;
			Assert::IsFalse(karnet1.sprawdzWaznosc());


		}
		TEST_METHOD(oplacKarnet)
		{
			Karnet karnet2;
			karnet2.ostatniaPlatnosc = 100000;
			karnet2.oplacKarnet();

			Assert::AreEqual(time(0), karnet2.ostatniaPlatnosc);

		}
		TEST_METHOD(KarnetConstr)
		{
			Karnet karnet3;
			TypKarnetu typkarnetu1;
			time_t czas = time(0);
			karnet3 = Karnet(czas, typkarnetu1);
			
			Assert::AreEqual(karnet3.ostatniaPlatnosc, czas);
			Assert::AreEqual(karnet3.typkarnetu.nazwa, typkarnetu1.nazwa);
			Assert::AreEqual(karnet3.typkarnetu.cena, typkarnetu1.cena);
			Assert::AreEqual(karnet3.typkarnetu.open, typkarnetu1.open);
			Assert::AreEqual(karnet3.typkarnetu.zajecia, typkarnetu1.zajecia);

		}
		TEST_METHOD(getTypKarnetu)
		{
			Karnet karnet4;
			TypKarnetu typKarnetu4;
			karnet4.typkarnetu = typKarnetu4;

			Assert::AreEqual(karnet4.typkarnetu.nazwa, karnet4.getTypKarnetu().nazwa);
			Assert::AreEqual(karnet4.typkarnetu.cena, karnet4.getTypKarnetu().cena);
			Assert::AreEqual(karnet4.typkarnetu.open, karnet4.getTypKarnetu().open);
			Assert::AreEqual(karnet4.typkarnetu.zajecia, karnet4.getTypKarnetu().zajecia);
		}
		TEST_METHOD(getOstatniaPlatnosc)
		{
			Karnet karnet5;
			karnet5.ostatniaPlatnosc = time(0);

			Assert::AreEqual(karnet5.ostatniaPlatnosc, karnet5.getOstatniaPlatnosc());
		}

	};
	TEST_CLASS(KlientClass)
	{
		TEST_METHOD(wpiszDane)
		{
			Klient klient1;
			const char* imie = "adam";
			const char* nazwisko= "krawiec";
			const char* telefon= "";
			const char* email= "";


			klient1.wpiszDane("Jan", "Kowalski", "444444444", "j.kowal@gmail.com");
			Assert::AreEqual("Jan", imie);
			Assert::AreEqual("Kowalski", nazwisko);
			Assert::AreEqual("444444444", telefon);
			Assert::AreEqual("j.kowal@gmail.com", email);
		}
		TEST_METHOD(KlientConstr)
		{
			Klient klient2;
			const char* imie = "adam";
			const char* nazwisko = "krawiec";
			const char* telefon = "";
			const char* email = "";

			Assert::AreEqual("Jan", imie);
			Assert::AreEqual("Kowalski", nazwisko);
			Assert::AreEqual("444444444", telefon);
			Assert::AreEqual("j.kowal@gmail.com", email);
		}

	};
	TEST_CLASS(KontoUzytkownikaClass)
	{
		TEST_METHOD(wpiszDaneLog)
		{
			KontoUzytkownika konto1;
			const char* login = "jkowal";
			const char* haslo = "1234";

			konto1.wpiszDaneLogowania("akrawiec", "4321");
			Assert::AreEqual(login, "akrawiec");
			Assert::AreEqual(haslo, "4321");
		}
		TEST_METHOD(KontoUzytkownikaConstr)
		{
			KontoUzytkownika konto1;
			const char* login = "jkowal";
			const char* haslo = "1234";
			konto1 = KontoUzytkownika();


			Assert::AreEqual(login, "akrawiec");
			Assert::AreEqual(haslo, "4321");
		}
		TEST_METHOD(zarzadzajKontemAdmin)
		{
			KontoUzytkownika konto1;
			const char* login = "jkowal";
			const char* haslo = "1234";

			konto1.zarzadzajKontemAdmin("akrawiec", "4321");
			Assert::AreEqual(login, "akrawiec");
			Assert::AreEqual(haslo, "4321");
		}
		TEST_METHOD(rezerwacjaZajec)
		{
			Assert::AreEqual(0, "4321");
		}
		TEST_METHOD(usuniecieRezerwacji)
		{
			Assert::AreEqual(0, "4321");
		}
		TEST_METHOD(przegladajZajecia)
		{
			Assert::AreEqual(0, "4321");
		}
		TEST_METHOD(przegladajCennik)
		{
			Assert::AreEqual(0, "4321");
		}
		TEST_METHOD(wyswietlKarnet)
		{
			Assert::AreEqual(0, "4321");
		}

	};
	TEST_CLASS(TypKarnetuClass)
	{
	public:

		TEST_METHOD(TypKarnetuConstr)
		{
			TypKarnetu karnet1;
			karnet1.nazwa = "miesieczny";
			karnet1.cena = 100;
			karnet1.open = true;
			karnet1.zajecia = false;

			karnet1 = TypKarnetu("semsetralny", 120, false, true);
			Assert::AreEqual(120, karnet1.cena);
			Assert::AreEqual(false, karnet1.open);
			Assert::AreEqual(true, karnet1.zajecia);

		}
		TEST_METHOD(modyfikujDaneKarnetu)
		{
			TypKarnetu karnet1;
			karnet1.nazwa = "miesieczny";
			karnet1.cena = 100;
			karnet1.open = true;
			karnet1.zajecia = false;

			karnet1.modyfikujDaneKarnetu("semsetralny", 120, false, true);
			Assert::AreEqual(120, karnet1.cena);
			Assert::AreEqual(false, karnet1.open);
			Assert::AreEqual(true, karnet1.zajecia);

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
			Assert::AreEqual(weekendowy.nazwa, cennik1.typyKarnetow[cennik1.typyKarnetow.size() - 1].nazwa);
			Assert::AreEqual(weekendowy.cena, cennik1.typyKarnetow[cennik1.typyKarnetow.size() - 1].cena);
			Assert::AreEqual(weekendowy.open, cennik1.typyKarnetow[cennik1.typyKarnetow.size() - 1].open);
			Assert::AreEqual(weekendowy.zajecia, cennik1.typyKarnetow[cennik1.typyKarnetow.size() - 1].zajecia);

		}
		TEST_METHOD(usunKarnet)
		{
			Cennik cennik2;
			TypKarnetu weekendowy;
			weekendowy = TypKarnetu("weekendowy", 100, true, true);
			cennik2.dodajKarnet(weekendowy);
			unsigned long long  i = cennik2.typyKarnetow.size();
			cennik2.usunKarnet("weekendowy");
			Assert::AreEqual(i, cennik2.typyKarnetow.size() - 1);

		}
		TEST_METHOD(CennikConstr)
		{
			Cennik cennik3;
			TypKarnetu karnet1, karnet2;
			vector<TypKarnetu> lista = { karnet1, karnet2 };
			cennik3.typyKarnetow = lista;
			cennik3 = Cennik(lista);
			Assert::AreEqual(lista[0].nazwa, cennik3.typyKarnetow[0].nazwa);
			Assert::AreEqual(lista[0].cena, cennik3.typyKarnetow[0].cena);
			Assert::AreEqual(lista[0].open, cennik3.typyKarnetow[0].open);
			Assert::AreEqual(lista[0].zajecia, cennik3.typyKarnetow[0].zajecia);
			Assert::AreEqual(lista[1].nazwa, cennik3.typyKarnetow[1].nazwa);
			Assert::AreEqual(lista[1].cena, cennik3.typyKarnetow[1].cena);
			Assert::AreEqual(lista[1].open, cennik3.typyKarnetow[1].open);
			Assert::AreEqual(lista[1].zajecia, cennik3.typyKarnetow[1].zajecia);

		}

	};
	TEST_CLASS(HarmonogramClass)
	{
	public:

		TEST_METHOD(dodajZajecia)
		{
			HarmonogramZajec harmonogram1;
			Zajecia weekendowy;
			vector<string> uczestnicy = { "ania", "basia" };
			weekendowy = Zajecia("pilates", "trudne", time(0), 3600, 10, "Adam", uczestnicy);
			unsigned long long i = harmonogram1.listaZajec.size();
			harmonogram1.dodajZajecia("pilates", 15);
			Assert::AreEqual(i, harmonogram1.listaZajec.size()+1);

		}
		TEST_METHOD(usunZajecia)
		{
			HarmonogramZajec harmonogram2;
			Zajecia weekendowy;
			vector<string> uczestnicy = { "ania", "basia" };
			weekendowy = Zajecia("pilates", "trudne", time(0), 3600, 10, "Adam", uczestnicy);
			harmonogram2.dodajZajecia("pilates", 15);
			unsigned long long  i = harmonogram2.listaZajec.size();
			harmonogram2.usunZajecia("pilates", 15);
			Assert::AreEqual(i, harmonogram2.listaZajec.size() - 1);

		}
		
		TEST_METHOD(HarmonogramConstr)
		{
			HarmonogramZajec harmonogram3;
			Zajecia zajecia1, zajecia2;
			vector<Zajecia> lista = { zajecia1, zajecia2 };
			harmonogram3.listaZajec = lista;
			harmonogram3 = HarmonogramZajec(lista);
			Assert::AreEqual(lista[0].prowadzacy, harmonogram3.listaZajec[0].prowadzacy);
			Assert::AreEqual(lista[0].nazwa, harmonogram3.listaZajec[0].nazwa);
			Assert::AreEqual(lista[0].opis, harmonogram3.listaZajec[0].opis);
			Assert::AreEqual(lista[0].dataZajec, harmonogram3.listaZajec[0].dataZajec);
			Assert::AreEqual(lista[0].czasTrwania, harmonogram3.listaZajec[0].czasTrwania);
			Assert::AreEqual(lista[0].liczbaMiejsc, harmonogram3.listaZajec[0].liczbaMiejsc);
			Assert::AreEqual(lista[1].prowadzacy, harmonogram3.listaZajec[1].prowadzacy);
			Assert::AreEqual(lista[1].nazwa, harmonogram3.listaZajec[1].nazwa);
			Assert::AreEqual(lista[1].opis, harmonogram3.listaZajec[1].opis);
			Assert::AreEqual(lista[1].dataZajec, harmonogram3.listaZajec[1].dataZajec);
			Assert::AreEqual(lista[1].czasTrwania, harmonogram3.listaZajec[1].czasTrwania);
			Assert::AreEqual(lista[1].liczbaMiejsc, harmonogram3.listaZajec[1].liczbaMiejsc);

		}
		

	};
	TEST_CLASS(KontoPracownikaClass)
	{
	public:

		TEST_METHOD(wpiszDaneLog)
		{
			KontoPracownika konto1;
			const char* login = "jkowal";
			const char* haslo = "1234";

			konto1.wpiszDaneLogowania("akrawiec", "4321");
			Assert::AreEqual(login, "akrawiec");
			Assert::AreEqual(haslo, "4321");
		}
		TEST_METHOD(KontoUzytkownikaConstr)
		{
			KontoPracownika konto1;
			const char* login = "jkowal";
			const char* haslo = "1234";
			konto1 = KontoPracownika();


			Assert::AreEqual(login, "akrawiec");
			Assert::AreEqual(haslo, "4321");
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
			Assert::AreEqual(nazwa, zajecia1.nazwa);
			Assert::AreEqual(opis, zajecia1.opis);
			Assert::AreEqual(dataZajec, zajecia1.dataZajec);
			Assert::AreEqual(czasTrwania, zajecia1.czasTrwania);
			Assert::AreEqual(liczbaMiejsc, zajecia1.liczbaMiejsc);
			Assert::AreEqual(prowadzacy, zajecia1.prowadzacy);
			Assert::AreEqual(loginyUczestnikow[0], zajecia1.loginyUczestnikow[0]);
			Assert::AreEqual(loginyUczestnikow[1], zajecia1.loginyUczestnikow[1]);
		}
		TEST_METHOD(getProwadzacy)
		{
			Zajecia zajecia1;
			zajecia1.prowadzacy = "Adam";
			
			Assert::AreEqual(zajecia1.prowadzacy, zajecia1.getProwadzacy());
		}
		TEST_METHOD(getNazwa)
		{
			Zajecia zajecia1;
			zajecia1.nazwa = "pilates";

			Assert::AreEqual(zajecia1.nazwa, zajecia1.getNazwa());
		}
		TEST_METHOD(getOpis)
		{
			Zajecia zajecia1;
			zajecia1.opis = "trudne";

			Assert::AreEqual(zajecia1.opis, zajecia1.getOpis());
		}
		TEST_METHOD(getDataZajec)
		{
			Zajecia zajecia1;
			zajecia1.dataZajec = time(0);

			Assert::AreEqual(zajecia1.dataZajec, zajecia1.getDataZajec());
		}
		TEST_METHOD(getCzasTrwania)
		{
			Zajecia zajecia1;
			zajecia1.czasTrwania = 3600;

			Assert::AreEqual(zajecia1.czasTrwania, zajecia1.getCzasTrwania());
		}
		TEST_METHOD(getLicbzaMiejsc)
		{
			Zajecia zajecia1;
			zajecia1.liczbaMiejsc = 15;

			Assert::AreEqual(zajecia1.liczbaMiejsc, zajecia1.getLiczbaMiejsc());
		}
		TEST_METHOD(getLoginyUczestnikow)
		{
			Zajecia zajecia1;
			zajecia1.loginyUczestnikow = {"kasia", "asia"};

			Assert::AreEqual(zajecia1.loginyUczestnikow[0], zajecia1.getLoginyUczestnikow()[0]);
			Assert::AreEqual(zajecia1.loginyUczestnikow[1], zajecia1.getLoginyUczestnikow()[1]);

		}

	};
}
