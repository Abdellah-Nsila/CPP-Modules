/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:38:58 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/09 22:22:55 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool	isPseudoLiterals(std::string& s)
{
	if (s == "-inf" || s == "+inf" || s == "inf" || s == "nan"
		|| s == "-inff" || s == "+inff" || s == "inff" || s == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << strtof(s.c_str(), NULL) << "f" << std::endl;
		std::cout << "double: " << strtod(s.c_str(), NULL) << std::endl;
		return (true);
	}
	return (false);
}

void	displayAllImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	displayChar(double value)
{
	char	c;

	std::cout << "char: ";
	if (std::isinf(value) || std::isnan(value)
		|| value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	c = static_cast<char>(value);
	if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void	displayInt(double value)
{
	std::cout << "int: ";
	if (std::isinf(value) || std::isnan(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
	}
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void	displayFloat(float value)
{
	std::cout << "float: ";
	if (std::isinf(value) || std::isnan(value))
	{
		std::cout << "impossible" << std::endl;
	}
	else
		std::cout << static_cast<float>(value) << "f" << std::endl;
}

void	displayDouble(double value)
{
	std::cout << "double: ";
	if (std::isinf(value) || std::isnan(value))
	{
		std::cout << "impossible" << std::endl;
	}
	else
		std::cout << static_cast<double>(value) << std::endl;
}

void	castToTypes(std::string s)
{
	if (isPseudoLiterals(s))
		return ;

	double	value = 0.0;
	switch (getType(s))
	{
		case (CHAR):
		{
			value = static_cast<double>(s[0]);
			break ;
		}
		case (INT):
		{
			value = static_cast<double>(atol(s.c_str()));
			break;
		}
		case (FLOAT):
		{
			value = static_cast<double>(strtof(s.c_str(), NULL));
			break;
		}
		case (DOUBLE):
		{
			value = static_cast<double>(strtod(s.c_str(), NULL));
			break ;
		}
		default:
			displayAllImpossible();
			return ;
	}
	displayChar(value);
	displayInt(value);
	std::cout << std::fixed << std::setprecision(1);
	displayFloat(value);
	displayDouble(value);
}

void	ScalarConverter::convert(std::string& s)
{
	if (!s.empty())
		castToTypes(s);
	else
		std::cerr << "Empty argument!" << std::endl;
}
