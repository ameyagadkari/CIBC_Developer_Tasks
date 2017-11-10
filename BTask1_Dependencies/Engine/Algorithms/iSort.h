/*
This file provides the interface which different sorts can implement
*/

#ifndef AVG_ISORT_H
#define AVG_ISORT_H

namespace avg
{
	namespace Algorithms
	{
		// Class Declaration
		//==================

		template <typename T>
		class iSort
		{
		public:

			//Interface
			//=========

			virtual void Sort(int const i_size, T* io_arrayToSort) = 0;

			//Initialization/Clean up
			//-----------------------

			virtual ~iSort() = default;

		};
	}
}

#endif // AVG_ISORT_H
