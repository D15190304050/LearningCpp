#pragma once
#include "stdafx.h"
#include "NumberOfInversions.h"
#include "TestOption.h"

namespace AlgorithmDesigns
{
	class AlgorithmTests
	{
	public:
		// Functionality test function for the NumberOfInversions class.
		static void NoiFunctionalityTest(int testData[] = nullptr, int length = 0);
		
		// Unit test function for the NumberOfInversions class.
		static void NoiUnitTest();

		// Functionality test function for the TopK class.
		static void TopKFunctionalityTest(TestOption option = TestOption::DefaultIntArray, int specifiedArray[] = nullptr, int length = 10, int k = 5);

		// Unit test function for the TopK class.
		static void TopKUnitTest();
	};
}