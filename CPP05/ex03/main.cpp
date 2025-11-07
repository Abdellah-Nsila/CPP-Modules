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
		AForm*	f2;
		AForm*	f3;
		//TODO: There is leaks if you throw after a succeded form creation
		f1 = i1.makeForm("shrubbery creation", "Home");
		f2 = i1.makeForm("robotomy request", "Bender");
		f3 = i1.makeForm("presidential pardon", "Jorshwa");
		
		std::cout << *f1 << std::endl;
		std::cout << *f2 << std::endl;
		std::cout << *f3 << std::endl;

		delete f1;
		delete f2;
		delete f3;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
