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
	m_count++;
	if (m_startIndex == ms_invalidIndex && m_endIndex == ms_invalidIndex)
	{
		m_startIndex = 0;
		m_endIndex = 0;
	}
	else
	{
		m_endIndex = m_count - 1;
	}
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
	m_count++;
	if (m_startIndex == ms_invalidIndex && m_endIndex == ms_invalidIndex)
	{
		m_startIndex = 0;
		m_endIndex = 0;
	}
	else
	{
		m_endIndex = m_count - 1;
	}
}

void avg::DataStructures::cCircularArray::PopFront()
{
	if (IsEmpty())
	{
		std::cout << "Cannot pop from empty queue" << std::endl;
		return;
	}

	if (m_frontIndex == m_backIndex)
	{
		m_frontIndex = ms_invalidIndex;
		m_backIndex = ms_invalidIndex;
		m_startIndex = ms_invalidIndex;
		m_endIndex = ms_invalidIndex;
	}
	else if (m_frontIndex == m_size - 1)
	{
		m_frontIndex = 0;
	}
	else
	{
		m_frontIndex = m_frontIndex + 1;
	}
	m_count--;
}

void avg::DataStructures::cCircularArray::PopBack()
{
	if (IsEmpty())
	{
		std::cout << "Cannot pop from empty queue" << std::endl;
		return;
	}

	if (m_frontIndex == m_backIndex)
	{
		m_frontIndex = ms_invalidIndex;
		m_backIndex = ms_invalidIndex;
		m_startIndex = ms_invalidIndex;
		m_endIndex = ms_invalidIndex;
	}
	else if (m_backIndex == 0)
	{
		m_backIndex = m_size - 1;
	}
	else
	{
		m_backIndex = m_backIndex - 1;
	}
	m_count--;
}

int avg::DataStructures::cCircularArray::GetFront() const
{
	if (IsEmpty())
	{
		std::cout << "Cannot get from empty queue" << std::endl;
		return ms_invalidIndex;
	}
	return m_internalArray[m_startIndex];
}

int avg::DataStructures::cCircularArray::GetBack() const
{
	if (IsEmpty())
	{
		std::cout << "Cannot get from empty queue" << std::endl;
		return ms_invalidIndex;
	}
	return m_internalArray[m_endIndex];
}

void avg::DataStructures::cCircularArray::RotateLeft(const int32_t i_steps)
{
	if (m_startIndex != ms_invalidIndex && m_endIndex != ms_invalidIndex)
	{
		const int actualSteps = i_steps%m_count;
		m_startIndex -= actualSteps;
		m_endIndex -= actualSteps;
		if (m_startIndex < 0)
		{
			m_startIndex = m_size - m_startIndex;
		}
		if (m_endIndex < 0)
		{
			m_endIndex = m_size - m_endIndex;
		}
	}
}

void avg::DataStructures::cCircularArray::RotateRight(const int32_t i_steps)
{
	if (m_startIndex != ms_invalidIndex && m_endIndex != ms_invalidIndex)
	{
		const int actualSteps = i_steps%m_count;
		m_startIndex += actualSteps;
		m_endIndex += actualSteps;
		if (m_startIndex >= m_size)
		{
			m_startIndex = m_startIndex%m_size;
		}
		if (m_endIndex >= m_size)
		{
			m_endIndex = m_endIndex%m_size;
		}
	}
}

