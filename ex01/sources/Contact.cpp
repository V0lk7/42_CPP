/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:53:01 by jduval            #+#    #+#             */
/*   Updated: 2023/07/20 17:55:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>

Contact::Contact()
{
	id = -1;
}

Contact::~Contact(){}

void	Contact::set_infos(std::string new_info, int type)
{
	infos[type] = new_info;
}

std::string	Contact::get_infos(int type)
{
	return (infos[type]);
}

void	Contact::set_id(int new_id)
{
	std::cout << "new id = " << new_id << std::endl;
	id = new_id;
	std::cout << "id = " << id << std::endl;
}

int		Contact::get_id(void)
{
	return (id);
}

void	Contact::debug_display(void)
{
	int	i = 0;

	while (i < contact_parameters)
	{
		std::cout << infos[i] << std::endl;
		i++;
	}
}
