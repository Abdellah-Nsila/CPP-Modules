/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:49:26 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/07 10:31:46 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
	private:
		std::vector<int>	_container;
	 	unsigned int		_capacity;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		Span&	operator=(const Span& copy);
		~Span();

		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		template <typename It>
		void	addNumber(It begin, It end)
		{
			unsigned int	distance = std::distance(begin, end);
			if (this->_container.size() + distance > this->_capacity)
				throw SpanIsFull();
			this->_container.insert(this->_container.end(), begin, end);
		}
		void	display();

		class SpanIsFull : public std::exception
		{
			public :
				const char*	what() const throw();
		};

		class UnderTwoNumbers : public std::exception
		{
			public :
				const char*	what() const throw();
		};
};
