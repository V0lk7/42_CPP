/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:43:15 by jduval            #+#    #+#             */
/*   Updated: 2023/09/07 15:08:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

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


void	Harl::complain(std::string level)
{
	void	(Harl::*funcptr[4])(void) = {&Harl::debug,
										&Harl::info,
										&Harl::warning,
										&Harl::error};
	std::string const	inputs[4] =	{	"DEBUG",
										"INFO",
										"WARNING",
										"ERROR"};
	for (int i = 0; i < 4; i++)
	{
		switch(level.compare(inputs[i])){
			case 0 :
			{
				while (i < 4)
					(this->*funcptr[i++])();
				return ;
			}
			default :
				continue ;
		}
	}
	std::cout << "Wrong parameter, Try : DEBUG, INFO, WARNING or ERROR" << std::endl;
}
