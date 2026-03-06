/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:43 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/06 17:17:59 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	testJacobLogic(size_t pendSize)
{
	size_t	lastJacob = 1;
	size_t	insertCount = 0;
	std::vector<int>	jacobSeq = jacobSequence(pendSize + 1);
	for (size_t k = 3; k < jacobSeq.size(); k++)
	{
		size_t	currentJacob = jacobSeq[k];
		size_t	topJacobId = std::min(currentJacob, pendSize + 1);
		for (size_t i = topJacobId; i > lastJacob; i--)
		{
			if (i < 2)
				break;
			// int	pendIdx = i - 2;
			std::cout << "ID: " << i << "   loserIdx: " << i - 2 << "   winnerIdx: " << i + insertCount << std::endl;
			insertCount++;
		}
		lastJacob = jacobSeq[k];
		// if (lastJacob > pendSize)
		// 	break;
	}
}

int	main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;
	// if (argc < 2)
	// {
	// 	std::cerr << argv[0] << std::endl;
	// }

	// testJacobLogic(12);

	std::vector<int>	numbers;
	numbers.push_back(5);
	numbers.push_back(13);
	numbers.push_back(7);
	numbers.push_back(4);
	numbers.push_back(6);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(1);
	numbers.push_back(20);
	numbers.push_back(8);

	displayContainer(numbers, 1, "original numbers before");
	pmergeMe(numbers);

	displayContainer(numbers, 1, "original numbers after");
	return 0;
}
