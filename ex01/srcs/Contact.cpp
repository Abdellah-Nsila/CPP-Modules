/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:08:01 by abnsila           #+#    #+#             */
/*   Updated: 2025/06/15 20:45:12 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

using namespace std;

Contact::Contact(void) {}

Contact::Contact(string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

string	Contact::formatString(string str)
{
	size_t	len;

	len = str.length();
	if (len <= 10)
		return (str);
	return (str.replace(9, str.length(), "."));
}

void	Contact::displayField(string field)
{
	cout << '|';
	cout << setfill(' ') << setw(10) << formatString(field);
}

void Contact::displayColumn(int id)
{
	cout << setfill(' ') << setw(10) << id;
	displayField(firstName);
	displayField(lastName);
	displayField(nickName);
	cout << endl;
}

void Contact::displayContact(void)
{
	cout << "First name     : " << firstName << endl;
	cout << "Last name      : " << lastName << endl;
	cout << "Nickname       : " << nickName << endl;
	cout << "Phone number   : " << phoneNumber << endl;
	cout << "Darkest secret : " << darkestSecret << endl;
}
