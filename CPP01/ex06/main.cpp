/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:25:25 by jduval            #+#    #+#             */
/*   Updated: 2023/07/27 10:29:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

static int	is_there_filter(const int ac);
static void	put_message(const std::string filter, Harl &harl);

int	main(int ac, char **av)
{
	Harl	harl;
	int		filter;

	filter = is_there_filter(ac);
	switch(filter){
		case 2 :
			std::cout	<< "What are you talking about ??" 
						<< " Need one filter, not a J.K Rowling novel"
						<< std::endl;
			break ;
		case 1 :
			put_message(av[1], harl);
			break ;
		default :
			std::cout << "No filter.... Need one, don't you think ?" << std::endl;
			break ;
	}
	return (0);	
}

static void	put_message(const std::string filter, Harl &harl)
{
	int	result_compare;
	const std::string	comparators[4] = {	"DEBUG",
											"INFO",
											"WARNING",
											"ERROR"};
	for (int i = 0; i < 4; i++)
	{
		result_compare = comparators[i].compare(filter);
		switch (result_compare){
			case 0 :
				harl.complain(i);
				return ;
			default :
				continue ;
		}
	}
	std::cout << "We don't speak the same langage i guess" << std::endl;
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
