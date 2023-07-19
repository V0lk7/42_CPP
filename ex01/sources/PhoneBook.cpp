/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:11:53 by jduval            #+#    #+#             */
/*   Updated: 2023/07/19 18:58:19 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	index = 0;
}

PhoneBook::~PhoneBook(void){}

int	PhoneBook::get_index(void)
{
	return (index);
}

void	PhoneBook::increment_index(void)
{
	if (index == 7)
		index = 0;
	else
		index++;
}

Contact	&PhoneBook::get_contact(int which)
{
	return (list[which]);
}
