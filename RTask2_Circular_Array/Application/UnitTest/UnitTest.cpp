// Include Files
//==============

#include "UnitTest.h"
#include "cEmployee.h"
#include "sVector2.h"

#include <Engine/DataStructures/cCircularArray.h>

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>


// Helper Function Declarations
//=============================

namespace
{
	void TestPodType();
	void TestCustomUserClassEmployee();
	void TestCustomUserStructVector2();	
}

// Interface
//==========
void avg::UnitTest::RunUnitTest()
{
	srand(static_cast<unsigned int>(time(static_cast<time_t *>(nullptr))));
	TestPodType();
	TestCustomUserClassEmployee();
	TestCustomUserStructVector2();
}

// Helper Function Definitions
//============================

namespace
{
#define LENGTH 10

	void TestPodType()
	{
		std::vector<int> integerVector;
		for (auto i = 0; i < LENGTH; i++)
		{
			integerVector.push_back(i);
		}
		avg::DataStructures::cCircularArray<int> circularArray(LENGTH, integerVector.data());
		circularArray.PrintOriginalArray();
		circularArray.RotateRight(3);
		std::cout << "Rotated Array is" << std::endl;
		for (auto& x : circularArray)
		{
			std::cout << x << std::endl;
		}
	}

	void TestCustomUserClassEmployee()
	{
		std::vector<avg::Database::cEmployee> employeeVector;
		for (auto i = 0; i < LENGTH; i++)
		{
			employeeVector.push_back(avg::Database::cEmployee("John" + std::to_string(i), "Doe", 10000 * (static_cast<double>(rand()) / RAND_MAX), rand() % 65));
		}
		avg::DataStructures::cCircularArray<avg::Database::cEmployee> circularArray(LENGTH, employeeVector.data());
		circularArray.PrintOriginalArray();
		circularArray.RotateLeft(5);
		circularArray.PrintRotatedArray();
	}

	void TestCustomUserStructVector2()
	{
		std::vector<avg::Math::sVector2> vector2Vector;
		for (auto i = 0; i < LENGTH; i++)
		{
			const auto modifier = static_cast<float>(rand()) / RAND_MAX;
			vector2Vector.push_back(avg::Math::sVector2(10000 * modifier, 5000 * modifier));
		}
		avg::DataStructures::cCircularArray<avg::Math::sVector2> circularArray(LENGTH, vector2Vector.data());
		circularArray.PrintOriginalArray();
		circularArray.RotateLeft(13);
		circularArray.PrintRotatedArray();
	}

#undef LENGTH
}
