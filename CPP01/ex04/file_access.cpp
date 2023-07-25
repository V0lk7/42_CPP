/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_access.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:40:11 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 17:38:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "functions.hpp"

bool	files_are_valid(std::ifstream &infile,
						std::ofstream &outfile,
						std::string (&inputs)[4])
{
	infile.open(inputs[INFILE].c_str());
	if (infile.is_open() == false)
	{
		std::cout << "Problem with the infile opening." << std::endl;
		return (false);
	}
	outfile.open(inputs[OUTFILE].c_str());
	if (outfile.is_open() == false)
	{
		infile.close();
		std::cout << "Problem with the outfile opening." << std::endl;
		return (false);
	}
	return (true);
}
