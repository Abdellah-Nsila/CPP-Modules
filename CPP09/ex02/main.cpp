/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:43 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/07 13:42:55 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <cstdlib> // Required for srand() and rand()
#include <ctime>   // Required for time()
#include <algorithm> // Required for std::generate

void	testJacobLogic(size_t pendSize)
{
	size_t	lastJacob = 1;
	size_t	insertCount = 0;
	std::vector<int>	jacobSeq = jacobSequence(pendSize + 1);
	for (size_t k = 3; k < jacobSeq.size(); k++)
	{
		size_t	currentJacob = jacobSeq[k];
		size_t	topJacobId = std::min(currentJacob, pendSize);
		std::cout << "lastJacob: " << lastJacob << std::endl;
		for (size_t i = topJacobId; i > lastJacob; i--)
		{
			if (i < 2)
				break;
			// int	pendIdx = i - 2;
			std::cout << "ID: " << i << "   loserIdx: " << i - 2 << std::endl;
			insertCount++;
		}
		lastJacob = jacobSeq[k];
		// if (lastJacob > pendSize)
		// 	break;
	}
}

int getRandomNumber(int min, int max)
{
    // Formula: rand() % (max - min + 1) + min
    return (rand() % (max - min + 1)) + min;
}

std::vector<int>	generateRandomVectorNumbers()
{
    const int VECTOR_SIZE = getRandomNumber(1, 100);
    const int MIN_VAL = 1;
    const int MAX_VAL = 100;

    std::vector<int> random_vector(VECTOR_SIZE);

    for (size_t i = 0; i < random_vector.size(); ++i) {
        random_vector[i] = getRandomNumber(MIN_VAL, MAX_VAL);
    }
	return (random_vector);
}

bool	isVectorSorted(const std::vector<int>& vec)
{
    if (vec.size() <= 1) {
        return true;
    }
    for (unsigned int i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i+1]) {
            return false; // Found an unsorted pair
        }
    }
    return true; // All pairs were in non-descending order
}

int	main(int argc, char* argv[])
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	(void)argc;
	(void)argv;
	// if (argc < 2)
	// {
	// 	std::cerr << argv[0] << std::endl;
	// }

	for (size_t i = 0; i < 10; i++)
	{
		std::vector<int>	v = generateRandomVectorNumbers();
		// displayContainer(v, 1, "original numbers before");
		pmergeMe(v);
		// displayContainer(v, 1, "original numbers after");
		if (isVectorSorted(v))
			std::cout << "Sorted\n" << std::endl;
		else
			std::cout << "Not Sorted\n" << std::endl;
	}
	return 0;
}
