/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:15:54 by jduval            #+#    #+#             */
/*   Updated: 2023/08/10 11:17:17 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include <iostream>

IMateriaSource::IMateriaSource()
{
	std::cout << "IMateriaSource : Default constructor called." << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &src)
{
	std::cout << "IMateriaSource : Copy constructor called." << std::endl;
	*this = src;
}

IMateriaSource::~IMateriaSource()
{
	std::cout << "IMateriaSource : Destructor called." << std::endl;
}

IMateriaSource	&IMateriaSource::operator=(IMateriaSource const &rhs)
{
	(void) rhs;
	return (*this);
}
