// AlgorithmDesigns.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "NumberOfInversions.h"

int main()
{
	using namespace std;
	using namespace AlgorithmDesigns;

	int data[] = { 2, 6, 3, 4, 5, 1 };
	cout << "The number of inversions of the input array is: " << NumberOfInversions::MergeBasedCount(data, 6) << endl;

	// Keep the console window open in debug mode.
	system("pause");
    return 0;
}