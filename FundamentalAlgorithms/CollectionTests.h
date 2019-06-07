#pragma once
#include "stdafx.h"
#include "LinkedList.h"

namespace DataWorks
{
	namespace Collections
	{
		class CollectionTests
		{
		private:
			static void PrintString(const std::string & s);

		public:
			static void LinkedListFunctionalityTest();
		};
	}
}