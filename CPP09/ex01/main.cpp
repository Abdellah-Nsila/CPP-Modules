/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:07:43 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/16 10:48:40 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char* argv[])
{
	int	result;

	if (argc != 2)
	{
		std::cerr << "Syntax error: ./RPN \"exp\"" << std::endl;
		return 1;
	}
	try
	{
			result = RPN(argv[1]);
	std::cout << result << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}