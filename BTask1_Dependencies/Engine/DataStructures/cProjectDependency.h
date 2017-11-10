/*
This file implements custom data structure to hold project name and their priority in build order
*/

#ifndef AVG_PROJECTDEPENDENCY_H
#define AVG_PROJECTDEPENDENCY_H

// Include Files
//==============

#include <map>

namespace avg
{
	namespace DataStructures
	{
		class cProjectDependency
		{
		public:

			//Interface
			//=========

			static void AddDependency(char const i_projectName1, char const);
			static void PrintBuildOrder(cProjectDependency const*const& i_array);

			//Operators
			//---------

			bool operator<(cProjectDependency const& i_other) const;

			//Initialization/Clean up
			//-----------------------

			cProjectDependency(char const i_projectName);
			
		private:

			//Data
			//====

			static std::map<char, int> ms_projectName_priority_map;
			static unsigned ms_count;
			char m_projectName = 0;			
		};
	}
}

#endif // AVG_PROJECTDEPENDENCY_H
