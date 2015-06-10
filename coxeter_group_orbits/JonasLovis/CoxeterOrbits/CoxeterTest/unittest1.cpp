#include "stdafx.h"
#include "CppUnitTest.h"
#include "../epsilonVector.h"
#include "../orbit.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoxeterTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestA6)
		{
			char letter = 'A';
			EpsilonVector vec(6);
			vec[0] = 1.3123;
			vec[1] = 3.313;
			vec[2] = 8.3;
			vec[3] = 2.342;
			vec[4] = 2.433;
			vec[5] = 0.11;
			GeneratorList list(simple_roots(letter, 6));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 5040;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge von (n+1)!");
		}

		TEST_METHOD(TestA10)
		{
			char letter = 'A';
			EpsilonVector vec(10);
			vec[0] = 1.3123;
			vec[1] = 3.313;
			vec[2] = 8.3;
			vec[3] = 2.342;
			vec[4] = 2.433;
			vec[5] = 0.11;
			vec[6] = 12.3;
			vec[7] = 22.42;
			vec[8] = 21.433;
			vec[9] = 10.11;
			GeneratorList list(simple_roots(letter, 10));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 5040;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge von n+1!");
		}

		TEST_METHOD(TestB2)
		{
			char letter = 'B';
			EpsilonVector vec(2);
			vec[0] = 3.3123;
			vec[1] = 1.142;
			GeneratorList list(simple_roots(letter, 2));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 8;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge");
		}

		TEST_METHOD(TestB3)
		{
			char letter = 'B';
			EpsilonVector vec(3);
			vec[0] = 27;
			vec[1] = 3.313;
			vec[2] = 0.023;
			GeneratorList list(simple_roots(letter, 3));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 48;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge");
		}

		TEST_METHOD(TestB6)
		{
			char letter = 'B';
			EpsilonVector vec(6);
			vec[0] = 1.3123;
			vec[1] = 3.313;
			vec[2] = 8.3;
			vec[3] = 2.342;
			vec[4] = 2.433;
			vec[5] = 0.11;
			GeneratorList list(simple_roots(letter, 6));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 46080;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge");
		}


		TEST_METHOD(TestC3)
		{
			char letter = 'C';
			EpsilonVector vec(3);
			vec[0] = 1.3123;
			vec[1] = 3.313;
			vec[2] = 8.3;
			GeneratorList list(simple_roots(letter, 3));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 48;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge");
		}


		TEST_METHOD(TestD4)
		{
			char letter = 'D';
			EpsilonVector vec(4);
			vec[0] = 1.3123;
			vec[1] = 3.313;
			vec[2] = 8.3;
			vec[3] = 2.342;
			GeneratorList list(simple_roots(letter, 4));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 192;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge");
		}



		TEST_METHOD(TestE7)
		{
			char letter = 'E';
			EpsilonVector vec(7);
			vec[0] = 3.3123;
			vec[1] = 1.142;
			vec[2] = 113;
			vec[3] = 11.3;
			vec[4] = 413;
			vec[5] = 1.222;
			vec[6] = 8;
			GeneratorList list(simple_roots(letter, 7));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 2903040;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge");
		}


		TEST_METHOD(TestF4)
		{
			char letter = 'F';
			EpsilonVector vec(4);
			vec[0] = 3.3123;
			vec[1] = 1.142;
			vec[2] = 113;
			vec[3] = 1.1;
			GeneratorList list(simple_roots(letter, 4));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 1152;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge");
		}


		TEST_METHOD(TestG)
		{
			char letter = 'G';
			EpsilonVector vec(3);
			vec[0] = 3.3123;
			vec[1] = 1.142;
			vec[2] = 113;
			GeneratorList list(simple_roots(letter, 2));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 12;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge");
		}

		TEST_METHOD(TestH3)
		{
			char letter = 'H';
			EpsilonVector vec(3);
			vec[0] = 3.3123;
			vec[1] = 1.142;
			vec[2] = 113;
			GeneratorList list(simple_roots(letter, 3));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 120;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge");
		}

		TEST_METHOD(TestI2)
		{
			char letter = 'I';
			EpsilonVector vec(2);
			vec[0] = 3.3123;
			vec[1] = 1.142;
			GeneratorList list(simple_roots(letter, 2));
			Orbit orb = orbit(list, vec);
			size_t orbSize = 4;
			Assert::AreEqual(orbSize, orb.size(), L"Entspricht nicht der erwarteten Orbitlaenge");
		}

	};
}