#pragma once
#include "stdafx.h"
#include <ctime>

namespace DataWorks
{
	// The StdRandom class provides static methods for generating pseudo-random number for various descrete and coutinuous distributions.
	// It also provides method for shuffling an array or sub-array.
	class StdRandom
	{
	private:
		class Random
		{
		public:
			// The seed of this random number generator.
			unsigned int seed;

			// Initializes a new random number generator with time-reveland seed.
			Random()
			{
				seed = (unsigned)time(nullptr);
				srand(seed);
			}

			// Initializes a new random number generator with specified seed.
			// seed : The specified seed.
			Random(unsigned int seed)
			{
				this->seed = seed;
				srand(seed);
			}

			// Returns a non-negative random integer between [0, 32767].
			int NextInt() { return rand(); }

			// Returns a random floating number that is greater than to equal to 0.0 and less than 1.0.
			double NextDouble() { return rand() / ((double)RAND_MAX); }
		};

		// A instance of the pseudo-random number generator.
		Random random;

	public:
		// Initializes an instance of StdRandom with time-relevant seed.
		StdRandom() { random = Random(); }

		// Initializes an instance of StdRandom with specified seed.
		StdRandom(unsigned int seed) { SetSeed(seed); }

		// Free resources.
		~StdRandom() {}

		// Reset the seed of this random number generator.
		void SetSeed(unsigned int seed) { random = Random(seed); }

		// Returns a non-negative random integer between [0, 32767].
		int NextInt() { return random.NextInt(); }

		// Returns a random floating number that is greater than to equal to 0.0 and less than 1.0.
		double NextDouble() { return random.NextDouble(); }

		// Returns a random integer number uniformly in [0,n).
		// maxValue : Number of possibile numebrs.
		int Uniform(int maxValue) { return random.NextInt() % maxValue; }

		// Returns a random real number uniformly in [minValue, maxValue).
		// minValue : The left end-point.
		// maxValue : The right end-point.
		int Uniform(int minValue, int maxValue);

		// Returns a random double number uniformly in [minValue, maxValue).
		// minValue : The left end-point.
		// maxValue : The right end-point.
		double Uniform(double minValue, double maxValue);

		// Re-arranges the elements of the specified array in uniformly random order.
		// T : A type parameter with no constrain.
		// a : The array to shuffle.
		// length : The length of the input array.
		template<class T>
		void Shuffle(T a[], int length)
		{
			using namespace std;

			if (a == nullptr)
				throw runtime_error("The input array is null.");

			for (int i = 0; i < length; i++)
			{
				// Generate an index between i and (n - 1) to swap.
				int indexToSwap = i + Uniform(length - i);

				// Swap them.
				T temp = a[i];
				a[i] = a[indexToSwap];
				a[indexToSwap] = temp;
			}
		}

		// Re-arrange the elements in the specified sub-array (with index [low, high]) in uniformly random order.
		// T : A type parameter with no constrain.
		// a : The array to shuffle.
		// low : The left end-point.
		// high : The right end-point.
		template<class T>
		void Shuflle(T a[], int length, int low, int high)
		{
			using namespace std;

			if (a == nullptr)
				throw runtime_error("The input array is null.");
			if ((low < 0) ||
				(low > high) ||
				(high > length))
				throw range_error("Illegal sub-array range.");

			for (int i = low, i <= high; i++)
			{
				// Generate an index between i and (n - 1) to swap.
				int indexToSwap = i + Uniform(high - i);

				// Swap them.
				T temp = a[i];
				a[i] = a[indexToSwap];
				a[indexToSwap] = temp;
			}
		}
	};
}