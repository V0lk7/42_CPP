/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:56:25 by jduval            #+#    #+#             */
/*   Updated: 2023/09/04 11:57:09 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
//	std::cout << "Cure : Default constructor called." << std::endl;
}

Cure::Cure(Cure const &src) : AMateria("cure")
{
//	std::cout << "Cure : Copy constructor called." << std::endl;
	*this = src;
}

Cure::~Cure()
{
//	std::cout << "Cure : Destructor called." << std::endl;
}

Cure	&Cure::operator=(Cure const &rhs)
{
	(void) rhs;
	return (*this);
}

Cure::Cure(std::string const &type) : AMateria("cure")
{
	(void) type;
//	std::cout << "Cure : Constructor with type called." << std::endl;
}

AMateria	*Cure::clone(void) const
{
	AMateria	*materia = new Cure();
	return (materia);
}

void	Cure::use(ICharacter &target) const
{
	std::cout	<< "Cure: * heals "
				<< target.getName() << "'s wounds *"
				<< std::endl;
}
