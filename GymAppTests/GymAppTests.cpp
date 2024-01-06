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
			karnet3.typkarnetu = NULL;
			
			Assert::AreEqual(karnet3.ostatniaPlatnosc, czas);
			Assert::IsNotNull(karnet3.typkarnetu);

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
			Assert::AreEqual("Kowalski", telefon);
			Assert::AreEqual("Kowalski", email);
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
			Assert::AreEqual("Kowalski", telefon);
			Assert::AreEqual("Kowalski", email);
		}

	};
}
