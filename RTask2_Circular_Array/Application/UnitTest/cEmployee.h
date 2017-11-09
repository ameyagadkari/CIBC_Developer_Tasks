/*
This class represents an employee in a database
*/

// DISCLAIMER: THIS IS NOT A COMPLETE EMPLOYEE REPRESENTATION, USING IT TO DEMO THE CIRCULAR ARRAY

#ifndef AVG_DATABASE_CEMPLOYEE_H
#define AVG_DATABASE_CEMPLOYEE_H

// Include Files
//==============

#include <string>

// Class Declaration and Definition
//=================================

namespace avg
{
	namespace Database
	{
		class cEmployee
		{
			// Interface
			//==========

		public:

			std::string GetFullName() const
			{
				return m_firstName + " " + m_lastName;
			}

			//Operators
			//---------

			friend std::ostream& operator<< (std::ostream& o_stream, cEmployee const& i_employee)
			{
				return o_stream << "An employee named " << i_employee.GetFullName() << " earns $" << i_employee.m_salary << " at the age of " << std::to_string(i_employee.m_age);
			}

			// Initialization / CleanUp
			//-------------------------

			cEmployee() :m_firstName("UnKnown"), m_lastName("UnKnown"), m_salary(-1.0), m_age(0) {}
			cEmployee(const std::string i_firstName, const std::string i_lastName, const double i_salary, const uint8_t i_age) :m_firstName(i_firstName), m_lastName(i_lastName), m_salary(i_salary), m_age(i_age) {}

		private:

			// Data
			//=====

			std::string m_firstName;
			std::string m_lastName;
			double m_salary;
			uint8_t m_age;
		};
	}
}

#endif	// AVG_DATABASE_CEMPLOYEE_H
