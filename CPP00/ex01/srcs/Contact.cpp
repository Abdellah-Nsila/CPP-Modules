/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:08:01 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/14 10:09:26 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

Contact::Contact(void) {}

Contact::Contact(std::string firstName, std::string lastName
		, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

std::string	Contact::formatString(std::string str)
{
	size_t	len;

	len = str.length();
	if (len >= 10)
    	return str.substr(0, 9) + ".";
	return (str);
}

void	Contact::displayField(std::string field)
{
	std::cout << '|';
	std::cout << std::setfill(' ') << std::setw(10) << formatString(field);
}

void Contact::displayColumn(int id)
{
	std::cout << std::setfill(' ') << std::setw(10) << id;
	displayField(firstName);
	displayField(lastName);
	displayField(nickName);
	std::cout << std::endl;
}

void Contact::displayContact(void)
{
	std::cout << "First name     : " << firstName << std::endl;
	std::cout << "Last name      : " << lastName << std::endl;
	std::cout << "Nickname       : " << nickName << std::endl;
	std::cout << "Phone number   : " << phoneNumber << std::endl;
	std::cout << "Darkest secret : " << darkestSecret << std::endl;
}
