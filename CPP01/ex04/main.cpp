/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:26:37 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 17:56:19 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "functions.hpp"

int	main(int ac, char **av)
{
	std::string		inputs[4];
	std::ifstream	infile;
	std::ofstream	outfile;

	if (input_is_valid(ac, av, inputs) == false)
		return (1);
	create_name_outfile(inputs[0], inputs[3]);
	if (files_are_valid(infile, outfile, inputs) == false)
		return (1);
	bool	flag = replace_to_newfile(infile, outfile, inputs);
	input.close();
	output.close();
	if (flag == false)
		return (1);
	return (0);
}
