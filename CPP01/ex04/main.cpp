/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:18:29 by abnsila           #+#    #+#             */
/*   Updated: 2025/09/15 11:10:22 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	process_line(std::string& line, std::string& s1, std::string& s2)
{
	size_t	i = 0;
	size_t	s1_len = s1.length();
	size_t	s2_len = s2.length();

	if (s1.empty())
		return ;
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

int	setup_files(std::string& infile_path, std::string& outfile_path
	, std::string& s1, std::string& s2)
{
	std::string		buff_line;

	std::ifstream	infile(infile_path);
	if (!infile.is_open())
	{
		std::cerr << "Can't open " << infile_path << std::endl;
		return (1);
	}
	std::ofstream	outfile(outfile_path);
	if (!outfile.is_open())
	{
		std::cerr << "Can't open " << outfile_path << std::endl;
		return (1);
	}
	while (getline(infile, buff_line))
	{
		process_line(buff_line, s1, s2);
		outfile << buff_line << std::endl; 
	}
	infile.close();
	outfile.close();
	return (0);
}

int main (int argc, char **argv)
{
	std::string	infile_path;
	std::string	outfile_path;
	std::string	s1;
	std::string	s2;

	if (argc != 4)
	{
		std::cout << "./program <infile_file_path> s1 s2" << std::endl;	
		return (1);
	}
	
	infile_path = argv[1];
	outfile_path = std::string(argv[1]).append(".replace");
	s1 = argv[2];
	s2 = argv[3];
	return (setup_files(infile_path, outfile_path, s1, s2));
}
