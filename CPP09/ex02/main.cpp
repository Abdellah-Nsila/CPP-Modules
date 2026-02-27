/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:43 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/27 10:24:24 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << argv[0] << std::endl;
	}
	std::vector<int> jacob = jacobSequence(11);
	std::cout << (jacob.back() - *(jacob.end() - 2)) << std::endl;
	return 0;
}
