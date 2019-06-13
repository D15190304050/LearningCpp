#pragma once

#include <iterator>
#include <exception>
#include "InvalidOperationException.h"
#include "ArgumentNullException.h"

namespace DataWorks
{
	namespace Collections
	{
		template<class T>
		class LinkedListNode
		{
		private:
			LinkedList<T>* list;
			LinkedListNode<T>* previous;
			LinkedListNode<T>* next;
			T value;

		public:
			LinkedListNode(const T& value) : value(value)
			{
				list = nullptr;
				previous = nullptr;
				next = nullptr;
			}

			LinkedListNode(const LinkedList<T>* list, const T& value) : list(list), value(value) {}

			~LinkedListNode()
			{
				Invalidate();
			}

			public LinkedListNode<T> * Next() const { return next; }
			public LinkedListNode<T> * Previous() const { return previous; }
			public T& GetValue() const { return value; }
			public void SetValue(const T& value) { this->value = value; }
			public LinkedList<T>* GetList() { return list; }
			public void SetList(const LinkedList<T>* list)
			{
				if (list == nullptr)
					throw ArgumentNullException("The argument \"list\" cannot be null.");

				if (this->list == nullptr)
					this->list = list;
				else
					throw DataWorks::InvalidOperationException::InvalidOperationException("The LinkedList this LinkedListNode attached to can only be assigned once.");
			}
			public void Invalidate()
			{
				list = nullptr;
				next = nullptr;
				previous = nullptr;
			}

			public void SetPrevious(LinkedListNode<T>* previous)
			{
				this->previous = previous;
			}

			public void SetNext(LinkedListNode<T>* next)
			{
				this->next = next;
			}

			// TODO: overload operator=()
		};

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

		template<class T>
		class LinkedList
		{
		private:
			LinkedListNode<T>* head;
			int count;
			int version;

			void ValidateNode(const LinkedListNode<T>* node)
			{
				if (node == nullptr)
					throw ArgumentNullException("Argument \"node\" cannot be null.");

				if (node->GetList() != this)
					throw InvalidOperationException("The given \"node\" doesn't belong to the LinkedList.");
			}

			void ValidateNewNode(const LinkedListNode<T>* node)
			{
				if (node == nullptr)
					throw ArgumentNullException("Argument \"node\" cannot be null.");

				if (node->GetList() != nullptr)
					throw ArgumentNullException("The given \"node\" doesn't belong to the LinkedList.");
			}

			void InternalInsertNodeBefore(LinkedListNode<T>* node, LinkedListNode<T>* newNode)
			{
				newNode->SetNext(node);
				newNode->SetPrevious(node->Previous());
				node->Previous->SetNext(newNode);
				node->SetPrevious(newNode);
				version++;
				count++;
			}

			void InternalInsertNodeToEmptyList(LinkedListNode<T>* newNode)
			{
				if ((head != null) || (count != 0))
					throw InvalidOperationException("LinkedList must be empty when this method is called!");

				newNode->SetNext(newNode);
				newNode->SetPrevious(newNode);
				head = newNode;
				version++;
				count++;
			}

			void InternalRemoveNode(LinkedListNode<T>* node)
			{
				if (node->GetList() != this)
					throw InvalidOperationException("Deleting the node from another list!");
				if (head == null)
					throw InvalidOperationException("This method shouldn't be called on empty list!");

				if (node->Next() == node)
				{
					delete head;
					head = null;
				}
				else
				{
					node->Next()->SetPrevious(node->Previous());
					node->Previous()->SetNext(node->Next());
					if (head == node)
						head = head->Next();
				}

				node->Invalidate();
				count--;
				version++;
			}

		public:
			LinkedList() :head(nullptr) {}
			virtual ~LinkedList()
			{
				if (count == 0)
					delete head;
				else
				{
					LinkedListNode* last = head->previous;
					LinkedListNode* current = head;
					LinkedListNode* toRemove = nullptr;

					while (current != last)
					{
						toRemove = current;
						current = current->Next();
						delete toRemove;
						toRemove = nullptr;
					}

					delete last;
					delete head;
				}
			}

			int Count()const { return count; }
			LinkedListNode<T>* First()const { return head; }
			LinkedListNode<T>* Last()const { return head == nullptr ? head : head->previous; }

			void AddAfter(LinkedListNode<T>* node, const T& value);
			void AddAfter(LinkedListNode<T>* node, LinkedListNode<T>* newNode);

			void AddLast(const& value);
		};
	}
}