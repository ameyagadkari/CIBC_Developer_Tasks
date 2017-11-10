/*
This file implements the isort interface to do heap sort
*/

#ifndef AVG_CHEAPSORT_H
#define AVG_CHEAPSORT_H

// Include Files
//==============

#include "iSort.h"
#include <utility>

namespace avg
{
	namespace Algorithms
	{
		// Class Declaration
		//==================

		template <typename T>
		class cHeapSort : public iSort<T>
		{
			// Interface
			//==========

			void Heapify(T* io_arrayToSort, int const i_size, int const i_index)
			{
				auto smallest = i_index;
				const auto left = 2 * i_index + 1;
				const auto right = 2 * i_index + 2;

				if (left < i_size && io_arrayToSort[left] < io_arrayToSort[smallest])
				{
					smallest = left;
				}

				if (right < i_size && io_arrayToSort[right] < io_arrayToSort[smallest])
				{
					smallest = right;
				}

				if (smallest != i_index)
				{
					std::swap(io_arrayToSort[i_index], io_arrayToSort[smallest]);
					Heapify(io_arrayToSort, i_size, smallest);
				}
			}

			void Sort(int const i_size, T* io_arrayToSort) override
			{
				for (auto i = i_size / 2 - 1; i >= 0; i--)
				{
					Heapify(io_arrayToSort, i_size, i);
				}
				for (auto i = i_size - 1; i >= 0; i--)
				{
					std::swap(io_arrayToSort[0], io_arrayToSort[i]);
					Heapify(io_arrayToSort, i, 0);
				}
			}		
		};
	}
}

#endif // AVG_CHEAPSORT_H
