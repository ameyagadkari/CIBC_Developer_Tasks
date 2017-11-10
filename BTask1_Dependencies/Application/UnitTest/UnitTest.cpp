// Include Files
//==============

#include "UnitTest.h"

#include <Engine/Algorithms/cHeapSort.h>
#include <Engine/DataStructures/cProjectDependency.h>

#include <cstdlib>
#include <ctime>

// Helper Function Declarations
//=============================

namespace
{
	void TestDependencies();
}

// Interface
//==========

void avg::UnitTest::RunUnitTest()
{
	srand(static_cast<unsigned int>(time(static_cast<time_t *>(nullptr))));
	TestDependencies();
}

// Helper Function Definitions
//============================

namespace
{
#define LENGTH 6
#define LENGTH2 10
	void TestDependencies()
	{
		avg::DataStructures::cProjectDependency z[LENGTH]{ 'a','b','c','d','e','f' };
		char dependencyDescriptionArray[LENGTH2] = { 'a','d','f','b','b','d','f','a','d','c' };
		for (auto i = 0; i < LENGTH2; i += 2)
		{
			avg::DataStructures::cProjectDependency::AddDependency(dependencyDescriptionArray[i], dependencyDescriptionArray[i + 1]);
		}
		avg::Algorithms::cHeapSort<avg::DataStructures::cProjectDependency> heapSort;
		avg::Algorithms::iSort<avg::DataStructures::cProjectDependency>* sort = &heapSort;
		sort->Sort(LENGTH, z);

		avg::DataStructures::cProjectDependency::PrintBuildOrder(z);
	}

#undef LENGTH
#undef LENGTH2
}
