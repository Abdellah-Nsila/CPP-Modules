/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:38 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/09 16:05:20 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

#include <climits>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <vector>
#include <deque>

struct Pair
{
	int		a;
	int 	b;
	bool	matched;
	Pair(int w, int l) : a(w), b(l), matched(false) {};
};

std::vector<int>	pmergeMe(std::vector<int>& numbers);
std::deque<int>		pmergeMe(std::deque<int>& numbers);
bool				isValidNumber(std::string&	arg);

template <typename T>
bool	fillContainer(int argc, char* argv[], T& container)
{
	for (int i = 1; i < argc; i++)
	{
		std::string	arg(argv[i]);
		if (isValidNumber(arg))
			container.push_back(std::atoi(argv[i]));
	}
	return (true);
}

template <typename T>
void	binaryInsert(T& container, int number, typename T::iterator end)
{
	typename T::iterator	insertionPos = std::upper_bound(
		container.begin(), end, number);
	container.insert(insertionPos, number);
}

template <typename T>
T	jacobSequence(size_t pendSize)
{
	T		sequence;
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

template <typename T>
void	displayContainer(std::string state, T container)
{
	std::cout << state << ": ";
	for (size_t i = 0; i < container.size(); i++)
	{
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}
