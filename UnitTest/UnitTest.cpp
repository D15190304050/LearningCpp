#include "pch.h"
#include "CppUnitTest.h"
#include "../DataWorks/LinkedList.h"
#include "../DataWorks/Merge.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			using namespace DataWorks::Collections;
			using namespace std;

			LinkedList<int> list;
			for (int i = 0; i < 5; i++)
				list.AddLast(i);
			Assert::AreEqual(5, list.Count());
		}

		TEST_METHOD(TestMethod2)
		{
			using namespace DataWorks::Sort;
			using namespace std;

			int x[] = { 5,7,9,6,3,4,5,1 };
			Merge::Sort(x, 8);
			bool ascending = true;
			for (int i = 0; i < 7; i++)
			{
				if (x[i] > x[i + 1])
					ascending = false;
			}

			Assert::AreEqual(true, ascending);
		}
	};
}
