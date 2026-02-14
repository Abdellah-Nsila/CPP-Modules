/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:58:05 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/13 23:16:08 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include <map>

int	parseBtcHistory(std::string f)
{
	std::map<std::string, double>	m1;

	// Open file
	std::ifstream	file(f.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	
	// Collect data
	std::string	line;
	while (getline(file, line))
	{
		std::cout << line << std::endl;
	}
	
	return 0;
}
