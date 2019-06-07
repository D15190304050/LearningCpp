#pragma once
#include "stdafx.h"
#include "SortTest.h"
#include "Insertion.h"
#include "Merge.h"

namespace DataWorks
{
	namespace Sort
	{
		void SortTest::QuickSortFunctionalityTest()
		{
			using namespace std;

			int length = 10;
			int testData[] = { 7, 8, 9, 6, 3, 5, 4, 0, 1, 2 };

			Quick quick;
			quick.Sort(testData, length);

			for (int i : testData)
				cout << i << " ";
			cout << endl;
		}

		void SortTest::MinPQFunctionalityTest()
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

		void SortTest::InsertionSortFunctionalityTest()
		{
			using namespace std;

			int length = 10;
			int testData[] = { 7, 8, 9, 6, 3, 5, 4, 0, 1, 2 };
			Insertion::Sort(testData, length);

			for (int i : testData)
				cout << i << " ";
			cout << endl;
		}

		void SortTest::MergeSortFunctionalityTest()
		{
			using namespace std;

			int length = 10;
			int testData[] = { 7, 8, 9, 6, 3, 5, 4, 0, 1, 2 };
			int * data = new int[length];
			for (int i = 0; i < length; i++)
				data[i] = testData[i];
			Merge::Sort(testData, length);

			for (int i : testData)
				cout << i << " ";
			cout << endl;

			delete[] data;
		}
	}
}