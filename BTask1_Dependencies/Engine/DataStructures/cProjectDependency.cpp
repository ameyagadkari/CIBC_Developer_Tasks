// Include Files
//==============

#include "cProjectDependency.h"

#include <iostream>

// Static Data Initialization
//===========================

std::map<char, int> avg::DataStructures::cProjectDependency::ms_projectName_priority_map;
unsigned avg::DataStructures::cProjectDependency::ms_count = 0;

//Interface
//=========

void avg::DataStructures::cProjectDependency::AddDependency(char const i_projectName1, char const)
{
	try
	{
		ms_projectName_priority_map[i_projectName1] = ++ms_projectName_priority_map.at(i_projectName1);
	}
	catch (std::out_of_range e)
	{
		std::cerr << "Cannot add dependency on a non-existant project " << e.what() << std::endl;
	}
}

void avg::DataStructures::cProjectDependency::PrintBuildOrder(cProjectDependency const*const& i_array)
{
	if (ms_projectName_priority_map[i_array[0].m_projectName] <= 0)return;
	std::cout << "The build order is: " << std::endl;
	for (unsigned i = 0; i < ms_count; ++i)
	{
		std::cout << i_array[i].m_projectName << "  ";
	}
	std::cout << std::endl;
}

//Operators
//---------

bool avg::DataStructures::cProjectDependency::operator<(cProjectDependency const& i_other) const
{
	return ms_projectName_priority_map[m_projectName] < ms_projectName_priority_map[i_other.m_projectName];
}

//Initialization/Clean up
//-----------------------

avg::DataStructures::cProjectDependency::cProjectDependency(char const i_projectName)
	:
	m_projectName(i_projectName)
{
	try
	{
		ms_projectName_priority_map.at(i_projectName);
	}
	catch (std::out_of_range e)
	{
		ms_projectName_priority_map[i_projectName] = 0;
		ms_count++;
	}
}
