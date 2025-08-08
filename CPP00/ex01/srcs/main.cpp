/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:28:18 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/08 18:36:14 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

int	main()
{
	PhoneBook	phoneBook;
	string		command;

	while (true)
	{
		command = phoneBook.input("Enter a command [ADD] [SEARCH] [EXIT]: ");
		if (cin.eof())
			break;

		if (command == "ADD")
		{
			if (!phoneBook.add())
				cout << "\nError in adding Contact!" << endl;
		}
		else if (command == "SEARCH")
		{
			phoneBook.search();
		}
		else if (command == "EXIT")
			break;
		else if (!command.empty())
			cout << "Invalid command!" << endl;
	}
	cout << endl;
	cin.clear();
	return (0);
}
