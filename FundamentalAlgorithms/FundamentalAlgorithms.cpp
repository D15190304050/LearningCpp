// FundamentalAlgorithms.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LinkedList.h"
#include "UnitTest.h"
#include "StdRandom.h"

int main()
{
	using namespace FundamentalAlgorithms;
	using namespace std;

	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	StdRandom random;
	random.Shuffle<int>(a, 10);

	for (int i : a)
		cout << i << " ";
	cout << endl;

	// Keep the console window open in debug mode.
	system("pause");
    return 0;
}