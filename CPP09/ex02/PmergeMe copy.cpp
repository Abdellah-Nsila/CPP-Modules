/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:35 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/04 09:51:12 by abnsila          ###   ########.fr       */
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
	while (num <= blocksNum)
	{
		num = sequence[i - 1] + (2 * sequence[i - 2]);
		sequence.push_back(num);
		i++;
	}
	return (sequence);
}

void	recursiveSort(std::vector<int>& numbers, size_t blockSize)
{
	std::cout << "blockSize: " << blockSize << std::endl;
	//  Step 1: the division into the pairs & sorting
	// 1. Base Case: Do we have at least one pair of blocks?
	if ((blockSize * 2) > numbers.size())
		return ;

	// displayContainer(numbers, "numbers");
	// 2. Pairwise Comparison & Block Swapping
	size_t	blocksNum = numbers.size() / blockSize;

	for (size_t i = 0; i + 1 < blocksNum; i += 2)
	{
		// Winner indices
		int winner1_idx = (i + 1) * blockSize - 1;	// index of last element in the first block
		int winner2_idx = (i + 2) * blockSize - 1;	// index of last element in the second block
		std::cout << "idx1: " << winner1_idx << "   idx2: " << winner2_idx  << std::endl;
		
		if (numbers[winner1_idx] > numbers[winner2_idx])
		{
			std::cout << "w1: " << numbers[winner1_idx] << "   w2: " << numbers[winner2_idx] << std::endl;
			// We swap the FULL blocks
			// Start1: i * blockSize			Index of block 1 start
			// End1:   (i + 1) * blockSize		Swaping up to (begin + number) of element
			// Start2: (i + 1) * blockSize		Index of block 2 start
			std::swap_ranges(numbers.begin() + (i * blockSize),
			numbers.begin() + ((i + 1) * blockSize),
			numbers.begin() + ((i + 1) * blockSize));
		}
	}
	displayContainer(numbers, blockSize, "numbers before");

	// 3. Drill Down
	recursiveSort(numbers, blockSize * 2);

	displayContainer(numbers, blockSize, "numbers after");
	
	// Steps 2 and 3: the initialization and insertion 
	// 4. THE UNWINDING (Phase 3)
	std::vector<int>	mainChaine;
	std::vector<int>	pendChaine;
	std::vector<int>	winnersCaptains;
	std::vector<int>	residual;
	bool				hasResidual = false;

	if (numbers.size() > (blocksNum * blockSize))
	{
		hasResidual = true;
		std::copy(numbers.begin() + (blocksNum * blockSize),
						numbers.end(),
						std::back_inserter(residual));
	}

	// B. Handle the "Level Residual" (The odd block)
	size_t pairedBlocksNum = blocksNum;
	if (pairedBlocksNum % 2)
	{
		hasResidual = true;
		pairedBlocksNum = blocksNum - 1;
		residual.insert(residual.begin(), 
							numbers.begin() + (pairedBlocksNum * blockSize),
							numbers.begin() + (blocksNum * blockSize));
	}

	// Taking b1, a1 at once
	std::copy(numbers.begin(),
				numbers.begin() + (2 * blockSize),
				std::back_inserter(mainChaine));
	for (size_t i = 2; i < pairedBlocksNum; i++)
	{
		// Copying Winners to main chaine
		if (i % 2)
		{
			std::copy(numbers.begin() + (i * blockSize),
						numbers.begin() + (i + 1) * blockSize,
						std::back_inserter(mainChaine));
			winnersCaptains.push_back(numbers[((i + 1) * blockSize) - 1]);
		}
		// Copying Winners to pend chaine
		else
		{
			std::copy(numbers.begin() + (i * blockSize),
						numbers.begin() + (i + 1) * blockSize,
						std::back_inserter(pendChaine));				
		}
	}

	displayContainer(winnersCaptains, blockSize,"winnersCaptains");

	displayContainer(mainChaine, blockSize,"mainChaine");
	displayContainer(pendChaine, blockSize,"pendChaine");

	// Generate Jacobsthal Sequence
	std::vector<int>	jSeq = jacobSequence(pendChaine.size() / blockSize);
	size_t	lastJacob = 1;
	size_t	currentJacob;
	size_t	totalPendBlocks = pendChaine.size() / blockSize;

	for (size_t k = 3; k < jSeq.size(); k++)
	{
		currentJacob = jSeq[k]; // 3 2     5 4
		// TODO check J bound to stop 
		if (currentJacob > totalPendBlocks + 1)
			currentJacob = totalPendBlocks + 1;
		for (size_t i = currentJacob; i > lastJacob; i--)
		{
			size_t	pendIdx = i - 2; // Offset: b2 is index 0
			if (pendIdx >= totalPendBlocks)
				continue;

			int	partnerWinnerVal = winnersCaptains[pendIdx];
			std::vector<int>::iterator	endRange = std::find(mainChaine.begin(),
																mainChaine.end(),
																partnerWinnerVal);

			int partnerLoserVal = pendChaine[((pendIdx + 1) * blockSize) - 1];
			std::vector<int>::iterator	insertionPos = std::upper_bound(mainChaine.begin(), 
																		endRange,
																		partnerLoserVal);

			mainChaine.insert(insertionPos,
								pendChaine.begin() + (pendIdx * blockSize),
								pendChaine.begin() + ((pendIdx + 1) * blockSize));
		}
		lastJacob = currentJacob;
		if (lastJacob >= totalPendBlocks + 1)
			break;
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
	numbers = mainChaine;
	// std::copy(mainChaine.begin(), mainChaine.end(), numbers.begin());
	// displayContainer(mainChaine, 1, "numbers sorted");
}

// !!!!!!!!!!!!!!!!!!!!!!!!! Simulate in TLDRAW, TODO Original Straggler !!!!!!!!!!!!!!!!!!!!!!!!!

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

	recursiveSort(numbers, 1);

	// Insert Straggler if it exist
	if (hasStraggler)
	{	
		std::vector<int>::iterator	insertionPos = std::upper_bound(numbers.begin(),
		numbers.end(), straggler);
		numbers.insert(insertionPos, straggler);
	}
}
