/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:53:01 by jduval            #+#    #+#             */
/*   Updated: 2023/07/19 10:18:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(){}

Contact::~Contact(){}

int	Contact::set_infos(std::string new_info, int type)
{
	(void)type;
	infos[0] = new_info;
	return (0);
}

int	Contact::get_infos(int type)
{
	(void)type;
	std::cout << infos[0] << std::endl;
	return (0);
}
