/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:53:01 by jduval            #+#    #+#             */
/*   Updated: 2023/07/21 11:39:36 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{
	id = -1;
}

Contact::~Contact(){}

void	Contact::set_infos(std::string new_info, int type)
{
	infos[type] = new_info;
}

void	Contact::set_id(int new_id)
{
	std::cout << "new id = " << new_id << std::endl;
	id = new_id;
	std::cout << "id = " << id << std::endl;
}

int		Contact::get_id(void) const
{
	return (id);
}

void	Contact::display_base_search(void) const
{
	std::cout	<< std::setw(width_col) << this->id << "|"
				<< std::setw(width_col) << this->infos[0] << "|"
				<< std::setw(width_col) << this->infos[1] << "|"
				<< std::setw(width_col) << this->infos[2] << "|"
				<< std::endl;
}
