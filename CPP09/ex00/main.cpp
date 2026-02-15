/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:58:00 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/15 17:55:08 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <vector>
#include <algorithm>

int	main(int argc, char *argv[])
{
	try
	{
		std::map<std::string, double> data;

		if (argc != 2)
		{
			throw CannotOpenFile();
		}
		parseBtcDatabase("data.csv", data);
		bitcoinExchange(argv[1], data);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	
	return 0;
}
