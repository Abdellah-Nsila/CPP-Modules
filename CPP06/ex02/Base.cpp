/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:50:56 by abnsila           #+#    #+#             */
/*   Updated: 2025/12/30 18:01:02 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base::Base()
{
}

Base::~Base()
{
}

Base*	generate(void)
{
	int		n;
	Base*	obj = NULL;

	n = rand() % ( 3 - 1 + 1 ) + 1;
	if (n == 1)
		obj = new A();
	else if (n == 2)
		obj = new B();
	else if (n == 3)
		obj = new C();
	return (obj);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A Class" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "B Class" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "C Class" << std::endl;
		return ;
	}
	std::cout << "Invalid Class Pointer" << std::endl;
}

void	identify(Base& p)
{

	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A Class" << std::endl;
		return ;
	}
	catch (const std::exception& e)
	{
	}


	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B Class" << std::endl;
		return ;
	}
	catch (const std::exception& e)
	{
	}


	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C Class" << std::endl;
		return ;
	}
	catch (const std::exception& e)
	{
	}

	std::cout << "Invalid Class Refrence" << std::endl;
}
