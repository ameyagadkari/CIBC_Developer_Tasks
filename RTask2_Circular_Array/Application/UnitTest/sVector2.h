/*
This struct represents a position or direction in 2d space
*/

// DISCLAIMER: THIS IS NOT A COMPLETE VECTOR2 REPRESENTATION, USING IT TO DEMO THE CIRCULAR ARRAY

#ifndef AVG_MATH_SVECTOR2_H
#define AVG_MATH_SVECTOR2_H

// Include Files
//==============


// Struct Declaration and Definition
//==================================


namespace avg
{
	namespace Math
	{
		struct sVector2
		{
			// Data
			//=====

			float x = 0.0f, y = 0.0f;

			//Operators
			//---------

			friend std::ostream& operator<< (std::ostream& o_stream, sVector2 const& i_vector)
			{
				return o_stream << "X component: " << i_vector.x << " Y component: " << i_vector.y;
			}

			sVector2 operator +(const sVector2& i_rhs) const
			{
				return sVector2(x + i_rhs.x, y + i_rhs.y);
			}

			sVector2 operator -(const sVector2& i_rhs) const
			{
				return sVector2(x - i_rhs.x, y - i_rhs.y);
			}

			// Initialization / CleanUp
			//=========================

			sVector2() = default;
			sVector2(const float i_x, const float i_y) :x(i_x), y(i_y) {}
		};
	}
}

#endif	// EAE6320_MATH_SVECTOR2_H