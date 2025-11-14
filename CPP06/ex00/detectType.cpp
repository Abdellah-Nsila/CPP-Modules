/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:04:32 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/14 12:01:22 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "detectType.hpp"

bool	isChar(std::string s)
{
	// std::cout << "char: " << "\"" << s << "\"" << std::endl;
	return (s.length() == 1 && !isdigit(s[0]));
}

bool	isInt(std::string s)
{
	std::stringstream	ss(s);
	long	value;
	char	leftOver;
	ss >> value;
	if (ss.fail())
		return (false);
	if (ss >> leftOver)
		return (false);
	if (value < INT_MIN || value > INT_MAX)
		return (false);
	// std::cout << "int: " << "\"" << value << "\"" << std::endl;
	return (true);
}

bool	isFloat(std::string s)
{
	float	value;
	char	leftOver;

	if (s == "-inff" || s == "+inff" || s == "nanf")
		return (true);
	if (s[s.length() - 1] != 'f')
		return (false);
	std::stringstream	ss(s.substr(0, s.length() - 1));
	ss >> value;
	if (ss.fail())
		return (false);
	if (ss >> leftOver)
		return (false);
	if (s.find('.') == std::string::npos)
		return (false);
	if (value < -FLT_MIN || value > FLT_MAX)
		return (false);
	// std::cout << std::setprecision(4) << "float: " << "\"" << value << "\"" << std::endl;
	return (true);
}

bool	isDouble(std::string s)
{
	double	value;
	char	leftOver;

	if (s == "-inf" || s == "+inf" || s == "nan")
		return (true);
	std::stringstream	ss(s);
	ss >> value;
	if (ss.fail())
		return (false);
	if (ss >> leftOver)
		return (false);
	if (s.find('.') == std::string::npos)
		return (false);
	if (value < -DBL_MIN || value > DBL_MAX)
		return (false);
	// std::cout << std::setprecision(4) << "double: " << "\"" << value << "\"" << std::endl;
	return (true);
}

literalType	getType(std::string s)
{
	// std::cout << "\"" << s << "\"" << std::endl;
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
