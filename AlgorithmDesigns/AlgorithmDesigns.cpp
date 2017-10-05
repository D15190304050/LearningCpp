// AlgorithmDesigns.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "UnitTest.h"
#include "TopK.h"
#include <algorithm>

int main()
{
	using namespace std;
	using namespace AlgorithmDesigns;

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
	cout << "Please enter the k:";
	int k;
	cin >> k;

	// Test the TopK algorithm.
	AlgorithmTests::TopKFunctionalityTest(TestOption::SpecifiedArray, testData, length, k);

	// Keep the console window open in debug mode.
	system("pause");
    return 0;
}