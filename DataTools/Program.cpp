#include <iostream>
#include "common.h"
#include "LinkedList.h"
#include <stack>

int main()
{
	using namespace std;
	using namespace DataTools::Collections;

	typedef LinkedList<int>::iterator iterator;

	// Test for constructor.
	LinkedList<int> list;

	// Test for AddLast() and operator<<().
	for (int i = 0; i < 10; i++)
		list.AddLast(i);
	cout << list << endl;
	cout << list.Count() << endl;
	
	// Test for AddFrist().
	for (int i = 10; i < 20; i++)
		list.AddFirst(i);
	cout << list << endl;

	// Test for AddBefore() and AddAfter().
	LinkedListNode<int>* first = list.First();
	list.AddBefore(first, new LinkedListNode<int>(20));
	list.AddBefore(first, 21);
	list.AddAfter(first, new LinkedListNode<int>(22));
	list.AddAfter(first, 23);
	cout << list << endl;

	// Test for AddBefore(), AddAfter() and First().
	LinkedListNode<int>* last = list.Last();
	list.AddAfter(last, new LinkedListNode<int>(24));
	list.AddAfter(last, 25);
	list.AddBefore(last, new LinkedListNode<int>(26));
	list.AddBefore(last, 27);
	cout << list << endl;

	// Test for RemoveFirst(), RemoveLast() and Last().
	list.RemoveFirst();
	list.RemoveLast();
	cout << list << endl;

	// Test for Remove().
	list.Remove(1);
	list.Remove(list.First());
	cout << list << endl;

	// Test for Clear().
	list.Clear();
	cout << list.Count() << endl;

	system("pause");
	return 0;
}