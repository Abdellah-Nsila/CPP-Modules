/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:57:57 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/15 15:53:04 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

#include <cctype>
#include <climits>
#include <cstdlib>

#include <map>
#include <utility>

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

int	parseBtcData(std::string filePath);
int	bitcoinExchange(std::string filePath);
