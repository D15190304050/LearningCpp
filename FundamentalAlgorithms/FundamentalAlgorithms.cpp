// FundamentalAlgorithms.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LinkedList.h"
#include "CollectionTests.h"
#include "FunctionalityTest.h"
#include "Quick.h"

int main()
{
	using namespace std;
	using namespace FundamentalAlgorithms::Sort;
	
	int length = 10;
	int data[] = { 2, 5, 7, 9, 8, 6, 3, 4, 1, 0 };
	Quick quick;
	quick.Sort(data, length);
	for (int i : data)
		cout << i << " ";
	cout << endl;

	// Keep the console window open in debug mode.
	system("pause");
    return 0;
}