/*
main() is the entry point of a console program
*/

// Include Files
//==============

#include <Application/UnitTest/UnitTest.h>

#include <iostream>

// Entry Point
//============

int main(int, char**)
{
	// Run Unit Test
	avg::UnitTest::RunUnitTest();

#ifdef _WIN32	
	system("pause");
#else
	std::cout << "\nPress enter/return to exit . . ." << std::endl;
	getchar();
#endif
	return EXIT_SUCCESS;
}