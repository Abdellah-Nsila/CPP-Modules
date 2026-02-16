/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:58:05 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/16 09:25:39 by abnsila          ###   ########.fr       */
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

std::string	trim(const std::string& line)
{
	size_t l = line.find_first_not_of(" \t\r\n");
    if (l == std::string::npos) return ""; // empty string
    size_t r = line.find_last_not_of(" \t\r\n");
    return line.substr(l, r - l + 1);
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

bool	parseBtcDatabase(const std::string& filePath, std::map<std::string, double>& database)
{
	std::string	date;
	double		price;
	std::string	left;
	std::string	right;

	// Open file
	std::ifstream	file(filePath.c_str());
	if (!file.is_open())
		throw CannotOpenFile();

	// Collect database
	std::string	line;
	getline(file, line);
	while (getline(file, line))
	{
		if (line.find(',') == std::string::npos)
			continue ;

		left = line.substr(0, line.find(','));
		right = line.substr(line.find(',') + 1);

		left.erase(left.find_last_not_of(" \t") + 1);
		right.erase(0, right.find_first_not_of(" \t"));
		
		date = left;
		std::stringstream	ss(right);
		
		ss >> price;

		// Handle Errors and invalide inputs
		if (ss.fail() || !ss.eof())
			continue ;
		if (!isValidDateFormat(date) || !isValidDateValue(date))
			continue ;
		database.insert(std::pair<std::string, double>(date, price));
	}
	file.close();
	return true;
}

bool	parseBtcInput(std::string& line, std::string& date, double& quantity)
{
	size_t pipePos = line.find('|');
	
	if (pipePos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}

	// TODO trim spaces
	std::string	left = line.substr(0, pipePos);
	std::string	right = line.substr(pipePos + 1);
	left  = trim(left);
	right = trim(right);

	std::cout << "\"" << left << "\""  << std::endl;

	date = left;
	std::stringstream	ss(right);
	ss >> quantity;
	// std::cout << "\"" << date << "\""  << std::endl;

	// Handle Errors and invalide inputs
	// if (ss.fail() || !ss.eof())
	// {
	// 	std::cerr << "Error: bad input => " << line << std::endl;
	// 	return false;
	// }
	// if (!isValidDateFormat(date) || !isValidDateValue(date))
	// {
	// 	std::cerr << "Error: The requested date is older than anything in database." << std::endl;
	// 	return false;
	// }
	// if (quantity < 0)
	// {
	// 	std::cerr << "Error: not a positive number." << std::endl;
	// 	return false;
	// }
	// if (quantity > 1000)
	// {
	// 	std::cerr << "Error: too large a number." << std::endl;
	// 	return false;		
	// }
	return true;
}

void	bitcoinExchange(const std::string& filePath, const std::map<std::string, double>& database)
{
	std::string	date;
	double		quantity;
	double		factor;

	// Open file
	std::ifstream	file(filePath.c_str());
	if (!file.is_open())
		throw CannotOpenFile();

	// Collect database
	std::string	line;
	getline(file, line);
	while (getline(file, line))
	{
		if (parseBtcInput(line, date, quantity) == false)
			continue ;
		std::map<std::string, double>::const_iterator	it = database.lower_bound(date);
		if (it == database.end() || it->first != date)
		{
			if (it != database.begin())
				--it;
		// 	else
		// 	{
		// 		std::cerr << "Error: bad input => " << line << std::endl;
		// 		continue ;
		// 	}
		}
		factor = it->second;
		// std::cout << date << " => " << quantity << " = " << factor * quantity << std::endl;
	}
	file.close();
}
