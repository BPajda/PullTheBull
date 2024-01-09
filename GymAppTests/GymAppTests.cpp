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
			karnet3.ostatniaPlatnosc = time(0);
			time_t czas = 0;
			
			Assert::AreEqual(karnet3.ostatniaPlatnosc, czas);

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

		TEST_METHOD(dodajZajecia)
		{
			HarmonogramZajec harmonogram1;
			Zajecia weekendowy;
			vector<string> uczestnicy = { "ania", "basia" };
			weekendowy = Zajecia("pilates", "trudne", time(0), 3600, 10, "Adam", uczestnicy);
			unsigned long long i = harmonogram1.listaZajec.size();
			harmonogram1.dodajZajecia("pilates", 15);
			Assert::AreEqual(i, harmonogram1.listaZajec.size() + 1);

		}
	};
}
