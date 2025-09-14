/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:52:53 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/14 10:22:19 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	this->total = 0;
}

std::string	PhoneBook::input(std::string msg)
{
	std::string	var;

	while (true)
	{	
		std::cout << msg;
		if (!getline(std::cin, var))
		{
			if (std::cin.eof())
				exit(EXIT_FAILURE);
		}
		if (var.empty())
			continue ;
		return (var);
	}
}

bool	PhoneBook::add(void)
{
	std::string firstName = this->input("Type your Fist Name: ");
	if (firstName.empty()) return (false);
	std::string lastName = this->input("Type your Last Name: ");
	if (lastName.empty()) return (false);
	std::string nickName = this->input("Type your Nick Name: ");
	if (nickName.empty()) return (false);
	std::string phoneName = this->input("Type your Phone Name: ");
	if (phoneName.empty()) return (false);
	std::string darkestSecret = this->input("Type your Darkest Secret: ");
	if (darkestSecret.empty()) return (false);
	Contact	newContact(firstName, lastName, nickName, phoneName, darkestSecret);
	arr[index] = newContact;
	index = (index + 1) % MAX;
	if (total < MAX)
		total++;
	return (true);
}

void	PhoneBook::getContactById(void)
{
	std::string	input;
	int			id;

	std::cout << "Enter the Contact id: ";
	while (true)
	{
		if (!getline(std::cin, input))
			exit(EXIT_FAILURE);
		if ((input.length() == 1) && std::isdigit(input[0]))
		{
			id = input[0] - '0';
			if (id < 0 || id > this->total - 1)
			{
				std::cout << "Contact id: " << id << " not found!\n";
				break ;
			}
			this->arr[id].displayContact();
			break ;
		}
		else
		{
			std::cout << "Input error: Enter only digits: ";
			continue ;
		}
	}
}

void	PhoneBook::search(void)
{
	if (this->total == 0)
	{
		std::cout << "PhoneBook is empty\n";
		return ;
	}
	for (int i = 0; i < this->total; i++)
		this->arr[i].displayColumn(i);
	this->getContactById();
}
