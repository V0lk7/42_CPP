/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inputs.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:50:13 by jduval            #+#    #+#             */
/*   Updated: 2023/07/31 09:59:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

static bool	valid_nb_parameters(int ac)
{
	if (ac != 4)
	{
		if (ac > 4)
		{
			std::cout	<< "Too much parameters. Need 3 parameters only"
						<< std::endl;
		}
		else
		{
			std::cout	<< "Not enough parameters. Need 3 parameters only"
						<< std::endl;
		}
		return (false);
	}
	return (true);
}

static bool	valid_contents(char **av, std::string (&inputs)[4])
{
	for (int i = 0; i < 3; i++)
	{
		inputs[i] = av[i + 1];
		if (inputs[i].empty() == true)
		{
			std::cout	<< "Parameter " << i + 1 << " can't be empty"
						<< std::endl;
			return (false);
		}
	}
	return (true);
}

bool	input_is_valid(int ac, char **av, std::string (&inputs)[4])
{
	if (valid_nb_parameters(ac) == false)
		return (false);
	if (valid_contents(av, inputs) == false)
		return (false);
	return (true);
}
