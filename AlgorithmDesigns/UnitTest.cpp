#pragma once
#include "stdafx.h"
#include "UnitTest.h"
#include "TopK.h"

namespace AlgorithmDesigns
{
	void AlgorithmTests::NoiFunctionalityTest(int testData[], int length)
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

		cout << "The contents of the test array is: ";
		for (int i = 0; i < length; i++)
			cout << data[i] << " ";
		cout << endl;
		cout << "The number of inversions of the test array is: " << NumberOfInversions::MergeBasedCount(data, length) << endl;
	}

	void AlgorithmTests::NoiUnitTest()
	{
		using namespace FundamentalAlgorithms;

		// Test with default settings.
		NoiFunctionalityTest();

		// Test with specified data.
		StdRandom random;
		int length = 10;
		int * data = new int[length];
		for (int i = 0; i < length; i++)
			data[i] = i;
		random.Shuffle(data, length);
		NoiFunctionalityTest(data, length);
	}

	void AlgorithmTests::TopKFunctionalityTest(TestOption option, int specifiedArray[], int length, int k)
	{
		using namespace std;
		TopK topk;

		// Generate the data for the test.
		int * sourceData;
		if (option == TestOption::DefaultIntArray)
			sourceData = new int[10]{ 4, 5, 6, 9, 8, 7, 1, 2, 3, 0 };
		else
			sourceData = specifiedArray;

		// The array that contains the top-k elements extracted by specified method from the data.
		int * result;

		// The array that contains the deep copy of the sourceData.
		int * data = new int[length];

		// Test the PartitionBasedSelection() method.
		// Make a deep copy of the source data because the sort operation will change the array.
		cout << "Test for the SortBasedSelection() function." << endl;
		for (int i = 0; i < length; i++)
			data[i] = sourceData[i];
		result = topk.PartitionBasedSelection(data, length, k);
		for (int i = 0; i < k; i++)
			cout << result[i] << " ";
		cout << endl;
		delete[] result;

		// Release memory.
		delete[] data;
	}
}