#pragma once
#include "stdafx.h"
#include "Quick.h"
#include "MinPriorityQueue.h"

namespace FundamentalAlgorithms
{
	namespace Sort
	{
		class SortTest
		{
		public:
			// Functionality test function for the quick sort algorithm.
			static void QuickSortFunctionalityTest();
			
			// Functionality test function for the MinPriorityQueue class.
			static void MinPQFunctionalityTest()
			{
				using namespace std;

				cout << "Test for strings:" << endl;
				int length = 6;
				string strings[] = { "123", "456", "789", "111", "222", "333" };
				MinPriorityQueue<string> pqString(strings, length);
				while (!pqString.IsEmpty())
					cout << pqString.DeleteMin() << endl;

				cout << "Test for int array:" << endl;
				int integers[] = { 3, 5, 4, 6, 2, 1 };
				MinPriorityQueue<int> pqInt;
				for (int i : integers)
					pqInt.Add(i);
				while (!pqInt.IsEmpty())
					cout << pqInt.DeleteMin() << " ";
				cout << endl;
			}
		};
	}
}