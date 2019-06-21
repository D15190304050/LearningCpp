#include <iostream>
#include "common.h"
#include "LinkedList.h"
#include <stack>

int main()
{
	using namespace std;
	using namespace DataTools::Collections;

	typedef LinkedList<int>::iterator iterator;

	LinkedList<int> list;
	for (int i = 0; i < 10; i++)
		list.AddLast(i);

	for (iterator i = list.begin(); i != list.end(); i++)
		cout << *i << " ";
	cout << endl;

	cout << list.Count() << endl;
	
	for (int i = 10; i < 20; i++)
		list.AddFirst(i);
	for (iterator i = list.begin(); i != list.end(); i++)
		cout << *i << " ";
	cout << endl;

	LinkedListNode<int>* first = list.First();
	list.AddBefore(first, new LinkedListNode<int>(20));
	list.AddBefore(first, 21);
	list.AddAfter(first, new LinkedListNode<int>(22));
	list.AddAfter(first, 23);
	for (iterator i = list.begin(); i != list.end(); i++)
		cout << *i << " ";
	cout << endl;

	LinkedListNode<int>* last = list.Last();
	list.AddAfter(last, new LinkedListNode<int>(24));
	list.AddAfter(last, 25);
	list.AddBefore(last, new LinkedListNode<int>(26));
	list.AddBefore(last, 27);
	for (iterator i = list.begin(); i != list.end(); i++)
		cout << *i << " ";
	cout << endl;

	list.Clear();
	cout << list.Count() << endl;

	system("pause");
	return 0;
}