/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:35 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/26 09:52:51 by abnsila          ###   ########.fr       */
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


typedef std::vector<std::pair<int, int> >	PairContainer;

std::vector<int>	generateMainChaine(PairContainer& sortedPairs, int straggler, bool hasStraggler)
{
	
}

void	recursiveSort(std::vector<int>& numbers, int groupSize)
{
	// 1. Base Case: Do we have at least one pair of groups?
	if (groupSize * 2 > numbers.size())
		return ;

	// 2. Pairwise Comparison & Block Swapping
	int	groupsNum = numbers.size() / groupSize;
	for (int i = 0; i < groupsNum; i += 2)
	{
		// Winner indices
		int winner1_idx = i + groupSize - 1;			// i = 0; groupSize = 4 => 0 + 4 - 1 = 3
		int winner2_idx = i + (2 * groupSize) - 1;		// i = 0; groupSize = 4 => 0 + (2 * 4) - 1 = 7
	
		if (numbers[winner1_idx] > numbers[winner2_idx])
		{
			// We swap the FULL blocks
            // Start1: i * groupSize
            // End1:   (i + 1) * groupSize (Exclusive, so it includes winner1)
            // Start2: (i + 1) * groupSize
			std::swap_ranges(numbers.begin() + (i * groupSize),
								numbers.begin() + i + groupSize,
								numbers.begin() + i + groupSize);
		}
	}
	
	
}

void	pmergeMe(std::vector<int>& numbers)
{
	PairContainer	pairs;
	int				straggler = 0;
	bool			hasStraggler = false;

	// Handle the straggler
	if (numbers.size() % 2)
	{
		straggler = numbers.back();
		hasStraggler = true;
		numbers.pop_back();
	}

	// Create Pairs
	for (size_t i = 0; i < numbers.size() - 1; (i =+ 2))
	{
		std::pair<int, int>	pair;
		
		pair.first = std::max(numbers[i], numbers[i + 1]);
		pair.second = std::min(numbers[i], numbers[i + 1]);
		pairs.push_back(pair);
	}

	recursiveSort(numbers, 2);

	//? I dont know i have have to do next step inside recursiveSortPairs or here
	

	
}
