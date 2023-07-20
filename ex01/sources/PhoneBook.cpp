/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:11:53 by jduval            #+#    #+#             */
/*   Updated: 2023/07/20 17:50:26 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(void)
{
	index = 0;
}

PhoneBook::~PhoneBook(void){}

int	PhoneBook::get_index(void)
{
	return (index);
}

void	PhoneBook::increment_index(int i)
{
	if (index == number_of_contacts - 1)
		index = 0;
	else
		index += i;;
}

Contact	&PhoneBook::get_contact(int which)
{
	return (list[which]);
}
