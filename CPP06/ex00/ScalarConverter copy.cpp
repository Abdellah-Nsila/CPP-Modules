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

template <typename T_Value, typename T_Cast>
bool	isOutOfRange(T_Value value)
{
	if (!std::numeric_limits<T_Cast>::is_integer)
		return (std::isinf(value) || std::isnan((value)));
	T_Cast	minBound = std::numeric_limits<T_Cast>::min();
	T_Cast	maxBound = std::numeric_limits<T_Cast>::max();
	return (value < minBound || value > maxBound);
}

template <typename T>
void	display(T value)
{
	std::cout << "char: ";
	if (isOutOfRange<T, char>(value))
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

	std::cout << "int: ";
	if (isOutOfRange<T, int>(value))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "float: ";
	if (isOutOfRange<T, float>(value))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: ";
	if (isOutOfRange<T, double>(value))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<double>(value) << std::endl;
}

void	castToTypes(std::string s)
{
	if (isPseudoLiterals(s))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << strtof(s.c_str(), NULL) << "f" << std::endl;
		std::cout << "double: " << strtod(s.c_str(), NULL) << std::endl;
		return ;
	}

	switch (getType(s))
	{
		case (CHAR):
		{
			display<char>(s[0]);
			break ;
		}
		case (INT):
		{
			display<long>(atol(s.c_str()));
			break;
		}
		case (FLOAT):
		{
			display<float>(strtof(s.c_str(), NULL));
			break;
		}
		case (DOUBLE):
		{
			display<double>(strtod(s.c_str(), NULL));
			break ;
		}
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << "f" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
	}
}

void	ScalarConverter::convert(std::string& s)
{
	if (!s.empty())
		castToTypes(s);
	else
		std::cerr << "Empty argument!" << std::endl;
}
