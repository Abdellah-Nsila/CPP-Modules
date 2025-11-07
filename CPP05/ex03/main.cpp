#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	// Init Forms
	ShrubberyCreationForm	s1 = ShrubberyCreationForm("Home");
	std::cout << s1 << std::endl;

	RobotomyRequestForm	r1 = RobotomyRequestForm("Bird");
	std::cout << r1 << std::endl;

	PresidentialPardonForm	p1 = PresidentialPardonForm("Jorshwa");
	std::cout << p1 << std::endl;
	
	// Execution
	try
	{	
		Bureaucrat	b1 = Bureaucrat("B1", 60);
		std::cout << b1 << std::endl;

		b1.signForm(s1);
		b1.signForm(r1);
		b1.signForm(p1);

		b1.executeForm(s1);
		b1.executeForm(r1);
		b1.executeForm(p1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
