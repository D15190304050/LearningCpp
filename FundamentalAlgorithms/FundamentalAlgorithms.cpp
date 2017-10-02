// FundamentalAlgorithms.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LinkedList.h"
#include <string>

void PrintInt(const int & x)
{
	using namespace std;
	cout << x << " ";
}

void PrintString(const std::string & s)
{
	using namespace std;
	cout << s << " ";
}

int main()
{
	using namespace std;
	using namespace FundamentalAlgorithms::Collections;

	string strings[] = { "123", "456", "789", "111", "222", "333" };
	LinkedList<string> list;
	for (int i = 0; i < 6; i++)
		list.AddLast(strings[i]);
	list.Traverse(PrintString);
	cout << endl;
	list.TraverseReversely(PrintString);
	cout << endl;
	cout << "The node count is: " << list.Count() << " now" << endl;

	cout << list.RemoveFirst() << " " << list.RemoveLast() << endl;
	cout << "The node count is: " << list.Count() << " now" << endl;

	// Keep the console window open in debug mode.
	system("pause");
    return 0;
}