/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:17:59 by jduval            #+#    #+#             */
/*   Updated: 2023/09/19 11:47:33 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

A::A()
{
	std::cout << "A constructor called" << std::endl;
}

A::~A()
{
	std::cout << "A destructor called" << std::endl;
}

B::B()
{
	std::cout << "B constructor called" << std::endl;
}

B::~B()
{
	std::cout << "B destructor called" << std::endl;
}

C::C()
{
	std::cout << "C constructor called" << std::endl;
}

C::~C()
{
	std::cout << "C destructor called" << std::endl;
}
