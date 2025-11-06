#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	// Good Initialization
	try
	{
		Form	f1 = Form("Good", 42, 10);
		Form	f2;
		f2 = f1;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Bad Initialization
	try
	{
		Form	f1 = Form("Bad", 13, 3700);
		Form	f2(f1);
	
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Low Exception
	try
	{
		Bureaucrat	low = Bureaucrat("B1", 75);
		Form		f1 = Form("Form_1", 100, 150);
		Form		f2 = Form("Form_2", 10, 100);

		std::cout << low << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		low.signForm(f1);
		low.signForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}