#pragma once
#include "stdafx.h"
#include "UnitTest.h"
#include "TopK.h"
#include "AccumlateNumbers.h"

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
		delete[] data;
	}

	void AlgorithmTests::TopKFunctionalityTest(TestOption option, int specifiedArray[], int length, int k)
	{
		using namespace std;
		using namespace FundamentalAlgorithms::Sort;

		// Initialize a TopK solver.
		TopK topk;

		// Generate the data for the test.
		int * sourceData = nullptr;
		if (option == TestOption::DefaultIntArray)
			sourceData = new int[10]{ 4, 5, 6, 9, 8, 7, 1, 2, 3, 0 };
		else
			sourceData = specifiedArray;

		// The array that contains the top-k elements extracted by specified method from the data.
		int * result;

		// The array that contains the deep copy of the sourceData.
		int * data = new int[length];

		// Test the PartitionBasedExtraction() function.
		// Make a deep copy of the source data because the sort operation will change the array.
		cout << "Test for the PartitionBasedExtraction() function." << endl;
		for (int i = 0; i < length; i++)
			data[i] = sourceData[i];
		result = topk.PartitionBasedExtraction(data, length, k);
		for (int i = 0; i < k; i++)
			cout << result[i] << " ";
		cout << endl;
		delete[] result;

		// Test the SortBasedExtraction() function.
		// Make a deep copy of the source data because the sort operation will change the array.
		cout << "Test for the SortBasedExtraction() function." << endl;
		for (int i = 0; i < length; i++)
			data[i] = sourceData[i];
		result = topk.SortBasedExtraction(data, length, k);
		for (int i = 0; i < k; i++)
			cout << result[i] << " ";
		cout << endl;
		delete[] result;

		// Test the MinPQBasedExtraction() function.
		cout << "Test for the MinPQBasedExtraction() function" << endl;
		result = topk.MinPQBasedExtraction(sourceData, length, k);
		for (int i = 0; i < k; i++)
			cout << result[i] << " ";
		cout << endl;
		delete[] result;

		// Test the MinPQBasedExtraction2() function.
		cout << "Test for the MinPQBasedExtraction2() function" << endl;
		result = topk.MinPQBasedExtraction2(sourceData, length, k);
		for (int i = 0; i < k; i++)
			cout << result[i] << " ";
		cout << endl;
		delete[] result;

		// Release memory.
		delete[] data;
	}

	void AlgorithmTests::TopKUnitTest()
	{
		// Test with default settings.
		TopKFunctionalityTest();

		// Test with specified data.
		StdRandom random;
		int length = 100;
		int k = 10;
		int * data = new int[length];
		for (int i = 0; i < length; i++)
			data[i] = i;
		random.Shuffle(data, length);
		TopKFunctionalityTest(TestOption::SpecifiedArray, data, length, k);
		delete[] data;
	}

	void AlgorithmTests::TopKStandardTest()
	{
		using namespace std;

		// Get the length of the input array.
		int length;
		cout << "Please enter the length of the input array: ";
		cin >> length;

		// Get the array.
		cout << "Please enter the array in a line separated by space." << endl;
		int * testData = new int[length];
		for (int i = 0; i < length; i++)
			cin >> testData[i];

		// Get the k.
		cout << "Please enter the k: ";
		int k;
		cin >> k;

		// Test the TopK algorithm.
		AlgorithmTests::TopKFunctionalityTest(TestOption::SpecifiedArray, testData, length, k);
	}

	void AlgorithmTests::AccumulateNumbersFunctionalityTest()
	{
		using namespace std;
		cout << "Query for cases that there are 4 and 25 pegs" << endl;
		AccumlateNumbers an(50);
		cout << an.MaxNumbers(4) << " " << an.MaxNumbers(25) << endl;
	}
}