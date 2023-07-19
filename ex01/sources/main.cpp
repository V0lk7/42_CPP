/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:28:10 by jduval            #+#    #+#             */
/*   Updated: 2023/07/19 18:54:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	book;
	//Contact		&Cobject = book.get_contact(0);
	std::string	input;

	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "Well done, you EOF the program... Now it's Exit time !" << std::endl;
			return (0);
		}
		if (input.empty() == true)
			std::cout << input << "Try to write something..." << std::endl;
		else if (input.compare("ADD") == 0)
			std::cout << input << " inserted" << std::endl;
			//add_contact;
		else if (input.compare("SEARCH") == 0)
			std::cout << input << " inserted" << std::endl;
		else if (input.compare("EXIT") == 0)
			std::cout << input << " inserted" << std::endl;
		else
			std::cout << "Wrong command. Try ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}
