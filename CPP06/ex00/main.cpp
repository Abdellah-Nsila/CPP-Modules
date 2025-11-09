/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:34:35 by abnsila           #+#    #+#             */
/*   Updated: 2025/11/09 22:20:32 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Syntax: ./convert <literal string>" << std::endl;
		return (1);
	}
	// std::cout << static_cast<int>(argv[1][0]) << std::endl;
	std::string s = std::string(argv[1]);
	ScalarConverter::convert(s);
}
