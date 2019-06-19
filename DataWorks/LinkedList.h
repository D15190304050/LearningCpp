#pragma once

#include <iterator>
#include <exception>
#include "InvalidOperationException.h"
#include "ArgumentNullException.h"
#include "ArgumentOutOfRangeException.h"
#include "ArgumentException.h"

namespace DataWorks
{
	namespace Collections
	{
		template<class T>
		class LinkedList
		{
		private:
			class LinkedListNode
			{
			private:
				LinkedList* list;
				LinkedListNode* previous;
				LinkedListNode* next;
				T value;

			public:
				explicit LinkedListNode(const T& value) : value(value)
				{
					list = nullptr;
					previous = nullptr;
					next = nullptr;
				}

				explicit LinkedListNode(const LinkedList* list, const T& value) : list(list), value(value) {}

				~LinkedListNode()
				{
					Invalidate();
				}

				LinkedListNode* Next() const { return next; }
				LinkedListNode* Previous() const { return previous; }
				T& GetValue() const { return value; }
				void SetValue(const T& value) { this->value = value; }
				LinkedList* GetList() { return list; }
				void SetList(const LinkedList* list)
				{
					if (list == nullptr)
						throw ArgumentNullException("The argument \"list\" cannot be nullptr.");

					if (this->list == nullptr)
						this->list = list;
					else
						throw DataWorks::InvalidOperationException::InvalidOperationException("The LinkedList this LinkedListNode attached to can only be assigned once.");
				}
				void Invalidate()
				{
					list = nullptr;
					next = nullptr;
					previous = nullptr;
				}

				void SetPrevious(LinkedListNode* previous)
				{
					this->previous = previous;
				}

				void SetNext(LinkedListNode* next)
				{
					this->next = next;
				}

				// TODO: overload operator=() and Constructor().
			};

			class LinkedListIterator : public std::iterator<std::input_iterator_tag, T>
			{
			private:
				LinkedListNode* current;
				LinkedListNode* head;
				bool moved;
			public:
				// Constructor.
				LinkedListIterator(LinkedListNode* node, LinkedListNode* head) : current(node), head(head), moved(false) {}

				// Assignment.
				LinkedListIterator& operator = (const LinkedListIterator& iterator)
				{
					current = iterator->current;
					return *this;
				}

				// Unequal.
				bool operator != (const LinkedListIterator& iterator)
				{
					return current != iterator->current;
				}

				// Equal.
				bool operator == (const LinkedListIterator& iterator)
				{
					return current == iterator->current;
				}

				// Prefix-increment.
				LinkedListIterator& operator++()
				{
					moved = true;
					current = current->next;
					return *this;
				}

