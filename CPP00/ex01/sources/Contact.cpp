/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:53:01 by jduval            #+#    #+#             */
/*   Updated: 2023/07/27 15:57:14 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

Contact::Contact() : id (-1)
{
	for (int i = 0; i < number_of_contacts; i++)
		this->infos[i] = "";
}

Contact::~Contact(){}

void	Contact::set_infos(std::string new_info[])
{
	for (int i = 0; i < contact_parameters; i++)
		this->infos[i] = new_info[i];
}

void	Contact::set_id(int new_id)
{
	this->id = new_id;
}

int		Contact::get_id(void) const
{
	return (this->id);
}

void	Contact::display_all_contacts(void) const
{
	std::string	display[4];
	std::ostringstream	tmp;

	tmp << this->id;
	display[0] = tmp.str();
	for (int i = 0; i < 3; i++)
	{
		if (this->infos[i].size() > width_col)
		{
			display[i + 1] = this->infos[i].substr(0, width_col - 1);
			display[i + 1].push_back('.');
		}
		else
			display[i + 1] = this->infos[i];
	}
	std::cout	<< std::setw(width_col) << display[0] << "|"
				<< std::setw(width_col) << display[1] << "|"
				<< std::setw(width_col) << display[2] << "|"
				<< std::setw(width_col) << display[3] << "|"
				<< std::endl;
}

void	Contact::display_infos(void) const
{
	if (id == -1)
	{
		for (int i = 0; i < contact_parameters; i++)
			std::cout << contact_params[i] << "[EMPTY]" << std::endl;
		return ;
	}
	for (int i = 0; i < contact_parameters; i++)
		std::cout << contact_params[i] << this->infos[i] << std::endl;
}
