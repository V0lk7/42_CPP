/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:47:47 by jduval            #+#    #+#             */
/*   Updated: 2023/07/31 13:34:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "function.hpp"
#include <iostream>
#include <new>

int	main(void)
{
	PhoneBook	book;
	std::string	input;

	while (std::getline(std::cin, input))
	{
		if (input.empty() == true)
			std::cout << bad_input[0] << std::endl;
		else if (input.compare(user_pathern[0]) == 0)
			(void)add_input(book);
		else if (input.compare(user_pathern[1]) == 0)
			(void)search_input(book);
		else if (input.compare(user_pathern[2]) == 0)
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
