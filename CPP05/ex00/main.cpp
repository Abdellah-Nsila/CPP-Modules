#include "Bureaucrat.hpp"

int	main()
{
	// Good Initialization
	try
	{
		Bureaucrat	b1 = Bureaucrat("Good", 42);
		Bureaucrat	b2;
		// Bureaucrat	b2 = b1; This is copy constructor not assignement constructor
		b2 = b1; // This is assignement constructor
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Bad Initialization
	try
	{
		Bureaucrat	b1 = Bureaucrat("Bad", 1337);
		Bureaucrat	b2(b1);
	
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// High Exception
	try
	{
		Bureaucrat	high = Bureaucrat("High", 1);

		std::cout << high << std::endl;
		high.increGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Low Exception
	try
	{
		Bureaucrat	low = Bureaucrat("Low", 150);

		std::cout << low << std::endl;
		low.decreGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}