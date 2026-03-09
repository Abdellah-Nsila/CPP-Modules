/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:38 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/09 17:39:24 by abnsila          ###   ########.fr       */
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

std::vector<int>	pmergeMe(std::vector<int>& numbers, const std::vector<int>& jacobSeq);
std::deque<int>		pmergeMe(std::deque<int>& numbers, const std::vector<int>& jacobSeq);
bool				isValidNumber(std::string&	arg);
std::vector<int>	jacobSequence(size_t size);

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
void	displayContainer(std::string state, T container)
{
	std::cout << state << ": ";
	for (size_t i = 0; i < container.size(); i++)
	{
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}
