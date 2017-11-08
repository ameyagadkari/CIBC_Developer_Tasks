// Include Files
//==============

#include "cCircularArray.h"

#include <cassert>
#include <new>
#include <iostream>

// Static Data Initialization
//===========================

//uint32_t constexpr avg::DataStructures::cCircularArray::ms_invalidIndex = ~0;

// Interface
//==========

// Initialization / Clean up
//--------------------------

avg::DataStructures::cCircularArray::cCircularArray(const uint32_t i_size)
{
	assert(i_size < ~0);
	m_internalArray = new (std::nothrow) int[i_size];
	assert(m_internalArray);
	m_size = i_size;
	if (!m_internalArray)
	{
		std::cerr << "Memory allocation failed" << std::endl;
	}
}

avg::DataStructures::cCircularArray::~cCircularArray()
{
	if (m_internalArray)
	{
		delete[] m_internalArray;
	}
}

bool avg::DataStructures::cCircularArray::IsFull() const
{
	return (m_frontIndex == 0 && m_backIndex == m_size - 1) || (m_frontIndex == m_backIndex + 1);
}


bool avg::DataStructures::cCircularArray::IsEmpty() const
{
	return (m_frontIndex == ms_invalidIndex);
}

void avg::DataStructures::cCircularArray::PushFront(const int i_value)
{
	if (IsFull())
	{
		std::cerr << "Cannot insert more elements into this circular array" << std::endl;
		return;
	}

	if (IsEmpty())
	{
		m_frontIndex = 0;
		m_backIndex = m_frontIndex + 1;
	}
	else if (!m_frontIndex)
	{
		m_frontIndex = m_size - 1;
	}
	else
	{
		m_frontIndex = m_frontIndex - 1;
	}

	m_internalArray[m_frontIndex] = i_value;
}

void avg::DataStructures::cCircularArray::PushBack(const int i_value)
{
	if (IsFull())
	{
		std::cerr << "Cannot insert more elements into this circular array" << std::endl;
		return;
	}

	if (IsEmpty())
	{
		m_backIndex = 0;
		m_frontIndex = m_size - 1;
	}
	else if (m_backIndex == m_size - 1)
	{
		m_backIndex = 0;
	}
	else
	{
		m_backIndex = m_backIndex + 1;
	}
	m_internalArray[m_backIndex] = i_value;
}

