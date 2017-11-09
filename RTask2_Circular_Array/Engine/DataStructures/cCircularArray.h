/*
This file provides the interface for treating an array of type T as a circular array to efficiently rotate it
Note:	No actual rotation is involved we just read the array as if its rotated,
		I think this is the most efficient way I could come up with
*/

#ifndef AVG_CCIRCULARARRAY_H
#define AVG_CCIRCULARARRAY_H


// Include Files
//==============

#include "cIterator.h"

#include <cstdint>

// Class Declaration
//==================

namespace avg
{
	namespace DataStructures
	{
		template <typename T>
		class cCircularArray
		{
			// Interface
			//==========

		public:

			void RotateLeft(uint32_t const i_steps);
			void RotateRight(uint32_t const i_steps);

			void PrintOriginalArray() const;
			void PrintRotatedArray() const;

			// For-each support
			//=================

			cIterator<T> begin() const { return cIterator<T>(*this, 0); }
			cIterator<T> end() const { return cIterator<T>(*this, m_size); }

			//Operators
			//---------

			T const& operator [](int const i_index);
			T& operator [](int const i_index) const;

			// Initialization / Clean up
			//--------------------------

			explicit cCircularArray(uint32_t const i_size, T *const i_pointerToArray);
			~cCircularArray() = default;
		private:

			int64_t CalculateActualIndex(int const i_index) const;

			// Data
			//=====

			int64_t m_rotationOffset;
			T *const m_internalArray;
			uint32_t const m_size;
		};
	}
}

#include "cCircularArray.inl"

#endif	// AVG_CCIRCULARARRAY_H
