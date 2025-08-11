/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:18:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/08/11 17:14:14 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void	process_line(string& line, string s1, string s2)
{
	size_t	i = 0;
	size_t	s1_len = s1.length();
	size_t	s2_len = s2.length();

	while (i < line.length())
	{
		if (line.compare(i, s1_len, s1) == 0)
		{
			line.erase(i, s1_len);
			line.insert(i, s2);
			i += s2_len - 1;
		}
		i++;
	}
}

int main (int argc, char **argv)
{
	ifstream	file;
	ofstream	file_replace;
	string		file_name;
	string		line;
	
	if (argc != 4)
		return (1);
	
	file_name = argv[1];
	file_name.append(".replcae");
	file.open(argv[1]);
	file_replace.open(file_name.c_str());

	while (getline(file, line))
	{
		process_line(line, argv[2], argv[3]);
		file_replace << line << endl; 
	}

	file.close();
	file_replace.close();
	return (0);
}
