/*
This file provides the interface for custom iterator
*/

#ifndef AVG_CITERATOR_H
#define AVG_CITERATOR_H

// Include Files
//==============

#include <cstdint>

// Forward Declarations
//=====================

namespace avg
{
	namespace DataStructures
	{
		template <typename T>
		class cCircularArray;
	}
}

// Class Declaration
//==================

namespace avg
{
	namespace DataStructures
	{
		template <typename T>
		class cIterator
		{

			// Interface
			//==========

		public:

			explicit cIterator(cCircularArray<T>const& i_container, uint32_t const i_index)
				:
				m_container(i_container),
				m_index(i_index)
			{}

			//Operators
			//---------

			bool operator!=(cIterator const& i_other) { return (m_index != i_other.m_index); }
			const cIterator& operator++() { m_index++; return *this; }
			T& operator*() { return m_container[m_index]; }

		private:
			const cCircularArray<T>& m_container;
			uint32_t m_index;
		};
	}
}

#endif	// AVG_CITERATOR_H
