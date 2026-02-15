/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:58:05 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/15 15:55:01 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char*	NoInputFile::what() const throw()
{
	return "No Input File is given!";
}

const char*	CannotOpenFile::what() const throw()
{
	return "Error: could not open file.";
}

bool	isValidDateFormat(const std::string& date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(date[i]))
			return false;
	}
	return true;
}

bool	isValidDateValue(const std::string& date)
{
	int	year = atoi(date.substr(0, 4).c_str());
	int	month = atoi(date.substr(5, 2).c_str());
	int	day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	int	dayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		dayInMonth[1] = 29;
	if (day > dayInMonth[month - 1])
		return false;
	return true;
}

int	parseBtcData(std::string filePath, std::map<std::string, double> container)
{
	std::string	date;
	double		price;

	// Open file
	std::ifstream	file(filePath.c_str());
	if (!file.is_open())
		throw CannotOpenFile();

	// Collect data
	std::string	line;
	getline(file, line);
	while (getline(file, line))
	{
		date = line.substr(0, line.find(','));
		std::stringstream	ss(line.substr(line.find(',') + 1));
		ss >> price;

		// TODO Handle Errors and invalide inputs
		// std::cout << "date: " << date << "  price: " << price << std::endl;
		if (!isValidDateFormat(date) || !isValidDateValue(date))
			return false;
		container.insert(std::pair<std::string, double>(date, price));
	}
	return 0;
}

int	parseBtcInput(std::string line, std::string& date, double& quantity)
{
	if (line.find('|') == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 1;
	}
	date = line.substr(0, line.find('|') - 1);
	std::stringstream	ss(line.substr(line.find('|') + 2));
	ss >> quantity;

	// TODO Handle Errors and invalide inputs
	
	if (!isValidDateFormat(date) || !isValidDateValue(date))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 1;
	}
	if (quantity < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return 1;
	}
	if (quantity > INT_MAX)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return 1;		
	}
	return 0;
}

int	bitcoinExchange(std::string filePath)
{
	std::string	date;
	double		quantity;

	// Open file
	std::ifstream	file(filePath.c_str());
	if (!file.is_open())
		throw CannotOpenFile();

	// Collect data
	std::string	line;
	getline(file, line);
	while (getline(file, line))
	{
		if (parseBtcInput(line, date, quantity) != 0)
			continue ;
		std::cout << "2011-01-09 => 1 = 0.32" << std::endl;
	}
	return 0;
}

