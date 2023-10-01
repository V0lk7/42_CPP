/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:59:29 by jduval            #+#    #+#             */
/*   Updated: 2023/10/01 16:04:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserMessages.hpp"
#include "Database.hpp"
#include <iostream>

static bool	CheckArgumentsNumbers(int ac);

int	main(int ac, char **av)
{
	if (CheckArgumentsNumbers(ac) == false)
		return (1);
	Database	btc;
	try{
		btc.openDataBaseFile().openInputFile(av[1]);
		btc.createDatabase();
		btc.findInputsInDatabase();
	}
	catch(std::exception &e){
		std::cerr << e.what() << "Exiting program now." << std::endl;
		return (1);
	}
	return (0);
}

static bool	CheckArgumentsNumbers(int ac)
{
	if (ac == 1)
	{
		std::cerr	<< ErrorNumbersOfArgs[1]
					<< ErrorNumbersOfArgs[0] << std::endl;
		return (false);
	}
	else if (ac > 2)
	{
		std::cerr	<< ErrorNumbersOfArgs[2]
					<< ErrorNumbersOfArgs[0] << std::endl;
		return (false);
	}
	else
		return (true);
}
