/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:17:59 by jduval            #+#    #+#             */
/*   Updated: 2023/09/13 14:01:42 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstddef>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter : Default construtor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << "ScalarConverter : Copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter : Destructor called" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, ScalarConverter const &rhs)
{
	return (o);
}
