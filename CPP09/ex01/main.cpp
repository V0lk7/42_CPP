/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:38:19 by jduval            #+#    #+#             */
/*   Updated: 2023/10/01 18:55:51 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RpnUtilities.hpp"
#include <iostream>
#include <sstream>

static bool	CheckArgsNumber(int ac);

int	main(int ac, char **av)
{
	if (CheckArgsNumber(ac) == false)
		return (1);

	std::string	UserInput(av[1]);
	std::istringstream	InputStream(UserInput);
	std::stack<double>	Numbers;
	int					Type;

	UserInput.clear();
	while (InputStream.eof() == false)
	{
		while (UserInput.empty() == true)
		{
			std::getline(InputStream, UserInput, ' ');
			if (InputStream.good() == false || InputStream.eof() == true)
				break ;
		}
		Type = RecognizeInput(UserInput);
		if (Type == ERROR)
		{
			std::cout << "RPN: Unauthorized entry : " << UserInput << std::endl;
			return (1);
		}
		else if (Type == DIGIT)
			AddDigitToStack(Numbers, UserInput);
		else
		{
			try{
				OperateOnStack(Numbers, Type);
			}
			catch (std::exception &e){
				std::cout << e.what() << std::endl;
				return (1);
			}
		}
		UserInput.clear();
	}
	if (Numbers.size() != 1)
		std::cout << "Error, can't define a result" << std::endl;
	else
		std::cout << Numbers.top() << std::endl;
	return (0);
}

static bool	CheckArgsNumber(int ac)
{
	if (ac != 2)
	{
		std::cout << "Need one argument." << std::endl;
		return (false);
	}
	return (true);
}
