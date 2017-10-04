#pragma once
#include "stdafx.h"
#include "StdRandom.h"
#include "FunctionalityTest.h"

namespace FundamentalAlgorithms
{
	void FunctionalityTest::StdRandomFunctionalityTest()
	{
		using namespace FundamentalAlgorithms;
		using namespace std;

		cout << "Test for the shuffling operation:" << endl;
		int a[] = { 0,1,2,3,4,5,6,7,8,9 };
		cout << "Test for shuffling operation:" << endl;
		cout << "The original array is: ";
		for (int i : a)
			cout << i << " ";
		cout << endl;

		StdRandom random;
		random.Shuffle<int>(a, 10);

		cout << "The shuffled array is: ";
		for (int i : a)
			cout << i << " ";
		cout << endl;

		cout << "Generate 10 random double floating-number: " << endl;
		for (int i = 0; i < 10; i++)
			cout << random.NextDouble() << " ";
		cout << endl;
	}
}