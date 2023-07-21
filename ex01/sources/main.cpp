/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:28:10 by jduval            #+#    #+#             */
/*   Updated: 2023/07/21 18:12:07 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include "function.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	book;
	std::string	input;

	while (std::getline(std::cin, input))
	{
		if (input.empty() == true)
			std::cout << bad_input[0] << std::endl;
		else if (input.compare("ADD") == 0)
			(void)add_input(book);
		else if (input.compare("SEARCH") == 0)
			std::cout << input << " inserted" << std::endl;
		else if (input.compare("EXIT") == 0)
			//std::cout << input << " inserted" << std::endl;
			break ;
		else
			std::cout << bad_input[2] << std::endl;
	}
	if (std::cin.eof() == true)
	{
		std::cout << bad_input[3] << std::endl;
		return (0);
	}
	return (0);
}
