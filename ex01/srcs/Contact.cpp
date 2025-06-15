/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:08:01 by abnsila           #+#    #+#             */
/*   Updated: 2025/06/15 19:22:29 by abnsila          ###   ########.fr       */
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

void Contact::displayColumn(int id)
{
	cout << setfill('.') << setw(10) << id;
	cout << '|';
	cout << setfill('.') << setw(10) << firstName;
	cout << '|';
	cout << setfill('.') << setw(10) << lastName;
	cout << '|';
	cout << setfill('.') << setw(10) << nickName << endl;
	// cout << id << " | " << firstName << " | " << lastName << " | " << nickName << endl;
}

void Contact::displayContact(void)
{
	cout << "First name: " << firstName << endl;
	cout << "Last name: " << lastName << endl;
	cout << "Nickname: " << nickName << endl;
	cout << "Phone number: " << phoneNumber << endl;
	cout << "Darkest secret: " << darkestSecret << endl;
}
