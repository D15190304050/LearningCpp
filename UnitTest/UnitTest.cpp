#include "pch.h"
#include "CppUnitTest.h"
#include "../DataTools/LinkedList.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			using namespace DataTools::Collections;
			using namespace std;

			// Test for constructor.
			LinkedList<int> list;

			// Test for AddLast() and operator<<().
			for (int i = 0; i < 10; i++)
				list.AddLast(i);
			

			// Test for Count().
			Assert::AreEqual(10, list.Count());
		}
	};
}
