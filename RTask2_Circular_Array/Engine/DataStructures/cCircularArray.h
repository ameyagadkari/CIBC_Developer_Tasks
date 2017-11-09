/*
This file provides the interface for treating an array of type T as a circular array to efficiently rotate it
Note:	No actual rotation is involved we just read the array as if its rotated,
		write functionality is disabled but can be easily added
		I think this is the most efficient way I could come up with
*/

#ifndef AVG_CCIRCULARARRAY_H
#define AVG_CCIRCULARARRAY_H


// Include Files
//==============

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

			//Operators
			//---------

			T const& operator [](int const i_index);
			T operator [](int const i_index) const;

			// Initialization / Clean up
			//--------------------------

			explicit cCircularArray(uint32_t const i_size, T const*const i_pointerToArray);
			~cCircularArray() = default;
		private:

			int64_t CalculateActualIndex(int const i_index) const;

			// Data
			//=====

			int64_t m_rotationOffset;
			T const*const m_internalArray;
			uint32_t const m_size;
		};
	}
}

#include "cCircularArray.inl"

#endif	// AVG_CCIRCULARARRAY_H
