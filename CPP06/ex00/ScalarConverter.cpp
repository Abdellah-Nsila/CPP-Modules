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
		return (true);
	return (false);
}

void	display(std::string s, char c, long n_int, float n_float, double n_double)
{
	// Char
	if (isPseudoLiterals(s))
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;

	// Int
	if (isPseudoLiterals(s))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << n_int << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	// Float
	std::cout << "float: "  << n_float << "f" << std::endl;

	// Double
	std::cout << "double: " << n_double << std::endl;
}

void	cast(std::string s)
{
	char	c = '\0';
	int		n_int = 0;
	float	n_float = 0.0f;
	double	n_double = 0.0;

	switch (getType(s))
	{
		case (CHAR):
		{
			c = s[0];
			n_int = static_cast<int>(c);
			n_float = static_cast<float>(c);
			n_double = static_cast<double>(c);
			break ;
		}
		case  (INT):
		{
			n_int = atoi(s.c_str());
			c = static_cast<char>(n_int);
			n_float = static_cast<float>(n_int);
			n_double = static_cast<double>(n_int);
			break;
		}
		case (FLOAT):
		{
			n_float = strtof(s.c_str(), NULL);
			c = static_cast<char>(n_float);
			n_int = static_cast<int>(n_float);
			n_double = static_cast<double>(n_float);
			break;
		}
		case  (DOUBLE):
		{
			n_double = strtod(s.c_str(), NULL);
			c = static_cast<char>(n_double);
			n_int = static_cast<int>(n_double);
			n_float = static_cast<float>(n_double);
			break ;
		}
		default:
			std::cerr << "Error: Invalid Input" << std::endl;
			return ;
	}
	display(s, c, n_int, n_float, n_double);
}

void	ScalarConverter::convert(std::string& s)
{
	if (!s.empty())
		cast(s);
	else
		std::cerr << "Empty argument!" << std::endl;
}
