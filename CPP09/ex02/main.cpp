/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:43 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/09 15:59:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Not enought arguments" << std::endl;
		return (1);
	}

	try
	{
		std::vector<int>	c1;
		std::deque<int>		c2;

		fillContainer(argc, argv, c1);
		fillContainer(argc, argv, c2);

		displayContainer("Before", c1);
		clock_t start_vec = std::clock();
		c1 = pmergeMe(c1);
		clock_t end_vec = std::clock();
		
		clock_t start_deq = std::clock();
		c2 = pmergeMe(c2);
		clock_t end_deq = std::clock();
		displayContainer("After", c2);

		std::cout << std::fixed << std::setprecision(5);

		double	time_vec = static_cast<double>(end_vec - start_vec);
		double	time_deq = static_cast<double>(end_deq - start_deq);

		std::cout << "Time to process a range of " << c1.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
		std::cout << "Time to process a range of " << c2.size() << " elements with std::deque : " << time_deq << " us" << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
