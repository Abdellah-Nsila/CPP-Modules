#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{	
		Intern	i1 = Intern();

		AForm*	f1;
		f1 = i1.makeForm("shrubbery creation", "Home");
		std::cout << *f1 << std::endl;
		delete f1;
		
		AForm*	f2;
		f2 = i1.makeForm("robotomy request5", "Bender");
		std::cout << *f2 << std::endl;
		delete f2;
		
		AForm*	f3;
		f3 = i1.makeForm("presidential pardon", "Jorshwa");
		std::cout << *f3 << std::endl;
		delete f3;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
