#ifndef AVG_CCIRCULARARRAY_INL
#define AVG_CCIRCULARARRAY_INL

// Include Files
//==============

#include "cCircularArray.h"

#include <iostream>

// Interface
//==========

// Initialization / Clean up
//--------------------------
template <typename T>
avg::DataStructures::cCircularArray<T>::cCircularArray(uint32_t const i_size, T const*const i_pointerToArray)
	:
	m_rotationOffset(0),
	m_internalArray(i_pointerToArray),
	m_size(i_size)
{}

template <typename T>
void avg::DataStructures::cCircularArray<T>::RotateLeft(uint32_t const i_steps)
{
	const auto actualSteps = i_steps%m_size;
	m_rotationOffset += actualSteps;
	if (abs(m_rotationOffset) >= m_size)
	{
		m_rotationOffset %= m_size;
	}
}

template <typename T>
void avg::DataStructures::cCircularArray<T>::RotateRight(uint32_t const i_steps)
{
	const auto actualSteps = i_steps%m_size;
	m_rotationOffset -= actualSteps;
	if (abs(m_rotationOffset) >= m_size)
	{
		m_rotationOffset %= m_size;
	}
}

template <typename T>
T const& avg::DataStructures::cCircularArray<T>::operator [](int const i_index)
{
	const auto actualIndex = CalculateActualIndex(i_index);
	return m_internalArray[actualIndex];
}

template <typename T>
T avg::DataStructures::cCircularArray<T>::operator [](int const i_index) const
{
	const auto actualIndex = CalculateActualIndex(i_index);
	return m_internalArray[actualIndex];
}

template <typename T>
int64_t avg::DataStructures::cCircularArray<T>::CalculateActualIndex(int const i_index) const
{
	auto actualIndex = i_index + m_rotationOffset;
	if (actualIndex < 0)
	{
		actualIndex += m_size;
	}
	else if (actualIndex >= m_size)
	{
		actualIndex %= m_size;
	}
	return actualIndex;
}

template <typename T>
void avg::DataStructures::cCircularArray<T>::PrintOriginalArray() const
{
	std::cout << "Original Array is" << std::endl;
	for (uint32_t i = 0; i < m_size; i++)
	{
		std::cout << m_internalArray[i] << std::endl;
	}
}

template <typename T>
void avg::DataStructures::cCircularArray<T>::PrintRotatedArray() const
{
	std::cout << "Rotated Array is" << std::endl;
	for (uint32_t i = 0; i < m_size; i++)
	{
		std::cout << (*this)[i] << std::endl;
	}
}

#endif	// AVG_CCIRCULARARRAY_INL
