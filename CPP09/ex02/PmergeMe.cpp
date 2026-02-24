/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:35 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/23 16:35:17 by abnsila          ###   ########.fr       */
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

void	pmerge()
{
	
}
