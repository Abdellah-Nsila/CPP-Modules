/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:35 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/05 17:24:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// // We have:
// // MainChain: [Winner1, Winner2, Winner3...] (Sorted)
// // Pend:      [Loser2, Loser3, Loser4...] (Not sorted relative to each other)
// // Note: Loser1 is already at the front of MainChain.

// JacobSequence = {3, 5, 11, 21...}
// Idx = 0

// While (Pend is not empty)
// {
//     // 1. Get the next target index from Jacobsthal sequence
//     target_idx = JacobSequence[Idx]
    
//     // 2. We must process losers from 'target_idx' DOWN TO the previous bound
//     // Example: If Jacob number is 3, we process Loser 3, then Loser 2.
//     // Example: If Jacob number is 5, we process Loser 5, then Loser 4.
    
//     current_loser_idx = target_idx
    
//     While (current_loser_idx > previous_bound)
//     {
//         // A. Pick the Loser to insert
//         Element loser = Pend[current_loser_idx]
        
//         // B. Determine the Search Range
//         // Crucial: You can only search up to the position of its 'Pair' (Winner).
//         // If you search beyond its Winner, you break the sort.
//         Winner = get_paired_winner(loser)
//         search_limit = iterator_to(Winner) in MainChain
        
//         // C. Binary Search
//         insertion_point = std::upper_bound(MainChain.begin(), search_limit, loser)
        
//         // D. Insert
//         MainChain.insert(insertion_point, loser)
        
//         current_loser_idx--
//     }
    
//     previous_bound = target_idx
//     Idx++
// }

// // Finally: Insert the Straggler (if it exists) using Binary Search on the ENTIRE MainChain.


std::vector<int>	jacobSequence(int blocksNum)
{
	std::vector<int>	sequence;
	int	i = 2;
	int	num = 0;

	sequence.push_back(0);
	sequence.push_back(1);
	while (num < blocksNum)
	{
		num = sequence[i - 1] + (2 * sequence[i - 2]);
		sequence.push_back(num);
		i++;
	}
	return (sequence);
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
	
	// 11 . 
	
	size_t	lastJacob = 1;
	std::vector<int>	jacobSeq = jacobSequence(pend.size() + 1);
	for (size_t k = 3; k < jacobSeq.size(); k++)
	{
		size_t	currentJacob = jacobSeq[k];
		size_t	actualEnd = std::min(currentJacob, pend.size());
		for (size_t i = currentJacob; i > actualEnd; i--)
		{
			if (i < 2)
				break;
			int	pendIdx = i - 2;
			// --- BINARY INSERTION LOGIC GOES HERE ---
			// 1. Get value: pend[pendIdx]
			// 2. Find partner a_i in mainChain
			// 3. Binary search up to a_i
			// 4. Insert
		}
		lastJacob = jacobSeq[k];
		if (lastJacob > pend.size())
			break;
	}
	
}

void	pmergeMe(std::vector<int>& numbers)
{
	int		straggler = 0;
	bool	hasStraggler = false;

	if (numbers.size() < 2)
		return;

	// Handle the straggler
	if (numbers.size() % 2)
	{
		straggler = numbers.back();
		hasStraggler = true;
		numbers.pop_back();
	}

	recursiveSort(numbers);

	// Insert Straggler if it exist
	if (hasStraggler)
	{	
		std::vector<int>::iterator	insertionPos = std::upper_bound(numbers.begin(),
		numbers.end(), straggler);
		numbers.insert(insertionPos, straggler);
	}
}
