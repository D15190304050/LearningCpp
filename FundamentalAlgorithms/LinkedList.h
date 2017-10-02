#pragma once
#include <stdexcept>

namespace FundamentalAlgorithms
{
	namespace Collections
	{
		using namespace std;

		// The LinkedList class represents a doubly linked list.
		// T is a generic type.
		template<class T>
		class LinkedList
		{
		private:
			// The Node class represents a node with 2 links (previous and next) in linked list.
			class Node
			{
			public:
				// The data stored in this node.
				T data;

				// The next node of this node.
				Node * next;

				// The previous node of this node.
				Node * previous;

				// Initializes a new node that stroes the specified item.
				Node(T & t)
				{
					data = t;
					next = nullptr;
					previous = nullptr;
				}
			};

			// The first node of this linked list.
			Node * first;

			// The last node of this linked list.
			Node * last;

			// A counter that contains the number of nodes (items) in this linked list.
			int count;

		public:
			// Initialize an empty LinkedList.
			LinkedList()
			{
				first = nullptr;
				last = nullptr;
				count = 0;
			}

			// Releases memory of this linked list.
			~LinkedList()
			{
				// Get the first node of this linked list.
				Node * current = first;

				// Loop until reach the end of this linked list.
				while (current != nullptr)
				{
					// Get the current node and delete it later.
					Node * temp = current;

					// Move to the next node.
					current = current->next;

					// Delete the current node.
					delete temp;
					temp = nullptr;
				}
			}

			// Returns true if there is no items in this linked list, false otherwise.
			bool IsEmpty() const { return count == 0; }

			// Returns the number of nodes (items) in this linked list.
			int Count() const { return count; }

			// Adds a new node containing the specified data at the start of this linked list.
			// T is a generic type.
			// t : the item to add.
			void AddFirst(T & t)
			{
				// Initialize a new node with specified data.
				Node * toAdd = new Node(t);

				// If the linked list is empty, then the first and last point to the same node.
				// Else, change the node reference.
				if (count == 0)
				{
					first = toAdd;
					last = toAdd;
				}
				else
				{
					toAdd->next = first;
					first->previous = toAdd;
					first = toAdd;
				}

				// Update the node counter.
				count++;
			}

			// Adds a new node containing the specified data at the end of this linked list.
			// T is a generic type.
			// t : the item to add.
			void AddLast(T & t)
			{
				// Initialize a new node with specified data.
				Node * toAdd = new Node(t);

				// If the linked list is empty, then the first and last point to the same node.
				// Else, change the node reference.
				if (count == 0)
				{
					first = toAdd;
					last = toAdd;
				}
				else
				{
					last->next = toAdd;
					toAdd->previous = last;
					last = toAdd;
				}

				// Update the node counter.
				count++;
			}

			// Removes and returns the first element from this linked list..
			T RemoveFirst()
			{
				// Throw the runtime_error if this linked list is empty when being called.
				if (count == 0)
					throw runtime_error("There is no item in this linked list now.");

				// Get the node to remove.
				Node * toRemove = first;

				// Get the item to return.
				// Make a deep copy here because the delete operation will release the data stored in the node.
				T item = toRemove->data;

				// Change the node reference.
				first = first->next;
				first->previous = nullptr;

				// Remove the first node.
				delete toRemove;

				// Update the counter.
				count--;

				// Return the item.
				return item;
			}

			// Removes and returns the last element from this linked list.
			T RemoveLast()
			{
				// Throw the runtime_error if this linked list is empty when being called.
				if (count == 0)
					throw runtime_error("There is no item in this linked list now.");

				// Get the node to remove.
				Node * toRemove = last;

				// Get the item to return.
				// Make a deep copy here because the delete operation will release the data stored in the node.
				T item = toRemove->data;

				// Change the node reference.
				last = last->previous;
				last->next = nullptr;

				// Remove the last node.
				delete toRemove;

				// Update the counter.
				count--;

				// Return the item.
				return item;
			}

			// Traverses this linked list with specified function.
			void Traverse(void(*pfun)(const T &))
			{
				// Get the first node.
				Node * current = first;

				// Loop until reach the end of this linked list.
				while (current != nullptr)
				{
					// Call the function.
					pfun(current->data);

					// Move to the next node.
					current = current->next;
				}
			}

			// Traverses this linked list reversely with specified function.
			void TraverseReversely(void(*pfun)(const T &))
			{
				// Get the last node.
				Node * current = last;

				// Loop until reach the start of this linked list.
				while (current != nullptr)
				{
					// Call the function.
					pfun(current->data);

					// Move to the previous node.
					current = current->previous;
				}
			}
		};
	}
}