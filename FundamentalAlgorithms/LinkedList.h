#pragma once
#include <stdexcept>
#include <iterator>
#include <iostream>
#include "LinkedListNode.h"

namespace DataWorks
{
	namespace Collections
	{
		template<class T>
		class LinkedListIterator : public std::iterator<std::input_iterator_tag, T>
		{
		private:
			LinkedListNode<T>* current;

		public:
			// Constructor.
			LinkedListIterator(LinkedListNode<T>* node) : current(node) {}

			// Assignment.
			LinkedListIterator& operator = (const LinkedListIterator& iterator)
			{
				current = iterator.current;
				return *this;
			}

			// Unequal.
			bool operator != (const LinkedListIterator& iterator)
			{
				return current != iterator.current;
			}

			// Equal.
			bool operator == (const LinkedListIterator& iterator)
			{
				return current = iterator.current;
			}

			// Prefix-increment.
			LinkedListIterator& operator++()
			{
				current = current->next;
				return *this;
			}

			// Suffix-increment.
			LinkedListIterator operator++(int)
			{
				LinkedListIterator tmp = *this;
				current = current->next;
				return tmp;
			}

			// Get value.
			T& operator * ()
			{
				return current->data;
			}
		};

		// The LinkedList class represents a doubly linked list.
		// T is a generic type.
		template<class T>
		class LinkedList
		{
		private:
			// The Node class represents a node with 2 links (previous and next) in linked list.
			

			// The first node of this linked list.
			LinkedListNode<T>* first;

			// The last node of this linked list.
			LinkedListNode<T>* last;

			// A counter that contains the number of nodes (items) in this linked list.
			int count;

		public:
			typedef LinkedListIterator<T> iterator;

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
				LinkedListNode<T>* current = first;

				// Loop until reach the end of this linked list.
				while (current != nullptr)
				{
					// Get the current node and delete it later.
					LinkedListNode<T>* temp = current;

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
			void AddFirst(T& t)
			{
				// Initialize a new node with specified data.
				LinkedListNode<T>* toAdd = new LinkedListNode<T>(t);

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
			void AddLast(T& t)
			{
				// Initialize a new node with specified data.
				LinkedListNode<T>* toAdd = new LinkedListNode<T>(t);

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
					throw std::runtime_error("There is no item in this linked list now.");

				// Get the node to remove.
				LinkedListNode<T>* toRemove = first;

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
					throw std::runtime_error("There is no item in this linked list now.");

				// Get the node to remove.
				LinkedListNode<T>* toRemove = last;

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

			iterator begin()
			{
				return iterator(first);
			}

			iterator end()
			{
				return iterator(last);
			}
		};
	}
}