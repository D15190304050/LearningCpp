#pragma once
#include "stdafx.h"
#include "SortTest.h"

namespace FundamentalAlgorithms
{
	namespace Sort
	{
		void SortTest::QuickSortFunctionalityTest()
		{
			using namespace std;

			StdRandom random;
			int length = 10;
			int testData[] = { 7, 8, 9, 6, 3, 5, 4, 0, 1, 2 };
			random.Shuffle(testData, length);

			Quick quick;
			quick.Sort(testData, length);

			for (int i : testData)
				cout << i << " ";
			cout << endl;
		}
	}
}