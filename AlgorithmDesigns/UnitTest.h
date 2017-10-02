#pragma once
#include "stdafx.h"
#include "NumberOfInversions.h"

namespace AlgorithmDesigns
{
	class AlgorithmTests
	{
	public:
		static void NoiFunctionalityTest(int testData[] = nullptr, int length = 0)
		{
			using namespace std;
			using namespace AlgorithmDesigns;

			int * data = nullptr;
			if (testData == nullptr)
			{
				length = 6;
				data = new int[length] { 2, 6, 3, 4, 5, 1 };
			}
			else
				data = testData;

			cout << "The number of inversions of the input array is: " << NumberOfInversions::MergeBasedCount(data, length) << endl;
		}

		static void NoiUnitTest()
		{
			// Test with default settings.
			NoiFunctionalityTest();

			// Test with specified data.
			int length = 10;
			int * data = new int[length];
			for (int i = 0; i < length; i++)
				data[i] = i;
			for (int i = 2; i < length; i++)
				;
		}
	};
}