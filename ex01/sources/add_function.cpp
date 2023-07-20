/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_function.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:23:36 by jduval            #+#    #+#             */
/*   Updated: 2023/07/20 18:01:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>

int	add_input(PhoneBook &book)
{
	std::string		input;
	Contact 		&contact = book.get_contact(book.get_index());
	int				i = 0;

	while (i < contact_parameters)
	{
		std::cout << add_request[i] << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << bad_input[3] << std::endl;
			return (1);
		}
		if (input.empty() == true)
		{
			std::cout << bad_input[1] << std::endl;
			continue ;
		}
		contact.set_infos(input, i);
		i++;
	}
	contact.set_id(book.get_index());
	book.increment_index();
	return (0);
}
