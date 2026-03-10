/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:35 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/10 07:58:03 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	pmergeMe(std::vector<int>& numbers, const std::vector<int>& jacobSeq)
{
	// 1 . Base Case: No Pair can be made
	if (numbers.size() < 2)
		return numbers;

	// 2 . Pairs container
	std::vector<Pair>	pairs;
	pairs.reserve(numbers.size() / 2);

	// 3 . Handle straggler
	int	straggler = 0;
	bool hasStraggler = false;
	if (numbers.size() % 2)
	{
		hasStraggler = true;
		straggler = numbers.back();
		numbers.pop_back();
	}

	// 4 . Setup Pairs
	for (size_t i = 0; i < numbers.size(); i += 2)
	{
		if (numbers[i] > numbers[i+1])
			pairs.push_back(Pair(numbers[i], numbers[i+1]));
		else
			pairs.push_back(Pair(numbers[i+1], numbers[i]));
	}

	// 5 . Setup mainChaine
	std::vector<int>	mainChaine;
	mainChaine.reserve(pairs.size());
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChaine.push_back(pairs[i].a);
	}

	// 7 . Recursion
	mainChaine = pmergeMe(mainChaine, jacobSeq);

	// 8 . The Unwinding Phase
	// 9 . Re-mapping: We must match losers to their specific winners in the returned sorted chain.
	std::vector<int>	pend;
	pend.reserve(mainChaine.size());
	for (size_t i = 0; i < mainChaine.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (!pairs[j].matched && mainChaine[i] == pairs[j].a)
			{
				pend.push_back(pairs[j].b);
				pairs[j].matched = true; // Marke it as matched so it's not matched again
            	break; // Move to the next winner in mainChaine
			}
		}
	}

	// 10 . Insert b1 because we know b1 < a1
	mainChaine.insert(mainChaine.begin(), pend[0]);

	// 11 . Binary-Insertion + Jacobsthal-Sequence
	size_t	lastJacob = 1;
	size_t	insertCount = 1;

	for (size_t k = 3; k < jacobSeq.size(); k++)
	{
		size_t	currentJacob = jacobSeq[k];
		size_t	topJacobId = std::min(currentJacob, pend.size());

		for (size_t idx = topJacobId; idx > lastJacob; idx--)
		{
			if (idx < 2)
				break;
			int loser = pend[idx - 1];
			size_t	rangeLimit = std::min(idx + insertCount, mainChaine.size());
			binaryInsert(mainChaine, loser, mainChaine.begin() + rangeLimit);
			insertCount++;
		}
		lastJacob = jacobSeq[k];
		if (lastJacob >= pend.size())
			break;
	}

	if (hasStraggler)
		binaryInsert(mainChaine, straggler, mainChaine.end());	

	return (mainChaine);
}

std::deque<int>	pmergeMe(std::deque<int>& numbers, const std::vector<int>& jacobSeq)
{
	// 1 . Base Case: No Pair can be made
	if (numbers.size() < 2)
		return numbers;

	// 2 . Pairs container
	std::deque<Pair>	pairs;

	// 3 . Handle straggler
	int	straggler = 0;
	bool hasStraggler = false;
	if (numbers.size() % 2)
	{
		hasStraggler = true;
		straggler = numbers.back();
		numbers.pop_back();
	}

	// 4 . Setup Pairs
	for (size_t i = 0; i < numbers.size(); i += 2)
	{
		if (numbers[i] > numbers[i+1])
			pairs.push_back(Pair(numbers[i], numbers[i+1]));
		else
			pairs.push_back(Pair(numbers[i+1], numbers[i]));
	}

	// 5 . Setup mainChaine
	std::deque<int>	mainChaine;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChaine.push_back(pairs[i].a);
	}

	// 7 . Recursion
	mainChaine = pmergeMe(mainChaine, jacobSeq);

	// 8 . The Unwinding Phase
	// 9 . Re-mapping: We must match losers to their specific winners in the returned chain.
	std::deque<int>	pend;
	for (size_t i = 0; i < mainChaine.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (mainChaine[i] == pairs[j].a)
			{
				pend.push_back(pairs[j].b);
				pairs[j].matched = true; // Marke it as matched so it's not matched again
            	break; // Move to the next winner in mainChaine
			}
		}
	}

	// 10 . Insert b1 because we know b1 < a1
	mainChaine.insert(mainChaine.begin(), pend[0]);

	// 11 . Binary-Insertion + Jacobsthal-Sequence
	size_t	lastJacob = 1;
	size_t	insertCount = 1;

	for (size_t k = 3; k < jacobSeq.size(); k++)
	{
		size_t	currentJacob = jacobSeq[k];
		size_t	topJacobId = std::min(currentJacob, pend.size());

		for (size_t idx = topJacobId; idx > lastJacob; idx--)
		{
			if (idx < 2)
				break;
			int loser = pend[idx - 1];
			size_t	rangeLimit = std::min(idx + insertCount, mainChaine.size());
			binaryInsert(mainChaine, loser, mainChaine.begin() + rangeLimit);
			insertCount++;
		}
		lastJacob = jacobSeq[k];
		if (lastJacob >= pend.size())
			break;
	}

	if (hasStraggler)
		binaryInsert(mainChaine, straggler, mainChaine.end());	

	return (mainChaine);
}

std::vector<int>	jacobSequence(size_t size)
{
	std::vector<int>		sequence;
	size_t	i = 2;
	size_t	num = 0;

	sequence.push_back(0);
	sequence.push_back(1);
	while (num < size)
	{
		num = sequence[i - 1] + (2 * sequence[i - 2]);
		sequence.push_back(num);
		i++;
	}
	return (sequence);
}

bool	isValidNumber(std::string&	arg)
{
	if (arg.empty())
		return (false);
	int	start = 0;
	if (arg[0] == '+')
	{
		if (arg[0] == '+' && arg.length() == 1)
			throw std::invalid_argument("Error: Invalid number format");	
		start = 1;
	}
	else if (arg[0] == '-')
	{
		throw std::invalid_argument("Error: Ngative numbers not allowed");
	}
	for (size_t i = start; i < arg.length(); i++)
	{
		if (!std::isdigit(arg[i]))
			throw std::invalid_argument("Error: Invalid number format");
	}
	char*	endPtr;
	long value = std::strtol(arg.c_str(), &endPtr, 10);
	if (value < 0)
		throw std::out_of_range("Error: Ngative numbers not allowed");
	if (value > INT_MAX)
		throw std::out_of_range("Error: Number too large for integer");
	return true;
}

std::vector<int>	parseInput(int argc, char** argv)
{
    std::vector<int> master;
    master.reserve(argc - 1);

    for (int i = 1; i < argc; i++)
	{
        std::string arg(argv[i]);
        if (isValidNumber(arg))
            master.push_back(std::atoi(argv[i]));
    }
    return master;
}
