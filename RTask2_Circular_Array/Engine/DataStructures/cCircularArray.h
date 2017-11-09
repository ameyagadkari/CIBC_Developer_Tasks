/*
This file provides the interface for custom data structure "Circular Array"
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
		class cCircularArray
		{
			// Interface
			//==========
		public:		
			bool IsFull() const;
			bool IsEmpty() const;
			void PushFront(const int i_value);
			void PushBack(const int i_value);
			void PopFront();
			void PopBack();
			int  GetFront() const;
			int  GetBack() const;
			void RotateLeft(const int32_t i_steps);
			void RotateRight(const int32_t i_steps);
			// Initialization / Clean up
			//--------------------------
			explicit cCircularArray(const uint32_t i_size);
			~cCircularArray();
		private:
			// Data
			//=====

			static constexpr int32_t ms_invalidIndex = -1;
			int* m_internalArray = nullptr;
			uint32_t m_size = 0;
			uint32_t m_count = 0;
			int32_t m_frontIndex = ms_invalidIndex;
			int32_t m_backIndex = ms_invalidIndex;
			int32_t m_startIndex = ms_invalidIndex;
			int32_t m_endIndex = ms_invalidIndex;
		};
	}
}

#endif	// AVG_CCIRCULARARRAY_H
