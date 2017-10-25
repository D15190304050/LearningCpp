// FundamentalAlgorithms.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LinkedList.h"
#include "CollectionTests.h"
#include "FunctionalityTest.h"
#include "Quick.h"
#include "SortTest.h"

int main()
{
	using namespace std;
	using namespace FundamentalAlgorithms::Sort;
	
	//SortTest::QuickSortFunctionalityTest();
	//SortTest::MinPQFunctionalityTest();
	//SortTest::InsertionSortFunctionalityTest();
	//SortTest::MergeSortFunctionalityTest();
	FundamentalAlgorithms::Collections::CollectionTests::LinkedListFunctionalityTest();

	// Keep the console window open in debug mode.
	system("pause");
    return 0;
}