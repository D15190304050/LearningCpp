#pragma once

namespace DataTools
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

			virtual ~LinkedListNode() {}
		};
	}
}