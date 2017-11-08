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
			int  GetFront();
			int  GetBack();
			// Initialization / Clean up
			//--------------------------
			explicit cCircularArray(const uint32_t i_size);
			~cCircularArray();
		private:
			// Data
			//=====

			static constexpr uint32_t ms_invalidIndex = ~0;
			int* m_internalArray = nullptr;
			uint32_t m_size = 0;
			uint32_t m_frontIndex = ms_invalidIndex;
			uint32_t m_backIndex = 0;
		};
	}
}

#endif	// AVG_CCIRCULARARRAY_H
