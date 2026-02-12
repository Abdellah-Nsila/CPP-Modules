/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:23:15 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/12 15:40:37 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename std::stack<T, Container>::container_type::iterator		iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator	const_iterator;

	public:
		MutantStack();
		MutantStack(const MutantStack& copy);
		const MutantStack&	operator=(const MutantStack& copy);
		~MutantStack();

		iterator		begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;
};

#include "MutantStack.tpp"
