#pragma once
#include "stdafx.h"
#include "CollectionTests.h"
#include "LinkedList.h"

namespace DataWorks
{
	namespace Collections
	{
		void CollectionTests::PrintString(const std::string & s)
		{
			using namespace std;
			cout << s << " ";
		}

		void CollectionTests::LinkedListFunctionalityTest()
		{
			using namespace std;

			string strings[] = { "123", "456", "789", "111", "222", "333" };
			LinkedList<string> list;
			for (int i = 0; i < 6; i++)
				list.AddLast(strings[i]);
			//list.Traverse(PrintString);

			for (LinkedList<string>::iterator i = list.begin(); i != list.end(); i++)
				cout << *i << endl;

			cout << endl;
			//list.TraverseReversely(PrintString);
			cout << endl;
			cout << "The node count is: " << list.Count() << " now" << endl;

			cout << list.RemoveFirst() << " " << list.RemoveLast() << endl;
			cout << "The node count is: " << list.Count() << " now" << endl;
		}
	}
}