				// Suffix-increment.
				LinkedListIterator operator++(int)
				{
					moved = true;
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

			LinkedListNode* head;
			int count;
			int version;

			void ValidateNode(const LinkedListNode* node)
			{
				if (node == nullptr)
					throw ArgumentNullException("Argument \"node\" cannot be nullptr.");

				if (node->GetList() != this)
					throw InvalidOperationException("The given \"node\" doesn't belong to the LinkedList.");
			}

			void ValidateNewNode(const LinkedListNode* node)
			{
				if (node == nullptr)
					throw ArgumentNullException("Argument \"node\" cannot be nullptr.");

				if (node->GetList() != nullptr)
					throw ArgumentNullException("The given \"node\" doesn't belong to the LinkedList.");
			}

			void InternalInsertNodeBefore(LinkedListNode* node, LinkedListNode* newNode)
			{
				newNode->SetNext(node);
				newNode->SetPrevious(node->Previous());
				node->Previous->SetNext(newNode);
				node->SetPrevious(newNode);
				version++;
				count++;
			}

			void InternalInsertNodeToEmptyList(LinkedListNode* newNode)
			{
				if ((head != nullptr) || (count != 0))
					throw InvalidOperationException("LinkedList must be empty when this method is called!");

				newNode->SetNext(newNode);
				newNode->SetPrevious(newNode);
				head = newNode;
				version++;
				count++;
			}

			void InternalRemoveNode(LinkedListNode* node)
			{
				if (node->GetList() != this)
					throw InvalidOperationException("Deleting the node from another list!");
				if (head == nullptr)
					throw InvalidOperationException("This method shouldn't be called on empty list!");

				if (node->Next() == node)
				{
					delete head;
					head = nullptr;
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
			explicit LinkedList() :head(nullptr) {}
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
			LinkedListNode* First()const { return head; }
			LinkedListNode* Last()const { return head == nullptr ? head : head->previous; }

			LinkedListNode* AddAfter(LinkedListNode* node, const T& value)
			{
				ValidateNode(node);
				LinkedListNode* result = new LinkedListNode(this, value);
				InternalInsertNodeBefore(node->next, result);
				return result;
			}

			void AddAfter(LinkedListNode* node, LinkedListNode* newNode)
			{
				ValidateNode(node);
				ValidateNewNode(newNode);
				InternalInsertNodeBefore(node->Next(), newNode);
				newNode->SetList(this);
			}

			LinkedListNode* AddBefore(LinkedListNode* node, const T& value)
			{
				ValidateNode(node);
				LinkedListNode* result = new LinkedListNode(node->list, value);
				InternalInsertNodeBefore(node, result);
				if (node == head)
					head = result;

				return result;
			}

			void AddBefore(LinkedListNode* node, LinkedListNode* newNode)
			{
				ValidateNode(node);
				ValidateNewNode(newNode);
				InternalInsertNodeBefore(node, newNode);
				node->list = this;
				if (node == head)
					head = newNode;
			}

			LinkedListNode* AddFirst(const T& value)
			{
				LinkedListNode* result = new LinkedListNode(this, value);
				if (head == nullptr)
					InternalInsertNodeToEmptyList(result);
				else
				{
					InternalInsertNodeBefore(head, result);
					head = result;
				}

				return result;
			}

			void AddFirst(LinkedListNode* node)
			{
				ValidateNewNode(node);

				if (head == nullptr)
					InternalInsertNodeToEmptyList(node);
				else
				{
					InternalInsertNodeBefore(head, node);
					head = node;
				}

				node->list = this;
			}

			LinkedListNode* AddLast(const& value)
			{
				LinkedListNode* result = new LinkedListNode(this, value);
				if (head == nullptr)
					InternalInsertNodeToEmptyList(result);
				else
					InternalInsertNodeBefore(head, result);

				return result;
			}

			void AddLast(LinkedListNode* node)
			{
				ValidateNode(node);

				if (head == nullptr)
					InternalInsertNodeToEmptyList(node);
				else
					InternalInsertNodeBefore(head, node);

				node->list = this;
			}

			void Clear()
			{
				LinkedListNode* current = head;
				while (current != nullptr)
				{
					LinkedListNode* temp = current;
					current = current->next;
					temp->Invalidate();
					delete temp;
				}

				head = nullptr;
				count = 0;
				version++;
			}

			// Note: This method use operator= to test if 2 values are equal.
			LinkedListNode* Find(const T& value)
			{
				LinkedListNode* current = head;
				if (current != nullptr)
				{
					if (value != nullptr)
					{
						do
						{
							if (current->value == value)
								return current;
							current = current->next;
						}
						while (current != head);
					}
					else
					{
						do
						{
							if (current->value == nullptr)
								return current;
							current = current->next;
						}
						while (current != head);
					}
				}

				return nullptr;
			}

			// Note: This method use operator= to test if 2 values are equal.
			LinkedListNode* FindLast(const T& value)
			{
				if (head == nullptr)
					return nullptr;

				LinkedListNode* last = head->previous;
				LinkedListNode* current = last;

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
						while (current != last);
					}
					else
					{
						do
						{
							if (current->value == nullptr)
								return current;
							current = current->previous;
						}
						while (current != last);
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

				LinkedListNode* current = head;
				if (current != nullptr)
				{
					do
					{
						destArray[startIndex++] = current->value;
						current = current->next;
					}
					while (current != head);
				}
			}

			bool Remove(const T& value)
			{
				LinkedListNode* target = Find(value);
				if (target != nullptr)
				{
					InternalRemoveNode(target);
					return true;
				}
				return false;
			}

			void Remove(LinkedListNode* node)
			{
				ValidateNode(node);
				InternalRemoveNode(node);
			}

			void RemoveFirst()
			{
				if (head == nullptr)
					throw InvalidOperationException("Linked list is empty.");

				InternalRemoveNode(head);
			}

			void RemoveLast()
			{
				if (head == nullptr)
					throw InvalidOperationException("Linked list is empty.");

				InternalRemoveNode(head->previous);
			}
		};
	}
}