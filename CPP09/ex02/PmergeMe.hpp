/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:18:38 by abnsila           #+#    #+#             */
/*   Updated: 2026/03/03 15:50:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

std::vector<int>	jacobSequence(int groupsNum);
void	pmergeMe(std::vector<int>& numbers);

template <typename T>
void	displayContainer(T container, int groupSize, std::string name)
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
		else if (gs != groupSize)
		{
			std::cout << container[i] << ", ";
			gs++;
		}
		else if (gs == groupSize)
		{
			std::cout << container[i] << "] ";
			gs = 1;
		}
	}
	std::cout << std::endl;
	std::cout << "============================================================" << std::endl;
}
