/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:52:53 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/08 18:27:58 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	this->total = 0;
}

string	PhoneBook::input(string msg)
{
	// TODO: No empty fields
	string	var;

	while (true)
	{	
		cout << msg;
		if (!getline(cin, var))
		{
			if (cin.eof())
				return ("");
			cin.clear();
			return ("");
		}
		if (var.empty())
			continue ;
		return (var);
	}
}

bool	PhoneBook::add(void)
{
	string firstName = this->input("Type your Fist Name: ");
	if (firstName.empty()) return (false);
	string lastName = this->input("Type your Last Name: ");
	if (lastName.empty()) return (false);
	string nickName = this->input("Type your Nick Name: ");
	if (nickName.empty()) return (false);
	string phoneName = this->input("Type your Phone Name: ");
	if (phoneName.empty()) return (false);
	string darkestSecret = this->input("Type your Darkest Secret: ");
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
	string id;

	while (true)
	{
		// 4294967295 overflow to -1
		// 4294967296 overflow to 0
		id = this->input("Enter the Contact id: ");
		if (id.empty())
		{
			cout << endl;
			break ;
		}
		if (!isNumber(id))
		{
			cout << "Input error: " << id << ": type a valid number!\n";
			continue ;
		}
		int idx = ft_atoi(id);
		if (idx < 0 || idx > this->total - 1)
		{
			cout << "Contact id: " << idx << " not found!\n";
			break ;
		}
		this->arr[idx].displayContact();
		break ;
	}
}

void	PhoneBook::search(void)
{
	if (this->total == 0)
	{
		cout << "PhoneBook is empty\n";
		return ;
	}
	for (int i = 0; i < this->total; i++)
	{	
		this->arr[i].displayColumn(i);
	}
	this->getContactById();
}
