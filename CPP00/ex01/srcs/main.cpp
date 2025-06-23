/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:28:18 by abnsila           #+#    #+#             */
/*   Updated: 2025/06/15 20:40:48 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

using namespace std;

int	main()
{
	PhoneBook	phoneBook;
	string		command;

	while (!cin.eof())
	{
		command = phoneBook.input("Enter a command [ADD] [SEARCH] [EXIT]: ");
		if (command == "ADD")
		{
			// TODO: This check is optional
			if (!phoneBook.add())
				cout << "\nError in adding Contact!" << endl;
		}
		else if (command == "SEARCH")
		{
			phoneBook.search();
		}
		else if (command == "EXIT")
			break ;
		else if(!command.empty())
			cout << "Invalid command!\n";
	}
	return (0);
}
