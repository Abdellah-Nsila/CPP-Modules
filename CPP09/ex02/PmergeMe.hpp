/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:38 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/06 06:53:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

struct Pair
{
	int	a;
	int b;
	Pair(int w, int l) : a(w), b(l) {};
};

std::vector<int>	jacobSequence(size_t pendSize);
void	pmergeMe(std::vector<int>& numbers);

template <typename T>
void	displayContainer(T container, int blockSize, std::string name)
{
	int	gs = 1;

	std::cout << "=========================" << name << "=========================" << std::endl;
	for (size_t i = 0; i < container.size(); i++)
	{
		if (gs == 1)
		{
			std::cout << "[" << container[i] << ", ";
			gs++;
		}
		else if (gs != blockSize)
		{
			std::cout << container[i] << ", ";
			gs++;
		}
		else if (gs == blockSize)
		{
			std::cout << container[i] << "] ";
			gs = 1;
		}
	}
	std::cout << std::endl;
	std::cout << "============================================================" << std::endl;
}
