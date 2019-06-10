#pragma once

#include <iterator>
#include "Iterator.h"

namespace DataWorks
{
	namespace Collections
	{
		template<class T>
		class IReadOnlyCollection
		{
		protected:
			IReadOnlyCollection() {}
			virtual ~IReadOnlyCollection() {}

		public:

			// Gets the number of elements contained in this collection.
			// Returns: The number of elements in this collection.
			int Count() const = 0;

			// Determines whether this IReadOnlyCollection contains a specific value.
			// Parameter [value]: The value to locate in this IReadOnlyCollection.
			// Returns: [true] if the specified value is found in this IReadOnlyCollection; otherwise, [false].
			bool Contains(T value) const = 0;

			// Copies the elements of this IReadOnlyCollection to an array, starting at index 0.
			// Parameter [dest]: The one-dimensional array that is the destination of the elements copied from this IReadOnlyCollection, The array must have zero-based indexing.
			// Parameter [destLength]: The available length of the array.
			// Exception [ArgumentNullException]: The given array is null.
			// Exception [ArrayIndexOutOfBoundsException]: Array index is greater than or equal to the length of the array.
			// Exception [ArgumentException]: The number of elements in the source IReadOnlyCollection is greater than the available space from 0 to the end of the destination array, i.e. the capacity of the given array.
			void CopyTo(T* dest, int destLength) const = 0;

			void CopyTo(T* dest, int destLength, int startIndex) const = 0;
		};
	}
}