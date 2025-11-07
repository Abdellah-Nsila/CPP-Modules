#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Unknown ShrubberyCreationForm", 145, 137), _target("Unknown target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target)
{
	this->createFile();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target)
{
	this->createFile();
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
		AForm::operator=(copy);
		this->createFile();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::createFile() const
{
	std::string		outFile_path = (this->_target + "_shrubbery");
	std::ofstream	outFile(outFile_path.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Can't open " << outFile_path << std::endl;
		return ;
	}

	outFile << "=================== ASCII trees ==================\n"
	<< "                                  # #### ####" << '\n'
    << "                            ### \\/#|### |/####" << '\n'
    << "                           ##\\/#/ \\||/##/_/##/_#" << '\n'
    << "                         ###  \\/###|/ \\/ # ###" << '\n'
    << "                       ##_\\_#\\_\\## | #/###_/_####" << '\n'
    << "                      ## #### # \\ #| /  #### ##/##" << '\n'
    << "                       __#_--###`  |{,###---###-~" << '\n'
    << "                                 \\ }{" << '\n'
    << "                                  }}{" << '\n'
    << "                                  }}{" << '\n'
    << "                                  {{}" << '\n'
    << "                            , -=-~{ .-^- _"
	<< std::endl;
	outFile.close();
}
