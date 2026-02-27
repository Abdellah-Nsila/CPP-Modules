/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:35 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/27 15:58:48 by abnsila          ###   ########.fr       */
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


std::vector<int>	jacobSequence(int groupsNum)
{
	std::vector<int>	sequence;
	int	i = 2;
	int	num = 0;

	sequence.push_back(0);
	sequence.push_back(1);
	while (num < groupsNum)
	{
		num = sequence[i - 1] + (2 * sequence[i - 2]);
		sequence.push_back(num);
		i++;
	}

	// Debugging
	// for (size_t i = 0; i < sequence.size(); i++)
	// {
	// 	std::cout << sequence[i] << std::endl;
	// }
	
	return (sequence);
}

void	recursiveSort(std::vector<int>& numbers, int groupSize)
{
	//  Step 1: the division into the pairs & sorting
	// 1. Base Case: Do we have at least one pair of groups?
	if (groupSize * 2 > numbers.size())
		return ;

	// 2. Pairwise Comparison & Block Swapping
	int	groupsNum = numbers.size() / groupSize;
	for (int i = 0; i < groupsNum; i += 2)
	{
		// Winner indices
		int winner1_idx = i + groupSize - 1;			// i = 0; groupSize = 4 => 0 + 4 - 1 = 3
		int winner2_idx = (i + 2) * groupSize - 1;		// i = 0; groupSize = 4 => (0 + 2) * 4 - 1 = 7
	
		if (numbers[winner1_idx] > numbers[winner2_idx])
		{
			// We swap the FULL blocks
            // Start1: i * groupSize
            // End1:   (i + 1) * groupSize (Exclusive, so it includes winner1)
            // Start2: (i + 1) * groupSize
			std::swap_ranges(numbers.begin() + (i * groupSize),
								numbers.begin() + ((i + 1) * groupSize),
								numbers.begin() + ((i + 1) * groupSize));
		}
	}

	// 3. Drill Down
	recursiveSort(numbers, groupSize * 2);

	// Steps 2 and 3: the initialization and insertion 
	// 4. THE UNWINDING (Phase 3)
	std::vector<int>	mainChaine;
	std::vector<int>	pendChaine;
	std::vector<int>	winnersCaptains;
	std::vector<int>	residual;
	bool				hasResidual = false;

	if (numbers.size() > (groupsNum * groupSize))
	{
		hasResidual = true;
		std::copy(numbers.begin() + (groupsNum * groupSize),
						numbers.end(),
						std::back_inserter(residual));
	}

	// Taking b1, a1 at once
	std::copy(numbers.begin(), numbers.begin() + (2 * groupSize), std::back_inserter(mainChaine));
	for (size_t i = 2; i < groupsNum; i++)
	{
		// Copying Winners to main chaine
		if (i % 2)
		{
			std::copy(numbers.begin() + (i * groupSize),
						numbers.begin() + (i + 1) * groupSize,
						std::back_inserter(mainChaine));
			winnersCaptains.push_back(*(numbers.begin() + ((i + 1) * groupSize) - 1));
		}
		// Copying Winners to pend chaine
		else
		{
			std::copy(numbers.begin() + (i * groupSize),
						numbers.begin() + (i + 1) * groupSize,
						std::back_inserter(pendChaine));				
		}
	}

	// Generate Jacobsthal Sequence
	std::vector<int>	jSeq = jacobSequence(pendChaine.size() / groupsNum);
	int	lastJacob = 1;
	int	currentJacob;

	for (size_t k = 3; k < jSeq.size(); k++)
	{
		currentJacob = jSeq[k]; // 3 2     5 4 
		for (size_t i = currentJacob; i > lastJacob; i--)
		{
			int	pendIdx = i - 2; // Offset: b2 is index 0
			if (pendIdx >= (pendChaine.size() / groupSize))
				continue;

			int	partnerWinnerVal = winnersCaptains[pendIdx];
			std::vector<int>::iterator	endRange = std::find(mainChaine.begin(),
																mainChaine.end(),
																partnerWinnerVal);

			int partnerLoserVal = pendChaine[((pendIdx + 1) * groupSize) - 1];
			std::vector<int>::iterator	insertionPos = std::upper_bound(mainChaine.begin(), 
																		endRange,
																		partnerLoserVal);

			mainChaine.insert(insertionPos,
								pendChaine.begin() + (pendIdx * groupSize),
								pendChaine.begin() + ((pendIdx + 1) * groupSize));
		}
		lastJacob = currentJacob;
	}

	// 5. Insert the Residual
	if (hasResidual)
	{
		// Use the last element of the residual block for comparison
		int	residualLastVal =  residual.back();

		// Range is the WHOLE mainChaine
		std::vector<int>::iterator	insertionPos = std::upper_bound(
			mainChaine.begin(),	mainChaine.end(),residualLastVal);

		mainChaine.insert(insertionPos,
							residual.begin(),
							residual.end());
	}

	// 6. FINISH THE UNWINDING
	// This is the most important step: move the sorted mainChaine back to numbers!
	std::copy(mainChaine.begin(), mainChaine.end(), numbers.begin());
}

// void	pmergeMe(std::vector<int>& numbers)
// {
// 	PairContainer	pairs;
// 	int				straggler = 0;
// 	bool			hasStraggler = false;

// 	// Handle the straggler
// 	if (numbers.size() % 2)
// 	{
// 		straggler = numbers.back();
// 		hasStraggler = true;
// 		numbers.pop_back();
// 	}

// 	// Create Pairs
// 	for (size_t i = 0; i < numbers.size() - 1; (i =+ 2))
// 	{
// 		std::pair<int, int>	pair;
		
// 		pair.first = std::max(numbers[i], numbers[i + 1]);
// 		pair.second = std::min(numbers[i], numbers[i + 1]);
// 		pairs.push_back(pair);
// 	}

// 	recursiveSort(numbers, 2);

// 	//? I dont know i have have to do next step inside recursiveSortPairs or here

	
	

	
// }

