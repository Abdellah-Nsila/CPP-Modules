/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:43 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/01 13:56:30 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;
	// if (argc < 2)
	// {
	// 	std::cerr << argv[0] << std::endl;
	// }

	std::vector<int>	numbers;
	numbers.push_back(5);
	numbers.push_back(1);
	numbers.push_back(13);
	numbers.push_back(2);

	pmergeMe(numbers);

	displayContainer(numbers);
	return 0;
}
