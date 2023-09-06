/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:41:46 by jduval            #+#    #+#             */
/*   Updated: 2023/09/06 11:23:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	//std::cout << "Ice : Default constructor called." << std::endl;
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
//	std::cout << "Ice : Copy constructor called." << std::endl;
	*this = src;
}

Ice::~Ice()
{
//	std::cout << "Ice : Destructor called." << std::endl;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	(void) rhs;
	return (*this);
}

Ice::Ice(std::string const &type) : AMateria("ice")
{
	(void) type;
//	std::cout << "Ice : Constructor with type called." << std::endl;
}

AMateria	*Ice::clone(void) const
{
	AMateria	*materia = new Ice();
	return (materia);
}

void	Ice::use(ICharacter &target) const
{
	ICharacter	*ptr = &target;
	
	if (ptr != NULL)
		std::cout	<< "Ice: * shoots an ice bolt at "
					<< target.getName() << " *"
					<< std::endl;
}
