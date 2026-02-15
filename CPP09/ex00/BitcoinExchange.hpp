/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:57:57 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/15 17:13:03 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

#include <cctype>
#include <cstdlib>

#include <map>
#include <utility>
#include <algorithm>

class NoInputFile : public std::exception
{
	public :
		const char*	what() const throw();
};

class CannotOpenFile : public std::exception
{
	public :
		const char*	what() const throw();
};

bool	parseBtcDatabase(const std::string& filePath, std::map<std::string, double>& data);
void	bitcoinExchange(const std::string& filePath, const std::map<std::string, double>& database);
