#pragma once

#include <iterator>
#include <iostream>
#include <exception>
#include "InvalidOperationException.h"
#include "ArgumentNullException.h"
#include "ArgumentOutOfRangeException.h"
#include "ArgumentException.h"

namespace DataTools
{
	namespace Collections
	{
		// Declear the LinkedList<T> class here so that it can be accessed before being implemented in this file.
		// Dumb C++ compilation mechanism.
		template<class T>
		class LinkedList;

		template<class T>
		class LinkedListNode
		{
		public:
			LinkedList<T>* list;
			LinkedListNode* previous;
			LinkedListNode* next;
			T value;

			explicit LinkedListNode(const T& value) : list(nullptr), value(value), previous(nullptr), next(nullptr)
			{
			}

			explicit LinkedListNode(LinkedList<T>* list, const T& value) : list(list), value(value), previous(nullptr), next(nullptr)
			{
			}

			~LinkedListNode()
			{
				Invalidate();
			}

			void Invalidate()
			{
				next = nullptr;
				previous = nullptr;
			}

			// TODO: overload operator=() and Constructor().
		};

		template<class T>
		class LinkedList
		{
		private:
			template<class T>
			class LinkedListIterator : public std::iterator<std::input_iterator_tag, T>
			{
			private:
				LinkedList<T>* list;
				LinkedListNode<T>* current;
				int version;

				void ValidateVersion()
				{
					if (version != list->version)
						throw InvalidOperationException("Modified LinkedList during iteration.");
				}

			public:
				// Constructor.
				LinkedListIterator(LinkedListNode<T>* node) : current(node) {}

				// Assignment.
				LinkedListIterator& operator = (const LinkedListIterator& iterator)
				{
					current = iterator->current;
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
					return current == iterator->current;
				}

				// Prefix-increment.
				LinkedListIterator& operator++()
				{
					void ValidateVersion();
					current = current->next;
					return *this;
				}

				// Suffix-increment.
				LinkedListIterator operator++(int)
				{
					void ValidateVersion();
					LinkedListIterator tmp = *this;
					current = current->next;
					return tmp;
				}

				// Get value.
				T& operator * ()
				{
					return current->value;
				}
			};

			LinkedListNode<T>* first;
			LinkedListNode<T>* last;
			int count;
			int version;

			void ValidateNode(const LinkedListNode<T>* node) const 
			{
				if (node == nullptr)
					throw ArgumentNullException("Argument \"node\" cannot be nullptr.");

				if (node->list != this)
					throw ArgumentException("The given node belongs to another LinkedList.");
			}

			void ValidateNewNode(const LinkedListNode<T>* node) const 
			{
				if (node == nullptr)
					throw ArgumentNullException("Argument \"node\" cannot be nullptr.");

				if (node->list != nullptr)
					throw ArgumentException("The given node is attached to another LinkedList.");
			}

			void InternalInsertNodeBefore(LinkedListNode<T>* node, LinkedListNode<T>* newNode)
			{
				if (node->previous != nullptr)
				{
					node->previous->next = newNode;
					newNode->previous = node->previous;
					newNode->next = node;
					node->previous = newNode;
				}
				else
				{
					newNode->next = node;
					node->previous = newNode;

					first = newNode;
				}

				version++;
				count++;
			}

			void InternalInsertNodeAfter(LinkedListNode<T>* node, LinkedListNode<T>* newNode)
			{
				if (node->next != nullptr)
				{
					node->next->previous = newNode;
					newNode->next = node->next;
					newNode->previous = node;
					node->next = newNode;
				}
				else
				{
					node->next = newNode;
					newNode->previous = node;

					last = newNode;
				}
				
				version++;
				count++;
			}

			void InternalInsertNodeToEmptyList(LinkedListNode<T>* newNode)
			{
				if ((first != nullptr) || (count != 0))
					throw InvalidOperationException("LinkedList must be empty when this method is called!");

				first = newNode;
				last = newNode;
				version++;
				count++;
			}

			void InternalRemoveNode(LinkedListNode<T>* node)
			{
				if (first == nullptr)
					throw InvalidOperationException("This method shouldn't be called on empty list!");

				if (count == 0)
				{
					first = nullptr;
					last = nullptr;

					count--;
					version++;
				}
				else if (node == first)
					RemoveFirst();
				else if (node == last)
					RemoveLast();
				else
				{
					node->next->previous = node->previous;
					node->previous->next = node->next;
					delete node;

					count--;
					version++;
					TryEmptyList();
				}
			}

			void TryEmptyList()
			{
				if (count == 0)
				{
					first = nullptr;
					last = nullptr;
				}
			}

		public:
			typedef LinkedListIterator<T> iterator;
			iterator begin()const { return iterator(first); }
			iterator end()const { return iterator(nullptr); }

			explicit LinkedList() :first(nullptr), last(nullptr), count(0), version(0) {}
			virtual ~LinkedList()
			{
				if (count != 0)
				{
					LinkedListNode<T>* current = first;
					LinkedListNode<T>* toRemove = nullptr;

					while (current != nullptr)
					{
						toRemove = current;
						current = current->next;
						delete toRemove;
						toRemove = nullptr;
					}

					first = nullptr;
					last = nullptr;
				}
			}

