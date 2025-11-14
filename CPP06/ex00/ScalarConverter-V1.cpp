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
#include <cstdlib>
#include <iomanip>
#include <cerrno>
#include <climits>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

// void	convertToChar(std::string s)
// {
// 	std::stringstream	ss(s);
// 	int					n_int;

// 	ss >> n_int ;
// 	std::cout << "Int: " << n_int << ", \"" << s << "\"" << std::endl;
// 	if (n_int >= 32 && n_int <= 126)
// 		std::cout << static_cast<char>(n_int) << std::endl;
// 	else if (s != "0" && s != "-0" && n_int == 0)
// 		std::cout << "impossible" << std::endl;
// 	else if (n_int <= 255)
// 		std::cout << "Non displayable" << std::endl;
// 	else
// 		std::cout << "impossible" << std::endl;
// }

// void	convertToInt(std::string s)
// {
// 	std::stringstream	ss(s);
// 	int	n_int;

// 	ss >> n_int;

	
// }

// void	convertToFloat(std::string s)
// {
// 	(void)s;
// 	// if ()
// 	// {
		
// 	// }
// }

// void	convertToDouble(std::string s)
// {
// 	(void)s;
// 	// if ()
// 	// {
		
// 	// }
// }

bool	isChar(std::string s)
{
	return (s.length() == 1 && !isdigit(s[0]));
}

bool	isInt(std::string s)
{
	char*	endPtr;

	(strtol(s.c_str(), &endPtr, 10));
	if (*endPtr != '\0')
	{
		// std::cout << "Not int: " << "\"" << endPtr << "\"" << std::endl;
		return (false);
	}
	return (true);
}

bool	isFloat(std::string s)
{
	char*	endPtr;

	if (s == "-inff" || s == "+inff" || s == "nanf")
		return (true);
	strtof(s.c_str(), &endPtr);
	if (*endPtr == 'f'
		&& *(endPtr + 1) == '\0'
		&& s.find(".", 1) != std::string::npos)
	{
			return (true);
	}
	// std::cout << "Not double: " << "\"" << endPtr << "\"" << std::endl;
	return (false);
}

bool	isDouble(std::string s)
{
	char*	endPtr;

	if (s == "-inf" || s == "+inf" || s == "nan")
		return (true);
	strtod(s.c_str(), &endPtr);
	if (*endPtr == '\0'
		&& s.find('.', 1) != std::string::npos
		&& s[s.length() - 1] != '.')
	{
		return (true);
	}
	// std::cout << "Not double: " << "\"" << endPtr << "\"" << std::endl;
	return (false);
}

literalType	getType(std::string s)
{
	std::cout << "\"" << s << "\"" << std::endl;
	if (isChar(s))
	{
		// std::cout << "isChar: " << s << std::endl;
		return (CHAR);
	}
	else if (isInt(s))
	{
		// std::cout << "isInt: " << s << std::endl;
			return (INT);
	}
	else if (isFloat(s))
	{
		// std::cout << "isFloat: " << s << std::endl;
		return (FLOAT);
	}
	else if (isDouble(s))
	{
		// std::cout << "isDouble: " << s << std::endl;
		return (DOUBLE);
	}
	else
	{
		// std::cerr << "Invalide input" << std::endl;
		return (INVALID);
	}
}

void	cast(std::string s)
{
	char	c = '\0';
	long	n_int = 0;
	float	n_float = 0.0f;
	double	n_double = 0.0;

	std::cout << "\"" << s << "\"" << std::endl;
	switch (getType(s))
	{
		case (CHAR):
		{
			// std::cout << "isChar: " << s << std::endl;
			c = s[0];
			n_int = static_cast<int>(c);
			n_float = static_cast<float>(c);
			n_double = static_cast<double>(c);
			break ;
		}
		case  (INT):
		{
			// std::cout << "isInt: " << s << std::endl;
			errno = 0;
			n_int = strtol(s.c_str(), NULL, 10);
			if (errno == ERANGE || n_int < INT_MIN || n_int > INT_MAX)
				std::cerr << "Overflow in int" << std::endl;
			c = static_cast<char>(n_int);
			n_float = static_cast<float>(n_int);
			n_double = static_cast<double>(n_int);
			break ;
		}
		case  (FLOAT):
		{
			// std::cout << "isFloat: " << s << std::endl;
			errno = 0;
			n_float = strtof(s.c_str(), NULL);
			if (errno == ERANGE)
				std::cerr << "Overflow in float" << std::endl;
			c = static_cast<char>(n_float);
			n_int = static_cast<int>(n_float);
			n_double = static_cast<double>(n_float);
			break ;
		}
		case  (DOUBLE):
		{
			// std::cout << "isDouble: " << s << std::endl;
			errno = 0;
			n_double = strtod(s.c_str(), NULL);
			if (errno == ERANGE)
				std::cerr << "Overflow in double" << std::endl;
			c = static_cast<char>(n_double);
			n_int = static_cast<int>(n_double);
			n_float = static_cast<float>(n_double);
			break ;
		}
		default:
			break;
	}
	
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << n_int << std::endl;
	std::cout << "float: " << std::setprecision(1) << n_float << "f" << std::endl;
	std::cout << "double: " << std::setprecision(1) << n_double << std::endl;
}


void	ScalarConverter::convert(std::string& s)
{
	std::cout << std::fixed; 
	cast(s);
}
