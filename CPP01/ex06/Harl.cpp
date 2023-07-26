/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:43:15 by jduval            #+#    #+#             */
/*   Updated: 2023/07/26 16:51:56 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <cstdlib>

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout	<< "[DEBUG]" << std::endl;
	std::cout	<< "It's debug time !"
				<< std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "[INFO]" << std::endl;
	std::cout	<< "It's all about information."
				<< std::endl;
}

void	Harl::warning(void)
{
	std::cout	<< "[WARNING]" << std::endl;
	std::cout	<< "Warning... What's the danger !??"
				<< std::endl;
}

void	Harl::error(void)
{
	std::cout	<< "[ERROR]" << std::endl;
	std::cout	<< "Well, it's an error. Well done !"
				<< std::endl;
}

typedef void (Harl::*funcptr)();

void	Harl::complain(int start)
{
	funcptr	functions[4] = {&Harl::debug,
							&Harl::info,
							&Harl::warning,
							&Harl::error};

	for (int i = start; i < 4; i++)
		(this->*functions[i])();
}
