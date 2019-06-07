#pragma once

namespace DataWorks
{
	namespace Collections
	{
		template<class T>
		class LinkedListNode
		{
		public:
			T data;
			LinkedListNode* next;
			LinkedListNode* previous;

			LinkedListNode(T& data) : data(data)
			{
				next = nullptr;
				previous = nullptr;
			}
		};
	}
}