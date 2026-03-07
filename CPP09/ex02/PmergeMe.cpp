/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:35 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/07 07:36:55 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	jacobSequence(size_t pendSize)
{
	std::vector<int>	sequence;
	size_t	i = 2;
	size_t	num = 0;

	sequence.push_back(0);
	sequence.push_back(1);
	while (num < pendSize)
	{
		num = sequence[i - 1] + (2 * sequence[i - 2]);
		sequence.push_back(num);
		i++;
	}
	return (sequence);
}

void	binaryInsert(std::vector<int>& numbers, int value, size_t right)
{
	size_t	left = 0;

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		// Value is smaller, search the left half
		if (value < numbers[mid])
			right = mid;
		// Value is larger or equal, search the right half
		else
			left = mid + 1;
	}
	numbers.insert(numbers.begin() + left, value);
}

std::vector<int>	recursiveSort(std::vector<int>& numbers)
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
	mainChaine = recursiveSort(mainChaine);

	// 8 . The Unwinding Phase
	// 9 . Re-mapping: We must match losers to their specific winners in the returned chain.
	std::vector<int>	pend;
	pend.reserve(mainChaine.size());
	for (size_t i = 0; i < mainChaine.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (mainChaine[i] == pairs[j].a)
				pend.push_back(pairs[j].b);
		}
	}

	// 10 . Insert b1 because we know b1 < a1
	mainChaine.insert(mainChaine.begin(), pend[0]);

	// 11 . Binary-Insertion + Jacobsthal-Sequence
	size_t	lastJacob = 1;
	size_t	insertCount = 1;
	std::vector<int>	jacobSeq = jacobSequence(pend.size() + 1);

	for (size_t k = 3; k < jacobSeq.size(); k++)
	{
		size_t	currentJacob = jacobSeq[k];
		size_t	topJacobId = std::min(currentJacob, pend.size());

		for (size_t i = topJacobId; i > lastJacob; i--)
		{
			if (i < 2)
				break;
			int	pendIdx = i - 1;
			int loser = pend[pendIdx];
			size_t	range_limit = std::min(i + insertCount, mainChaine.size());
			binaryInsert(mainChaine, loser, range_limit);
			insertCount++;
		}
		lastJacob = jacobSeq[k];
		if (lastJacob >= pend.size())
			break;
	}

	if (hasStraggler)
		binaryInsert(mainChaine, straggler, mainChaine.size());

	return (mainChaine);
}

void	pmergeMe(std::vector<int>& numbers)
{
	if (numbers.size() < 2)
		return;

	numbers = recursiveSort(numbers);
}
