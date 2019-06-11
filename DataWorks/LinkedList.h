#pragma once

#include <iterator>
#include <exception>
#include "InvalidOperationException.h"

namespace DataWorks
{
	namespace Collections
	{
		template<class T>
		class LinkedListNode
		{
		private:
			LinkedList<T> * list;
			LinkedListNode* previous;
			LinkedListNode* next;
			T value;

		public:
			LinkedListNode(const T& value) : value(value)
			{
				list = nullptr;
				previous = nullptr;
				next = nullptr;
			}

			LinkedListNode(const LinkedList<T> * list, const T& value) : list(list), value(value) {}

			~LinkedListNode()
			{
				Invalidate();
			}

			public LinkedListNode Next() const { return next; }
			public LinkedListNode Previous() const { return previous; }
			public T& GetValue() const { return value; }
			public void SetValue(const T& value) { this->value = value; }
			public LinkedList<T> * GetList() { return list; }
			public void SetList(const LinkedList<T> * list)
			{
				if (list == nullptr)
					throw

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
		};

		template<class T>
		class LinkedListIterator : public std::iterator<std::input_iterator_tag, T>
		{

		};

		template<class T>
		class LinkedList
		{

		};
	}
}