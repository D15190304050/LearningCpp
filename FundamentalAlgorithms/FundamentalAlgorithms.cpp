// DataWorks.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LinkedList.h"
#include "CollectionTests.h"
#include "FunctionalityTest.h"
#include "Quick.h"
#include "SortTest.h"
#include "List.h"

int main()
{
	using namespace std;
	using namespace DataTools::Sort;
	
	//SortTest::QuickSortFunctionalityTest();
	//SortTest::MinPQFunctionalityTest();
	//SortTest::InsertionSortFunctionalityTest();
	//SortTest::MergeSortFunctionalityTest();
	DataWorks::Collections::CollectionTests::LinkedListFunctionalityTest();

	//List<int> list(100);
	//for (int i = 0; i < 20; i++)
	//	list.Add(i);

	//for (List<int>::iterator i = list.begin(); i != list.end(); i++)
	//	cout << *i << endl;

	// Keep the console window open in debug mode.
	system("pause");
    return 0;
}