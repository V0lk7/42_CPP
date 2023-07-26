/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:26:37 by jduval            #+#    #+#             */
/*   Updated: 2023/07/26 12:03:08 by jduval           ###   ########.fr       */
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
	int				return_flag = 0;

	if (input_is_valid(ac, av, inputs) == false)
		return (1);
	create_name_outfile(inputs[0], inputs[3]);
	if (files_are_valid(infile, outfile, inputs) == false)
		return (1);
	return_flag = change_input(infile, outfile, inputs);
	infile.close();
	outfile.close();
	if (return_flag == 1)
		return (1);
	return (0);
}
