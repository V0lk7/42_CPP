/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_function.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:07:25 by jduval            #+#    #+#             */
/*   Updated: 2023/07/24 11:01:07 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

static void	display_contact(PhoneBook &book)
{
	//std::cout << std::setfill('-') << std::setw(width_col * 4 + 3) << std::endl;
	for (int i = 0; i < number_of_contacts; i++)
	{
		Contact	&contact = book.get_contact(i);
		if (contact.get_id() == -1)
			continue ;
		contact.display_all_contacts(); 
	//	std::cout << std::setfill('-') << std::setw(width_col * 4 + 3) << std::endl;
	}
}

int	get_index_to_input(std::string string)
{
	std::istringstream	convert(string);
	int					index;

	convert >> index;
	if ((index == 0 && string != "0")
		|| !(index >= 0 && index < number_of_contacts))
		return (-1);
	return (index);
}

static bool	is_book_empty(PhoneBook &book)
{
	Contact	&contact = book.get_contact(0);

	if (contact.get_id() == -1)
		return (true);
	else
		return (false);
}

int	search_input(PhoneBook &book)
{
	int	index;
	std::string	input;

	if (is_book_empty(book) == true)
	{
		std::cout << search_request[1] << std::endl; 
		return (0);
	}
	display_contact(book);
	while (getline(std::cin, input))
	{
		if (input == user_pathern[3])
		{
			std::cout << user_pathern[4] << std::endl;
			return (0);
		}
		index = get_index_to_input(input);
		if (index < 0)
		{
			std::cout << bad_input[4] << number_of_contacts << std::endl;  
			continue ;
		}
		Contact	&contact = book.get_contact(index);
		contact.display_infos();
	}
	return (0);
}
