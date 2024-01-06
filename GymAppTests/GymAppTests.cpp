#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Karnet.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
}
