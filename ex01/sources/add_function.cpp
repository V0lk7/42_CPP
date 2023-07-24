/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_function.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:23:36 by jduval            #+#    #+#             */
/*   Updated: 2023/07/24 08:22:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>

int	add_input(PhoneBook &book)
{
	std::string		input[contact_parameters];
	Contact 		&contact = book.get_contact(book.get_index());
	int				i = 0;

	while (i < contact_parameters)
	{
		std::cout << add_request[i] << std::endl;
		std::getline(std::cin, input[i]);
		if (std::cin.eof() == true)
			return (0);
		if (input[i].empty() == true)
		{
			std::cout << bad_input[1] << std::endl;
			continue ;
		}
		if (input[i] == user_pathern[3])
		{
			std::cout << add_request[5] << std::endl;
			return (0);
		}
		i++;
	}
	contact.set_infos(input);
	contact.set_id(book.get_index());
	book.increment_index();
	return (0);
}
