/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_input.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:44:43 by jduval            #+#    #+#             */
/*   Updated: 2023/07/26 13:06:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

static std::string	find_and_replace(std::string input,
									const std::string &s1,
									const std::string &s2);

int	change_input(std::ifstream &infile,
				std::ofstream &outfile,
				std::string (&inputs)[4])
{
	std::string	input;
	std::string	output;

	while (std::getline(infile, input))
	{
		if (infile.good() == false)
			return (1);
		if (infile.eof() != true)
			input.push_back('\n');
		output = find_and_replace(input, inputs[1], inputs[2]);
		outfile << output;
		if (outfile.good() == false)
			return (1);
		input.clear();
	}
	return (0);
}

static std::string	find_and_replace(std::string input,
									const std::string &s1,
									const std::string &s2)
{
	std::size_t	pos = 0;
	while (pos < input.size())
	{
		pos = input.find(s1, pos);
		if (pos == std::string::npos)
			break ;
		input.erase(pos, s1.size());
		input.insert(pos, s2);
		pos += s2.size();
	}
	return (input);
}