			int Count()const { return count; }
			LinkedListNode<T>* First()const { return first; }
			LinkedListNode<T>* Last()const { return last; }

			LinkedListNode<T>* AddAfter(LinkedListNode<T>* node, const T& value)
			{
				ValidateNode(node);
				LinkedListNode<T>* result = new LinkedListNode<T>(this, value);
				InternalInsertNodeAfter(node, result);

				return result;
			}

			void AddAfter(LinkedListNode<T>* node, LinkedListNode<T>* newNode)
			{
				ValidateNode(node);
				ValidateNewNode(newNode);
				InternalInsertNodeAfter(node, newNode);
			}

			LinkedListNode<T>* AddBefore(LinkedListNode<T>* node, const T& value)
			{
				ValidateNode(node);
				LinkedListNode<T>* result = new LinkedListNode<T>(this, value);
				InternalInsertNodeBefore(node, result);

				return result;
			}

			void AddBefore(LinkedListNode<T>* node, LinkedListNode<T>* newNode)
			{
				ValidateNode(node);
				ValidateNewNode(newNode);
				InternalInsertNodeBefore(node, newNode);
			}

			LinkedListNode<T>* AddFirst(const T& value)
			{
				LinkedListNode<T>* result = new LinkedListNode<T>(this, value);
				if (first == nullptr)
					InternalInsertNodeToEmptyList(result);
				else
				{
					InternalInsertNodeBefore(first, result);
					first = result;
				}

				return result;
			}

			void AddFirst(LinkedListNode<T>* node)
			{
				ValidateNewNode(node);

				if (first == nullptr)
					InternalInsertNodeToEmptyList(node);
				else
				{
					InternalInsertNodeBefore(first, node);
					first = node;
				}
			}

			LinkedListNode<T>* AddLast(const T& value)
			{
				LinkedListNode<T>* result = new LinkedListNode<T>(this, value);
				if (first == nullptr)
					InternalInsertNodeToEmptyList(result);
				else
				{
					InternalInsertNodeAfter(last, result);
					last = result;
				}

				return result;
			}

			void AddLast(LinkedListNode<T>* node)
			{
				ValidateNode(node);

				if (first == nullptr)
					InternalInsertNodeToEmptyList(node);
				else
				{
					InternalInsertNodeAfter(last, node);
					last = node;
				}
			}

			void Clear()
			{
				LinkedListNode<T>* current = first;
				while (current != nullptr)
				{
					LinkedListNode<T>* temp = current;
					current = current->next;
					delete temp;
				}

				first = nullptr;
				last = nullptr;
				count = 0;
				version++;
			}

			// Note: This method use operator= to test if 2 values are equal.
			LinkedListNode<T>* Find(const T& value)
			{
				LinkedListNode<T>* current = first;
				if (current != nullptr)
				{
					do
					{
						if (current->value == value)
							return current;
						current = current->next;
					}
					while (current != nullptr);
				}

				return nullptr;
			}

			// Note: This method use operator= to test if 2 values are equal.
			LinkedListNode<T>* FindLast(const T& value)
			{
				if (first == nullptr)
					return nullptr;

				LinkedListNode<T>* current = last;

				if (current != nullptr)
				{
					if (value != nullptr)
					{
						do
						{
							if (current->value == value)
								return current;
							current = current->previous;
						}
						while (current != nullptr);
					}
					else
					{
						do
						{
							if (current->value == nullptr)
								return current;
							current = current->previous;
						}
						while (current != nullptr);
					}
				}
				return nullptr;
			}

			bool Contains(const T& value) const { return Find(value) != nullptr; }

			void CopyTo(T* destArray, int length, int startIndex) const
			{
				if (destArray == nullptr)
					throw ArgumentNullException("destArray");
				if ((startIndex < 0) || (startIndex >= length))
					throw ArgumentOutOfRangeException("startIndex");
				if (length - startIndex < count)
					throw ArgumentException("Insufficient space.");

				LinkedListNode<T>* current = first;
				if (current != nullptr)
				{
					do
					{
						destArray[startIndex++] = current->value;
						current = current->next;
					}
					while (current != nullptr);
				}
			}

			bool Remove(const T& value)
			{
				LinkedListNode<T>* target = Find(value);
				if (target != nullptr)
				{
					InternalRemoveNode(target);
					return true;
				}
				return false;
			}

			void Remove(LinkedListNode<T>* node)
			{
				ValidateNode(node);
				InternalRemoveNode(node);
			}

			void RemoveFirst()
			{
				if (first == nullptr)
					throw InvalidOperationException("Linked list is empty.");

				LinkedListNode<T>* originalFirst = first;
				first = first->next;
				first->previous = nullptr;
				delete originalFirst;

				count--;
				version++;
				TryEmptyList();
			}

			void RemoveLast()
			{
				if (first == nullptr)
					throw InvalidOperationException("Linked list is empty.");

				LinkedListNode<T>* originalLast = last;
				last = last->previous;
				last->next = nullptr;
				delete originalLast;

				count--;
				version++;
				TryEmptyList();
			}

			template<class T>
			friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
			{
				for (LinkedListIterator<T> i = list.begin(); i != list.end(); i++)
					os << *i << " ";

				return os;
			}
		};
	}
}