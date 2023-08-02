/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:25:25 by jduval            #+#    #+#             */
/*   Updated: 2023/08/02 07:50:52 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

static int	is_there_filter(const int ac);

int	main(int ac, char **av)
{
	Harl	harl;
	int		filter;

	filter = is_there_filter(ac);
	switch(filter){
		case 2 :
			std::cout	<< "Too much parameters" << std::endl;
			break ;
		case 1 :
			harl.complain(av[1]);
			break ;
		default :
			std::cout << "Not enough parameters" << std::endl;
			break ;
	}
	return (0);	
}

static int	is_there_filter(const int ac)
{
	int	filter;

	switch(ac){
		case 1 :
			filter = 0;
			break ;
		case 2 :
			filter = 1;
			break ;
		default :
			filter = 2;
			break ;
	}
	return (filter);
}
