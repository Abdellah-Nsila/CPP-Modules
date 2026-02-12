/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:22:25 by abnsila           #+#    #+#             */
/*   Updated: 2026/02/12 18:25:51 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// int main()
// {
// 	MutantStack<int> mstack;
	
// 	mstack.push(5);
// 	mstack.push(17);
	
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
	
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
	
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
	
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
	
// 	std::stack<int> s(mstack);
	
// 	return 0;
// }


int	main()
{
	MutantStack<int>	s1;

	s1.push(5);
	s1.push(11);
	s1.push(85);

	s1.pop();

	MutantStack<int>	s2(s1);
	MutantStack<int>::iterator it = s2.begin();
	MutantStack<int>::iterator ite = s2.end();
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	s1.pop();
	s1.pop();

	std::cout << s1.size() << std::endl;
	std::cout << s2.size() << std::endl;

	s1 = s2;
	it = s1.begin();
	ite = s1.end();
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}